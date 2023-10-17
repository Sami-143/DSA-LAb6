#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int value)
    {
        data = value;
        next = nullptr;
    }
};

void Insert_AT_Tail(node *&head, int val)
{
    node *n = new node(val);

    if (head == nullptr)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void Insert_AT_Head(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

int search_At_Middle(node *&head)
{
    if (head == nullptr)
    {
        return -1;
    }

    int node_counter = 0;
    node *oneStep = head;
    node *twoStep = head;

    while (oneStep != nullptr && twoStep->next != nullptr)
    {
        oneStep = oneStep->next;
        twoStep = twoStep->next->next;
        node_counter++;
    }

    return node_counter;
}

void insertAtMiddle(node *&head, int val)
{
    node *curr = new node(val);
    int node_counter = 0;
    node *temp = head;
    while (temp != nullptr)
    {
        node_counter++;
        temp = temp->next;
    }
    temp = head;
    int mid = node_counter / 2;

    for (int i = 0; i < mid; i++)
    {
        temp = temp->next;
    }
    node *next_node = temp->next;
    temp->next = curr;
    curr->next = next_node;
}

void insert_After(node *&head, int val)
{
    node *curr = new node(val);
    node *temp = head;
    while (temp != nullptr)
    {
        temp = temp->next;
    }
    node *next_node = temp->next;
    temp->next = curr;
    curr->next = next_node;
}

// This function is used to delte the middle element in the Linked List
void removeMiddle(node *&head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    int counter = 0;
    node *temp = head;
    node *prev_ptr = nullptr;

    while (temp != nullptr)
    {
        counter++;
        temp = temp->next;
    }

    temp = head;
    int mid = counter / 2;

    for (int i = 0; i < mid; i++)
    {
        prev_ptr = temp;
        temp = temp->next;
    }

    prev_ptr->next = temp->next;
    delete temp;
}

bool isEmpty(node *&head)
{
    node *temp = head;
    if (head == nullptr)
    {
        return true;
    }
    return false;
}

bool search(node *&head, int key)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deletionAtHead(node *&head)
{
    node *todelete = head;
    head = head->next;
    delete todelete;
}

void deletion(node *&head, int val)
{
    if (head == nullptr)
    {
        return;
    }
    if (head->next == nullptr)
    {
        deletionAtHead(head);
        return;
    }
    node *temp = head;

    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void deleteAtTail(node *&head)
{
    node *temp = head;
    if (temp == nullptr)
    {
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

bool isCircularLinkedList(node *head)
{
    node *temp = head;
    if (temp == nullptr)
    {
        return false;
    }
    while (temp->next != nullptr)
    {
        temp = temp->next;
        if (temp->next == head)
        {
            return true;
        }
    }
    return false;
}

node *reverse(node *&head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;


    
}

node *reverseRecursive(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newhead = reverseRecursive(head->next);
    head= head->next->next;
    head->next = NULL;

    return newhead;
}

void display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{

    node *head = NULL;
    Insert_AT_Tail(head, 1);
    Insert_AT_Tail(head, 2);
    Insert_AT_Tail(head, 3);
    Insert_AT_Tail(head, 4);
    Insert_AT_Tail(head, 5);
    // Insert_AT_Head(head,6);

    display(head);

    deleteAtTail(head);
    display(head);
    // if(isEmpty(head))
    // {
    //     cout<<"link list is empty"<<endl;
    // }

    // cout<<search(head,3)<<endl;
    // deletion(head,2);
    // deletionAtHead(head);
    // display(head);
    // cout<<search_At_Middle(head);

    // cout<<isCircularLinkedList(head);
    // return 0;
}

// #include <iostream>
// using namespace std;

// template <typename T>
// class node {
// public:
//     T data;
//     node<T>* next;

//     node(T value) {
//         data = value;
//         next = nullptr;
//     }
// };

// template <typename T>
// bool isEmpty(node<T>* head) {
//     return head == nullptr;
// }

// template <typename T>
// void display(node<T>* head) {
//     node<T>* temp = head;
//     while (temp != nullptr) {
//         cout << temp->data << "->";
//         temp = temp->next;
//     }
//     cout << "NULL" << endl;
// }

// template <typename T>
// T GetFront(node<T>* head) {
//     if (head == nullptr) {
//         return T();
//     }
//     return head->data;
// }

// template <typename T>
// T GetTail(node<T>* head) {
//     if (head == nullptr) {
//         return T();
//     }

//     node<T>* temp = head;
//     while (temp->next != nullptr) {
//         temp = temp->next;
//     }
//     return temp->data;
// }

// int main() {
//     node<int>* intHead = nullptr;
//     Insert_AT_Tail(intHead, 1);
//     Insert_AT_Tail(intHead, 2);
//     Insert_AT_Tail(intHead, 3);
//     Insert_AT_Tail(intHead, 4);
//     Insert_AT_Tail(intHead, 5);

//     display(intHead);

//     if (isEmpty(intHead)) {
//         cout << "Integer linked list is empty" << endl;
//     } else {
//         int intFrontValue = GetFront(intHead);
//         int intTailValue = GetTail(intHead);

//         cout << "Integer Front Value: " << intFrontValue << endl;
//         cout << "Integer Tail Value: " << intTailValue << endl;
//     }

//     node<double>* doubleHead = nullptr;
//     Insert_AT_Tail(doubleHead, 1.1);
//     Insert_AT_Tail(doubleHead, 2.2);
//     Insert_AT_Tail(doubleHead, 3.3);
//     Insert_AT_Tail(doubleHead, 4.4);
//     Insert_AT_Tail(doubleHead, 5.5);

//     display(doubleHead);

//     if (isEmpty(doubleHead)) {
//         cout << "Double linked list is empty" << endl;
//     } else {
//         double doubleFrontValue = GetFront(doubleHead);
//         double doubleTailValue = GetTail(doubleHead);

//         cout << "Double Front Value: " << doubleFrontValue << endl;
//         cout << "Double Tail Value: " << doubleTailValue << endl;
//     }

//     return 0;
// }
