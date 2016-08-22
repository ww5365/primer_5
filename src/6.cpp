/*
 * 6.cpp
 *
 *  Created on: 2016年8月20日
 *      Author: wangwei69
 *
 *  通过编程学语言：c++
 *
 *  相当于反过来的一种思路，去学习编程语言。
 *
 *  工欲善其事，必先利其器。
 *
 *  chapter 6: 函数
 *  行文脉络：
 *  函数参数(传值，实参、形参)->
 *
 *
 */

#include <initializer_list>
#include <string>
#include <iostream>

#include <stdarg.h>
#include "4.hpp"


void sum_int(const int len,...);
void print_msg(char *buf,const char *format,...);

void test_6(){



    //尽量使用常量引用

    //数组作为形参

    ///可变参数的函数


    ///省略号参数:可变参数


    sum_int(4,344,4,5,6);

    char buf[256];
    buf[0]='\0';

    print_msg(buf,"this is %s test and result is %d","wangwei",1);

    printf("the buf content: %s",buf);
}

/*
 *  参数
 */

//数组作为形参

///下面三个函数等价；
void print1(const int *); //形参都作为const int* 来看待
void print2(const int[]);  //形参作用于一个数组，意图明显
void print3(const int[10]); // 忽略形参大小10的；防止越界，如何管理指针形参？

///管理数组指针长度的技术
void print(const int[],const int size); //常用，直接指明长度
void print(const int [],const int *beg,const int *end);//数组，开始元素指针，和尾元素后一个指针

///数组引用作为形参？ 能达到改变数组内部元素的目的，如何定义,下面那个是？

//void print(int &arr[10]);  //arr是一个有10个整形引用的数组
void print(int (&arr)[10]);//yes,not lose parathesis

///多维数组作为参数；多维实际在C++没有实现，其实是数组的数组

void print(int arr[][10]);
void print(int (*arr)[10]);//arr是指针，指向有10个元素的数组

//可变参数

///initializer_list形参

//void err_msg(initializer_list<std::string> para){
//
//    std::cout <<"test" <<std::endl;
//}

///省略号形参：参数通常用于c和c++通用类型，类对象通常难正确拷贝传递

/// <stdarg.h> va_list,va_start(),va_arg(),va_end()
/// 本质是一系列的宏定义；根据进程运行空间，参数的分布情况，计算出各个参数的地址；
/// 参数从右向左入栈，所以高地址->低地址：第n个->第1个参数；

void sum_int(const int len,...){ //计算整型参数的和,长度可变

    va_list para;
    va_start(para,len); //sum_res是最后一个固定参数名称; para 指向第一可变参数的起始位置
    int para_value = va_arg(para,int);  //获取第一个int类型参数的值； 注意va_arg的第二个参数是数据类型：int

    std::cout << "param:" << 1 << ": "<<para_value <<std::endl;

    for (int i = 1 ;i < len;i++){
        para_value = va_arg(para,int);
        std::cout << "param:" << i+1 << ": "<<para_value <<std::endl;
    }
    va_end(para);
}

///vsnprintf打印va_list变量，进而能打印出可变参数,结果放在buf;

void print_msg(char *buf,const char *format,...){
    va_list va_par;
    va_start(va_par,format);
    vsnprintf(buf,256,format,va_par);  //专门格式化打印va_list变量
    va_end(va_par);

}






