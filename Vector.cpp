﻿#include "Vector3.h"
#include <Novice.h>
#include <math.h>

Vector3 Add(const Vector3& v1, const Vector3& v2) {
	Vector3 add = {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
	return add;
}

Vector3 operator+(const Vector3& v1, const Vector3& v2) { return Add(v1, v2); }

Vector3 operator+(const Vector3& v) { 
	return v;

}





Vector3 Subtract(const Vector3& v1, const Vector3& v2) {
	Vector3 subtract = {v1.x + -v2.x, v1.y - v2.y, v1.z - v2.z};
	return subtract;
}

Vector3 operator-(const Vector3& v1, const Vector3& v2) { return Subtract(v1, v2); }

Vector3 operator-(const Vector3& v) { return {-v.x, -v.y, -v.z}; }

Vector3 Multiply(float scalar, const Vector3& v) {
	Vector3 multply = {scalar * v.x, scalar * v.y, scalar * v.z};
	return multply;
}

Vector3 operator*(float scalar, const Vector3& v) { return Multiply(scalar, v); }

Vector3 operator*(const Vector3& v, float scalar) { 
	return Multiply(scalar, v); }


Vector3 operator*(const Vector3& v,const Vector3& v2) {
	Vector3 multiply = {v.x * v2.x, v.y * v2.y, v.z * v2.z};
	return multiply;
}

Vector3 operator/(const Vector3& v, float scalar) { 
	Vector3 divide = {v.x / scalar, v.y / scalar, v.z / scalar};
	return divide;
}

float Dot(const Vector3& v1, const Vector3& v2) { return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z); }

float Length(const Vector3& v) { return sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z)); }

Vector3 Normalize(const Vector3& v) {
	float length = sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));

	Vector3 normalize = v;
	if (length != 0) {
		normalize.x = v.x / length;
		normalize.y = v.y / length;
		normalize.z = v.z / length;
	}
	return normalize;
}

void VectorScreenPrintf(int posX, int posY, const Vector3& vector, const char* label) {
	const int kColumnWidth = 60;
	Novice::ScreenPrintf(posX, posY, "%.02f", vector.x);
	Novice::ScreenPrintf(posX + kColumnWidth, posY, "%.02f", vector.y);
	Novice::ScreenPrintf(posX + kColumnWidth * 2, posY, "%.02f", vector.z);
	Novice::ScreenPrintf(posX + kColumnWidth * 3, posY, "%s", label);
}

Vector3 Cross(const Vector3& v1, const Vector3& v2) {
	Vector3 cross = {v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x};
	return cross;
}
