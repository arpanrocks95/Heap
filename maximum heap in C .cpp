#include <stdio.h>
#include <climits>

int array[20];
int capacity = 20;
int size = 0;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int parent(int i){  return (i - 1) / 2; }
int leftChild(int i ){  return (i * 2) + 1; }
int rightChild(int i ){ return (i * 2) + 2; }
int getMax() { return array[0]; }

void insertKey(int key){
    if (size == capacity) {printf("Heap is Overflow , Could not Insert"); return; }
    size++;
    int index = size - 1;
    array[index] = key;
    while( index != 0 && array[parent(index)] < array[index]){
        swap(&array[index],&array[parent(index)]);
        index = parent(index);
    }
}
void increaseKey(int index ,int new_value){
    array[index] = new_value;
    while( index != 0 && array[parent(index)] < array[index]){
        swap(&array[index],&array[parent(index)]);
        index = parent(index);
    }
}
void maxHeapify(int index){
    int l = leftChild(index);
    int r = rightChild(index);
    int greatest = index;
    if (l < size && array[l] > array[index])
        greatest = l;
    if (r < size && array[r] > array[greatest])
        greatest = r;
    if (greatest != index)
    {
        swap(&array[index], &array[greatest]);
        maxHeapify(greatest);
    }
}

int extractMin(){
    if(size <= 0) return INT_MIN;
    if(size == 1) { size--; return array[0] ;}
    int root = array[0];
    array[0] = array[size - 1];
    size--;
    maxHeapify(0);
    return root;
}
void deleteKey(int index){
    increaseKey(index,INT_MAX);
    extractMin();
}

int main(){
    insertKey(3);
    insertKey(2);
    deleteKey(1);
    insertKey(15);
    insertKey(5);
    insertKey(4);
    insertKey(45);
    for (int i = 0; i < size; ++i) {
        printf("%d ",array[i]);
    }
    printf("\n");
    increaseKey(2,10);
    for (int i = 0; i < size; ++i) {
        printf("%d ",array[i]);
    }

    return 0;
}