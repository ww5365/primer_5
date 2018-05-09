/*
 * 1.cpp
 *
 *  Created on: 2016年2月24日
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
 *@brief 使用说明
 *
 *1、引用的使用说明
 *
 */

void primer_2_34(){

//    //引用
//    int &iref;  //错误，必须要初始化
//    int i = 10;
//    int &iref1 = i; //ok
//    float &iref2 = i; //错误，类型不一致
//    int &iref3 = 10; //不能使用字面值







}





/*
 * @brief
 * 1.变量初始化的几种形式
 * 2.变量命名
 */

void primer_2_2_1(){

    //变量初始化形式
    int t1 = 10;  //常见方式
    int t2 = (10);
    int t3{10}; //c++11中得到全面应用；与下面的括号相比，丢失精度情况下，错误不执行;初始化列表
    int t4(10); //类对象定义初始化，经常能看到；

    printf("initialization forms:%d %d %d %d",t1, t2, t3, t4);

    //命名，不建议情况
    int _Test = 10; //_+大写
    int __test = 10; //两个_开头

    printf("initialization forms:%d %d",_Test, __test);





}



/*
 * @brief
 * 1、字面值常量的表示
 * 2、不同进制表示，打印
 * 3、转移序列
 */

void primer_2_1_3(){

    //进制，整型和浮点字面值常量
    int l_int = 0x17;//16进制,标识:0x
    int o_int = 010; //8进制,标识:0 也就是说，不能随便以0开头表示一个数据，会被看做8进制的。
    double l_double = 12.30E4F; //双精度浮点，E标识指数，F标识是浮点类型
    long double l_double2 = 12.223e9F;

    printf("int literal : %o,%d,%x,%lf\n", l_int,l_int,l_int,l_double);
    printf("int literal : %o,%d,%x,%.5Lf\n", o_int,o_int,o_int,l_double2);
    //转义序列
    bool literal_bool = true;
    char liter_char1 = 'M';
    char liter_char2 = '\115';  //泛转义，八进制最多3个数字标识一个字符；
    char liter_char3 = '\x4d';   //十六进制
    char *ptr = NULL;  //空指针赋初值使用：0 ，NULL，来初始化为空指针；
    char *ptr2 = nullptr;   // c++ 11 中引入了：nullptr 来初始化空指针，新标准下推荐使用；
    const char *liter_str = u8"hello world";   //指定了字符串的字面常量值编码格式，是utf8

    cout << "result:" << liter_char1 << liter_char2 << liter_char3  << liter_str <<endl;

    /*
     * 技术topic：
     *
     * 1、编译c++ 11 标准的程序？ -std=c++0x
     *    g++ -std=c++0x -I "D:\workspace\primer_5\inc" -O0 -g3 -Wall -c -fmessage-length=0
     *
     * 2、字面值常量，存储在进程运行空间中哪个部分？
     *    .txt,.data,.bss,heap,stack
     *    存放在代码段(.txt),比如"hello world";但liter_str这个变量本身放在stack段；
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

/*
 * @brief signed、unsigned 区别
 */
void primer_2_1_2(){


    //1、误用unsigned,导致死循环case。

    /*
    cout << "endless loop case, illustration" << endl;
    for (unsigned int i = 3; i >= 0; i--){
        cout << "integer i: " << i << endl;
        //为啥会死？
    }
    */


    //2、编译器隐式数据类型转换：signed -> unsigned  导致数据溢出

    unsigned int i = -6;
    cout << "i + 5 = " << i + 5 << endl; //会得到-1的结果吗？

    cout << "the max unsigned int: " << INT_MAX << endl;

}

/*
 * @biref c++11内置数据类型,占用字节和表示范围
 *
 * numeric_limits<TYTPE> c++11模板类表示基本数据类型范围:<limits>
 *
 */

void primer_2_1_1(){

    //boolean
    cout << "bool bytes: " << sizeof(bool) << endl;

    //字符类型
    char ch_1 = 'A';
    wchar_t wch_1 = L'w';//宽字符类型：L
    char16_t ch16_1 = u'w'; //支持unicode扩展编码，u
    char32_t ch32_1 = U'w'; //支持unicode扩展编码，U

    std::cout <<"char bytes:"  << sizeof(ch_1) << " rang:" << static_cast<int>(numeric_limits<char>::min()) << "~" << static_cast<int>(numeric_limits<char>::max()) << endl;
    std::cout << "wchar_t bytes: " << sizeof(wch_1) << " rang:" << numeric_limits<wchar_t>::min() << "~" << numeric_limits<wchar_t>::max() << endl;
    std::cout << "char16_t bytes: " << sizeof(ch16_1) << " rang:" << numeric_limits<char16_t>::min() << "~" << numeric_limits<char16_t>::max() << endl;
    std::cout << "char32_t bytes: " << sizeof(ch32_1) << " rang:" << numeric_limits<char32_t>::min() << "~" << numeric_limits<char32_t>::max() << endl;

    //unsigned short、short

    cout << "unsigned int bytes: " << sizeof(unsigned int) << " rang:"<< numeric_limits<unsigned int>::min() << "~" << numeric_limits<unsigned int>::max() << endl;
    cout << "int bytes: " << sizeof(int) << " rang:"<< numeric_limits<int>::min() << "~" << numeric_limits<int>::max() << endl;


    //unsigned int、int
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



