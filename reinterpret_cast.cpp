/*************************************************************************
	> File Name: reinterpret_cast.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月22日 星期四 07时14分16秒
 ************************************************************************/

#include<iostream>
#include<cassert>
#include<cstdlib>
int f(){return 42;}
int main(int argc,char *argv[])
{
    int i = 7;
    //pointer to integer and back 
    uintptr_t v1 = reinterpret_cast<uintptr_t>(&i); 
    std::cout << "The value of &i is 0x"<<std::hex<< v1 <<std::endl;
    int *p1 = reinterpret_cast<int*>(v1);
    std::cout <<"*p1: "<< *p1 <<std::endl;
    assert(p1 == &i);  

    //pointer to function to another and back. 
    void(*fp1)() = reinterpret_cast<void(*)()>(f);
    //fp1(); undefined behavior
    int(*fp2)() = reinterpret_cast<int(*)()>(fp1);
    std::cout << std::dec <<fp2()<<std::endl;
        
    //type aliasing through pointer 
    char* p2 = reinterpret_cast<char *>(&i);
    if(p2[0] == '\x7'){
        std::cout << "This system is little-endian"<<std::endl;
    }else{
        std::cout << "This system is big-endian"<<std::endl;
    }

    //type aliasing through reference 
    reinterpret_cast<unsigned int&>(i) = 42;
    std::cout << i<< std::endl;

    return 0;
}
