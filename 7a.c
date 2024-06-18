#include<stdio.h>
#include <setjmp.h>
jmp_buf buf;
void foo()
{
        int regular_var = 10;
        volatile int vol_var = 20;
        register int reg_var = 30;
        printf("Inside foo():\n");
        printf("Regular variable: %d\n",regular_var);
        printf("vol:%d\n",vol_var);
        printf("%d \n",reg_var);
        longjmp(buf,1);
}
int main()
{
        int regular_var = 1;
        volatile int vol_var =2;
        register int reg_var=3;
        printf("Before longjmp:\n");
         printf("Regular variable: %d\n",regular_var);
         printf("vol:%d\n",vol_var);
         printf("%d \n",reg_var);
         if(setjmp(buf)==0) // first time this executes it will return 0
         {
                 foo();
         }else
         {
                 printf("after longjmp:\n");
                 printf("Regular variable: %d\n",regular_var);                                                           printf("vol:%d\n",vol_var);                                                                             printf("%d \n",reg_var);
         }
         return 0;
}
