/*
 *  ͷ�ļ��к�������primer��ͷ��,�����½ں�
 *  ���磺primer_2_1_2 ��ʶ��2�£���1�ڵ�2�������discussion��
 *
 *  Created on: 2016��2��26��
 */

#include <iostream>
#include <vector>
#include "1.h"
#include "2.h"
#include "3.h"
#include "4.hpp"



using namespace std;

int main(){

    cout << "hello word!" <<endl;
    primer_2_2_1();

    int res= 0;
    std::string str = "-4c";
    hex_2_dec(str,res);
    cout <<"hex: " << str << " to: " <<res <<endl;
    test_6();

}
