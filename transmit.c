#include <stdio.h>
int len(char *a){
  for(int i=0;;i++){
    if(a[i]=='\0'){
      return i;
    }
  }
}
char *transmit(char *uid,char *data){
  int i,j=0;
  int n1=len(uid);
  int n2=len(data);
  static char resuilt[sizeof(char)];
  for(i=0;i<n1;i++){
    resuilt[i]=uid[i];
  }
  for(i=n1;i<n1+n2;i++){
    resuilt[i]=data[j];
    j++;
  }
  resuilt[i]='\0';
  char *k=resuilt;
  return k;
}
int main(void)
{
  char *data;
  data=transmit((char*)"1010",(char*)"12345");
  printf("%s",data);
}
