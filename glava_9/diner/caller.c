#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int main()
{
    char *my_env[] = {"JUICE=персик и яблоко", NULL};
    execle("./test_diner", "test_diner", "4", NULL, my_env);
    
    perror("Ошибка execle");
    return 1;
}