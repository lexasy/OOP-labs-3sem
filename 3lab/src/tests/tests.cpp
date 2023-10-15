#include <gtest/gtest.h>
#include "../includes/figure_array.hpp"

TEST(test_01, length_between_points_test) {
    Point p1(0, 0); Point p2(1, 1);
    ASSERT_TRUE(length_btw_points(p1, p2) == sqrt(2));
}

TEST(test_02, length_between_points_test) {
    Point p1(0, 0); Point p2(0, 0);
    ASSERT_TRUE(length_btw_points(p1, p2) == 0);
}

TEST(test_03, copy_points_constructor_test)
{
    Point p1(0, 0); Point p2(0, 1); Point p3(1, 0); Point p4(1, 1); Point p5(2, 2);
    Point ptarr[5];
    ptarr[0] = p1; ptarr[1] = p2; ptarr[2] = p3; ptarr[3] = p4; ptarr[4] = p5;
    Pentagon pent(p1, p2, p3, p4, p5);
    for (int i = 0; i < 5; i++) {
        ASSERT_TRUE(pent.get_array_pointer()[i] == ptarr[i]);
    }
}

TEST(test_04, copy_points_constructor_test)
{
    Point p1(0, 0); Point p2(0, 1); Point p3(1, 0); Point p4(1, 1); Point p5(2, 2); Point p6(3, 3);
    Point ptarr[6];
    ptarr[0] = p1; ptarr[1] = p2; ptarr[2] = p3; ptarr[3] = p4; ptarr[4] = p5; ptarr[5] = p6;
    Hexagon hex(p1, p2, p3, p4, p5, p6);
    for (int i = 0; i < 6; i++) {
        ASSERT_TRUE(hex.get_array_pointer()[i] == ptarr[i]);
    }
}

TEST(test_05, copy_points_constructor_test)
{
    Point p1(0, 0); Point p2(0, 1); Point p3(1, 0); Point p4(1, 1); Point p5(2, 2); Point p6(3, 3); Point p7(4, 3); Point p8(3 ,4);
    Point ptarr[8];
    ptarr[0] = p1; ptarr[1] = p2; ptarr[2] = p3; ptarr[3] = p4; ptarr[4] = p5; ptarr[5] = p6; ptarr[6] = p7; ptarr[7] = p8;
    Octagon oct(p1, p2, p3, p4, p5, p6, p7, p8);
    for (int i = 0; i < 6; i++) {
        ASSERT_TRUE(oct.get_array_pointer()[i] == ptarr[i]);
    }
}

TEST(test_06, copy_and_compare_overloaded_operators_test)
{
    Point p3pt1(3, 0); Point p3pt2(3 * cos(2 * M_PI / 5), 3 * sin(2 * M_PI / 5)); Point p3pt3(3 * cos(4 * M_PI / 5), 3 * sin(4 * M_PI / 5)); Point p3pt4(3 * cos(6 * M_PI / 5), 3 * sin(6 * M_PI / 5)); Point p3pt5(3 * cos(8 * M_PI / 5), 3 * sin(8 * M_PI / 5));
    Pentagon pent1(p3pt1, p3pt2, p3pt3, p3pt4, p3pt5);
    Pentagon pent2; pent2 = pent1;
    ASSERT_TRUE(pent1 == pent2);
}

TEST(test_07, copy_and_compare_overloaded_operators_test)
{
    Point h1pt1(2 * cos(2 * M_PI / 6), 2 * sin(2 * M_PI / 6)); Point h1pt2(2 * cos(4 * M_PI / 6), 2 * sin(4 * M_PI / 6)); Point h1pt3(2 * cos(6 * M_PI / 6), 2 * sin(6 * M_PI / 6)); Point h1pt4(2 * cos(8 * M_PI / 6), 2 * sin(8 * M_PI / 6)); Point h1pt5(2 * cos(10 * M_PI / 6), 2 * sin(10 * M_PI / 6)); Point h1pt6(2 * cos(12 * M_PI / 6), 2 * sin(12 * M_PI / 6));
    Hexagon hex1(h1pt1, h1pt2, h1pt3, h1pt4, h1pt5, h1pt6);
    Hexagon hex2; hex2 = hex1;
    ASSERT_TRUE(hex1 == hex2);
}

TEST(test_08, copy_and_compare_overloaded_operators_test) {
    Point o2pt1(2 * cos(0), 2 * sin(0)); Point o2pt2(2 * cos(M_PI / 4), 2 * sin(M_PI / 4)); Point o2pt3(2 * cos(M_PI / 2), 2 * sin(M_PI / 2)); Point o2pt4(2 * cos(3 * M_PI / 4), 2 * sin(3 * M_PI / 4)); Point o2pt5(2 * cos(M_PI), 2 * sin(M_PI)); Point o2pt6(2 * cos(5 * M_PI / 4), 2 * sin(5 * M_PI / 4)); Point o2pt7(2 * cos(3 * M_PI / 2), 2 * sin(3 * M_PI / 2)); Point o2pt8(2 * cos(7 * M_PI / 4), 2 * sin(7 * M_PI / 4));
    Octagon oct1(o2pt1, o2pt2, o2pt3, o2pt4, o2pt5, o2pt6, o2pt7, o2pt8);
    Octagon oct2; oct2 = oct1;
    ASSERT_TRUE(oct1 == oct2);
}

TEST(test_09, move_overloaded_operator_test)
{
    Point p2pt1(1, 0); Point p2pt2(cos(2 * M_PI / 5), sin(2 * M_PI / 5)); Point p2pt3(cos(4 * M_PI / 5), sin(4 * M_PI / 5)); Point p2pt4(cos(6 * M_PI / 5), sin(6 * M_PI / 5)); Point p2pt5(cos(8 * M_PI / 5), sin(8 * M_PI / 5));
    Point p1pt1(2, 0); Point p1pt2(2 * cos(2 * M_PI / 5), 2 * sin(2 * M_PI / 5)); Point p1pt3(2 * cos(4 * M_PI / 5), 2 * sin(4 * M_PI / 5)); Point p1pt4(2 * cos(6 * M_PI / 5), 2 * sin(6 * M_PI / 5)); Point p1pt5(2 * cos(8 * M_PI / 5), 2 * sin(8 * M_PI / 5));
    Pentagon pent1(p2pt1, p2pt2, p2pt3, p2pt4, p2pt5);
    Pentagon pent2(p1pt1, p1pt2, p1pt3, p1pt4, p1pt5);
    Pentagon pent3; pent3 = pent2;
    pent1 = std::move(pent2);
    ASSERT_TRUE(pent1 == pent3);
    ASSERT_TRUE(pent2.get_array_pointer() == nullptr);
}

TEST(test_10, move_overloaded_operator_test)
{
    Point h3pt1(3 * cos(2 * M_PI / 6), 3 * sin(2 * M_PI / 6)); Point h3pt2(3 * cos(4 * M_PI / 6), 3 * sin(4 * M_PI / 6)); Point h3pt3(3 * cos(6 * M_PI / 6), 3 * sin(6 * M_PI / 6)); Point h3pt4(3 * cos(8 * M_PI / 6), 3 * sin(8 * M_PI / 6)); Point h3pt5(3 * cos(10 * M_PI / 6), 3 * sin(10 * M_PI / 6)); Point h3pt6(3 * cos(12 * M_PI / 6), 3 * sin(12 * M_PI / 6)); 
    Point h1pt1(2 * cos(2 * M_PI / 6), 2 * sin(2 * M_PI / 6)); Point h1pt2(2 * cos(4 * M_PI / 6), 2 * sin(4 * M_PI / 6)); Point h1pt3(2 * cos(6 * M_PI / 6), 2 * sin(6 * M_PI / 6)); Point h1pt4(2 * cos(8 * M_PI / 6), 2 * sin(8 * M_PI / 6)); Point h1pt5(2 * cos(10 * M_PI / 6), 2 * sin(10 * M_PI / 6)); Point h1pt6(2 * cos(12 * M_PI / 6), 2 * sin(12 * M_PI / 6));
    Hexagon hex1(h3pt1, h3pt2, h3pt3, h3pt4, h3pt5, h3pt6);
    Hexagon hex2(h1pt1, h1pt2, h1pt3, h1pt4, h1pt5, h1pt6);
    Hexagon hex3; hex3 = hex2;
    hex1 = std::move(hex2);
    ASSERT_TRUE(hex1 == hex3);
    ASSERT_TRUE(hex2.get_array_pointer() == nullptr);
}

TEST(test_11, move_overloaded_operator_test)
{
    Point o1pt1(cos(0), sin(0)); Point o1pt2(cos(M_PI / 4), sin(M_PI / 4)); Point o1pt3(cos(M_PI / 2), sin(M_PI / 2)); Point o1pt4(cos(3 * M_PI / 4), sin(3 * M_PI / 4)); Point o1pt5(cos(M_PI), sin(M_PI)); Point o1pt6(cos(5 * M_PI / 4), sin(5 * M_PI / 4)); Point o1pt7(cos(3 * M_PI / 2), sin(3 * M_PI / 2)); Point o1pt8(cos(7 * M_PI / 4), sin(7 * M_PI / 4));
    Point o2pt1(2 * cos(0), 2 * sin(0)); Point o2pt2(2 * cos(M_PI / 4), 2 * sin(M_PI / 4)); Point o2pt3(2 * cos(M_PI / 2), 2 * sin(M_PI / 2)); Point o2pt4(2 * cos(3 * M_PI / 4), 2 * sin(3 * M_PI / 4)); Point o2pt5(2 * cos(M_PI), 2 * sin(M_PI)); Point o2pt6(2 * cos(5 * M_PI / 4), 2 * sin(5 * M_PI / 4)); Point o2pt7(2 * cos(3 * M_PI / 2), 2 * sin(3 * M_PI / 2)); Point o2pt8(2 * cos(7 * M_PI / 4), 2 * sin(7 * M_PI / 4));
    Octagon oct1(o1pt1, o1pt2, o1pt3, o1pt4, o1pt5, o1pt6, o1pt7, o1pt8);
    Octagon oct2(o2pt1, o2pt2, o2pt3, o2pt4, o2pt5, o2pt6, o2pt7, o2pt8);
    Octagon oct3; oct3 = oct2;
    oct1 = std::move(oct2);
    ASSERT_TRUE(oct1 == oct3);
    ASSERT_TRUE(oct2.get_array_pointer() == nullptr);
}

TEST(test_12, area_method_test)
{
    Point p2pt1(1, 0); Point p2pt2(cos(2 * M_PI / 5), sin(2 * M_PI / 5)); Point p2pt3(cos(4 * M_PI / 5), sin(4 * M_PI / 5)); Point p2pt4(cos(6 * M_PI / 5), sin(6 * M_PI / 5)); Point p2pt5(cos(8 * M_PI / 5), sin(8 * M_PI / 5));
    Pentagon pent(p2pt1, p2pt2, p2pt3, p2pt4, p2pt5);
    ASSERT_TRUE(static_cast<double>(pent) == 2.378);
}

TEST(test_13, area_method_test)
{
    Point h2pt1(cos(2 * M_PI / 6), sin(2 * M_PI / 6)); Point h2pt2(cos(4 * M_PI / 6), sin(4 * M_PI / 6)); Point h2pt3(cos(6 * M_PI / 6), sin(6 * M_PI / 6)); Point h2pt4(cos(8 * M_PI / 6), sin(8 * M_PI / 6)); Point h2pt5(cos(10 * M_PI / 6), sin(10 * M_PI / 6)); Point h2pt6(cos(12 * M_PI / 6), sin(12 * M_PI / 6));
    Hexagon hex(h2pt1, h2pt2, h2pt3, h2pt4, h2pt5, h2pt6);
    ASSERT_TRUE(static_cast<double>(hex) == 2.598);
}

TEST(test_14, area_method_test)
{
    Point o1pt1(cos(0), sin(0)); Point o1pt2(cos(M_PI / 4), sin(M_PI / 4)); Point o1pt3(cos(M_PI / 2), sin(M_PI / 2)); Point o1pt4(cos(3 * M_PI / 4), sin(3 * M_PI / 4)); Point o1pt5(cos(M_PI), sin(M_PI)); Point o1pt6(cos(5 * M_PI / 4), sin(5 * M_PI / 4)); Point o1pt7(cos(3 * M_PI / 2), sin(3 * M_PI / 2)); Point o1pt8(cos(7 * M_PI / 4), sin(7 * M_PI / 4));
    Octagon oct(o1pt1, o1pt2, o1pt3, o1pt4, o1pt5, o1pt6, o1pt7, o1pt8);
    ASSERT_TRUE(static_cast<double>(oct) == 2.828);
}

TEST(test_15, area_method_test)
{
    Point p1pt1(2, 0); Point p1pt2(2 * cos(2 * M_PI / 5), 2 * sin(2 * M_PI / 5)); Point p1pt3(2 * cos(4 * M_PI / 5), 2 * sin(4 * M_PI / 5)); Point p1pt4(2 * cos(6 * M_PI / 5), 2 * sin(6 * M_PI / 5)); Point p1pt5(2 * cos(8 * M_PI / 5), 2 * sin(8 * M_PI / 5));
    Pentagon pent(p1pt1, p1pt2, p1pt3, p1pt4, p1pt5);
    ASSERT_TRUE(static_cast<double>(pent) == 9.511);
}

TEST(test_16, area_method_test)
{
    Point h1pt1(2 * cos(2 * M_PI / 6), 2 * sin(2 * M_PI / 6)); Point h1pt2(2 * cos(4 * M_PI / 6), 2 * sin(4 * M_PI / 6)); Point h1pt3(2 * cos(6 * M_PI / 6), 2 * sin(6 * M_PI / 6)); Point h1pt4(2 * cos(8 * M_PI / 6), 2 * sin(8 * M_PI / 6)); Point h1pt5(2 * cos(10 * M_PI / 6), 2 * sin(10 * M_PI / 6)); Point h1pt6(2 * cos(12 * M_PI / 6), 2 * sin(12 * M_PI / 6));
    Hexagon hex(h1pt1, h1pt2, h1pt3, h1pt4, h1pt5, h1pt6);
    ASSERT_TRUE(static_cast<double>(hex) == 10.392);
}

TEST(test_17, area_method_test)
{
    Point o2pt1(2 * cos(0), 2 * sin(0)); Point o2pt2(2 * cos(M_PI / 4), 2 * sin(M_PI / 4)); Point o2pt3(2 * cos(M_PI / 2), 2 * sin(M_PI / 2)); Point o2pt4(2 * cos(3 * M_PI / 4), 2 * sin(3 * M_PI / 4)); Point o2pt5(2 * cos(M_PI), 2 * sin(M_PI)); Point o2pt6(2 * cos(5 * M_PI / 4), 2 * sin(5 * M_PI / 4)); Point o2pt7(2 * cos(3 * M_PI / 2), 2 * sin(3 * M_PI / 2)); Point o2pt8(2 * cos(7 * M_PI / 4), 2 * sin(7 * M_PI / 4));
    Octagon oct(o2pt1, o2pt2, o2pt3, o2pt4, o2pt5, o2pt6, o2pt7, o2pt8);
    ASSERT_TRUE(static_cast<double>(oct) == 11.314);
}

TEST(test_18, area_method_test)
{
    Point p3pt1(3, 0); Point p3pt2(3 * cos(2 * M_PI / 5), 3 * sin(2 * M_PI / 5)); Point p3pt3(3 * cos(4 * M_PI / 5), 3 * sin(4 * M_PI / 5)); Point p3pt4(3 * cos(6 * M_PI / 5), 3 * sin(6 * M_PI / 5)); Point p3pt5(3 * cos(8 * M_PI / 5), 3 * sin(8 * M_PI / 5));
    Pentagon pent(p3pt1, p3pt2, p3pt3, p3pt4, p3pt5);
    ASSERT_TRUE(static_cast<double>(pent) == 21.399);
}

TEST(test_19, area_method_test)
{
    Point h3pt1(3 * cos(2 * M_PI / 6), 3 * sin(2 * M_PI / 6)); Point h3pt2(3 * cos(4 * M_PI / 6), 3 * sin(4 * M_PI / 6)); Point h3pt3(3 * cos(6 * M_PI / 6), 3 * sin(6 * M_PI / 6)); Point h3pt4(3 * cos(8 * M_PI / 6), 3 * sin(8 * M_PI / 6)); Point h3pt5(3 * cos(10 * M_PI / 6), 3 * sin(10 * M_PI / 6)); Point h3pt6(3 * cos(12 * M_PI / 6), 3 * sin(12 * M_PI / 6)); 
    Hexagon hex(h3pt1, h3pt2, h3pt3, h3pt4, h3pt5, h3pt6);
    ASSERT_TRUE(static_cast<double>(hex) == 23.383);
}

TEST(test_20, area_method_test)
{
    Point o3pt1(3 * cos(0), 3 * sin(0)); Point o3pt2(3 * cos(M_PI / 4), 3 * sin(M_PI / 4)); Point o3pt3(3 * cos(M_PI / 2), 3 * sin(M_PI / 2)); Point o3pt4(3 * cos(3 * M_PI / 4), 3 * sin(3 * M_PI / 4)); Point o3pt5(3 * cos(M_PI), 3 * sin(M_PI)); Point o3pt6(3 * cos(5 * M_PI / 4), 3 * sin(5 * M_PI / 4)); Point o3pt7(3 * cos(3 * M_PI / 2), 3 * sin(3 * M_PI / 2)); Point o3pt8(3 * cos(7 * M_PI / 4), 3 * sin(7 * M_PI / 4));
    Octagon oct(o3pt1, o3pt2, o3pt3, o3pt4, o3pt5, o3pt6, o3pt7, o3pt8);
    ASSERT_TRUE(static_cast<double>(oct) == 25.456);
}

TEST(test_21, gemetrical_centre_method_test)
{
    Point p2pt1(1, 0); Point p2pt2(cos(2 * M_PI / 5), sin(2 * M_PI / 5)); Point p2pt3(cos(4 * M_PI / 5), sin(4 * M_PI / 5)); Point p2pt4(cos(6 * M_PI / 5), sin(6 * M_PI / 5)); Point p2pt5(cos(8 * M_PI / 5), sin(8 * M_PI / 5));
    Pentagon pent(p2pt1, p2pt2, p2pt3, p2pt4, p2pt5);
    Point p(0, 0);
    ASSERT_TRUE(pent.geometrical_centre() == p);
}

TEST(test_22, geometrical_centre_method_test)
{
    Point h2pt1(cos(2 * M_PI / 6), sin(2 * M_PI / 6)); Point h2pt2(cos(4 * M_PI / 6), sin(4 * M_PI / 6)); Point h2pt3(cos(6 * M_PI / 6), sin(6 * M_PI / 6)); Point h2pt4(cos(8 * M_PI / 6), sin(8 * M_PI / 6)); Point h2pt5(cos(10 * M_PI / 6), sin(10 * M_PI / 6)); Point h2pt6(cos(12 * M_PI / 6), sin(12 * M_PI / 6));
    Hexagon hex(h2pt1, h2pt2, h2pt3, h2pt4, h2pt5, h2pt6);
    Point p(0, 0);
    ASSERT_TRUE(hex.geometrical_centre() == p);
}

TEST(test_23, geometrical_centre_method_test)
{
    Point o1pt1(cos(0), sin(0)); Point o1pt2(cos(M_PI / 4), sin(M_PI / 4)); Point o1pt3(cos(M_PI / 2), sin(M_PI / 2)); Point o1pt4(cos(3 * M_PI / 4), sin(3 * M_PI / 4)); Point o1pt5(cos(M_PI), sin(M_PI)); Point o1pt6(cos(5 * M_PI / 4), sin(5 * M_PI / 4)); Point o1pt7(cos(3 * M_PI / 2), sin(3 * M_PI / 2)); Point o1pt8(cos(7 * M_PI / 4), sin(7 * M_PI / 4));
    Octagon oct(o1pt1, o1pt2, o1pt3, o1pt4, o1pt5, o1pt6, o1pt7, o1pt8);
    Point p(0, 0);
    ASSERT_TRUE(oct.geometrical_centre() == p);
}

TEST(test_24, geometrical_centre_method_test)
{
    Point p1pt1(2, 0); Point p1pt2(2 * cos(2 * M_PI / 5), 2 * sin(2 * M_PI / 5)); Point p1pt3(2 * cos(4 * M_PI / 5), 2 * sin(4 * M_PI / 5)); Point p1pt4(2 * cos(6 * M_PI / 5), 2 * sin(6 * M_PI / 5)); Point p1pt5(2 * cos(8 * M_PI / 5), 2 * sin(8 * M_PI / 5));
    Pentagon pent(p1pt1, p1pt2, p1pt3, p1pt4, p1pt5);
    Point p(0, 0);
    ASSERT_TRUE(pent.geometrical_centre() == p);
}

TEST(test_25, geometrical_centre_method_test) 
{
    Point h1pt1(2 * cos(2 * M_PI / 6), 2 * sin(2 * M_PI / 6)); Point h1pt2(2 * cos(4 * M_PI / 6), 2 * sin(4 * M_PI / 6)); Point h1pt3(2 * cos(6 * M_PI / 6), 2 * sin(6 * M_PI / 6)); Point h1pt4(2 * cos(8 * M_PI / 6), 2 * sin(8 * M_PI / 6)); Point h1pt5(2 * cos(10 * M_PI / 6), 2 * sin(10 * M_PI / 6)); Point h1pt6(2 * cos(12 * M_PI / 6), 2 * sin(12 * M_PI / 6));
    Hexagon hex(h1pt1, h1pt2, h1pt3, h1pt4, h1pt5, h1pt6);
    Point p(0, 0);
    ASSERT_TRUE(hex.geometrical_centre() == p);
}

TEST(test_26, geometrical_centre_method_test)
{
    Point o2pt1(2 * cos(0), 2 * sin(0)); Point o2pt2(2 * cos(M_PI / 4), 2 * sin(M_PI / 4)); Point o2pt3(2 * cos(M_PI / 2), 2 * sin(M_PI / 2)); Point o2pt4(2 * cos(3 * M_PI / 4), 2 * sin(3 * M_PI / 4)); Point o2pt5(2 * cos(M_PI), 2 * sin(M_PI)); Point o2pt6(2 * cos(5 * M_PI / 4), 2 * sin(5 * M_PI / 4)); Point o2pt7(2 * cos(3 * M_PI / 2), 2 * sin(3 * M_PI / 2)); Point o2pt8(2 * cos(7 * M_PI / 4), 2 * sin(7 * M_PI / 4));
    Octagon oct(o2pt1, o2pt2, o2pt3, o2pt4, o2pt5, o2pt6, o2pt7, o2pt8);
    Point p(0, 0);
    ASSERT_TRUE(oct.geometrical_centre() == p);
}

TEST(test_27, geometrical_centre_method_test)
{
    Point p3pt1(3, 0); Point p3pt2(3 * cos(2 * M_PI / 5), 3 * sin(2 * M_PI / 5)); Point p3pt3(3 * cos(4 * M_PI / 5), 3 * sin(4 * M_PI / 5)); Point p3pt4(3 * cos(6 * M_PI / 5), 3 * sin(6 * M_PI / 5)); Point p3pt5(3 * cos(8 * M_PI / 5), 3 * sin(8 * M_PI / 5));
    Pentagon pent(p3pt1, p3pt2, p3pt3, p3pt4, p3pt5);
    Point p(0, 0);
    ASSERT_TRUE(pent.geometrical_centre() == p);
}

TEST(test_28, geometrical_centre_method_test)
{
    Point h3pt1(3 * cos(2 * M_PI / 6), 3 * sin(2 * M_PI / 6)); Point h3pt2(3 * cos(4 * M_PI / 6), 3 * sin(4 * M_PI / 6)); Point h3pt3(3 * cos(6 * M_PI / 6), 3 * sin(6 * M_PI / 6)); Point h3pt4(3 * cos(8 * M_PI / 6), 3 * sin(8 * M_PI / 6)); Point h3pt5(3 * cos(10 * M_PI / 6), 3 * sin(10 * M_PI / 6)); Point h3pt6(3 * cos(12 * M_PI / 6), 3 * sin(12 * M_PI / 6)); 
    Hexagon hex(h3pt1, h3pt2, h3pt3, h3pt4, h3pt5, h3pt6);
    Point p(0, 0);
    ASSERT_TRUE(hex.geometrical_centre() == p);
}

TEST(test_29, geometrical_centre_method_test)
{
    Point o3pt1(3 * cos(0), 3 * sin(0)); Point o3pt2(3 * cos(M_PI / 4), 3 * sin(M_PI / 4)); Point o3pt3(3 * cos(M_PI / 2), 3 * sin(M_PI / 2)); Point o3pt4(3 * cos(3 * M_PI / 4), 3 * sin(3 * M_PI / 4)); Point o3pt5(3 * cos(M_PI), 3 * sin(M_PI)); Point o3pt6(3 * cos(5 * M_PI / 4), 3 * sin(5 * M_PI / 4)); Point o3pt7(3 * cos(3 * M_PI / 2), 3 * sin(3 * M_PI / 2)); Point o3pt8(3 * cos(7 * M_PI / 4), 3 * sin(7 * M_PI / 4));
    Octagon oct(o3pt1, o3pt2, o3pt3, o3pt4, o3pt5, o3pt6, o3pt7, o3pt8);
    Point p(0, 0);
    ASSERT_TRUE(oct.geometrical_centre() == p);
}

TEST(test_30, figure_array_test)
{
    Pentagon pent; Hexagon hex; Octagon oct;
    Figure_array *fig_array = create_array();
    append_figure(fig_array, &pent);
    append_figure(fig_array, &hex);
    append_figure(fig_array, &oct);
    ASSERT_TRUE(fig_array->array[0]->return_type() == "Pentagon");
    ASSERT_TRUE(fig_array->array[1]->return_type() == "Hexagon");
    ASSERT_TRUE(fig_array->array[2]->return_type() == "Octagon");
    destroy_array(fig_array);
}

TEST(test_31, figure_array_test)
{
    Pentagon pent; Hexagon hex; Octagon oct;
    Figure_array *fig_array = create_array();
    append_figure(fig_array, &pent);
    append_figure(fig_array, &hex);
    append_figure(fig_array, &oct);
    fig_array->array = rmv_figure(fig_array, 0);
    ASSERT_TRUE(fig_array->array[0]->return_type() == "Hexagon");
    ASSERT_TRUE(fig_array->array[1]->return_type() == "Octagon");
    destroy_array(fig_array);
}

TEST(test_32, figure_array_test)
{
    Pentagon pent; Hexagon hex; Octagon oct;
    Figure_array *fig_array = create_array();
    append_figure(fig_array, &pent);
    append_figure(fig_array, &hex);
    append_figure(fig_array, &oct);
    fig_array->array = rmv_figure(fig_array, 1);
    ASSERT_TRUE(fig_array->array[0]->return_type() == "Pentagon");
    ASSERT_TRUE(fig_array->array[1]->return_type() == "Octagon");
    destroy_array(fig_array);
}

TEST(test_33, figure_array_test)
{
    Pentagon pent; Hexagon hex; Octagon oct;
    Figure_array *fig_array = create_array();
    append_figure(fig_array, &pent);
    append_figure(fig_array, &hex);
    append_figure(fig_array, &oct);
    fig_array->array = rmv_figure(fig_array, 2);
    ASSERT_TRUE(fig_array->array[0]->return_type() == "Pentagon");
    ASSERT_TRUE(fig_array->array[1]->return_type() == "Hexagon");
    destroy_array(fig_array);
}

TEST(test_34, exception_area_test)
{
    Point p1(0, 0); Point p2(0, 1); Point p3(1, 0); Point p4(1, 1); Point p5(2, 2);
    Pentagon pent(p1, p2, p3, p4, p5);
    EXPECT_THROW(static_cast<double>(pent), std::logic_error);
}

TEST(test_35, exception_area_test)
{
    Point p1(0, 0); Point p2(0, 1); Point p3(1, 0); Point p4(1, 1); Point p5(2, 2); Point p6(3, 3);
    Hexagon hex(p1, p2, p3, p4, p5, p6);
    EXPECT_THROW(static_cast<double>(hex), std::logic_error);
}

TEST(test_36, exception_area_test)
{
    Point p1(0, 0); Point p2(0, 1); Point p3(1, 0); Point p4(1, 1); Point p5(2, 2); Point p6(3, 3); Point p7(4, 3); Point p8(3 ,4);
    Octagon oct(p1, p2, p3, p4, p5, p6, p7, p8);
    EXPECT_THROW(static_cast<double>(oct), std::logic_error);
}

TEST(test_37, exception_geometrical_centre_test)
{
    Point p1(0, 0); Point p2(0, 1); Point p3(1, 0); Point p4(1, 1); Point p5(2, 2);
    Pentagon pent(p1, p2, p3, p4, p5);
    EXPECT_THROW(pent.geometrical_centre(), std::logic_error);
}

TEST(test_38, exception_geometrical_centre_test)
{
    Point p1(0, 0); Point p2(0, 1); Point p3(1, 0); Point p4(1, 1); Point p5(2, 2); Point p6(3, 3);
    Hexagon hex(p1, p2, p3, p4, p5, p6);
    EXPECT_THROW(hex.geometrical_centre(), std::logic_error);
}

TEST(test_39, exception_geometrical_centre_test)
{
    Point p1(0, 0); Point p2(0, 1); Point p3(1, 0); Point p4(1, 1); Point p5(2, 2); Point p6(3, 3); Point p7(4, 3); Point p8(3 ,4);
    Octagon oct(p1, p2, p3, p4, p5, p6, p7, p8);
    EXPECT_THROW(oct.geometrical_centre(), std::logic_error);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}