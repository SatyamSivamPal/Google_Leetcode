class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int,int>mpp;
        int n = nums.size();

        int min = floor(n/3) + 1;
        vector<int>ans;
        for(int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
            if(mpp[nums[i]] == min)
            {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};