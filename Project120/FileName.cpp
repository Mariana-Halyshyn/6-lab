#include <iostream>
#include <algorithm> 
#include <locale> 
using namespace std;

// Шаблонна функція для знаходження максимального значення елементів масиву
template <typename T>
T maxElement(T* arr, int size) {
    T maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Шаблонний клас для сортування 
template <typename T>
class ArraySorter {
private:
    T* arr;
    int size;

public:
    
    ArraySorter(T* array, int s) : arr(array), size(s) {} // Конструктор

    void sortDescending() { // сортуванння масиву
        std::sort(arr, arr + size, [](T a, T b) { return a > b; });
    }

    void printArray() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
  
    setlocale(LC_ALL, "ukr");

    double doubleArr[] = { 3.1, 5.5, 4.2, 5.8, 6.2, 3, 9.03 };
    int size = sizeof(doubleArr) / sizeof(doubleArr[0]);

 
    cout << "Масив: ";
    for (int i = 0; i < size; i++) {
        cout << doubleArr[i] << " ";
    }
    cout << endl;

    cout << "Максимальний елемент масиву: " << maxElement(doubleArr, size) << endl;

    ArraySorter<double> sorter(doubleArr, size);
    sorter.sortDescending();
    cout << "Відсортований масив у порядку спадання: ";
    sorter.printArray();

    return 0;
}

