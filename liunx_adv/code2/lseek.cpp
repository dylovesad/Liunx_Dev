/*
    @author: <github.com/mik3y>
    @date: 2026-04-05
    @description: lseek.cpp
    @note:

        off_t lseek(int fd, off_t offset, int whence);
        whence 参数的三个宏
        宏定义	含义	说明
        SEEK_SET	文件开头	偏移量 offset 必须 >= 0
        SEEK_CUR	当前位置	offset 可正（向后）可负（向前）
        SEEK_END	文件末尾	offset 通常为负值（向前移）



*/

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>

#define BUF_SIZE 1024
int main(int argc, char *argv[])
{
    if(argc != 2){
        std::cout << "请输入正确文本" << std::endl;
        exit(-1);
    }
    return 0;
}