/*************************************************************************
	> File Name: CMyString.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月26日 星期一 07时24分33秒
 ************************************************************************/

#include<iostream>
#include<string.h>
class CMyString{
public:
    CMyString(char * pData){
        m_pData = new char[1024];
        strcpy(m_pData,pData);
    }
    CMyString(const CMyString& str); //拷贝构造函数
    CMyString& operator=(const CMyString& str);
    ~CMyString(void){
        std::cout << "调用析构函数"<<std::endl;
        delete[] m_pData;
    }
    char* m_pData;
};
CMyString::CMyString(const CMyString& str){
    std::cout << "yang"<<std::endl;
    m_pData = new char[strlen(str.m_pData)+1];
    strcpy(m_pData,str.m_pData);
}
CMyString& CMyString::operator=(const CMyString& str){
  /*问题1.如果new char分配失败时，m_pData将是一个空指针,这将非常危险. 
   *解决方法:1.先new char 在执行delete .
   *2.申请一个临时对象strTemp.m_pData和实例自身的m_pData做交换，由于strTemp是一个临时变量,出作用域后，自动调用strTemp的析构函数. 
   */
  /*if(this == &str){
        return *this;
    }
    std::cout << "我是赋值运算符"<<std::endl;
    delete []m_pData;
    m_pData = NULL;
    m_pData = new char[strlen(str.m_pData)+1];
    strcpy(m_pData,str.m_pData);
    return *this;*/
    if(this != &str){
    std::cout << "我是赋值运算符"<<std::endl;
        CMyString strTemp(str);
        char *temp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = temp;
    }
    return *this;
}
int main(int argc,char *argv[])
{
    char buf[]="yanglongfei";
    CMyString a(buf);
    //a.m_pData = new char[10];
    //a.m_pData
    //CMyString b(a);
    CMyString b("sss");
    CMyString c("sss");
    c=b=a;
    std::cout << b.m_pData<<std::endl;

   return 0;
}
