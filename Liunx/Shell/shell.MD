# 变量	含义
# $0	当前脚本本身的文件名
# $1	第 1 个传递给脚本的参数
# $2	第 2 个传递给脚本的参数
# $3	第 3 个传递给脚本的参数
# ...	以此类推（最多$9，超过用${10}）
# $#	传递给脚本的参数总个数
# $@	所有传递的参数（推荐用）


#! /bin/bash
echo -n "please input filename >:"

read filename
echo "filename=$filename"

if ! test -e $filename          #文件不存在则报错
then
echo "file not existed"
exit 1
fi

if test -b $filename            #块设备文件
then
        echo "block"
elif test -c $filename          #字符设备文件
then
echo "character"
elif test -d $filename          #目录
then
echo "directory 文件夹"
elif test -h $filename          #符号链接
then
echo "link"
elif test -f $filename          #普通文件
then
echo "regular"
fi
             
