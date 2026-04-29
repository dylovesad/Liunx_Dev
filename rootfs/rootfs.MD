ROOTFS 是linux操作系统运行所必需的文件


### 系统起始文件 ###
1. 标准根文件系统
直接运行：/sbin/init然后依次执行：
/etc/inittab 配置
执行 /etc/rcS 初始化脚本
启动串口控制台、后台服务等
2. 极简根文件系统（最小 rootfs）
没有 /sbin/init，内核最后会直接拉起 /bin/sh开机直接进命令行 shell。
