/*
    @author: 
    @date: 2026/04/05
    @brief: ./fseek3  7.txt 
    文件逆序
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main(int argc, char const *argv[])
{ 
    FILE *fp1;
    long size = -1;
    char ch1,ch2; 
    if(argc!=2) {
        std::cout << "运行程序请确定好参数(./app filename)" << std::endl;
        exit(-1);
    }
    fp1 = fopen(argv[1], "r+");
    if (fp1 == nullptr)
    {
        std::cout << "文件打开失败" << std::endl;
        exit(-1);
    }
    fseek(fp1, 0, SEEK_END);
    size = ftell(fp1);
    fseek(fp1, 0, SEEK_SET);

    for (long i = 0; i < size/2; i++)
    {
            fseek(fp1, i, SEEK_SET);
            ch1 = fgetc(fp1);

            fseek(fp1, -i, SEEK_END);
            ch2 = fgetc(fp1);

            fseek(fp1, i, SEEK_SET);
            fputc(ch2, fp1);

            fseek(fp1, -i, SEEK_END);
            fputc(ch1, fp1);
    }
    
    
    return 0;
}