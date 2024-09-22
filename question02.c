#include <stdio.h>

int countWaysDP(int n) {
    int dp[n + 1];  // 动态规划数组，dp[i]表示金额为i时的组合数
    dp[0] = 1;      // 金额为0时，只有一种组合方式

    int coins[] = {1, 2, 5};  // 硬币面值

    // 遍历每个硬币
    for (int i = 0; i < 3; i++) {
        // 对每个硬币，更新金额从硬币面值到n的dp值
        for (int j = coins[i]; j <= n; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[n];  // 返回金额为n时的组合数
}

int main() {
    int n;
    printf("请输入总金额: ");
    scanf("%d", &n);

    int result = countWaysDP(n);
    printf("共有不同的组合方式：%d\n", result);

    return 0;
}
