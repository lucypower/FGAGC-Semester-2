#include "Vector3D.h"

Vector3D::Vector3D() // constructor
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3D::Vector3D(float x1, float y1, float z1) // constructor with values
{
	x = x1;
	y = y1;
	z = z1;
}

Vector3D::Vector3D(const Vector3D& vec) // copy constructor
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

Vector3D Vector3D::operator+(const Vector3D& vec) //addition
{
	return Vector3D(x + vec.x, y + vec.y, z + vec.z);
}

Vector3D& Vector3D::operator+=(const Vector3D& vec)//assign new result to vector
{
	x += vec.x;
	y += vec.y;
	z += vec.z;

	return *this;
}

Vector3D Vector3D::operator-(const Vector3D& vec) //subtraction
{
	return Vector3D(x - vec.x, y - vec.y, z - vec.z);
}

Vector3D& Vector3D::operator-=(const Vector3D& vec)//assign new result to vector
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;

	return *this;
}

Vector3D Vector3D::operator*(float value) //multiplication
{	
	return Vector3D(x * value, y * value, z * value);
}

Vector3D& Vector3D::operator*=(float value) //assign new result to vector.
{
	x *= value;
	y *= value;
	z *= value;

	return *this;
}

Vector3D Vector3D::operator/(float value) //division
{
	assert(value != 0); // prevent divide by 0

	return Vector3D(x / value, y / value, z / value);
}

Vector3D& Vector3D::operator/=(float value) //assign new result to vector
{
	assert(value != 0); // prevent divide by 0

	x /= value;
	y /= value;
	z /= value;

	return *this;
}

Vector3D& Vector3D::operator=(const Vector3D& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;

	return *this;
}

float Vector3D::dot_product(const Vector3D& vec) //scalar dot_product
{	
	return ((x * vec.x) + (y * vec.y) + (z * vec.z)); 
}

Vector3D Vector3D::cross_product(const Vector3D& vec) //cross_product
{	
	return Vector3D(((y * vec.z) - (z * vec.y)), ((z * vec.x) - (x * vec.z)), ((x * vec.y) - (y * vec.x)));
}

Vector3D Vector3D::normalization() //normalized vector
{	
	assert(magnitude() != 0);
	*this /= magnitude();
	return *this;
}

float Vector3D::square() //gives square of the vector
{
	return (x * x) + (y * y) + (z * z);
}

float Vector3D::distance(const Vector3D& vec) //distance between two vectors
{
	Vector3D distance = *this - vec;
	return distance.magnitude();
}

float Vector3D::magnitude() //magnitude of the vector
{
	return sqrt(square());
}

float Vector3D::show_X() //return x
{
	return x;
}

float Vector3D::show_Y() //return y
{
	return y;
}

float Vector3D::show_Z() //return z
{
	return z;
}

void Vector3D::disp() //display value of vectors
{
	cout << x << " " << y << " " << z << endl;
}