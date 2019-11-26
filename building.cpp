#include "building.h"
#include <string>
#include <QDebug>

using namespace std;

Building::Building()
{
    floor[0] = new Floor(new Add1);
    floor[1] = new Floor(new Prime);
    floor[2] = new Floor(new LongestPair);
    floor[3] = new Floor(new ShyGame);
    floor[4] = new Floor(new FibonacciOfFibonacci);
    floor[8] = new Floor(new FindFactorial);
    floor[9] = new Floor(new ShortestSummationDistance);
}

void Building::run(int n)
{
    data.testdata = judge.getData(n);
    data.submit = floor[n]->p->solve(data.testdata);
    data.correct = judge.submitData(data.submit);
    data.spendtime = judge.getSpendTime();
}
