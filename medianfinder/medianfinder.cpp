#include "medianfinder.h"

MedianFinder::MedianFinder()
{
    //ctor
}

MedianFinder::~MedianFinder()
{
    //dtor
}

int MedianFinder::BruteForceMedian(int *dataArray, size_t length){
    int k = ceil((float)length / 2);
    int numSmaller = 0;
    int numEqual = 0;

    for (int i = 0; i < length; i++){
        numSmaller = 0;
        numEqual = 0;

        for (int j = 0; j < length; j++){
            if(dataArray[j] < dataArray[i]){
                numSmaller++;
            } else if (dataArray[j] == dataArray[i]){
                numEqual++;
            }
        }
        if (numSmaller < k && k <= (numSmaller + numEqual)){
            return dataArray[i];
        }
    }
}

unsigned int MedianFinder::basicOperatorCounterFindMedian(int *dataArray, size_t length){
    int k = ceil((float)length / 2);
    int numSmaller = 0;
    int numEqual = 0;
    int basicOperationCounter = 0;

    for (int i = 0; i < length; i++){
        numSmaller = 0;
        numEqual = 0;

        for (int j = 0; j < length; j++){
            basicOperationCounter++;
            if(dataArray[j] < dataArray[i]){
                numSmaller++;
            } else{
                basicOperationCounter++;
                if (dataArray[j] == dataArray[i]){
                numEqual++;
                }
            }
        }
        basicOperationCounter+=2;
        if (numSmaller < k && k <= (numSmaller + numEqual)){
            return basicOperationCounter;
        }
    }
}

unsigned int MedianFinder::timerFindMedian(int *dataArray, size_t length){
    int k = ceil((float)length / 2);
    int numSmaller = 0;
    int numEqual = 0;

    clock_t ticks = clock();

    for (int i = 0; i < length; i++){
        numSmaller = 0;
        numEqual = 0;

        for (int j = 0; j < length; j++){
            if(dataArray[j] < dataArray[i]){
                numSmaller++;
            } else if (dataArray[j] == dataArray[i]){
                numEqual++;
            }
        }
        if(numSmaller < k && k <= (numSmaller + numEqual)){
            return clock() - ticks;
        }
    }
}
