#include "../MaxComparator/MaxComparator.cpp"
#include <iostream>

template<typename T, typename Comparator>
void quick_sort(T* arrayToSort, int left, int right);
template<typename T, typename Comparator>
int find_pivot(T* arrayToPartition, int left, int right);
template<typename T>
void swap(T* array, int firstPosition, int secondPosition);
template<typename T, typename Comparator>
int partition(T* arrayToPartition, int left, int right, T& pivot);
template<typename T>
void print(T* arrayToPrint, int arraySize);


int main(int argc, char const *argv[])
{
    int arr[] = { 1, 10, 25, 4, 0 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    print<int>(arr, arrSize);

    quick_sort<int, MaxComparator<int> >(arr, 0, arrSize-1);
    print<int>(arr, arrSize);

    return 0;
}

template<typename T, typename Comparator>
void quick_sort(T* arrayToSort, int left, int right) {
    if (right <= left)
    {
        return;
    }
    int pivotIndex = find_pivot<T, Comparator>(arrayToSort, left, right);
    swap(arrayToSort, pivotIndex, right);
    int frstPositionRightSubarray = partition<T, Comparator>(arrayToSort, left-1, right, arrayToSort[right]);
    swap(arrayToSort, frstPositionRightSubarray, right);
    quick_sort<T, Comparator>(arrayToSort, left, frstPositionRightSubarray-1);
    quick_sort<T, Comparator>(arrayToSort, frstPositionRightSubarray+1, right);
}

template<typename T, typename Comparator>
int find_pivot(T* arrayToPartition, int left, int right) {
    return (left+right) / 2;
}

template<typename T>
void swap(T* array, int firstPosition, int secondPosition) {
    T temp = array[firstPosition];
    array[firstPosition] = array[secondPosition];
    array[secondPosition] = temp;
}

template<typename T, typename Comparator>
int partition(T* arrayToPartition, int left, int right, T& pivot) {
    do
    {
        while (Comparator::prior(arrayToPartition[++left], pivot)) { };
        while ( (left < right) && Comparator::prior(pivot, arrayToPartition[--right]) ) { };
        swap(arrayToPartition, left, right);
    } while (left < right);
    return left;
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