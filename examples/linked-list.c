#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

//allocate a new Node
Node* makeNode(int data)
{
    Node* temp = malloc(sizeof(Node));
    temp->data = data; 
    return temp;
}

//insert a Node to given list 
Node* insertNode(Node** list, Node* node)
{
    node->next = *list;
    return node;
}

//size_t findListSize(Node* head)
//{
//    size_t n;
//    
//    while(head != NULL)
//    {
//       n++;
//       head = head->next;
//    }
//    return n;
//}

size_t findListSize(Node* head)
{
    if(head == NULL)
    {
        return 0;
    }
    return 1 + findListSize(head->next);

}

void printList(Node* list)
{
    printf("List: ");
    while(list)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

void deleteIndex(Node** list, size_t n)
{
    Node* prev;
    Node* curr;
    prev = *list;
    curr = *list;
    for(size_t i=0; i < n; ++i)
    {
        prev = curr;    
        curr = curr->next;
    }
    prev->next = curr->next;
}
void deleteVal(Node** list, int val)
{
    Node* prev;
    Node* curr;
    prev = *list;
    curr = *list;
    while(curr != NULL)
    {
        if(curr->data == val){
            break;
        }
        prev = curr;    
        curr = curr->next;
    }
    prev->next = curr->next;
}


int main()
{
    Node* list;

    list = makeNode(0);
    for(int i=1; i < 42; i++)
    {
        insertNode(&list, makeNode(i));
    }
    deleteIndex(&list, 5);
    deleteIndex(&list, 14);

    printf("list size: %ld\n", findListSize(list));
    printList(list);
    


    return 0;
}
