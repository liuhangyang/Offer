/*************************************************************************
	> File Name: CMyString.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月26日 星期一 07时24分33秒
 ************************************************************************/

#include<iostream>
#include<string.h>
/*定义一个赋值运算符的时候,应该注意的点:
 *1.是否把返回值声明为该类型的引用,并在函数结束前返回实例自身的引用,只有返回一个引用,才可以允许连续赋值,假设有3个CMyString的对象:str1,str2,str3，在程序中语句str1=str2=str3将不能通过编译. 
 *2.把传入的参数的类型应该申明为常量的引用,如果传入的参数不是引用而是实例,那么从形参到实例将会调用一次赋值构造函数,把参数申明为引用类型可以避免这样的无谓消耗,能提高代码的效率,同时,我们在赋值运算符函数内不会改变传入实例的状态,因此应该为传入的引用参数加上const关键字.  
 *3.是否释放实例自身已有的内存,如果我们忘记在分配新内存之前释放自身已有的空间,程序将出现内存泄露. 
 *4.是否判断传入的参数和当前的实例(*this)是不是同一个实例,如果是同一个,则不进行赋值惭怍,直接返回,如果事先不进行判断就进行赋值,那么在释放实例自身内存时就会释放传入参数的内存,因此就再也找不到要赋值的内容了.  
 *
 */
class CMyString{
public:
    CMyString(char * pData = NULL){
        m_pData = new char(strlen(pData)+1);
        strcpy(m_pData,pData);
    }
    CMyString(const CMyString& str); //拷贝构造函数
    CMyString& operator=(const CMyString& str);
    ~CMyString(void){
        delete[] m_pData;
    }
private:
    char* m_pData;
};
CMyString::CMyString(const CMyString& str){
    std::cout << "yang"<<std::endl;
    m_pData = new char[strlen(str.m_pData)+1];
    strcpy(m_pData,str.m_pData);
}
CMyString& CMyString::operator=(const CMyString& str){
    if(this == &str){
        return *this;
    }

    delete []m_pData;
    m_pData = NULL;
    m_pData = new char[strlen(str.m_pData)+1];
    strcpy(m_pData,str.m_pData);
    return *this;
}
int main(int argc,char *argv[])
{
    char buf[]="yanglongfei";
    CMyString a(buf);
    //a.m_pData = new char[10];
    //a.m_pData
    CMyString b(a);
    
    
   return 0;
}
