#include "mediantester.h"

MedianTester::~MedianTester()
{
    //dtor
}

MedianTester::MedianTester(){
    finder = new MedianFinder();
    medianArray = new MedianArray(DEFAULT_ARRAY_SIZE);
    clearFiles();
}

void MedianTester::clearFiles(){
    remove("rawData/basic_operation.csv");
    remove("rawData/time_experiment.csv");
}

void MedianTester::exportResults(int arrayLength, long long int result){
    std::ofstream file;

    switch(getCurrentExperiment()){
        case BASIC_OPERATOR_EXPERIMENT:
            file.open("rawData/basic_operation.csv", std::ios::app);

            if(file){
                cout << "Basic Operations = " << result << endl << endl;
                file <<  arrayLength << ","<<result << "\r";
                file.close();
            } else {
                cout << "could not open file." << endl;
            }
            break;
        case TIME_EXPERIMENT:
            file.open("rawData/time_experiment.csv", std::ios::app);

            if(file){
                cout << "Execution Time = " << result/double(CLOCKS_PER_SEC) * 1000.0  << " ms" << endl << endl;
                file <<  arrayLength << ","<<result/double(CLOCKS_PER_SEC) * 1000.0 << "\r";
                file.close();
            } else {
                cout << "could not open file." << endl;
            }
            break;
    }
}

void MedianTester::runMedianFinder (int *dataArray, size_t length){
    int result = 0;
    medianArray->setArray(dataArray, length);

    result = finder->BruteForceMedian(medianArray->getMedianArray(), medianArray->getLength());
    medianArray->printArray();
    cout << endl << "The median is: " << result << endl << endl;
}

void MedianTester::performExperiment(int experimentType){
    unsigned int result = 0;

    setCurrentExperiment(experimentType);

    cout << endl <<endl;

    //perform testing for every test in testArray
    for (int i = 0; i < NUMBER_OF_TESTS; i++){
        cout << "Performing Test Number " << i + 1 << " of " << NUMBER_OF_TESTS<< endl;
        adjustArraySize(testArrayLengths[i]);

        result = averageOperation();
        cout << "Completed" << endl;
        exportResults(medianArray->getLength(), result);

    }
}

long long int MedianTester::averageOperation(){
    long long int result = 0;
    int numRepeats = 0;

    //change number of repeats for larger sized arrays
    if(medianArray->getLength() >= LARGE_ARRAY_SIZE){
        numRepeats = NUMBER_OF_REPEATS_FOR_LARGE_N;
    } else{
        numRepeats = NUMBER_OF_REPEATS;
    }

    //randomize value and get cumulative sum of tests
    for (int i = 0; i < numRepeats; i++){
        medianArray->randomizeArrayValues();
        result += performTest();
    }
    return ceil(result / numRepeats);
}

int MedianTester::performTest(){
    unsigned int result = 0;

    switch(currentExperiment){
        case BASIC_OPERATOR_EXPERIMENT:
            result = doBasicOperation();
            break;
        case TIME_EXPERIMENT:
            result = doTimeExecution();
            break;
    }
    return result;
}

int MedianTester::doBasicOperation(){
    return finder->basicOperatorCounterFindMedian(medianArray->getMedianArray(), medianArray->getLength());
}

int MedianTester::doTimeExecution(){
    return finder->timerFindMedian(medianArray->getMedianArray(), medianArray->getLength());
}

void MedianTester::randomiseValues(){
    medianArray->randomizeArrayValues();
}

void MedianTester::adjustArraySize(size_t length){
    medianArray->getNewArray(length);
}

int MedianTester::getCurrentExperiment(){
    return currentExperiment;
}

void MedianTester::setCurrentExperiment(int value){
    currentExperiment = value;
}
