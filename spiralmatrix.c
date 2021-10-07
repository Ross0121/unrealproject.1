#include <stdio.h>
int spiralarray(int n);
int prime_comp(int n);

int main()
{ 
  int n;
  printf("enter the value of n = ");
  scanf("%d",&n);
  if(n>0)
  {
  spiralarray(n);
  }
  else
  {
  printf("Invalid input.");
  }

  return 0;
}
int prime_comp(int n)
{
  int check=0,i=2;
  while(i<=n/2)
  {
      if(n%i==0)
         check++;
      i++;
  }
  if(check==0)
  return 1;
  
  else
  return 0;
  
}
  
int spiralarray(int n)
{
   int i,p=0,c=0;
   int prime[2000];
   int comp[2000];
   for(i=2;i<=2000;i++)
   {
       if(prime_comp(i)==1)
       {
           prime[p]=i;
           p++;
       }
       else
       {
           comp[c]=i;
           c++;
       }
   }
   p=0;
   c=0;
   
   int rows,column,r=0,s=0,a=1,j;
   rows=n;
   column=n;
   int arr[n][n];
   while((r<rows)&&(s<column))
   {
      i=s;
      while(i<column)
      {
         if(a%2==1)
         {
             arr[r][i]=prime[p++];
         }
         else
         {
             arr[r][i]=comp[c++];
         }
         a++;
         i++;
      }
      r++;
      i=r;
     while(i<rows)
      {
          if(a%2==1)
          {
              arr[i][column-1]=prime[p++];
          }
          else
          {
              arr[i][column-1]=comp[c++];
          }
          a++;
          i++;
      }
      column--;
      if(r<rows)
      {
          i=column-1;while(i>=s)
          {
              if(a%2==1)
              {
                  arr[rows-1][i]=prime[p++];
              }
              else
              {
                  arr[rows-1][i]=comp[c++];
              }
              a++;i--;
          }
          rows--;
      }
      
      if(s<column)
      {
          i=rows-1;
          while(i>=r)
          {
              if(a%2==1)
              {
                  arr[i][s]=prime[p++];
              }
              else
              {
                arr[i][s]=comp[c++];
              }
              a++;i--;
          }
          s++;
      }
   }
  for(i=0;i<n;i++)
  {
      for(j=0;j<n;j++)
      {
          printf("%d\t",arr[i][j]);
      }
      printf("\n");
  }
  return 0;  
}
