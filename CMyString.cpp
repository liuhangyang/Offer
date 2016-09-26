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
