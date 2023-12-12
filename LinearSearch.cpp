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

class Linear
{
public:
    bool Search(int *arr, int n, int key)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == key)
            {
                return 1;
            }
        }
        return 05;
    }
};

int main()
{
    array *A1 = new array;
    Linear *S1 = new Linear;
    int n, key;
    cout << "Enter the size of the array: ";
    cin >> n;
    int *arr = new int[n];
    A1->Inp(arr, n);
    cout << "Enter the key to be searched: ";
    cin >> key;
    bool found = S1->Search(arr, n, key);
    if (found)
    {
        cout << "Key has been found." << endl;
    }
    else
    {
        cout << "Key not found." << endl;
    }
}