/*films2.c--使用链表进行数据存储*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TSIZE 45
typedef struct film{
    char title[TSIZE];
    int rating;
    struct film *next;    //指向链表的下一个结构
}films;

int main()
{
    films *head = NULL;
    films *current,*prev;
    char input[TSIZE];

    /*收集并存储信息*/
    puts("Enter first movie title:");
    while(gets(input) != NULL && input[0] != '\0')
    {
        current = (films *)malloc(sizeof(films));
        if (head == NULL)   /*第一个结构*/
            head = current;
        else
            prev->next = current;
        current->next = NULL;
        strcpy(current->title,input);
        puts("Enter you rating<0-10>:");
        scanf("%d",&current->rating);
        while(getchar() !='\n')
            continue;
        puts("Enter next movie title:");
        prev = current;
    }

    /*给出列表*/
    if(head == NULL)
        printf("Empty list!\n");
    else
        printf("Here are the lists of the movies:\n");
    current = head;
    while(current != NULL)
    {
        printf("The movie %s has a rating %d.\n",current->title,
            current->rating);
        current = current->next;
    }

    /*任务完成，释放链表*/
    current = head;
    while(current != NULL)
    {
        free(current);
        current = current->next;
    }

    printf(":::BYE:::");
    return 0;
    
}