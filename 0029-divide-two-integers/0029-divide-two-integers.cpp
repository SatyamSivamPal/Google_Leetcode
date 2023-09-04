class Solution {
public:
    int divide(int dividend, int divisor) {
        //edge case
        
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool sign = (dividend >= 0) == (divisor >= 0) ? true: false;

        long long result = 0;

        long long divide = abs(dividend);
        long long divis = abs(divisor);

        while(divide - divis >= 0)
        {
            int  cnt = 0;
            while(divide - (divis << 1 << cnt) >= 0)
            {
                cnt++;
            }
            result += 1 << cnt;
            divide = divide - (divis << cnt);
        }

        if(sign)
        {
            return result;
        }
        return -result;
    }
};