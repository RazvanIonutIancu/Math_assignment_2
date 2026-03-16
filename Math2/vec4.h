#pragma once
#include <cmath>






class vec4
{
public:
	float x;
	float y;
	float z;
	float w;



	vec4()
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
		this->w = 0.0f;
	}

	vec4(const float x, const float y, const float z, const float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	vec4(const vec4& v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		this->w = v.w;
	}




	vec4& operator=(const vec4& rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;
		this->w = rhs.w;

		return *this;
	}

	vec4 operator-() const
	{
		return vec4({ this->x * (-1), this->y * (-1), this->z * (-1), this->w * (-1)});
	}



	vec4 operator+(const vec4& rhs) const
	{
		return vec4({ this->x + rhs.x , this->y + rhs.y , this->z + rhs.z, this->w + rhs.w });
	}

	vec4& operator +=(const vec4& rhs)
	{
		this->x += rhs.x;
		this->y += rhs.y;
		this->z += rhs.z;
		this->w += rhs.w;

		return *this;
	}



	vec4 operator-(const vec4& rhs) const
	{
		return vec4({ this->x - rhs.x , this->y - rhs.y , this->z - rhs.z, this->w - rhs.w });
	}

	vec4& operator -=(const vec4& rhs)
	{
		this->x -= rhs.x;
		this->y -= rhs.y;
		this->z -= rhs.z;
		this->w -= rhs.w;

		return *this;
	}


	vec4& operator*=(const float scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;
		return *this;
	}

	vec4 operator*(const float scalar) const
	{
		return vec4{ this->x * scalar, this->y * scalar, this->z * scalar, this->w * scalar };
	}



	bool operator==(const vec4& rhs) const
	{
		return (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z && this->w == rhs.w);
	}
	bool operator!=(const vec4& rhs) const
	{
		return !(this->x == rhs.x && this->y == rhs.y && this->z == rhs.z && this->w == rhs.w);
	}



	float& operator[](const int i)
	{
		if (i == 0) return this->x;
		if (i == 1) return this->y;
		if (i == 2) return this->z;
		if (i == 3) return this->w;
	}

	const float& operator[](const int i) const
	{
		if (i == 0) return this->x;
		if (i == 1) return this->y;
		if (i == 2) return this->z;
		if (i == 3) return this->w;
	}
}; // Class end







float dot(const vec4& a, const vec4& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

float length(const vec4& v)
{
	return std::sqrt(dot(v, v));
}

vec4 normalize(const vec4& v)
{
	float vecLength = length(v);

	if (vecLength == 0.0f)
	{
		return vec4{ 0.0f, 0.0f, 0.0f, 0.0f };
	}

	return vec4{ v.x / vecLength, v.y / vecLength, v.z / vecLength, v.w / vecLength };
}