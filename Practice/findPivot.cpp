#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int findSum(int n)
{
    int sum = n * (n + 1) / 2;
    int rt = sqrt(sum);
    if (rt * rt == sum) return rt;
    return -1;
}

int main()
{
    int n = 6;

    cout << findSum(n) << endl;
    return 0;
}