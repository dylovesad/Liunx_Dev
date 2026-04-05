/*
    @author  DJH
    @date   20206.4.5
    @brief  Cache(全缓存)
    @note 全缓存强刷新
    int fflush(FILE *stream); //强制刷新
*/
#include<iostream>
#include<cstring>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    FILE *fp ;
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
    fp = fopen(argv[1],"a+") ;  
    if(fp==nullptr) {
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
        ret = fwrite(buf,1,10,stdout);
        if(ret<0) exit(-1);
        usleep(1000*100);
    }

    return 0;
}
