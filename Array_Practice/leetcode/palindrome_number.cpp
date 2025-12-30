class Solution {
public:
    int utility (int x)
    {
        int rem = 0;
        long long revNum = 0;

        while (x > 0)
        {
            rem = x%10;
            revNum = revNum * 10 + rem;
            x = x/10;
        }
        return revNum;
    }

    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }
        int res = utility(x);
        if (res == x)
            return true;
        return false;
    }
};