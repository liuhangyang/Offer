/*************************************************************************
	> File Name: typechange1.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月21日 星期三 07时30分45秒
 ************************************************************************/

#include<iostream>
using namespace std;
class A
{};
class B:public A
{};
class C
{};
int main()
{
    B b;
    A& a1=b;
    //向上转型,及把子类类型转换为父类类型.  
    B& another_b=static_cast<B&>(a1);
    
}
