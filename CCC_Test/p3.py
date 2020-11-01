"""
class Solution {
    public int countVowelPermutation(int n) {
        double[][] dp = new double[n + 1][5];
        for (int i = 0; i < 5; i++){
        	dp[1][i] = 1;
        }
        for (int i = 2; i <= n; i++){
        	dp[i][0] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4];
        	dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
        	dp[i][2] = dp[i - 1][1] + dp[i - 1][3];
        	dp[i][3] = dp[i - 1][2];
        	dp[i][4] = dp[i - 1][2] + dp[i - 1][3];
        	for (int j = 0; j < 5; j++){
        		dp[i][j] %= 1000000007;
        	}
        }
        int res = 0;
        for (int i = 0; i < 5; i++){
        	res += dp[n][i];
        	res %= 1000000007;
        }
        return res;
    }
}
"""
def count(n):
    mod = 10**9+7
    add = lambda x,y: (x+y)%(mod)
    dp = [[1 for i in range(5) ] for j in range(n+1)]
    for i in range(2,n+1):
        dp[i][0] = dp[i-1][1]+dp[i-1][2]+dp[i-1][4]
        dp[i][1] = dp[i-1][0]+dp[i-1][2]
        dp[i][2] = dp[i-1][1]+dp[i-1][3]
        dp[i][3] = dp[i-1][2]
        dp[i][4] = dp[i-1][2]+dp[i-1][3]
        for j in range(5):
            dp[i][j] %= 10**9+7
    res = 0
    for i in range(5):
        res = add(res,dp[n][i])
    return res