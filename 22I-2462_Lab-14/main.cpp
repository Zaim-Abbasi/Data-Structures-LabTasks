#include "CityMap.h"

int main()
{
    CityMap city;

    int option;

    while (true)
    {
        cout << "\nMenu:\n"
                "1. Add Intersection\n"
                "2. Add Road\n"
                "3. Display City Map\n"
                "4. Find Shortest Path\n"
                "5. Exit\n"
                "Choose an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            int intersectionID;
            cout << "Enter Intersection ID: ";
            cin >> intersectionID;
            city.addIntersection(intersectionID);
            break;
        }
        case 2:
        {
            int source, destination, length;
            cout << "Enter Source Intersection ID: ";
            cin >> source;
            cout << "Enter Destination Intersection ID: ";
            cin >> destination;
            cout << "Enter Road Length: ";
            cin >> length;
            city.addRoad(source, destination, length);
            break;
        }
        case 3:
            city.displayCityMap();
            break;
        case 4:
        {
            int start, end;
            cout << "Enter Start Intersection ID: ";
            cin >> start;
            cout << "Enter End Intersection ID: ";
            cin >> end;

            city.findShortestPath(start, end);
            break;
        }
        case 5:
            return 0;
        }
    }

    return 0;
}
