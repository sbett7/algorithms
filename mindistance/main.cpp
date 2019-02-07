#include <iostream>
#include "tester.h"


using namespace std;

int main()
{
    Tester* tester = new Tester();

    //Functional testing arrays
    int* randomArray = new int[10]{
        1, 2, 7, 12, 32, 17, 99, 1000, 500, 2000
    };

    int* sameValues = new int[10]{
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };

    // efficiency experiments
    tester->performExperiment(Tester::basicOperation);
    tester->performExperiment(Tester::executionTime);

    //MinDistance Algorithm

    //tester->runAlgorithm(randomArray, 10, Tester::minDistance1);
    //tester->runAlgorithm(sameValues, 10, Tester::minDistance1);
    //tester->runAlgorithm(negativeValues, 10, Tester::minDistance1);

    //MinDistance2 Algorithm

    return 0;
}
