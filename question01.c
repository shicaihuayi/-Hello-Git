#include <stdio.h>
#include <string.h>

// 删除字符串中第 i 个字符
void remove_char(char *str, int i) {
    int len = strlen(str);
    for (int j = i; j < len - 1; j++) {
        str[j] = str[j + 1];
    }
    str[len - 1] = '\0';
}

// 简化分数函数
void simplify_fraction(char *numerator, char *denominator) {
    int i, j;
    
    // 遍历分子中的每一个字符
    for (i = 0; i < strlen(numerator); i++) {
        for (j = 0; j < strlen(denominator); j++) {
            // 如果发现相同的字符，就将它从分子和分母中删除
            if (numerator[i] == denominator[j]) {
                remove_char(numerator, i);
                remove_char(denominator, j);
                i--;  // 删除字符后，i 需要回退，以检查新的字符
                break;
            }
        }
    }
    
    // 打印结果
    if (strlen(numerator) == 0) {
        printf("1 / %s\n", denominator);
    } else if (strlen(denominator) == 0) {
        printf("%s / 1\n", numerator);
    } else {
        printf("%s / %s\n", numerator, denominator);
    }
}

int main() {
    // 定义分子和分母
    char numerator[20] = "1428571";
    char denominator[20] = "2857142";

    // 简化分数
    simplify_fraction(numerator, denominator);

    return 0;
}
