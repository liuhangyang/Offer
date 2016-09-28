/*************************************************************************
	> File Name: lock.h
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月27日 星期二 17时19分37秒
 ************************************************************************/

#ifndef _LOCK_H
#define _LOCK_H
#include <mutex>
class Lock
{
private:
    CCriticalSection m_cs;
public:
    Lock(CCriticalSection cs):m_cs(cs){
        m_cs.Lock();
    }
    ~Lock(){
        m_cs.Unlock();
    }
};
#endif
