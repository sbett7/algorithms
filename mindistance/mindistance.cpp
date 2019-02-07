#include "mindistance.h"

MinDistance::MinDistance()
{
    //ctor
}

MinDistance::~MinDistance()
{
    //dtor
}

int MinDistance::minDistance(int* A, size_t n){
    int dmin = std::numeric_limits<int>::max();;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i != j && abs(A[i] - A[j]) < dmin){
                dmin = abs(A[i] - A[j]);
            }
        }
    }
    return dmin;
}

long long int MinDistance::minDistanceBasicCount(int* A, size_t n){
    int dmin = std::numeric_limits<int>::max();;
    long long int basicCount = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
                basicCount++;
            if (i != j && abs(A[i] - A[j]) < dmin){
                dmin = abs(A[i] - A[j]);
            }
        }
    }
    return basicCount;
}

long long int MinDistance::minDistanceExecutionTime(int* A, size_t n){
    int dmin = std::numeric_limits<int>::max();;

    clock_t ticks = clock();

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i != j && abs(A[i] - A[j]) < dmin){
                dmin = abs(A[i] - A[j]);
            }
        }
    }
    return clock() - ticks;
}

int MinDistance::minDistanceTwo(int* A, size_t n){
    int dmin = std::numeric_limits<int>::max();;
    int temp = 0;
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            temp = abs(A[i] - A[j]);
            if (temp < dmin){
                dmin = temp;
            }
        }
    }
    return dmin;
}

long long int MinDistance::minDistanceTwoBasicCount(int* A, size_t n){

    int dmin = std::numeric_limits<int>::max();;
    int temp = 0;
    long long int basicCount = 0;

    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            basicCount++;
            temp = abs(A[i] - A[j]);
            if (temp < dmin){
                dmin = temp;
            }
        }
    }
    return basicCount;
}

long long int MinDistance::minDistanceTwoExecutionTime(int* A, size_t n){
    int dmin = std::numeric_limits<int>::max();;
    int temp = 0;

    clock_t ticks = clock();

    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            temp = abs(A[i] - A[j]);
            if (temp < dmin){
                dmin = temp;
            }
        }
    }
    return clock() - ticks;
}

