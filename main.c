#include <unistd.h>
#include <stdio.h>
#include "arm_clock.h"
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
