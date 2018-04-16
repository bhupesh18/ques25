#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
void case_changer(char buffer3[100]);

void case_changer(char buffer3[100])
{
     int i=0;
     int length=strlen(buffer3);
     for(i=0;i<length;i++)
     {
         char check;
          check=buffer3[i]; 
         if((check>='A')&&(check<='Z'))
             buffer3[i]=(check+32);
         else if((check>='a')&&(check<='z'))
              buffer3[i]=(check-32);   
         
         printf("%c",buffer3[i]);  
      
    }
      
}
int main()
{
       int size;
       int pd[2];
       pipe(pd);  
       char buffer[100];
       write(1,"PLEASE ENTER THE INPUT = ",25);
       size=read(0,buffer,100);
       printf("YOUT INPUT IS = %s",buffer);
       pid_t p;
       p=fork();
       if(p>0)
       { 
             close(pd[0]);
             write(pd[1],buffer,1000);    
       }     
       else
       {
             close(pd[1]);
             char buffer2[100];
             strcpy(buffer2,buffer);
             int data = read(pd[0],buffer2,100);  
             case_changer(buffer2);   
       } 
      return 0;
}
