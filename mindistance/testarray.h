#ifndef TESTARRAY_H
#define TESTARRAY_H

#include <stdlib.h>
#include <iostream>
#include <stdio.h>

using namespace std;

class TestArray
{
    public:
        TestArray(size_t length);
        virtual ~TestArray();

        void randomizeArrayValues();
        void getNewArray(size_t length);

        int *getTestArray();

        size_t getLength();

        void printArray();
        void setArray(int* desiredArray, size_t length);

    protected:

    private:
        int *testArray;
        void deleteArray();

        size_t currentLength;
};

#endif // TESTARRAY_H
