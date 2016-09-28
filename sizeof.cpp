/*************************************************************************
	> File Name: sizeof.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月28日 星期三 07时40分00秒
 ************************************************************************/

#include<iostream>
using namespace std;
int GetSize(int data[]){
    return sizeof(data);
}
int main(int argc,char *argv[])
{
    int data1[] = {1,2,3,4,5};
    int size1 = sizeof(data1);

    int* data2 = data1;
    int size2 = sizeof(data2);
    
    int size3 = GetSize(data1);
    std::cout << size1 << size2 <<size3 <<std::endl;
   return 0;
}
