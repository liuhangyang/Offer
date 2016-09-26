/*************************************************************************
	> File Name: dynamic_cast.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月22日 星期四 07时58分28秒
 ************************************************************************/

#include<iostream>
class Base
{
public:
    int b;
    virtual void Test(){
        std::cout << "base"<<std::endl;
    }
};
class Derived:public Base{
public:
    int d;
    virtual void Test(){
        std::cout <<"Derived"<<std::endl;
    }
};
int main(int argc,char *argv[])
{
    //切割:覆盖方法和子类数据丢失的现象生成切割(slice)
    Derived d;
    Base b = d; //直接赋值(产生切割)
    b.Test();
    std::cout <<"dd"<<std::endl;
    Base& b2 = d; //使用引用赋值(不产生切割)
    b2.Test();

    Base* b3 = &d; //使用指针赋值(不产生切割)
    b3->Test();
    
    //使用dynamic_cast 进行向下强制类型转换. 
    Base *b1 = new Derived;
    Derived *d1 = dynamic_cast<Derived *>(b1);
    if(!d1){
        std::cout << "dynamic_cast err!"<<std::endl;
    }else{
        d1->Test();
    }
   return 1;
}
