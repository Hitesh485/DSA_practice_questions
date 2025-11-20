#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int cut_into_segments(int n, int x, int y, int z) 
{
    if (n == 0) return 0;
    if (n < 0) return INT_MIN;

    int a = cut_into_segments(n-x, x, y, z) + 1;
    int b = cut_into_segments(n-y, x, y, z) + 1;
    int c = cut_into_segments(n-z, x, y, z) + 1;

    return max(a, max(b,c));
}

int main ()
{
    int n = 7, x = 5, y = 2, z = 2;
    if (cut_into_segments(n, x, y, z) < 0)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << cut_into_segments(n, x, y, z) << endl;
    return 0;
}