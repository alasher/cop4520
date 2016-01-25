#include <cstdio>
#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <cmath>
#include <fstream>
#include "primecounter.h"
#include "main.h"

using namespace std;

int main(int argc, char** argv) {
	
	cout << "Beginning search for primes less than " << MAX_TEST << "..." << endl;
	
	int i;
	auto start = chrono::system_clock::now();
	
	PrimeCounter<P_INT> *c = new PrimeCounter<P_INT>();
	
	vector<thread> threads;
	int threadCounter[N_THREADS];
	
	// Create the threads and start counting
	for(i=0; i < N_THREADS; i++) {
		threadCounter[i] = 0;
		threads.push_back(thread(countSeveralTimes, c, threadCounter+i));
	}
	
	// After we start all the threads, join them all to this thread so
	// we don't run the print lines until they're all done.
	for(i=0; i < N_THREADS; i++) threads[i].join();
	
	// Once we get to this line, we're finished. note the time!
	auto end = chrono::system_clock::now();
	chrono::duration<double> elapsedTime = end-start;
	
	if(printResults(c, elapsedTime.count())) {
		cout << "Finished!\nWrote program results into \"primes.txt\".\n";
	} else {
		cout << "ERROR: Failed to write results into \"primes.txt\"!\n";
	}
	
	delete c;
	
	return 0;
}

void countSeveralTimes(PrimeCounter<P_INT> *counter, int *inc) {
	P_INT n = counter->getAndIncrement();
	while(n <= MAX_TEST) {
		
		(*inc)++; // increment the value in this thread's 'counter'
		
		if(primeTest(n)) {
			counter->addToSum(n);
			counter->incNumPrimes();
			counter->pushToList(n);
		}
		
		n = counter->getAndIncrement();
	}
}

bool primeTest(P_INT n) {
	if(n <= 1) return false;
	if(n <= 3) return true;
	if(n % 2 == 0 || n % 3 == 0) return false;
	
	P_INT i;
	P_INT max = (P_INT) floor(sqrt((double) n));
	
	// Check every odd number less than sqrt(n)
	for(i=5; i <= max; i+=2)
		if(n % i == 0) return false;
	
	return true;
}

bool printResults(PrimeCounter<P_INT> *c, double t) {
	ofstream primes;
	primes.open("primes.txt");
	if(!primes.is_open()) return false;
	
	primes << "Search for primes less than " << MAX_TEST << endl << endl;
	primes << "Elapsed time: " << t << " seconds." << endl;
	primes << "Total number of primes found: " << c->getNumPrimes() << endl;
	primes << "Sum of all primes found: " << c->getSum() << endl;
	primes << "Highest " << N_HIGHEST_PRIME << " primes found: ";
	c->printList(primes);
	
	primes.close();
	return true;
}