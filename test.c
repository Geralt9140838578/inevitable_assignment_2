#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int rear = -1;
int select = 1;

void add_element(int data)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full. Cannot add more elements.\n");
        return;
    }
    queue[++rear] = data;
}

void remove_element(int position)
{
    if (position < 0 || position > rear)
    {
        printf("Invalid position.\n");
        return;
    }
    for (int i = position; i < rear; i++)
    {
        // printf("%d ,  is remove from the queue\n",position);
        queue[i] = queue[i + 1];
    }
    rear--;
}

void find_element(int data)
{
    for (int i = 0; i <= rear; i++)
    {
        if (queue[i] == data)
        {
            printf("yes %d is present in the list\n", queue[i]);
            return;
        }
    }
    printf("Element %d not found in the queue.\n", data);
}

void print_queue()
{
    if (rear == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = 0; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int rem = 100;

    while (1)
    {
        if (select == 1)
        {
            int x = 0, num = 0;
            printf(" ---->>Warning MSG !!!! Buffer size remaining %d <----\n Number of the element want to insert in the queue\n", rem);
            scanf("%d", &x);
            for (int i = 0; i < x; i++)
            {
                printf("Enter the number want to insert in queue \n");
                scanf("%d", &num);
                add_element(num);
            }
            rem = rem - x;
            print_queue();
        }
        printf("press\n 0--> for exit the program\n 1--> for enter more element in the queue\n 2-->for remove the element from the queue\n 3--> for search the element present in the queue\n");
        scanf("%d", &select);
        if (select == 2)
        {
            int X = 0;
            printf("which position element want to remove from the list\n");
            scanf("%d", &X);
            remove_element(X - 1);
            print_queue();
        }
        else if (select == 3)
        {
            while (1)
            {
                printf("enter the element want to find in the queue\n");
                int find = 0;

                scanf("%d", &find);
                find_element(find);
                print_queue();
                int z = 1;
                printf("---> Press 1 if you want to search more element in the queue<---\n---> press 0 if you dont want to search more element<--- \n");
                scanf("%d", &z);
                if (z == 0)
                    break;
            }
        }
        if (select == 0)
        {
            printf("--->THANK YOU !!!<----");
            return 0;
        }
    }
    return 0;
}