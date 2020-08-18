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
};




int main(){
    priorityQueue pq1;
    pq1.push(10);
    cout << pq1.peek() << " ";
    pq1.push(20);
    cout << pq1.peek() << " ";
    pq1.push(5);
    cout << pq1.peek() << " ";

    pq1.pop();

    cout <<"\n" <<  pq1.peek() << " ";
    pq1.pop();

    cout <<  pq1.peek() << " ";

    pq1.pop();

    pq1.peek();
    
    pq1.pop();
    return 0;
}