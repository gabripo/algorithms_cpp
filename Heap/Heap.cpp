#include "Heap.h"

template<typename T, typename Comparator>
Heap<T, Comparator>::Heap(T* inputArray, int inputNumElements, int inputMaxSize) {
    heapArray = inputArray;
    numElements = inputNumElements;
    maxSize = inputMaxSize;
    buildHeap();
}

template<typename T, typename Comparator>
void Heap<T, Comparator>::buildHeap() {
    for (int i = numElements/2 - 1; i >= 0 ; i--)
    {
        siftdown(i);
    }
}

template<typename T, typename Comparator>
T Heap<T, Comparator>::removeFirst() {
    if (numElements <= 0)
    {
        std::cout << "Heap is empty!" << std::endl;
    }
    swap(heapArray, 0, --numElements);
    if (numElements != 0)
    {
        siftdown(0);
    }
    return heapArray[numElements];
}

template<typename T, typename Comparator>
T Heap<T, Comparator>::remove(int positionToRemove) {
    if ( (positionToRemove < 0) && (positionToRemove >= numElements) )
    {
        std::cout << "Bad position!" << std::endl;
    }
    if (positionToRemove == (numElements-1))
    {
        numElements--;
    }
    else
    {
        swap(heapArray, positionToRemove, --numElements);
        while ( (positionToRemove != 0) && (Comparator::prior(heapArray[positionToRemove], heapArray[parent(positionToRemove)])) )
        {
            swap(heapArray, positionToRemove, parent(positionToRemove));
            positionToRemove = parent(positionToRemove);
        }
        if (numElements != 0)
        {
            siftdown(positionToRemove);
        }
        return heapArray[numElements];
    }   
}

template<typename T, typename Comparator>
void Heap<T, Comparator>::siftdown(int nodePosition) {
    while (!isLeaf(nodePosition))
    {
        int greaterChildCurrentNode = leftChild(nodePosition);
        int rightChildCurrentNode = rightChild(nodePosition);
        if ( (rightChildCurrentNode < numElements) && Comparator::prior(heapArray[rightChildCurrentNode], heapArray[greaterChildCurrentNode]) )
        {
            greaterChildCurrentNode = rightChildCurrentNode;
        }
        if (Comparator::prior(heapArray[nodePosition], heapArray[greaterChildCurrentNode]))
        {
            return;
        }
        swap(heapArray, nodePosition, greaterChildCurrentNode);
        nodePosition = greaterChildCurrentNode;
    }
}

template<typename T, typename Comparator>
void Heap<T, Comparator>::insert(const T& elementToInsert) {
    if (numElements >= maxSize)
    {
        std::cout << "Heap is full!" << std::endl;
        return;
    }
    int currentNodePosition = numElements++;
    heapArray[currentNodePosition] = elementToInsert;
    while ( (currentNodePosition != 0) && (Comparator::prior(heapArray[currentNodePosition], heapArray[parent(currentNodePosition)])) )
    {
        swap(heapArray, currentNodePosition, parent(currentNodePosition));
        currentNodePosition = parent(currentNodePosition);
    }
}

template<typename T, typename Comparator>
void Heap<T, Comparator>::swap(T* array, int index1stElement, int index2ndElement) {
    T temp = array[index1stElement];
    array[index1stElement] = array[index2ndElement];
    array[index2ndElement] = temp;
}

template<typename T, typename Comparator>
bool Heap<T, Comparator>::isLeaf(int nodePosition) const {
    return ( (nodePosition >= numElements/2) && (nodePosition < numElements) );
}

template<typename T, typename Comparator>
int Heap<T, Comparator>::leftChild(int nodePosition) const {
    return (2*nodePosition + 1);
}

template<typename T, typename Comparator>
int Heap<T, Comparator>::rightChild(int nodePosition) const {
    return (2*nodePosition + 2);
}

template<typename T, typename Comparator>
int Heap<T, Comparator>::parent(int nodePosition) const {
    return (nodePosition-1) / 2;
}

template<typename T, typename Comparator>
int Heap<T, Comparator>::size() const {
    return numElements;
}

template<typename T, typename Comparator>
void Heap<T, Comparator>::print() const {
    printFromNodeToLevel(0, 0);
}

template<typename T, typename Comparator>
void Heap<T, Comparator>::printFromNodeToLevel(int startingNode, int level) const {
    if (startingNode > numElements-1)
    {
        return;
    }
    printFromNodeToLevel(leftChild(startingNode), level+1);
    for (int i = 0; i < level; i++)
    {
        std::cout << "  ";
    }
    std::cout << heapArray[startingNode] << std::endl;
    printFromNodeToLevel(rightChild(startingNode), level+1);
}