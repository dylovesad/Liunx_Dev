/*
    @author: 
    @date: 2026/04/05
    @brief: ./fwrite7 fwrite7.cpp 7.txt
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

#define SIZE 256
int main(int argc, char const *argv[])
{
    FILE *fp1, *fp2;
    char buffer [SIZE]={0};
    if (argc != 3)
    {
        std::cout << "运行程序请确定好参数(./app filename)" << std::endl;
        exit(-1);
    }

    fp1 = fopen(argv[1], "r");
    if (fp1 == nullptr)
    {
        std::cout << "文件1打开失败" << std::endl;
        exit(-1);
    }
    fp2 = fopen(argv[2], "w+");
    if (fp2 == nullptr)
    {
        std::cout << "文件2打开失败" << std::endl;
        exit(-1);
    }
    while (fread(buffer,1,SIZE,fp1) > 0)
    {
        fwrite(buffer,1,SIZE,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    std::cout << "文件复制成功" << std::endl;
    return 0;
}


