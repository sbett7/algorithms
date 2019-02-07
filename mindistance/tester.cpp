#include "tester.h"



Tester::Tester(){
    finder = new MinDistance();
    testArray = new TestArray(DEFAULT_ARRAY_SIZE);
    clearFiles();
}

Tester::~Tester()
{
    //dtor
}

void Tester::clearFiles(){
    remove("rawData/basic_operation.csv");
    remove("rawData/time_experiment.csv");

}

void Tester::exportResults(int arrayLength, long long int result, long long int result2){
    std::ofstream file;

    file.open(getFileName().c_str(), std::ios::app);

    if (!file){
        cout << "Could not open file";
    } else{
        switch(getCurrentExperiment()){
            case basicOperation:
                cout << "MinDistance Algorithm Basic Operations = " << result << endl;
                cout << "MinDistance2 Algorithm Basic Operations = " << result2 << endl;
                file <<  arrayLength << "," << result << "," << result2<< "\r";
                file.close();
                break;
            case executionTime:
                cout << "MinDistance Algorithm Execution Time = " << result/double(CLOCKS_PER_SEC) * 1000.0  << " ms" << endl;
                cout << "MinDistance2 Algorithm Execution Time = " << result2/double(CLOCKS_PER_SEC) * 1000.0  << " ms" << endl;
                file <<  arrayLength << ","<<result/double(CLOCKS_PER_SEC) * 1000.0 <<","<<result2/double(CLOCKS_PER_SEC) * 1000.0 << "\r";
                file.close();
                break;
        }
    }
}

void Tester::runAlgorithm (int *dataArray, size_t length, Algorithm algorithm){
    int result = 0;

    setCurrentAlgorithm(algorithm);
    testArray->setArray(dataArray, length);

    switch(algorithm){
        case minDistance1:
            result = finder->minDistance(testArray->getTestArray(), testArray->getLength());
            break;
        case minDistance2:
            result = finder->minDistanceTwo(testArray->getTestArray(), testArray->getLength());
            break;
    }

    testArray->printArray();
    cout << endl << "The minimum distance is: " << result << endl << endl;
}

void Tester::performExperiment(Experiment experimentType){
    long long int* results = new long long int[2] {0, 0};
    setCurrentExperiment(experimentType);

    cout << endl <<endl;

    for (int i = 0; i < NUMBER_OF_TESTS; i++){
        adjustArraySize(testArrayLengths[i]);
        cout << "Performing Test Number " << i + 1 << " of " << NUMBER_OF_TESTS<< endl;

        for (int algorithm = minDistance1; algorithm <=minDistance2; algorithm++){
            setCurrentAlgorithm(static_cast<Algorithm>(algorithm));
            results[algorithm] = averageOperation();
            cout << "Calculated value for Algorithm " << algorithm + 1<< endl;
        }
        exportResults(testArray->getLength(), results[minDistance1], results[minDistance2]);
        cout << "Completed" << endl << endl;
    }
    delete results;
}

long long int Tester::averageOperation(){
    long long int result = 0;
    int numRepeats = 0;

    //change number of repeats for larger sized arrays
    if(testArray->getLength() >= LARGE_ARRAY_SIZE){
        numRepeats = NUMBER_OF_REPEATS_FOR_LARGE_N;
    } else{
        numRepeats = NUMBER_OF_REPEATS;
    }

    //randomize value and get cumulative sum of tests
    for (int i = 0; i < numRepeats; i++){
        testArray->randomizeArrayValues();
        result += performTest();
    }
    return ceil(result / numRepeats);
}

long long int Tester::performTest(){
    long long int result = 0;

    switch(getCurrentExperiment()){
        case basicOperation:
            result = doBasicOperation();
            break;
        case executionTime:
            result = doTimeExecution();
            break;
    }
    return result;
}

long long int Tester::doBasicOperation(){
    switch(getCurrentAlgorithm()){
        case minDistance1:
            return finder->minDistanceBasicCount(testArray->getTestArray(), testArray->getLength());
            break;
        case minDistance2:
            return finder->minDistanceTwoBasicCount(testArray->getTestArray(), testArray->getLength());
            break;
    }
}

long long int Tester::doTimeExecution(){
    switch(getCurrentAlgorithm()){
        case minDistance1:
            return finder->minDistanceExecutionTime(testArray->getTestArray(), testArray->getLength());
            break;
        case minDistance2:
            return finder->minDistanceTwoExecutionTime(testArray->getTestArray(), testArray->getLength());
            break;
    }
}

void Tester::randomiseValues(){
    testArray->randomizeArrayValues();
}

void Tester::adjustArraySize(size_t length){
    testArray->getNewArray(length);
}

Tester::Experiment Tester::getCurrentExperiment(){
    return currentExperiment;
}

void Tester::setCurrentExperiment(Experiment value){
    currentExperiment = value;
}

Tester::Algorithm Tester::getCurrentAlgorithm(){
    return currentAlgorithm;
}

void Tester::setCurrentAlgorithm(Algorithm value){
    currentAlgorithm = value;
}

string Tester::getFileName(){
    switch(getCurrentExperiment()){
        case basicOperation:
            return "rawData/basic_operation.csv";
        case executionTime:
            return "rawData/time_experiment.csv";
    }
}
