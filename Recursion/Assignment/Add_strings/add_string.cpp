class Solution {
public:

    void RE(string &nums1, int n1, string &nums2, int n2, string &ans, int carry = 0)
    {
        if (n1 < 0 && n2 < 0)
        {
            if (carry != 0)
            {
                ans.push_back(carry + '0');
            }
            return;
        }

        int p1 = ((n1 >= 0) ? nums1[n1] : '0') - '0';
        int p2 = ((n2 >= 0) ? nums2[n2] : '0') - '0';
        int csum = p1 + p2 + carry;
        int digit = csum % 10;
        carry = csum/10;
        ans.push_back(digit + '0'); // int to char
        RE(nums1, n1-1, nums2, n2-1, ans, carry);
    }

    string addStrings(string num1, string num2) {
        string ans = "";
        RE(num1, num1.size()-1, num2, num2.size()-1, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};