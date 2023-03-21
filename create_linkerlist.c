#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>

typedef struct node
{
    uint8_t data;
    struct node *next;
}node;

void addNode(node *ptr,uint8_t data){
    static uint8_t check =1;
    if(check ==1){

        ptr->data=data;
        ptr->next=NULL;
        check =0;
    }else{
        while (ptr->next !=NULL)
        {
            ptr=ptr->next;
        }
        
        node *newNode=(node *)malloc(sizeof(node));
        newNode->next=NULL;
        newNode->data=data;
        ptr->next=newNode;
    }
    
}void Display(node *node){
    printf("\n");
    while (node!=NULL)
    {
        printf("%d\n",node->data);
        node=node->next;

    }
    
}
int main(int argc, char const *argv[])
{
    node arr;
    addNode(&arr,5);
    addNode(&arr,7);
    addNode(&arr,8);
    addNode(&arr,10);
    addNode(&arr,15);
    addNode(&arr,30);
    addNode(&arr,16);
    Display(&arr);
    return 0;
}
