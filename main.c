#include <unistd.h>
#include <stdio.h>
#define NSEC_PER_SEC   1000000000L
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

    __uint64_t ts, te, freq;

    ts = arch_timer_get_cntkctl();
    sleep(2);
    te = arch_timer_get_cntkctl();

    freq = arch_timer_get_freq();

    printf("Aarch64 %ld cycles\n", (te - ts));
    printf(" Frequency = %ld\n", freq);
    printf("Time taken : %f Sec \n",(float)(te-ts)/(float)freq);
    printf("Time taken : %f ns \n",(float)(te-ts)*(float)NSEC_PER_SEC/(float)freq);
    return 0;
}
