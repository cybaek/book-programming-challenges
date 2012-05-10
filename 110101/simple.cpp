#include <iostream>

using namespace std;

const long MAX_CACHE_SIZE = 1000000;

long cycleCache[MAX_CACHE_SIZE+1];

int getCycle(long number) {
    if (cycleCache[number] != 0) {
        return cycleCache[number];
    }

    long value = number;
    int cycle = 1;

    while (value != 1) {
        if (value % 2) {
            value = value * 3 + 1;
        }
        else {
            value = value / 2;
        }
        cycle++;
    }

    cycleCache[number] = cycle;
    return cycle;
}

int getMaxCycle(long from, long to) {
    if (from > to) {
        std::swap(from, to);
    }

    int currMaxCycle = 0;
    int cycle;
    for (long i = from; i <= to; i++) {

        cycle = getCycle(i);

        if (cycle > currMaxCycle) {
            currMaxCycle = cycle;
        }
    }

    return currMaxCycle;
}

int main(int argc, char** argv) {
    long from, to;
    while (scanf("%ld %ld", &from, &to) == 2) {
        cout << from << " " << to << " " << getMaxCycle(from, to) << endl;
    }
    return 0;
}
