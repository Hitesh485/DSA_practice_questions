#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int buySell(vector<int> &prices)
{
    int buy = INT_MAX;
    int sell = INT_MIN;
    int day = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        // lowest = min(lowest, prices[i]);
        if (buy > prices[i])
        {
            buy = prices[i];
            day = i;
        }
    }

    if (buy == prices[prices.size()-1])
    {
        return 0;
    }

    for (int i= day+1; i < prices.size(); i++)
    {
        sell = max(sell, prices[i]);
    }

    return sell - buy;


}

int main()
{
    vector<int> arr = {7,10,1,3,6,9,2};
    cout << buySell(arr) << endl;
    return 0;
}