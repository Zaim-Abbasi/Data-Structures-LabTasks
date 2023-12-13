#include "intersection.h"

class CityMap
{
private:
    Road *roads[MAX_INTERSECTIONS];
    Intersection intersections[MAX_INTERSECTIONS];

public:
    CityMap() {}

    void addIntersection(int intersectionID){
        
    }

    void addRoad(int source, int destination, int length)
    {
        Road *newRoad = new Road(destination, length);
        newRoad->next = intersections[source].roads;
        intersections[source].roads = newRoad;

        // Add the road in both directions (undirected graph)
        newRoad = new Road(source, length);
        newRoad->next = intersections[destination].roads;
        intersections[destination].roads = newRoad;
    }

    void displayCityMap()
    {
        cout << "City Map:\n";
        for (int i = 0; i < MAX_INTERSECTIONS; ++i)
        {
            if (intersections[i].roads != nullptr)
            {
                cout << "Intersection " << i << " connected to:\n";
                Road *currentRoad = intersections[i].roads;
                while (currentRoad != nullptr)
                {
                    cout << "  Intersection " << currentRoad->destination
                         << " (Length: " << currentRoad->length << ")\n";
                    currentRoad = currentRoad->next;
                }
            }
        }
    }

    void findShortestPath(int start, int end)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int distance[MAX_INTERSECTIONS];
        int parent[MAX_INTERSECTIONS];

        for (int i = 0; i < MAX_INTERSECTIONS; ++i)
        {
            distance[i] = INT_MAX;
            parent[i] = -1;
        }

        pq.push({0, start});
        distance[start] = 0;

        while (!pq.empty())
        {
            int current = pq.top().second;
            pq.pop();

            Road *currentRoad = intersections[current].roads;
            while (currentRoad != nullptr)
            {
                int next = currentRoad->destination;
                int weight = currentRoad->length;

                if (distance[current] + weight < distance[next])
                {
                    distance[next] = distance[current] + weight;
                    parent[next] = current;
                    pq.push({distance[next], next});
                }

                currentRoad = currentRoad->next;
            }
        }

        // Display the shortest path
        cout << "Shortest Path: ";
        int current = end;
        vector<int> path;
        while (current != -1)
        {
            path.push_back(current);
            current = parent[current];
        }

        for (auto it = path.rbegin(); it != path.rend(); ++it)
        {
            cout << *it << " ";
        }
        cout << "\n";
    }
};
