#pragma once

#include <chrono>
#include <utility>
#include <limits>

class Random2DCoordinateGenerator
{
	public:
	Random2DCoordinateGenerator();
	Random2DCoordinateGenerator(long long seed);
	Random2DCoordinateGenerator(const Random2DCoordinateGenerator & src);
	Random2DCoordinateGenerator(Random2DCoordinateGenerator && src);
	Random2DCoordinateGenerator & operator=(const Random2DCoordinateGenerator & src);
	Random2DCoordinateGenerator & operator=(Random2DCoordinateGenerator && src);
	~Random2DCoordinateGenerator();

	long long seed() const;
	long long operator()(const long long& x, const long long& y);
	void reset();

	private:
	unsigned long long _seed;
	unsigned long long _state;

	void xorshift();
	long long u_to_s(unsigned long long src) const;
	unsigned long long s_to_u(long long src) const;

};
