/*************************************************************************
	> File Name: typechange.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月21日 星期三 07时27分19秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(int argc,char *argv[])
{
    int c = static_cast<int>(7.987);
    std::cout<< "c:"<<c<<std::endl;
   return 0;
}
