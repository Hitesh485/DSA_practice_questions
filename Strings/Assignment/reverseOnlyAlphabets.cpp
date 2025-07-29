class Solution {
public:

    bool checkAlpha(char ch)
    {
        if ((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90))
        {
            return true;
        }
        return false;
    }

    string reverseOnlyLetters(string s) {
        int i = 0;
        int j = s.size()-1;
        while (i < j)
        {
            if (checkAlpha(s[i]) && checkAlpha(s[j]))
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if (!checkAlpha(s[i]))
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return s;
    }
};