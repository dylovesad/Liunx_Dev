/*
    @author:
    @date: 2026/04/05
    @brief: ./fseek  7.txt

    int fseek(FILE *stream, long offset, int whence);
    stream: 文件指针
    offset: 偏移量（可正可负）
    正值：向后移动
    负值：向前移动
    whence: 起始位置（SEEK_SET、SEEK_CUR、SEEK_END）

*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main(int argc, char const *argv[])
{
    FILE *fp;
    int pos = -1;
    long size = -1;
    if (argc != 2)
    {
        std::cout << "运行程序请确定好参数(./app filename)" << std::endl;
        exit(-1);
    }
    fp = fopen(argv[1], "r");
    if (fp == nullptr)
    {
        std::cout << "文件打开失败" << std::endl;
        exit(-1);
    }
    pos = fseek(fp, 200, SEEK_SET);
    if (pos != 0)
    {
        std::cout << "文件指针移动失败" << std::endl;
        exit(-1);
    }
    else
    {
        std::cout << "文件指针移动成功" << std::endl;
    }
    size = ftell(fp);
    std::cout << "文件指针位置：" << size << std::endl;
    return 0;
}