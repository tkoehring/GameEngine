#pragma once
#include <iostream>

namespace engine { namespace spatial {



	struct vec2
	{
		float x, y;

		vec2();
		vec2(const float &x,const float &y);


		vec2& add(const vec2 &operand);
		vec2& subtract(const vec2 &operand);
		vec2& multiply(const float &operand);
		vec2& operator+=(const vec2 &operand);
		vec2& operator-=(const vec2 &operand);
		vec2& operator*=(const float &operand);
		vec2& operator++();
		vec2& operator++(int);
		vec2& operator--();
		vec2& operator--(int);
		bool operator==(const vec2 &operand);
		bool operator!=(const vec2 &operand);

		friend vec2 operator+(vec2 lh, const vec2 &rh);
		friend vec2 operator-(vec2 lh, const vec2 &rh);
		friend vec2 operator*(vec2 lh, const float &rh);
		friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);
	};









}}