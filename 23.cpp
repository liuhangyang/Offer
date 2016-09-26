/*************************************************************************
	> File Name: 23.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月23日 星期五 07时27分37秒
 ************************************************************************/

#include<iostream>
class A
{
private: 
    int value;
public:
    A(int n){
        value=n;
    }
    A(const A& other){
        value = other.value;
    }
    void print(){
        std::cout << value <<std::endl;
    }
};
int main(int argc,char *argv[])
{
    A a = 10;
    A b = a;
    b.print();
   return 0;
}
