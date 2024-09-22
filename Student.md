# 创建三个文件：一个是实际报名的 9999 名学生名单（文件 1），另一个是报名时记录的 10000 名学生名单（文件 2），每行一个名字

## 做法步骤1
创建 actual_students.txt 文件：

这个文件包含实际报名的 9999 名学生，每行一个学生的名字。
示例内容：

text
复制代码
张三
李四
王五
...
创建 registered_students.txt 文件：

这个文件包含报名时记录的 10000 名学生，每行一个学生的名字。
示例内容：

text
复制代码
张三
李四
王五
赵六
...

创建 name.txt 文件：，找到需要领取奖品的学生

示例内容：

text
复制代码
张三
李四
...

可以在 Ubuntu 终端中使用 nano 编辑器创建这些文件，也可以使用喜欢的文本编辑器提前在 Windows 中创建好，再将其放入 Ubuntu 文件系统。

使用 nano 创建文件的步骤：
创建 actual_students.txt 文件：

bash
复制代码
nano actual_students.txt
然后在编辑器中输入每行一个学生名字。

创建 registered_students.txt 文件：

bash
复制代码
nano registered_students.txt
同样，在编辑器中输入 10000 名学生，每行一个名字。

创建 name.txt 文件：

bash
复制代码
nano name.txt

输入完成后，按 Ctrl + X 退出编辑器，按 Y 保存文件。

## 做法步骤二
在终端中创建一个 process_students.sh 脚本：

bash
复制代码
nano process_students.sh

### 具体代码实现：

#!/bin/bash

# 步骤1：定义输入和输出文件路径
actual_file="actual_students.txt"
registered_file="registered_students.txt"
name_file="name.txt"

# 创建照片存放目录
pics_dir="pics"
winners_dir="winners_pic"

# 如果目录不存在，则创建
mkdir -p $pics_dir
mkdir -p $winners_dir

# 步骤2：从 10000 名报名学生中随机抽取 1000 名
# 使用 shuf 随机打乱 registered_file 并抽取前 1000 名
shuf -n 1000 $registered_file > selected_students.txt

# 计数变量，用于给每个照片命名
count=1

# 步骤3：为抽中的每个学生生成一张照片，命名为“名字+编号”
while read -r student; do
  touch "$pics_dir/${student}${count}.jpg"  # 生成模拟照片文件
  count=$((count + 1))
done < selected_students.txt

echo "照片已生成到 $pics_dir 目录中。"

# 步骤4：读取 name.txt 中中奖的学生，并将对应照片拷贝到 winners_pic 文件夹
while read -r winner; do
  # 找到以中奖学生名字开头的照片并复制到 winners_pic 目录
  find $pics_dir -name "${winner}*.jpg" -exec cp {} $winners_dir \;
done < $name_file

echo "中奖照片已拷贝到 $winners_dir 目录中。"

### 运行步骤：

将上述脚本保存为 process_students.sh 文件。

给予脚本执行权限：

bash
复制代码
chmod +x process_students.sh
运行脚本：

bash
复制代码
./process_students.sh
脚本运行后，将在 pics 文件夹中生成模拟的照片文件，在 winners_pic 文件夹中放置中奖学生的照片。

### 将成果推送到GitHub

