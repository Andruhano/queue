#include <iostream>
using namespace std;

template<typename T>
class Queue 
{
    struct Node 
    {
        T data;
        Node* next;
        Node* prev;
        Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t size;

public:
    Queue() : head(nullptr), tail(nullptr), size(0) {}

    ~Queue() 
    {
        while (head) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(const T& value) 
    {
        Node* newNode = new Node(value);
        if (!tail) 
        {
            head = tail = newNode;
        }
        else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void pop() 
    {
        if (!head) 
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete temp;
        size--;
    }

    T front() const 
    {
        if (!head) 
        {
            cout << "Queue is empty!" << endl;
        }
        return head->data;
    }

    T back() const 
    {
        if (!tail) 
        {
            cout << "Queue is empty!" << endl;
        }
        return tail->data;
    }

    bool isEmpty() const 
    {
        return size == 0;
    }

    size_t getSize() const 
    {
        return size;
    }
};

int main() 
{
    Queue<int> q;
    q.add(1);
    q.add(2);
    q.add(3);

    cout << "Front of queue: " << q.front() << endl;
    cout << "Back of queue: " << q.back() << endl;
    cout << "Queue size: " << q.getSize() << endl;

    q.pop();
    cout << "Front of queue after pop: " << q.front() << endl;
    cout << "Queue size after pop: " << q.getSize() << endl;

    return 0;
}
