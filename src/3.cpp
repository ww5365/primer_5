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

    string s1; //��ʼ��Ϊ���ַ���
    string s2 = "wangwei"; //������ʼ��
    string s3 (s2); //ֱ�ӳ�ʼ��
    string s4 (10,'c'); //ֱ�ӳ�ʼ����10��c�������ַ���

    cout << "input string: "<<endl;

    //getline �ӱ�׼���룬��ȡһ������,�������ݿ����пո�

    /*
    while(getline(cin,s1)){//�Ƿ����ļ������� ��ֹ
        if (s1.size() >10)
            cout << s1 <<endl;
    }

    */


    //string ���͵�һЩ����

    s1.empty();    //�ַ����п�
    s1 = s2 + s4;  //�ַ�������
    string::size_type len = s1.size(); //�ַ����ĳ���
    cout <<"s1: "  <<s1 <<endl;



    //��Χfor ���
    cout <<"s4: " << s4 << endl;
    for (auto &c :s4){
        c = toupper(c);  //��Ϊ��c������s4��ÿ��Ԫ�أ�����s4��ֵ������Ϊ��д��
        cout << c <<endl;
    }

    cout <<"s4_2: " <<s4 <<endl;




}
