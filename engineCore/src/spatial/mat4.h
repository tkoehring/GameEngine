#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include "vec3.h"

namespace engine { namespace matrices {
	 
		struct mat4
		{
			float elements[16];
			mat4();
			mat4(const float &diagonal);
			mat4(const float *arr);
			~mat4();

			//Identity Matrices
			static mat4 identity();
			//Projection Matrices
			static mat4 othergraphic(float left, float right, float bottom, float top, float near, float far);
			static mat4 perspective(float fov, float aspectRatio, float near, float far);
			//Translation Matrices
			static mat4 translation(const vectors::vec3 &translation);
			static mat4 rotation(float angle, const vectors::vec3 &axis);
			static mat4 scale(const vectors::vec3 &scale);

			mat4& multiply(const mat4 &operand);
			friend mat4 operator*(mat4 lh, const mat4 &rh);
			mat4& operator*=(const mat4 &operand);
		};
		
}}
