/*************************************************************************
	> File Name: BetteSinigle.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月27日 星期二 17时23分56秒
 ************************************************************************/
 /*第一次调用时产生该类的实例,并且以后返回此实例.
  * 用锁保证安全性,原因:多个线程可能进入判断是否已经存在实例的if语句,从而是非线程安全的.使用double-check
  *来保证thread safety.但是如果处理大量数据时，该锁才能成为严重的性能瓶颈.  
  */
#include<iostream>
#include<mutex>
class Singleton
{
private:
    Singleton(){};
  //Singleton(const Singleton &);
 //Singleton& operator = (const Singleton &);
public:
    static Singleton *Instantialize();
    static Singleton *pInstance;
    static std::mutex mut;

};
Singleton* Singleton::pInstance = NULL; //静态变量要在类外进行初始化或在类外进行声明. 
std::mutex Singleton::mut; //在类外声明但不进行初始化.
Singleton * Singleton::Instantialize(){
    //用两次的原因:
    //1.如果一个线程进入第一个if，加锁,在还没有实例话pInsatnce时，第二个线程进入第一个if,等待锁的释放，第一个线程释放锁后,如果没有第一个if，则会导致第二个线程会再次进行创建. 
    std::cout << "yang" <<std::endl;
    if(pInstance == NULL){
    std::cout << "ddd"<<std::endl;
        std::lock_guard<std::mutex> locker(mut); 
        if(pInstance == NULL){
            pInstance = new Singleton();
        }
    }
    return pInstance;
}
int main(int argc,char *argv[])
{
    Singleton* p1 = Singleton::Instantialize();
    Singleton* p2 = Singleton::Instantialize();
    std::cout << "p1"<<p1 <<" "<<"p2"<<p2<<std::endl;
   return 0;
}

