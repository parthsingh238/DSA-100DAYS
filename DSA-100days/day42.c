#include <stdio.h>

#define MAX 100

int queue[MAX];
int stack[MAX];
int front = 0, rear = -1;
int top = -1;

int main() {
    int n,i,x;

    scanf("%d",&n);

    // enqueue elements
    for(i=0;i<n;i++){
        scanf("%d",&x);
        queue[++rear] = x;
    }

    // queue -> stack
    while(front <= rear){
        stack[++top] = queue[front++];
    }

    // stack -> queue
    front = 0;
    rear = -1;

    while(top >= 0){
        queue[++rear] = stack[top--];
    }

    // print reversed queue
    for(i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }

    return 0;
}