class Solution {
public:
    string reverseWords(string s) {
        // stack<char>st;

        string temp = "";
        string ans = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ' && temp.size() > 0)
            {
                reverse(temp.begin(), temp.end());
                ans = ans + temp;
                ans.push_back(' ');
                temp = "";
            }

           else if(s[i] != ' ')
            {
                temp.push_back(s[i]);
            }
        }

        reverse(temp.begin(), temp.end());
        if(temp.size() > 0)
        {
            ans = ans + temp;
        }

        return ans;
    }
};