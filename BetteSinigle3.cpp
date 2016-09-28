/*************************************************************************
	> File Name: BetteSinigle3.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月27日 星期二 20时06分45秒
 ************************************************************************/

#include<iostream>
#include <mutex>
class CSingleton
{
private:
    CSingleton(){}  
    static CSingleton* m_pInstance;
    static std::mutex mtx;
    class GC{
        public: 
        ~GC(){
            if(CSingleton::m_pInstance){
                delete CSingleton::m_pInstance;
            }
        }
    };
    static GC gc;
public:
    static CSingleton *GetInstance(){
        if(m_pInstance == NULL){
            std::lock_guard<std::mutex> lock(mtx);
            if(m_pInstance == NULL){
                m_pInstance = new CSingleton();
            }
        }
        return m_pInstance;
    }
};
CSingleton::GC CSingleton::gc;
CSingleton* CSingleton::m_pInstance = NULL;
std::mutex CSingleton::mtx;
int main(int argc,char *argv[])
{
    CSingleton *p1 = CSingleton::GetInstance();
    CSingleton *p2 = CSingleton::GetInstance();
    std::cout << "p1:"<<p1<<"  "<<"p2:"<<p2<<std::endl;
   return 0;
}
