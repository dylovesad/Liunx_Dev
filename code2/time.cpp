#include <iostream>
#include <cstring>
#include <ctime>       
#include <unistd.h>
#include <cstdio>      
#include <fcntl.h>

/***标准io实现：每秒写入一次当前时间到文件***/
/*
int main(int argc, char *argv[])
{
    FILE *p1;
    if (argc != 2)
    {
        std::cout << "运行程序请确定好参数(./app filename)" << std::endl;
        return -1;  // 比 _exit(-1) 更规范
    }

    // 打开文件：追加+可读
    p1 = fopen(argv[1], "a+");
    if (p1 == nullptr)
    {
        std::cout << "文件未打开" << std::endl;
        return -1;  // 打开失败必须退出
    }

    // 无限循环：每秒写入一次当前时间
    while(1){
        // 每次循环都获取最新时间（原代码只获取了一次！）
        time_t now = time(nullptr);
        tm* local_time = localtime(&now);
        char buffer[100];
        // 格式化时间字符串
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S\n", local_time);

        // 写入文件
        fwrite(buffer, 1, strlen(buffer), p1);
        //fwrite("\n", 1, 1, p1);
        // 强制刷新缓冲区到磁盘（关键！）
        fflush(p1);

        // 休眠1秒
        sleep(1);
    }

    // 理论上永远走不到这里
    fclose(p1);
    return 0;
}
*/

/***文件io实现：每秒写入一次当前时间到文件***/

int main(int argc, char *argv[])
{
    int p1;
    if (argc != 2)
    {
        std::cout << "运行程序请确定好参数(./app filename)" << std::endl;
        return -1;  // 比 _exit(-1) 更规范
    }

    // 打开文件：追加+可读
    p1 = open(argv[1], O_RDWR|O_CREAT| O_APPEND);
    if (p1 < 0)
    {
        std::cout << "文件未打开" << std::endl;
        _exit(-1);  // 打开失败必须退出
    }

    // 无限循环：每秒写入一次当前时间
    while(1){
        // 每次循环都获取最新时间（原代码只获取了一次！）
        time_t now = time(nullptr);
        tm* local_time = localtime(&now);
        char buffer[100];
        // 格式化时间字符串
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S\n", local_time);

        // 写入文件
        write(STDOUT_FILENO,buffer,strlen(buffer));
        //fwrite("\n", 1, 1, p1);
        // 强制刷新缓冲区到磁盘（关键！）
        //fflush(p1);
        // 休眠1秒 
        sleep(1);
    }

    // 理论上永远走不到这里
    close(p1);
    return 0;
}
