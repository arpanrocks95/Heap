#include <iostream>
using namespace std;

class MinHeap{

    int left(int i) {return (2 * i + 1);}
    int right(int i) {return (2 * i + 2);}
    void Heapify(int A[], int i, int size)
    {

        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < size && A[l] < A[i]) {smallest = l;}
        if (r < size && A[r] < A[smallest]) {smallest = r;}
        if (smallest != i) {
            swap(A[i], A[smallest]);
            Heapify(A, smallest, size);
        }
    }
public:
    template<size_t n>
    MinHeap(int (&A) [n]){
        int i = (n - 2) / 2;
        while(i >= 0){
            Heapify(A,i--,n);
        }
    }
    template<size_t n>
    int pop(int (&A) [n]){
        if(n <= 0) return -1;
        A[0] = A[n-1];
        int top = A[0];
        Heapify(A,0,n);
        return top;
    }
};


int main() {
/*
               9

          4		 7

        1   -2	  6	  5

    */

    int A[] = {9, 4, 7, 1, -2, 6, 5};
    MinHeap pq(A);

    /*
               -2

          1		 5

        9	4	  6	  7	 */

    for (int i = 0; i < (*(&A + 1) - A); i++) {
        cout << A[i] << " ";
    }

    return 0;
}