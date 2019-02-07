#ifndef MEDIANFINDER_H
#define MEDIANFINDER_H

#include <math.h>
#include <ctime>
#include <cstdlib>

class MedianFinder
{
    public:
        MedianFinder();

        virtual ~MedianFinder();

        int BruteForceMedian(int *dataArray, size_t length);
        unsigned int basicOperatorCounterFindMedian(int *dataArray, size_t length);
        unsigned int timerFindMedian(int *dataArray, size_t length);

    protected:

    private:

};

#endif // MEDIANFINDER_H
