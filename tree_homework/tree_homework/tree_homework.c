#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning(disable : 4996)

#include "Utilities_achiya.h"

struct datalist
{
    int age;
};

struct child
{
    // management or metaData
    int level;
    struct child* left;
    struct child* right;
    struct child* parent;

    // data (real data)
    struct datalist data;
}; 

struct child* root = NULL;

// מבנה להגדרת רשימה מקושרת מסוג תור
struct queueItem
{
    int id;
    struct queueItem* next;
    struct queueItem* prev;

    struct child* dataChild;
};

struct queueItem* queue_Head;
struct queueItem* queue_tail;



void AddItem(struct datalist item);
void Queue_Push(struct child* dataChild);
struct queueItem* Queue_Pop();
void Queue_Clear();
void BuildTree();
struct child* FindEmptyPlaceLeaf(struct child* dataChild);
int Queue_IsEmpty();

void log_init(char filename[1000]);



int main()
{   
    time_t t = time(&t);
    srand(t);
    
    /*
    datalist detail1;
    detail1.age = 11;
    AddItem(detail1);

    datalist detail2;
    detail2.age = 12;
    AddItem(detail2);

    datalist detail3;
    detail3.age = 13;
    AddItem(detail3);
    */

    root = NULL;
    queue_tail = NULL;
    queue_Head = NULL;

    BuildTree();

    Queue_Push(NULL);
    Queue_Push(NULL);
    Queue_Push(NULL);
    Queue_Pop();
    Queue_Pop();
    Queue_Pop();
    Queue_Clear();

    
    
    struct child leaf;
    struct child* leafPtr = (struct child*)malloc(sizeof(struct child));

    leaf.data.age = 23;
    leafPtr->data.age = 23;

    //strcpy(leaf.Details.address, "dafsdfsdf");

    return 0;
}

void AddItem(struct datalist item)
{
    struct child* newLeaf = (struct child*)malloc(sizeof(struct child));
    newLeaf->data = item;
    newLeaf->right = NULL;
    newLeaf->left = NULL;

    /*
    currnt->data.age = 23;
    strcpy(currnt->data.name, "hjghkl")
    //(rand() % 100) + 1;
    */

    if (root == NULL)
    {
        newLeaf->parent = NULL;
        root = newLeaf;
        newLeaf->level = 0;
    }
    else 
    {
        struct queueItem* queue_current;
        struct child* foundEmptyPlace = NULL;
        //newLeaf->level = data->age;
        Queue_Push(root);

        while ((queue_current = Queue_Pop()) != NULL)
        {
            foundEmptyPlace = NULL;
            if (queue_current->dataChild->left == NULL)
            {
                foundEmptyPlace = queue_current->dataChild;
                foundEmptyPlace->left = newLeaf;
                newLeaf->parent = foundEmptyPlace;
                newLeaf->level = 1;
            }
            else if (queue_current->dataChild->right == NULL)
            {
                foundEmptyPlace = queue_current->dataChild;
                foundEmptyPlace->right = newLeaf;
                newLeaf->parent = foundEmptyPlace;
                newLeaf->level = 1;
            }

        }
    }


}

void Queue_Push(struct child* dataChild)
{
    struct queueItem* newQitem = (struct queueItem*)malloc(sizeof(struct queueItem));
    newQitem->dataChild = dataChild;
    newQitem->next = NULL;

    if (queue_Head == NULL)
    {
        queue_Head = newQitem;
        queue_tail = newQitem;
        newQitem->next = NULL;
        newQitem->prev = NULL;
    }
    else
    {
        queue_Head->next = newQitem;
        newQitem->prev = queue_Head;
        queue_Head = newQitem;
    }

}

struct queueItem* Queue_Pop()
{
    struct queueItem* ret = NULL;

    if (queue_Head == NULL)
    {
        return NULL;
    }
    else if (queue_Head == queue_tail)
    {
        ret = queue_Head;
        queue_Head = NULL;
        queue_tail = NULL;
        return ret;
    }
    else
    {
        ret = queue_tail;
        queue_tail->next->prev = NULL;
        queue_tail = queue_tail->next;
        return ret;
    }

}

void Queue_Clear()
{
    queue_Head = NULL;
    queue_tail = NULL;
}

void BuildTree()
{
    for (int i = 0; i < 10; i++)
    {
        struct datalist* data = (struct datalist*)malloc(sizeof(struct datalist));
        data->age = i;

        AddItem(*data);
    }
}

struct child* FindEmptyPlaceLeaf(struct child* dataChild)
{
    if (dataChild->left != NULL)
    {
        return dataChild->left;
    }
    else if (dataChild->right != NULL)
    {
        return dataChild->right;
    }
    else
    {
        return NULL;
    }
}

int Queue_IsEmpty()
{
    if (queue_Head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}