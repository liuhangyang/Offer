/*************************************************************************
	> File Name: delete.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月26日 星期一 14时51分12秒
 ************************************************************************/

#include<iostream>
class T{
public:
    T(){
        std::cout <<"constructor"<<std::endl;
    }
    ~T(){
        std::cout << "destructor"<<std::endl;
    }
};
int main(int argc,char *argv[])
{
    const int  NUM = 3;
    T* p1 = new T[NUM];
    std::cout <<"hex::"<<std::hex << p1<<std::endl;
    //delete []p1;
    delete []p1;

    T* p2 = new T[NUM];
    std::cout << p2 <<std::endl;
    delete[] p2;
   return 0;
}
