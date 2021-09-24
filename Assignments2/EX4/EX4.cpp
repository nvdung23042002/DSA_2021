// EX4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// add element
void Enqueue(char queue[], char element, int& rear, int arraySize) {
    if (rear == arraySize)            // Queue is full
        cout << "Queue is FULL";
    else {
        queue[rear] = element;    // Add the element to the back
        rear++;
    }
}

// del first element
void Dequeue(char queue[], int& front, int rear) {
    if (front == rear)            // Queue is empty
        cout << "Queue empty";
    else {
        queue[front] = 0;        // Delete the front element
        front++;
    }
}

char Front(char queue[], int front) {
    return queue[front];
}


int main() {
    char queue[20] = { 'a', 'b', 'c', 'd' };
    int front = 0, rear = 4;
    int arraySize = 20;                // Size of the array
    int N = 3;                    // Number of steps
    char ch;
    for (int i = 0; i < N; ++i) {
        ch = Front(queue, front);
        Enqueue(queue, ch, rear, arraySize);
        Dequeue(queue, front, rear);
    }
    for (int i = front; i < rear; ++i)
        cout << queue[i];
    cout << endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
