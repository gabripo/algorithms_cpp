#include "../MaxComparator/MaxComparator.cpp"
#include <iostream>

template<typename T, typename Comparator>
void shell_sort(T* arrayToSort, int arraySize);
template<typename T, typename Comparator>
void insertion_sort_2(T* arrayToSort, int arraySize, int increment);
template<typename T>
void swap(T* array, int firstPosition, int secondPosition);
template<typename T>
void print(T* arrayToPrint, int arraySize);


int main(int argc, char const *argv[])
{
    int arr[] = { 1, 10, 25, 4, 0, 19, 11, 23 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    print<int>(arr, arrSize);

    shell_sort<int, MaxComparator<int> >(arr, arrSize);
    print<int>(arr, arrSize);

    return 0;
}

template<typename T, typename Comparator>
void shell_sort(T* arrayToSort, int arraySize) {
    for (int i = arraySize/2; i > 2 ; i /= 2)
    {
        for (int j = 0; j < i; j++) {
            insertion_sort_2<int, Comparator>(&arrayToSort[j], arraySize-j, i);
        }
    }
    insertion_sort_2<int, Comparator>(arrayToSort, arraySize, 1);
}

template<typename T, typename Comparator>
void insertion_sort_2(T* arrayToSort, int arraySize, int increment) {
    for (int i = increment; i < arraySize; i += increment)
    {
        for (int j = i; (j >= increment) && (Comparator::prior(arrayToSort[j], arrayToSort[j-increment])) ; j -= increment)
        {
            swap(arrayToSort, j, j-increment);  
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