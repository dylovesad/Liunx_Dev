/*
    @author: <github.com/mik3y>
    @date: 2021-07-05
    @description: open.cpp
    @note:2. 
     常用 flags (打开模式)
    这些标志可以通过位或运算符 | 组合使用：

        标志	说明
    O_RDONLY	只读方式打开
    O_WRONLY	只写方式打开
    O_RDWR	    读写方式打开
    O_CREAT	    如果文件不存在则创建
    O_EXCL	    与 O_CREAT 连用，如果文件已存在则报错（确保原子性创建）
    O_TRUNC	    如果文件存在且为写入模式，则清空文件内容
    O_APPEND	追加模式，每次写入都从文件末尾开始
    O_NONBLOCK	非阻塞模式打开

    3. mode (文件权限)
    当使用 O_CREAT 时，必须指定第三个参数 mode。通常使用八进制数或宏定义：

    宏定义	八进制	含义
    S_IRUSR	0400	文件所有者可读
    S_IWUSR	0200	文件所有者可写
    S_IXUSR	0100	文件所有者可执行
    S_IRGRP	0040	同组用户可读
    S_IROTH	0004	其他用户可读


*/

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>

#define BUF_SIZE 1024
int main(int argc, char *argv[])
{
    char buf[BUF_SIZE]={0};
    int fd = open("open.txt",  O_RDWR |O_CREAT|O_APPEND,0644);
    if (fd == -1) {
        perror("open failed");
        exit(-1);
    }
    const char *msg = argv[1];
    write(fd, msg, strlen(msg));
    write(fd, "\n", 1);
    lseek(fd, 0, SEEK_SET);

    while (int a =read(fd, buf, BUF_SIZE) > 0)
    {
        std::cout << buf << std::endl;
        memset(buf, 0,sizeof(buf));
    }
    
    close(fd);
    std::cout << "文件写入成功" << std::endl;
    return 0;
}