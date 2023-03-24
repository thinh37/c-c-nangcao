#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>

typedef struct node
{
    uint8_t data;
    struct node *next;
}node;
node *newNode(int data){
    node *new=(node *)malloc(sizeof(node));
    new->next=NULL;
    new->data=data;
    return new;
}
void push_back(node *ptr,uint8_t data){
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
        
        
        ptr->next=newNode(data);
    }
    
}void Display(node *ptr){
    printf("\n");
    while (ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}
void assign (node *ptr,int index,int x){
    int i = 0;
    while (ptr->next != NULL && i != index)
    {
        i++;
        ptr= ptr->next;
    }
    ptr->data=x;
}
node *pop_back(node *ptr){
        while (ptr->next->next != NULL)
        {
            ptr=ptr->next;
        }
       ptr->next=NULL;
    return ptr;

}

node *erase(node *ptr,int index){
    int i=0;
    if(index==0){
        ptr->data=ptr->next->data;
        index=1;
    }
    
    while (ptr->next!=NULL&& i != (index-1))
    {
        i++;
        ptr=ptr->next;
    }
    ptr->next=ptr->next->next;
    return ptr;
}
void clear(node *ptr){
    node *temp=ptr;
    while(ptr->next!=NULL){
        temp=temp->next;
        free(ptr);
        temp=ptr;
    }
    free(ptr);
}
uint8_t getData(node *ptr, int index){
    int i=0;
    while (ptr->next!=NULL)
    {
        if(i==index) return (ptr->data); 
        ptr=ptr->next;
        i++;
    }
    if(index>i) return 0;
    return ptr->data;
}
int main(int argc, char const *argv[])
{
    node arr;
    int x;
    for(int i=0;i<7;i++){
        printf("Nhap node %d:",i);
        scanf("%d",&x);
        push_back(&arr,x);
    }
   printf("DANH SACH SAU KHI NHAP:");
    Display(&arr);
    printf("\nXOA PHAN TU CUOI:");
    pop_back(&arr);
    Display(&arr);
    printf("\nXOA PHAN TU VI TRI 0");
    erase(&arr,0);
    Display(&arr);
    printf("\nXOA PHAN TU VI TRI 4");
    erase(&arr,4);
    Display(&arr);
    printf("\nTHAY DOI GIA TRI VI TRI 2");
    assign(&arr,2,99);
    Display(&arr);
    printf("LAY GIA TRI TAI VI TRI 3 LA: %d",getData(&arr,2));
    printf("\nXOA-KET THUC");
    clear(&arr);
    Display(&arr);
    return 0;
}
