#include<stdio.h>

int main()
{
    unsigned short int a=0,b=0; //declaring unsigned 16 bit integer 
    printf("Enter two numbers:\n");
    scanf("%hu",&a);
    scanf("%hu",&b);

  int cnt=0;
  for(int i=0;i<16;i++) //counting matched indices of two nos
    {
      if((a&(1<<i))==(b&(1<<i)))
      cnt+=1;;
    }
    
  if(cnt>12)         //checking the given condition
    printf("1\n");
  else 
    printf("0\n");
    
  return 0;
}
