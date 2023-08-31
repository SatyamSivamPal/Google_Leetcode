class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b)
    {
        return a.second > b.second;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>> v;

        for(int i = 0; i < boxTypes.size(); i++)
        {
            pair<int,int> p = {boxTypes[i][0], boxTypes[i][1]};
            v.push_back(p);
        }

        sort(v.begin(), v.end(), cmp);

        int total = 0;

        for(int i = 0; i < v.size(); i++)
        {
            if(v[i].first > truckSize)
            {
                total += truckSize * v[i].second;
                truckSize = 0;
            }
            else{
                total += v[i].first * v[i].second;
                truckSize = truckSize - v[i].first;
            }
        }

        return total;
    }
};