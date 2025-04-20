#pragma once

#include <vector>
#include <random>
#include <limits>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include "libftpp.hpp"

class PerlinNoise2D
{
	public:
	PerlinNoise2D() = default;
	PerlinNoise2D(const PerlinNoise2D & src) = default;
	PerlinNoise2D(PerlinNoise2D && src) = default;
	PerlinNoise2D & operator=(const PerlinNoise2D & src) = default;
	PerlinNoise2D & operator=(PerlinNoise2D && src) = default;
	~PerlinNoise2D() = default;

	float sample(float x, float y);

	private:
	int _size_x;
	int _size_y;
	std::vector<std::vector<IVector2<float>>> _grid;

	void expand(int x, int y);
	IVector2<float> gen_gradient();
	float lerp(float a, float b, float t);
	float fade(float t);

};

float PerlinNoise2D::sample(float x, float y)
{
	if (x >= std::numeric_limits<int>::max() || x < 0
	 || y >= std::numeric_limits<int>::max() || y < 0)
	 	throw std::invalid_argument("Perlin noise grid limited to 0 / max int");
	if (x >= _size_x || y >= _size_y)
		expand(
			std::max(8, std::max((int)(x * 2), (int) (x + 1))),
			std::max(8, std::max((int)(y * 2), (int) (y + 1)))
		);


	IVector2<float> point{x, y};

	int grid_x = (int) floor(x);
	int grid_y = (int) floor(y);

	IVector2<float> off_00{x - grid_x, y - grid_y};
	IVector2<float> off_01{x - grid_x, y - (grid_y + 1)};
	IVector2<float> off_10{x - (grid_x + 1), y - grid_y};
	IVector2<float> off_11{x - (grid_x + 1), y - (grid_y + 1)};

	float dot_00 = off_00.dot(_grid[grid_y][grid_x]);
	float dot_01 = off_01.dot(_grid[grid_y + 1][grid_x]);
	float dot_10 = off_10.dot(_grid[grid_y][grid_x + 1]);
	float dot_11 = off_11.dot(_grid[grid_y + 1][grid_x + 1]);

	float u = fade(off_00.x);
	float v = fade(off_00.y);
	float lerp_x1 = lerp(dot_00, dot_10, u);
	float lerp_x2 = lerp(dot_01, dot_11, u);

	return lerp(lerp_x1, lerp_x2, v);
}

void PerlinNoise2D::expand(int x, int y)
{
	_grid.reserve(y);

	for(int j = 0; j < _size_y; j ++)
	{
		_grid.at(j).reserve(x);
		for(int i = _size_x; i < x; i ++)
		{
			_grid.at(j).emplace_back(gen_gradient());
		}
	}

	for(int j = _size_y; j < y; j ++)
	{
		_grid.emplace_back(std::vector<IVector2<float>>());
		_grid.at(j).reserve(x);
		for(int i = 0; i < x; i ++)
		{
			_grid.at(j).emplace_back(gen_gradient());
		}
	}

	_size_x = x;
	_size_y = y;
}

IVector2<float> PerlinNoise2D::gen_gradient()
{
    static std::mt19937 rng(std::random_device{}());
    static std::uniform_real_distribution<float> dist(0.0f, 2.0f * 3.1415926535f);
    float angle = dist(rng);
    return IVector2<float>(std::cos(angle), std::sin(angle));
}

float PerlinNoise2D::lerp(float a, float b, float t)
{return a + t * (b - a);}

float PerlinNoise2D::fade(float t)
{return t * t * t * (t * (t * 6 - 15) + 10);}
