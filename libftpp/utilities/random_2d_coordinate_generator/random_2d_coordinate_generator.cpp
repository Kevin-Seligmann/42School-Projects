#include "random_2d_coordinate_generator.hpp"



Random2DCoordinateGenerator::Random2DCoordinateGenerator()
:_seed(std::chrono::high_resolution_clock().now().time_since_epoch().count()),_state(_seed){}

Random2DCoordinateGenerator::Random2DCoordinateGenerator(long long seed)
:_seed(s_to_u(seed)),_state(_seed){}

Random2DCoordinateGenerator::Random2DCoordinateGenerator(const Random2DCoordinateGenerator & src)
:_seed(src._seed),_state(src._state){}

Random2DCoordinateGenerator::Random2DCoordinateGenerator(Random2DCoordinateGenerator && src)
:_seed(std::move(src._seed)),_state(std::move(src._state)){}

Random2DCoordinateGenerator & Random2DCoordinateGenerator::operator=(const Random2DCoordinateGenerator & src)
{_seed = src._seed; _state = src._state; return *this;}

Random2DCoordinateGenerator & Random2DCoordinateGenerator::operator=(Random2DCoordinateGenerator && src)
{_seed = src._seed; _state = src._state; return *this;}

Random2DCoordinateGenerator::~Random2DCoordinateGenerator(){}

long long Random2DCoordinateGenerator::seed() const
{return u_to_s(_seed);}

long long Random2DCoordinateGenerator::operator()(const long long& x, const long long& y)
{
	_state += x;
	xorshift();
	_state += y;
	xorshift();
	return u_to_s(_state);
}

void Random2DCoordinateGenerator::xorshift()
{
	_state ^= (_state << 13);
	_state ^= (_state >> 7);
	_state ^= (_state << 17);
}

long long Random2DCoordinateGenerator::u_to_s(unsigned long long src) const
{
	return static_cast<long long>(src);
}

unsigned long long Random2DCoordinateGenerator::s_to_u(long long src) const
{
	return static_cast<unsigned long long>(src);
}

void Random2DCoordinateGenerator::reset(){_state = _seed;}
