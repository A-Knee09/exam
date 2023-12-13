#include <iostream>
using namespace std;

class array
{
public:
    void Inp(int *arr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << endl;
    }
    void Out(int *arr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Sort
{
public:
    void Merge(int *arr, int s, int e)
    {
        int mid = s + (e - s) / 2;

        int length1 = mid - s + 1;
        int length2 = e - mid;

        int *first = new int[length1];
        int *second = new int[length2];

        int MAI = s;
        for (int i = 0; i < length1; i++)
        {
            first[i] = arr[MAI++];
        }
        MAI = mid + 1;
        for (int i = 0; i < length2; i++)
        {
            second[i] = arr[MAI++];
        }

        // Merge 2 sorted array;
        int idx1 = 0;
        int idx2 = 0;
        MAI = s;

        while (idx1 < length1 && idx2 < length2)
        {
            if (first[idx1] < second[idx2])
            {
                arr[MAI++] = first[idx1++];
            }
            else
            {
                arr[MAI++] = second[idx2++];
            }
        }
        while (idx1 < length1)
        {
            arr[MAI++] = first[idx1++];
        }
        while (idx2 < length2)
        {
            arr[MAI++] = second[idx2++];
        }
    }

    void MergeSort(int *arr, int s, int e)
    {
        if (s >= e)
        {
            return;
        }
        int mid = s + (e - s) / 2;
        MergeSort(arr, s, mid);     // Left Part solve
        MergeSort(arr, mid + 1, e); // Right Part solve
        Merge(arr, s, e);
    }
};

int main()
{
    int size;
    Sort *s = new Sort;
    cout << "Enter the size of the array: ";
    cin >> size;
    int *arr = new int[size];
    array *a = new array;
    a->Inp(arr, size);
    cout << "Orignal array: ";
    a->Out(arr, size);
    cout << "Sorted array is: ";
    s->MergeSort(arr, 0, size - 1);
    a->Out(arr, size);
    return 0;
}