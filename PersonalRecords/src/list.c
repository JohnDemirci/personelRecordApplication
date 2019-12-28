#include "list.h"

void add(LIST **head, LIST **tail, void *data)
{
    if (*tail == NULL)
    {
        *head = *tail = (LIST *) malloc(sizeof(LIST));
        (*head)->data = data;
        (*head)->next = NULL;
    } else
    {
        (*tail)->next = (LIST *) malloc(sizeof(LIST));
        *tail = (*tail)->next;
        (*tail)->data = data;
        (*tail)->next = NULL;
    }
}

void clearIteratively(LIST **head, LIST **tail)
{
    printf("pld work");
    if (*head == NULL)
        return;

    LIST *currNode = *head;
    LIST *nextNode = NULL;

    do
    {
        nextNode = currNode->next;

        if (currNode->data != NULL)
            free(currNode->data);

        free(currNode);

        currNode = nextNode;

    } while (currNode != NULL);

    *head = NULL;
    *tail = NULL;
}

void clearRecursively(LIST **currNode, LIST **tail)
{
    if (*currNode == NULL || *tail == NULL)
        return;

    LIST *nextNode;
    
    // TODO Complete this function

    nextNode = (*currNode)->next;
    free((*currNode)->data);
    free((*currNode));

    clearRecursively(&nextNode, tail);

    *currNode = NULL;
    *tail = NULL;
}

void delete(LIST **head, LIST **tail, void *data)
{
    if (*head == NULL)
        return;

    if (data == NULL)
        return;

    if ((*head)->data == data)
    {
        LIST *newHead = (*head)->next;
        free((*head)->data);
        free(*head);
        *head = newHead;

        if (*head == NULL)
            *tail = NULL;

        return;
    }

    LIST *prevNode, *currNode;

    prevNode = (*head);
    currNode = (*head)->next;
    while (currNode != NULL)
    {
        // TODO Complete this function
        // mistake here
        if (currNode->data == data) {
            prevNode->next = currNode->next;
            if (currNode->data == (*tail)->data) {
                *tail = prevNode;
            }
            // free stuff here
            free(currNode->data);
            free(currNode);

        }
        currNode = currNode->next;
        prevNode = prevNode->next;

    }
}