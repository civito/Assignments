//2013011703_������ 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Up_Left 3
#define Left 2
#define Up 1

int c[1000][1000];
int b[1000][1000];

void LCS_Length(char* s1,char* s2)
{
   int m,n,i,j;
   m=strlen(s1)-1;
   n=strlen(s2)-1;
   for(i=1;i<=m;i++)
   {
      c[i][0]=0;
   }
   for(j=0;j<=n;j++)
   {
      c[0][j]=0;
   }
   for(i=1;i<=m;i++)
   {
      for(j=1;j<=n;j++)
      {
         if(s1[i]==s2[j])
         {
            c[i][j]=c[i-1][j-1]+1;
            b[i][j]=Up_Left;
         }
         else if(c[i-1][j]>=c[i][j-1])
            {
               c[i][j]=c[i-1][j];
               b[i][j]=Up;
            }
               
         else{
               c[i][j]=c[i][j-1];
               b[i][j]=Left;
            }
         
      }
   }
}

int Print_Lcs(char* s1,int i,int j)
{

   if(i==0 || j==0)
      return 0;
   if(b[i][j]==Up_Left)
   {
      Print_Lcs(s1,i-1,j-1);
      printf("%c",s1[i]);
   }
   else if(b[i][j]==Up)
   {
      
      Print_Lcs(s1,i-1,j);
   }
   else
      Print_Lcs(s1,i,j-1);
   return 0;
      
}
int main()
{
   int i;
   char s1[1000];
   char s2[1000];
   gets(s1);
   gets(s2);
   for(i=strlen(s1);i>0;i--)
   {
      s1[i]=s1[i-1];
   }
   for(i=strlen(s2);i>0;i--)
   {
      s2[i]=s2[i-1];
   }
   
   LCS_Length(s1,s2);
   Print_Lcs(s1,strlen(s1)-1,strlen(s2)-1);
   
   return 0;
}
