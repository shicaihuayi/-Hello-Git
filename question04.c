#include <stdio.h>

int main() {
    int x, y;
    
    // 输入两个两位数
    printf("请输入第一个两位数: ");
    scanf("%d", &x);

    printf("请输入第二个两位数: ");
    scanf("%d", &y);

    // 检查输入是否为两位数
    if ((x >= 10 && x <= 99) && (y >= 10 && y <= 99)) {
        // 计算乘积
        int result = x * y;
        printf("%d 和 %d 的乘积是: %d\n", x, y, result);
    } else {
        printf("输入的数字不是两位数，请输入10到99之间的数字。\n");
    }

    return 0;
}
