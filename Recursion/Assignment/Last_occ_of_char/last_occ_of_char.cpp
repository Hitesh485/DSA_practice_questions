#include <iostream>
#include <cstring>
#include <string>
#include <typeinfo>

using namespace std;

// iterative approach
int last_occ_char(string &str, char &ch)
{
    int ans = 0;
    int n = str.size()-1;
    int i = 0;
    while (i <= n)
    {
        if (str[i] == ch)
        {
            ans = i;
        }
        i++;
    }
    return ans;
}

// using rec
int last_occ_char_rec(string &str, char &ch, int n, int i, int ans)
{
    if (i > n-1)
    {
        return ans;
    }

    if (str[i] == ch)
        ans = i;
    
    return last_occ_char_rec(str, ch, n, i+1, ans);
}

// Method - 2 (search reverse)
int last_occ_char_rec_search_rev(string &str, char &ch, int n, int i)
{
    if (i < 0)
    {
        return -1;
    }

    if (str[i] == ch)
        return i;
    
    return last_occ_char_rec_search_rev(str, ch, n, i-1);
}

// Built in function
// return pointer of first char of string
// return null if char not found

/*
The c_str() method in C++ is a member function of the std::string class that returns a pointer to a null-terminated C-style character array (a C-string) representing the current content of the std::string object. 


Purpose: It facilitates interoperability between C++ std::string objects and functions or APIs that expect C-style strings (const char*). This is particularly useful when working with legacy C libraries or system-level functions.


Return Value: It returns a const char* pointer, indicating that the returned character array should not be modified directly. Modifying the data pointed to by c_str() can lead to undefined behavior, as the underlying std::string object might have its own internal memory management.
*/

int last_occ_char_str(string &str, char ch)
{
    char str2[str.size()];
    int i = 0;
    while (str[i] != '\0')
    {
        str2[i] = str[i];
        i++;
    }
    const char *ptr = strrchr(str2, ch);

    // ptr is the pointer of d i.e 6th index
    // str2 is pointer of start i.e 0th index
    // now 6 - 0 + 1 = 7. (+1 for indexing).
    return ptr - str2+1;    

}

int main ()
{
    string str = "abcddedfvc";
    char ch = 'd';
    int n = str.size();
    int i = 0;

    // cout << last_occ_char(str, ch) << endl;
    // cout << last_occ_char_rec(str, ch, n, i, 0) << endl;
    i = n;
    // cout << last_occ_char_rec_search_rev(str, ch, n, i) << endl;

    cout << last_occ_char_str(str, ch) << endl;

    return 0;
}