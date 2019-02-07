#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "medianfinder.h"
#include "mediantester.h"

using namespace std;

int main()
{
    MedianTester *tester = new MedianTester();

    int ascending[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sameValues[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1 ,1};
    int unsortedValues[10] = {4, 4, 3, 2, 1, 6, 7, 8, 2, 1};

    int ascendingMultiples[11] = {1, 1, 2, 3, 4, 7, 8 ,9 ,11, 11, 12};
    int descending[11] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int unsortedValues1[11] = {1, 2, 6, 2, 1, 6, 7, 4, 2, 8, 11};

    //gather empirical data
    cout << endl << endl << "Performing Basic Operation Experiment";
    tester->performExperiment(BASIC_OPERATOR_EXPERIMENT);
    cout << endl << endl << "Performing Time Execution Experiment";
    tester->performExperiment(TIME_EXPERIMENT);

    cout << "Performing Functional Testing" << endl;

    //functional testing array size of 10
    tester->adjustArraySize(10);

    tester->runMedianFinder(ascending, 10);
    tester->runMedianFinder(sameValues, 10);
    tester->runMedianFinder(unsortedValues, 10);

    //functional testing array size 11
    tester->adjustArraySize(11);

    tester->runMedianFinder(ascendingMultiples, 11);
    tester->runMedianFinder(descending, 11);
    tester->runMedianFinder(unsortedValues1, 11);

    return 0;
}


