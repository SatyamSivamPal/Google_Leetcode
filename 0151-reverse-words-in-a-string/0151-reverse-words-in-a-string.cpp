class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";

        for(int i = s.size()-1; i >= 0; i--)
        {
            if(s[i] == ' ' && temp.size() > 0)
            {

                // while(s[i] == ' ')i--;
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

        if(ans[ans.size() - 1] == ' ')
        {
            ans.pop_back();
        }
        

        return ans;
    }
};