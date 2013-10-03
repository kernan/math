#ifndef MATH_CORE_vector4_INL
#define MATH_CORE_vector4_INL

#include "vector2.hpp"
#include "vector3.hpp"
#include "vector4.hpp"
#include "../func.hpp"

using namespace math::core;

/**
 * Default constructor.
 */
template<typename T>
vector4<T>::vector4(void) : x(), y() {}

/**
 * Parameterized constructor.
 * @param x Vector x-component.
 * @param y Vector y-component.
 * @param z Vector z-component.
 * @param w Vector w-component.
 */
template<typename T>
vector4<T>::vector4(const T& x, const T& y, const T& z, const T& w) : x(x), y(y), z(z), w(w) {}

/**
 * Parameterized constructor.
 * @param V 2-d vector.
 * @param z Vector z-component.
 * @param w Vector w-component.
 */
template<typename T>
vector4<T>::vector4(const vector2<T>& V, const T& z, const T& w) : vector4(V.x, V.y, z, w) {}

/**
 * Paremeterized constructor.
 * @param V 3-d vector.
 * @param w Vector w-component.
 */
template<typename T>
vector4<T>::vector4(const vector3<T>& V, const T& w) : vector4(V.x, V.y, V.z, w) {}

/**
 * Set vector equal to another.
 * @param orig Vector to set equal to.
 * @return The modified vector.
 */
template<typename T>
vector4<T>& vector4<T>::operator=(const vector4<T>& orig) {
	this->x = orig.x;
	this->y = orig.y;
	return *this;
}

/**
 * Negate a vector.
 * @return The vector negated.
 */
template<typename T>
vector4<T> vector4<T>::operator-(void) const {
	T x = -this->x;
	T y = -this->y;
	return vector4<T>(x, y);
}

/**
 * Component-wise vector addition.
 * @param V Vector to add.
 * @return The component-wise vector sum.
 */
template<typename T>
vector4<T> vector4<T>::operator+(const vector4<T>& V) const {
	T x = this->x + V.x;
	T y = this->y + V.y;
	return vector4<T>(x, y);
}

/**
 * Component-wise vector addition. Copy the result into this vector.
 * @param V Vector to add.
 * @return The modified vector (component-wise sum).
 */
template<typename T>
vector4<T>& vector4<T>::operator+=(const vector4<T>& V) {
	return *this = *this + V;
}

/**
 * Component-wise vector subtraction.
 * @param V Vector to subtract.
 * @return The component-wise vector difference.
 */
template<typename T>
vector4<T> vector4<T>::operator-(const vector4<T>& V) const {
	return *this + -V;
}

/**
 * Component-wise vector subtraction. Copy the result into this vector.
 * @param V Vector to subtract.
 * @return The modified vector (component-wise difference).
 */
template<typename T>
vector4<T>& vector4<T>::operator-=(const vector4<T>& V) {
	return *this = *this - V;
}

/**
 * Component-wise vector multiplication.
 * @param V Vector to multiply.
 * @return The component-wise product.
 */
template<typename T>
vector4<T> vector4<T>::operator*(const vector4<T>& V) const {
	T x = this->x * V.x;
	T y = this->y * V.y;
	return vector4<T>(x, y);
}

/**
 * Component-wise vector multiplication. Copy the result into this vector.
 * @param V Vector to multiply.
 * @return The modified vector (component-wise product).
 */
template<typename T> 
vector4<T>& vector4<T>::operator*=(const vector4<T>& V) {
	return *this = *this * V;
}

/**
 * Component-wise vector division.
 * @param V Vector to divide by.
 * @return The component-wise quotient.
 */
template<typename T>
vector4<T> vector4<T>::operator/(const vector4<T>& V) const {
	T x = this->x / V.x;
	T y = this->y / V.y;
	return vector4<T>(x, y);
}

/**
 * Component-wise vector division. Copy the result into this vector.
 * @param V Vector to divide by.
 * @return The modified vector (component-wise quotient).
 */
template<typename T>
vector4<T>& vector4<T>::operator/=(const vector4<T>& V) {
	return *this = *this / V;
}

/**
 * Calculate the nor-negative vector norm (magnitude squared).
 * @return Vector magnitude squared.
 */
template<typename T>
T vector4<T>::norm(void) const {
	return (this->x * this->x) + (this->y * this->y);
}

/**
 * Calculate the vector length.
 * @return Vector magnitude.
 */
template<typename T>
T vector4<T>::mag(void) const {
	return math::sqrt(this->norm());
}

/**
 * Calculate the vector normal.
 * @return Vector normal.
 */
template<typename T>
vector4<T> vector4<T>::normal(void) const {
	T mag = this->mag();
	T x = this->x / mag;
	T y = this->y / mag;
	return vector4<T>(x, y);
}

/**
 * Normalize a vector.
 * @return The modified vector (vector normal).
 */
template<typename T>
vector4<T>& vector4<T>::normalize(void) {
	return *this = this->normal();
}

/**
 * Check vector equality.
 * @param other Vector to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T>
bool vector4<T>::operator==(const vector4<T>& other) const {
	return this->x == other.x && this->y == other.y;
}

// TODO Use enable_if to specialize.
template<>
bool vector4<float>::operator==(const vector4<float>& other) const {
	return math::equals(this->x, other.x) && math::equals(this->y, other.y);
}

template<>
bool vector4<double>::operator==(const vector4<double>& other) const {
	return math::equals(this->x, other.x) && math::equals(this->y, other.y);
}

template<>
bool vector4<long double>::operator==(const vector4<long double>& other) const {
	return math::equals(this->y, other.x) && math::equals(this->y, other.y);
}

/**
 * Check vector inequality.
 * @param other Vector to check inequality with.
 * @return False if they are equal, otherwise true.
 */
template<typename T>
bool vector4<T>::operator!=(const vector4<T>& other) const {
	return !(*this == other);
}

/**
 * Calculate the inner vector product (dot product).
 * @param V1 Vector to take inner product of.
 * @param V2 Vector to take inner product of.
 * @return Vector dot product.
 */
template<typename T>
T vector4<T>::dot(const vector4<T>& V1, const vector4<T>& V2) {
	return (V1.x * V2.x) + (V1.y * V2.y);
}

/**
 * Calculate the reflection direction.
 * @param I Incident vector.
 * @param N Normal vector.
 * @return Reflection of incident over the normal.
 */
template<typename T>
vector4<T> vector4<T>::reflect(const vector4<T>& I, const vector4<T>& N) {
	return I - static_cast<T>(2.0) * vector4::dot(N, I) * N;
}

/**
 * Calculate the refraction direction.
 * @param I Incident vector.
 * @param N Normal vector.
 * @param eta Ratio of refraction.
 * @return Refraction of the indedent over the normal.
 */
template<typename T>
vector4<T> vector4<T>::refract(const vector4<T>& I, const vector4<T>& N, const T& eta) {
	T k = static_cast<T>(1.0) - eta * eta * (static_cast<T>(1.0) - vector4::dot(N, I) * vector4::dot(N, I));
	if (k < static_cast<T>(0.0)) {
		return vector4<T>();
	} else {
		// TODO Need generic sqrt.
		// return eta * I - (eta * vector4::dot(N, I) + math::sqrt(k)) * N;
		return vector4<T>();
	}
}

/**
 * Linearly interpolate between two vectors.
 * @param S Start vector.
 * @param E End vector.
 * @param t Value to interpolate by.
 * @return Interpolated vector.
 */
template<typename T>
vector4<T> lerp(const vector4<T>& S, const vector4<T>& E, const T& t) {
	return S + (t * (E - S));
}

/**
 * Scalar multiplication.
 * @param s Scalar to multiply by.
 * @param V Vector to multiply.
 * @return Scalar-vector product.
 */
template<typename T>
vector4<T> math::core::operator*(const T& s, const vector4<T>& v) {
	T x = s * v.x;
	T y = s * v.y;
	return vector4<T>(x, y);
}

/**
 * Ouput to stream.
 * @param out Stream to ouput to.
 * @param V Vector to print.
 * @return Modified output stream.
 */
template<typename T>
std::ostream& math::core::operator<<(std::ostream& out, const vector4<T>& v) {
	return out << "<" << v.x << ", " << v.y << ">";
}

#endif