#include <stdio.h>

#define MAX 10

int vector[MAX];
int top1 = -1;        
int top2 = MAX;      


void push1(int valoare) {
    if (top1 < top2 - 1) {
        top1++;
        vector[top1] = valoare;
        printf("Stiva 1: Am adăugat %d\n", valoare);
    } else {
        printf("Eroare: Nu mai e loc în vector pentru Stiva 1!\n");
    }
}

int pop1() {
    if (top1 >= 0) {
        int v = vector[top1];
        top1--;
        return v;
    } else {
        printf("Stiva 1 este goală!\n");
        return -1;
    }
}


void push2(int valoare) {
    if (top1 < top2 - 1) {
        top2--;
        vector[top2] = valoare;
        printf("Stiva 2: Am adăugat %d\n", valoare);
    } else {
        printf("Eroare: Nu mai e loc în vector pentru Stiva 2!\n");
    }
}

int pop2() {
    if (top2 < MAX) {
        int v = vector[top2];
        top2++;
        return v;
    } else {
        printf("Stiva 2 este goală!\n");
        return -1;
    }
}


int main() {
    printf("--- Umplem Stivele ---\n");
    push1(10);
    push1(20);
    push2(100);
    push2(200);
    push1(30); 

    printf("\n--- Golim Stivele ---\n");
    printf("Pop din Stiva 1: %d\n", pop1());
    printf("Pop din Stiva 2: %d\n", pop2());

    return 0;
}
