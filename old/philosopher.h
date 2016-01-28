#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <cstdlib>
#include <iostream>
#include <thread>

#define MAX_WAIT 20 // Maximum think/wait wait period, in seconds

class Philosopher {
	
	std::thread t;
	int id;
	static int generateDuration();
	
	public:
		Philosopher(int inid);
		
		// a philosopher, when created, will cycle between eating and thinking
		void eat();
		void think();
};

#endif