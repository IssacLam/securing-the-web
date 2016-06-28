// seems no needs a harness for this function

/*#include "utils/s2n_timer.h"
#include "tls/s2n_config.h"

void *malloc(__CPROVER_size_t);

int main(int argc, char * const *argv){
        struct s2n_config *config;
        struct s2n_timer *timer;
        int result;

        config = malloc(sizeof(struct s2n_config));
        timer = malloc(sizeof(struct s2n_timer));

        result = s2n_timer_start(config, timer);
        
        __CPROVER_assert(result == 0, "ERROR: s2n_timer_start result");
        __CPROVER_assert(timer->time != NULL, "ERROR: s2n_timer_start");

        return 0;
}*/
