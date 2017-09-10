#include "vec2.h"

namespace engine { namespace spatial {

	

	vec2::vec2()
	{
		x = 0.0f;
		y = 0.0f;
	}

	vec2::vec2(const float &x, const float &y)
	{
		this->x = x;
		this->y = y;
	}

	vec2& vec2::add(const vec2 &operand)
	{
		x += operand.x;
		y += operand.y;
		return *this;
	}

	vec2& vec2::subtract(const vec2 &operand)
	{
		x -= operand.x;
		y -= operand.y;
		return *this;
	}

	vec2& vec2::multiply(const float &operand)
	{
		x *= operand;
		y *= operand;
		return *this;
	}

	vec2& vec2::operator+=(const vec2 &operand)
	{
		return add(operand);
	}

	vec2& vec2::operator-=(const vec2 &operand)
	{
		return subtract(operand);
	}

	vec2& vec2::operator*=(const float &operand)
	{
		return multiply(operand);
	}

	vec2& vec2::operator++()
	{
		this->x += 1;
		this->y += 1;
		return *this;
	}

	vec2& vec2::operator++(int)
	{
		vec2 result(*this);
		++(*this);
		return *this;
	}

	vec2& vec2::operator--()
	{
		this->x -= 1;
		this->y -= 1;
		return *this;
	}

	vec2& vec2::operator--(int)
	{
		vec2 result(*this);
		--(*this);
		return *this;
	}

	bool vec2::operator==(const vec2 &operand)
	{
		return this->x == operand.x && this->y == operand.y;
	}

	bool vec2::operator!=(const vec2 &operand)
	{
		return !(*this == operand);
	}

	//Overloaded Operators
	std::ostream& operator<<(std::ostream& stream, const vec2& vector)
	{
		stream << "X: " << vector.x << " Y: " << vector.y;
		return stream;
	}

	vec2 operator+(vec2 lh, const vec2 &rh)
	{
		return lh.add(rh);
	}

	vec2 operator-(vec2 lh, const vec2 &rh)
	{
		return lh.subtract(rh);
	}

	vec2 operator*(vec2 lh, const float &rh)
	{
		return lh.multiply(rh);
	}
}}