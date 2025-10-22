#include <iostream>
#include <vector>

using namespace std;

int lowerBound(vector<int> &arr, int x)
{
    int s = 0;
    int e = arr.size() - 1;
    int ans = e;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] < x)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

vector<int> bs_method(vector<int> &arr, int k, int x)
{
    int h = lowerBound(arr, x);
    int l = h - 1;

    while (k--)
    {
        // edge case
        if (l < 0)
        {
            h++;
        }
        // edge case
        else if (h >= arr.size())
        {
            l--;
        }
        else if (x - arr[l] > arr[h] - x)
        {
            h++;
        }
        else
        {
            l--;
        }
    }
    return vector<int>(arr.begin() + l + 1, arr.begin() + h);
}


vector<int> two_ptr_method(vector<int> &arr, int k, int x)
{
    int l = 0, h = arr.size() - 1;

    while (h - l >= k)
    {
        if (x - arr[l] > arr[h] - x)
        {
            l++;
        }
        else
        {
            h--;
        }
    }
    // h+1 is because vector will create upto n-1 index.
    return vector<int>(arr.begin() + l, arr.begin() + h + 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 4, x = 3;


    // vector<int> res = two_ptr_method(arr, k, x);
    vector<int> res = bs_method(arr, k, x);

    for (auto iter : arr)
    {
        cout << iter << " ";
    }
    cout << endl;
    return 0;
}

// Best sol in terms of TC ->
/*
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int s=0;
        int e=arr.size()-k;
        while(s<e){
            int mid = s+(e-s)/2;
            if(x-arr[mid]>arr[mid+k]-x) {
                s=mid+1;
            }
            else{
                e=mid;
            }
        }

        vector<int> result;
        for(int i=s;i<s+k;i++){
             result.push_back(arr[i]);
        }
        return result;

    }
*/