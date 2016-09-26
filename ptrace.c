/*************************************************************************
	> File Name: ptrace.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月22日 星期四 20时06分38秒
 ************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.hmZ.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/ptrace.h>
#include <sys/reg.h>
int main(int argc,char *argv[])
{
    pid_t child;
    long orig_eax;
    child = fork();
    if(child == 0){
        ptrace(PTRACE_TRACEME,0,NULL,NULL);
        execl("/bin/ls","ls",NULL);
    }else{
        wait(NULL);
        orig_eax=ptrace(PTRACE_PEEKUSER,child,4*0x24,NULL);
        printf("The child made a system call %ld\n",orig_eax);
        ptrace(PTRACE_CONT,child,NULL,NULL);
    }
   return 0;
}
