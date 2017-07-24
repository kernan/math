#ifndef VMATH_MATRIX3X2_HPP
#define VMATH_MATRIX3X2_HPP

#include <array>
#include <ostream>
#include <type_traits>
#include <vmath/matrix.hpp>
#include <vmath/vector3.hpp>

// TODO
#define VMATH_MATRIX3X2_BINARY_OPERATOR(OP)
#define VMATH_MATRIX3X2_BINARY_OPERATOR_ASSIGN(OP)
#define VMATH_MATRIX3X2_BINARY_SCALAR_OPERATOR(OP)
#define VMATH_MATRIX3X2_BINARY_SCALAR_OPERATOR_ASSIGN(OP)

namespace vmath {

/*!
 * Matrix specialization for 3x2 matrix in column-major form
 */
template<typename T>
class Matrix<T, 3, 2> {
public:
	std::array<Vector<T, 3>, 2> data;

	Matrix() : data() {}
	Matrix(const Vector<T, 3>& a, const Vector<T, 3>& b) : data({a, b}) {}
	explicit Matrix(const std::array<Vector<T, 3>, 2>& data) : data(data) {}

	Vector<T, 3> operator[](const std::size_t i) const {
		return this->data.at(i);
	}
	
	Vector<T, 3>& operator[](const std::size_t i) {
		return this->data.at(i);
	}

	VMATH_MATRIX3X2_BINARY_OPERATOR_ASSIGN(+=)
	VMATH_MATRIX3X2_BINARY_OPERATOR_ASSIGN(-=)

	VMATH_MATRIX3X2_BINARY_SCALAR_OPERATOR_ASSIGN(*=)
	VMATH_MATRIX3X2_BINARY_SCALAR_OPERATOR_ASSIGN(/=)
};

VMATH_MATRIX3X2_BINARY_OPERATOR(+)
VMATH_MATRIX3X2_BINARY_OPERATOR(-)

VMATH_MATRIX3X2_BINARY_SCALAR_OPERATOR(*)
VMATH_MATRIX3X2_BINARY_SCALAR_OPERATOR(/)

template<typename T>
bool operator==(const Matrix<T, 3, 2>& lhs, const Matrix<T, 3, 2>& rhs) {
	return lhs[0] == rhs[0] && lhs[1] == rhs[1];
}

template<typename T>
bool operator!=(const Matrix<T, 3, 2>& lhs, const Matrix<T, 3, 2>& rhs) {
	return !(lhs == rhs);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T, 3, 2>& m) {
	os << "[" << m[0] << "," << m[1] << "]";
}

} // namespace vmath

#undef VMATH_MATRIX3X2_BINARY_OPERATOR
#undef VMATH_MATRIX3X2_BINARY_OPERATOR_ASSIGN
#undef VMATH_MATRIX3X2_BINARY_SCALAR_OPERATOR
#undef VMATH_MATRIX3X2_BINARY_SCALAR_OPERATOR_ASSIGN

#endif