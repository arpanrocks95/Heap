#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
struct priorityQueueMax{
private:
    vector <int> A;
    int parent(int i){
        return (i - 1) /2;
    }
    int leftChild(int i){
        return (2 * i) + 1;
    }
    int rightChild(int i){
        return (2 * i) + 2;
    }

    void heapifyUp(int index){

        if(index && A[parent(index)] < A[index]){
            swap(A[parent(index)],A[index]);
            heapifyUp(parent(index));
        }

    }

    void heapifyDown(int index ){
        int left = leftChild(index);
        int right = rightChild(index);
        int smallest = index;
        if(left < size() && A[index] < A[left])
            smallest = left;
        if(right < size() && A[index] < A[right])
            smallest = right;
        if(smallest != index){
            swap(A[index],A[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    unsigned int size(){
        return A.size();
    }

    bool empty(){
        return size() == 0;
    }

    void push(int key){
        A.push_back(key);
        int index = size() - 1;
        heapifyUp(index);
    }

    void pop(){
        try{
            if ( size() == 0) throw  out_of_range("Vector<X>::at() : " "index is out of range(Heap underflow)");
            A[0] = A.back();
            A.pop_back();
            heapifyDown(0);
        }
        catch (const out_of_range& oor) {
            cout << "\n" << oor.what();
        }
    }
    int peek(){
        try {
            if(size() == 0) throw out_of_range("Vector<X>::at() : " "index is out of range(Heap underflow)");
            return A.front();
        }catch(const out_of_range& oor){
            cout << "\n" << oor.what();
        }
    }
    void viewpq(){
        for (int i = 0; i < size(); ++i) {
            cout << A[i] << " ";
        }
    }
};

struct priorityQueueMin{
private:
    vector <int> A;
    int parent(int i){
        return (i - 1) /2;
    }
    int leftChild(int i){
        return (2 * i) + 1;
    }
    int rightChild(int i){
        return (2 * i) + 2;
    }

    void heapifyUp(int index){

        if(index && A[parent(index)] > A[index]){
            swap(A[parent(index)],A[index]);
            heapifyUp(parent(index));
        }

    }

    void heapifyDown(int index ){
        int left = leftChild(index);
        int right = rightChild(index);
        int smallest = index;
        if(left < size() && A[index] > A[left])
            smallest = left;
        if(right < size() && A[index] > A[right] && A[smallest] > A[right])
            smallest = right;
        if(smallest != index){
            swap(A[index],A[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    unsigned int size(){
        return A.size();
    }

    bool empty(){
        return size() == 0;
    }
    void viewpq(){
        for (int i = 0; i < size(); ++i) {
            cout << A[i] << " ";
        }
    }
    void push(int key){
        A.push_back(key);
        int index = size() - 1;
        heapifyUp(index);
    }

    int pop(){
        try{
            if ( size() == 0) throw  out_of_range("Vector<X>::at() : " "index is out of range(Heap underflow)");
            int top = A[0];
            A[0] = A.back();
            A.pop_back();
            heapifyDown(0);
            return top;
        }
        catch (const out_of_range& oor) {
            cout << "\n" << oor.what();
        }
    }
    int peek(){
        try {
            if(size() == 0) throw out_of_range("Vector<X>::at() : " "index is out of range(Heap underflow)");
            return A.front();
        }catch(const out_of_range& oor){
            cout << "\n" << oor.what();
        }
    }
};
/*
 * We can easily solve this problem in O(n + klogn) by using a min-heap.
 * The idea is to simply construct a min-heap of size n and insert all elements of the array (A[0..n-1]) into it.
 * Then we pop first k-1 elements from it. Now k’th smallest element will reside at the root of the min-heap.
 */
template <size_t n>
int findKthSmallestUsingMinHeap(int (&A)[n],int k){
    priorityQueueMax pq1;
    for (int &i : A) pq1.push(i);
    for (int j = 1; j < k; ++j) pq1.pop();
    return pq1.peek();
}

/*
 *We can easily solve this problem in O(nlogk) by using a max-heap.
 * The idea is to construct a max-heap of size k and insert first k elements of array (A[0..k-1]) into the heap.
 * Then for each of the remaining element of the array (A[k..n-1]),
 * if that element is less than the root of the heap, we replace the root with current element.
 * We repeat this process till array is exhausted.
 * Now we will be left with k smallest elements of the array in the max-heap and k’th smallest element will reside at the root of the max-heap.
 *
 * */



template <size_t n>
int findKthSmallestUsingMaxHeap(int (&A)[n],int k){
    priorityQueueMax pq1;
    for (int j = 0; j < k; ++j) pq1.push(A[j]);
    pq1.viewpq();
    cout << "\n";
    for (int i = k ; i < n; ++i) {
        if(A[i] < pq1.peek()) {
            pq1.pop();
            pq1.push(A[i]);
        }
    }
    return pq1.peek();
}

int main(){
    int a[]  = { 7, 4, 6, 3, 9, 1 };
    const size_t k = 3;

    cout << "K'th smallest element in the array is " << findKthSmallestUsingMinHeap(a, k) << "\n";
    cout << "K'th smallest element in the array is " << findKthSmallestUsingMaxHeap(a, k);

    return 0;
}