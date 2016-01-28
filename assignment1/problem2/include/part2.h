#include <iostream>
#include <cstdlib>
#include <vector>
#include <thread>
#include <mutex>

std::mutex printStream;
std::mutex **forks;
int numPhilosophers;
void think(int, int thinkFor);
void eat(int, int eatFor);
int generateDuration();