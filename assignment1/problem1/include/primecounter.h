#ifndef ACOUNTER_H
#define ACOUNTER_H

#include <atomic>
#include <queue>
#include <mutex>
#include <fstream>

template <class T>
class PrimeCounter {
	
	std::atomic<T> *value;
	std::atomic<T> *numPrimes;
	std::atomic<T> *sum;
	std::mutex lock;
	
	// We want a priority queue that pops the smallest element, rather than the largest
	std::priority_queue<T, std::vector<T>, std::greater<T>> q;
	
	public:
		PrimeCounter();
		~PrimeCounter();
		T getAndIncrement();
		T get();
		T getSum();
		void addToSum(T);
		T getNumPrimes();
		T incNumPrimes();
		void pushToList(T);
		void printList(std::ofstream &f);
};

#endif