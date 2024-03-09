#include "googletest/googlemock/include/gmock/gmock.h"
#include "googletest/googletest/include/gtest/gtest.h"
#include "include/Sixnumber.hpp"
#include <fstream>
using namespace std;


TEST(TestGroupName, Constructor_default) {
    bool test=true;
    try{
        Six o;
    }
    catch(std::bad_alloc &ex){
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test=false;
    }

    ASSERT_TRUE(test);
}

TEST(TestGroupName, Constructor_n) {
    bool test=true;
    size_t r=100;
    try{
        Six o(r,'5');
    }catch(std::bad_alloc &ex){
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test=false;
    }
    ASSERT_TRUE(test);
    test=false;
    try{
        Six i(r,'9');
    }catch(std::logic_error &ex){
        std::cout<<"logical exception:"<<ex.what()<<std::endl;
        test=true;
    }
    ASSERT_TRUE(test);
}
TEST(TestGroupName, Constructor_initializer_list) {
   bool test=true;
    try{
        Six o{'5','1','0','3'};
    }
    catch(std::bad_alloc &ex){
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test=false;
    }
    ASSERT_TRUE(test);
    test=false;
    try{
        Six i{'9','1','0','3'};
    }catch(std::logic_error &ex){
        std::cout<<"logical exception:"<<ex.what()<<std::endl;
        test=true;
    }
    ASSERT_TRUE(test);
}
TEST(TestGroupName, test_equality) {
Six o1{'0','5','1'};
Six o2{'0','5','1'};
Six o3{'0','5','1','4'};
Six o4{'2','5','1'};
ASSERT_TRUE(o1==o1);
ASSERT_TRUE(o1==o2);
ASSERT_FALSE(o1==o3);
ASSERT_FALSE(o1==o4);
}
TEST(TestGroupName, test_non_equality) {
Six o1{'0','5','1'};
Six o2{'0','5','1'};
Six o3{'0','5','1','4'};
Six o4{'2','5','1'};
ASSERT_FALSE(o1!=o1);
ASSERT_FALSE(o1!=o2);
ASSERT_TRUE(o1!=o3);
ASSERT_TRUE(o1!=o4);
}
TEST(TestGroupName, shrink_in_constructor_test) {
    Six o1{'0','0','0'};
    Six o;
    ASSERT_TRUE(o==o1);
    Six o2{'1','1','0','0','0'};
    Six o3(2,'1');
    ASSERT_TRUE(o2==o3);
}
TEST(TestGroupName, string_Constructor) {
    string s = "321";
    bool test=true;
    Six o1{'1','2','3'};
    try{
        Six o(s);
    }catch(std::bad_alloc &ex){
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test=false;
    }
    ASSERT_TRUE(test);
    Six o(s);
    ASSERT_TRUE(o1==o);
}
TEST(TestGroupName, Constructor_copy) {
    string s ="12345012340";
    bool test=true;
    Six o1(s);
    try{
        Six o(o1);
    }catch(std::bad_alloc &ex){
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test=false;
    }
    ASSERT_TRUE(test);
    Six o(o1);
    ASSERT_TRUE(o==o1);
}
TEST(TestGroupName, test_greater) {
    string s = "5422312", r = "5422313",e="5452312";
    Six o1;
    Six o2(s);
    Six o3(r);
    Six o4(e);
    ASSERT_TRUE(o2>o1);
    ASSERT_TRUE(o3>o1);
    ASSERT_TRUE(o4>o1);
    ASSERT_FALSE(o1>o2);
    ASSERT_FALSE(o1>o1);
    ASSERT_FALSE(o2>o2);
    ASSERT_FALSE(o2>o3);
    ASSERT_TRUE(o4>o3);
    ASSERT_TRUE(o4>o2);
    ASSERT_TRUE(o4>o3);
    ASSERT_TRUE(o3>o2);
}
TEST(TestGroupName, test_lesser) {
    string s = "5422312", r = "5422313",e="5452312";
    Six o1;
    Six o2(s);
    Six o3(r);
    Six o4(e);
    ASSERT_TRUE(o1<o2);
    ASSERT_TRUE(o1<o3);
    ASSERT_TRUE(o1<o4);
    ASSERT_FALSE(o2<o1);
    ASSERT_FALSE(o1<o1);
    ASSERT_FALSE(o2<o2);
    ASSERT_FALSE(o3<o2);
    ASSERT_TRUE(o2<o3);
    ASSERT_TRUE(o2<o4);
    ASSERT_TRUE(o3<o4);
    ASSERT_TRUE(o2<o3);
}
TEST(TestGroupName, summ_test_1) {
    string s = "123", r = "1234",e="250",i="1524";
    Six o1;
    Six o2(s);
    Six o3(r);
    Six o4(e);
    Six o6(o2);
    Six o7(i);
    Six o8;
    o8+=o8;
    ASSERT_TRUE(o8==o1);
    o6+=o1;
    ASSERT_TRUE(o2==o6);
    o2+=o2;
    ASSERT_TRUE(o2==o4);
    o3+=o4;
    ASSERT_TRUE(o7==o3);

}
TEST(TestGroupName, summ_test_2) {
    string s = "123", r = "1234",e="250",i="1524";
    Six o1;
    Six o2(s);
    Six o3(r);
    Six o4(e);
    Six o7(i);
    ASSERT_TRUE(o1==(o1+o1));
    ASSERT_TRUE(o2==(o2+o1));
    ASSERT_TRUE((o2+o2)==o4);
    ASSERT_TRUE(o7==(o3+o4));

}
TEST(TestGroupName, sub_test_1) {
    string s = "123", r = "1234",e="250",i="544";
    Six o1;
    Six o2(s);
    Six o3(r);
    Six o4(e);
    Six o6(o2);
    Six o7(i);
    Six o8;
    o8-=o8;
    ASSERT_TRUE(o8==o1);
    o6-=o1;
    ASSERT_TRUE(o2==o6);
    o2-=o2;
    ASSERT_TRUE(o2==o1);
    o3-=o4;
    ASSERT_TRUE(o7==o3);
    bool test=false;
    try{
        o8-=o6;
    }
    catch(std::logic_error &ex){
        std::cout<<"logical exception:"<<ex.what()<<std::endl;
        test=true;
    }
    ASSERT_TRUE(test);

}
TEST(TestGroupName, sub_test_2) {
    string s = "123", r = "1234",e="250",i="544";
    Six o1;
    Six o2(s);
    Six o3(r);
    Six o4(e);
    Six o7(i);
    Six o8;
    ASSERT_TRUE((o8-o8)==o1);
    ASSERT_TRUE(o2==(o2-o1));
    ASSERT_TRUE((o2-o2)==o1);
    ASSERT_TRUE(o7==(o3-o4));
    bool test=false;
    try{
       o8-o2;
    }
    catch(std::logic_error &ex){
        std::cout<<"logical exception:"<<ex.what()<<std::endl;
        test=true;
    }
    ASSERT_TRUE(test);

}
TEST(TestGroupName, out_test) {
    std::ofstream test;
    std::ifstream test1;
    test.open("test.txt");
    string s1="123450",s2="";
    Six o(s1);
    test<<o;
    test.close();
    test1.open("test.txt");
    test1>>s2;
    ASSERT_TRUE(s1==s2);
    test1.close();


}
TEST(TestGroupName, Constructor_move) {
     string s = "123",t="250";
     Six o1(t);
     Six o(s);
     Six o2(o+o);
     ASSERT_TRUE(o2==o1);


}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);


    return RUN_ALL_TESTS();
}
