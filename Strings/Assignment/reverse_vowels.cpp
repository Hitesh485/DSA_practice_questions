// approach 1
/*

class Solution {
public:

    bool isVowel(char ch)
    {
        vector<int> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        for (auto iter : vowels)
        {
            if (ch == iter)
            {
                return true;
            }
        }
        return false;
    }

    string reverseVowels(string s) {

        // two pointer approach
        int i = 0;
        int j = s.size()-1;

        while (i < j)
        {
            if (isVowel(s[i]) && isVowel(s[j]))
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if (isVowel(s[i]) && !isVowel(s[j]))
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return s;
    }
};

*/