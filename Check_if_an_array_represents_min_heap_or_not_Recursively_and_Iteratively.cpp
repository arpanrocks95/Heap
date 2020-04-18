#include <iostream>
using namespace std;

template <size_t n>

int checkMinHeapRecursively(int (&arr)[n], int index){
    if(2 * index + 2 > n) return 1;
    bool left = (arr[index] <= arr[2*index + 1]) && checkMinHeapRecursively(arr, 2*index + 1);
    bool right = (2*index + 2 == n) || (arr[index] <= arr[2*index + 2] && checkMinHeapRecursively(arr, 2*index + 2));
    return left && right;
}
template <size_t n>
int checkMinHeapIteratively(int (&arr)[n]){
    int len = (n-2)/2;
    for (int i = 0; i <= len; ++i) {
        if(arr[i] > arr[2 * i + 1] || ((2*i + 2 != n) && arr[i] > arr[i*2 + 2])) return 0;
    }
    return 1;
}
int main()
{
    int a[] =  {1, 2, 3, 4, 5, 6};   //{ 6, 4, 7, 1, 9, -2};
    if(checkMinHeapRecursively(a,0))    cout << "Yes\n";
    else    cout << "No\n";
    if(checkMinHeapIteratively(a))  cout << "Yes\n";
    else    cout << "No\n";


    return 0;
}