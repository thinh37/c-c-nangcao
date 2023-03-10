#include <stdio.h>
#include <stdarg.h>
void convertStringtoBin(char *a){
int i,j;
for( i=0;;i++){
  if(a[i]=='\0'){
      break;
    }
  char temp[7];
  int t=a[i];
  for(j=6;j>=0;j--){
    if(t%2==0){
      temp[j]='0';
    }else{
      temp[j]='1';
    }
    t=t/2;
  }
  printf("%c: %s\n",a[i],temp);
}
}
int main(void)
{
  convertStringtoBin("my name is thinh");
}
