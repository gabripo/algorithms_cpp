#include <iostream>

template<typename T, typename Comparator>
class Heap {
    private:
        T* heapArray;
        int numElements;
        int maxSize;
        void swap(T* array, int index1stElement, int index2ndElement);
        void siftdown(int nodePosition);
        void printFromNodeToLevel(int startingNode, int level) const;
    public:
        Heap(T* inputArray, int inputNumElements, int inputMaxSize);
        
        int size() const;
        bool isLeaf(int nodePosition) const;
        int leftChild(int nodePosition) const;
        int rightChild(int nodePosition) const;
        int parent(int nodePosition) const;
        void buildHeap();
        void insert(const T& elementToInsert);
        T removeFirst();
        T remove(int positionToRemove);
        void print() const;
};