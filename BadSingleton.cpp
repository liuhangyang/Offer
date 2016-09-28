/*************************************************************************
	> File Name: BadSingleton.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月27日 星期二 16时59分21秒
 ************************************************************************/

#include<iostream>
class CSingleton
{
private:
    CSingleton(){  //构造函数是私有的.

    }
    // CSingleton(const CSingleton &);
   // CSingleton &operator=(const CSingleton &);
public:
    static CSingleton* GetInstance(){
        
        static CSingleton instance; 
        return instance;
    }
};
int main(int argc,char *argv[])
{
  //  CSingleton singleton = CSingleton::GetInstance();
    
   return 0;
}
