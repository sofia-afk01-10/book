#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int status;
    pid_t pid;

    printf("=== Фрагмент 1 ===\n");
    pid = fork();
    if (pid == 0) {
        char *my_env[] = {"FOOD=кофе", NULL};
        execle("./coffee", "./coffee", "пончики", NULL, my_env);
        fprintf(stderr, "Не могу запустить процесс: %s\n", strerror(errno));
        return 1;
    }
    wait(&status);
    
    printf("\n=== Фрагмент 2 ===\n");
    pid = fork();
    if (pid == 0) {
        char *my_env[] = {"FOOD=пончиками", NULL};
        execle("./coffee", "./coffee", "сливки", NULL, my_env);
        fprintf(stderr, "Не могу запустить процесс: %s\n", strerror(errno));
        return 1;
    }
    wait(&status);
    
    printf("\n=== Фрагмент 3 ===\n");
    pid = fork();
    if (pid == 0) {
        char *my_env[] = {"FOOD=кофе", NULL};
        execle("./coffee", "кофе", NULL, my_env);
        fprintf(stderr, "Не могу запустить процесс: %s\n", strerror(errno));
        return 1;
    }
    wait(&status);
    
    printf("\n=== Фрагмент 4 ===\n");
    pid = fork();
    if (pid == 0) {
        char *my_env[] = {"FOOD=пончиками", NULL};
        execle("./coffee", "кофе", NULL, my_env);
        fprintf(stderr, "Не могу запустить процесс: %s\n", strerror(errno));
        return 1;
    }
    wait(&status);
    
    return 0;
}