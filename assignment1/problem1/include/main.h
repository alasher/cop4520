#ifndef MAIN_H
#define MAIN_H

#define MAX_TEST 100000000
#define N_THREADS 8
#define N_HIGHEST_PRIME 10
#define PRINT_THREAD_COUNT 1

typedef unsigned long long int P_INT;

void countSeveralTimes(PrimeCounter<P_INT> *counter, int*);
bool primeTest(P_INT);
bool printResults(PrimeCounter<P_INT> *, double);

#endif