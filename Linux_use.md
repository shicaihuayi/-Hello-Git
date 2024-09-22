# 操作步骤
## 1. 启动 Ubuntu 终端
如果你已经安装了 Ubuntu 子系统，你可以通过以下几种方式启动 Ubuntu 终端：

方式 1：在 Windows 搜索栏 中，输入 Ubuntu 并点击打开。
方式 2：打开 PowerShell 或 命令提示符，然后输入：
bash
复制代码
wsl
这将启动你在 WSL 中安装的 Ubuntu 子系统。

## 2. 在 Ubuntu 中创建和运行 Shell 脚本
以下是在 Ubuntu 终端中进行操作的详细步骤：

任务 1：计算数字总和与平均值
2.1 创建文件 numbers.txt
在终端中输入以下命令，使用 nano 文本编辑器创建一个 numbers.txt 文件：

bash
复制代码
nano numbers.txt
在文件中输入一些数字，每行一个数字。例如：

text
复制代码
10
20
30
40
输入完数字后，按 Ctrl + X 退出编辑器，然后按 Y 保存并退出。

2.2 编写 calculate_sum_avg.sh 脚本
在终端中创建一个 calculate_sum_avg.sh 脚本：

bash
复制代码
nano calculate_sum_avg.sh
复制并粘贴以下代码到编辑器中：

bash
复制代码
#!/bin/bash

input_file="numbers.txt"
output_file="result.json"

sum=0
count=0

while read -r line
do
  sum=$(echo "$sum + $line" | bc)
  count=$((count + 1))
done < "$input_file"

if [ "$count" -ne 0 ]; then
  average=$(echo "scale=2; $sum / $count" | bc)
else
  average=0
fi

echo "{" > "$output_file"
echo "  \"sum\": $sum," >> "$output_file"
echo "  \"average\": $average" >> "$output_file"
echo "}" >> "$output_file"

echo "结果已写入到 $output_file"
保存并退出编辑器（按 Ctrl + X，然后按 Y，再按回车）。

2.3 赋予脚本执行权限并运行脚本
赋予脚本可执行权限：

bash
复制代码
chmod +x calculate_sum_avg.sh
运行脚本：

bash
复制代码
./calculate_sum_avg.sh
脚本会读取 numbers.txt 中的数字，并生成 result.json 文件。你可以通过以下命令查看生成的 JSON 文件：

bash
复制代码
cat result.json

## 3踩过的坑
bc 工具未正确安装
脚本使用 bc 进行计算，如果 bc 工具未安装或者无法使用，可能会导致计算失败，返回 0。

解决方案：
检查 bc 是否安装：
运行以下命令查看 bc 是否可用：
bash
复制代码
which bc
如果 bc 未安装，可以通过以下命令安装：
bash
复制代码
sudo apt-get install bc
检查步骤
检查 numbers.txt 文件内容：

确保文件中有数字，每行一个数字，无其他空行或非数字字符。
检查文件路径：

确保文件与脚本位于同一目录，或者使用文件的绝对路径。
检查 bc 工具：

确保 bc 已正确安装并可以运行。