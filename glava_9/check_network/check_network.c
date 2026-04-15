#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
    if (execl("/sbin/ip", "ip", "addr", NULL) == -1)
    {
        fprintf(stderr, "Не удалось запустить ip: %s\n", strerror(errno));
        return 1;
    }
    return 0;
}