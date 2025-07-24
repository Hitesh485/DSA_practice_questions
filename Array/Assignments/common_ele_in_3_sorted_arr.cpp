#include <iostream>
#include <vector>
#include <set>

using namespace std;

// vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
//                            vector<int> &arr3)
// {
//     // Code Here
//     set<int> st;
//     for (int i = 0; i < arr1.size(); i++)
//     {
//         for (int j = 0; j < arr2.size(); j++)
//         {
//             for (int k = 0; k < arr3.size(); k++)
//             {
//                 if ((arr1[i] == arr2[j]) && arr2[j] == arr3[k])
//                 {
//                     st.insert(arr1[i]);
//                 }
//             }
//         }
//     }

//     vector<int> res;
//     for (auto it : st)
//     {
//         res.push_back(it);
//     }
//     return res;
// }

vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
    vector<int> res;
    set<int> st;

    int i, j, k;
    i = j = k = 0;
    int n1 = a.size();
    int n2 = b.size();
    int n3 = c.size();
    while ((i < n1) && (j < n2) && (k < n3))
    {
        if (a[i] == b[j] && b[j] == c[k])
        {
            st.insert(a[i]);
            i++, j++, k++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < c[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }

    for (auto it : st)
    {
        res.push_back(it);
    }

    return res;
}

int main()
{
    vector<int> arr1 = {1, 5, 10, 20, 40, 80};
    vector<int> arr2 = {6, 7, 20, 80, 100};
    vector<int> arr3 = {3, 4, 15, 20, 30, 70, 80, 120};

    vector<int> res = commonElements(arr1, arr2, arr3);

    if (res.size() != 0)
    {
        for (auto it : res)
        {
            cout << it << ", ";
        }
    }
    else
    {
        cout << -1 << endl;
    }
    cout << endl;

    return 0;
}