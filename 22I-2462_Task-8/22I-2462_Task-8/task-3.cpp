#include <iostream>
using namespace std;
class Queue
{
public:
    int *arr;
    int front;
    int rear;
    int TotalCapacity;
    int size;

    Queue()
    {
    }
    Queue(int TotalCapacity)
    {
        this->TotalCapacity = TotalCapacity;
        arr = new int[TotalCapacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    void Enqueue(int x)
    {
        if (IsFull() == true)
            cout << "Queue is full" << endl;
        else
        {
            rear = (rear + 1) % TotalCapacity;
            arr[rear] = x;
            size++;
        }
    }

    void Dequeue()
    {
        if (IsEmpty() == true)
            cout << "Queue is empty" << endl;
        else
        {
            front = (front + 1) % TotalCapacity;
            size--;
        }
    }

    bool IsEmpty()
    {
        return size == 0;
    }

    int getFront()
    {
        if (IsEmpty() == true)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    void reverse()
    {
        for (int i = 0; i < size / 2; i++)
        {
            int temp = arr[(front + i) % TotalCapacity]; // gets index from the front
            arr[(front + i) % TotalCapacity] = arr[(front + size - i - 1) % TotalCapacity]; //gets index from last
            arr[(front + size - i - 1) % TotalCapacity] = temp;
        }
    }

    void Display()
    {
        if (IsEmpty() == true)
            cout << "Queue is empty" << endl;
        else
        {
            for (int i = 0; i < size; i++)
            {
                cout << arr[(front + i) % TotalCapacity] << " ";
            }
            cout << endl;
        }
    }

    bool IsFull()
    {
        return size == TotalCapacity;
    }
};

int main()
{
    int TotalCapacity;
    Queue q(TotalCapacity);

    cout << "Enter the number of elements: ";
    int x;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        int y;
        cout << "Enter element: ";
        cin >> y;
        q.Enqueue(y);
    }

    q.reverse();

    cout << "Reversed queue is: ";
    q.Display();

    return 0;
}