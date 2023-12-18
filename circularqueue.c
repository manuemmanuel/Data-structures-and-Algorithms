#include <stdio.h>
int rear = -1, front = -1, queue[20], max;
int enqueue(int item);
int dequeue();
int display();
void main() {
    int choice, num, k = 1;
    printf("Enter the maximum size of the queue: ");
    scanf("%d", &max);
    while (k != 0) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter a choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter a number: ");
            scanf("%d", &num);
            enqueue(num);
        } 
        else if (choice == 3) {
            display();
        } 
        else if (choice == 2) {
            dequeue();
        } 
        else if (choice == 4) {
            break;
        }
    }
}
int enqueue(int item) {
    if ((front == 0 && rear == max - 1) || (rear == front - 1 && front != -1)) {
        printf("\nOVERFLOW\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % max;
        queue[rear] = item;
    }
}
int dequeue() {
    if (front == -1) {
        printf("\nThe queue is EMPTY.\n");
    } else {
        printf("The dequeued element is %d", queue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % max;
        }
    }
}
int display() {
    printf("The queue is: \n");
    int i = front;
    while (i != rear) {
        printf("%d/", queue[i]);
        i = (i + 1) % max;
    }
    printf("%d",queue[i]);
    printf("\nRear: %d",rear);
    printf("\nFront: %d",front);
}
