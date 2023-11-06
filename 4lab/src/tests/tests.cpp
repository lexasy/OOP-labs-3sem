#include <gtest/gtest.h>
#include "../includes/figure_array.hpp"

TEST(test_01, length_between_points_test) {
    Point<int> p1(0, 0); Point<int> p2(1, 1);
    ASSERT_TRUE(length_btw_points(p1, p2) == sqrt(2));
}

TEST(test_02, length_between_points_test) {
    Point<double> p1(0, 0); Point<double> p2(0, 0);
    ASSERT_TRUE(length_btw_points(p1, p2) == 0);
}

TEST(test_03, copy_points_constructor_test)
{
    Point<int> p1(0, 0); Point<int> p2(0, 1); Point<int> p3(1, 0); Point<int> p4(1, 1); Point<int> p5(2, 2);
    std::shared_ptr<Point<int>[]> ptarr = std::shared_ptr<Point<int>[]>(new Point<int>[5]);
    ptarr[0] = p1; ptarr[1] = p2; ptarr[2] = p3; ptarr[3] = p4; ptarr[4] = p5;
    Pentagon pent(p1, p2, p3, p4, p5);
    for (int i = 0; i < 5; i++) {
        ASSERT_TRUE(pent.points_array_pointer_getter()[i] == ptarr[i]);
    }
}

TEST(test_04, copy_points_constructor_test)
{
    Point<double> p1(0, 0); Point<double> p2(0, 1); Point<double> p3(1, 0); Point<double> p4(1, 1); Point<double> p5(2, 2); Point<double> p6(3, 3);
    std::shared_ptr<Point<double>[]> ptarr = std::shared_ptr<Point<double>[]>(new Point<double>[6]);
    ptarr[0] = p1; ptarr[1] = p2; ptarr[2] = p3; ptarr[3] = p4; ptarr[4] = p5; ptarr[5] = p6;
    Hexagon hex(p1, p2, p3, p4, p5, p6);
    for (int i = 0; i < 6; i++) {
        ASSERT_TRUE(hex.points_array_pointer_getter()[i] == ptarr[i]);
    }
}

TEST(test_05, copy_points_constructor_test)
{
    Point<int> p1(0, 0); Point<int> p2(0, 1); Point<int> p3(1, 0); Point<int> p4(1, 1); Point<int> p5(2, 2); Point<int> p6(3, 3); Point<int> p7(4, 3); Point<int> p8(3 ,4);
    std::shared_ptr<Point<int>[]> ptarr = std::shared_ptr<Point<int>[]>(new Point<int>[8]);
    ptarr[0] = p1; ptarr[1] = p2; ptarr[2] = p3; ptarr[3] = p4; ptarr[4] = p5; ptarr[5] = p6; ptarr[6] = p7; ptarr[7] = p8;
    Octagon oct(p1, p2, p3, p4, p5, p6, p7, p8);
    for (int i = 0; i < 8; i++) {
        ASSERT_TRUE(oct.points_array_pointer_getter()[i] == ptarr[i]);
    }
}

TEST(test_06, copy_and_compare_overloaded_operators_test)
{
    Point<double> p3pt1(3, 0); Point<double> p3pt2(3 * cos(2 * M_PI / 5), 3 * sin(2 * M_PI / 5)); Point<double> p3pt3(3 * cos(4 * M_PI / 5), 3 * sin(4 * M_PI / 5)); Point<double> p3pt4(3 * cos(6 * M_PI / 5), 3 * sin(6 * M_PI / 5)); Point<double> p3pt5(3 * cos(8 * M_PI / 5), 3 * sin(8 * M_PI / 5));
    Pentagon<double> pent1(p3pt1, p3pt2, p3pt3, p3pt4, p3pt5);
    Pentagon<double> pent2; pent2 = pent1;
    ASSERT_TRUE(pent1 == pent2);
}

TEST(test_07, copy_and_compare_overloaded_operators_test)
{
    Point<double> h1pt1(2 * cos(2 * M_PI / 6), 2 * sin(2 * M_PI / 6)); Point<double> h1pt2(2 * cos(4 * M_PI / 6), 2 * sin(4 * M_PI / 6)); Point<double> h1pt3(2 * cos(6 * M_PI / 6), 2 * sin(6 * M_PI / 6)); Point<double> h1pt4(2 * cos(8 * M_PI / 6), 2 * sin(8 * M_PI / 6)); Point<double> h1pt5(2 * cos(10 * M_PI / 6), 2 * sin(10 * M_PI / 6)); Point<double> h1pt6(2 * cos(12 * M_PI / 6), 2 * sin(12 * M_PI / 6));
    Hexagon<double> hex1(h1pt1, h1pt2, h1pt3, h1pt4, h1pt5, h1pt6);
    Hexagon<double> hex2; hex2 = hex1;
    ASSERT_TRUE(hex1 == hex2);
}

TEST(test_08, copy_and_compare_overloaded_operators_test) {
    Point<double> o2pt1(2 * cos(0), 2 * sin(0)); Point<double> o2pt2(2 * cos(M_PI / 4), 2 * sin(M_PI / 4)); Point<double> o2pt3(2 * cos(M_PI / 2), 2 * sin(M_PI / 2)); Point<double> o2pt4(2 * cos(3 * M_PI / 4), 2 * sin(3 * M_PI / 4)); Point<double> o2pt5(2 * cos(M_PI), 2 * sin(M_PI)); Point<double> o2pt6(2 * cos(5 * M_PI / 4), 2 * sin(5 * M_PI / 4)); Point<double> o2pt7(2 * cos(3 * M_PI / 2), 2 * sin(3 * M_PI / 2)); Point<double> o2pt8(2 * cos(7 * M_PI / 4), 2 * sin(7 * M_PI / 4));
    Octagon<double> oct1(o2pt1, o2pt2, o2pt3, o2pt4, o2pt5, o2pt6, o2pt7, o2pt8);
    Octagon<double> oct2; oct2 = oct1;
    ASSERT_TRUE(oct1 == oct2);
}

TEST(test_09, area_method_test)
{
    Point<double> p2pt1(1, 0); Point<double> p2pt2(cos(2 * M_PI / 5), sin(2 * M_PI / 5)); Point<double> p2pt3(cos(4 * M_PI / 5), sin(4 * M_PI / 5)); Point<double> p2pt4(cos(6 * M_PI / 5), sin(6 * M_PI / 5)); Point<double> p2pt5(cos(8 * M_PI / 5), sin(8 * M_PI / 5));
    Pentagon<double> pent(p2pt1, p2pt2, p2pt3, p2pt4, p2pt5);
    ASSERT_TRUE(static_cast<double>(pent) == 2.378);
}

TEST(test_10, area_method_test)
{
    Point<double> h2pt1(cos(2 * M_PI / 6), sin(2 * M_PI / 6)); Point<double> h2pt2(cos(4 * M_PI / 6), sin(4 * M_PI / 6)); Point<double> h2pt3(cos(6 * M_PI / 6), sin(6 * M_PI / 6)); Point<double> h2pt4(cos(8 * M_PI / 6), sin(8 * M_PI / 6)); Point<double> h2pt5(cos(10 * M_PI / 6), sin(10 * M_PI / 6)); Point<double> h2pt6(cos(12 * M_PI / 6), sin(12 * M_PI / 6));
    Hexagon<double> hex(h2pt1, h2pt2, h2pt3, h2pt4, h2pt5, h2pt6);
    ASSERT_TRUE(static_cast<double>(hex) == 2.598);
}

TEST(test_11, area_method_test)
{
    Point<double> o1pt1(cos(0), sin(0)); Point<double> o1pt2(cos(M_PI / 4), sin(M_PI / 4)); Point<double> o1pt3(cos(M_PI / 2), sin(M_PI / 2)); Point<double> o1pt4(cos(3 * M_PI / 4), sin(3 * M_PI / 4)); Point<double> o1pt5(cos(M_PI), sin(M_PI)); Point<double> o1pt6(cos(5 * M_PI / 4), sin(5 * M_PI / 4)); Point<double> o1pt7(cos(3 * M_PI / 2), sin(3 * M_PI / 2)); Point<double> o1pt8(cos(7 * M_PI / 4), sin(7 * M_PI / 4));
    Octagon<double> oct(o1pt1, o1pt2, o1pt3, o1pt4, o1pt5, o1pt6, o1pt7, o1pt8);
    ASSERT_TRUE(static_cast<double>(oct) == 2.828);
}

TEST(test_12, gemetrical_centre_method_test)
{
    Point<double> p2pt1(1, 0); Point<double> p2pt2(cos(2 * M_PI / 5), sin(2 * M_PI / 5)); Point<double> p2pt3(cos(4 * M_PI / 5), sin(4 * M_PI / 5)); Point<double> p2pt4(cos(6 * M_PI / 5), sin(6 * M_PI / 5)); Point<double> p2pt5(cos(8 * M_PI / 5), sin(8 * M_PI / 5));
    Pentagon<double> pent(p2pt1, p2pt2, p2pt3, p2pt4, p2pt5);
    Point<double> p(0, 0);
    ASSERT_TRUE(pent.geometrical_centre() == p);
}

TEST(test_13, geometrical_centre_method_test)
{
    Point<double> h2pt1(cos(2 * M_PI / 6), sin(2 * M_PI / 6)); Point<double> h2pt2(cos(4 * M_PI / 6), sin(4 * M_PI / 6)); Point<double> h2pt3(cos(6 * M_PI / 6), sin(6 * M_PI / 6)); Point<double> h2pt4(cos(8 * M_PI / 6), sin(8 * M_PI / 6)); Point<double> h2pt5(cos(10 * M_PI / 6), sin(10 * M_PI / 6)); Point<double> h2pt6(cos(12 * M_PI / 6), sin(12 * M_PI / 6));
    Hexagon<double> hex(h2pt1, h2pt2, h2pt3, h2pt4, h2pt5, h2pt6);
    Point<double> p(0, 0);
    ASSERT_TRUE(hex.geometrical_centre() == p);
}

TEST(test_14, geometrical_centre_method_test)
{
    Point<double> o1pt1(cos(0), sin(0)); Point<double> o1pt2(cos(M_PI / 4), sin(M_PI / 4)); Point<double> o1pt3(cos(M_PI / 2), sin(M_PI / 2)); Point<double> o1pt4(cos(3 * M_PI / 4), sin(3 * M_PI / 4)); Point<double> o1pt5(cos(M_PI), sin(M_PI)); Point<double> o1pt6(cos(5 * M_PI / 4), sin(5 * M_PI / 4)); Point<double> o1pt7(cos(3 * M_PI / 2), sin(3 * M_PI / 2)); Point<double> o1pt8(cos(7 * M_PI / 4), sin(7 * M_PI / 4));
    Octagon<double> oct(o1pt1, o1pt2, o1pt3, o1pt4, o1pt5, o1pt6, o1pt7, o1pt8);
    Point<double> p(0, 0);
    ASSERT_TRUE(oct.geometrical_centre() == p);
}

TEST(test_15, figure_array_test)
{
    Pentagon<int> pent; Hexagon<int> hex; Octagon<int> oct;
    Figure_array<std::shared_ptr<Figure<int>>> fig_array;
    fig_array.append_figure(std::make_shared<Pentagon<int>>(pent));
    fig_array.append_figure(std::make_shared<Hexagon<int>>(hex));
    fig_array.append_figure(std::make_shared<Octagon<int>>(oct));
    ASSERT_TRUE(fig_array[0]->return_type() == "Pentagon");
    ASSERT_TRUE(fig_array[1]->return_type() == "Hexagon");
    ASSERT_TRUE(fig_array[2]->return_type() == "Octagon");
}

TEST(test_16, figure_array_test)
{
    Pentagon<double> pent; Hexagon<double> hex; Octagon<double> oct;
    Figure_array<std::shared_ptr<Figure<double>>> fig_array;
    fig_array.append_figure(std::make_shared<Pentagon<double>>(pent));
    fig_array.append_figure(std::make_shared<Hexagon<double>>(hex));
    fig_array.append_figure(std::make_shared<Octagon<double>>(oct));
    fig_array.rmv_figure(2);
    ASSERT_TRUE(fig_array[0]->return_type() == "Pentagon");
    ASSERT_TRUE(fig_array[1]->return_type() == "Hexagon");
}

TEST(test_17, figure_array_test)
{
    Pentagon<double> pent; Hexagon<double> hex; Octagon<double> oct;
    Figure_array<std::shared_ptr<Figure<double>>> fig_array;
    fig_array.append_figure(std::make_shared<Pentagon<double>>(pent));
    fig_array.append_figure(std::make_shared<Hexagon<double>>(hex));
    fig_array.append_figure(std::make_shared<Octagon<double>>(oct));
    fig_array.rmv_figure(1);
    ASSERT_TRUE(fig_array[0]->return_type() == "Pentagon");
    ASSERT_TRUE(fig_array[1]->return_type() == "Octagon");
}

TEST(test_18, figure_array_test)
{
    Pentagon<double> pent; Hexagon<double> hex; Octagon<double> oct;
    Figure_array<std::shared_ptr<Figure<double>>> fig_array;
    fig_array.append_figure(std::make_shared<Pentagon<double>>(pent));
    fig_array.append_figure(std::make_shared<Hexagon<double>>(hex));
    fig_array.append_figure(std::make_shared<Octagon<double>>(oct));
    fig_array.rmv_figure(0);
    ASSERT_TRUE(fig_array[0]->return_type() == "Hexagon");
    ASSERT_TRUE(fig_array[1]->return_type() == "Octagon");
}

TEST(test_19, exception_area_test)
{
    Point<int> p1(0, 0); Point<int> p2(0, 1); Point<int> p3(1, 0); Point<int> p4(1, 1); Point<int> p5(2, 2);
    Pentagon<int> pent(p1, p2, p3, p4, p5);
    EXPECT_THROW(static_cast<double>(pent), std::logic_error);
}

TEST(test_20, exception_area_test)
{
    Point<double> p1(0, 0); Point<double> p2(0, 1); Point<double> p3(1, 0); Point<double> p4(1, 1); Point<double> p5(2, 2); Point<double> p6(3, 3);
    Hexagon<double> hex(p1, p2, p3, p4, p5, p6);
    EXPECT_THROW(static_cast<double>(hex), std::logic_error);
}

TEST(test_21, exception_area_test)
{
    Point<float> p1(0, 0); Point<float> p2(0, 1); Point<float> p3(1, 0); Point<float> p4(1, 1); Point<float> p5(2, 2); Point<float> p6(3, 3); Point<float> p7(4, 3); Point<float> p8(3 ,4);
    Octagon<float> oct(p1, p2, p3, p4, p5, p6, p7, p8);
    EXPECT_THROW(static_cast<double>(oct), std::logic_error);
}

TEST(test_22, exception_geometrical_centre_test)
{
    Point<float> p1(0, 0); Point<float> p2(0, 1); Point<float> p3(1, 0); Point<float> p4(1, 1); Point<float> p5(2, 2);
    Pentagon<float> pent(p1, p2, p3, p4, p5);
    EXPECT_THROW(pent.geometrical_centre(), std::logic_error);
}

TEST(test_23, exception_geometrical_centre_test)
{
    Point<double> p1(0, 0); Point<double> p2(0, 1); Point<double> p3(1, 0); Point<double> p4(1, 1); Point<double> p5(2, 2); Point<double> p6(3, 3);
    Hexagon<double> hex(p1, p2, p3, p4, p5, p6);
    EXPECT_THROW(hex.geometrical_centre(), std::logic_error);
}

TEST(test_24, exception_geometrical_centre_test)
{
    Point<long> p1(0, 0); Point<long> p2(0, 1); Point<long> p3(1, 0); Point<long> p4(1, 1); Point<long> p5(2, 2); Point<long> p6(3, 3); Point<long> p7(4, 3); Point<long> p8(3 ,4);
    Octagon<long> oct(p1, p2, p3, p4, p5, p6, p7, p8);
    EXPECT_THROW(oct.geometrical_centre(), std::logic_error);
}

TEST(test_25, default_constructor_area_test)
{
    Pentagon<int> pent; Hexagon<double> hex; Octagon<long double> oct;
    ASSERT_TRUE(static_cast<double>(pent) == 0);
    ASSERT_TRUE(static_cast<double>(hex) == 0);
    ASSERT_TRUE(static_cast<double>(oct) == 0);
}

TEST(test_26, default_constructor_geometrical_centre_test) 
{
    Pentagon<int> pent; Hexagon<int> hex; Octagon<int> oct;
    Point<int> p;
    ASSERT_TRUE(pent.geometrical_centre() == p);
    ASSERT_TRUE(hex.geometrical_centre() == p);
    ASSERT_TRUE(oct.geometrical_centre() == p);
}

TEST(test_27, default_and_not_default_test)
{
    Pentagon<double> pent1; Hexagon<long> hex1; Octagon<unsigned> oct1;
    Point<double> p3pt1(0, 0); Point<double> p3pt2(0, 0); Point<double> p3pt3(0, 0); Point<double> p3pt4(0, 0); Point<double> p3pt5(0, 0);
    Point<long> h3pt1(0, 0); Point<long> h3pt2(0, 0); Point<long> h3pt3(0, 0); Point<long> h3pt4(0, 0); Point<long> h3pt5(0, 0); Point<long> h3pt6(0, 0); 
    Point<unsigned> o3pt1(0, 0); Point<unsigned> o3pt2(0, 0); Point<unsigned> o3pt3(0, 0); Point<unsigned> o3pt4(0, 0); Point<unsigned> o3pt5(0, 0); Point<unsigned> o3pt6(0, 0); Point<unsigned> o3pt7(0, 0); Point<unsigned> o3pt8(0, 0);
    Pentagon pent2(p3pt1, p3pt2, p3pt3, p3pt4, p3pt5);
    Hexagon hex2(h3pt1, h3pt2, h3pt3, h3pt4, h3pt5, h3pt6);
    Octagon oct2(o3pt1, o3pt2, o3pt3, o3pt4, o3pt5, o3pt6, o3pt7, o3pt8);
    ASSERT_TRUE(pent1 == pent2);
    ASSERT_TRUE(hex1 == hex2);
    ASSERT_TRUE(oct1 == oct2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}