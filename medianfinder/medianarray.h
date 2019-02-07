#ifndef MEDIANARRAY_H
#define MEDIANARRAY_H

#include <stdlib.h>
#include <iostream>
#include <stdio.h>

using namespace std;


class MedianArray
{
    public:
        MedianArray(size_t length);
        virtual ~MedianArray();

        void randomizeArrayValues();
        void getNewArray(size_t length);

        int *getMedianArray();

        size_t getLength();

        void printArray();
        void setArray(int* desiredArray, size_t length);

    protected:

    private:
        int *dataArray;
        void deleteArray();

        size_t currentLength;

};

#endif // MEDIANARRAY_H
