#include <iostream>

using namespace std;
// Max Heap
// we can convert any array into heap using heapify function.


// Very Important Question
void heapify(int arr[], int n, int i)
{
    int index = i;
    int largest = index;
    int leftIndex = 2*i;
    int rightIndex = 2*i+1;

    if (leftIndex <= n && arr[largest] < arr[leftIndex] )
    {
        largest = leftIndex;
    }

    if (rightIndex <= n && arr[largest] < arr[rightIndex])
    {
        largest = rightIndex;
    }

    if (largest != index)
    {
        // now largest will update and we need to swap.
        swap(arr[largest], arr[index]);
        index = largest;
        heapify(arr, n, index);
    }
}

void buidHeap (int arr[], int n)
{
    for (int i = n/2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
}

int main ()
{
    int arr[] = {-1, 12, 15, 13, 11, 14};
    int n = 5;

    buidHeap(arr, n);

    cout << "printing heap: " << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}