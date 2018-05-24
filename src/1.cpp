/*
 * 1.cpp
 *
 *  Created on: 2016��2��24��
 *      Author: wangwei69
 */

#include <iostream>
#include <limits>
#include <cwchar>
#include "1.h"
using namespace std;


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


/*
 * @brief
 *
 * 1��const
 * 2��constexpr:c++11
 * 3��auto:c++11
 * 4��decltype():c++11
 *
 */

//const ���������÷�Χ�� Ĭ��������ļ�����Ч������ʱʹ��extern�������ļ��п���ͨ��
extern int test_const =  random();

void primer_2_4_5(){

    //voidָ�룺�������͵�ָ�븳ֵ����ǿ��ת��Ϊ��Ҫָ������
    void *ptr = nullptr;
    int a = 9;
    ptr = &a;
    cout <<"the result: " << (*(int*)ptr) <<endl;

    //const���ã���ʼ��
    const int &aa = 10;  //����ʹ������ֵ���������ø���ֵ����ȱ��const�ǲ��е�
    const int &aa2 = 2 * test_const; //����const�������ã�ָ����ʽ���������ò����ԣ�
    /*
     * ������ʵ�ʹ��̣�
     * int tmp = 2*test_const; //����һ����ʱ����
     * const int &aa2 = tmp;
     */
    cout <<"aa value: " << aa <<endl;

    //ָ�����ĳ���ָ��
    const int *const ptr_const = &a; //ptr_const���ܸı䣻*ptr_const�е�ֵҲ���ܸı䣻

    //constexpr c++ 11 :�������ʽ������׶ξ�ȷ����ֵ���ô�������׶μ�飿���ߵ�Ч�ʣ�
    //constexpr ��������һ�������ǳ����ұ����ó������ʽ��ʼ��

    constexpr int  i = 32;  //�����ó�����ʾʽ��ֵ��
    const int ii = random(); // ii���ǳ������ʽ

    //constexpr int iii = random();//����ȷ��ֵ��iii���ǳ�����ʾʽ��
    cout << "constexpr: " << i <<endl;

    constexpr char *str ="wangwei"; //str �ǳ���ָ��;*str�����ݿɱ䣻constexprֱ������str������
    const char *str2 = "wangwei2";  //str2 ��ָ���ַ���������ָ��, ���ǳ���ָ�룻const������������
    cout <<"str:" << str <<endl;

    //c++ 11 using :�����Ķ���
    typedef char *string_c1;
    using string_c2 = char *;  //C++ 11 �������ԣ��ȼ��������д��
    const string_c1 test = "wangwei test ";   //test �ǳ���ָ�룻���������ǣ�char* ��const���εľ��ǻ������ͱ��������Ա���test�ǳ�����
    cout <<"c2: " <<test <<endl;

    // c++11 auto :��֪��ĳ�����ʽ�����ͣ���ʹ���䷵��ֵ������ʹ��auto�������ͣ��������Զ�����������ͣ�auto��������Ҫ��ֵ��
    auto tt = test;  //tt ��const char * ���ͣ��ײ�const������������ϲ�const�򲻱���
    const auto t3 = 42 ;  //t3 �����γ���
    const auto &t4 = t3; //t4 �����ͳ�������

    //c++ 11 decltype :��ʹ��ĳ�����������ͣ�������ʹ���������������ֵ��ʹ��decltype��������������ȡ����
    decltype(test) test2 = "szdd"; //test2 ��const char*����
    cout <<"test2: " <<test2 <<endl;

}



/*
 *@brief ʹ��˵��
 *
 *1�����õ�ʹ��˵��:
 *   �����ʼ������ֻ���ñ�����ʼ��
 *   ���ͱ���һֱ
 *
 *
 */

void primer_2_3_1(){

//    //����
//    int &iref;  //���󣬱���Ҫ��ʼ��
    int i = 10;
//    int &iref1 = i; //ok
//    float &iref2 = i; //�������Ͳ�һ��
//    int &iref3 = 10; //����ʹ������ֵ

    int *ptr = &i;
    int *&r_ptr = ptr; //���岢��ʼ����ָ��ָ�������

    const int &iref4 = 10; //ʹ��const�޶�֮�󣬿���ʹ������ֵ��ʼ������

}


/*
 * @brief
 * 1.������ʼ���ļ�����ʽ
 * 2.��������
 */

void primer_2_2_1(){

    //������ʼ����ʽ
    int t1 = 10;  //������ʽ
    int t2 = (10);
    int t3{10}; //c++11�еõ�ȫ��Ӧ�ã��������������ȣ���ʧ��������£�����ִ��;��ʼ���б�
    int t4(10); //��������ʼ���������ܿ�����

    printf("initialization forms:%d %d %d %d",t1, t2, t3, t4);

    //���������������
    int _Test = 10; //_+��д
    int __test = 10; //����_��ͷ

    printf("initialization forms:%d %d",_Test, __test);

}



/*
 * @brief
 * 1������ֵ�����ı�ʾ
 * 2����ͬ���Ʊ�ʾ����ӡ
 * 3��ת������
 */

void primer_2_1_3(){

    //���ƣ����ͺ͸�������ֵ����
    int l_int = 0x17;//16����,��ʶ:0x
    int o_int = 010; //8����,��ʶ:0 Ҳ����˵�����������0��ͷ��ʾһ�����ݣ��ᱻ����8���Ƶġ�
    double l_double = 12.30E4F; //˫���ȸ��㣬E��ʶָ����F��ʶ�Ǹ�������
    long double l_double2 = 12.223e9F;

    printf("int literal : %o,%d,%x,%lf\n", l_int,l_int,l_int,l_double);
    printf("int literal : %o,%d,%x,%.5Lf\n", o_int,o_int,o_int,l_double2);
    //ת������
    bool literal_bool = true;
    char liter_char1 = 'M';
    char liter_char2 = '\115';  //��ת�壬�˽������3�����ֱ�ʶһ���ַ���
    char liter_char3 = '\x4d';   //ʮ������
    char *ptr = NULL;  //��ָ�븳��ֵʹ�ã�0 ��NULL������ʼ��Ϊ��ָ�룻
    char *ptr2 = nullptr;   // c++ 11 �������ˣ�nullptr ����ʼ����ָ�룬�±�׼���Ƽ�ʹ�ã�
    const char *liter_str = u8"hello world";   //ָ�����ַ��������泣��ֵ�����ʽ����utf8

    cout << "result:" << liter_char1 << liter_char2 << liter_char3  << liter_str <<endl;

    /*
     * ����topic��
     *
     * 1������c++ 11 ��׼�ĳ��� -std=c++0x
     *    g++ -std=c++0x -I "D:\workspace\primer_5\inc" -O0 -g3 -Wall -c -fmessage-length=0
     *
     * 2������ֵ�������洢�ڽ������пռ����ĸ����֣�
     *    .txt,.data,.bss,heap,stack
     *    ����ڴ����(.txt),����"hello world";��liter_str��������������stack�Σ�
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

/*
 * @brief signed��unsigned ����
 */
void primer_2_1_2(){


    //1������unsigned,������ѭ��case��

    /*
    cout << "endless loop case, illustration" << endl;
    for (unsigned int i = 3; i >= 0; i--){
        cout << "integer i: " << i << endl;
        //Ϊɶ������
    }
    */


    //2����������ʽ��������ת����signed -> unsigned  �����������

    unsigned int i = -6;
    cout << "i + 5 = " << i + 5 << endl; //��õ�-1�Ľ����

    cout << "the max unsigned int: " << INT_MAX << endl;

}

/*
 * @biref c++11������������,ռ���ֽںͱ�ʾ��Χ
 *
 * numeric_limits<TYTPE> c++11ģ�����ʾ�����������ͷ�Χ:<limits>
 *
 */

void primer_2_1_1(){

    //boolean
    cout << "bool bytes: " << sizeof(bool) << endl;

    //�ַ�����
    char ch_1 = 'A';
    wchar_t wch_1 = L'w';//���ַ����ͣ�L
    char16_t ch16_1 = u'w'; //֧��unicode��չ���룬u
    char32_t ch32_1 = U'w'; //֧��unicode��չ���룬U

    std::cout <<"char bytes:"  << sizeof(ch_1) << " rang:" << static_cast<int>(numeric_limits<char>::min()) << "~" << static_cast<int>(numeric_limits<char>::max()) << endl;
    std::cout << "wchar_t bytes: " << sizeof(wch_1) << " rang:" << numeric_limits<wchar_t>::min() << "~" << numeric_limits<wchar_t>::max() << endl;
    std::cout << "char16_t bytes: " << sizeof(ch16_1) << " rang:" << numeric_limits<char16_t>::min() << "~" << numeric_limits<char16_t>::max() << endl;
    std::cout << "char32_t bytes: " << sizeof(ch32_1) << " rang:" << numeric_limits<char32_t>::min() << "~" << numeric_limits<char32_t>::max() << endl;

    //unsigned short��short

    cout << "unsigned int bytes: " << sizeof(unsigned int) << " rang:"<< numeric_limits<unsigned int>::min() << "~" << numeric_limits<unsigned int>::max() << endl;
    cout << "int bytes: " << sizeof(int) << " rang:"<< numeric_limits<int>::min() << "~" << numeric_limits<int>::max() << endl;


    //unsigned int��int
    cout << "unsigned int bytes: " << sizeof(unsigned int) << " rang:"<< numeric_limits<unsigned int>::min() << "~" << numeric_limits<unsigned int>::max() << endl;
    cout << "int bytes: " << sizeof(int) << " rang:"<< numeric_limits<int>::min() << "~" << numeric_limits<int>::max() << endl;

    //long
    cout << "unsigned long bytes: " << sizeof(unsigned long) << " rang:"<< numeric_limits<unsigned long>::min() << "~" << numeric_limits<unsigned long>::max() << endl;
    cout << "long bytes: " << sizeof(long) << " rang:"<< numeric_limits<long>::min() << "~" << numeric_limits<long>::max() << endl;

    //long long
    cout << "unsigned long bytes: " << sizeof(unsigned long long) << " rang:"<< numeric_limits<unsigned long long>::min() << "~" << numeric_limits<unsigned long long>::max() << endl;
    cout << "long long bytes: " << sizeof(long long) << " rang:"<< numeric_limits<long long >::min() << "~" << numeric_limits<long long>::max() << endl;

    //float,double,long double
    cout << "float bytes: " << sizeof(float) << " rang:"<< numeric_limits<float>::min() << "~" << numeric_limits<float>::max() << " epsilon: " << numeric_limits<float>::epsilon()<< " digits: " <<numeric_limits<float>::digits << endl;
    cout << "double bytes: " << sizeof(double) << " rang:"<< numeric_limits<double>::min() << "~" << numeric_limits<double>::max() << " epsilon: " << numeric_limits<double>::epsilon()<< " digits: " <<numeric_limits<double>::digits << endl;
    cout << "long double bytes: " << sizeof(long double) << " rang:"<< numeric_limits<long double>::min() << "~" << numeric_limits<long double>::max() << " epsilon: " << numeric_limits<long double>::epsilon()<< " digits: " <<numeric_limits<long double>::digits << endl;

}



