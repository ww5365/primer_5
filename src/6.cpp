/*
 * 6.cpp
 *
 *  Created on: 2016��8��20��
 *      Author: wangwei69
 *
 *  ͨ�����ѧ���ԣ�c++
 *
 *  �൱�ڷ�������һ��˼·��ȥѧϰ������ԡ�
 *
 *  ���������£�������������
 *
 *  chapter 6: ����
 *  �������磺
 *  ��������(��ֵ��ʵ�Ρ��β�)->
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



    //����ʹ�ó�������

    //������Ϊ�β�

    ///�ɱ�����ĺ���


    ///ʡ�ԺŲ���:�ɱ����


    sum_int(4,344,4,5,6);

    char buf[256];
    buf[0]='\0';

    print_msg(buf,"this is %s test and result is %d","wangwei",1);

    printf("the buf content: %s",buf);
}

/*
 *  ����
 */

//������Ϊ�β�

///�������������ȼۣ�
void print1(const int *); //�βζ���Ϊconst int* ������
void print2(const int[]);  //�β�������һ�����飬��ͼ����
void print3(const int[10]); // �����βδ�С10�ģ���ֹԽ�磬��ι���ָ���βΣ�

///��������ָ�볤�ȵļ���
void print(const int[],const int size); //���ã�ֱ��ָ������
void print(const int [],const int *beg,const int *end);//���飬��ʼԪ��ָ�룬��βԪ�غ�һ��ָ��

///����������Ϊ�βΣ� �ܴﵽ�ı������ڲ�Ԫ�ص�Ŀ�ģ���ζ���,�����Ǹ��ǣ�

//void print(int &arr[10]);  //arr��һ����10���������õ�����
void print(int (&arr)[10]);//yes,not lose parathesis

///��ά������Ϊ��������άʵ����C++û��ʵ�֣���ʵ�����������

void print(int arr[][10]);
void print(int (*arr)[10]);//arr��ָ�룬ָ����10��Ԫ�ص�����

//�ɱ����

///initializer_list�β�

//void err_msg(initializer_list<std::string> para){
//
//    std::cout <<"test" <<std::endl;
//}

///ʡ�Ժ��βΣ�����ͨ������c��c++ͨ�����ͣ������ͨ������ȷ��������

/// <stdarg.h> va_list,va_start(),va_arg(),va_end()
/// ������һϵ�еĺ궨�壻���ݽ������пռ䣬�����ķֲ��������������������ĵ�ַ��
/// ��������������ջ�����Ըߵ�ַ->�͵�ַ����n��->��1��������

void sum_int(const int len,...){ //�������Ͳ����ĺ�,���ȿɱ�

    va_list para;
    va_start(para,len); //sum_res�����һ���̶���������; para ָ���һ�ɱ��������ʼλ��
    int para_value = va_arg(para,int);  //��ȡ��һ��int���Ͳ�����ֵ�� ע��va_arg�ĵڶ����������������ͣ�int

    std::cout << "param:" << 1 << ": "<<para_value <<std::endl;

    for (int i = 1 ;i < len;i++){
        para_value = va_arg(para,int);
        std::cout << "param:" << i+1 << ": "<<para_value <<std::endl;
    }
    va_end(para);
}

///vsnprintf��ӡva_list�����������ܴ�ӡ���ɱ����,�������buf;

void print_msg(char *buf,const char *format,...){
    va_list va_par;
    va_start(va_par,format);
    vsnprintf(buf,256,format,va_par);  //ר�Ÿ�ʽ����ӡva_list����
    va_end(va_par);

}






