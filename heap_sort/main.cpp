#include "../MaxComparator/MaxComparator.cpp"
#include "../Heap/Heap.cpp"
#include <iostream>

template<typename T, typename Comparator>
void heap_sort(T* arrayToSort, int arraySize);
template<typename T>
void swap(T* array, int firstPosition, int secondPosition);
template<typename T>
void print(T* arrayToPrint, int arraySize);


int main(int argc, char const *argv[])
{
    int arr[] = { 1, 10, 25, 4, 0 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    print<int>(arr, arrSize);

    heap_sort<int, MaxComparator<int> >(arr, arrSize);
    print<int>(arr, arrSize);

    return 0;
}

template<typename T, typename Comparator>
void heap_sort(T* arrayToSort, int arraySize) {
    T maxHeapVal;
    Heap<T, Comparator> heap(arrayToSort, arraySize, arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        maxHeapVal = heap.removeFirst();
    }
}

template<typename T>
void swap(T* array, int firstPosition, int secondPosition) {
    if (firstPosition == secondPosition)
    {
        return;
    }
    T temp = array[firstPosition];
    array[firstPosition] = array[secondPosition];
    array[secondPosition] = temp;
}

template<typename T>
void print(T* arrayToPrint, int arraySize) {
    std::cout << "[ ";
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << arrayToPrint[i] << " ";
    }
    std::cout << " ]" << std::endl;
}