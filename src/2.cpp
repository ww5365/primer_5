/*
 * 2.cpp
 *
 *  Created on: 2016��2��26��
 *      Author: wangwei69
 */
#include<iostream>
using namespace std;

void test_2(){

    //void ָ�룬�������͵�ָ�븳ֵ����ǿ��ת��Ϊ��Ҫָ������

    void * ptr = nullptr;
    int a = 9;
    int *ptr = &a;
    cout <<"the result: " << (*(int*)ptr) <<endl;

    //const ����

    const int & aa = 10;  //����ʹ������ֵ���������ø���ֵ����ȱ��const�ǲ��е�
    cout <<"aa value: " << aa <<endl;

    // constexpr  c++ 11 ���������ʽ

    constexpr int  i = 32;  //i �ǳ������ʽ������ֵ��ֵ
    cout << "constexpr: " << i <<endl;
    constexpr char *str ="wangwei"; //str �ǳ���ָ�룬��const��ͬ�ĵط�
    //str[0] = '2';
    cout <<"str:" << str <<endl;

    //�����Ķ���
    typedef char *string_c1;
    using string_c2 = char *;  //C++ 11 �������ԣ��ȼ��������д��
    const string_c1 test = "wangwei test ";   //test �ǳ���ָ�룻����ָ���ַ�������ָ�룻 ���������ǣ�char*
    cout <<"c2: " <<test <<endl;

    // auto�� ��֪��ĳ�����ʽ�����ͣ���ʹ���䷵��ֵ������ʹ��auto�������ͣ��������Զ������������
    auto tt = test;  //tt ��const char * ���ͣ��ײ�const����
    const auto t3 = 42 ;  //t3 �����γ���

    //decltype����ʹ��ĳ�����ʽ�����ͣ�������ʹ��������ʽ������ֵ��ʹ��decltype�����ʽ��������ȡ����
    decltype(test) test2 = "szdd"; //test2 ��const char*����
    cout <<"test2: " <<test2 <<endl;





}



