#include "part3.h"
#define MAX_WAIT 10

using namespace std;

int main(int argc, char **argv){
	
	printStream.lock();
	cout << "Dining Philosophers v3 - Starvation Free\nPress CTRL+C to terminate.\n\n";
	printStream.unlock();
	
	srand(time(NULL));
	
	// Make this constant 5, for now
	int i;
	numPhilosophers = 5;
	
	vector<thread> philosophers;
	forks = (mutex **) malloc(sizeof(mutex*) * numPhilosophers);
	
	// The number of forks is equal to the number of philosophers
	// A philosopher, k, uses forks k and k+1 to eat...
	// except the last philosopher, k = n-1, who uses forks n-1 and 0.
	for(i=0; i < numPhilosophers; i++) {
		forks[i] = new mutex();
	}
	
	for(i=0; i < numPhilosophers; i++) {
		philosophers.push_back(thread(think, i, generateDuration()));
	}
	
	for(i=0; i < numPhilosophers; i++) {
		philosophers[i].join();
	}
	
	
	free(forks);
	
	return 0;
}

void think(int id, int thinkFor) {
	printStream.lock();
	cout << "philosopher "<< id << " thinking for " << thinkFor << " second(s).\n";
	printStream.unlock();
	
	// Spend some time thinking
	this_thread::sleep_for(chrono::seconds(thinkFor));
	
	// Spend time in here, waiting for some darn chopsticks
	request(id);
	
	// once we're here, we can successfully eat. Finally!
	eat(id, generateDuration());
}

void eat(int id, int eatFor) {
	printStream.lock();
	cout << "philosopher "<< id << " eating for " << eatFor << " second(s).\n";	
	printStream.unlock();
	
	this_thread::sleep_for(chrono::seconds(eatFor));
	
	drop(id);
	
	think(id, generateDuration());
}

// Request to eat, jump onto the queue if necessary
// Stay in here until we're allowed to eat
void request(int id) {
	
	queueMutex.lock();
	q.push(id);
	queueMutex.unlock();
	
	int forkA = id, forkB = (id == numPhilosophers-1) ? 0 : forkA + 1;
	
	// try to grab the fork with the *lower* ID
	forks[(forkA < forkB) ? forkA : forkB]->lock();
	
	// now, try to grab the other one!
	forks[(forkA < forkB) ? forkB : forkA]->lock();
}

void drop(int id) {
	
	queueMutex.lock();
	q.pop();
	queueMutex.unlock();
	
	int forkA = id, forkB = (id == numPhilosophers-1) ? 0 : forkA + 1;
	
	forks[forkB]->unlock();
	forks[forkA]->unlock();
}

int generateDuration() {
	return rand() % (MAX_WAIT + 1);
}