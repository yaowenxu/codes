// #define _GNU_SOURCE

#include <stdint.h>
#include <stdio.h>
#include <sched.h>
#include <pthread.h>
#include <stdlib.h>


static inline void print_cpu_mask(cpu_set_t cpu_mask)
{
    unsigned char flag = 0;
    printf("Cpu affinity is ");
    for (unsigned int i = 0; i < sizeof(cpu_set_t); i ++)
    {
        if (CPU_ISSET(i, &cpu_mask))
        {
            if (flag == 0)
            {
                flag = 1;
                printf("%d", i);
            }
            else
            {
                printf(",%d", i);
            }
        }
    }
    printf(".\n");
}

static inline void get_cpu_mask(pid_t pid, cpu_set_t *mask)
{
    if (sched_getaffinity(pid, sizeof(cpu_set_t), mask) == -1)
    {
        perror("get cpu affinity failed.\n");
        abort();
    }
}

static inline void set_cpu_mask(pid_t pid, cpu_set_t *mask)
{
    if (sched_setaffinity(pid, sizeof(cpu_set_t), mask) == -1)
    {
        perror("set cpu affinity failed.\n");
        abort();
    }
}

int main(int argc, char *argv[])
{
    unsigned int active_cpu = 1;
    cpu_set_t cpu_mask;

    get_cpu_mask(0, &cpu_mask);
    print_cpu_mask(cpu_mask);

    CPU_ZERO(&cpu_mask);
    CPU_SET(active_cpu, &cpu_mask);
    set_cpu_mask(0, &cpu_mask);

    get_cpu_mask(0, &cpu_mask);
    print_cpu_mask(cpu_mask);

    for(;;)
    {
        ;
    }
    return 0;
}

