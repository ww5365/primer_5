/*
 * 3.cpp
 *
 *  Created on: 2016��3��1��
 *      Author: wangwei69
 */

#include <string>
#include <iostream>

using namespace std;

void test_3(){

    /*
     * string ��ʹ��
     */

    //�ַ�����ʼ��
    string s1; //��ʼ��Ϊ���ַ���
    string s2 = "wangwei"; //������ʼ��
    string s3 (s2); //ֱ�ӳ�ʼ��
    string s4 (10,'c'); //ֱ�ӳ�ʼ����10��c�������ַ���

    char *str = "wangweihao";
    string s5(str,1,3);

    cout << "s5:" <<s5 <<endl;
    cout << "input string: "<<endl;

    //getline �ӱ�׼���룬��ȡһ������,�������ݿ����пո�

    /*
    while(getline(cin,s1)){//�Ƿ����ļ������� ��ֹ
        if (s1.size() >10)
            cout << s1 <<endl;
    }

    */


    //string ���͵�һЩ����

    //c_string �� stringת��
    char str1[] = "wangwei nihao";
    char cpy_str[20];
    s1 = str1;  //c_string ֱ�Ӹ���string
    const char *str2 = s1.c_str(); //��'\0' ��β
    const char *str3 = s1.data();  //û��'\0' ��β
    s1.copy(cpy_str,3,0);  //�����wan ������0��ʼ������Ϊ3���ַ���������cpy_str

    cout << "s1: " <<s1 <<endl;
    cout << "str2: " <<cpy_str <<endl;

    //Ԫ�ش�ȡ

    cout<<"s1[2] " <<s1[2] <<endl;
    cout<<"s1.at " <<s1.at(2) <<endl;  //��Խ����

    //�ַ����ıȽ�

    if(s1 == str1){  //���ԱȽ�string��c_string
        cout << "equal two string content" <<endl;
    }

    if(s1.compare(0,4,s2,0,4) == 0){  //s1:"wangwei nihao" s2:"wangwei"  ǰ4���ַ����бȽ�
        cout << "equal two string content ,just for 4 char" << endl;
    }

    //�ַ�������
    string::size_type ind = s1.find("nn"); //���Ҳ���������npos
    if (ind != string::npos){
        cout << "find !" <<endl;
    }else{
        cout << "not find !" <<endl;
    }
    cout << "size_type : " <<ind <<endl;

    s1.empty();    //�ַ����п�
    s1 = s2 + s4;  //�ַ�������
    string::size_type len = s1.size(); //�ַ����ĳ���,ע��ʹ��string::size_type ����
    cout <<"s1: "  <<s1 <<endl;

    //��Χfor ���
    cout <<"s4: " << s4 << endl;
    for (auto &c :s4){
        c = toupper(c);  //��Ϊ��c������s4��ÿ��Ԫ�أ�����s4��ֵ������Ϊ��д��
        cout << c <<endl;
    }

    cout <<"s4_2: " <<s4 <<endl;

}
