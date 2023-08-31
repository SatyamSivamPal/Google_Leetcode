class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int len = s.size();
        int index = -1;

        if(len == 1) return -1;

        for(int i = len-2; i >= 0; i--)
        {
            if(s[i] - '0' < s[i+1]-'0')
            {
                index = i;
                break;
            }
        }

        if(index == -1)
        {
            return -1;
        }

        for(int i = len-1; i > index && index != -1; i--)
        {
            if(s[i]-'0' > s[index]-'0')
            {
                swap(s[i], s[index]);
                break;
            }
        }

        reverse(s.begin() + index+1, s.end());

        long long ans = stoll(s);

        if(ans >= INT32_MIN && ans <= INT32_MAX)
        {
            return ans;
        }
        else{
            return -1;
        }

        // return ans;
    }
};