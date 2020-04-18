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


vector <int> Sort(vector <int> list[],int M){
    priorityQueue pq1;
    vector <int> sortedArray;
    vector <int> startindex;
    for (int i = 0; i < M ; ++i) {
        pq1.push(list[i][0]);
        startindex.push_back(0);
    }

    while(!pq1.empty()){
        sortedArray.push_back(pq1.pop());
        for (int i = 0; i < M ; ++i) {
            if(sortedArray[sortedArray.size() - 1] == list[i][startindex[i]] && (startindex[i]+1 !=list[i].size() )){
                startindex[i] = startindex[i] + 1;
                pq1.push(list[i][startindex[i]]);
            }
        }

    }
    return sortedArray;
}


int main(){
    vector<int> list[] =
            {
                    { 10, 20, 30, 40 },
                    { 15, 25, 35 },
                    { 27, 29, 37, 48, 93 },
                    { 32, 33 }
            };

    int M = sizeof(list) / sizeof(list[0]);
    vector<int> a = Sort(list, M);
    for(int &i : a) cout << i <<" ";
    return 0;
}