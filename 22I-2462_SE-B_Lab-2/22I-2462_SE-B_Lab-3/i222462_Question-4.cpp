#include <iostream>
#include <string>
using namespace std;
// Define a template class for boxes
template <typename T>
class StockBox
{
private:
    T label;

public:
    StockBox(const T &label) : label(label) {}

    T getLabel() const
    {
        return label;
    }
};

// Define a class to manage the collection of stock boxes
template <typename T>
class StockManager
{
public:
    StockManager(int capacity) : capacity(capacity), size(0)
    {
        boxes = new StockBox<T>[capacity];
    }

    ~StockManager()
    {
        delete[] boxes;
    }

    void addBox(const StockBox<T> &box)
    {
        if (size < capacity)
        {
            boxes[size] = box;
            size++;
        }
    }

    void displayCollection()
    {
        for (int i = 0; i < size; i++)
        {
            cout << boxes[i].getLabel() << endl;
        }
        // 
        
    }

    StockBox<T> findBoxWithHighestValue()
    {
        if (size == 0)
        {
            throw logic_error("No boxes in the collection.");
        }

        StockBox<T> maxBox = boxes[0];
        for (int i = 1; i < size; i++)
        {
            if (boxes[i].getLabel() > maxBox.getLabel())
            {
                maxBox = boxes[i];
            }
        }

        return maxBox;
    }

private:
    StockBox<T> *boxes;
    int capacity;
    int size;
};

int main()
{
    int capacity = 30;
    StockManager<int> intBoxManager(capacity);            // Manage boxes with integer labels
    StockManager<double> doubleBoxManager(capacity);      // Manage boxes with double labels
    StockManager<string> stringBoxManager(capacity); // Manage boxes with string labels

    // Simulate receiving 30 boxes with different labels
    for (int i = 0; i < 10; i++)
    {
        intBoxManager.addBox(StockBox<int>(i));
        doubleBoxManager.addBox(StockBox<double>(i * 10.0));
        stringBoxManager.addBox(StockBox<string>("Label_" + to_string(i)));
    }

    // Display the collection of each type of boxes
    cout << "Collection of integer boxes:" << endl;
    intBoxManager.displayCollection();

    cout << "\nCollection of double boxes:" << endl;
    doubleBoxManager.displayCollection();

    cout << "\nCollection of string boxes:" << endl;
    stringBoxManager.displayCollection();

    // Find the box with the highest value
    StockBox<int> maxIntBox = intBoxManager.findBoxWithHighestValue();
    StockBox<double> maxDoubleBox = doubleBoxManager.findBoxWithHighestValue();
    StockBox<string> maxStringBox = stringBoxManager.findBoxWithHighestValue();

    cout << "\nBox with the highest integer label: " << maxIntBox.getLabel() << endl;
    cout << "Box with the highest double label: " << maxDoubleBox.getLabel() << endl;
    cout << "Box with the highest string label: " << maxStringBox.getLabel() << endl;

    return 0;
}
