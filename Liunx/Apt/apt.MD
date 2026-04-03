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

3.apt pplicy查看软件安装状态
#policy策略，
sudo apt policy<软件名称>
sudo apt policy gcc
#检查gcc 的安装状态
sudo apt policy sl
#检查s1软件安装状态
sudo apt policy snake4#检查snake4 软件安装状态

4.aptlist软件清单
sudo apt 1ist #列出系统所的软件包清单
sudo apt list <软件名称>#列出这个软甲的清单
sudo aptlist<软件名称> -a #列出这个软件的所有版本清单
#例如
sudo apt list gcc
sudo apt list gcc -a
sudo apt list sl -a
sudo apt list snake4

5.apt prge卸载软件和配置文件
sudo apt purge <软件名称>
sudo apt purge snake4# 卸载软件和清除配置文件

6.apt search搜索软件包
在可以用的软件包中搜索制定的包，如果找到，该命令将返回名称与搜索词匹配的包。
sudo apt search <软件包名称>
#例如
sudo apt search snake4

7.apt update 更新软件目录
从服务器更新软件信息到本地，保持本地的软件信息和服务器一致。
#更软软件源信息sudo apt update
sudo apt list --upgradable#查看可升级的软件信息
