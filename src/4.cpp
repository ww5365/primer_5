/*
 * 4.cpp
 *
 *  Created on: 2016��6��28��
 *      Author: wangwei69
 */

#include "4.hpp"
#include <string>
#include <iostream>

/*
 * ������  ���ʽ
 */


void test_4(){


    //ǰ�ú��ã��������Լ� ���㣺 ����ʹ��ǰ�ð汾���������

   //��Ԫ���������: Ƕ�ף� ���
    int score = 80 ;
    std::string str1 = (score >90)? "high score" :(score < 60)? "not pass" :"usual pass";
    std::cout << "socre: " <<str1 <<std::endl;

    //λ���㣺 >> , <<, ~, & ,| ,^,

    unsigned char bits = 0227;
    std::cout <<"bits: " <<bits <<"reverse bit: " <<~bits <<std::endl; //ȡ���������ǣ�������char��8bit��Ϊint��32�����ٷ�ת

    unsigned long quiz = 17; //�����޷��ų����ͣ���5 bit�Ƿ�Ϊ0��

    bool res = quiz & (1UL << 4); //�Ȼ�ȡ�޷�������ֵ������1UL<<4 �ٽ���������
    std::cout << "the res: " <<res <<std::endl;


    //sizeof �������

    int x[10];
    int *ptr = x;
    int len = sizeof(x)/sizeof(*x); //������������������ܳ��ȣ�*x��һ��Ԫ��ռ�õ��ֽ�����
    std::cout << "compute the len of array: " << len <<std::endl;
    int len2 = sizeof(ptr)/sizeof(*ptr);//ָ����������ָ��Ĵ�С��64bit
    std::cout << "compute the len of array2: "<<sizeof(ptr) <<":" <<sizeof(*ptr) <<":"<<len2 <<std::endl;

    decltype(x) xx;

    int len3 = sizeof(xx)/sizeof(*xx);// xx Ϊint[10] ��������
    std::cout << "compute the len of array3: "<<sizeof(xx) <<":" <<sizeof(*xx) <<":"<<len3 <<std::endl;

    //��ʽ��������ת��

       //������������������ת��ָ�룻 ��sizeof��decltype,&,typeid ���㣬���ǿ������ݣ�����������ܿ�������

       // ָ�룬 ָ������ǳ�����ָ��ת��void *; ָ����������ָ��ת����const void*;


    //��ʾ����ת��   cast_name<type>(expression)

    int i = 2,j = 3;
    double k = static_cast<double> (i)/j; //static_cast : �ײ㲻��const��������ȷ


    /*
     * ��ʾ����ת��:
     * static_case<TYPE>(EXP) : ���
     * const_cast : ֻ�ı���ʽ��ȡ�������ӣ�const���ԣ����ܸı����ͣ� ȡ��const���Ժ󣬶��ڳ������б�д�ķ��գ�ʹ�ó������� �������ص���������
     * dynamic_cast:
     * reinterpret_cast :
     *
     */

    int test = 10;
    const void *ptr1 = &test;

    const int *ptr_exact = static_cast<const int *>(ptr1); //��void * ���͵�ָ��ת��int *

    //int *ptr_exact2 = const_cast<int *>(ptr1);  //���󣬲��ܸı�����

    void *ptr_exact3 = const_cast<void *>(ptr1); //��ȷ������ȥ����const���ԣ����ı����ͣ�














}



