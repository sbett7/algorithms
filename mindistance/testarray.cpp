#include "testarray.h"

TestArray::~TestArray()
{
    //dtor
}

TestArray::TestArray(size_t length){
    currentLength = length;
    testArray = new int[length];
    getNewArray(length);
}

void TestArray::randomizeArrayValues(){

    for (int i = 0; i < getLength(); i++){
        testArray[i] = rand();
    }
}

void TestArray::getNewArray(size_t length){
    deleteArray();

    //create new array
    testArray = new int[length];
    currentLength = length;
    randomizeArrayValues();
}

void TestArray::setArray(int* desiredArray, size_t length){
    deleteArray();
    testArray = new int[length];
    currentLength = length;

    //store desired values in testArray
    for(int i = 0; i < length; i++){
        testArray[i] = desiredArray[i];
    }
}

void TestArray::deleteArray(){
    delete testArray;
}

int *TestArray::getTestArray(){
    return testArray;
}

size_t TestArray::getLength(){
    return currentLength;
}

void TestArray::printArray(){
    cout << "The array of length " << getLength() << " contains: " << endl;

    for (int i = 0; i < getLength(); i++){
        cout << testArray[i] << " ";
    }
    cout << endl;
}
