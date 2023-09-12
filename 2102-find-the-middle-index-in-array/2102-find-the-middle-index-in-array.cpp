class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        vector<int>rsum(n,0);

        for(int i = n-2; i>=0; i--)
        {
            rsum[i] = rsum[i+1] + nums[i+1];
        }
        
        int ans = -1;
        int lsum = 0;
        for(int i=0; i<n; i++)
        {
            if(lsum == rsum[i])
            {
                ans = i;
                break;
            }
            lsum = lsum+nums[i];
        }

        if(ans == -1)
        {
            return -1;
        }
        return ans;
    }
};