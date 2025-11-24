#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int si, int ei)
{
    // let us assume the pivot element is our first index
    int pivotEle = arr[si];
    int pivotIdx = -1;
    int count = 0;
    // finding the correct position of pivot element
    for (int i = si + 1; i <= ei; i++)
    {
        if (arr[si] >= arr[i])
        {
            count++;
        }
    }
    pivotIdx = count + si;
    // swap the pivot element with there correct position element
    swap(arr[si], arr[pivotIdx]);

    int i = si;
    int j = ei;
    while (i < pivotIdx && j > pivotIdx)
    {
        if (arr[i] <= arr[pivotIdx])
        {
            i++;
        }
        else if (arr[j] >= arr[pivotIdx])
        {
            j--;
        }
        else if (arr[i] > arr[pivotIdx] && arr[j] < arr[pivotIdx])
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIdx;
}

void quickSort(vector<int> &arr, int si, int ei)
{
    if (si >= ei)
        return;
    int pi = partition(arr, si, ei);
    quickSort(arr, si, pi - 1);
    quickSort(arr, pi + 1, ei);
}

int main()
{

    int n;
    cout << "Enter the element of the array: ";
    cin >> n;
    int si = 0;
    int ei = n - 1;

    vector<int> arr(n);

    cout << "Enter the element of the array : ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Sorted array : ";

    quickSort(arr, si, ei);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}