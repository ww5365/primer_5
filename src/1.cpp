/*
 * 1.cpp
 *
 *  Created on: 2016��2��24��
 *      Author: wangwei69
 */

#include <iostream>
#include "1.h"
using namespace std;

void test_1(){

    //���泣��ֵ

    bool literal_bool = true;

    char liter_char1 = 'M';
    char liter_char2 = '\115';  //ת�壬�˽���
    char liter_char3 = '\x4d';   //ʮ������

    double liter_double = 1.23e3;

    const char *liter_str = u8"hello world";   //ָ�����ַ��������泣��ֵ����utf8��

    cout << "result:" << liter_char1 << liter_char2 << liter_char3 << liter_double << liter_str <<endl;

}
