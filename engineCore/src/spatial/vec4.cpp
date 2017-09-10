#include "vec4.h"

namespace engine { namespace spatial {

	

	vec4::vec4()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	vec4::vec4(const float &x, const float &y, const float &z, const float &w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	vec4& vec4::add(const vec4 &operand)
	{
		x += operand.x;
		y += operand.y;
		z += operand.z;
		w += operand.w;
		return *this;
	}

	vec4& vec4::subtract(const vec4 &operand)
	{
		x -= operand.x;
		y -= operand.y;
		z -= operand.z;
		w -= operand.w;
		return *this;
	}

	vec4& vec4::multiply(const float &operand)
	{
		x *= operand;
		y *= operand;
		z *= operand;
		w *= operand;
		return *this;
	}

	vec4& vec4::operator+=(const vec4 &operand)
	{
		return add(operand);
	}

	vec4& vec4::operator-=(const vec4 &operand)
	{
		return subtract(operand);
	}

	vec4& vec4::operator*=(const float &operand)
	{
		return multiply(operand);
	}

	vec4& vec4::operator++()
	{
		this->x += 1;
		this->y += 1;
		this->z += 1;
		this->w += 1;
		return *this;
	}

	vec4& vec4::operator++(int)
	{
		vec4 result(*this);
		++(*this);
		return *this;
	}

	vec4& vec4::operator--()
	{
		this->x -= 1;
		this->y -= 1;
		this->z -= 1;
		this->w -= 1;
		return *this;
	}

	vec4& vec4::operator--(int)
	{
		vec4 result(*this);
		--(*this);
		return *this;
	}

	bool vec4::operator==(const vec4 &operand)
	{
		return this->x == operand.x && this->y == operand.y && this->z == operand.z && this->z == operand.w;
	}

	bool vec4::operator!=(const vec4 &operand)
	{
		return !(*this == operand);
	}

	//Overloaded Operators
	std::ostream& operator<<(std::ostream& stream, const vec4& vector)
	{
		stream << "X: " << vector.x << " Y: " << vector.y << " Z: " << vector.z << " W: " << vector.w;
		return stream;
	}

	vec4 operator+(vec4 lh, const vec4 &rh)
	{
		return lh.add(rh);
	}

	vec4 operator-(vec4 lh, const vec4 &rh)
	{
		return lh.subtract(rh);
	}

	vec4 operator*(vec4 lh, const float &rh)
	{
		return lh.multiply(rh);
	}
}}