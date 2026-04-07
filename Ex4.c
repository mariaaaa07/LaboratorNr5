#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int coada[MAX];
int front = 0, rear = -1, nrElemCoadă = 0;

void enqueue(int x) {
    rear = (rear + 1) % MAX;
    coada[rear] = x;
    nrElemCoadă++;
}

int dequeue() {
    int x = coada[front];
    front = (front + 1) % MAX;
    nrElemCoadă--;
    return x;
}

int stiva[MAX];
int top = -1;

void push(int x) {
    stiva[++top] = x;
}

int pop() {
    return stiva[top--];
}

int main() {
    int x, i, j;
    srand(time(NULL)); 

    printf("Introduceți numărul de jucători: ");
    scanf("%d", &x);

    for (i = 1; i <= x; i++) {
        enqueue(i);
    }

    printf("\nÎncepe jocul!\n");

    while (nrElemCoadă > 0) {
        int hotPotato = (rand() % 10) + 1;
        
        for (j = 0; j < hotPotato - 1; j++) {
            enqueue(dequeue());
        }

        int eliminat = dequeue();
        printf("Jucătorul %d a prins cartoful fierbinte și a ieșit!\n", eliminat);
        
        push(eliminat);
    }

    printf("\nClasament (de la ultimul rămas la primul ieșit):\n");
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");

    return 0;
}
