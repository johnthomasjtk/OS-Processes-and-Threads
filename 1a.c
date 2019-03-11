#include<stdio.h>
#include<stdlib.h> 
int main()
{
printf("PATH = %s\n", getenv("PATH"));
printf("USER = %s\n", getenv("USER"));
printf("HOME = %s\n", getenv("HOME"));
printf("PWD  = %s\n", getenv("PWD"));
return (0);
}
