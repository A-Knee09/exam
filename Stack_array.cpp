#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    int size;
    int *arr;

public:
    Stack(int s)
    {
        this->size = s;
        arr = new int[size];
        top = -1;
    }
    ~Stack()
    {
        delete[] arr;
    }

    void push(int element)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = element;
        }

        else
        {
            cout << "Stack overflow." << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow." << endl;
        }
        else
        {
            top--;
        }
    }

    void IsEmpty()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
        }

        else
        {
            cout << "Stack is not empty." << endl;
        }
    }

    void peek()
    {
        if (top == -1)
        {
            cout << "Cant peek." << endl;
        }
        else
        {
            cout << arr[top];
            cout << endl;
        }
    }

    int Length()
    {
        return top + 1;
    }

    void print()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Stack *s1 = new Stack(5);
    s1->push(10);
    s1->push(20);
    s1->push(30);
    s1->push(40);
    s1->push(50);
    s1->peek();
    s1->pop();
    s1->peek();
    s1->print();
    s1->pop();
    s1->pop();
    s1->pop();
    s1->print();
    s1->pop();
    s1->peek();
    s1->IsEmpty();
}