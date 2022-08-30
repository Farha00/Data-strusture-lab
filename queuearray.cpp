#include<iostream>
using namespace std;
int n = 10;
class Queue {
private:
    int front;
    int rear;
    int arr[20];

public:
    Queue() {
        front = -1;
        rear = -1;
        for (int i = 0; i < n; i++) {
            arr[i] = 0;
        }
    }
    void enqueue(int val) {
        if (rear == n - 1)
        {
            cout << "Queue Overflow!!" << endl;
            return;
        }
        else if (front == -1 && rear == -1) {
            rear = 0;
            front = 0;
            arr[rear] = val;
        }
        else {
            rear++;
            arr[rear] = val;
        }

    }

    void dequeue() {
        int val;
        if (front == -1 && rear == -1)
        {
            cout << "Queue Underflow!!" << endl;

        }
        else if (rear == front) {
            val = arr[rear];
            rear = -1;
            front = -1;
            cout << "Element deleted from queue is : " << val << endl;
            front++;
        }
        else {
            cout << "front value: " << front << endl;
            val = arr[front];
            arr[front] = 0;
            cout << "Element deleted from queue is : " << val << endl;

            front++;
        }
    }


    void display() {
        if (front == -1)
        {
            cout << "Queue is empty!!" << endl;

        }
        else
            cout << "All elements  in the Queue are:" << endl;
        for (int i = 0; i < n; i++) {
            cout << arr[i] << "  ";
        }
        cout << "\nFront:" << front << endl;
        cout << "Rear:" << rear << endl;
        cout << endl;
    }

};

int main() {
    Queue q1;
    int value, option, ch;

    do {
        cout << "\tQUEUE USING ARRAY\t";
        cout << "\n";
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "Enter your choice : ";

        cin >> option;
        switch (option) {
        case 1:
            cout << "Enqueue Operation \nEnter an item to add in the Queue : " << endl;
            cin >> value;
            q1.enqueue(value);
            break;
        case 2:
            cout << "Dequeue Operation \nDequeued Value : " << endl;
            q1.dequeue();
            break;
        case 3:
            cout << "Display all elements in the queue" << endl;
            q1.display();
            break;
        default:
            cout << "Invalid option!!\n Try again " << endl;
        }
        cout << "Do you want to continue??\n1.Continue\n2.Exit\nEnter choice : ";
        cin >> ch;
    } while (ch != 0);

    return 0;
}