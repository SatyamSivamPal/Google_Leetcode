class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>st;
        for(int i = 0; i < nums.size(); i++)
        {
            st.insert(nums[i]);
        }
        if(nums.size() > st.size())
        {
            return true;
        }
        return false;
    }
};