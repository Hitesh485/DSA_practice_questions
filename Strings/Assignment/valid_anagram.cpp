class Solution
{
public:
    bool isAnagram(string s, string t)
    {

        // edge case ->
        if (s.size() != t.size())
        {
            return false;
        }

        // we have to achieve the same count of each char.

        unordered_map<int, int> mp1;
        for (int i = 0; i < s.size(); i++)
        {
            mp1[s[i]]++;
        }

        unordered_map<int, int> mp2;
        for (int i = 0; i < t.size(); i++)
        {
            mp2[t[i]]++;
        }

        // check occrr is same in s string or not
        for (int i = 0; i < t.size(); i++)
        {
            char key = t[i];
            if (mp1[key] != mp2[key])
            {
                return false;
            }
        }
        return true;
    }
}; 

// method -2 optimize
class Solution {
public:
    bool isAnagram(string s, string t) {
        // more optimize method -> 
        // going to maintain a freq table 0-255 (ascii).

        int freqTable[256] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            freqTable[s[i]]++;
        }

        // now, we have dec the count for t string,
        for (int i= 0;i < t.size(); i++)
        {
            freqTable[t[i]]--;
        }

        // All values of freqTable should be 0, if it is anagram
        for (int i= 0;i < 256; i++)
        {
            if (freqTable[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};