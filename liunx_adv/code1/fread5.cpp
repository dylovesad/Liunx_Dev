/*
    @author: 
    @date: 2026/04/05
    @brief: 测试fread函数   ./fread5 4.txt
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>

#define SIZE 128
int main(int argc,char const *argv[]){
    FILE *fp ;
    char buffer[SIZE] ={0};
    if(argc!=2) {
        std::cout << "运行程序请确定好参数(./app filename)" << std::endl;
        exit(-1);
    }
    
    fp = fopen(argv[1],"r") ;  
    if(fp==nullptr) {
        std::cout << "文件打开失败" << std::endl;
        exit(-1);
    }else {
        std::cout << "文件打开成功" << std::endl;
    }
    
    while (fread(buffer,1,SIZE,fp) > 0)
    {
       std::cout << buffer << std::endl;
       memset(buffer,0,SIZE);
    }
    fclose(fp);
    return 0;

}