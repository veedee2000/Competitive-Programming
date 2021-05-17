//Intuition:

//Put 1 (the smallest possible stick) at the first position, so it could be always visible. There are dp[n - 1][k - 1] such rearrangements. It's the number of rearrangements of greater sticks to the right, so that k - 1 of them are visible.
//Now inject this 1 to greater sticks rearrangements. That 1 will never be visible, as any of them will hide 1. There are dp[n - 1][k] rearrangements of greater sticks. And we can place 1 after any of n - 1 sticks in each rearrangement.

class Solution {
    int MOD = 1000000007;

public:
    int rearrangeSticks(int N, int K) {
        std::vector<std::vector<int64_t>> dp(N + 1, std::vector<int64_t>(N + 1, 0));
        dp[1][1] = 1;
        for (int n = 2; n <= N; n++) {
            for (int k = 1; k <= n; k++) {
                dp[n][k] += dp[n - 1][k - 1];
                dp[n][k] += dp[n - 1][k] * (n - 1);
                dp[n][k] %= MOD;
            }
        }
        return dp[N][K];
    }
};
