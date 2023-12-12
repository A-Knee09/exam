#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        this->data = d;
        prev = NULL;
        next = NULL;
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

class Double
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
            head->prev = temp;
            head = temp;
        }
    }

    void InsTail(Node *&head, Node *&tail, int d)
    {
        Node *temp = new Node(d);
        if (tail == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void InsAtPos(Node *&head, Node *&tail, int d, int pos)
    {
        if (pos == 1)
        {
            InsHead(head, tail, d);
            return;
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

            Node *NTI = new Node(d);
            NTI->next = temp->next;
            temp->next->prev = NTI;
            temp->next = NTI;
            NTI->prev = temp;
        }
    }

    void Delete(Node *&head, int pos)
    {
        if (pos == 1)
        {
            Node *temp = head;
            head = head->next;
            temp->prev = NULL;
            temp->next = NULL;
            delete temp;
        }
        else
        {
            Node *curr = head;
            Node *prev = prev;
            int count = 1;
            while (count < pos)
            {
                prev = curr;
                curr = curr->next;
                count++;
            }

            prev->next = curr->next;
            curr->next->prev = prev;
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;
        }
    }

    void display(Node *&head)
    {
        Node *temp = head;
        if (temp == NULL)
        {
            cout << "List is empty";
            cout << endl;
        }
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    Double *D = new Double;
    D->InsTail(head, tail, 10);
    D->InsTail(head, tail, 20);
    D->InsTail(head, tail, 10);
    D->Delete(head, 2);
    D->display(head);
}