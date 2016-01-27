#include "philosopher.h"

Philosopher::Philosopher(int inid) {
	id = inid;
	srand(time(NULL));
}

void Philosopher::eat(int eatFor) {
	std::cout << "Philosopher " << id << " is eating...\n";
	
	std::this_thread::sleep_for(std::chrono::seconds(eatFor));
	
	think(Philosopher::generateDuration());
}

void Philosopher::think(int thinkFor) {
	std::cout << "Philosopher " << id << " is eating...\n";
	
	std::this_thread::sleep_for(std::chrono::seconds(thinkFor));
	
	eat(Philosopher::generateDuration());
}

static int Philosopher::generateDuration() {
	return rand() % (MAX_WAIT + 1);
}