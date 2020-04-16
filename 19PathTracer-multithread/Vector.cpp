#include "vector.h"
#include <iostream>

Matrix4f::Matrix4f(){}
Matrix4f::~Matrix4f(){}

const Matrix4f Matrix4f::IDENTITY(1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f);

void Matrix4f::rotate(const Vector3f &axis, float degrees){

	float rad = (degrees * PI) / 180.0f;
	float magnitude = axis.magnitude();

	float x = axis[0] * (1.0 / magnitude);
	float y = axis[1] * (1.0 / magnitude);
	float z = axis[2] * (1.0 / magnitude);
	float c = cosf(rad);
	float s = sinf(rad);

	mtx[0][0] = (x * x) * (1.0f - c) + c;
	mtx[0][1] = (x * y) * (1.0f - c) + (z * s);
	mtx[0][2] = (x * z) * (1.0f - c) - (y * s);
	mtx[0][3] = 0.0f;

	mtx[1][0] = (y * x) * (1.0f - c) - (z * s);
	mtx[1][1] = (y * y) * (1.0f - c) + c;
	mtx[1][2] = (y * z) * (1.0f - c) + (x * s);
	mtx[1][3] = 0.0f;

	mtx[2][0] = (z * x) * (1.0f - c) + (y * s);
	mtx[2][1] = (z * y) * (1.0f - c) - (x * s);
	mtx[2][2] = (z * z) * (1.0f - c) + c;
	mtx[2][3] = 0.0f;

	mtx[3][0] = 0.0f;
	mtx[3][1] = 0.0f;
	mtx[3][2] = 0.0f;
	mtx[3][3] = 1.0f;
}

void Matrix4f::invRotate(const Vector3f &axis, float degrees)
{
	float rad = (degrees * PI) / 180.0f;
	float magnitude = axis.magnitude();

	float x = axis[0] * (1.0 / magnitude);
	float y = axis[1] * (1.0 / magnitude);
	float z = axis[2] * (1.0 / magnitude);
	float c = cosf(rad);
	float s = sinf(rad);

	mtx[0][0] = (x * x) * (1.0f - c) + c;
	mtx[1][0] = (x * y) * (1.0f - c) + (z * s);
	mtx[2][0] = (x * z) * (1.0f - c) - (y * s);
	mtx[3][0] = 0.0f;

	mtx[0][1] = (y * x) * (1.0f - c) - (z * s);
	mtx[1][1] = (y * y) * (1.0f - c) + c;
	mtx[2][1] = (y * z) * (1.0f - c) + (x * s);
	mtx[3][1] = 0.0f;

	mtx[0][2] = (z * x) * (1.0f - c) + (y * s);
	mtx[1][2] = (z * y) * (1.0f - c) - (x * s);
	mtx[2][2] = (z * z) * (1.0f - c) + c;
	mtx[3][2] = 0.0f;

	mtx[0][3] = 0.0f;
	mtx[1][3] = 0.0f;
	mtx[2][3] = 0.0f;
	mtx[3][3] = 1.0f;
}


void Matrix4f::translate(float dx, float dy, float dz){

	mtx[0][0] = 1.0f;
	mtx[0][1] = 0.0f;
	mtx[0][2] = 0.0f;
	mtx[0][3] = dx;

	mtx[1][0] = 0.0f;
	mtx[1][1] = 1.0f;
	mtx[1][2] = 0.0f;
	mtx[1][3] = dy;

	mtx[2][0] = 0.0f;
	mtx[2][1] = 0.0f;
	mtx[2][2] = 1.0f;
	mtx[2][3] = dz;

	mtx[3][0] = 0.0f;
	mtx[3][1] = 0.0f;
	mtx[3][2] = 0.0f;
	mtx[3][3] = 1.0f;
}

void Matrix4f::invTranslate(float dx, float dy, float dz){

	mtx[0][0] = 1.0f;
	mtx[0][1] = 0.0f;
	mtx[0][2] = 0.0f;
	mtx[0][3] = -dx;

	mtx[1][0] = 0.0f;
	mtx[1][1] = 1.0f;
	mtx[1][2] = 0.0f;
	mtx[1][3] = -dy;

	mtx[2][0] = 0.0f;
	mtx[2][1] = 0.0f;
	mtx[2][2] = 1.0f;
	mtx[2][3] = -dz;

	mtx[3][0] = 0.0f;
	mtx[3][1] = 0.0f;
	mtx[3][2] = 0.0f;
	mtx[3][3] = 1.0f;
}

void Matrix4f::scale(float a, float b, float c){

	mtx[0][0] = a;
	mtx[0][1] = 0.0f;
	mtx[0][2] = 0.0f;
	mtx[0][3] = 0.0f;

	mtx[1][0] = 0.0f;
	mtx[1][1] = b;
	mtx[1][2] = 0.0f;
	mtx[1][3] = 0.0f;

	mtx[2][0] = 0.0f;
	mtx[2][1] = 0.0f;
	mtx[2][2] = c;
	mtx[2][3] = 0.0f;

	mtx[3][0] = 0.0f;
	mtx[3][1] = 0.0f;
	mtx[3][2] = 0.0f;
	mtx[3][3] = 1.0f;
}

void Matrix4f::invScale(float a, float b, float c){

	if (a == 0) a = 1.0;
	if (b == 0) b = 1.0;
	if (c == 0) c = 1.0;

	mtx[0][0] = 1.0f / a;
	mtx[0][1] = 0.0f;
	mtx[0][2] = 0.0f;
	mtx[0][3] = 0.0f;

	mtx[1][0] = 0.0f;
	mtx[1][1] = 1.0f / b;
	mtx[1][2] = 0.0f;
	mtx[1][3] = 0.0f;

	mtx[2][0] = 0.0f;
	mtx[2][1] = 0.0f;
	mtx[2][2] = 1.0f / c;
	mtx[2][3] = 0.0f;

	mtx[3][0] = 0.0f;
	mtx[3][1] = 0.0f;
	mtx[3][2] = 0.0f;
	mtx[3][3] = 1.0f;
}

Matrix4f::Matrix4f(float m11, float m12, float m13, float m14,
	float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34,
	float m41, float m42, float m43, float m44)
{
	mtx[0][0] = m11, mtx[0][1] = m12, mtx[0][2] = m13, mtx[0][3] = m14;
	mtx[1][0] = m21, mtx[1][1] = m22, mtx[1][2] = m23, mtx[1][3] = m24;
	mtx[2][0] = m31, mtx[2][1] = m32, mtx[2][2] = m33, mtx[2][3] = m34;
	mtx[3][0] = m41, mtx[3][1] = m42, mtx[3][2] = m43, mtx[3][3] = m44;
}

float *Matrix4f::operator[](int row)
{
	return mtx[row];
}

const float *Matrix4f::operator[](int row) const
{
	return mtx[row];
}

void Matrix4f::identity()
{
	mtx[0][0] = 1.0f, mtx[0][1] = 0.0f, mtx[0][2] = 0.0f, mtx[0][3] = 0.0f;
	mtx[1][0] = 0.0f, mtx[1][1] = 1.0f, mtx[1][2] = 0.0f, mtx[1][3] = 0.0f;
	mtx[2][0] = 0.0f, mtx[2][1] = 0.0f, mtx[2][2] = 1.0f, mtx[2][3] = 0.0f;
	mtx[3][0] = 0.0f, mtx[3][1] = 0.0f, mtx[3][2] = 0.0f, mtx[3][3] = 1.0f;
}

Matrix4f Matrix4f::transpose(){

 return Matrix4f(mtx[0][0], mtx[1][0], mtx[2][0], mtx[3][0],
				 mtx[0][1], mtx[1][1], mtx[2][1], mtx[3][1],
				 mtx[0][2], mtx[1][2], mtx[2][2], mtx[3][2],
				 mtx[0][3], mtx[1][3], mtx[2][3], mtx[3][3]);
}

void Matrix4f::transpose(Matrix4f &m){

	float tmp = m[0][1]; m[0][1] = m[1][0]; m[1][0] = tmp;
		  tmp = m[0][2]; m[0][2] = m[2][0]; m[2][0] = tmp;
		  tmp = m[0][3]; m[0][3] = m[3][0]; m[3][0] = tmp;

		  tmp = m[2][1]; m[2][1] = m[1][2]; m[1][2] = tmp;
		  tmp = m[3][1]; m[3][1] = m[1][3]; m[1][3] = tmp;

		  tmp = m[2][3]; m[2][3] = m[3][2]; m[3][2] = tmp;
}

Matrix4f &Matrix4f::operator*=(const Matrix4f &rhs)
{
	Matrix4f tmp;

	// Row 1.
	tmp.mtx[0][0] = (mtx[0][0] * rhs.mtx[0][0]) + (mtx[0][1] * rhs.mtx[1][0]) + (mtx[0][2] * rhs.mtx[2][0]) + (mtx[0][3] * rhs.mtx[3][0]);
	tmp.mtx[0][1] = (mtx[0][0] * rhs.mtx[0][1]) + (mtx[0][1] * rhs.mtx[1][1]) + (mtx[0][2] * rhs.mtx[2][1]) + (mtx[0][3] * rhs.mtx[3][1]);
	tmp.mtx[0][2] = (mtx[0][0] * rhs.mtx[0][2]) + (mtx[0][1] * rhs.mtx[1][2]) + (mtx[0][2] * rhs.mtx[2][2]) + (mtx[0][3] * rhs.mtx[3][2]);
	tmp.mtx[0][3] = (mtx[0][0] * rhs.mtx[0][3]) + (mtx[0][1] * rhs.mtx[1][3]) + (mtx[0][2] * rhs.mtx[2][3]) + (mtx[0][3] * rhs.mtx[3][3]);

	// Row 2.
	tmp.mtx[1][0] = (mtx[1][0] * rhs.mtx[0][0]) + (mtx[1][1] * rhs.mtx[1][0]) + (mtx[1][2] * rhs.mtx[2][0]) + (mtx[1][3] * rhs.mtx[3][0]);
	tmp.mtx[1][1] = (mtx[1][0] * rhs.mtx[0][1]) + (mtx[1][1] * rhs.mtx[1][1]) + (mtx[1][2] * rhs.mtx[2][1]) + (mtx[1][3] * rhs.mtx[3][1]);
	tmp.mtx[1][2] = (mtx[1][0] * rhs.mtx[0][2]) + (mtx[1][1] * rhs.mtx[1][2]) + (mtx[1][2] * rhs.mtx[2][2]) + (mtx[1][3] * rhs.mtx[3][2]);
	tmp.mtx[1][3] = (mtx[1][0] * rhs.mtx[0][3]) + (mtx[1][1] * rhs.mtx[1][3]) + (mtx[1][2] * rhs.mtx[2][3]) + (mtx[1][3] * rhs.mtx[3][3]);

	// Row 3.
	tmp.mtx[2][0] = (mtx[2][0] * rhs.mtx[0][0]) + (mtx[2][1] * rhs.mtx[1][0]) + (mtx[2][2] * rhs.mtx[2][0]) + (mtx[2][3] * rhs.mtx[3][0]);
	tmp.mtx[2][1] = (mtx[2][0] * rhs.mtx[0][1]) + (mtx[2][1] * rhs.mtx[1][1]) + (mtx[2][2] * rhs.mtx[2][1]) + (mtx[2][3] * rhs.mtx[3][1]);
	tmp.mtx[2][2] = (mtx[2][0] * rhs.mtx[0][2]) + (mtx[2][1] * rhs.mtx[1][2]) + (mtx[2][2] * rhs.mtx[2][2]) + (mtx[2][3] * rhs.mtx[3][2]);
	tmp.mtx[2][3] = (mtx[2][0] * rhs.mtx[0][3]) + (mtx[2][1] * rhs.mtx[1][3]) + (mtx[2][2] * rhs.mtx[2][3]) + (mtx[2][3] * rhs.mtx[3][3]);

	// Row 4.
	tmp.mtx[3][0] = (mtx[3][0] * rhs.mtx[0][0]) + (mtx[3][1] * rhs.mtx[1][0]) + (mtx[3][2] * rhs.mtx[2][0]) + (mtx[3][3] * rhs.mtx[3][0]);
	tmp.mtx[3][1] = (mtx[3][0] * rhs.mtx[0][1]) + (mtx[3][1] * rhs.mtx[1][1]) + (mtx[3][2] * rhs.mtx[2][1]) + (mtx[3][3] * rhs.mtx[3][1]);
	tmp.mtx[3][2] = (mtx[3][0] * rhs.mtx[0][2]) + (mtx[3][1] * rhs.mtx[1][2]) + (mtx[3][2] * rhs.mtx[2][2]) + (mtx[3][3] * rhs.mtx[3][2]);
	tmp.mtx[3][3] = (mtx[3][0] * rhs.mtx[0][3]) + (mtx[3][1] * rhs.mtx[1][3]) + (mtx[3][2] * rhs.mtx[2][3]) + (mtx[3][3] * rhs.mtx[3][3]);

	*this = tmp;
	return *this;
}

Matrix4f Matrix4f::operator*(const Matrix4f &rhs) const
{
	Matrix4f tmp(*this);
	tmp *= rhs;
	return tmp;
}

//////////////////////////////////////////////////////////////////////
Vector2f::Vector2f(){

	vec[0] = 0.0f;
	vec[1] = 0.0f;
}
Vector2f::~Vector2f(){}

Vector2f::Vector2f(float x_, float y_)
{
	vec[0] = x_;
	vec[1] = y_;

}

float &Vector2f::operator[](int index){
	return vec[index];
}

const float Vector2f::operator[](int index) const{
	return vec[index];
}

const float* Vector2f::getVec()const{

	return vec;
}

Vector2f &Vector2f::operator-=(const Vector2f &rhs){

	vec[0] -= rhs.vec[0], vec[1] -= rhs.vec[1];
	return *this;
}

Vector2f &Vector2f::operator+=(const Vector2f &rhs){

	vec[0] += rhs.vec[0], vec[1] += rhs.vec[1];
	return *this;
}


Vector2f Vector2f::operator+(const Vector2f &rhs) const{

	Vector2f tmp(*this);
	tmp += rhs;
	return tmp;
}

Vector2f Vector2f::operator-(const Vector2f &rhs) const{

	Vector2f tmp(*this);
	tmp -= rhs;
	return tmp;
}

Vector2f Vector2f::operator*(float scalar) const{

	return Vector2f(vec[0] * scalar, vec[1] * scalar);
}

Vector2f Vector2f::operator/(float scalar) const{

	return Vector2f(vec[0] / scalar, vec[1] / scalar);
}

Vector2f operator-(const Vector2f &v){

	return Vector2f(-v.vec[0], -v.vec[1]);
}



//////////////////////////////////////////////////////////////////////

Vector3f::Vector3f(){

	vec[0] = 0.0f;
	vec[1] = 0.0f;
	vec[2] = 0.0f;
}

Vector3f::~Vector3f(){}

Vector3f::Vector3f(float x_, float y_, float z_){

	vec[0] = x_;
	vec[1] = y_;
	vec[2] = z_;
}

Vector3f::Vector3f(const Vector4f &v){
	vec[0] = v[0];
	vec[1] = v[1];
	vec[2] = v[2];
}

float &Vector3f::operator[](int index){
	return vec[index];
}

const float Vector3f::operator[](int index) const{
	return vec[index];
}

const float* Vector3f::getVec()const{

	return vec;
}

Vector3f &Vector3f::operator-=(const Vector3f &rhs){

	vec[0] -= rhs.vec[0], vec[1] -= rhs.vec[1], vec[2] -= rhs.vec[2];
	return *this;
}

Vector3f &Vector3f::operator+=(const Vector3f &rhs){

	vec[0] += rhs.vec[0], vec[1] += rhs.vec[1], vec[2] += rhs.vec[2];
	return *this;
}


Vector3f Vector3f::operator+(const Vector3f &rhs) const{
	Vector3f tmp(*this);
	tmp += rhs;
	return tmp;
}

Vector3f Vector3f::operator-(const Vector3f &rhs) const{

	Vector3f tmp(*this);
	tmp -= rhs;
	return tmp;
}

Vector3f Vector3f::operator*(float scalar) const{

	return Vector3f(vec[0] * scalar, vec[1] * scalar, vec[2] * scalar);
}

Vector3f Vector3f::operator*(const Vector3f &rhs)const {

	return Vector3f(vec[0] * rhs[0], vec[1] * rhs[1], vec[2] * rhs[2]);
}


Vector3f operator*(float scalar, const Vector3f& v){

	return Vector3f(v[0] * scalar, v[1] * scalar, v[2] * scalar);
}

Vector3f Vector3f::operator/(float scalar) const{

	return Vector3f(vec[0] / scalar, vec[1] / scalar, vec[2] / scalar);
}

Vector3f operator-(const Vector3f &v){

	return Vector3f(-v.vec[0], -v.vec[1], -v.vec[2]);
}


Vector3f Vector3f::cross(const Vector3f &p, const Vector3f &q)
{
	return Vector3f((p.vec[1] * q.vec[2]) - (p.vec[2] * q.vec[1]),
		(p.vec[2] * q.vec[0]) - (p.vec[0] * q.vec[2]),
		(p.vec[0] * q.vec[1]) - (p.vec[1] * q.vec[0]));
}

float Vector3f::dot(const Vector3f &p, const Vector3f &q){

	return (p.vec[0] * q.vec[0]) + (p.vec[1] * q.vec[1]) + (p.vec[2] * q.vec[2]);
}

float Vector3f::magnitude() const{

	return sqrtf((vec[0] * vec[0]) + (vec[1] * vec[1]) + (vec[2] * vec[2]));
}

float Vector3f::sqMagnitude() const {

	return (vec[0] * vec[0]) + (vec[1] * vec[1]) + (vec[2] * vec[2]);
}

void Vector3f::normalize(Vector3f &p){

	float invMag = 1.0f / p.magnitude();
	p.vec[0] *= invMag, p.vec[1] *= invMag, p.vec[2] *= invMag;
}

Vector3f Vector3f::normalize(){

	float invMag = 1.0f / magnitude();

	return Vector3f(vec[0] * invMag, vec[1] * invMag, vec[2] * invMag);
}

Vector3f Vector3f::Min(const Vector3f &p, const Vector3f &q){

	return Vector3f(std::min(p[0], q[0]), std::min(p[1], q[1]), std::min(p[2], q[2]));
}

Vector3f Vector3f::Max(const Vector3f &p, const Vector3f &q){

	return Vector3f(std::max(p[0], q[0]), std::max(p[1], q[1]), std::max(p[2], q[2]));
}


void Vector3f::set(float x_, float y_, float z_){

	vec[0] = x_, vec[1] = y_, vec[2] = z_;
}


bool Vector3f::null(){

	return vec[0] == 0.0 && vec[1] == 0.0 && vec[2] == 0.0;

}

bool Vector3f::isSame(const Vector3f &p){


	return fabs(vec[0] - p[0]) < 0.0001 && fabs(vec[1] - p[1]) < 0.0001 && fabs(vec[2] - p[2]) < 0.0001;
}

Vector3f operator*(const Vector3f &lhs, const Matrix4f &rhs){

	return Vector3f((lhs[0] * rhs.mtx[0][0]) + (lhs[1] * rhs.mtx[1][0]) + (lhs[2] * rhs.mtx[2][0]),
		(lhs[0] * rhs.mtx[0][1]) + (lhs[1] * rhs.mtx[1][1]) + (lhs[2] * rhs.mtx[2][1]),
		(lhs[0] * rhs.mtx[0][2]) + (lhs[1] * rhs.mtx[1][2]) + (lhs[2] * rhs.mtx[2][2]));
}


Vector3f operator*(const Matrix4f &rhs, const Vector3f &lhs ){
	
	return Vector3f((lhs[0] * rhs.mtx[0][0]) + (lhs[1] * rhs.mtx[0][1]) + (lhs[2] * rhs.mtx[0][2]),
		(lhs[0] * rhs.mtx[1][0]) + (lhs[1] * rhs.mtx[1][1]) + (lhs[2] * rhs.mtx[1][2]),
		(lhs[0] * rhs.mtx[2][0]) + (lhs[1] * rhs.mtx[2][1]) + (lhs[2] * rhs.mtx[2][2]));
}



////////////////////////////////////////////////////////////////////////////////////////

Vector4f::Vector4f(){

	vec[0] = 0.0f;
	vec[1] = 0.0f;
	vec[2] = 0.0f;
	vec[3] = 0.0f;
}
Vector4f::~Vector4f(){}

Vector4f::Vector4f(float x_, float y_, float z_, float w_)
{
	vec[0] = x_;
	vec[1] = y_;
	vec[2] = z_;
	vec[3] = w_;
}

Vector4f::Vector4f(const Vector3f &rhs, float w_){
	vec[0] = rhs[0];
	vec[1] = rhs[1];
	vec[2] = rhs[2];
	vec[3] = w_;
}

float Vector4f::magnitude() const{

	return sqrtf((vec[0] * vec[0]) + (vec[1] * vec[1]) + (vec[2] * vec[2]) + (vec[3] * vec[3]));
}

Vector4f Vector4f::normalize(){

	float invMag = 1.0f / magnitude();

	return Vector4f(vec[0] * invMag, vec[1] * invMag, vec[2] * invMag, vec[3] * invMag);
}

void Vector4f::normalize(Vector4f &p){

	float invMag = 1.0f / p.magnitude();
	p.vec[0] *= invMag, p.vec[1] *= invMag, p.vec[2] *= invMag, p.vec[3]*= invMag;
}

float &Vector4f::operator[](int index){
	return vec[index];
}

const float Vector4f::operator[](int index) const{
	return vec[index];
}

Vector4f &Vector4f::operator-=(const Vector4f &rhs){

	vec[0] -= rhs.vec[0], vec[1] -= rhs.vec[1], vec[2] -= rhs.vec[2], vec[3] -= rhs.vec[3];
	return *this;
}

Vector4f &Vector4f::operator+=(const Vector4f &rhs){

	vec[0] += rhs.vec[0], vec[1] += rhs.vec[1], vec[2] += rhs.vec[2], vec[3] += rhs.vec[3];
	return *this;
}


Vector4f Vector4f::operator+(const Vector4f &rhs) const{
	Vector4f tmp(*this);
	tmp += rhs;
	return tmp;
}

Vector4f Vector4f::operator-(const Vector4f &rhs) const{

	Vector4f tmp(*this);
	tmp -= rhs;
	return tmp;
}

Vector4f Vector4f::operator*(float scalar) const{

	return Vector4f(vec[0] * scalar, vec[1] * scalar, vec[2] * scalar, vec[3] * scalar);
}

Vector4f Vector4f::operator/(float scalar) const{

	return Vector4f(vec[0] / scalar, vec[1] / scalar, vec[2] / scalar, vec[3] / scalar);
}

Vector4f operator-(const Vector4f &v){

	return Vector4f(-v.vec[0], -v.vec[1], -v.vec[2], -v.vec[3]);
}


Vector3f operator*(const Vector4f &lhs, const Matrix4f &rhs){

	return Vector3f((lhs[0] * rhs.mtx[0][0]) + (lhs[1] * rhs.mtx[1][0]) + (lhs[2] * rhs.mtx[2][0]) + (lhs[3] * rhs.mtx[3][0]),
		(lhs[0] * rhs.mtx[0][1]) + (lhs[1] * rhs.mtx[1][1]) + (lhs[2] * rhs.mtx[2][1]) + (lhs[3] * rhs.mtx[3][1]),
		(lhs[0] * rhs.mtx[0][2]) + (lhs[1] * rhs.mtx[1][2]) + (lhs[2] * rhs.mtx[2][2]) + (lhs[3] * rhs.mtx[3][2]));
	
}


Vector3f operator*(const Matrix4f &rhs, const Vector4f &lhs){

	return Vector3f((lhs[0] * rhs.mtx[0][0]) + (lhs[1] * rhs.mtx[0][1]) + (lhs[2] * rhs.mtx[0][2]) + (lhs[3] * rhs.mtx[0][3]),
		(lhs[0] * rhs.mtx[1][0]) + (lhs[1] * rhs.mtx[1][1]) + (lhs[2] * rhs.mtx[1][2]) + (lhs[3] * rhs.mtx[1][3]),
		(lhs[0] * rhs.mtx[2][0]) + (lhs[1] * rhs.mtx[2][1]) + (lhs[2] * rhs.mtx[2][2]) + (lhs[3] * rhs.mtx[2][3]));

	
	
}