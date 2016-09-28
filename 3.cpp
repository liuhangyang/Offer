/*************************************************************************
	> File Name: 3.cpp
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年09月29日 星期四 07时01分10秒
 ************************************************************************/

#include<iostream>
/*算法思想:1.从右上角开始找,如果右上角的数大于所找的数,则--column,如果等于,则返回true,如果小于,row++;
 */
using namespace std;
bool FindNum(int (*array)[4],int rows,int columns,int number)
{
    bool found = false;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            std::cout << array[i][j]<<std::endl;
        }
    }
    if(array !=NULL && rows > 0 && columns > 0){
        int row =0;
        int column=columns-1;
        while(row < rows && column >= 0){
            if(array[row][column] == number){
                found = true;
                break;
            }else if(array[row][column] > number){
                    --column;
            }else{
                    ++row;
                }
            }
    }
    return found;
}
int main(int argc,char *argv[])
{
    int array[4][4]={
        1,2,8,9,
        2,4,9,12,
        4,7,10,13,
        6,8,11,15
    };
    bool found = FindNum(array,4,4,7);
    std::cout << "found:"<<found<<std::endl;
   return 0;
}
