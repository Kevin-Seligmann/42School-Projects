#pragma once

#include <vector>
#include <functional>
#include <utility>

template <typename TEvent, typename FRet = void, typename... FArgs>
class Observer 
{
	public:
	using ftype = std::function<FRet(FArgs...)>;
	using event = std::pair<TEvent, ftype>;

	Observer();
	~Observer();
	Observer(const Observer & src);
	Observer(Observer && src);
	Observer & operator=(const Observer & rhs);
	Observer & operator=(Observer && rhs);

	void subscribe(TEvent eventType, ftype lambda);
	void notify(TEvent eventType, FArgs && ... args);

	private:
	std::vector<event> _events;
};

template <typename TEvent, typename FRet, typename... FArgs>
Observer<TEvent, FRet, FArgs...>::Observer(){}

template <typename TEvent, typename FRet, typename... FArgs>
Observer<TEvent, FRet, FArgs...>::~Observer(){}

template <typename TEvent, typename FRet, typename... FArgs>
Observer<TEvent, FRet, FArgs...>::Observer(const Observer & src)
{_events = src._events;}

template <typename TEvent, typename FRet, typename... FArgs>
Observer<TEvent, FRet, FArgs...>::Observer(Observer && src)
{_events = std::move(src._events);}

template <typename TEvent, typename FRet, typename... FArgs>
Observer<TEvent, FRet, FArgs...> & Observer<TEvent, FRet, FArgs...>::operator=(const Observer & rhs)
{if (&rhs != this) _events = rhs._events; return *this;}

template <typename TEvent, typename FRet, typename... FArgs>
Observer<TEvent, FRet, FArgs...> & Observer<TEvent, FRet, FArgs...>::operator=(Observer && rhs)
{if (&rhs != this) _events = std::move(rhs._events); return *this;}

template <typename TEvent, typename FRet, typename... FArgs>
void Observer<TEvent, FRet, FArgs...>::subscribe(TEvent eventType, ftype lambda)
{
	_events.push_back(std::make_pair(eventType, lambda));
}

template <typename TEvent, typename FRet, typename... FArgs>
void Observer<TEvent, FRet, FArgs...>::notify(TEvent eventType, FArgs && ... args)
{
	for (auto & event : _events)
		if (event.first == eventType)
			event.second(std::forward<FArgs>(args)...);
}
