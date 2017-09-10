#include "mat4.h"

namespace engine { namespace spatial {

		mat4::mat4()
		{
			for (int i = 0; i < 16; i++)
			{
				elements[i] = 0;
			}
		}

		mat4::mat4(const float &diagonal)
		{
			for (int i = 0; i < 16; i++)
			{
				elements[i] = 0;
			}

			elements[0] = diagonal;
			elements[5] = diagonal;
			elements[10] = diagonal;
			elements[15] = diagonal;
		}

		mat4::mat4(const float *arr)
		{
			for (int i = 0; i < 16; i++)
			{
				elements[i] = arr[i];
			}
		}

		mat4::~mat4()
		{
		}

		mat4 mat4::identity()
		{
			return mat4(1.0f);
		}

		mat4 mat4::othergraphic(float left, float right, float bottom, float top, float near, float far)
		{
			mat4 result;

			result.elements[0] = 2 / (right - left);
			result.elements[5] = 2 / (top - bottom);
			result.elements[10] = -2 / (far - near);
			result.elements[12] = (right + left) / (right - left);
			result.elements[13] = (top + bottom) / (top - bottom);
			result.elements[14] = (far + near) / (far - near);
			result.elements[15] = 1;

			return result;
		}
		mat4 mat4::perspective(float fov, float aspectRatio, float near, float far)
		{
			fov = ((fov * M_PI) / 180);

			mat4 result;
			result.elements[0] = 1 / (aspectRatio * tan(fov / 2));
			result.elements[5] = 1 / tan(fov / 2);
			result.elements[10] = -((far + near) / (far - near));
			result.elements[11] = -1;
			result.elements[14] = -((2 * (far + near)) / (far - near));
			return result;
		}
		
		mat4 mat4::translation(const vec3 &translation)
		{
			mat4 result(1.0f);
			result.elements[12] = translation.x;
			result.elements[13] = translation.y;
			result.elements[14] = translation.z;
			return result;
		}

		mat4 mat4::rotation(float angle, const vec3 &axis)
		{
			mat4 result(1.0f);
			angle = ((angle * M_PI) / 180);
			float angleC = cos(angle);
			float angleS = sin(angle);

			result.elements[0] = (axis.x * (1 - angleC)) + angleC;
			result.elements[1] = ((axis.x * axis.y) * (1 - angleC)) + (axis.z * angleS);
			result.elements[2] = ((axis.x * axis.z) * (1 - angleC)) + (axis.y * angleS);

			result.elements[4] = ((axis.x * axis.y) * (1 - angleC)) - (axis.z * angleS);
			result.elements[5] = axis.x * (1 - angleC) + angleC;
			result.elements[6] = ((axis.y * axis.z) * (1 - angleC)) + (axis.x * angleS);

			result.elements[8] = ((axis.x * axis.z) * (1 - angleC)) + (axis.y * angleS);
			result.elements[9] = ((axis.y * axis.z) * (1 - angleC)) - (axis.x * angleS);
			result.elements[10] = axis.x * (1 - angleC) + angleC;

			return result;
		}

		mat4 mat4::scale(const vec3 &scale)
		{
			mat4 result(1.0f);
			result.elements[0] = scale.x;
			result.elements[5] = scale.y;
			result.elements[10] = scale.z;
			return result;
		}

		mat4& mat4::multiply(const mat4 &operand)
		{
			for (int row = 0; row < 4; row++)
			{
				float temp[4];

				for (int column = 0; column < 4; column++)
				{
					float sum = 0;

					for (int i = 0; i < 4; i++)
					{
						sum += elements[row + (i * 4)] * operand.elements[i + (column * 4)];
					}

					temp[column] = sum;
				}

				for (int j = 0; j < 4; j++)
				{
					elements[row + (j * 4)] = temp[j];
				}

			}

			return *this;
		}

		mat4& mat4::operator*=(const mat4 &operand)
		{
			return multiply(operand);
		}

		//Overloaded Operator
		mat4 operator*(mat4 lh, const mat4 &rh)
		{
			mat4 result = lh.multiply(rh);
			return result; 
		}
}}