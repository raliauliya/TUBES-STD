#ifndef KORAKORA_H_INCLUDED
#define KORAKORA_H_INCLUDED

#include <iostream>

using namespace std;

#define Top(K) (K).Top      // stack
#define infoS(K) (K).infoS  // stack
#define infoQ(K) (K)->infoQ // queue
#define next(K) (K)->next   // queue
#define head(K) ((K).head)  // queue
#define tail(K) ((K).tail)  // queue

struct KoraKora
{
    string nama;
    int ticketID;
};

// stack
struct stack
{
    KoraKora infoS[100];
    int Top;
};

// queue
typedef struct elmtQueue *adrQueue;

struct elmtQueue
{
    KoraKora infoQ;
    adrQueue next;
};

struct queue
{
    adrQueue head;
    adrQueue tail;
};

// stack
void createStack(stack &S);
bool isEmptyS(stack S);
bool isFull(stack S);
void push(stack &S, string nama, int ticketID);
void pop(stack &S);
void printInfoS(stack S);

// queue

void createQueue(queue &Q);
bool isEmptyQ(queue &Q);
void createElementQ(KoraKora antrianBaru, adrQueue &P);
void enqueue(queue &Q, adrQueue P);
KoraKora dequeue(queue &Q, adrQueue P);
void printInfoQ(queue Q);

#endif // KORAKORA_H_INCLUDED
