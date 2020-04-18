#include <iostream>
#include <vector>
using namespace std;

// Data structure for Min Heap
class PriorityQueue
{

    int LEFT(int i) {return (2 * i + 1);}
    int RIGHT(int i) {return (2 * i + 2);}

    void Heapify(vector <int> &A,int i,int size)
    {
        int left = LEFT(i);
        int right = RIGHT(i);
        int largest = i;
        if (left < size && A[left] > A[i])  largest = left;
        if (right < size && A[right] > A[largest])   largest = right;
        if (largest != i) {
            swap(A[i], A[largest]);
            Heapify(A,largest,size);
        }
    }

public:


    PriorityQueue(vector<int> &arr, int n)
    {

        int i = (n - 2) / 2;
        while (i >= 0) Heapify(arr,i--,n);

    }

    int pop(vector <int> &arr,int size )
    {
        if (size <= 0) {return -1;}
        int top = arr[0];
        arr[0] = arr[size-1];
        size--;
        Heapify(arr,0,size);
        return top;
    }
};


void HeapSort(vector<int> &A, int n)
{

    PriorityQueue pq(A, n);
    while(n > 0) {
        A[n-1] = pq.pop(A,n);
        n--;
    }
}


int main()
{
    vector<int> A = { 6, 4, 7, 1, 9, -2};
    int n = A.size();
    HeapSort(A, n);
    for (int i = 0; i < n; ++i) cout << A[i] << " ";

    return 0;
}