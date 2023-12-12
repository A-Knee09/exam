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

class Duplicate
{
public:
    void Find(int *arr, int n)
    {
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    if (!found)
                    {

                        cout << "Duplicate values: ";
                        found = true;
                    }
                    cout << arr[i] << " ";
                    break;
                }
            }
        }
        if (!found)
        {
            cout << "No duplicate values found in the array.";
        }

        cout << endl;
    }
};

int main()
{
    array *a = new array;
    Duplicate *d = new Duplicate;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int *arr = new int[n];
    a->Inp(arr, n);
    d->Find(arr, n);
}