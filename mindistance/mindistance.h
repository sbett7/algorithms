#ifndef MINDISTANCE_H
#define MINDISTANCE_H

#include <math.h>
#include <ctime>
#include <cstdlib>
#include <limits>

class MinDistance
{
    public:
        MinDistance();
        virtual ~MinDistance();

        int minDistance(int* A, size_t n);
        long long int minDistanceBasicCount(int* A, size_t n);
        long long int minDistanceExecutionTime(int* A, size_t n);

        int minDistanceTwo(int* A, size_t n);
        long long int minDistanceTwoBasicCount(int* A, size_t n);
        long long int minDistanceTwoExecutionTime(int* A, size_t n);


    protected:

    private:
};

#endif // MINDISTANCE_H
