#include "medianarray.h"

MedianArray::~MedianArray()
{
    //dtor
}

MedianArray::MedianArray(size_t length){
    currentLength = length;
    dataArray = new int[length];
    getNewArray(length);
}

void MedianArray::randomizeArrayValues(){

    for (int i = 0; i < getLength(); i++){
        dataArray[i] = rand();
    }
}

void MedianArray::getNewArray(size_t length){
    deleteArray();

    //create new array
    dataArray = new int[length];
    currentLength = length;
    randomizeArrayValues();
}

void MedianArray::setArray(int* desiredArray, size_t length){
    deleteArray();
    dataArray = new int[length];
    currentLength = length;

    //store desired values in dataArray
    for(int i = 0; i < length; i++){
        dataArray[i] = desiredArray[i];
    }
}

void MedianArray::deleteArray(){
    delete dataArray;
}

int *MedianArray::getMedianArray(){
    return dataArray;
}

size_t MedianArray::getLength(){
    return currentLength;
}

void MedianArray::printArray(){
    cout << "The array of length " << getLength() << " contains: " << endl;

    for (int i = 0; i < getLength(); i++){
        cout << dataArray[i] << " ";
    }
    cout << endl;
}

