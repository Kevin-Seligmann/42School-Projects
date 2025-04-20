#pragma once

#include <vector>
#include <tuple>
#include <algorithm>
#include <stdexcept>

template<typename TState>
class StateMachine 
{
	using transition_type = std::tuple<TState, TState, std::function<void()>>;
	using action_type = std::pair<TState, std::function<void()>>;

	public:
	StateMachine() = default;
	~StateMachine() = default;
	StateMachine(const StateMachine &) = default;
	StateMachine(StateMachine &&) = default;
	StateMachine & operator=(const StateMachine &) = default;
	StateMachine & operator=(StateMachine &) = default;



	void addState(const TState& state);
	void addTransition(const TState& startState, const TState & finalState, const std::function<void()> & lambda);
	void addAction(const TState & state, const std::function<void()> & lambda);
	void transitionTo(const TState& state);
	void update();

	private:
	std::vector<TState> _possible_states;
	std::vector<transition_type> _transitions;
	std::vector<action_type> _actions;
	TState current_state{};

	bool is_possible_state(const TState & state);
};

template<typename TState>
void StateMachine<TState>::addState(const TState& state)
{
	if (is_possible_state(state))
		throw std::invalid_argument("Trying to add an already possible state");
	if (!is_possible_state(current_state))
		current_state = state;
	_possible_states.push_back(state);
}

template<typename TState>
void StateMachine<TState>::addTransition
(const TState& startState, const TState & finalState, const std::function<void()> & lambda)
{
	if (!is_possible_state(startState) || !is_possible_state(finalState))
		throw std::invalid_argument("Adding transaction for invalid state");

	auto it = std::find_if(_transitions.begin(), _transitions.end(),
	[&] (transition_type & tuple)->bool
	{return (std::get<0>(tuple) == startState && std::get<1>(tuple) == finalState);});

	if (it != _transitions.end())
		_transitions.erase(it);
	_transitions.push_back(make_tuple(startState, finalState, lambda));
}

template<typename TState>
void StateMachine<TState>::addAction(const TState & state, const std::function<void()> & lambda)
{
	if (!is_possible_state(state))
		throw std::invalid_argument("Adding action for invalid state");

	auto it = std::find_if(_actions.begin(), _actions.end(),
	[&] (action_type & pair)->bool {return (pair.first == state);});

	if (it != _actions.end())
		_actions.erase(it);
	_actions.push_back(make_pair(state, lambda));
}

template<typename TState>
void StateMachine<TState>::transitionTo(const TState& state)
{
	if (!is_possible_state(state))
		throw std::invalid_argument("Transitioning to invalid state");
	
	auto it = std::find_if(_transitions.begin(), _transitions.end(),
	[&] (transition_type & tuple)->bool
	{return (std::get<0>(tuple) == current_state && std::get<1>(tuple) == state);});

	current_state = state;
	if (it == _transitions.end())
		throw std::invalid_argument("Transition for state not found");
	(std::get<2>(*it))();
}

template<typename TState>
void StateMachine<TState>::update()
{
	auto it = std::find_if(_actions.begin(), _actions.end(),
	[&] (action_type & pair)->bool
	{return (pair.first == current_state);});

	if (it == _actions.end())
		throw std::invalid_argument("Action for state not found");
	(it->second)();
}

template<typename TState>
bool StateMachine<TState>::is_possible_state(const TState & state)
{
	auto it = std::find(_possible_states.begin(), _possible_states.end(), state);
	return (it != _possible_states.end());
}
