class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int>rsum(n, 0);
        for(int i=n-2; i>=0; i--)
        {
            rsum[i] = rsum[i+1] + nums[i+1];
        }

        vector<int>ans;
        int lsum = 0;
        for(int i = 0; i<n; i++)
        {
            int diff = abs(rsum[i]-lsum);
            ans.push_back(diff);
            lsum = lsum+nums[i];
        }

        return ans;
    }
};