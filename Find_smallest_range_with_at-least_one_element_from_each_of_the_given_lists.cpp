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
    void transfer(vector <int> &B){
        for (int i = 0; i < size(); ++i) {
            B.push_back(A[i]);
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
int checkInRange(vector <int> &A){

    int cond = 1;
    if(A[A.size() -2 ] > A[A.size() - 1]){
        int temp = A[A.size() -2 ];
        A[A.size() -2 ] =A[A.size() - 1];
        A[A.size() - 1 ] = temp;
    }
    for (int i = 0; i < A.size() -1; ++i) {
        if(A[i] - A[i+1] != -1) cond = 0;
    }
    return cond;
}

vector <int> smallestRange(vector <int> list[],int M){


    int cond = 0;
    priorityQueue pq1;
    vector <int> sortedArray;
    vector <int> startindex;

    for (int i = 0; i < M ; ++i) {
        pq1.push(list[i][0]);
        startindex.push_back(0);
    }

    while(!cond){
        vector <int> temppq;
        pq1.transfer(temppq);
        cond = checkInRange(temppq);
        if(cond) {return temppq;}
        sortedArray.push_back(pq1.pop());
        for (int i = 0; i < M ; ++i) {
            if(sortedArray[sortedArray.size() - 1] == list[i][startindex[i]] && (startindex[i]+1 !=list[i].size() )){
                startindex[i] = startindex[i] + 1;
                pq1.push(list[i][startindex[i]]);
            }
        }

    }

}


int main(){

    vector<int> list[] =
            {
                    {2, 3, 4, 8, 10, 15},
                    {1, 5, 12 },
                    {7, 8, 15, 16 },
                    {3, 6}
            };

    int M = sizeof(list) / sizeof(list[0]);
    vector <int> A = smallestRange(list, M);
    cout << "smallest range with at least one element from all the lists :";for(int &i: A) cout << i <<" ";
    return 0;
}