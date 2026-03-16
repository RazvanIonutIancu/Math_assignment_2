#pragma once
#include <cmath>




class vec3
{
public:

	float x;
	float y;
	float z;

	vec3()
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
	}

	vec3(const float x, const float y, const float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3(vec3 const& v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
	}


	vec3 operator=(vec3 const& rhs)
	{
		return *this;
	}

	vec3 operator-()
	{
		return vec3({ this->x * (-1), this->y * (-1), this->z * (-1)});
	}



	vec3 operator+(vec3 const& rhs)
	{
		return vec3({ this->x + rhs.x , this->y + rhs.y , this->z + rhs.z });
	}

	vec3 operator +=(vec3 const& rhs)
	{
		return vec3({ this->x += rhs.x , this->y += rhs.y , this->z += rhs.z });
	}



	vec3 operator-(vec3 const& rhs)
	{
		return vec3({ this->x - rhs.x , this->y - rhs.y , this->z - rhs.z });
	}

	vec3 operator -=(vec3 const& rhs)
	{
		return vec3({ this->x -= rhs.x , this->y -= rhs.y , this->z -= rhs.z });
	}



	bool operator==(vec3 const& rhs)
	{
		return (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z);
	}
	bool operator!=(vec3 const& rhs)
	{
		return !(this->x == rhs.x && this->y == rhs.y && this->z == rhs.z);
	}



	float operator[](const int i)
	{
		if (i == 0) return this->x;
		if (i == 1) return this->y;
		if (i == 2) return this->z;
	}

	const float const& operator[](const int i) const
	{
		if (i == 0) return this->x;
		if (i == 1) return this->y;
		if (i == 2) return this->z;
	}



};



float dot(const vec3& a, const vec3& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

float length(const vec3& v)
{
	return std::sqrt(dot(v, v));
}

vec3 cross(const vec3& a, const vec3& b)
{
	return vec3{ a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x };
}

vec3 normalize(const vec3& v)
{
	float vecLength = length(v);

	if (vecLength == 0.0f)
	{
		return vec3{ 0.0f, 0.0f, 0.0f };
	}

	return vec3{ v.x / vecLength, v.y / vecLength, v.z / vecLength };
}