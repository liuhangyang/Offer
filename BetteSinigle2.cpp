/*************************************************************************
	> File Name: BetteSinigle2.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月27日 星期二 20时01分54秒
 ************************************************************************/

#include<iostream>
class SingletonStatic
{
private:
    static const SingletonStatic* m_instance;
    SingletonStatic(){}
public:
    static const SingletonStatic* getInstance(){
        return m_instance;
    }
};
const SingletonStatic* SingletonStatic::m_instance = new SingletonStatic;
int main(int argc,char *argv[])
{
   const SingletonStatic *p1 = SingletonStatic::getInstance();
   const SingletonStatic *p2 = SingletonStatic::getInstance();
    std::cout << "p1:"<<p1 <<" "<< "p2:"<<p2<<std::endl;
   return 0;
}
