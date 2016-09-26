/*************************************************************************
	> File Name: strTonum.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月19日 星期一 07时00分06秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<limits>
bool strToInt(const char *str,int &nInt){
    if(str == NULL){
        std::cout <<"空指针"<<std::endl;
        return  false;
    }else if(str == ""){
        std::cout << "空串"<<std::endl;
        return false;
    }else if((strcmp(str,"+") == 0) || (strcmp(str,"-") == 0)){
        std::cout << "字符串输入无效"<<std::endl;
        return false;
    }else{
        const char *p = str;
        bool isFirst = true; //标记是否为字符串的第一个字符
        bool hasMinus = false; //标记字符串的第一个字符是否是负号.
        nInt = 0;
        while(*p != '\0'){
            if(isFirst && (*p) == '-' ){
                hasMinus = true;
                p++;
                continue;
            }else if(isFirst && (*p) == '+'){
                p++;
                continue;
            }
            if((*p) >= '0' && (*p) <= '9'){
                nInt = nInt*10+*p-'0';
                if((!hasMinus && nInt > std::numeric_limits<int>::max()) || (hasMinus && nInt < std::numeric_limits<int>::min())){
                    std::cout << "字符串数值溢出,输入无效!"<<std::endl;
                    return false;
                }
                    p++;
                }else{
                    std::cout << "字符串中包含有非数字的字符,不能转换为数字"<<std::endl;
                    return false;
                }
        }
                    if(hasMinus){
                        nInt = (-1) * nInt;
                    }
                    return true;
    }
}
int main(int argc,char *argv[])
{
    /*int nTest1 = 1000000000000000;
    int nTest2 = -1000000000000000;
    if(nTest1 > 0x7FFFFFFF){
        std::cout << "上溢"<<std::endl;
    }
    if(nTest2 < (signed int)0x80000000){
        std::cout << "下溢"<<std::endl;
    } */
    int nInt = 0;
    char *str = NULL;
    if(strToInt("123",nInt)){
        std::cout << nInt<<std::endl;
    }
    if(strToInt("",nInt)){
        std::cout <<nInt<<std::endl;
    }
    if(strToInt(str,nInt)){
        std::cout <<nInt<<std::endl;
    }
    if(strToInt("-123",nInt)){
        std::cout <<nInt<<std::endl;
    }
    if(strToInt("+123",nInt)){
        std::cout <<nInt<<std::endl;
    }
    if(strToInt("-#45466@",nInt)){
        std::cout <<nInt<<std::endl;
    }
    if(strToInt("10000000000000000000000000",nInt)){
        std::cout <<nInt<<std::endl;
    }
    if(strToInt("-10000000000000000000000000",nInt)){
        std::cout <<nInt<<std::endl;
    }
   return 0;
}
