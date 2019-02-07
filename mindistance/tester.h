#ifndef TESTER_H
#define TESTER_H


#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include "string"

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>


#include "mindistance.h"
#include "testarray.h"



#define NUMBER_OF_REPEATS 20
#define NUMBER_OF_REPEATS_FOR_LARGE_N 60
#define DEFAULT_ARRAY_SIZE 7
#define LARGE_ARRAY_SIZE 4000

#define TIME_EXPERIMENT 0
#define BASIC_OPERATOR_EXPERIMENT 1

#define NUMBER_OF_TESTS 29


class Tester
{
    public:

        enum Experiment {basicOperation, executionTime};
        enum Algorithm {minDistance1, minDistance2};

        Tester();
        virtual ~Tester();

        void runAlgorithm (int *dataArray, size_t length, Algorithm algorithm);

        void exportResults(int arrayLength, long long int result, long long int result2);

        void performExperiment(Experiment experimentType);


        void randomiseValues();
        void adjustArraySize(size_t length);

        Experiment getCurrentExperiment();
        void setCurrentExperiment(Experiment value);

        void setCurrentAlgorithm(Algorithm value);
        Algorithm getCurrentAlgorithm();

    protected:

    private:
        long long int averageOperation();
        long long int performTest();
        long long int doBasicOperation();
        long long int doTimeExecution();

        void clearFiles();
        void printAlgorithmResult();

        string getFileName();

        Experiment currentExperiment;
        Algorithm currentAlgorithm;



        MinDistance* finder;
        TestArray* testArray;
        int testArrayLengths[29] = {10, 50, 100, 250, 500, 1000, 1500, 2000, 2500,
         3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500,
         9000, 9500, 10000, 11000, 12500, 14000, 15000, 16500};

};

#endif // TESTER_H
