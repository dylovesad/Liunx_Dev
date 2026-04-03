1.apt install 安装软件

sudo apt install <软件名称>
sudo apt -f install#修复系统的软件安装错误
#例如
sudo apt install sl#小火车安装软件，可以使用LS去执行这个可执行程序
sudo apt instal1 snake4 #贪吃蛇游戏，可以使用snake4启动程序

2.apt remove卸载软件

sudo apt remove<软件名称>
sudo apt autoremove # 自动卸载系统不再需要的软件包
#例如
#卸载火车软件sudo apt remove sl
sudo apt remove snake4#卸载贪吃蛇游戏

7.apt update 更新软件目录
从服务器更新软件信息到本地，保持本地的软件信息和服务器一致。
#更软软件源信息sudo apt update
sudo apt list --upgradable#查看可升级的软件信息
