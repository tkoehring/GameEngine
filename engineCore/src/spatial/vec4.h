#pragma once
#include <iostream>

namespace engine { namespace spatial {



	struct vec4
	{
		float x, y, z, w;

		vec4();
		vec4(const float &x,const float &y, const float &z, const float &w);


		vec4& add(const vec4 &operand);
		vec4& subtract(const vec4 &operand);
		vec4& multiply(const float &operand);
		vec4& operator+=(const vec4 &operand);
		vec4& operator-=(const vec4 &operand);
		vec4& operator*=(const float &operand);
		vec4& operator++();
		vec4& operator++(int);
		vec4& operator--();
		vec4& operator--(int);
		bool operator==(const vec4 &operand);
		bool operator!=(const vec4 &operand);

		friend vec4 operator+(vec4 lh, const vec4 &rh);
		friend vec4 operator-(vec4 lh, const vec4 &rh);
		friend vec4 operator*(vec4 lh, const float &rh);
		friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
	};









}}