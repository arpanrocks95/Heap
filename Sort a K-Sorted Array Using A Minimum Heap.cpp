#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

struct priorityQueue{
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
        if(right < size() && A[index] > A[right])
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

template <size_t n>
void sortKsortedArray(int (&A) [n],int k){
    priorityQueue pq1;
    for (int i = 0; i <= k  ; ++i) {
        pq1.push(A[i]);
    }
    int index = 0;
    for (int j = k + 1; j < n ; ++j) {
        A[index++] = pq1.pop();
        pq1.push(A[j]);
    }
    while(!pq1.empty()){
        A[index++] = pq1.pop();
    }
}


int main(){
    int  A[] = { 1, 4, 5, 2, 3, 7, 8, 6, 10, 9};
    int k = 2;
    sortKsortedArray(A,k);
    for(int &i : A){
        cout << i << " ";
    }

    return 0;
}