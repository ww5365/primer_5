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
#include <cassert>

#include <stdarg.h>
#include "4.hpp"


void sum_int(const int len,...);
void print_msg(char *buf,const char *format,...);

int (*fun_ret_2(int arr[][4],int))[4];//����ָ����4���е�����ָ��

constexpr int fun_test(){return 42;}

int calc(char *,char*){return 1;}  // int calc(char* const,char* const );  �ظ�����
int calc(const char* ,const char* ){return 2;}



void test_6(){



    /*
     * ��������
     */

    //����ʹ�ó�������
    //������Ϊ�β�

    ///�ɱ�����ĺ���


    ///ʡ�ԺŲ���:�ɱ����


    sum_int(4,344,4,5,6);

    char buf[256];
    buf[0]='\0';

    print_msg(buf,"this is %s test and result is %d","wangwei",1);

    printf("the buf content: %s",buf);

    /*
     * �����ķ���ֵ
     */

    //��������ָ��,��Զ�ά��������

    int array_test[][4] ={
            {1,2,3,4},
            {4,3,2,1},
            {5,6,7,8}
    };

    int (*ptr) [4] ;
    int size_test = sizeof(array_test)/sizeof(array_test[0]);
    ptr = fun_ret_2(array_test,size_test);

    int *ptr2 = array_test[1];

    for(auto i =0 ;i<4;i++){
        std::cout << std::endl
        <<"two dimension:" << (ptr2)[i] <<" ";
    }

    std::cout <<std::endl;
    //���������������;����������  ����


    //constexpr ����   ��;��    ���磺 constexpr int fun_test(){return 42;} �������ǳ�������������

    int array[fun_test()]; //constexpr: ������������ʱ��constexpr���������滻�ɽ��ֵ

    //�����ĵ��Լ����� ˼�룺����ʱʹ�ã����ߺ�Ҫ���ε����Դ���

    ///assert Ԥ����꣬ͷ�ļ�cassert
    assert(1<3); //����Ϊ�棬����ִ������Ĵ��룻����Ϊ��0�������Ϣ����ֹ����

    ///NDEBUG :
    ////1. gcc -D NDEBUG main.c  : �ӱ���������NDEBUG����ִ�е��Գ����൱����main��ʼ������ #define NDEBUG��ͬʱassertҲ������Ч��
    ////2. #ifndef NDEBUG ...#endif  : û�ж��岻���е��Ա�ʶ��Ҳ���ǽ��е��ԣ�ִ�е��Դ���

    #ifndef NDEBUG

    std::cout <<"function:" << __func__  //������Ϊÿ����������ģ���ź�������
         <<" at file:"  << __FILE__   //Ԥ���������壬�����õ�����4����Ϣ
         <<" at line:"  << __LINE__
         <<" on date:"  << __DATE__
         <<" at time:"  << __TIME__
         <<std::endl;

    #endif




    std::cout <<"this is programmer end"<<std::endl;


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


/*
 * �����ķ���ֵ
 */

//��ֵ����

///��α����أ�������ֵ���ص����õ�

///���ܷ��ؾֲ�������ָ�������

const std::string &fun_p(){
    std::string ret;
    if (!ret.empty())
        return ret;  // ���󣺾ֲ�����
    else
        return "empty"; //���󣺾ֲ�����
}

///���طǳ������ã���Ϊ��ֵ�� ������

char &get_first_char(std::string str){
    if(!str.empty())
        return str[0];
}

void test(){
    std::string tt = "hangwei";
    get_first_char(tt) = 'w'; //��һ���ַ���Ϊw
    std::cout << tt <<std::endl;
}


//��������ֵ����������ָ��

typedef int arr1[10];  //arr1��int[10]���ͱ���
using arr2 = int [10]; //ͬ�ϣ�c++11

arr1 *fun1(int len);//��������ֵ��ָ��int[10]��һ��ָ��

int (*fun2(int len))[10]; //ͬ�ϣ������Ķ��巽ʽ

//int *fun2_1(int len)[10]; //����ֵ��һ������10��ָ��Ԫ�ص�����

auto fun3(int len) ->int (*)[10]; //c++11 β�õķ�����������


int (*fun_ret_2(int arr[][4] ,int size))[4]{
    //���ض�ά�����еڶ��е���ָ��
    if(size>=2){
        int (*ptr)[4] ;
        ptr = &arr[1];
        return ptr;
    }
    return 0;
}


//���������������;����������

///Ĭ��ʵ��
std::string screen(size_t h = 24, size_t w = 80, char back_grd = 'a'){return NULL;}//ע��Ĭ��ʵ�Σ��ӵ�һ��Ĭ�Ͽ�ʼ���������������Ĭ��

///�������� inline  ע�������ͺ궨�������  �׶Σ����룬Ԥ����  ������飺�У���  ��

inline int fun_test(int a, int b){
    return a>b?a:b; //�����������������ڵ��õ�ֱ��չ���ñ��ʽ
}













