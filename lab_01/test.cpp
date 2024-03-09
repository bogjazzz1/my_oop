#include "googletest/googlemock/include/gmock/gmock.h"
#include "googletest/googletest/include/gtest/gtest.h"
#include "lab_func.hpp"
using namespace std;


TEST(TestGroupName, empty_test) {
    string s = "";
    ASSERT_TRUE(s == lab_func(s));
}

TEST(TestGroupName, simple_test_1) {
    string s = "acb";
    ASSERT_TRUE("bca" == lab_func(s));
}
TEST(TestGroupName, simple_test_2) {
    string s = "aba";
    ASSERT_TRUE("bab" == lab_func(s));
}
TEST(TestGroupName, c_test) {
    string s = "ccccccccc";
    ASSERT_TRUE("ccccccccc" == lab_func(s));
}
TEST(TestGroupName, lab_test_2) {
    string s = "aabacbaa";
    ASSERT_TRUE("bbabcabb" == lab_func(s));
}
TEST(TestGroupName, reverse_test) {
    string s = "aabacbaa", r = "";
    r = lab_func(s);
    ASSERT_TRUE("bbabcabb" == r);
    ASSERT_TRUE(s == lab_func(r));
}
TEST(TestGroupName, false_test_1) {
    string s = "aabacbaa", r = "";
    r = lab_func(s);
    ASSERT_FALSE("cbabcabb" == r);
}
TEST(TestGroupName, false_test_2) {
    string s = "";
    ASSERT_FALSE("c" == lab_func(s));
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);


    return RUN_ALL_TESTS();
}
