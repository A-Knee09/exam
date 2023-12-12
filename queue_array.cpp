#include <iostream>
using namespace std;

class Queue
{
private:
    int qfront;
    int qrear;
    int size;
    int *arr;

public:
    Queue(int size)
    {
        this->size = size;
        qfront = 0;
        qrear = 0;
        arr = new int[size];
    }

    void Enqueue(int element)
    {
        if (qrear == size)
        {
            cout << "Queue overflow." << endl;
        }

        else
        {
            arr[qrear] = element;
            qrear++;
        }
    }

    int Dequeue()
    {
        if (qrear == qfront)
        {
            cout << "Cant Dequeue, Queue underflow." << endl;
        }
        else
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == qrear)
            {
                qfront = 0;
                qrear = 0;
            }
            return ans;
        }
    }

    void display()
    {
        if (qfront == qrear)
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            for (int i = qfront; i < qrear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue *Q = new Queue(3);
    Q->Enqueue(10);
    Q->Enqueue(10);
    Q->Enqueue(10);
    Q->display();
    Q->Dequeue();
    Q->Dequeue();
    Q->Dequeue();
    Q->display();
}