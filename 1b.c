#include<stdio.h>
#include<stdlib.h> 
int main()
{

setenv("ROOT","root","1");
printf("ROOT = %s\n", getenv("ROOT"));
printf("PATH = %s\n", getenv("PATH"));
printf("USER = %s\n", getenv("USER"));
printf("HOME = %s\n", getenv("HOME"));
printf("PWD  = %s\n", getenv("PWD"));
return (0);
}
