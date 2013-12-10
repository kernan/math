#ifndef MATH_CORE_SWIZZLE_SWIZZLE2_INL
#define MATH_CORE_SWIZZLE_SWIZZLE2_INL

#include "swizzle.hpp"
#include "swizzle2.hpp"
#include "../vector.hpp"

using namespace math::core;

/**
 * Convert from a swizzle to a vector.
 * @return Converted vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Swizzle2<T, N, E1, E2>::operator Vector<T, 2>(void) {
	return Vector<T, 2>(this->data[E1], this->data[E2]);
}

/**
 * Set this swizzle (and the underlying Vector) equal to a Vector.
 * @param V Vector to set equal to.
 * @return The modified Vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::operator=(const Vector<T, 2>& V) {
	this->data[E1] = V.x;
	this->data[E2] = V.y;
	return *(Vector<T, 2>*)this;
}

/**
 * Add a vector to this swizzle.
 * @param V Vector to add.
 * @return The vector sum.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector<T, 2> Swizzle2<T, N, E1, E2>::operator+(const Vector<T, 2>& V) const {
	return *(Vector<T, 2>*)this + V;
}

/**
 * Add a vector to this swizzle. Set this swizzle (and the underlying vector) to
 * the result.
 * @param V Vector to add.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::operator+=(const Vector<T, 2>& V) {
	return *this = *this + V;
}

/**
 * Subtract a vector from this swizzle.
 * @param V Vector to subtract.
 * @return Vector difference.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector<T, 2> Swizzle2<T, N, E1, E2>::operator-(const Vector<T, 2>& V) const {
	return *(Vector<T, 2>*)this - V;
}

/**
 * Subtract a vector from this swizzle. Set this swizzle (and the underlying
 * vector) to the result.
 * @param V Vector to add.
 * @return The modified vector (component-wise difference).
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::operator-=(const Vector<T, 2>& V) {
	return *this = *this + V;
}

/**
 * Multiply this swizzle by a vector.
 * @param V Vector to multiply by.
 * @return The vector product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector<T, 2> Swizzle2<T, N, E1, E2>::operator*(const Vector<T, 2>& V) const {
	return *(Vector<T, 2>*)this * V;
}

/**
 * Multiply this swizzle by a vector. Set this swizzle (and the underlying
 * vector) to the result.
 * @param V Vector to multiply by.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::operator*=(const Vector<T, 2>& V) {
	return *this = *this * V;
}

/**
 * Divide this swizzle by a vector.
 * @param V Vector to divide by.
 * @return The vector quotient.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector<T, 2> Swizzle2<T, N, E1, E2>::operator/(const Vector<T, 2>& V) const {
	return *(Vector<T, 2>*)this / V;
}

/**
 * Divide this swizzle by a vector. Set this swizzle (and the underlying vector)
 * to the result.
 * @param V Vector to multiply by.
 * @return The modified vector.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::operator/=(const Vector<T, 2>& V) {
	return *this = *this / V;
}

/**
 * Vector-scalar multiplication.
 * @param s Scalar to multiply by.
 * @return The vector-scalar product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector<T, 2> Swizzle2<T, N, E1, E2>::operator*(const T& s) const {
	return *(Vector<T, 2>*)this * s;
}

/**
 * Vector-scalar multiplication. Set this swizzle (and the underlying vector) to
 * the result.
 * @param s Scalar to multipy by.
 * @return The vector-scalar product.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::operator*=(const T& s) {
	return *this = *this * s;
}

/**
 * Vector-scalar division.
 * @param s Scalar to divide by.
 * @return The vector-scalar quotient.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
Vector<T, 2> Swizzle2<T, N, E1, E2>::operator/(const T& s) const {
	return *(Vector<T, 2>*)this / s;
}

/**
 * Vector-scalar division. Set this swizzle (and the underlying vector) to the
 * result.
 * @param s Scalar to multiply by.
 * @return The vector-scalar quotient.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
template<typename U, typename>
Vector<T, 2>& Swizzle2<T, N, E1, E2>::operator/=(const T& s) {
	return *this = *this / s;
}

/**
 * Check swizzle-vector equality.
 * @param V Vector to check equality with.
 * @return True if they are equal, otherwise false.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
bool Swizzle2<T, N, E1, E2>::operator==(const Vector<T, 2>& V) const {
	return *(Vector<T, 2>*)this == V;
}

/**
 * Check swizzle-vector inequality.
 * @param V Vector to check inequality with.
 * @return False if they are equal, otherwise true.
 */
template<typename T, std::size_t N, std::size_t E1, std::size_t E2>
bool Swizzle2<T, N, E1, E2>::operator!=(const Vector<T, 2>& V) const {
	return *(Vector<T, 2>*)this != V;
}

#endif
