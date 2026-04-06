#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Structura pentru Coadă (folosită pentru joc)
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

// Structura pentru Stivă (folosită pentru salvarea ordinii inverse)
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
    srand(time(NULL)); // Inițializăm generatorul de numere random

    printf("Introduceți numărul de jucători: ");
    scanf("%d", &x);

    // 1. Punem toți jucătorii în coadă (jucătorul 1, 2, ..., x)
    for (i = 1; i <= x; i++) {
        enqueue(i);
    }

    printf("\nÎncepe jocul!\n");

    // Jocul continuă până când rămâne un singur jucător
    while (nrElemCoadă > 0) {
        // Generăm un număr random de "pasări" ale cartofului (între 1 și 10)
        int hotPotato = (rand() % 10) + 1;
        
        // Mutăm jucătorii de la început la final de 'hotPotato - 1' ori
        for (j = 0; j < hotPotato - 1; j++) {
            enqueue(dequeue());
        }

        // Jucătorul care a rămas cu cartoful (al 'hotPotato'-lea) este eliminat
        int eliminat = dequeue();
        printf("Jucătorul %d a prins cartoful fierbinte și a ieșit!\n", eliminat);
        
        // Îl salvăm în stivă pentru afișarea finală
        push(eliminat);
    }

    // 2. Afișăm rezultatele în ordine inversă (folosind stiva)
    printf("\nClasament (de la ultimul rămas la primul ieșit):\n");
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");

    return 0;
}
