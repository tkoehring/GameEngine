#include "vec3.h"

namespace engine { namespace vectors {

	

	vec3::vec3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	vec3::vec3(const float &x, const float &y, const float &z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3& vec3::add(const vec3 &operand)
	{
		x += operand.x;
		y += operand.y;
		z += operand.z;
		return *this;
	}

	vec3& vec3::subtract(const vec3 &operand)
	{
		x -= operand.x;
		y -= operand.y;
		z -= operand.z;
		return *this;
	}

	vec3& vec3::multiply(const float &operand)
	{
		x *= operand;
		y *= operand;
		z *= operand;
		return *this;
	}

	vec3& vec3::operator+=(const vec3 &operand)
	{
		return add(operand);
	}

	vec3& vec3::operator-=(const vec3 &operand)
	{
		return subtract(operand);
	}

	vec3& vec3::operator*=(const float &operand)
	{
		return multiply(operand);
	}

	vec3& vec3::operator++()
	{
		this->x += 1;
		this->y += 1;
		this->z += 1;
		return *this;
	}

	vec3& vec3::operator++(int)
	{
		vec3 result(*this);
		++(*this);
		return *this;
	}

	vec3& vec3::operator--()
	{
		this->x -= 1;
		this->y -= 1;
		this->z -= 1;
		return *this;
	}

	vec3& vec3::operator--(int)
	{
		vec3 result(*this);
		--(*this);
		return *this;
	}

	bool vec3::operator==(const vec3 &operand)
	{
		return this->x == operand.x && this->y == operand.y && this->z == operand.z;
	}

	bool vec3::operator!=(const vec3 &operand)
	{
		return !(*this == operand);
	}

	//Overloaded Operators
	std::ostream& operator<<(std::ostream& stream, const vec3& vector)
	{
		stream << "X: " << vector.x << " Y: " << vector.y << " Z: " << vector.z;
		return stream;
	}

	vec3 operator+(vec3 lh, const vec3 &rh)
	{
		return lh.add(rh);
	}

	vec3 operator-(vec3 lh, const vec3 &rh)
	{
		return lh.subtract(rh);
	}

	vec3 operator*(vec3 lh, const float &rh)
	{
		return lh.multiply(rh);
	}
}}