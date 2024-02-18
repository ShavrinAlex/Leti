#include <stdio.h>
#include <sched.h>

int main (void) {
    	struct sched_param shdprm; // Значения параметров планирования
    	printf ("диапазоны приоритетов для разных политик планирования\n");
    	printf ("SCHED_FIFO : от %d до %d\n",
    	sched_get_priority_min (SCHED_FIFO),
    	sched_get_priority_max (SCHED_FIFO));
    	printf ("SCHED_RR : от %d до %d\n",sched_get_priority_min (SCHED_RR),sched_get_priority_max (SCHED_RR));
    	printf ("SCHED_OTHER: от %d до %d\n",sched_get_priority_min (SCHED_OTHER),sched_get_priority_max (SCHED_OTHER));
    	printf ("Текущая политика планирования для текущего процесса: ");
    	
    	switch (sched_getscheduler (0)) {
            	case SCHED_FIFO:
                    	printf ("SCHED_FIFO\n");
                    	break;
            	case SCHED_RR:
                    	printf ("SCHED_RR\n");
                    	break;
            	case SCHED_OTHER:

                    	printf ("SCHED_OTHER\n");
                    	break;
            	case -1:
                    	perror ("SCHED_GETSCHEDULER");
                    	break;
            	default:
                    	printf ("Неизвестная политика планирования\n");
    	}
    	if (sched_getparam (0, &shdprm) == 0) {
            	printf ("Текущий приоритет текущего процесса: %d\n",shdprm.sched_priority);
    	} else {
            	perror ("SCHED_GETPARAM");
    	}
    	return 0;
}

