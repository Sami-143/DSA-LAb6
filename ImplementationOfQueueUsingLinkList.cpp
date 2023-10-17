#include <iostream>
using namespace std;
template <typename T>
class LinkedList
{
private:
    class node
    {
        T data;
        node *next;
        node(T value)
        {
            data = value;
            next = nullptr; 
        }
    };

    node *head;
    node *tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void append(T value)
    {
        node *newNode = new node(value);
        if (tail == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    T removeFront()
    {
        if (head == nullptr)
        {
            cout<<"Queue is empty"<<endl;
        }
        T data = head->data;
        node *temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr)
        {
            tail = nullptr;
        }
        return data;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }
};

template <typename T>
class Queue
{
private:
    LinkedList<T> list;

public:
    Queue() {}

    void Enqueue(T value)
    {
        list.append(value);
    }

    T Dequeue()
    {
        return list.removeFront();
    }

    bool IsEmpty()
    {
        return list.isEmpty();
    }
};

int main()
{
    Queue<int> queue;

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);

    while (!queue.IsEmpty())
    {
        cout << queue.Dequeue() << " ";
    }

    cout << endl;

    return 0;
}
