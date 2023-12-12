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

class binary
{
public:
    int First_Occ(int *arr, int n, int key)
    {
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;
        int ans = -1;

        while (s <= e)
        {
            if (arr[mid] == key)
            {
                ans = mid;
                e = mid - 1;
            }
            else if (arr[mid] < key)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }

            mid = s + (e - s) / 2;
        }
        return ans;
    }

    int Last_Occ(int *arr, int n, int key)
    {
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;
        int ans = -1;

        while (s <= e)
        {
            if (arr[mid] == key)
            {
                ans = mid;
                s = mid + 1;
            }
            else if (arr[mid] < key)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }

            mid = s + (e - s) / 2;
        }
        return ans;
    }
};

int main()
{
    array *a = new array;
    binary *b = new binary;
    int n, key;

    cout << "Enter the size of the array: ";
    cin >> n;
    int *arr = new int[n];
    a->Inp(arr, n);
    cout << "Enter the key to be searched: ";
    cin >> key;
    int index1 = b->First_Occ(arr, n, key);
    int index2 = b->Last_Occ(arr, n, key);
    cout << "The first occurrence of key " << key << " is at position " << index1 + 1 << endl;
    cout << "The last occurrence of key " << key << " is at position " << index2 + 1 << endl;
    int total = (index2 - index1) + 1;
    cout << "Total number of occurrences are: " << total;
}