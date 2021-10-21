#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    
    if (numberset != NULL)
    {
        s.average = s.min = s.max = numberset[0];    
        for (i = 1; i < setlength ; i++)
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
