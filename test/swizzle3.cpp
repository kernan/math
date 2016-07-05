#include <boost/test/unit_test.hpp>

#define VMATH_CORE_SWIZZLE_ENABLE_ELEMENT_ACCESSORS
#include <vmath/core/vector.hpp>
#include <vmath/core/swizzle/swizzle3.hpp>

BOOST_AUTO_TEST_SUITE(Swizzle3)

BOOST_AUTO_TEST_CASE(negate_op) {
	vmath::core::Vector<float, 3> V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	vmath::core::Vector<float, 3> V_neg;
	V_neg = -V.yzx;
	BOOST_CHECK_CLOSE(V_neg.x, -100.89f, 1e-4f);
	BOOST_CHECK_CLOSE(V_neg.y, 18.2f, 1e-4f);
	BOOST_CHECK_CLOSE(V_neg.z, -20.12f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(add_op) {
	vmath::core::Vector<float, 3> V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	vmath::core::Vector<float, 3> V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	vmath::core::Vector<float, 3> V_add;
	V_add = V1.yxy + V2.xxx;
	BOOST_CHECK_CLOSE(V_add.x, 111.23f, 1e-4f);
	BOOST_CHECK_CLOSE(V_add.y, 30.46f, 1e-4f);
	BOOST_CHECK_CLOSE(V_add.z, 111.23f, 1e-4f);
	V_add = V2.xxx + V1.yxy;
	BOOST_CHECK_CLOSE(V_add.x, 111.23f, 1e-4f);
	BOOST_CHECK_CLOSE(V_add.y, 30.46f, 1e-4f);
	BOOST_CHECK_CLOSE(V_add.x, 111.23f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(add_eq_op) {
	vmath::core::Vector<float, 3> V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	vmath::core::Vector<float, 3> V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	vmath::core::Vector<float, 3> V_add = V1;
	V_add.yxz += V2.xxx;
	BOOST_CHECK_CLOSE(V_add.x, 30.46f, 1e-4f);
	BOOST_CHECK_CLOSE(V_add.y, 111.23f, 1e-4f);
	BOOST_CHECK_CLOSE(V_add.z, -7.859999999f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(sub_op) {
	vmath::core::Vector<float, 3> V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	vmath::core::Vector<float, 3> V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.12f;
	vmath::core::Vector<float, 3> V_sub;
	V_sub = V1.yxx - V2.xxz;
	BOOST_CHECK_CLOSE(V_sub.x, 90.55f, 1e-4f);
	BOOST_CHECK_CLOSE(V_sub.y, 9.78f, 1e-4f);
	BOOST_CHECK_SMALL(V_sub.z, 1e-7f);
	V_sub = V2.xxz - V1.yxx;
	BOOST_CHECK_CLOSE(V_sub.x, -90.55f, 1e-4f);
	BOOST_CHECK_CLOSE(V_sub.y, -9.78f, 1e-4f);
	BOOST_CHECK_SMALL(V_sub.z, 1e-7f);
}

BOOST_AUTO_TEST_CASE(sub_eq_op) {
	vmath::core::Vector<float, 3> V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	vmath::core::Vector<float, 3> V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	vmath::core::Vector<float, 3> V_sub = V1;
	V_sub.yxz -= V2.xxx;
	BOOST_CHECK_CLOSE(V_sub.x, 9.78f, 1e-4f);
	BOOST_CHECK_CLOSE(V_sub.y, 90.55f, 1e-4f);
	BOOST_CHECK_CLOSE(V_sub.z, -28.54f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(mult_op) {
	vmath::core::Vector<float, 3> V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	vmath::core::Vector<float, 3> V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	vmath::core::Vector<float, 3> V_mult;
	V_mult = V1.yxx * V2.xxx;
	BOOST_CHECK_CLOSE(V_mult.x, 1043.2026f, 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.y, 208.0408f, 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.z, 208.0408f, 1e-4f);
	V_mult = V2.xxx * V1.yxx;
	BOOST_CHECK_CLOSE(V_mult.x, 1043.2026f, 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.y, 208.0408f, 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.z, 208.0408f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(mult_eq_op) {
	vmath::core::Vector<float, 3> V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = -18.2f;
	vmath::core::Vector<float, 3> V2;
	V2.x = 10.34f;
	V2.y = -15.5f;
	V2.z = 20.2f;
	vmath::core::Vector<float, 3> V_mult = V1;
	V_mult.yxz *= V2.xyx;
	BOOST_CHECK_CLOSE(V_mult.x, -311.86f, 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.y, 1043.2026f, 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.z, -188.188f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(div_op) {
	vmath::core::Vector<float, 3> V1;
	V1.x = 20.0f;
	V1.y = 40.0f;
	V1.z = 60.0f;
	vmath::core::Vector<float, 3> V2;
	V2.x = 2.0f;
	V2.y = 4.0f;
	V2.z = 6.0f;
	vmath::core::Vector<float, 3> V_div;
	V_div = V1.yxx / V2.xxx;
	BOOST_CHECK_CLOSE(V_div.x, 20.0f, 1e-4f);
	BOOST_CHECK_CLOSE(V_div.y, 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(V_div.z, 10.0f, 1e-4f);
	V_div = V1.xxx / V2.yxx;
	BOOST_CHECK_CLOSE(V_div.x, 5.0f, 1e-4f);
	BOOST_CHECK_CLOSE(V_div.y, 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(V_div.z, 10.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(div_eq_op) {
	vmath::core::Vector<float, 3> V1;
	V1.x = 20.0f;
	V1.y = 40.0f;
	V1.z = 60.0f;
	vmath::core::Vector<float, 3> V2;
	V2.x = 2.0f;
	V2.y = 4.0f;
	V2.z = 6.0f;
	vmath::core::Vector<float, 3> V_div = V1;
	V_div.yxz /= V2.yxx;
	BOOST_CHECK_CLOSE(V_div.x, 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(V_div.y, 10.0f, 1e-4f);
	BOOST_CHECK_CLOSE(V_div.z, 30.0f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_mult_op) {
	vmath::core::Vector<float, 3> V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	float s = -34.45f;
	vmath::core::Vector<float, 3> V_mult;
	V_mult = V.xyz * s;
	BOOST_CHECK_CLOSE(V_mult.x, -693.134f, 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.y, -3475.6605f, 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.z, 626.99f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_mult_eq_op) {
	vmath::core::Vector<float, 3> V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	float s = -34.45f;
	vmath::core::Vector<float, 3> V_mult = V;
	V_mult.zyx *= s;
	BOOST_CHECK_CLOSE(V_mult.x, -693.134f, 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.y, -3475.6605f, 1e-4f);
	BOOST_CHECK_CLOSE(V_mult.z, 626.99f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_div_op) {
	vmath::core::Vector<float, 3> V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	float s = -34.45f;
	vmath::core::Vector<float, 3> V_div;
	V_div.xyz = V / s;
	BOOST_CHECK_CLOSE(V_div.x, -0.5840348330914369f, 1e-4f);
	BOOST_CHECK_CLOSE(V_div.y, -2.9285921625544264f, 1e-4f);
	BOOST_CHECK_CLOSE(V_div.z, 0.5283018867924527f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(scalar_div_eq_op) {
	vmath::core::Vector<float, 3> V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	float s = -34.45f;
	vmath::core::Vector<float, 3> V_div = V;
	V_div.zxy /= s;
	BOOST_CHECK_CLOSE(V_div.x, -0.5840348330914369f, 1e-4f);
	BOOST_CHECK_CLOSE(V_div.y, -2.9285921625544264f, 1e-4f);
	BOOST_CHECK_CLOSE(V_div.z, 0.5283018867924527f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(swizzles) {
	vmath::core::Vector<float, 3> V;
	V.x = 20.12f;
	V.y = 100.89f;
	V.z = -18.2f;
	// 2d swizzles <x, y, z>
	auto xx = V.xx;
	BOOST_CHECK_CLOSE(xx.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xx.getE2(), V.x, 1e-4f);
	auto xy = V.xy;
	BOOST_CHECK_CLOSE(xy.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xy.getE2(), V.y, 1e-4f);
	auto xz = V.xz;
	BOOST_CHECK_CLOSE(xz.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xz.getE2(), V.z, 1e-4f);
	auto yx = V.yx;
	BOOST_CHECK_CLOSE(yx.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yx.getE2(), V.x, 1e-4f);
	auto yy = V.yy;
	BOOST_CHECK_CLOSE(yy.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yy.getE2(), V.y, 1e-4f);
	auto yz = V.yz;
	BOOST_CHECK_CLOSE(yz.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yz.getE2(), V.z, 1e-4f);
	auto zx = V.zx;
	BOOST_CHECK_CLOSE(zx.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zx.getE2(), V.x, 1e-4f);
	auto zy = V.zy;
	BOOST_CHECK_CLOSE(zy.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zy.getE2(), V.y, 1e-4f);
	auto zz = V.zz;
	BOOST_CHECK_CLOSE(zz.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zz.getE2(), V.z, 1e-4f);
	// 3d swizzles <x, y, z>
	auto xxx = V.xxx;
	BOOST_CHECK_CLOSE(xxx.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxx.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxx.getE3(), V.x, 1e-4f);
	auto xxy = V.xxy;
	BOOST_CHECK_CLOSE(xxy.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxy.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxy.getE3(), V.y, 1e-4f);
	auto xxz = V.xxz;
	BOOST_CHECK_CLOSE(xxz.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxz.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxz.getE3(), V.z, 1e-4f);
	auto xyx = V.xyx;
	BOOST_CHECK_CLOSE(xyx.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyx.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyx.getE3(), V.x, 1e-4f);
	auto xyy = V.xyy;
	BOOST_CHECK_CLOSE(xyy.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyy.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyy.getE3(), V.y, 1e-4f);
	auto xyz = V.xyz;
	BOOST_CHECK_CLOSE(xyz.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyz.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyz.getE3(), V.z, 1e-4f);
	auto xzx = V.xzx;
	BOOST_CHECK_CLOSE(xzx.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xzx.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(xzx.getE3(), V.x, 1e-4f);
	auto xzy = V.xzy;
	BOOST_CHECK_CLOSE(xzy.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xzy.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(xzy.getE3(), V.y, 1e-4f);
	auto xzz = V.xzz;
	BOOST_CHECK_CLOSE(xzz.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xzz.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(xzz.getE3(), V.z, 1e-4f);
	auto yxx = V.yxx;
	BOOST_CHECK_CLOSE(yxx.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxx.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxx.getE3(), V.x, 1e-4f);
	auto yxy = V.yxy;
	BOOST_CHECK_CLOSE(yxy.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxy.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxy.getE3(), V.y, 1e-4f);
	auto yxz = V.yxz;
	BOOST_CHECK_CLOSE(yxz.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxz.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxz.getE3(), V.z, 1e-4f);
	auto yyx = V.yyx;
	BOOST_CHECK_CLOSE(yyx.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyx.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyx.getE3(), V.x, 1e-4f);
	auto yyy = V.yyy;
	BOOST_CHECK_CLOSE(yyy.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyy.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyy.getE3(), V.y, 1e-4f);
	auto yyz = V.yyz;
	BOOST_CHECK_CLOSE(yyz.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyz.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyz.getE3(), V.z, 1e-4f);
	auto yzx = V.yzx;
	BOOST_CHECK_CLOSE(yzx.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yzx.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(yzx.getE3(), V.x, 1e-4f);
	auto yzy = V.yzy;
	BOOST_CHECK_CLOSE(yzy.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yzy.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(yzy.getE3(), V.y, 1e-4f);
	auto yzz = V.yzz;
	BOOST_CHECK_CLOSE(yzz.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yzz.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(yzz.getE3(), V.z, 1e-4f);
	auto zxx = V.zxx;
	BOOST_CHECK_CLOSE(zxx.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zxx.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(zxx.getE3(), V.x, 1e-4f);
	auto zxy = V.zxy;
	BOOST_CHECK_CLOSE(zxy.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zxy.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(zxy.getE3(), V.y, 1e-4f);
	auto zxz = V.zxz;
	BOOST_CHECK_CLOSE(zxz.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zxz.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(zxz.getE3(), V.z, 1e-4f);
	auto zyx = V.zyx;
	BOOST_CHECK_CLOSE(zyx.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zyx.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(zyx.getE3(), V.x, 1e-4f);
	auto zyy = V.zyy;
	BOOST_CHECK_CLOSE(zyy.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zyy.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(zyy.getE3(), V.y, 1e-4f);
	auto zyz = V.zyz;
	BOOST_CHECK_CLOSE(zyz.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zyz.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(zyz.getE3(), V.z, 1e-4f);
	auto zzx = V.zzx;
	BOOST_CHECK_CLOSE(zzx.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzx.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzx.getE3(), V.x, 1e-4f);
	auto zzy = V.zzy;
	BOOST_CHECK_CLOSE(zzy.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzy.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzy.getE3(), V.y, 1e-4f);
	auto zzz = V.zzz;
	BOOST_CHECK_CLOSE(zzz.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzz.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzz.getE3(), V.z, 1e-4f);
	// 4d swizzles <x, y, z>
	auto xxxx = V.xxxx;
	BOOST_CHECK_CLOSE(xxxx.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxxx.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxxx.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxxx.getE4(), V.x, 1e-4f);
	auto xxxy = V.xxxy;
	BOOST_CHECK_CLOSE(xxxy.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxxy.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxxy.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxxy.getE4(), V.y, 1e-4f);
	auto xxxz = V.xxxz;
	BOOST_CHECK_CLOSE(xxxz.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxxz.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxxz.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxxz.getE4(), V.z, 1e-4f);
	auto xxyx = V.xxyx;
	BOOST_CHECK_CLOSE(xxyx.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxyx.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxyx.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xxyx.getE4(), V.x, 1e-4f);
	auto xxyy = V.xxyy;
	BOOST_CHECK_CLOSE(xxyy.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxyy.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxyy.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xxyy.getE4(), V.y, 1e-4f);
	auto xxyz = V.xxyz;
	BOOST_CHECK_CLOSE(xxyz.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxyz.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxyz.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xxyz.getE4(), V.z, 1e-4f);
	auto xxzx = V.xxzx;
	BOOST_CHECK_CLOSE(xxzx.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxzx.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxzx.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(xxzx.getE4(), V.x, 1e-4f);
	auto xxzy = V.xxzy;
	BOOST_CHECK_CLOSE(xxzy.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxzy.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxzy.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(xxzy.getE4(), V.y, 1e-4f);
	auto xxzz = V.xxzz;
	BOOST_CHECK_CLOSE(xxzz.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxzz.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xxzz.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(xxzz.getE4(), V.z, 1e-4f);
	auto xyxx = V.xyxx;
	BOOST_CHECK_CLOSE(xyxx.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyxx.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyxx.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyxx.getE4(), V.x, 1e-4f);
	auto xyxy = V.xyxy;
	BOOST_CHECK_CLOSE(xyxy.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyxy.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyxy.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyxy.getE4(), V.y, 1e-4f);
	auto xyxz = V.xyxz;
	BOOST_CHECK_CLOSE(xyxz.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyxz.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyxz.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyxz.getE4(), V.z, 1e-4f);
	auto xyyx = V.xyyx;
	BOOST_CHECK_CLOSE(xyyx.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyyx.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyyx.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyyx.getE4(), V.x, 1e-4f);
	auto xyyy = V.xyyy;
	BOOST_CHECK_CLOSE(xyyy.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyyy.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyyy.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyyy.getE4(), V.y, 1e-4f);
	auto xyyz = V.xyyz;
	BOOST_CHECK_CLOSE(xyyz.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyyz.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyyz.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyyz.getE4(), V.z, 1e-4f);
	auto xyzx = V.xyzx;
	BOOST_CHECK_CLOSE(xyzx.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyzx.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyzx.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(xyzx.getE4(), V.x, 1e-4f);
	auto xyzy = V.xyzy;
	BOOST_CHECK_CLOSE(xyzy.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyzy.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyzy.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(xyzy.getE4(), V.y, 1e-4f);
	auto xyzz = V.xyzz;
	BOOST_CHECK_CLOSE(xyzz.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xyzz.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xyzz.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(xyzz.getE4(), V.z, 1e-4f);
	auto xzxx = V.xzxx;
	BOOST_CHECK_CLOSE(xzxx.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xzxx.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(xzxx.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xzxx.getE4(), V.x, 1e-4f);
	auto xzxy = V.xzxy;
	BOOST_CHECK_CLOSE(xzxy.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xzxy.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(xzxy.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xzxy.getE4(), V.y, 1e-4f);
	auto xzxz = V.xzxz;
	BOOST_CHECK_CLOSE(xzxz.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xzxz.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(xzxz.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xzxz.getE4(), V.z, 1e-4f);
	auto xzyx = V.xzyx;
	BOOST_CHECK_CLOSE(xzyx.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xzyx.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(xzyx.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xzyx.getE4(), V.x, 1e-4f);
	auto xzyy = V.xzyy;
	BOOST_CHECK_CLOSE(xzyy.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xzyy.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(xzyy.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xzyy.getE4(), V.y, 1e-4f);
	auto xzyz = V.xzyz;
	BOOST_CHECK_CLOSE(xzyz.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xzyz.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(xzyz.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(xzyz.getE4(), V.z, 1e-4f);
	auto xzzx = V.xzzx;
	BOOST_CHECK_CLOSE(xzzx.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xzzx.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(xzzx.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(xzzx.getE4(), V.x, 1e-4f);
	auto xzzy = V.xzzy;
	BOOST_CHECK_CLOSE(xzzy.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xzzy.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(xzzy.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(xzzy.getE4(), V.y, 1e-4f);
	auto xzzz = V.xzzz;
	BOOST_CHECK_CLOSE(xzzz.getE1(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(xzzz.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(xzzz.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(xzzz.getE4(), V.z, 1e-4f);
	auto yxxx = V.yxxx;
	BOOST_CHECK_CLOSE(yxxx.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxxx.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxxx.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxxx.getE4(), V.x, 1e-4f);
	auto yxxy = V.yxxy;
	BOOST_CHECK_CLOSE(yxxy.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxxy.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxxy.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxxy.getE4(), V.y, 1e-4f);
	auto yxxz = V.yxxz;
	BOOST_CHECK_CLOSE(yxxz.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxxz.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxxz.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxxz.getE4(), V.z, 1e-4f);
	auto yxyx = V.yxyx;
	BOOST_CHECK_CLOSE(yxyx.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxyx.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxyx.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxyx.getE4(), V.x, 1e-4f);
	auto yxyy = V.yxyy;
	BOOST_CHECK_CLOSE(yxyy.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxyy.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxyy.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxyy.getE4(), V.y, 1e-4f);
	auto yxyz = V.yxyz;
	BOOST_CHECK_CLOSE(yxyz.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxyz.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxyz.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxyz.getE4(), V.z, 1e-4f);
	auto yxzx = V.yxzx;
	BOOST_CHECK_CLOSE(yxzx.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxzx.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxzx.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(yxzx.getE4(), V.x, 1e-4f);
	auto yxzy = V.yxzy;
	BOOST_CHECK_CLOSE(yxzy.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxzy.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxzy.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(yxzy.getE4(), V.y, 1e-4f);
	auto yxzz = V.yxzz;
	BOOST_CHECK_CLOSE(yxzz.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yxzz.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yxzz.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(yxzz.getE4(), V.z, 1e-4f);
	auto yyxx = V.yyxx;
	BOOST_CHECK_CLOSE(yyxx.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyxx.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyxx.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yyxx.getE4(), V.x, 1e-4f);
	auto yyxy = V.yyxy;
	BOOST_CHECK_CLOSE(yyxy.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyxy.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyxy.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yyxy.getE4(), V.y, 1e-4f);
	auto yyxz = V.yyxz;
	BOOST_CHECK_CLOSE(yyxz.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyxz.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyxz.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yyxz.getE4(), V.z, 1e-4f);
	auto yyyx = V.yyyx;
	BOOST_CHECK_CLOSE(yyyx.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyyx.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyyx.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyyx.getE4(), V.x, 1e-4f);
	auto yyyy = V.yyyy;
	BOOST_CHECK_CLOSE(yyyy.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyyy.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyyy.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyyy.getE4(), V.y, 1e-4f);
	auto yyyz = V.yyyz;
	BOOST_CHECK_CLOSE(yyyz.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyyz.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyyz.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyyz.getE4(), V.z, 1e-4f);
	auto yyzx = V.yyzx;
	BOOST_CHECK_CLOSE(yyzx.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyzx.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyzx.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(yyzx.getE4(), V.x, 1e-4f);
	auto yyzy = V.yyzy;
	BOOST_CHECK_CLOSE(yyzy.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyzy.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyzy.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(yyzy.getE4(), V.y, 1e-4f);
	auto yyzz = V.yyzz;
	BOOST_CHECK_CLOSE(yyzz.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyzz.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yyzz.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(yyzz.getE4(), V.z, 1e-4f);
	auto yzxx = V.yzxx;
	BOOST_CHECK_CLOSE(yzxx.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yzxx.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(yzxx.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yzxx.getE4(), V.x, 1e-4f);
	auto yzxy = V.yzxy;
	BOOST_CHECK_CLOSE(yzxy.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yzxy.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(yzxy.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yzxy.getE4(), V.y, 1e-4f);
	auto yzxz = V.yzxz;
	BOOST_CHECK_CLOSE(yzxz.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yzxz.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(yzxz.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(yzxz.getE4(), V.z, 1e-4f);
	auto yzyx = V.yzyx;
	BOOST_CHECK_CLOSE(yzyx.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yzyx.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(yzyx.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yzyx.getE4(), V.x, 1e-4f);
	auto yzyy = V.yzyy;
	BOOST_CHECK_CLOSE(yzyy.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yzyy.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(yzyy.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yzyy.getE4(), V.y, 1e-4f);
	auto yzyz = V.yzyz;
	BOOST_CHECK_CLOSE(yzyz.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yzyz.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(yzyz.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yzyz.getE4(), V.z, 1e-4f);
	auto yzzx = V.yzzx;
	BOOST_CHECK_CLOSE(yzzx.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yzzx.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(yzzx.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(yzzx.getE4(), V.x, 1e-4f);
	auto yzzy = V.yzzy;
	BOOST_CHECK_CLOSE(yzzy.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yzzy.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(yzzy.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(yzzy.getE4(), V.y, 1e-4f);
	auto yzzz = V.yzzz;
	BOOST_CHECK_CLOSE(yzzz.getE1(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(yzzz.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(yzzz.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(yzzz.getE4(), V.z, 1e-4f);
	auto zxxx = V.zxxx;
	BOOST_CHECK_CLOSE(zxxx.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zxxx.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(zxxx.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(zxxx.getE4(), V.x, 1e-4f);
	auto zxxy = V.zxxy;
	BOOST_CHECK_CLOSE(zxxy.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zxxy.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(zxxy.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(zxxy.getE4(), V.y, 1e-4f);
	auto zxxz = V.zxxz;
	BOOST_CHECK_CLOSE(zxxz.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zxxz.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(zxxz.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(zxxz.getE4(), V.z, 1e-4f);
	auto zxyx = V.zxyx;
	BOOST_CHECK_CLOSE(zxyx.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zxyx.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(zxyx.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(zxyx.getE4(), V.x, 1e-4f);
	auto zxyy = V.zxyy;
	BOOST_CHECK_CLOSE(zxyy.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zxyy.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(zxyy.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(zxyy.getE4(), V.y, 1e-4f);
	auto zxyz = V.zxyz;
	BOOST_CHECK_CLOSE(zxyz.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zxyz.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(zxyz.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(zxyz.getE4(), V.z, 1e-4f);
	auto zxzx = V.zxzx;
	BOOST_CHECK_CLOSE(zxzx.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zxzx.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(zxzx.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zxzx.getE4(), V.x, 1e-4f);
	auto zxzy = V.zxzy;
	BOOST_CHECK_CLOSE(zxzy.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zxzy.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(zxzy.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zxzy.getE4(), V.y, 1e-4f);
	auto zxzz = V.zxzz;
	BOOST_CHECK_CLOSE(zxzz.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zxzz.getE2(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(zxzz.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zxzz.getE4(), V.z, 1e-4f);
	auto zyxx = V.zyxx;
	BOOST_CHECK_CLOSE(zyxx.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zyxx.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(zyxx.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(zyxx.getE4(), V.x, 1e-4f);
	auto zyxy = V.zyxy;
	BOOST_CHECK_CLOSE(zyxy.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zyxy.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(zyxy.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(zyxy.getE4(), V.y, 1e-4f);
	auto zyxz = V.zyxz;
	BOOST_CHECK_CLOSE(zyxz.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zyxz.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(zyxz.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(zyxz.getE4(), V.z, 1e-4f);
	auto zyyx = V.zyyx;
	BOOST_CHECK_CLOSE(zyyx.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zyyx.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(zyyx.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(zyyx.getE4(), V.x, 1e-4f);
	auto zyyy = V.zyyy;
	BOOST_CHECK_CLOSE(zyyy.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zyyy.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(zyyy.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(zyyy.getE4(), V.y, 1e-4f);
	auto zyyz = V.zyyz;
	BOOST_CHECK_CLOSE(zyyz.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zyyz.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(zyyz.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(zyyz.getE4(), V.z, 1e-4f);
	auto zyzx = V.zyzx;
	BOOST_CHECK_CLOSE(zyzx.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zyzx.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(zyzx.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zyzx.getE4(), V.x, 1e-4f);
	auto zyzy = V.zyzy;
	BOOST_CHECK_CLOSE(zyzy.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zyzy.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(zyzy.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zyzy.getE4(), V.y, 1e-4f);
	auto zyzz = V.zyzz;
	BOOST_CHECK_CLOSE(zyzz.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zyzz.getE2(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(zyzz.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zyzz.getE4(), V.z, 1e-4f);
	auto zzxx = V.zzxx;
	BOOST_CHECK_CLOSE(zzxx.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzxx.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzxx.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(zzxx.getE4(), V.x, 1e-4f);
	auto zzxy = V.zzxy;
	BOOST_CHECK_CLOSE(zzxy.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzxy.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzxy.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(zzxy.getE4(), V.y, 1e-4f);
	auto zzxz = V.zzxz;
	BOOST_CHECK_CLOSE(zzxz.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzxz.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzxz.getE3(), V.x, 1e-4f);
	BOOST_CHECK_CLOSE(zzxz.getE4(), V.z, 1e-4f);
	auto zzyx = V.zzyx;
	BOOST_CHECK_CLOSE(zzyx.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzyx.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzyx.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(zzyx.getE4(), V.x, 1e-4f);
	auto zzyy = V.zzyy;
	BOOST_CHECK_CLOSE(zzyy.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzyy.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzyy.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(zzyy.getE4(), V.y, 1e-4f);
	auto zzyz = V.zzyz;
	BOOST_CHECK_CLOSE(zzyz.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzyz.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzyz.getE3(), V.y, 1e-4f);
	BOOST_CHECK_CLOSE(zzyz.getE4(), V.z, 1e-4f);
	auto zzzx = V.zzzx;
	BOOST_CHECK_CLOSE(zzzx.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzzx.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzzx.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzzx.getE4(), V.x, 1e-4f);
	auto zzzy = V.zzzy;
	BOOST_CHECK_CLOSE(zzzy.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzzy.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzzy.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzzy.getE4(), V.y, 1e-4f);
	auto zzzz = V.zzzz;
	BOOST_CHECK_CLOSE(zzzz.getE1(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzzz.getE2(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzzz.getE3(), V.z, 1e-4f);
	BOOST_CHECK_CLOSE(zzzz.getE4(), V.z, 1e-4f);
}

BOOST_AUTO_TEST_CASE(assign_op) {
	vmath::core::Vector<float, 2> V2;
	V2.x = 20.12f;
	V2.y = 100.89f;
	vmath::core::Vector<float, 3> V3;
	V3.x = 20.12f;
	V3.y = 100.89f;
	V3.z = -18.2f;
	vmath::core::Vector<float, 3> V;
	V.x = 0.0f;
	V.y = 0.0f;
	V.z = 0.0f;
	// 2d swizzle assign <x, y, z> from vector
	V.xy = V2;
	BOOST_CHECK_CLOSE(V.x, V2.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V2.y, 1e-4f);
	BOOST_CHECK_SMALL(V.z, 1e-7f);
	V.xz = V2;
	BOOST_CHECK_CLOSE(V.x, V2.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V2.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V2.y, 1e-4f);
	V.yx = V2;
	BOOST_CHECK_CLOSE(V.x, V2.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V2.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V2.y, 1e-4f);
	V.yz = V2;
	BOOST_CHECK_CLOSE(V.x, V2.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V2.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V2.y, 1e-4f);
	V.zx = V2;
	BOOST_CHECK_CLOSE(V.x, V2.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V2.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V2.x, 1e-4f);
	V.zy = V2;
	BOOST_CHECK_CLOSE(V.x, V2.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V2.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V2.x, 1e-4f);
	// 2d swizzle assign <x, y, z> from swizzle
	V.xy = V2.xx;
	BOOST_CHECK_CLOSE(V.x, V2.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V2.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V2.x, 1e-4f);
	V.xz = V2.yy;
	BOOST_CHECK_CLOSE(V.x, V2.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V2.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V2.y, 1e-4f);
	V.yx = V.xy;
	BOOST_CHECK_CLOSE(V.x, V2.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V2.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V2.y, 1e-4f);
	V.yz = V.xx;
	BOOST_CHECK_CLOSE(V.x, V2.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V2.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V2.x, 1e-4f);
	V.zx = V2.yy;
	BOOST_CHECK_CLOSE(V.x, V2.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V2.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V2.y, 1e-4f);
	V.zy = V2.xy;
	BOOST_CHECK_CLOSE(V.x, V2.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V2.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V2.x, 1e-4f);
	// 3d swizzle assign <x, y, z> from vector
	V.xyz = V3;
	BOOST_CHECK_CLOSE(V.x, V3.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V3.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V3.z, 1e-4f);
	V.xzy = V3;
	BOOST_CHECK_CLOSE(V.x, V3.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V3.z, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V3.y, 1e-4f);
	V.yxz = V3;
	BOOST_CHECK_CLOSE(V.x, V3.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V3.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V3.z, 1e-4f);
	V.yzx = V3;
	BOOST_CHECK_CLOSE(V.x, V3.z, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V3.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V3.y, 1e-4f);
	V.zxy = V3;
	BOOST_CHECK_CLOSE(V.x, V3.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V3.z, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V3.x, 1e-4f);
	V.zyx = V3;
	BOOST_CHECK_CLOSE(V.x, V3.z, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V3.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V3.x, 1e-4f);
	// 3d swizzle assign <x, y, z> from swizzle
	V.xyz = V3.xyz;
	BOOST_CHECK_CLOSE(V.x, V3.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V3.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V3.z, 1e-4f);
	V.xzy = V3.yyx;
	BOOST_CHECK_CLOSE(V.x, V3.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V3.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V3.y, 1e-4f);
	V.yxz = V3.yxy;
	BOOST_CHECK_CLOSE(V.x, V3.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V3.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V3.y, 1e-4f);
	V.yzx = V3.zzz;
	BOOST_CHECK_CLOSE(V.x, V3.z, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V3.z, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V3.z, 1e-4f);
	V.zxy = V3.xyz;
	BOOST_CHECK_CLOSE(V.x, V3.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V3.z, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V3.x, 1e-4f);
	V.zyx = V3.zyx;
	BOOST_CHECK_CLOSE(V.x, V3.x, 1e-4f);
	BOOST_CHECK_CLOSE(V.y, V3.y, 1e-4f);
	BOOST_CHECK_CLOSE(V.z, V3.z, 1e-4f);
}

BOOST_AUTO_TEST_CASE(equals) {
	vmath::core::Vector<float, 3> V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = 18.2f;
	vmath::core::Vector<float, 3> V2;
	V2.x = 10.34f;
	V2.y = 15.5f;
	V2.z = 20.2f;
	vmath::core::Vector<float, 3> V3;
	V3.x = 20.12f;
	V3.y = 100.89f;
	V3.z = 18.2f;
	BOOST_CHECK(!V1.xyz.equals(V2));
	BOOST_CHECK(!V2.xyz.equals(V3));
	BOOST_CHECK(V1.xyz.equals(V1));
	BOOST_CHECK(V1.xyz.equals(V3));
}

BOOST_AUTO_TEST_CASE(equals_specify_ulp) {
	vmath::core::Vector<float, 3> V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = 18.2f;
	vmath::core::Vector<float, 3> V2;
	V2.x = 10.34f;
	V2.y = 15.5f;
	V2.z = 20.2f;
	vmath::core::Vector<float, 3> V3;
	V3.x = 20.12f;
	V3.y = 100.89f;
	V3.z = 18.2f;
	BOOST_CHECK(!V1.xyz.equals(V2, 3));
	BOOST_CHECK(!V2.xyz.equals(V3, 3));
	BOOST_CHECK(V1.xyz.equals(V1, 3));
	BOOST_CHECK(V1.xyz.equals(V3, 3));
}

BOOST_AUTO_TEST_CASE(equals_op) {
	vmath::core::Vector<float, 3> V1;
	V1.x = 20.12f;
	V1.y = 100.89f;
	V1.z = 18.2f;
	vmath::core::Vector<float, 3> V2;
	V2.x = 10.34f;
	V2.y = 15.5f;
	V2.z = 20.2f;
	vmath::core::Vector<float, 3> V3;
	V3.x = 20.12f;
	V3.y = 100.89f;
	V3.z = 18.2f;
	BOOST_CHECK(V1.xyz != V2);
	BOOST_CHECK(V2.xyz != V3);
	BOOST_CHECK(V1.xyz == V1);
	BOOST_CHECK(V1.xyz == V3);
}

BOOST_AUTO_TEST_SUITE_END()
