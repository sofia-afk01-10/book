#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    char *feeds[] = {
        "http://www.cnn.com/rss/celebs.xml",
        "http://www.rollingstone.com/rock.xml",
        "http://eonline.com/gossip.xml"
    };
    int times = 3;
    
    // Проверка: нужен аргумент (поисковая фраза)
    if (argc < 2) {
        fprintf(stderr, "Использование: %s <поисковая_фраза>\n", argv[0]);
        return 1;
    }
    
    char *phrase = argv[1];
    int i;
    
    for (i = 0; i < times; i++) {
        char var[255];
        sprintf(var, "RSS_FEED=%s", feeds[i]);
        char *vars[] = {var, NULL};
        
        pid_t pid = fork();
        
        if (pid == -1) {
            fprintf(stderr, "Не могу клонировать процесс: %s\n", strerror(errno));
            return 1;
        }
        
        if (pid == 0) {
            // Дочерний процесс: запускаем скрипт
            if (execle("/usr/bin/python3", "/usr/bin/python3", 
                       "./rssgossip.py", phrase, NULL, vars) == -1) {
                fprintf(stderr, "Не могу запустить скрипт: %s\n", strerror(errno));
                return 1;
            }
        }
    }
    
    // Родитель ждёт завершения всех дочерних процессов
    while (wait(NULL) > 0);
    
    return 0;
}