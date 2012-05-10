#include <stdio.h>
#include <stdlib.h>
#include <iostream>

const long MAX_CACHE_SIZE = 1000000;

using namespace std;

int cycleCache[MAX_CACHE_SIZE+1];

int getCycle(long number) {
    if (cycleCache[number] != 0) {
        return cycleCache[number];
    }

    long value = number;
    int cycle = 1;
    int tmpCacheIndex[1000];
    long i = 0;

    while (value != 1) {

        if (value % 2) {
            value = value * 3 + 1;
        } else {
            value = value / 2;
        }

        tmpCacheIndex[i] = value;
        cycle++;
        i++;

        if (value < MAX_CACHE_SIZE && cycleCache[value] != 0) {
            cycle += cycleCache[value] - 1;

            while (i--) {
                if (tmpCacheIndex[i] < MAX_CACHE_SIZE) {
                    cycleCache[tmpCacheIndex[i]] = cycle - i - 1;
                }
            }
            break;
        }
    }

    cycleCache[number] = cycle;
    return cycle;
}

int getMaxCycle(long from, long to) {
    if (from > to) {
        swap(from, to);
    }

    int currMaxCycle = 0;
    int cycle;
    long i;
    for (i = from; i <= to; i++) {

        cycle = getCycle(i);

        if (cycle > currMaxCycle) {
            currMaxCycle = cycle;
        }
    }

    return currMaxCycle;
}

void makeSomeCache() {
    long i;
    for (i = 10000; i > 0; i--) {
        getCycle(i);
    }
}

int main(int argc, char** argv) {
    //makeSomeCache();
    long from, to;
    while (scanf("%ld %ld", &from, &to) == 2) {
        printf("%ld %ld %d\n", from, to, getMaxCycle(from, to));
    }

    return 0;

}
