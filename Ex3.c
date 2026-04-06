#include <stdio.h>

#define MAX 10

// Definim structura unei stive simple
int stiva1[MAX], top1 = -1;
int stiva2[MAX], top2 = -1;

// Operații de bază pentru stivă
void push1(int val) { stiva1[++top1] = val; }
int pop1() { return stiva1[top1--]; }

void push2(int val) { stiva2[++top2] = val; }
int pop2() { return stiva2[top2--]; }

// --- OPERAȚIILE PENTRU COADĂ ---

// 1. Enqueue (Adăugarea) - Punem mereu în prima stivă
void enqueue(int x) {
    if (top1 == MAX - 1) {
        printf("Coada este plină!\n");
        return;
    }
    push1(x);
    printf("Am adăugat %d în coadă.\n", x);
}

// 2. Dequeue (Scoaterea) - Magia se întâmplă aici
int dequeue() {
    // Dacă ambele stive sunt goale, coada e goală
    if (top1 == -1 && top2 == -1) {
        printf("Coada este goală!\n");
        return -1;
    }

    // Dacă stiva2 este goală, mutăm tot din stiva1 în stiva2
    // Asta va inversa ordinea elementelor!
    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }
    }

    // Acum scoatem din stiva2 (care are elementele în ordinea corectă de coadă)
    return pop2();
}

int main() {
    printf("--- Demo Coadă cu 2 Stive ---\n");
    
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Am scos: %d\n", dequeue()); // Ar trebui să scoată 10
    printf("Am scos: %d\n", dequeue()); // Ar trebui să scoată 20
    
    enqueue(40);
    printf("Am scos: %d\n", dequeue()); // Ar trebui să scoată 30
    printf("Am scos: %d\n", dequeue()); // Ar trebui să scoată 40

    return 0;
}
