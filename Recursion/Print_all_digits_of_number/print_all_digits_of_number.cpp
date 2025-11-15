#include <iostream>
#include <vector>

using namespace std;

vector<int> printDigits(int number, vector<int> &ans)
{
    if (number <= 0)
    {
        return ans;
    }
    
    int digit = number % 10;
    ans.push_back(digit);
    number = number / 10;
    
    return printDigits(number, ans);

}

void printDigits(int number)
{
    if (number == 0)
    {
        return;
    }
    
    printDigits(number/10);

    int digit = number % 10;
    cout << digit << " ";


}

int main ()
{
    vector<int> ans;
    int number = 4562;
    
    // vector<int> res = printDigits(number, ans);
    
    // for (auto iter : res)
    // {
    //     cout << iter << " ";
    // }
    
    // without using extra space
    printDigits(number);

    cout << endl;
    return 0;
}