/*
 * 1.cpp
 *
 *  Created on: 2016��2��24��
 *      Author: wangwei69
 */

#include <iostream>
#include "1.h"
using namespace std;

char *get_str_1();
char *get_str_2();
char *get_str_3();

void test_1(){

    //����ֵ����
    bool literal_bool = true;
    char liter_char1 = 'M';
    char liter_char2 = '\115';  //��ת�壬�˽��ƣ���ʶһ���ַ�
    char liter_char3 = '\x4d';   //ʮ������
    double liter_double = 1.23e3;  //�����ͳ���,����1230
    char *ptr = NULL;  //��ָ�븳��ֵʹ�ã�0 ��NULL������ʼ��Ϊ��ָ�룻
    char *ptr2 = nullptr;   // c++ 11 �������ˣ�nullptr ����ʼ����ָ�룬�±�׼���Ƽ�ʹ�ã�
    const char *liter_str = u8"hello world";   //ָ�����ַ��������泣��ֵ�����ʽ����utf8

    cout << "result:" << liter_char1 << liter_char2 << liter_char3 << liter_double << liter_str <<endl;

    /*
     * ����topic��
     *
     * 1������c++ 11 ��׼�ĳ��� -std=c++0x
     *    g++ -std=c++0x -I "D:\workspace\primer_5\inc" -O0 -g3 -Wall -c -fmessage-length=0
     *
     * 2������ֵ�������洢�ڽ������пռ����ĸ����֣�
     *    .txt,.data,.bss,heap,stack
     *    ����ڴ����(.txt),����"hello world";��liter_str����stack�Σ�
     *    liter_str[1] = 'a';  //�ᱨ�δ���
     */

    //��չ�������пռ�����

    char *str1 = get_str_1();// ����Stack���е������ں����˳�ʱ��������
    char *str2 = get_str_2();//��ȷ��ָ��Text���е��ַ�ֱ�������˳������Ż����
    char *str3 = get_str_3();//��ȷ��ָ��Heap���е����ݣ���ûfree()/delete

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

