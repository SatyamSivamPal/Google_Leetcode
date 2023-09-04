class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>mpp;
        // sort(nums.begin(), nums.end());
        for(int i  = 0; i < nums.size() ; i++)
        {
            if(nums[i] % 2 == 0)
            {
                mpp[nums[i]]++;
            }
        }
        int maxFreq = 0;
        int maxElem = -1;

        for(auto it : mpp)
        {
            if(it.second > maxFreq)
            {
                maxElem = it.first;
                maxFreq = it.second;
            }
        }

        return maxElem;

    }
};