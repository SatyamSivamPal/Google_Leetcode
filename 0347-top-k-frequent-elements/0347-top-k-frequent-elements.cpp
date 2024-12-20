class Solution {
public:
static bool cmp(pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second; 
        };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int>mp;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }

        vector<pair<int,int>>temp;
        vector<int>ans;

        for(auto it: mp){
            temp.push_back(it);
        }

        sort(temp.begin(), temp.end(), cmp);

        for(int i=0;i<k;i++){
            ans.push_back(temp[i].first);
        }
    
        return ans;
    }
};