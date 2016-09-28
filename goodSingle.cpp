/*************************************************************************
	> File Name: goodSingle.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月27日 星期二 16时41分50秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
class CSingleton
{
private:
    CSingleton(){

    }
public:
    static CSingleton &GetInstance(){
        static CSingleton instance; //局部静态变量. 
        return instance;
    }
/*1.使用局部静态变量,完全实现了单例的特性,而且代码量更少,也不用担心单例销毁问题.
 * 问题:Singleton singleton = Singleton::GetInstance();
 *这么做就出现了类拷贝的问题,这违背了单例的特性.产生的原因:编译器会为类默认生成拷贝构造函数来支持类的拷贝.
 *
 *
 */
};
int main(int argc,char *argv[])
{
  CSingleton singleton = CSingleton::GetInstance();
  printf("Singleton:%p\n",singleton);
    CSingleton singleton1 = CSingleton::GetInstance();
    printf("Singleton1:%p\n",singleton1);
    return 0;
}
