#pragma once
#include "vec3.h"
#include "vec4.h"



class mat4
{
public:

	vec4 m[4];


	mat4()
	{
		this->m[0] = vec4{ 1, 0, 0, 0 };
		this->m[1] = vec4{ 0, 1, 0, 0 };
		this->m[2] = vec4{ 0, 0, 1, 0 };
		this->m[3] = vec4{ 0, 0, 0, 1 };
	}

	mat4(const vec4& r0, const vec4& r1, const vec4& r2, const vec4& r3)
	{
		this->m[0] = r0;
		this->m[1] = r1;
		this->m[2] = r2;
		this->m[3] = r3;
	}

	mat4(const mat4& m)
	{
		this->m[0] = m[0];
		this->m[1] = m[1];
		this->m[2] = m[2];
		this->m[3] = m[3];
	}



	mat4& operator=(const mat4& rhs)
	{
		this->m[0] = rhs.m[0];
		this->m[1] = rhs.m[1];
		this->m[2] = rhs.m[2];
		this->m[3] = rhs.m[3];

		return *this;
	}

	mat4 operator*(const mat4& rhs) const
	{
		mat4 result;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				result.m[i][j] =
					this->m[i][0] * rhs.m[0][j]
					+ this->m[i][1] * rhs.m[1][j]
					+ this->m[i][2] * rhs.m[2][j]
					+ this->m[i][3] * rhs.m[3][j];



			}
		}

		return result;

	}

	vec4 operator*(const vec4& rhs) const
	{
		vec4 result;

		for (int i = 0; i < 4; i++)
		{
			result[i] = dot(this->m[i], rhs);
		}

		return result;
	}

	bool operator==(const mat4& rhs) const
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (this->m[i][j] != rhs.m[i][j])
				{
					return false;
				}
			}
		}

		return true;
	}

	bool operator!=(const mat4& rhs) const
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (this->m[i][j] != rhs.m[i][j])
				{
					return true;
				}
			}
		}

		return false;
	}


	vec4& operator[](const int& i)
	{
		if (i == 0) return this->m[0];
		if (i == 1) return this->m[1];
		if (i == 2) return this->m[2];
		if (i == 3) return this->m[3];
	}

	const vec4& operator[](const int& i) const
	{
		if (i == 0) return this->m[0];
		if (i == 1) return this->m[1];
		if (i == 2) return this->m[2];
		if (i == 3) return this->m[3];
	}

}; // Class end






float determinant(const mat4& m)
{
	vec3 a{ m[0][1], m[0][2], m[0][3] };
	vec3 b{ m[1][1], m[1][2], m[1][3] };
	vec3 c{ m[2][1], m[2][2], m[2][3] };
	vec3 d{ m[3][1], m[3][2], m[3][3] };

	return m[0][0] * dot(b, cross(c, d))
		 - m[1][0] * dot(a, cross(c, d))
		 + m[2][0] * dot(a, cross(b, d))
		 - m[3][0] * dot(a, cross(b, c));
}




mat4 inverse(const mat4& m)
{
	float theDeterminant = determinant(m);
	if (theDeterminant == 0.0f)
	{
		return mat4{};
	}

	mat4 theInverse;

	theInverse[0][0] =  dot(vec3{ m[1][1], m[1][2], m[1][3] }, cross(vec3{ m[2][1], m[2][2], m[2][3] }, vec3{ m[3][1], m[3][2], m[3][3] }));
	theInverse[0][1] = -dot(vec3{ m[0][1], m[0][2], m[0][3] }, cross(vec3{ m[2][1], m[2][2], m[2][3] }, vec3{ m[3][1], m[3][2], m[3][3] }));
	theInverse[0][2] =  dot(vec3{ m[0][1], m[0][2], m[0][3] }, cross(vec3{ m[1][1], m[1][2], m[1][3] }, vec3{ m[3][1], m[3][2], m[3][3] }));
	theInverse[0][3] = -dot(vec3{ m[0][1], m[0][2], m[0][3] }, cross(vec3{ m[1][1], m[1][2], m[1][3] }, vec3{ m[2][1], m[2][2], m[2][3] }));
	
	theInverse[1][0] = -dot(vec3{ m[1][0], m[1][2], m[1][3] }, cross(vec3{ m[2][0], m[2][2], m[2][3] }, vec3{ m[3][0], m[3][2], m[3][3] }));
	theInverse[1][1] =  dot(vec3{ m[0][0], m[0][2], m[0][3] }, cross(vec3{ m[2][0], m[2][2], m[2][3] }, vec3{ m[3][0], m[3][2], m[3][3] }));
	theInverse[1][2] = -dot(vec3{ m[0][0], m[0][2], m[0][3] }, cross(vec3{ m[1][0], m[1][2], m[1][3] }, vec3{ m[3][0], m[3][2], m[3][3] }));
	theInverse[1][3] =  dot(vec3{ m[0][0], m[0][2], m[0][3] }, cross(vec3{ m[1][0], m[1][2], m[1][3] }, vec3{ m[2][0], m[2][2], m[2][3] }));
	
	theInverse[2][0] =  dot(vec3{ m[1][0], m[1][1], m[1][3] }, cross(vec3{ m[2][0], m[2][1], m[2][3] }, vec3{ m[3][0], m[3][1], m[3][3] }));
	theInverse[2][1] = -dot(vec3{ m[0][0], m[0][1], m[0][3] }, cross(vec3{ m[2][0], m[2][1], m[2][3] }, vec3{ m[3][0], m[3][1], m[3][3] }));
	theInverse[2][2] =  dot(vec3{ m[0][0], m[0][1], m[0][3] }, cross(vec3{ m[1][0], m[1][1], m[1][3] }, vec3{ m[3][0], m[3][1], m[3][3] }));
	theInverse[2][3] = -dot(vec3{ m[0][0], m[0][1], m[0][3] }, cross(vec3{ m[1][0], m[1][1], m[1][3] }, vec3{ m[2][0], m[2][1], m[2][3] }));
	
	theInverse[3][0] = -dot(vec3{ m[1][0], m[1][1], m[1][2] }, cross(vec3{ m[2][0], m[2][1], m[2][2] }, vec3{ m[3][0], m[3][1], m[3][2] }));
	theInverse[3][1] =  dot(vec3{ m[0][0], m[0][1], m[0][2] }, cross(vec3{ m[2][0], m[2][1], m[2][2] }, vec3{ m[3][0], m[3][1], m[3][2] }));
	theInverse[3][2] = -dot(vec3{ m[0][0], m[0][1], m[0][2] }, cross(vec3{ m[1][0], m[1][1], m[1][2] }, vec3{ m[3][0], m[3][1], m[3][2] }));
	theInverse[3][3] =  dot(vec3{ m[0][0], m[0][1], m[0][2] }, cross(vec3{ m[1][0], m[1][1], m[1][2] }, vec3{ m[2][0], m[2][1], m[2][2] }));




	float reciprocal = 1.0f / theDeterminant;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			theInverse[i][j] *= reciprocal;

	return theInverse;
}


