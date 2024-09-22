#include <stdio.h>

// 逆推计算原本的桃子数量
int calculate_initial_peaches(int n, int m) {
    int peaches = m;  // 最后一只猴子看到的桃子数为 m
    for (int i = n; i > 1; i--) {
        // 逆推：第 i-1 只猴子看到的桃子数
        peaches = 2 * (peaches + 1);
    }
    return peaches;
}

int main() {
    int n, m;

    // 输入第 n 只猴子，以及它发现的桃子数 m
    printf("请输入第几只猴子 n: ");
    scanf("%d", &n);
    printf("请输入第 %d 只猴子发现的桃子数 m: ", n);
    scanf("%d", &m);

    // 计算原本的桃子数量
    int initial_peaches = calculate_initial_peaches(n, m);

    // 输出结果
    printf("原本的桃子数量为: %d\n", initial_peaches);

    return 0;
}
