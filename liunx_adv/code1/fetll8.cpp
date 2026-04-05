/*
    @author: 
    @date: 2026/04/05
    @brief: ./fetll8 7.txt

    r,w(清空文件)模式下，文件指针初始位置为文件开头
    a  模式下，文件指针初始位置为文件末尾
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main(int argc, char const *argv[])
{ 
    FILE *fp ;
    long pos = -1;
    long size = -1;
    if(argc!=2) {
        std::cout << "运行程序请确定好参数(./app filename)" << std::endl;
        exit(-1);
    }
    fp = fopen(argv[1], "a");
    if (fp == nullptr)
    {
        std::cout << "文件打开失败" << std::endl;
        exit(-1);
    }
    pos=ftell(fp);
    size = pos;
    if(pos<0){
        std::cout << "文件指针获取失败" << std::endl;
    }
    std::cout << "文件指针位置为:" << pos << std::endl;
    fclose(fp);
    std::cout << "文件大小为:" << size << std::endl;
    return 0;
}