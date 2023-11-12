class Solution {
public:
    
    bool f(vector<string> &time)
    {
        sort(time.begin(), time.end());
        
        
        if(time.size() >= 3)
        {
                for(int i = 0; i < time.size() - 2; i++)
                {
                    if(stoi(time[i+2]) - stoi(time[i]) < 100)
                    {
                        return true;
                    }
                }
        }
            
        return false;
        
    }
    
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        
        map<string, vector<string> >mp;
        
        for(auto it : access_times)
        {
            mp[it[0]].push_back(it[1]);
        }
        
        vector<string>ans;
        
        for(auto it : mp)
        {
            if(f(it.second))
            {
                
                ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};