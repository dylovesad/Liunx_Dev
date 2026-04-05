/*
    @author: 
    @date: 2026/04/05
    @brief: ./fseek2  7.txt 8.txt 9.txt
    从中间拆分两个文件
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main(int argc, char const *argv[])
{ 
    FILE *fp1, *fp2 ,*fp3;
    long pos = -1;
    if(argc!=4) {
        std::cout << "运行程序请确定好参数(./app filename)" << std::endl;
        exit(-1);
    }
    fp1 = fopen(argv[1], "r");
    if (fp1 == nullptr)
    {
        std::cout << "文件打开失败" << std::endl;
        exit(-1);
    }

    fp2 = fopen(argv[2], "w");
    if (fp2 == nullptr)
    {
        std::cout << "文件打开失败" << std::endl;
        exit(-1);
    }

    fp3 = fopen(argv[3], "w");
    if (fp3 == nullptr)
    {
        std::cout << "文件打开失败" << std::endl;
        exit(-1);
    }


    fseek(fp1, 0, SEEK_END);
    pos = ftell(fp1);
    std::cout << "文件指针位置：" <<pos << std::endl;
    fseek(fp1, 0, SEEK_SET);
    
    for(long i = 0; i < pos/2; i++){
        fputc(fgetc(fp1), fp2);
    }

    for(long i = pos/2; i < pos; i++){
        fputc(fgetc(fp1), fp3);
    }

    return 0;


}