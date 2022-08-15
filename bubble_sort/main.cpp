#include "../MaxComparator/MaxComparator.cpp"
#include <iostream>

template<typename T, typename Comparator>
void bubble_sort(T* arrayToSort, int arraySize);
template<typename T>
void swap(T* array, int firstPosition, int secondPosition);
template<typename T>
void print(T* arrayToPrint, int arraySize);


int main(int argc, char const *argv[])
{
    int arr[] = { 1, 10, 25, 4, 0 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    print<int>(arr, arrSize);

    bubble_sort<int, MaxComparator<int> >(arr, arrSize);
    print<int>(arr, arrSize);

    return 0;
}

template<typename T, typename Comparator>
void bubble_sort(T* arrayToSort, int arraySize) {
    for (int i = 0; i < arraySize-1; i++)
    {
        for (int j = arraySize-1; j > i ; j--)
        {
            if (Comparator::prior(arrayToSort[j], arrayToSort[j-1])) {
                swap(arrayToSort, j, j-1);  
            }
        }
    }
}

template<typename T>
void swap(T* array, int firstPosition, int secondPosition) {
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