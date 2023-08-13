#pragma once
#include <unistd.h>

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