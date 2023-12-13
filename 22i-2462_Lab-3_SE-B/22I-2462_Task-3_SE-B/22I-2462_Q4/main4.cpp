#include <iostream>
using namespace std;
template <typename T>
class MyVector {
private:
    T* data;
    int size, capacity;   
public:
    MyVector() {
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    void addElement(T element) {
        if (size == capacity) { 
            //yani full ha, or is case me ek or banana ha
            if (capacity == 0)
                capacity = 1;
            else
            {
                capacity = capacity * 2;
            }
            T* newData = new T[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size] = element;
        size++;
    }
    T getElement(int index) {
        if (index < 0 || index >= size) {
            //excaptional
            cout << "No such Index" << endl;
            return 0;
        }
            return data[index];
    }
    void changeElement(int index, T newValue) {
        if (index < 0 || index >= size) {
            cout << "No such Index" << endl;
            exit(0);
        }
        data[index] = newValue;
    }

    // Remove an element at a specific index
    void removeElement(int index) {
        if (index < 0 || index >= size) {
            cout << "No such Index" << endl;
            return;
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    // Get the current size of the vector
    int getSize() const {
        return size;
    }
    ~MyVector() {
        delete[] data;
    }
};

int main() {
    MyVector<int> intVector;
    int element;
    cout << "Enter element to add:";
    cin >> element;
    intVector.addElement(element);

    cout << "Enter element to add:";
    cin >> element;
    intVector.addElement(element);

    cout << "Enter element to add:";
    cin >> element;
    intVector.addElement(element);

    cout << "Displaying all elements:";
    cout<<intVector.getElement(0)<<endl;
    cout<<intVector.getElement(1)<<endl;
    cout<<intVector.getElement(2)<<endl;

    cout<<"Enter index to change element:";
    int index;
    cin>>index;
    cout<<"Enter a number to change element:";
    int value;
    cin>>value;
    intVector.changeElement(index,value);

    cout<<"Enter an element to remove it with it's index:";
    int index2;
    cin>>index2;
    intVector.removeElement(index2);

    cout << "Vector size: " << intVector.getSize() << std::endl;

    for (int i = 0; i < intVector.getSize(); i++) {
        std::cout << "Element " << i << ": " << intVector.getElement(i) << std::endl;
    }

    return 0;
}
