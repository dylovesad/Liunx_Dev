/*
    @author  DJH
    @date   20206.4.5
    @brief  Cache(非缓存)
    @note 
*/
#include<iostream>
#include<cstring>
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fp;
    if(argc!=2) {
        std::cout << "运行程序请确定好参数(./app filename)" << std::endl;
        exit(-1);
    }
    //fp = fopen(argv[1],"r") ;//只读方式打开文件，文件不存在报错。
    //fp = fopen(argv[1],"r+") ;//可读可写方式打开文件，文件不存在报错。
    //fp = fopen(argv[1],"w") ;//只写方式打开文件，文件不存在会自动创建文件，文件存在清空文件内容
    //fp = fopen(argv[1],"w+") ;//可读可写方式打开文件，文件不存在会自动创建文件，文件存在清空文件内容
    //fp = fopen(argv[1],"a") ; //只写方式打开文件，文件不存在会自动创建文件，文件存在则在文件末尾追加内容
    //fp = fopen(argv[1],"a+") ; // 可读可写方式打开文件，文件不存在会自动创建文件，文件存在则在文件末尾追加内
    fp = open(argv[1], O_RDWR	| O_CREAT) ;  
    if(fp < 0) {
        std::cout << "文件打开失败" << std::endl;
        exit(-1);
    }else {
        std::cout << "文件打开成功" << std::endl;
    }
    int i= 0,ret;
    char buf[1024] = {0};
    while(1) {
         ++i;
        sprintf(buf,"i=%08d\n",i);
        write(fp,buf,10);
        write(fp,"\n",1);
        if(ret<0) exit(-1);
        usleep(1000*1000);
    }

    return 0;
}
