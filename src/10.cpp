/*
 * 10.cpp
 *
 *  Created on: Feb 12, 2019
 *      Author: wangwei69
 */


#include "all.hpp"

#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <string>
#include <deque>
#include <iostream>
#include <functional>

using namespace std;
using namespace std::placeholders;


bool cmp_len(const string &s1, const string &s2){
    return s1.size() < s2.size();
}

bool cal_len(const string &s){
    return s.size() >= 3;
}

bool bigger_len(const string &s, string::size_type len){

    return s.size() >= len;
}

void print(const string &s, const string &tips){
    cout << tips << " " << s << endl;
}

/*
 *  ��10�� �����㷨
 *
 *  "����": ��ĳ�����ݽṹӵ�и���Ĳ���,���������ĳ�Ա����������ͨ���ԣ� ���������ڣ� ���� �� ����
 *
 *  algorithm
 *  numeric
 *
 *  �㷨��������������ֻ�������������������в���ͨ����������ʵ�֡�
 *       100����㷨�����ȥͨ���Ե����ʹ�����ǣ�
 *       �㷨���Ƿ��ȡԪ�ء��ı�Ԫ�ء�����Ԫ�أ�
 *
 *
 *  �㷨���ܣ�
 *
 *  find
 *  find_if
 *  count
 *  accumulate
 *  equal
 *
 *  fill
 *  fill_n
 *  copy
 *
 *  remove
 *  remove_if
 *  remove_copy_if
 *
 *  unique
 *  sort
 *  stable_sort
 *  partition
 *  reverse
 *
 *
 *  ���list forward_list�������㷨�������Ա����:
 *  �ı�������Ԫ��
 *
 *
 *
 *
 *  �㷨�����淶��
 *
 *  1. �ö������ص���ʽ��֧�ִ���ν��
 *     sort(b,e)
 *     sort(b,e, predicate)
 *
 *  2. _if�汾
 *
 *     ���������ˣ�ֱ��������һ����������Ϊ����������ͬ����������
 *
 *     find
 *     find_if
 *  3. �����Ͳ������汾
 *
 *     reverse(b,e) : ֱ����ԭ�����н��в�������ת
 *     reverse(b,e,dest)  : ��ת��Ľ�������浽dest��ԭ������Ԫ�ز���
 *
 *     remove_if(b,e, predicate)
 *     remove_copy_if(b,e,dest, prdicate)
 *
 *  4. �����ʶ��
 *
 *     replace(b,e, old, new)
 *     replace_if(b,e, predict, new)  //ν��
 *     replace_copy(b,e,dest,old, new) //ԭ������ֵ���䣻����ŵ�dest�����У�
 *     replace_copy_if(b,e,dest,predicate, new)
 *
 *
 *
 *
 */


void test_10(){

    /*
     * ֻ���㷨:
     * find
     * count
     * accumulate:���
     *
     * equal: �Ƚ�����������Ԫ�أ��Ƿ�һ�£��������ͣ�Ԫ�����ͣ���ʱ�����Բ�ͬ��
     *
     */

    vector<string> vec1 = {"wang", "wei", "ni", "hao"};

    //find
    auto it = find(vec1.cbegin(), vec1.cend(), "ni");
    if (it != vec1.end()){
        //������β�����������˵����������ָ���ַ���
        cout << "only read algorithm: find: " << *it << endl;
    }

    //accumulate: ��������"��"���㣻������Ԫ�������ǳ�ʼֵ��ͬʱ�����������Ԫ��������ͬ��
    string sum = accumulate(vec1.cbegin(), vec1.cend(), string("")); //������Ԫ�ز�����:"" �� const char* ��֧�� + ����
    cout << "only read algorithm: accumulate: " << sum << endl;


    //equal: ����3����������3���������¸���������ʼ���������¸��������ȣ����ڵ��ڵ�һ���������Ƚ�Ԫ�ظ�������һ�������ĳ���
    list<const char*> list1 = {"wang", "wei", "ni","hao", "a"};
    bool res = equal(vec1.cbegin(), vec1.cend(), list1.cbegin()); //��Ȼ�����������Ȳ�ͬ����vec1���ȷ�Χ�ڣ�Ԫ��ֵ������ȵģ�����true
    cout << "only read algorithm: equal: " << res << endl;



    /*
     * д�����㷨��
     *
     * fill: (b, e, V) �����������ǲ����ֵ
     * fill_n: (b, n, V) : ��������bָ��������У�ǰn��Ԫ�أ���ΪV
     *
     */

    vector<string> vec2;

    //fill:
    fill(vec2.begin(), vec2.end(), "test"); //vec2���ǿյ�
    //fill_n(vec2.begin(),1, "test"); //������������в���1��Ԫ�أ��ı�������С�ˡ�������������������
    fill_n(vec2.begin(), vec2.size(), "test");

    fill_n(back_inserter(vec2), 1, "test"); //back_inserter���������ģ����������
    cout << "write algorithm: fill: " << vec2.size() << endl;

    //copy(b, e, dest): ע�Ᵽ֤Ŀ�ĵ�ַ��dest��С�ٶ���>=��һ��������

    int ai[] = {1,2,3,4};
    constexpr int SIZE = sizeof(ai)/sizeof(*ai);
    vector<int> vec3;//(SIZE, 0);
    vec3.resize(SIZE);
    copy(begin(ai), end(ai), vec3.begin()); //���뱣֤vec3��size>=4

    cout << "write algorithm: copy: " << vec3.size() << endl;



    /*
     * �����㷨��
     *
     * sort    :  ����
     * unique  :  �����ظ���Ԫ�أ�����������ɾ��Ԫ�أ�ֻ����ǰ�����ˣ��������һ�����ظ���Ԫ�ص�β���������
     *
     */


    vector<string> vec4 = {"wang", "wei", "ni", "ni","hao", "a", "a"}; //�����ֵ������򣬲�ȥ��
    sort(vec4.begin(), vec4.end()); //Ĭ��ʹ��Ԫ�ص� < Ԫ�ط����Ƚϴ�С
    vector<string>::iterator it4 =  unique(vec4.begin(), vec4.end()); //�㷨����ı�������С�����ز��ظ�Ԫ��β���������
    vec4.erase(it4, vec4.end()); //�����Դ�������ɾ������ģ�"����"Ԫ��

    for (auto e : vec4){
        cout << "sort and unique algorithm: " << e << endl;
    }



    /*
     * ���Ʋ�����
     *
     *
     *  1���㷨���ݺ�����predicate  ν��  һԪ�Ͷ�Ԫ
     *
     *  ��ǰ�Ӵ����� ��ɱȽϵ�С����������bool��
     *
     *   bool cmp(const string &s1, const string &s2)
     *
     *   sort
     *   stable_sort
     *   partition
     *
     *
     *  2��lambda�� �������������ٶ���ĵ�����С������ ��lisp������ģ�
     *
     *  ��ʽ��  [�����б�](�����б�)->TYPE {������}
     *
     *  ѡ�ã� ֻ��һ�����ط�ʹ�ü򵥲����� ����Ƕ��ʹ�ã����ǽ�����Ƴɺ�����û�в���������������������Կ�����ν�������
     *        ���ֲ�����ʹ��ν��ʱ��ֻ����1��2����ͬ���Ͳ������в������������������ͨ�������ú��������
     *
     *  ˵����
     *
     *    ����ı��������ں��������������ڵģ�
     *     []
     *     [names]
     *     [=] : ��ʽ ֵ����
     *     [&] : ��ʽ ���ò���
     *     [=, identifier_list]  : identifier_list,��������ʾ ���ò���
     *     [&, identifier_list]  : identifier_list,��������ʾ ֵ����
     *
     *     �����б���ʽ����ʽ�� ֵ�������ò���
     *
     *     ֵ���� Ҫ��lambda�иı����ֵ����Ҫ��()���mutable
     *
     *    ���������г�return֮�����䣬�������β�÷������ͣ�����Ĭ����void��
     *
     *    3��bind  :  <functional>
     *
     *
     *    ����lambda�����봫�ݲ������㷨�еĿɵ��ö���������֣�
     *
     *    bind ���������� ʵ�ʾ����ã� newCallable(X,Y) ���������� callable(..,X,Y)
     *
     *    auto newCallable = bind(callable, ARG_LIST);
     *
     *    �µĿɵ��ö��� newCallable
     *    ARG_LIST: ռλ���� _1 ����newCallable�ĵ�һ���������������ơ������ڿռ�:placeholders
     *
     *              Ҫʹ���ⲿ���������ã���ô�죿����ֵ��������ͨ����ref��cref,������ֵ����callable����
     *
     *
     */


     //ν��ʹ��:

    //��vec4�����ַ����ĳ��ȴ�С��������,���ȵ�����������ͬ�İ���ԭ�����ֶ����У�
    stable_sort(vec4.begin(), vec4.end(), cmp_len); //��Ԫ

    vector<string> vec5 = {"abcd", "abc", "ab","abcde","a"};
    //partition : ν�ʷ���true����Ԫ�طŵ�ǰ�棻����false����Ԫ�طŵ����棻���أ����һ��ʹν��Ϊtrue֮���λ�ã�
    auto it5 = partition(vec5.begin(), vec5.end(), cal_len); //һԪ  �����abcd abc abcde ab a


    //lambdaʹ�ã�

    //Ѱ�ҳ���>=5���ַ���������ӡ��

    vector<string> vec6 = {"abcdef", "abc", "ab","abcde","abcdefg"};
    string::size_type sz = 4;

    stable_sort(vec6.begin(), vec6.end(),
                [](const string &s1, const string &s2)
                  { return s1.size() < s2.size(); }
               );//�Ȱ��ճ��ȴ�С���ַ�����������  ab abc abcde abcdef abcdefg


    //find_if
    auto it6 = find_if(vec6.begin(), vec6.end(),
                       [sz](const string &s)  mutable -> string::size_type  //ֵ����ķ�ʽ,�ı�szֵ������mutable; �г�return֮����䣬->Ҳ�����٣�
                       { if(sz <= 4) sz = 5;
                         return s.size() >= sz;
                       } );//ÿ��Ԫ���ж��Ƿ����sz���ҵ���һ������sz��Ԫ�أ����ش�λ�õ�������

    cout << "find_if: " << *it6 << endl;  //ָ��abcde��λ��

    //for_each
    for_each(it6, vec6.end(), [](const string &s)
             {cout << "bigger len 5: " << s << endl;}); //��ӡ��it6��ʼ��Ԫ�أ�


    // bind
    auto bigger_len_new = bind(bigger_len, _1, sz); //_1:ռλ�� ����cmp_len_new�ĵ�һ������;sz��ֵ�����ķ�ʽ���ݣ����÷�ʽ��ref,cref
    //����cmp_len_new(str), �൱�ڵ���bigger_len(str,sz)
    auto it6_2 = find_if(vec6.begin(), vec6.end(), bigger_len_new); //bind�����µĿɵ��ö���cmp_len_new һԪν��
    cout << "find_if_2: " << *it6_2 << endl;  //ָ��abcde��λ��


    /*
     * ��̽��������
     *
     * 1�����������
     *
     *    ��ͨ�������ǲ��ܸı�������С���������������룬ɾ�����ݣ����Բ����˲����������ʵ���ǵ�������������;
     *    ��������������
     *    ���أ�������
     *    ʵ�֣�����Ԫ�صĹ���
     *
     *   back_inserter(c)
     *   front_inserter(c) :  �������ֵ�� һֱ�������µ�ͷԪ��λ��;
     *   inserter(c, iter) : c������iter��Ҫ����Ԫ�ص�λ�ã�����ֵ��һֱ������������iterλ�ò��䣻
     *
     *  2�����������������
     *
     *    ƽʱ�õ���Щ������Ҫ��������
     *
     *  3�����������
     *
     *    ������������cbegin,cend, begin , end
     *
     *    �����������
     *    rbegin: ���һ��Ԫ�ص�λ��
     *    rend: ��һ��Ԫ��֮ǰ��λ��
     *    crbegin : ����������
     *    crend
     *
     *    ++ : �����ǴӺ���ǰ�ƶ�
     *    __ : �Ǵ�ǰ�����ƶ�
     *
     */


    list<string> l7 = {"wang", "wei", "ni", "hao"};
    deque<string> dec8,dec9; //����������vector����,Ҫcopy����Ԫ�أ���Ҫ�ã����������

    //front_inserter
    copy(l7.begin(), l7.end(), front_inserter(dec8)); //ͷ�壬�õ�����dec8�� hao ni wei wang
    for_each(dec8.begin(), dec8.end(), [](const string &s) {cout << "front inserter: " << s << endl;});

    //inserter
    copy(l7.begin(), l7.end(), inserter(dec9, dec9.begin())); //inserter����ֵ��һֱ������ԭλ���ϣ�
    string tips_str("");
    tips_str.assign("inserter: ");
    auto printstr = bind(print, _1, tips_str); //��һ����ӡ������������Ծ������for_each��ʹ��

    for_each(dec9.begin(), dec9.end(), printstr); //�㷨���һԪν�ʣ�����һ������:str

    //reverse_iterator
    string str10 = "this is test reverse_iterator";  //��ȡ_֮����ַ���
    auto it10 =  find(str10.crbegin(), str10.crend(), '_');
    cout << "reverse_iterator : " << *it10 << endl;
    string::const_iterator it100 = it10.base(); //base���ѷ����������������������ͬʱ��λ��ָ��'_'����һ��λ��

    cout << "reverse_iterator base: " << string(it100, str10.cend()) << endl;



    /*
     * �㷨�����淶
     *
     *  remove
     *  remove_if
     *  remove_copy_if
     *
     */


    vector<int> vec11 = {1,2,3,4,5,6,7,8,9,10};
    vector<int> dest;
    remove(vec11.begin(), vec11.end(), 5); //ɾ��ֵ: 5  ������vec��β�������
    cout << "remove size: " << vec11.size() << endl;  //������ɾ��Ԫ�أ�������С���䣻

    remove_copy(vec11.begin(), vec11.end(), back_inserter(dest), 5);

    for(auto e : dest){
        cout << "remove: " << e << endl;
    }


    /*
     * topic: list forward_list���е��㷨����Ƴɳ�Ա����
     *
     *    l1.merge(l2)
     *    l1.merge(l2, cmp): ע�� l1 �� l2 ����������ģ��ϲ���l2ɾ��Ϊ�գ�
     *
     *    l1.remove(val)
     *    l1.remove(pre): Ҫ��ɾ�����൱��erease
     *
     *    l1.reverse(): ����ת
     *
     *    l1.sort
     *    l1.sort(cmp):
     *
     *    l1.queue()
     *    l1.queue(pre):
     *
     *
     *    l1.splice()/splice_after(): ������һ��������Ԫ�أ��ŵ��Լ���������
     *
     *    (p, l2):       ����l2������Ԫ�أ��ŵ�p֮ǰ/֮��λ�ã� l1��l2��ͬ
     *
     *    (p, l2, p2):   ����l2��p2ָ���Ԫ�أ���l1�У�l1��l2������ͬ
     *
     *    (p, l2, b, e):  ��l2��[b,e)��Χ�ڵ�Ԫ�ؼ��е�p֮ǰ��
     *
     *
     *
     */


    list<int> l1 =  {4,2,5,6};
    list<int> l2 =  {1,3,5,2};

    l1.sort();
    l2.sort();
    //merge ������֮�����򼯺Ϻϲ�
    l1.merge(l2);

    //reverse
    l1.reverse(); //�����6,5,5,4,3,2,2,1

    cout << "the length l2: " << l2.size() << endl;
    list<int>::iterator it_l1 = ++ l1.begin();  //������iterator��һ����������

    //splice
    l1.splice(l1.begin(), l1 , it_l1); //�ѵ�2��Ԫ�أ����е���Ԫ��֮ǰ�����Ӧ���ǣ�5,6,5,4,3,2,2,1;

    l1.splice(l1.begin(), l1, ++l1.begin(), --l1.end()); //�ѵڶ���Ԫ�ص������ڶ���Ԫ��֮���list�����е���Ԫ��֮ǰ��6,5,4,3,2,2,5,1

    for(auto e : l1){

        cout << "the merge: " << e << endl;
    }


}
