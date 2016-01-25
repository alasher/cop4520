#include "primecounter.h"
#include "main.h"

template <class T> 
PrimeCounter<T>::PrimeCounter() {
	value = new std::atomic<T>();
	numPrimes = new std::atomic<T>();
	sum = new std::atomic<T>();
	
	value->store(3);
	sum ->store(2);
	numPrimes->store(1);
}

template <class T> 
PrimeCounter<T>::~PrimeCounter() {
	delete value;
	delete numPrimes;
	delete sum;
}

// Prime snatcher
template <class T> 
T PrimeCounter<T>::getAndIncrement() {
	return value->fetch_add(2);
}

template <class T> 
T PrimeCounter<T>::get() {
	return value->load();
}

// Sum handler
template <class T> 
T PrimeCounter<T>::getSum() {
	return sum->load();
}

template <class T> 
void PrimeCounter<T>::addToSum(T n) {
	sum->fetch_add(n);
}

// Prime counter
template <class T> 
T PrimeCounter<T>::getNumPrimes() {
	return numPrimes->load();
}

template <class T> 
T PrimeCounter<T>::incNumPrimes() {
	return numPrimes->fetch_add(1);
}

template <class T> 
void PrimeCounter<T>::pushToList(T n) {
	lock.lock();
	
	// Add this element into our priority queue
	q.push(n);
	
	// Remove the top (smallest) one.
	if(q.size() > N_HIGHEST_PRIME) q.pop();
	
	lock.unlock();
}

template <class T> 
void PrimeCounter<T>::printList(std::ofstream &f) {
	while(!q.empty()) {
		f << q.top() << (q.size() <= 1 ? "\n" : ", ");
		q.pop();
	}
}


// Template options
template class PrimeCounter<P_INT>;
template class PrimeCounter<int>;