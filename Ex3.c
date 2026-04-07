#include <stdio.h>

#define MAX 10

int stiva1[MAX], top1 = -1;
int stiva2[MAX], top2 = -1;

void push1(int val) { stiva1[++top1] = val; }
int pop1() { return stiva1[top1--]; }

void push2(int val) { stiva2[++top2] = val; }
int pop2() { return stiva2[top2--]; }


void enqueue(int x) {
    if (top1 == MAX - 1) {
        printf("Coada este plină!\n");
        return;
    }
    push1(x);
    printf("Am adăugat %d în coadă.\n", x);
}

int dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Coada este goală!\n");
        return -1;
    }

    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }
    }

    return pop2();
}

int main() {
    printf("--- Demo Coadă cu 2 Stive ---\n");
    
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Am scos: %d\n", dequeue()); 
    printf("Am scos: %d\n", dequeue()); 
    
    enqueue(40);
    printf("Am scos: %d\n", dequeue()); 
    printf("Am scos: %d\n", dequeue()); 

    return 0;
}
