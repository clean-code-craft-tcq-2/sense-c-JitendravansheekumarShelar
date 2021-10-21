#include "stats.h"
#include <cstddef>
#include <math.h>

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    
    if (numberset != NULL)
    {
        s.average = s.min = s.max = numberset[0];    
        for (int i = 1; i < setlength ; i++)
        {
            if (s.min > numberset[i])
                s.min = numberset[i];
            if (s.max < numberset[i])
                s.max = numberset[i];
        
            s.average = s.average + numberset[i];
        }    
        s.average = s.average / (float)setlength ;
        return s;
    }
    s.average = s.min = s.max = NAN;
    return s;

}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    if (computedStats.max > maxThreshold)
    {
        alerters[0]();
        alerters[1]();
    }
}
