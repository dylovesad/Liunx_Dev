# ==================== Linux 用户管理命令全集（合并为一个 Bash 脚本） ====================

# ========== 1. 用户创建 ==========
useradd testuser                # 基础创建
useradd -m testuser             # 创建并自动创建家目录
useradd -m -s /bin/bash testuser # 创建并指定 bash 为登录 shell
useradd -u 1005 testuser        # 指定 UID 创建
useradd -g group1 testuser      # 指定主组
useradd -G group2 testuser      # 指定附加组

# ========== 2. 密码管理 ==========
passwd testuser                 # 设置密码
passwd -d testuser              # 清空密码
passwd -l testuser              # 锁定用户
passwd -u testuser              # 解锁用户

# ========== 3. 修改用户信息 ==========
usermod -l newuser testuser     # 修改用户名
usermod -d /home/newhome newuser # 修改家目录
usermod -s /bin/bash newuser    # 修改登录 shell
usermod -g newgroup newuser     # 修改主组
usermod -G group3 newuser       # 覆盖附加组
usermod -aG group4 newuser      # 追加附加组（不覆盖）
usermod -u 1006 newuser         # 修改 UID

# ========== 4. 删除用户 ==========
userdel newuser                 # 删除用户，保留家目录
userdel -r newuser              # 删除用户 + 家目录 + 邮箱

# ========== 5. 用户组管理 ==========
groupadd group1                 # 创建组
groupadd -g 1005 group2         # 指定 GID 创建组
groupmod -n newgroup group2      # 修改组名
groupmod -g 1006 newgroup       # 修改 GID
groupdel newgroup               # 删除组
gpasswd -a testuser group1      # 添加用户到组
gpasswd -d testuser group1      # 从组删除用户
gpasswd -M user1,user2 group1    # 设置组内成员

# ========== 6. 查看信息 ==========
id testuser                     # 查看 UID/GID/组
whoami                          # 当前用户
w                               # 在线用户
users                           # 登录用户列表
last                            # 登录历史
groups testuser                 # 用户所属组
cat /etc/passwd                 # 所有用户
cat /etc/group                  # 所有组
cat /etc/shadow                 # 密码加密信息
cat /etc/shells                 # 可用 shell

# ========== 7. 切换与权限 ==========
su testuser                     # 切换用户
su - testuser                   # 完全切换环境
sudo command                    # 提权执行
visudo                          # 编辑 sudo 权限

# ========== 8. 密码策略 ==========
chage -l testuser               # 查看密码过期信息
chage -M 99999 testuser         # 密码永不过期
pwck                            # 检查用户配置
grpck                           # 检查组配置

# ==================== 结束 ====================
