/*
 * primer.cpp
 *
 *  Created on: 2016Äê2ÔÂ26ÈÕ
 *      Author: wangwei69
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
    int res= 0;
    std::string str = "-4c";
    hex_2_dec(str,res);
    cout <<"hex: " << str << " to: " <<res <<endl;
    test_6();

}
