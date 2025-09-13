class Solution {
public:
    int maxFreqSum(string s) {
        map<char,int>mp;
        int maxiVowl = 0;
        int maxiConso = 0;

        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        for(auto it: mp) {
            char c = it.first;
            int a = it.second;

            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                maxiVowl = max(maxiVowl, a);
            } else {
                maxiConso = max(maxiConso, a);
            }
        }

        cout<<maxiVowl<<" "<<maxiConso;

        return maxiVowl + maxiConso;
    }
};