#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

int main(int argc,char const *argv[]){
    FILE *fp ;
    std::vector<char> file(1,0);
    int i = 0;
    for(;;)
    {
        sprintf(&file.front(),"%d",i) ;  
        std::cout << &file.front() << std::endl;

        fopen(&file.front(),"w") ;
        if(fp==NULL) {
            std::cout << "文件打开失败" << std::endl;
            exit(-1);
        }else {
            ++i;
            std::cout << "文件打开成功a" << std::endl;
        }
    }
        return 0;
}