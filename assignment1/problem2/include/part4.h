#include <iostream>
#include <cstdlib>
#include <vector>
#include <thread>
#include <mutex>
#include <queue>
#include <string>

std::mutex printStream;
std::mutex **forks;
std::mutex queueMutex;
int numPhilosophers;
std::queue<int> q;
void think(int, int thinkFor);
void eat(int, int eatFor);
void request(int id);
void drop(int id);
int generateDuration();