#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
    //adds 1 to count for each node, stopping when reaching the end of the list
    int count = 0;
    node* curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}


// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head)
{
    char* string1 = malloc((length(head) + 1) * sizeof(char));
    node* curr = head;
    
    //traverse the list, add the letter in each node to string1
    int i = 0;
    while (curr != NULL)
    {
        string1[i] = curr->letter;
        curr = curr->next;
        i++;
    }
    string1[i] = '\0';
    return string1;
}


// inserts character to the linkedlist
// if the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    node* newNode = malloc(sizeof(node));
    newNode->letter = c;
    newNode->next = NULL;

    //if pHead is empty, then set it to newNode, because it is the end of the list
    if (*pHead == NULL)
    {
        *pHead = newNode;
    } 

    //traverse to the end of the list, insert newNode
    else
    {
        node* curr = *pHead;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}


// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    node* curr = *pHead;
    //frees each node while traversing through the list
    while (curr != NULL)
    {
        node* temp = curr->next;
        free(curr);
        curr = temp;
    }
    *pHead = NULL;
}


int main(void)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt","r");
    fscanf(inFile, " %d\n", &numInputs);
    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile," %c", &c);
            insertChar(&head, c);
        }
        str = toCString(head);
        printf("String is : %s\n", str);
        free(str);
        deleteList(&head);
        if (head != NULL)
        {
            printf("deleteList is not correct!");
            break;
        }
    }
    fclose(inFile);
}