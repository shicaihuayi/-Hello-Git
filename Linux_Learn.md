# Linux 终端环境配置与第三方工具安装指南

## 1. 获取 Linux 终端环境

在本部分，我们将介绍几种获取 Linux 终端环境的方式。

### 1.1 使用虚拟机安装 Linux

你可以通过虚拟化软件（如 VirtualBox 或 VMware）在本地运行 Linux 终端：

1. 下载并安装 VirtualBox 或 VMware。
2. 从 Ubuntu 官网（https://ubuntu.com/download）下载 Ubuntu 系统镜像。
3. 在虚拟机中创建新虚拟机，并选择下载的 ISO 镜像文件进行安装。
4. 安装完成后启动虚拟机，进入 Linux 终端。

### 1.2 使用 WSL (Windows Subsystem for Linux)

如果你使用的是 Windows 10 或 Windows 11，可以启用 WSL，允许你在 Windows 系统上运行 Linux 终端：

1. 打开“启用或关闭 Windows 功能”，启用 **“Windows Subsystem for Linux”**。
2. 通过 Microsoft Store 安装 Ubuntu。
3. 打开终端，输入 `wsl`，进入 Linux 终端。

### 1.3 使用在线 Linux 终端

如果不想在本地安装 Linux，可以使用在线的 Linux 终端：

- [GitPod](https://www.gitpod.io/)
- [Replit](https://replit.com/)
- [JSLinux](https://bellard.org/jslinux/)

### 1.4 使用云服务器

如果你有云服务器（如 AWS、Google Cloud、Azure），可以远程连接到服务器以获取 Linux 终端：

```bash
ssh username@your-server-ip

## 2. 第三方工具安装指南

在本部分，我将安装一些常用的第三方工具和运行程序

### 2.1 Git（版本控制工具）

安装Git
shicaihuayi@Shicaihuayi:~$ sudo apt-get update
sudo apt-get install git
Hit:1 http://security.ubuntu.com/ubuntu jammy-security InRelease
Hit:2 http://archive.ubuntu.com/ubuntu jammy InRelease
Hit:3 http://archive.ubuntu.com/ubuntu jammy-updates InRelease
Hit:4 http://archive.ubuntu.com/ubuntu jammy-backports InRelease
Reading package lists... Done
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
git is already the newest version (1:2.34.1-1ubuntu1.11).
git set to manually installed.
0 upgraded, 0 newly installed, 0 to remove and 2 not upgraded.

检擦 Git 是否安装成功
shicaihuayi@Shicaihuayi:~$ git --version
git version 2.34.1

### 2.2 Python 和 pip（编程语言和包管理工具）

安装 Python3 和 pip3：
指定太多，不展示了。。。

检测检查 Python 和 pip 版本：
shicaihuayi@Shicaihuayi:~$ python3 --version
pip3 --version
Python 3.10.12
pip 22.0.2 from /usr/lib/python3/dist-packages/pip (python 3.10)

安装 Python 库（例如 requests）：
shicaihuayi@Shicaihuayi:~$ pip3 install requests
Defaulting to user installation because normal site-packages is not writeable
Collecting requests
  Downloading requests-2.32.3-py3-none-any.whl (64 kB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 64.9/64.9 KB 790.2 kB/s eta 0:00:00
Collecting idna<4,>=2.5
  Downloading idna-3.10-py3-none-any.whl (70 kB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 70.4/70.4 KB 3.5 MB/s eta 0:00:00
Collecting certifi>=2017.4.17
  Downloading certifi-2024.8.30-py3-none-any.whl (167 kB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 167.3/167.3 KB 2.6 MB/s eta 0:00:00
Collecting urllib3<3,>=1.21.1
  Downloading urllib3-2.2.3-py3-none-any.whl (126 kB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 126.3/126.3 KB 8.5 MB/s eta 0:00:00
Collecting charset-normalizer<4,>=2
  Downloading charset_normalizer-3.3.2-cp310-cp310-manylinux_2_17_x86_64.manylinux2014_x86_64.whl (142 kB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 142.1/142.1 KB 6.4 MB/s eta 0:00:00
Installing collected packages: urllib3, idna, charset-normalizer, certifi, requests
  WARNING: The script normalizer is installed in '/home/shicaihuayi/.local/bin' which is not on PATH.
  Consider adding this directory to PATH or, if you prefer to suppress this warning, use --no-warn-script-location.
Successfully installed certifi-2024.8.30 charset-normalizer-3.3.2 idna-3.10 requests-2.32.3 urllib3-2.2.3

## 3. 运行一些程序

### 3.1  运行 Python 程序

编写 Python 脚本：
使用 Vim 或 Nano 创建一个 hello.py 文件：
  GNU nano 6.2                                            hello.py *
^G

^X





















^G Help        ^O Write Out   ^W Where Is    ^K Cut         ^T Execute     ^C Location    M-U Undo       M-A Set Mark
^X Exit        ^R Read File   ^\ Replace     ^U Paste       ^J Justify     ^/ Go To Line  M-E Redo       M-6 Copy       

编写简单的 Python 脚本：
SyntaxError: invalid syntax
>>> pyhton3
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
NameError: name 'pyhton3' is not defined
>>> print("Hello from Python!")
Hello from Python!

## 4.踩过的坑

错误意味着你在 Bash 终端中输入了不符合 Bash 语法的内容。Bash 是 Linux 终端默认的命令行解释器，它不能直接运行 Python 代码。因此，必须通过 Python 解释器 执行 Python 代码，而不是直接在 Bash 中输入 Python 语法。