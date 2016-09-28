/*************************************************************************
	> File Name: BadSingle.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月27日 星期二 07时23分07秒
 ************************************************************************/

#include<iostream>
using namespace std;
class CSingleton
{
private:
    CSingleton(){ //构造函数是私有的
    }
    //C++ 中静态成员函数必须在类外进行初始化,不然会报错. 
   static  CSingleton *m_pInstance;
public:
    
    static CSingleton* GetInstance()
    {
        if(m_pInstance == NULL){ //判断是否第一次调用
            m_pInstance = new CSingleton();
            return m_pInstance;
        }
    }
};
/**
 *存在的问题:1.m_pInstance指向的空间什么时候释放.
 *2.析构函数什么时候执行. 
 * 解决方法1:在程序结束时调用GetInsatnce()，并对返回的指针做delete操作,不易控制.
 *2.程序在结束时，系统会自动析构所有的全局变量,事实上,系统也会析构所有的类的静态成员变量,因此,我们可以在单例类中定义一个静态成员变量,它的唯一工作就是在析构函数中删除单例类的实例,  
 */
CSingleton* CSingleton::m_pInstance = NULL;
int main(int argc,char *argv[])
{
    CSingleton *p1=CSingleton::GetInstance();
    CSingleton *p2=p1->GetInstance();
    std::cout << "&p1:"<<p1 <<"&p2:"<<p2<<std::endl; 
   return 0;
}
