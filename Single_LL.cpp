#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

class Single
{
public:
    void InsHead(Node *&head, Node *&tail, int d)
    {
        Node *temp = new Node(d);
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }

    void InsTail(Node *&head, Node *&tail, int d)
    {
        Node *temp = new Node(d);
        if (tail == NULL)
        {
            tail = head = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void InsAtPos(Node *&head, Node *&tail, int d, int pos)
    {
        if (pos == 1)
        {
            InsHead(head, tail, d);
        }
        else
        {
            Node *temp = head;
            int count = 1;
            while (count < pos - 1)
            {
                temp = temp->next;
                count++;
            }
            if (temp->next == NULL)
            {
                InsTail(head, tail, d);
            }
            else
            {

                Node *NTI = new Node(d);
                NTI->next = temp->next;
                temp->next = NTI;
            }
        }
    }

    void Delete(Node *&head, int pos)
    {
        if (pos == 1)
        {
            Node *temp = head;
            head = temp->next;
            temp->next = NULL;
            delete temp;
        }
        else
        {
            int count = 1;
            Node *curr = head;
            Node *prev = NULL;
            while (count < pos)
            {
                prev = curr;
                curr = curr->next;
                count++;
            }
            if (curr == NULL)
            {
                cout << "Please Redefine Position." << endl;
            }
            else
            {

                prev->next = curr->next;
                curr->next = NULL;
                delete curr;
            }
        }
    }

    void Display(Node *&head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int Length(Node *&head)
    {
        int len = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        cout << "Length is: " << len;
        return len;
    }
};

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    Single *s1 = new Single;
    s1->InsHead(head, tail, 10);
    s1->InsTail(head, tail, 20);
    s1->InsAtPos(head, tail, 15, 2);
    s1->Display(head);
    s1->InsTail(head, tail, 30);
    s1->Display(head);
    s1->InsHead(head, tail, 5);
    s1->Display(head);
    s1->Length(head);
}