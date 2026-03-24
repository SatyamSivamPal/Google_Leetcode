class Solution {
public:
    int f(int i,int buy,int k,vector<int>& arr, vector<vector<vector<int>>>& dp) {
        int n = arr.size();
        //base case
        if(i == n) return 0;
        if(k == 0) return 0;
        
        if(dp[i][buy][k] != -1) return dp[i][buy][k];
        int profit = 0;
        if(buy) {
            int t = -arr[i] + f(i+1, 0, k, arr, dp);
            int nt = 0 + f(i+1, 1, k, arr, dp);

            profit = max(t, nt);
        } else {
            int t = arr[i] + f(i+1, 1, k-1, arr, dp);
            int nt = 0 + f(i+1, 0, k, arr, dp);

            profit = max(t, nt);
        }

        return dp[i][buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        int ans = f(0, 1, k, prices, dp);
        return ans;
    }
};