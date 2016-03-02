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

    /*
     * string 的使用
     */

    //字符串初始化
    string s1; //初始化为空字符串
    string s2 = "wangwei"; //拷贝初始化
    string s3 (s2); //直接初始化
    string s4 (10,'c'); //直接初始化，10个c，构成字符串

    char *str = "wangweihao";
    string s5(str,1,3);

    cout << "s5:" <<s5 <<endl;
    cout << "input string: "<<endl;

    //getline 从标准输入，读取一行数据,这行数据可以有空格

    /*
    while(getline(cin,s1)){//非法或文件结束符 终止
        if (s1.size() >10)
            cout << s1 <<endl;
    }

    */


    //string 类型的一些运算

    //c_string 和 string转换
    char str1[] = "wangwei nihao";
    char cpy_str[20];
    s1 = str1;  //c_string 直接赋给string
    const char *str2 = s1.c_str(); //以'\0' 结尾
    const char *str3 = s1.data();  //没有'\0' 结尾
    s1.copy(cpy_str,3,0);  //结果：wan 从索引0开始，长度为3的字符串拷贝给cpy_str

    cout << "s1: " <<s1 <<endl;
    cout << "str2: " <<cpy_str <<endl;

    //元素存取

    cout<<"s1[2] " <<s1[2] <<endl;
    cout<<"s1.at " <<s1.at(2) <<endl;  //有越界检查

    //字符串的比较

    if(s1 == str1){  //可以比较string和c_string
        cout << "equal two string content" <<endl;
    }

    if(s1.compare(0,4,s2,0,4) == 0){  //s1:"wangwei nihao" s2:"wangwei"  前4个字符进行比较
        cout << "equal two string content ,just for 4 char" << endl;
    }

    //字符串查找
    string::size_type ind = s1.find("nn"); //查找不到，返回npos
    if (ind != string::npos){
        cout << "find !" <<endl;
    }else{
        cout << "not find !" <<endl;
    }
    cout << "size_type : " <<ind <<endl;

    s1.empty();    //字符串判空
    s1 = s2 + s4;  //字符串连接
    string::size_type len = s1.size(); //字符串的长度,注意使用string::size_type 类型
    cout <<"s1: "  <<s1 <<endl;

    //范围for 语句
    cout <<"s4: " << s4 << endl;
    for (auto &c :s4){
        c = toupper(c);  //因为是c是引用s4中每个元素，所以s4的值，都变为大写啦
        cout << c <<endl;
    }

    cout <<"s4_2: " <<s4 <<endl;

}
