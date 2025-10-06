#include <iostream>
#include <limits.h>
#include <cmath>

using namespace std;

int divide(int dividend, int divisor)
{

    int start = 0;
    int end = abs(dividend);
    int ans = INT_MIN;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (abs(divisor * mid) == abs(dividend))
        {
            ans = mid;
            break;
        }
        else if (abs(divisor * mid) > abs(dividend))
        {
            // search in left
            end = mid - 1;
        }
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }

    
    if (ans >= INT_MAX)
    {
        cout << "int max" << endl;
        return pow(2,31)-1;
    }
    else if (ans <= INT_MIN)
    {
        cout << "int min" << endl;
        return -pow(2,31);
    }

    if (divisor < 0 && dividend < 0 || dividend > 0 && divisor > 0)
    {
        cout << "+ ans" << endl;
        return ans;
    }
    return ans *= -1;

}

int main()
{
    int dividend = -2147483648;
    int divisor = -1;

    cout << divide(dividend, divisor) << endl;
    return 0;
}