#ifndef MEDIANTESTER_H
#define MEDIANTESTER_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include "string"

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>


#include "medianfinder.h"
#include "medianarray.h"

#define NUMBER_OF_REPEATS 100
#define NUMBER_OF_REPEATS_FOR_LARGE_N 100
#define DEFAULT_ARRAY_SIZE 7
#define LARGE_ARRAY_SIZE 4000

#define TIME_EXPERIMENT 0
#define BASIC_OPERATOR_EXPERIMENT 1

#define NUMBER_OF_TESTS 24

class MedianTester
{
    public:
        MedianTester();
        virtual ~MedianTester();

        void runMedianFinder (int *dataArray, size_t length);
        void printBruteForceMedianResult();
        void exportResults(int arrayLength, long long int result);

        void performExperiment(int experimentType);

        void randomiseValues();
        void adjustArraySize(size_t length);

        int getCurrentExperiment();
        void setCurrentExperiment(int value);

    protected:

    private:
        long long int averageOperation();
        int performTest();
        int doBasicOperation();
        int doTimeExecution();

        int averageBasicOperationCount();
        int averageTimeOperation();
        void clearFiles();
        int currentExperiment;
        MedianFinder* finder;
        MedianArray* medianArray;
        int testArrayLengths[24] = {10, 50, 100, 250, 500, 1000, 1500, 2000, 2500,
         3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500,
         9000, 9500, 10000};

};

#endif // MEDIANTESTER_H
