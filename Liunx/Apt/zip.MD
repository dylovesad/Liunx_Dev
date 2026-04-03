格式	            打包 / 压缩命令	                        解压命令	                  说明
.tar	        tar -cvf  包名.tar     ->目录/文件	   tar -xvf   ->包名.tar	    只打包，不压缩
.tar.gz / .tgz	tar -zcvf 包名.tar.gz  ->目录/文件	   tar -zxvf  ->包名.tar.gz	 通用，速度快
.tar.bz2	    tar -jcvf 包名.tar.bz2 ->目录/文件	   tar -jxvf  ->包名.tar.bz2	压缩率更高
.tar.xz	        tar -Jcvf 包名.tar.xz  ->目录/文件	   tar -Jxvf  ->包名.tar.xz	 压缩率最高
.zip	        zip -r 包名.zip        ->目录/文件	   unzip      ->包名.zip	    Windows 通用
.rar	          rar a 包名.rar         ->目录/文件	   unrar x    ->包名.rar	    需安装 rar
