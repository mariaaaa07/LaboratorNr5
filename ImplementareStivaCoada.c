#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int stack[MAX];
int top = -1;
int valoare = peek();
bool isFull() {
    return top == MAX - 1;
}

bool isEmpty() {
    return top == -1;
}

void push(int data) {
    if (isFull()) {
        printf("Eroare: Stiva este plină!\n");
    } else {
        stack[++top] = data;
        printf("Am adăugat %d în stivă.\n", data);
    }
}

int pop() {
    if (isEmpty()) {
        printf("Eroare: Stiva este goală!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int peek() {
    if (isEmpty()) return -1;
    return stack[top];
}



int main() {
    printf("--- Demo Stivă ---\n");
    push(10);
    push(20);
    push(30);
    push(200);
    printf("Elementul din vârf (peek): %d\n", peek());
    printf("Am scos (pop): %d\n", pop());
    printf("Stiva este goală? %s\n", isEmpty() ? "Da" : "Nu");

    
#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int queue[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

bool isFull() {
    return itemCount == MAX;
}

bool isEmpty() {
    return itemCount == 0;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Eroare: Coada este plină!\n");
    } else {
        if (rear == MAX - 1) {
            rear = -1;
        }
        queue[++rear] = data;
        itemCount++;
        printf("Am adăugat %d în coadă.\n", data);
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Eroare: Coada este goală!\n");
        return -1;
    } else {
        int data = queue[front++];
        if (front == MAX) {
            front = 0;
        }
        itemCount--;
        return data;
    }
}

int peek() {
    if (isEmpty()) return -1;
    return queue[front];
}

int main() {
    printf("\n--- Demo Coadă ---\n");
    enqueue(100);
    enqueue(200);
    enqueue(300);
    
    printf("Primul element (peek): %d\n", peek());
    printf("Am scos din coadă (dequeue): %d\n", dequeue());
    printf("Coada este plină? %s\n", isFull() ? "Da" : "Nu");
    
    return 0;
}
    
    return 0;
}
