/*************************************************************************
	> File Name: const_cast.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月22日 星期四 06时54分19秒
 ************************************************************************/

#include<iostream>
struct type{
    type():i(3){}
    void m1(int v) const{
        //this->i = v;
        /**因为函数是const的,所以type::i是可读的,但是const_cast去掉了调用此函数对象的const属性. 
         * 
         */
        const_cast<type*>(this)->i = v;
    }
    int i;
};
int main(int argc,char *argv[])
{
    int i = 3;
    const int& cref_i = i;
    const_cast<int&>(cref_i) = 4; //去掉了cref_i的const属性.
    //cref_i=4; 错误,引用cref_i是只读的
    std::cout << "i = "<<i<<std::endl;
    
    type t;
    t.m1(4);
    std::cout << "type::i = "<<t.i << std::endl;
    const int j = 3;
    int *pj = const_cast<int *>(&j);
    *pj = 4;
   return 0;
}
