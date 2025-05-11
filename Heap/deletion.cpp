#include <iostream>

using namespace std;

// In deletion, always delete the root node only.

/*
1. replace last value with root node.
2. place root node to it's correct pos.
*/

// create heap
class Heap
{
public:
    int arr[101];
    int size;

    Heap()
    {
        size = 0;
    }

    void insert(int value)
    {
        // value insert at end
        size = size + 1;

        int index = size;
        arr[index] = value;

        // place at correct position

        // why not (i >= 1), because by >= it assume 0th ele is parent, and 0th pos is not valid, in Heap we started from 1st index of an arr.
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    int del()
    {
        int ans = arr[1];
        // replace root node value with last node data.
        arr[1] = arr[size];
        --size;

        // place root node ka data on it's correct position.
        int index = 1;

        while (index < size)
        {
            int left = 2*index;
            int right = 2*index+1;

            int largest = index;

            if (left < size && arr[index] < arr[left])
            {
                largest = left;
            } 
            if (right < size && arr[index] < arr[right])
            {
                largest = right;
            }

            if (largest == index)
            {
                // value is at correct position
                return ans; 
            }

            else{
                swap(arr[index], arr[largest]);
                index = largest;    
            }
        }
    }
};

int main()
{
    Heap h;
    h.arr[0] = -1;
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 40;
    h.arr[5] = 45;

    h.size = 5;
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    h.insert(110);

    h.del();

    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;
    return 0;
}