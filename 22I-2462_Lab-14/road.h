#include <iostream>
#include <queue>
using namespace std;
const int MAX_INTERSECTIONS = 100; // Adjust the maximum number of intersections if needed

// roads: edges
class Road
{
public:
    int destination;
    int length;
    Road *next;
    Road(int dest, int len) : destination(dest), length(len), next(nullptr) {}
};