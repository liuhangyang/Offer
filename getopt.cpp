/*************************************************************************
	> File Name: getopt.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月22日 星期四 14时59分40秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<iostream>
int main(int argc,char *argv[])
{
    int ch;
    opterr = 0;
    while((ch = getopt(argc,argv,"a:bcde"))!=-1){
        switch(ch){
            case 'a':printf("option a:%s\n",optarg);
            break;
            case 'b':printf("option b:b\n");
            break;
            default:
            printf("other option:%c\n",ch);
        }
        printf("optopt +%c\n",optopt);
    }
   return 0;
}
