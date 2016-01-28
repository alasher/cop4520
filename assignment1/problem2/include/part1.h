#include <iostream>
#include <cstdlib>
#include <vector>
#include <thread>
#include <mutex>

std::mutex l;
std::mutex **forks;
int numPhilosophers;
void think(int, int thinkFor);
void eat(int, int eatFor);
int generateDuration();