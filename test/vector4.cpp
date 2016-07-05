#include <boost/test/test_case_template.hpp>
#include <boost/test/unit_test.hpp>

#include <stdexcept>
#include <vmath/core/vector.hpp>
#include "type_lists.hpp"

BOOST_AUTO_TEST_SUITE(vector4)

BOOST_AUTO_TEST_CASE_TEMPLATE(size, T, float_types) {
	BOOST_CHECK(sizeof(vmath::core::Vector<T, 4>) == 4 * sizeof(T));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(create, T, float_types) {
	// default constructor
	vmath::core::Vector<T, 4> V_default;
	BOOST_CHECK_SMALL(V_default.x, static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(V_default.y, static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(V_default.z, static_cast<T>(1e-7));
	// parameterized constructor
	vmath::core::Vector<T, 4> V_param(static_cast<T>(1.0), static_cast<T>(2.0), static_cast<T>(3.0), static_cast<T>(4.0));
	BOOST_CHECK_CLOSE(V_param.x, static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(V_param.y, static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(V_param.z, static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(V_param.w, static_cast<T>(4.0), 1e-4f);
	// copy vector2
	vmath::core::Vector<T, 2> V2;
	V2.x = static_cast<T>(4.0);
	V2.y = static_cast<T>(3.0);
	vmath::core::Vector<T, 4> V_param2(V2, static_cast<T>(2.0), static_cast<T>(1.0));
	BOOST_CHECK_CLOSE(V_param2.x, static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(V_param2.y, static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(V_param2.z, static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(V_param2.w, static_cast<T>(1.0), 1e-4f);
	// copy vector3
	vmath::core::Vector<T, 3> V3;
	V3.x = static_cast<T>(4.0);
	V3.y = static_cast<T>(3.0);
	V3.z = static_cast<T>(2.0);
	vmath::core::Vector<T, 4> V_param3(V3, static_cast<T>(1.0));
	BOOST_CHECK_CLOSE(V_param3.x, static_cast<T>(4.0), 1e-4f);
	BOOST_CHECK_CLOSE(V_param3.y, static_cast<T>(3.0), 1e-4f);
	BOOST_CHECK_CLOSE(V_param3.z, static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(V_param3.w, static_cast<T>(1.0), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(copy, T, float_types) {
	vmath::core::Vector<T, 4> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	V.z = static_cast<T>(-18.2);
	V.w = static_cast<T>(35.63);
	vmath::core::Vector<T, 4> V_copy(V);
	BOOST_CHECK_CLOSE(V_copy.x, V.x, 1e-4f);
	BOOST_CHECK_CLOSE(V_copy.y, V.y, 1e-4f);
	BOOST_CHECK_CLOSE(V_copy.z, V.z, 1e-4f);
	BOOST_CHECK_CLOSE(V_copy.w, V.w, 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(move, T, float_types) {
	vmath::core::Vector<T, 4> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	V.z = static_cast<T>(-18.2);
	V.w = static_cast<T>(35.62);
	vmath::core::Vector<T, 4> V_move(std::move(V));
	BOOST_CHECK_CLOSE(V_move.x, V.x, 1e-4f);
	BOOST_CHECK_CLOSE(V_move.y, V.y, 1e-4f);
	BOOST_CHECK_CLOSE(V_move.z, V.z, 1e-4f);
	BOOST_CHECK_CLOSE(V_move.w, V.w, 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(members, T, float_types) {
	vmath::core::Vector<T, 4> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	V.z = static_cast<T>(-18.2);
	V.w = static_cast<T>(35.62);
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-4f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-4f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V.b, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V.p, 1e-4f);
	BOOST_CHECK_CLOSE(V.b, V.p, 1e-4f);
	BOOST_CHECK_CLOSE(V.w, V.a, 1e-4f);
	BOOST_CHECK_CLOSE(V.w, V.q, 1e-4f);
	BOOST_CHECK_CLOSE(V.a, V.q, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.x, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.r, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.y, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.g, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.t, 1e-4f);
	BOOST_CHECK_CLOSE(V[2], V.z, 1e-4f);
	BOOST_CHECK_CLOSE(V[2], V.b, 1e-4f);
	BOOST_CHECK_CLOSE(V[2], V.p, 1e-4f);
	BOOST_CHECK_CLOSE(V[3], V.w, 1e-4f);
	BOOST_CHECK_CLOSE(V[3], V.a, 1e-4f);
	BOOST_CHECK_CLOSE(V[3], V.q, 1e-4f);
	V.r = static_cast<T>(35.62);
	V.g = static_cast<T>(20.12);
	V.b = static_cast<T>(100.89);
	V.a = static_cast<T>(-18.2);
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-4f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-4f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V.b, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V.p, 1e-4f);
	BOOST_CHECK_CLOSE(V.b, V.p, 1e-4f);
	BOOST_CHECK_CLOSE(V.w, V.a, 1e-4f);
	BOOST_CHECK_CLOSE(V.w, V.q, 1e-4f);
	BOOST_CHECK_CLOSE(V.a, V.q, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.x, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.r, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.y, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.g, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.t, 1e-4f);
	BOOST_CHECK_CLOSE(V[2], V.z, 1e-4f);
	BOOST_CHECK_CLOSE(V[2], V.b, 1e-4f);
	BOOST_CHECK_CLOSE(V[2], V.p, 1e-4f);
	BOOST_CHECK_CLOSE(V[3], V.w, 1e-4f);
	BOOST_CHECK_CLOSE(V[3], V.a, 1e-4f);
	BOOST_CHECK_CLOSE(V[3], V.q, 1e-4f);
	V.s = static_cast<T>(-18.2);
	V.t = static_cast<T>(35.62);
	V.p = static_cast<T>(20.12);
	V.a = static_cast<T>(100.89);
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-4f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-4f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V.b, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V.p, 1e-4f);
	BOOST_CHECK_CLOSE(V.b, V.p, 1e-4f);
	BOOST_CHECK_CLOSE(V.w, V.a, 1e-4f);
	BOOST_CHECK_CLOSE(V.w, V.q, 1e-4f);
	BOOST_CHECK_CLOSE(V.a, V.q, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.x, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.r, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.y, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.g, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.t, 1e-4f);
	BOOST_CHECK_CLOSE(V[2], V.z, 1e-4f);
	BOOST_CHECK_CLOSE(V[2], V.b, 1e-4f);
	BOOST_CHECK_CLOSE(V[2], V.p, 1e-4f);
	BOOST_CHECK_CLOSE(V[3], V.w, 1e-4f);
	BOOST_CHECK_CLOSE(V[3], V.a, 1e-4f);
	BOOST_CHECK_CLOSE(V[3], V.q, 1e-4f);
	V[0] = static_cast<T>(100.89);
	V[1] = static_cast<T>(-18.2);
	V[2] = static_cast<T>(35.62);
	V[3] = static_cast<T>(20.12);
	BOOST_CHECK_CLOSE(V.x, V.r, 1e-4f);
	BOOST_CHECK_CLOSE(V.x, V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V.r, V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V.g, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V.t, 1e-4f);
	BOOST_CHECK_CLOSE(V.g, V.t, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V.b, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V.p, 1e-4f);
	BOOST_CHECK_CLOSE(V.b, V.p, 1e-4f);
	BOOST_CHECK_CLOSE(V.w, V.a, 1e-4f);
	BOOST_CHECK_CLOSE(V.w, V.q, 1e-4f);
	BOOST_CHECK_CLOSE(V.a, V.q, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.x, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.r, 1e-4f);
	BOOST_CHECK_CLOSE(V[0], V.s, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.y, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.g, 1e-4f);
	BOOST_CHECK_CLOSE(V[1], V.t, 1e-4f);
	BOOST_CHECK_CLOSE(V[2], V.z, 1e-4f);
	BOOST_CHECK_CLOSE(V[2], V.b, 1e-4f);
	BOOST_CHECK_CLOSE(V[2], V.p, 1e-4f);
	BOOST_CHECK_CLOSE(V[3], V.w, 1e-4f);
	BOOST_CHECK_CLOSE(V[3], V.a, 1e-4f);
	BOOST_CHECK_CLOSE(V[3], V.q, 1e-4f);
	// invalid index
	BOOST_CHECK_THROW(V[4], std::out_of_range);
	BOOST_CHECK_THROW(V[4] = static_cast<T>(0.0), std::out_of_range);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(assign_op, T, float_types) {
	vmath::core::Vector<T, 4> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	V.z = static_cast<T>(-18.2);
	V.w = static_cast<T>(35.62);
	vmath::core::Vector<T, 4> V_assign;
	V_assign = V;
	BOOST_CHECK_CLOSE(V_assign.x, V.x, 1e-4f);
	BOOST_CHECK_CLOSE(V_assign.y, V.y, 1e-4f);
	BOOST_CHECK_CLOSE(V_assign.z, V.z, 1e-4f);
	BOOST_CHECK_CLOSE(V_assign.w, V.w, 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(negate_op, T, float_types) {
	vmath::core::Vector<T, 4> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	V.z = static_cast<T>(-18.2);
	V.w = static_cast<T>(35.62);
	vmath::core::Vector<T, 4> V_neg;
	V_neg = -V;
	BOOST_CHECK_CLOSE(V_neg.x, static_cast<T>(-20.12), 1e-4f);
	BOOST_CHECK_CLOSE(V_neg.y, static_cast<T>(-100.89), 1e-4f);
	BOOST_CHECK_CLOSE(V_neg.z, static_cast<T>(18.2), 1e-4f);
	BOOST_CHECK_CLOSE(V_neg.w, static_cast<T>(-35.62), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(add_op, T, float_types) {
	vmath::core::Vector<T, 4> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	V1.z = static_cast<T>(-18.2);
	V1.w = static_cast<T>(35.62);
	vmath::core::Vector<T, 4> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	V2.z = static_cast<T>(20.2);
	V2.w = static_cast<T>(-200.34);
	vmath::core::Vector<T, 4> V_add;
	V_add = V1 + V2;
	BOOST_CHECK_CLOSE(V_add.x, static_cast<T>(30.46), 1e-4f);
	BOOST_CHECK_CLOSE(V_add.y, static_cast<T>(85.39), 1e-4f);
	BOOST_CHECK_CLOSE(V_add.z, static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(V_add.w, static_cast<T>(-164.72), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(add_eq_op, T, float_types) {
	vmath::core::Vector<T, 4> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	V1.z = static_cast<T>(-18.2);
	V1.w = static_cast<T>(35.62);
	vmath::core::Vector<T, 4> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	V2.z = static_cast<T>(20.2);
	V2.w = static_cast<T>(-200.34);
	vmath::core::Vector<T, 4> V_add = V1;
	V_add += V2;
	BOOST_CHECK_CLOSE(V_add.x, static_cast<T>(30.46), 1e-4f);
	BOOST_CHECK_CLOSE(V_add.y, static_cast<T>(85.39), 1e-4f);
	BOOST_CHECK_CLOSE(V_add.z, static_cast<T>(2.0), 1e-4f);
	BOOST_CHECK_CLOSE(V_add.w, static_cast<T>(-164.72), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(sub_op, T, float_types) {
	vmath::core::Vector<T, 4> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	V1.z = static_cast<T>(-18.2);
	V1.w = static_cast<T>(35.62);
	vmath::core::Vector<T, 4> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	V2.z = static_cast<T>(20.2);
	V2.w = static_cast<T>(-200.34);
	vmath::core::Vector<T, 4> V_sub;
	V_sub = V1 - V2;
	BOOST_CHECK_CLOSE(V_sub.x, static_cast<T>(9.78), 1e-4f);
	BOOST_CHECK_CLOSE(V_sub.y, static_cast<T>(116.39), 1e-4f);
	BOOST_CHECK_CLOSE(V_sub.z, static_cast<T>(-38.4), 1e-4f);
	BOOST_CHECK_CLOSE(V_sub.w, static_cast<T>(235.96), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(sub_eq_op, T, float_types) {
	vmath::core::Vector<T, 4> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	V1.z = static_cast<T>(-18.2);
	V1.w = static_cast<T>(35.62);
	vmath::core::Vector<T, 4> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	V2.z = static_cast<T>(20.2);
	V2.w = static_cast<T>(-200.34);
	vmath::core::Vector<T, 4> V_sub = V1;
	V_sub -= V2;
	BOOST_CHECK_CLOSE(V_sub.x, static_cast<T>(9.78), 1e-4f);
	BOOST_CHECK_CLOSE(V_sub.y, static_cast<T>(116.39), 1e-4f);
	BOOST_CHECK_CLOSE(V_sub.z, static_cast<T>(-38.4), 1e-4f);
	BOOST_CHECK_CLOSE(V_sub.w, static_cast<T>(235.96), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mult_op, T, float_types) {
	vmath::core::Vector<T, 4> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	V1.z = static_cast<T>(-18.2);
	V1.w = static_cast<T>(35.62);
	vmath::core::Vector<T, 4> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	V2.z = static_cast<T>(20.2);
	V2.w = static_cast<T>(-200.34);
	vmath::core::Vector<T, 4> V_mult;
	V_mult = V1 * V2;
	BOOST_CHECK_CLOSE(V_mult.x, static_cast<T>(208.0408), 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.y, static_cast<T>(-1563.795), 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.z, static_cast<T>(-367.64), 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.w, static_cast<T>(-7136.11079999999995), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mult_eq_op, T, float_types) {
	vmath::core::Vector<T, 4> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	V1.z = static_cast<T>(-18.2);
	V1.w = static_cast<T>(35.62);
	vmath::core::Vector<T, 4> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	V2.z = static_cast<T>(20.2);
	V2.w = static_cast<T>(-200.34);
	vmath::core::Vector<T, 4> V_mult = V1;
	V_mult *= V2;
	BOOST_CHECK_CLOSE(V_mult.x, static_cast<T>(208.0408), 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.y, static_cast<T>(-1563.795), 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.z, static_cast<T>(-367.64), 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.w, static_cast<T>(-7136.11079999999995), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(div_op, T, float_types) {
	vmath::core::Vector<T, 4> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	V1.z = static_cast<T>(-18.2);
	V1.w = static_cast<T>(35.62);
	vmath::core::Vector<T, 4> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	V2.z = static_cast<T>(20.2);
	V2.w = static_cast<T>(-200.34);
	vmath::core::Vector<T, 4> V_div;
	V_div = V1 / V2;
	BOOST_CHECK_CLOSE(V_div.x, static_cast<T>(1.9458413926499034), 1e-4f);
	BOOST_CHECK_CLOSE(V_div.y, static_cast<T>(-6.509032258064516), 1e-4f);
	BOOST_CHECK_CLOSE(V_div.z, static_cast<T>(-0.900990099009901), 1e-4f);
	BOOST_CHECK_CLOSE(V_div.w, static_cast<T>(-0.17779774383547967), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(div_eq_op, T, float_types) {
	vmath::core::Vector<T, 4> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	V1.z = static_cast<T>(-18.2);
	V1.w = static_cast<T>(35.62);
	vmath::core::Vector<T, 4> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	V2.z = static_cast<T>(20.2);
	V2.w = static_cast<T>(-200.34);
	vmath::core::Vector<T, 4> V_div = V1;
	V_div /= V2;
	BOOST_CHECK_CLOSE(V_div.x, static_cast<T>(1.9458413926499034), 1e-4f);
	BOOST_CHECK_CLOSE(V_div.y, static_cast<T>(-6.509032258064516), 1e-4f);
	BOOST_CHECK_CLOSE(V_div.z, static_cast<T>(-0.900990099009901), 1e-4f);
	BOOST_CHECK_CLOSE(V_div.w, static_cast<T>(-0.17779774383547967), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult_op, T, float_types) {
	vmath::core::Vector<T, 4> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	V.z = static_cast<T>(-18.2);
	V.w = static_cast<T>(35.62);
	T s = static_cast<T>(-34.45);
	vmath::core::Vector<T, 4> V_mult;
	V_mult = V * s;
	BOOST_CHECK_CLOSE(V_mult.x, static_cast<T>(-693.134), 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.y, static_cast<T>(-3475.6605), 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.z, static_cast<T>(626.99), 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.w, static_cast<T>(-1227.109), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_mult_eq_op, T, float_types) {
	vmath::core::Vector<T, 4> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	V.z = static_cast<T>(-18.2);
	V.w = static_cast<T>(35.62);
	T s = static_cast<T>(-34.45);
	vmath::core::Vector<T, 4> V_mult = V;
	V_mult *= s;
	BOOST_CHECK_CLOSE(V_mult.x, static_cast<T>(-693.134), 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.y, static_cast<T>(-3475.6605), 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.z, static_cast<T>(626.99), 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.w, static_cast<T>(-1227.109), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div_op, T, float_types) {
	vmath::core::Vector<T, 4> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	V.z = static_cast<T>(-18.2);
	V.w = static_cast<T>(35.62);
	T s = static_cast<T>(-34.45);
	vmath::core::Vector<T, 4> V_div;
	V_div = V / s;
	BOOST_CHECK_CLOSE(V_div.x, static_cast<T>(-0.5840348330914369), 1e-4f);
	BOOST_CHECK_CLOSE(V_div.y, static_cast<T>(-2.9285921625544264), 1e-4f);
	BOOST_CHECK_CLOSE(V_div.z, static_cast<T>(0.5283018867924527), 1e-4f);
	BOOST_CHECK_CLOSE(V_div.w, static_cast<T>(-1.0339622641509432), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(scalar_div_eq_op, T, float_types) {
	vmath::core::Vector<T, 4> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	V.z = static_cast<T>(-18.2);
	V.w = static_cast<T>(35.62);
	T s = static_cast<T>(-34.45);
	vmath::core::Vector<T, 4> V_div = V;
	V_div /= s;
	BOOST_CHECK_CLOSE(V_div.x, static_cast<T>(-0.5840348330914369), 1e-4f);
	BOOST_CHECK_CLOSE(V_div.y, static_cast<T>(-2.9285921625544264), 1e-4f);
	BOOST_CHECK_CLOSE(V_div.z, static_cast<T>(0.5283018867924527), 1e-4f);
	BOOST_CHECK_CLOSE(V_div.w, static_cast<T>(-1.0339622641509432), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mag, T, float_types) {
	vmath::core::Vector<T, 4> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	V.z = static_cast<T>(-18.2);
	V.w = static_cast<T>(35.62);
	T mag = V.mag();
	BOOST_CHECK_CLOSE(mag, static_cast<T>(110.37948586580751), 1e-4f);
	V.x = static_cast<T>(1.0);
	V.y = static_cast<T>(0.0);
	V.z = static_cast<T>(0.0);
	V.w = static_cast<T>(0.0);
	mag = V.mag();
	BOOST_CHECK_CLOSE(mag, static_cast<T>(1.0), 1e-4f);
	V.x = static_cast<T>(0.0);
	V.y = static_cast<T>(0.0);
	V.z = static_cast<T>(0.0);
	V.w = static_cast<T>(0.0);
	mag = V.mag();
	BOOST_CHECK_SMALL(mag, static_cast<T>(1e-7));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(mag2, T, float_types) {
	vmath::core::Vector<T, 4> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	V.z = static_cast<T>(-18.2);
	V.w = static_cast<T>(35.62);
	T mag2 = V.mag2();
	BOOST_CHECK_CLOSE(mag2, static_cast<T>(12183.6309), 1e-4f);
	V.x = static_cast<T>(1.0);
	V.y = static_cast<T>(0.0);
	V.z = static_cast<T>(0.0);
	V.w = static_cast<T>(0.0);
	mag2 = V.mag2();
	BOOST_CHECK_CLOSE(mag2, static_cast<T>(1.0), 1e-4f);
	V.x = static_cast<T>(0.0);
	V.y = static_cast<T>(0.0);
	V.z = static_cast<T>(0.0);
	V.w = static_cast<T>(0.0);
	mag2 = V.mag2();
	BOOST_CHECK_SMALL(mag2, static_cast<T>(1e-7));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(normal, T, float_types) {
	vmath::core::Vector<T, 4> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	V.z = static_cast<T>(-18.2);
	V.w = static_cast<T>(35.62);
	vmath::core::Vector<T, 4> V_norm(V.normal());
	BOOST_CHECK_CLOSE(V_norm.x, static_cast<T>(0.18228024747696905), 1e-4f);
	BOOST_CHECK_CLOSE(V_norm.y, static_cast<T>(0.914028537145233), 1e-4f);
	BOOST_CHECK_CLOSE(V_norm.z, static_cast<T>(-0.16488571093841137), 1e-4f);
	BOOST_CHECK_CLOSE(V_norm.w, static_cast<T>(0.32270489140803366), 2e-5f);
	V.x = static_cast<T>(1.0);
	V.y = static_cast<T>(0.0);
	V.z = static_cast<T>(0.0);
	V.w = static_cast<T>(0.0);
	V_norm = V.normal();
	BOOST_CHECK_CLOSE(V_norm.x, static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_SMALL(V_norm.y, static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(V_norm.z, static_cast<T>(1e-7));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(normalize, T, float_types) {
	vmath::core::Vector<T, 4> V;
	V.x = static_cast<T>(20.12);
	V.y = static_cast<T>(100.89);
	V.z = static_cast<T>(-18.2);
	V.w = static_cast<T>(35.62);
	V.normalize();
	BOOST_CHECK_CLOSE(V.x, static_cast<T>(0.18228024747696905), 1e-4f);
	BOOST_CHECK_CLOSE(V.y, static_cast<T>(0.914028537145233), 1e-4f);
	BOOST_CHECK_CLOSE(V.z, static_cast<T>(-0.16488571093841137), 1e-4f);
	BOOST_CHECK_CLOSE(V.w, static_cast<T>(0.32270489140803366), 2e-5f);
	V.x = static_cast<T>(1.0);
	V.y = static_cast<T>(0.0);
	V.z = static_cast<T>(0.0);
	V.w = static_cast<T>(0.0);
	vmath::core::Vector<T, 4> V_norm;
	V_norm = V.normalize();
	BOOST_CHECK_CLOSE(V_norm.x, static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_SMALL(V.y, static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(V.z, static_cast<T>(1e-7));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals, T, float_types) {
	vmath::core::Vector<T, 4> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	V1.z = static_cast<T>(-18.2);
	V1.w = static_cast<T>(35.62);
	vmath::core::Vector<T, 4> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	V2.z = static_cast<T>(20.2);
	V2.w = static_cast<T>(-200.34);
	vmath::core::Vector<T, 4> V3;
	V3.x = static_cast<T>(20.12);
	V3.y = static_cast<T>(100.89);
	V3.z = static_cast<T>(-18.2);
	V3.w = static_cast<T>(35.62);
	BOOST_CHECK(!V1.equals(V2));
	BOOST_CHECK(!V2.equals(V3));
	BOOST_CHECK(V1.equals(V1));
	BOOST_CHECK(V1.equals(V3));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals_specify_ulp, T, float_types) {
	vmath::core::Vector<T, 4> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	V1.z = static_cast<T>(-18.2);
	V1.w = static_cast<T>(35.62);
	vmath::core::Vector<T, 4> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	V2.z = static_cast<T>(20.2);
	V2.w = static_cast<T>(-200.34);
	vmath::core::Vector<T, 4> V3;
	V3.x = static_cast<T>(20.12);
	V3.y = static_cast<T>(100.89);
	V3.z = static_cast<T>(-18.2);
	V3.w = static_cast<T>(35.62);
	BOOST_CHECK(!V1.equals(V2, 3));
	BOOST_CHECK(!V2.equals(V3, 3));
	BOOST_CHECK(V1.equals(V1, 3));
	BOOST_CHECK(V1.equals(V3, 3));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(equals_op, T, float_types) {
	vmath::core::Vector<T, 4> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	V1.z = static_cast<T>(-18.2);
	V1.w = static_cast<T>(35.62);
	vmath::core::Vector<T, 4> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	V2.z = static_cast<T>(20.2);
	V2.w = static_cast<T>(-200.34);
	vmath::core::Vector<T, 4> V3;
	V3.x = static_cast<T>(20.12);
	V3.y = static_cast<T>(100.89);
	V3.z = static_cast<T>(-18.2);
	V3.w = static_cast<T>(35.62);
	BOOST_CHECK(V1 != V2);
	BOOST_CHECK(V2 != V3);
	BOOST_CHECK(V1 == V1);
	BOOST_CHECK(V1 == V3);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(dot, T, float_types) {
	vmath::core::Vector<T, 4> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	V1.z = static_cast<T>(-18.2);
	V1.w = static_cast<T>(35.62);
	vmath::core::Vector<T, 4> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	V2.z = static_cast<T>(20.2);
	V2.w = static_cast<T>(-200.34);
	T dot = vmath::core::Vector<T, 4>::dot(V1, V2);
	BOOST_CHECK_CLOSE(dot, static_cast<T>(-8859.505), 1e-4f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(reflect, T, float_types) {
	vmath::core::Vector<T, 4> I;
	I.x = static_cast<T>(-1.0);
	I.y = static_cast<T>(-1.0);
	I.z = static_cast<T>(0.0);
	I.w = static_cast<T>(0.0);
	vmath::core::Vector<T, 4> N;
	N.x = static_cast<T>(1.0);
	N.y = static_cast<T>(0.0);
	N.z = static_cast<T>(0.0);
	N.w = static_cast<T>(0.0);
	vmath::core::Vector<T, 4> R = vmath::core::Vector<T, 4>::reflect(I, N);
	BOOST_CHECK_CLOSE(R.x, static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(R.y, static_cast<T>(-1.0), 1e-4f);
	BOOST_CHECK_SMALL(R.z, static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(R.w, static_cast<T>(1e-7));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(refract, T, float_types) {
	vmath::core::Vector<T, 4> I;
	I.x = static_cast<T>(-1.0);
	I.y = static_cast<T>(-1.0);
	I.z = static_cast<T>(0.0);
	I.w = static_cast<T>(0.0);
	vmath::core::Vector<T, 4> N;
	N.x = static_cast<T>(1.0);
	N.y = static_cast<T>(0.0);
	N.z = static_cast<T>(0.0);
	N.w = static_cast<T>(0.0);
	T eta = static_cast<T>(0.2);
	vmath::core::Vector<T, 4> R = vmath::core::Vector<T, 4>::refract(I, N, eta);
	BOOST_CHECK_CLOSE(R.x, static_cast<T>(-1.0), 1e-4f);
	BOOST_CHECK_CLOSE(R.y, static_cast<T>(-0.2), 1e-4f);
	BOOST_CHECK_SMALL(R.z, static_cast<T>(1e-7));
	BOOST_CHECK_SMALL(R.w, static_cast<T>(1e-7));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(lerp, T, float_types) {
	vmath::core::Vector<T, 4> V1;
	V1.x = static_cast<T>(20.12);
	V1.y = static_cast<T>(100.89);
	V1.z = static_cast<T>(-18.2);
	V1.w = static_cast<T>(35.62);
	vmath::core::Vector<T, 4> V2;
	V2.x = static_cast<T>(10.34);
	V2.y = static_cast<T>(-15.5);
	V2.z = static_cast<T>(20.2);
	V2.w = static_cast<T>(-200.34);
	vmath::core::Vector<T, 4> V_lerp;
	V_lerp = vmath::core::Vector<T, 4>::lerp(V1, V2, 0.5f);
	BOOST_CHECK_CLOSE(V_lerp.x, static_cast<T>(15.23), 1e-4f);
	BOOST_CHECK_CLOSE(V_lerp.y, static_cast<T>(42.695), 1e-4f);
	BOOST_CHECK_CLOSE(V_lerp.z, static_cast<T>(1.0), 1e-4f);
	BOOST_CHECK_CLOSE(V_lerp.w, static_cast<T>(-82.36), 1e-4f);
}

BOOST_AUTO_TEST_SUITE_END()
