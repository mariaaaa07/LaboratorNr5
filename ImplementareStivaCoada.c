#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Verifică dacă stiva este plină
bool isFull() {
    return top == MAX - 1;
}

// Verifică dacă stiva este goală
bool isEmpty() {
    return top == -1;
}

// Adaugă un element în stivă
void push(int data) {
    if (isFull()) {
        printf("Eroare: Stiva este plină!\n");
    } else {
        stack[++top] = data;
        printf("Am adăugat %d în stivă.\n", data);
    }
}

// Scoate elementul din vârful stivei
int pop() {
    if (isEmpty()) {
        printf("Eroare: Stiva este goală!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Vizualizează elementul din vârf fără a-l scoate
int peek() {
    if (isEmpty()) return -1;
    return stack[top];
}

int main() {
    printf("--- Demo Stivă ---\n");
    push(10);
    push(20);
    push(30);
    
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

// Verifică dacă coada este plină
bool isFull() {
    return itemCount == MAX;
}

// Verifică dacă coada este goală
bool isEmpty() {
    return itemCount == 0;
}

// Adaugă un element la finalul cozii
void enqueue(int data) {
    if (isFull()) {
        printf("Eroare: Coada este plină!\n");
    } else {
        // Logică pentru coadă circulară simplă
        if (rear == MAX - 1) {
            rear = -1;
        }
        queue[++rear] = data;
        itemCount++;
        printf("Am adăugat %d în coadă.\n", data);
    }
}

// Scoate elementul din fața cozii
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

// Vizualizează primul element
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
