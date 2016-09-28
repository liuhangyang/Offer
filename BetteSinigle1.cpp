/*************************************************************************
	> File Name: BetteSinigle1.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月27日 星期二 19时56分04秒
 ************************************************************************/

#include <iostream>
#include <mutex>
#include<stdio.h>
class SingleInside
{
private:
    SingleInside(){}
public:
    static SingleInside& GetInstance(){
        static SingleInside instance;
        return instance;
    }
};
int main(int argc,char *argv[])
{
    SingleInside single = SingleInside::GetInstance();
    SingleInside Single1 = SingleInside::GetInstance();
   printf("single:%p\nsingle1:%p\n",single,Single1);
    return 0;
}
