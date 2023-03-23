#include<stdio.h>
#include<string.h>
void sum(int a,int b){
    printf("%d + %d=%d",a,b,a+b);
}
void sub(int a,int b){
    printf("%d - %d=%d",a,b,a-b);
}
int main(int argc, char const *argv[])
{
    int intArr[]={2,5,7,8};
    char charArr[]="hello world";
    
    double doubleArr[]={4.6,3.6,3.6,2.9,2.4};
    void (*funtionArr[])(int,int)={&sum,&sub};
    void *arr[4]={intArr,charArr,doubleArr,funtionArr};
    for(int i=0;i<4;i++){
        printf("%d\t",((int *)arr[0])[i]);
    }
    printf("\n");
    for(int i=0;i<strlen(arr[1]);i++){
            printf("%c",((char*)arr[1])[i]);
    }
    printf("\n");
    for(int i=0;i<5;i++){
    printf("%f\t",((double*)arr[2])[0]);
    }
    printf("\n");
    ((void (*)(int,int))(((void **)arr[3])[0]))(10,2);
    printf("\n");
    ((void (*)(int,int))(((void **)arr[3])[1]))(9,2);
    return 0;
}
