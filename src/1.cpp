/*
 * 1.cpp
 *
 *  Created on: 2016年2月24日
 *      Author: wangwei69
 */

#include <iostream>
#include "1.h"
using namespace std;

void test_1(){

    //字面常量值

    bool literal_bool = true;

    char liter_char1 = 'M';
    char liter_char2 = '\115';  //转义，八进制
    char liter_char3 = '\x4d';   //十六进制

    double liter_double = 1.23e3;

    const char *liter_str = u8"hello world";   //指定了字符串的字面常量值，是utf8的

    cout << "result:" << liter_char1 << liter_char2 << liter_char3 << liter_double << liter_str <<endl;

}
