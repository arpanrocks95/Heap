#include <iostream>
using namespace std;
/*
 * We can easily solve this problem in O(n + klogn) by using a max-heap.
 * The idea is to simply construct a max-heap of size n and insert all elements of the array (A[0..n-1]) into it.
 * Then we pop first k-1 elements from it. Now k’th largest element will reside at the root of the max-heap.
 */
class MaxHeap{

    int left(int i) {return (2 * i + 1);}
    int right(int i) {return (2 * i + 2);}
    void Heapify(int A[], int i, int size)
    {

        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < size && A[l] > A[i]) {largest = l;}
        if (r < size && A[r] > A[largest]) {largest = r;}
        if (largest != i) {
            swap(A[i], A[largest]);
            Heapify(A, largest, size);
        }
    }
public:
    template<size_t n>
    MaxHeap(int (&A) [n]){
        int i = (n - 2) / 2;
        while(i >= 0){
            Heapify(A,i--,n);
        }
    }
    template<size_t n>
    int pop(int (&A) [n]){
        if(n <= 0) return -1;
        int top = A[0];
        A[0] = A[n-1];
        Heapify(A,0,n);
        return top;
    }

};


int main() {

    int A[] = {7, 4, 6, 3, 9, 1};
    MaxHeap pq(A);
    for (int i = 0; i < (*(&A + 1) - A); i++) {
        cout << A[i] << " ";
    }
    cout <<"\nEnter the K  value\n";
    int k ;
    cin >> k;
    while(--k) pq.pop(A);
    for (int i = 0; i < (*(&A + 1) - A); i++) {
        cout << A[i] << " ";
    }

    return 0;
}