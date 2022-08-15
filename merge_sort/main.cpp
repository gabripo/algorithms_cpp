#include "../MaxComparator/MaxComparator.cpp"
#include <iostream>

template<typename T, typename Comparator>
void merge_sort(T* arrayToSort, T* tempArray, int left, int right);
template<typename T>
void swap(T* array, int firstPosition, int secondPosition);
template<typename T>
void print(T* arrayToPrint, int arraySize);


int main(int argc, char const *argv[])
{
    int arr[] = { 1, 10, 25, 4, 0 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    print<int>(arr, arrSize);

    int* tempArray = new int[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        tempArray[i] = arr[i];
    }
    merge_sort<int, MaxComparator<int> >(arr, tempArray, 0, arrSize-1);
    print<int>(arr, arrSize);

    return 0;
}

template<typename T, typename Comparator>
void merge_sort(T* arrayToSort, T* tempArray, int left, int right) {
    if (left == right)
    {
        return;
    }
    int mid = left + (right-left)/2;
    merge_sort<T, Comparator>(arrayToSort, tempArray, left, mid);
    merge_sort<T, Comparator>(arrayToSort, tempArray, mid+1, right);
    for (int i = left; i < right; i++)
    {
        tempArray[i] = arrayToSort[i];
    }
    // Merge operation back to arrayToSort
    int sublistLimitLeft = left;
    int sublistLimitRight = mid+1;
    for (int current = left; current <= right; current++) {
        if (sublistLimitLeft == mid+1)
        {
            arrayToSort[current] = tempArray[sublistLimitRight++];
        } else if (sublistLimitRight > right)
        {
            arrayToSort[current] = tempArray[sublistLimitLeft++];
        } else if (Comparator::prior(tempArray[sublistLimitLeft], tempArray[sublistLimitRight]))
        {
            arrayToSort[current] = tempArray[sublistLimitLeft++];
        } else
        {
            arrayToSort[current] = tempArray[sublistLimitRight++];
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