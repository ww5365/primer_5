/*
 * 1.cpp
 *
 *  Created on: 2016年2月24日
 *      Author: wangwei69
 */

#include <iostream>
#include "1.h"
using namespace std;

char *get_str_1();
char *get_str_2();
char *get_str_3();

void test_1(){

    //字面值常量
    bool literal_bool = true;
    char liter_char1 = 'M';
    char liter_char2 = '\115';  //泛转义，八进制，标识一个字符
    char liter_char3 = '\x4d';   //十六进制
    double liter_double = 1.23e3;  //浮点型常量,代表：1230
    char *ptr = NULL;  //空指针赋初值使用：0 ，NULL，来初始化为空指针；
    char *ptr2 = nullptr;   // c++ 11 中引入了：nullptr 来初始化空指针，新标准下推荐使用；
    const char *liter_str = u8"hello world";   //指定了字符串的字面常量值编码格式，是utf8

    cout << "result:" << liter_char1 << liter_char2 << liter_char3 << liter_double << liter_str <<endl;

    /*
     * 技术topic：
     *
     * 1、编译c++ 11 标准的程序？ -std=c++0x
     *    g++ -std=c++0x -I "D:\workspace\primer_5\inc" -O0 -g3 -Wall -c -fmessage-length=0
     *
     * 2、字面值常量，存储在进程运行空间中哪个部分？
     *    .txt,.data,.bss,heap,stack
     *    存放在代码段(.txt),比如"hello world";但liter_str放在stack段；
     *    liter_str[1] = 'a';  //会报段错误
     */

    //扩展进程运行空间的理解

    char *str1 = get_str_1();// 出错，Stack段中的数据在函数退出时就销毁了
    char *str2 = get_str_2();//正确，指向Text段中的字符直接量，退出程序后才会回收
    char *str3 = get_str_3();//正确，指向Heap段中的数据，还没free()/delete

    cout <<"str3:" <<str3 <<endl;
    if (str3!=NULL){
        delete str3;
    }
}


char *get_str_1(){
    char str[] = "hello world"; //stack
    return str;
}

char *get_str_2(){
    char *str = "hello world"; //txt
    return str;
}

char *get_str_3(){
    char tmp[] = "hello world";
    char *str = new char[12];
    memcpy(str,tmp,12);
    return str;               //heap
}

