#include <iostream>

// How many possible ways to reach from 0th to nth stairs.
// we allowed only two steps -> 1 step at a time or 2 steps at a time.

using namespace std;

int climb_stairs(int n, int ans)
{
    // base case 
    if (n == 0 || n == 1)
    {
        return 1;
    }

    ans = climb_stairs(n-1, ans) + climb_stairs(n-2, ans);
    return ans;
    
}

int main ()
{
    int n = 5;

    cout << climb_stairs(n, 0) << endl;
    cout << endl;
    return 0;
}