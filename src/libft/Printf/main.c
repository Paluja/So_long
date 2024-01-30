#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
int main (void)
{
    char *ptr = "hola";
    int klk = write(1,"D",1);
    ft_printf(" Formato d e i hola %d la verdad que %d si no\n",klk,-6);
    ft_printf(" Formato c %c Formato 2c %c\n",'a','X');
    ft_printf(" NULL %s NULL \n", NULL);
    // printf(" NULL %s NULL \n", NULL);
    ft_printf(" %p \n", -1);
    printf("Printf formato P pero el de verdad %p\n",ptr);
    ft_printf(" Formato u %u\n",45);
    ft_printf(" %x ", -1);
    // printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    ft_printf(" %x ", -1);
    ft_printf(" Formato %%\n");
    // ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);


}