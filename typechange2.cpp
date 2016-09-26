/*************************************************************************
	> File Name: typechange2.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月21日 星期三 20时59分04秒
 ************************************************************************/

#include<iostream>
#include<vector>
struct B{};
struct D:B{};
enum class E{ONE,TWO,THREE};
enum EU{ONE,TWO,THREE};
int main(int argc,char *argv[])
{
    //1.initalizing conversion
    int n = static_cast<int>(3.14);
    std::cout << "n= "<<n<<std::endl;
    std::vector<int> v=static_cast<std::vector<int>>(10);
    std::cout << "v.size() = "<<v.size()<<std::endl;
    //2.static downcast
    D d;
    B& br = d; //upcast via implicit conversion 
    D& another_d=static_cast<D&>(br);  //downcast 
    //3.lvalue to xvalue 
    std::vector<int> v2 = static_cast<std::vector<int>&&>(v);
    std::cout << "after move,v.size() = "<<v.size() << std::endl;
    //4.discarded-value expression 
    static_cast<void>(v2.size());
    //5.inverse of implicit conversion 
    void* nv = &n;
    int* ni = static_cast<int *>(nv);
    std::cout <<"*n1 "<<*ni<<std::endl;
    //6.array-to-pointer followed by upcast;
    D a[10];
    B* dp = static_cast<B*>(a);
    //7.scoped enum enum to another enum;
    E e = E::ONE;
    int one = static_cast<int>(e);

    E e2 = static_cast<E>(one);
    EU eu = static_cast<EU>(e2);
    //9.pointer to member upcast
    //todo 
    //10.void* to any type;  
    void* voidp = &e;
    std::vector<int>* p = static_cast<std::vector<int>*>(voidp);

    return 0;
}
