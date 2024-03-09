#include "include/Figurearray.hpp"
#include "googletest/googlemock/include/gmock/gmock.h"
#include "googletest/googletest/include/gtest/gtest.h"
#include <fstream>
using namespace std;
const double pi = M_PI;

TEST(vector_test, Constructor_default_vector)
{

    bool test = true;
    try {
        Vector<int64_t> a;
    }
    catch (std::range_error &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }

    ASSERT_TRUE(test);
    Vector<int64_t> a;
    ASSERT_TRUE(a.size() == 0);
    ASSERT_TRUE(a.capacity() == 1);
}


TEST(vector_test, Constructor_initializer_list)
{
    bool test = true;
    try {
        Vector<char> o{'5', '1', '0', '3'};
    }
    catch (std::range_error &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }
    ASSERT_TRUE(test);
    Vector<char> o{'5', '1', '0', '3'};
    ASSERT_TRUE(o.size() == 4);
}
TEST(vector_test, reserve)
{
    Vector<int64_t> test_1;
    size_t capacity = 100;

    test_1.reserve(capacity);

    ASSERT_TRUE(test_1.capacity() == capacity);
}
TEST(vector_test, test_equality)
{
    Vector<char> o1{'0', '5', '1'};
    Vector<char> o2{'0', '5', '1'};
    Vector<char> o3{'0', '5', '1', '4'};
    Vector<char> o4{'2', '5', '1'};
    ASSERT_TRUE(o1 == o1);
    ASSERT_TRUE(o1 == o2);
    ASSERT_FALSE(o1 == o3);
    ASSERT_FALSE(o1 == o4);
}
TEST(vector_test, test__not_equality)
{
    Vector<char> o1{'0', '5', '1'};
    Vector<char> o2{'0', '5', '1'};
    Vector<char> o3{'0', '5', '1', '4'};
    Vector<char> o4{'2', '5', '1'};
    ASSERT_FALSE(o1 != o1);
    ASSERT_FALSE(o1 != o2);
    ASSERT_TRUE(o1 != o3);
    ASSERT_TRUE(o1 != o4);
}
TEST(vector_test, Constructor_copy)
{
    bool test = true;
    Vector<char> o1{'5', '1', '0', '3'};
    try {
        Vector<char> o(o1);
    }
    catch (std::range_error &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }
    ASSERT_TRUE(test);
    Vector<char> o(o1);
    ASSERT_TRUE(o == o1);
}
TEST(vector_test, test_operator_squarebracket)
{
    Vector<char> o1{'5', '1', '0', '3'};
    ASSERT_TRUE(o1[2] == '0');
    ASSERT_TRUE(o1[1] == '1');
    ASSERT_TRUE(o1[0] == '5');
    ASSERT_TRUE(o1[3] == '3');
    o1[3] = '8';
    ASSERT_TRUE(o1[3] == '8');
}
TEST(vector_test, const_test_operator_squarebracket)
{
    const Vector<char> o1{'5', '1', '0', '3'};
    ASSERT_TRUE(o1[2] == '0');
    ASSERT_TRUE(o1[1] == '1');
    ASSERT_TRUE(o1[0] == '5');
    ASSERT_TRUE(o1[3] == '3');
}
TEST(vector_test, push_back)
{
    Vector<int> a;
    Vector<int> a1{1};
    Vector<int> a2{1, 2, 3};
    a.push_back(1);
    ASSERT_TRUE(a1 == a);
    a.push_back(2);
    a.push_back(3);
    ASSERT_TRUE(a2 == a);
}
TEST(vector_test, pop_back)
{
    Vector<int> a;
    Vector<int> a1{1};
    Vector<int> a2{1, 2, 3};
    a2.pop_back();
    a2.pop_back();
    ASSERT_TRUE(a1 == a2);
    a2.pop_back();
    ASSERT_TRUE(a2 == a);
}
TEST(vector_test, const_test_erase)
{
    Vector<char> o1{'5', '1', '0', '3'};
    Vector<char> o2{'5', '0', '3'};
    Vector<char> o3{'5', '0'};
    bool test = false;
    try {
        o1.erase(5);
    }
    catch (std::out_of_range &ex) {
        test = true;
    }
    ASSERT_TRUE(test);
    o1.erase(1);
    ASSERT_TRUE(o1 == o2);
    o1.erase(2);
    ASSERT_TRUE(o1 == o3);
}

TEST(Point_test, default_constructor)
{
    bool test = true;
    try {
        Point a;
    }
    catch (std::range_error &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }

    ASSERT_TRUE(test);
}
TEST(Point_test, x_y_constructor)
{
    bool test = true;
    try {
        Point a(100, 100);
    }
    catch (std::range_error &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }

    ASSERT_TRUE(test);
}
TEST(Point_test, copy_constructor)
{
    bool test = true;
    Point a(100, 100);
    try {
        Point b(a);
    }
    catch (std::range_error &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }

    ASSERT_TRUE(test);
    Point b(a);
    ASSERT_TRUE(b.get_x() == a.get_x());
    ASSERT_TRUE(b.get_y() == a.get_y());
}
TEST(Point_test, move_constructor)
{
    bool test = true;
    try {
        Point b(Point(100, 100));
    }
    catch (std::range_error &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }

    ASSERT_TRUE(test);
    Point b(Point(100, 100));
    ASSERT_TRUE(b.get_x() == 100);
    ASSERT_TRUE(b.get_y() == 100);
}
TEST(Point_test, assignment_test)
{
    Point a(10, 100);
    Point y(-1, -1);
    y = a;
    ASSERT_TRUE(y.get_x() == 10);
    ASSERT_TRUE(y.get_y() == 100);
}
TEST(Point_test, movement_test)
{
    Point y(-1, -1);
    y = Point(10, 100);
    ASSERT_TRUE(y.get_x() == 10);
    ASSERT_TRUE(y.get_y() == 100);
}
TEST(Point_test, equality_test)
{
    Point a(10, 100);
    Point y(10, 100);
    ASSERT_TRUE(a == y);
}
TEST(ROMB_test, default_constructor)
{
    bool test = true;
    try {
        Romb b;
    }
    catch (std::range_error &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }
    ASSERT_TRUE(true);
}
TEST(ROMB_test, Point_constructor)
{
    bool test = true;
    try {
        Romb b(Point(2, 3), Point(4, 0), Point(2, -3), Point(0, 0));
    }
    catch (std::exception &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }
    ASSERT_TRUE(true);
    test = false;
    try {
        Romb b(Point(0, 0), Point(4, 0), Point(2, -3), Point(0, 0));
    }
    catch (std::logic_error &ex) {
        test = true;
    }
    ASSERT_TRUE(true);
}
TEST(ROMB_test, side_constructor)
{
    bool test = true;
    try {
        Romb b(12);
    }
    catch (std::exception &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }
    ASSERT_TRUE(true);
    test = false;
    try {
        Romb b(-12);
    }
    catch (std::logic_error &ex) {
        test = true;
    }
    ASSERT_TRUE(true);
}
TEST(ROMB_test, equality)
{
    bool test = true;
    Point a1(0, 0);
    Point b1c(1, 3);
    Point c1(4, 4);
    Point d1(3, 1);
    Romb b12(Point(2, 3), Point(4, 0), Point(2, -3), Point(0, 0));
    Romb b1(Point(2, 3), Point(4, 0), Point(2, -3), Point(0, 0));
    Romb b122(1000);
    Romb z(a1, b1c, c1, d1);
    ASSERT_TRUE(b1 == b12);
    ASSERT_TRUE(b1 == b1);
    ASSERT_FALSE(b1 == b122);
    ASSERT_FALSE(z == b122);
    ASSERT_FALSE(b12 == b122);
}
TEST(ROMB_test, copy_constructor)
{
    bool test = true;
    Romb b12(Point(2, 3), Point(4, 0), Point(2, -3), Point(0, 0));
    try {
        Romb b(b12);
    }
    catch (std::exception &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }
    ASSERT_TRUE(true);
    Romb b(b12);
    ASSERT_TRUE(b == b12);
}
TEST(ROMB_test, assignment_test)
{
    Romb br(123);
    Romb br1(1);
    br1 = br;
    ASSERT_TRUE(br == br1);
}
TEST(ROMB_test, movement_test)
{
    Romb br(123);
    Romb br1(1);
    br = Romb(1);
    ASSERT_TRUE(br == br1);
}
TEST(ROMB_test, area_test)
{
    Romb b(Point(2, 3), Point(4, 0), Point(2, -3), Point(0, 0));
    ASSERT_TRUE(b.area() - 12 < DBL_EPSILON);
    Romb b1(Point(1, 3), Point(4, 4), Point(3, 1), Point(0, 0));
    ASSERT_TRUE(b1.area() - 12 < DBL_EPSILON);
}
TEST(ROMB_test, double_test)
{
    Romb b(Point(2, 3), Point(4, 0), Point(2, -3), Point(0, 0));
    ASSERT_TRUE(static_cast<double>(b) - 12 < DBL_EPSILON);
    Romb b1(Point(1, 3), Point(4, 4), Point(3, 1), Point(0, 0));
    ASSERT_TRUE(b1.area() - 12 < DBL_EPSILON);
}
TEST(ROMB_test, geometric_center)
{
    Romb b(Point(2, 3), Point(4, 0), Point(2, -3), Point(0, 0));
    ASSERT_TRUE(b.geometric_center() == Point(2, 0));
    Romb b1(Point(1, 3), Point(4, 4), Point(3, 1), Point(0, 0));
    ASSERT_TRUE(b1.geometric_center() == Point(2, 2));
}

//_____________________________________________________________________________________________________________________
TEST(Pentagon_test, default_constructor)
{
    bool test = true;
    try {
        Pentagon b;
    }
    catch (std::range_error &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }
    ASSERT_TRUE(true);
}
TEST(Pentagon_test, Point_constructor)
{
    bool test = true;
    try {
        Pentagon b(Point(0, 100), Point(sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)), Point(25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2, -25 - 25 * sqrt(5)), Point(-25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2, -25 - 25 * sqrt(5)), Point(-sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)));
    }
    catch (std::exception &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }
    ASSERT_TRUE(true);
    test = false;
    try {
        Pentagon b(Point(0, 0), Point(4, 0), Point(2, -3), Point(0, 0), Point(190, 9));
    }
    catch (std::logic_error &ex) {
        test = true;
    }
    ASSERT_TRUE(true);
}
TEST(Pentagon_test, side_constructor)
{
    bool test = true;
    try {
        Pentagon b(12);
    }
    catch (std::exception &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }
    ASSERT_TRUE(true);
    test = false;
    try {
        Pentagon b(-12);
    }
    catch (std::logic_error &ex) {
        test = true;
    }
    ASSERT_TRUE(true);
}
TEST(Pentagon_test, equality)
{
    bool test = true;

    Pentagon b(Point(0, 100), Point(sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)), Point(25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2, -25 - 25 * sqrt(5)), Point(-25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2, -25 - 25 * sqrt(5)), Point(-sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)));
    Pentagon b1(Point(0, 100), Point(sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)), Point(25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2, -25 - 25 * sqrt(5)), Point(-25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2, -25 - 25 * sqrt(5)), Point(-sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)));
    Pentagon b3(Point(9 + 0, 100), Point(9 + sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)), Point(9 + 25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2, -25 - 25 * sqrt(5)), Point(9 - 25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2, -25 - 25 * sqrt(5)), Point(9 - sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)));
    ASSERT_TRUE(b1 == b);
    ASSERT_TRUE(b1 == b1);
    ASSERT_FALSE(b1 == b3);
}
TEST(Pentagon_test, copy_constructor)
{
    bool test = true;
    Pentagon b1(123);
    try {
        Pentagon q(b1);
    }
    catch (std::exception &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }
    ASSERT_TRUE(true);
    Pentagon b(b1);
    ASSERT_TRUE(b == b1);
}
TEST(Pentagon_test, assignment_test)
{
    Pentagon br(123);
    Pentagon br1(1);
    br1 = br;
    ASSERT_TRUE(br == br1);
}
TEST(Pentagon_test, movement_test)
{
    Pentagon br(123);
    Pentagon br1(1);
    br = Pentagon(1);
    ASSERT_TRUE(br == br1);
}
TEST(Pentagon_test, area_test)
{
    Pentagon b(10);
    ASSERT_TRUE(b.area() - 172.04774005889672139347 < DBL_EPSILON);
}
TEST(Pentagon_test, double_test)
{
    Pentagon b(10);
    ASSERT_TRUE(static_cast<double>(b) - 172.04774005889672139347 < DBL_EPSILON);
}
TEST(Pentagon_test, geometric_center)
{
    Pentagon b(Point(0, 100), Point(sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)), Point(25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2, -25 - 25 * sqrt(5)), Point(-25 * (-sqrt(2) + sqrt(10)) * sqrt(sqrt(5) + 5) / 2, -25 - 25 * sqrt(5)), Point(-sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)));
    ASSERT_TRUE(b.geometric_center() == Point(0, 2.8421709430404009013e-15));
}
//_____________________________________________________________________________________________________________________
TEST(Hexagon_test, default_constructor)
{
    bool test = true;
    try {
        Hexagon b;
    }
    catch (std::range_error &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }
    ASSERT_TRUE(true);
}
TEST(Hexagon_test, Point_constructor)
{
    bool test = true;
    double Radius = 10;
    Point a = Point(9 + Radius * std::cos(0), Radius * std::sin(0));
    Point b = Point(9 + Radius * std::cos(1 * 2 * pi / 6), Radius * std::sin(1 * 2 * pi / 6));
    Point c = Point(9 + Radius * std::cos(2 * 2 * pi / 6), Radius * std::sin(2 * 2 * pi / 6));
    Point d = Point(9 + Radius * std::cos(3 * 2 * pi / 6), Radius * std::sin(2 * 3 * pi / 6));
    Point e = Point(9 + Radius * std::cos(4 * 2 * pi / 6), Radius * std::sin(4 * 2 * pi / 6));
    Point g = Point(9 + Radius * std::cos(5 * 2 * pi / 6), Radius * std::sin(5 * 2 * pi / 6));
    try {
        Hexagon b1(a, b, c, d, e, g);
    }
    catch (std::exception &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }
    ASSERT_TRUE(true);
    test = false;
    try {
        Hexagon b(Point(0, 0), Point(4, 0), Point(2, -3), Point(0, 0), Point(190, 9), Point(0, 0));
    }
    catch (std::logic_error &ex) {
        test = true;
    }
    ASSERT_TRUE(true);
}
TEST(Hexagon_test, side_constructor)
{
    bool test = true;
    try {
        Hexagon b(12);
    }
    catch (std::exception &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }
    ASSERT_TRUE(true);
    test = false;
    try {
        Hexagon b(-12);
    }
    catch (std::logic_error &ex) {
        test = true;
    }
    ASSERT_TRUE(true);
}
TEST(Hexagon_test, equality)
{
    bool test = true;
    double Radius = 10;
    Point a = Point(9 + Radius * std::cos(0), Radius * std::sin(0));
    Point b = Point(9 + Radius * std::cos(1 * 2 * pi / 6), Radius * std::sin(1 * 2 * pi / 6));
    Point c = Point(9 + Radius * std::cos(2 * 2 * pi / 6), Radius * std::sin(2 * 2 * pi / 6));
    Point d = Point(9 + Radius * std::cos(3 * 2 * pi / 6), Radius * std::sin(2 * 3 * pi / 6));
    Point e = Point(9 + Radius * std::cos(4 * 2 * pi / 6), Radius * std::sin(4 * 2 * pi / 6));
    Point g = Point(9 + Radius * std::cos(5 * 2 * pi / 6), Radius * std::sin(5 * 2 * pi / 6));
    Hexagon b123(a, b, c, d, e, g);
    Hexagon b1(a, b, c, d, e, g);
    Hexagon b3(1);
    ASSERT_TRUE(b1 == b123);
    ASSERT_TRUE(b1 == b1);
    ASSERT_FALSE(b1 == b3);
}
TEST(Hexagon_test, copy_constructor)
{
    bool test = true;
    Hexagon b1(123);
    try {
        Hexagon q(b1);
    }
    catch (std::exception &ex) {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }
    ASSERT_TRUE(true);
    Hexagon b(b1);
    ASSERT_TRUE(b == b1);
}
TEST(Hexagon_test, assignment_test)
{
    Hexagon br(123);
    Hexagon br1(1);
    br1 = br;
    ASSERT_TRUE(br == br1);
}
TEST(Hexagon_test, movement_test)
{
    Hexagon br(123);
    Hexagon br1(1);
    br = Hexagon(1);
    ASSERT_TRUE(br == br1);
}
TEST(Hexagon_test, area_test)
{
    Hexagon b(10);
    ASSERT_TRUE(b.area() - 259.80762113533165802437 < DBL_EPSILON);
}
TEST(Hexagon_test, double_test)
{
    Hexagon b(10);
    ASSERT_TRUE(static_cast<double>(b) - 259.80762113533165802437 < DBL_EPSILON);
}
TEST(Hexagon_test, geometric_center)
{
    double Radius = 10;
    Point a = Point(9 + Radius * std::cos(0), Radius * std::sin(0));
    Point b = Point(9 + Radius * std::cos(1 * 2 * pi / 6), Radius * std::sin(1 * 2 * pi / 6));
    Point c = Point(9 + Radius * std::cos(2 * 2 * pi / 6), Radius * std::sin(2 * 2 * pi / 6));
    Point d = Point(9 + Radius * std::cos(3 * 2 * pi / 6), Radius * std::sin(2 * 3 * pi / 6));
    Point e = Point(9 + Radius * std::cos(4 * 2 * pi / 6), Radius * std::sin(4 * 2 * pi / 6));
    Point g = Point(9 + Radius * std::cos(5 * 2 * pi / 6), Radius * std::sin(5 * 2 * pi / 6));
    Hexagon b12(a, b, c, d, e, g);
    ASSERT_TRUE(b12.geometric_center() == Point(9, 3e-16));
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);


    return RUN_ALL_TESTS();
}
