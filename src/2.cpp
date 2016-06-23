/*
 * 2.cpp
 *
 *  Created on: 2016年2月26日
 *      Author: wangwei69
 */
#include<iostream>
using namespace std;

void test_2(){

    //void指针：任意类型的指针赋值，再强制转换为想要指针类型
    void *ptr = nullptr;
    int a = 9;
    ptr = &a;
    cout <<"the result: " << (*(int*)ptr) <<endl;

    //const引用
    const int &aa = 10;  //可以使用字面值常量给引用赋初值，但缺少const是不行的
    cout <<"aa value: " << aa <<endl;

    //constexpr c++ 11 :常量表达式
    constexpr int  i = 32;  //i 是常量表达式，字面值赋值
    cout << "constexpr: " << i <<endl;

    constexpr char *str ="wangwei"; //str 是常量指针，和const不同的地方
    const char *str2 = "wangwei2";  //str2 是指向字符串常量的指针, 不是常量指针
    cout <<"str:" << str <<endl;

    //c++ 11 using :别名的定义
    typedef char *string_c1;
    using string_c2 = char *;  //C++ 11 的新特性，等价于上面的写法
    const string_c1 test = "wangwei test ";   //test 是常量指针；不是指向字符常量的指针； 基本类型是：char*
    cout <<"c2: " <<test <<endl;

    // c++11 auto :不知道某个表达式的类型，想使用其返回值，可以使用auto定义类型，编译器自动计算变量类型
    auto tt = test;  //tt 是const char * 类型，底层const保留；如果是上层const则不保留
    const auto t3 = 42 ;  //t3 是整形常量

    //c++ 11 decltype :想使用某个变量的类型，但不想使用这个变量，赋初值；使用decltype将变量的类型提取出来
    decltype(test) test2 = "szdd"; //test2 是const char*类型
    cout <<"test2: " <<test2 <<endl;

}



