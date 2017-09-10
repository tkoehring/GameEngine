#pragma once
#include <iostream>

namespace engine { namespace vectors {



	struct vec3
	{
		float x, y, z ;

		vec3();
		vec3(const float &x,const float &y, const float &z);


		vec3& add(const vec3 &operand);
		vec3& subtract(const vec3 &operand);
		vec3& multiply(const float &operand);
		vec3& operator+=(const vec3 &operand);
		vec3& operator-=(const vec3 &operand);
		vec3& operator*=(const float &operand);
		vec3& operator++();
		vec3& operator++(int);
		vec3& operator--();
		vec3& operator--(int);
		bool operator==(const vec3 &operand);
		bool operator!=(const vec3 &operand);

		friend vec3 operator+(vec3 lh, const vec3 &rh);
		friend vec3 operator-(vec3 lh, const vec3 &rh);
		friend vec3 operator*(vec3 lh, const float &rh);
		friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);
	};









}}