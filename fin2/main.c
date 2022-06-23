#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList{
    char value;
    struct LinkedList *next, *prev;
}LinkedList;

LinkedList* allocNode(){
    LinkedList* node = malloc(sizeof(LinkedList));
    return node;
}
LinkedList* appendList(LinkedList* head, char val){
    if(head == NULL){
        head = allocNode();
        head->value = val;
        return head;
    }
    LinkedList* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = allocNode();
    tail->next->value = val; 
    tail->next->prev = tail;
    return head;
}
void showList(LinkedList* head){
    LinkedList* now = head;
    while(now->next != NULL){
        printf("[%c]->", now->value);
        now = now->next;
    }
    printf("[%c]->->NULL\n", now->value);
    return;
}
LinkedList* reverseList(LinkedList* head){
    if(head == NULL)
        return NULL;
    LinkedList* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    head = tail;
    while(tail->prev != NULL){
        LinkedList* temp;
        temp = tail->prev;
        tail->prev = tail->next;
        tail->next = temp;
        tail = tail->next;
    }
    tail->prev = tail->next;
    tail->next = NULL;
    return head;
}
int main()
{
    LinkedList* head = NULL;
    head = appendList(head, 'A');
    head = appendList(head, 'B');
    head = appendList(head, 'C');
    head = appendList(head, 'D');
    head = appendList(head, 'E');
    showList(head);
    head = reverseList(head);
    showList(head);
    return 0;
}
