/*
 * 3.cpp
 *
 *  Created on: 2016年3月1日
 *      Author: wangwei69
 */

#include <string>
#include <iostream>

using namespace std;

void test_3(){

    string s1; //初始化为空字符串
    string s2 = "wangwei"; //拷贝初始化
    string s3 (s2); //直接初始化
    string s4 (10,'c'); //直接初始化，10个c，构成字符串

    cout << "input string: "<<endl;

    //getline 从标准输入，读取一行数据,这行数据可以有空格

    /*
    while(getline(cin,s1)){//非法或文件结束符 终止
        if (s1.size() >10)
            cout << s1 <<endl;
    }

    */


    //string 类型的一些运算

    s1.empty();    //字符串判空
    s1 = s2 + s4;  //字符串连接
    string::size_type len = s1.size(); //字符串的长度
    cout <<"s1: "  <<s1 <<endl;



    //范围for 语句
    cout <<"s4: " << s4 << endl;
    for (auto &c :s4){
        c = toupper(c);  //因为是c是引用s4中每个元素，所以s4的值，都变为大写啦
        cout << c <<endl;
    }

    cout <<"s4_2: " <<s4 <<endl;




}
