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

class CQueue
{
private:
    int *arr;
    int size;
    int qfront;
    int qrear;

public:
    CQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        qfront = -1;
        qrear = -1;
    }

    void Enqueue(int element)
    {
        if ((qfront == -1 && qrear == size - 1) || (qrear == (qfront - 1) % (size - 1)))
        {
            cout << "Queue is Full." << endl;
        }
        else if (qfront == -1)
        {
            qfront = qrear = 0;
            arr[qrear] = element;
        }
        else if (qrear == size - 1 && qfront != 0)
        {
            qrear = 0;
            arr[qrear] = element;
        }
        else
        {
            qrear++;
            arr[qrear] = element;
        }
    }

    int dequeue()
    {
        if (qfront == -1)
        {
            cout << "Queue underflow." << endl;
        }
        int ans = qfront;
        arr[qfront] = -1;
        if (qfront == qrear)
        {

            qfront = qrear = -1;
        }
        else if (qfront == size - 1)
        {
            qfront = 0;
        }
        else
        {
            qfront++;
        }
        return ans;
    }
};