#pragma once
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

};