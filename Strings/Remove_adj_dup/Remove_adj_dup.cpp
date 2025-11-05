#include <iostream>
#include <string>

using namespace std;

string remove_adj_dup(string &str)
{
    int i = 0;
    while (i < str.size()-1)
    {
        if (str.size()== 0) return "";
        if (str[i] == str[i+1])
        {
            str.erase(i, 2);
            i=0;
        }
        else
        {
            i++;
        }
        cout << "size of string : " << str.size() << endl;
    }
    return str;
}

string remove_adj_dup_2(string &str)
{
    string ans = "";
    int i = 0;

    while (i < str.size())
    {
        if (ans.empty())
        {
            ans += str[i];
        }

        else if (ans.back() != str[i])
        {
            ans += str[i];
        }
        else
        {
            ans.pop_back();
        }
        i++;
    }

    return ans;
}

string remove_adj_dup_3(string str) {
        int i = 0;
        string ans = "";

        while (i < str.size())
        {        
            if (ans.length()>0 && ans[ans.length()-1] == str[i])
                    {
                        ans.pop_back();
                    }
                else
                    {
                        ans.push_back(str[i]);
                    }
               
            i++;
        }
        return ans;
    }

int main ()
{
    string str = "abbaca";
    // string str = "aabbcc";

    cout << endl << endl;
    // cout << remove_adj_dup(str) << endl;

    // cout << remove_adj_dup_2(str) << endl;

    // improve time in ms
    cout << remove_adj_dup_3(str) << endl;




    
    // int i = 1;
    // // erase(index, pos)
    // str.erase(i, 2);
    // i = 0;
    // str.erase(i, 2);
    // cout << str << endl;
    return 0;
}