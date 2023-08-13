#include <unistd.h>
#include <stdio.h>

static inline __uint64_t arch_timer_get_cntkctl(void)
{
    __uint64_t cntkctl;
    asm volatile("isb; mrs %0, cntvct_el0" : "=r"(cntkctl));
    return cntkctl;
}

static inline __uint64_t arch_timer_get_freq(void)
{
    __uint64_t freq;
    asm volatile("isb; mrs %0, cntfrq_el0" : "=r"(freq));
    return freq;
}
int main()
{
#if 0
    printf("Before Sleep : %u\n",arch_timer_get_cntkctl());
    sleep(2);
    printf("After Sleep : %u\n",arch_timer_get_cntkctl());
#else
    __uint64_t ts, te, freq;
    //asm volatile("isb; mrs %0, cntvct_el0" : "=r"(ts));
    ts = arch_timer_get_cntkctl();
    sleep(1);
    te = arch_timer_get_cntkctl();
    //asm volatile("isb; mrs %0, cntvct_el0" : "=r"(te));
    freq = arch_timer_get_freq();
    //asm volatile("isb; mrs %0, cntfrq_el0" : "=r"(freq));

    printf("Aarch64 %ld cycles\n", (te - ts));

    printf(" Frequency = %ld\n", freq);
#endif
    return 0;
}
