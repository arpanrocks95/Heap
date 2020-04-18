#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
 * We can easily solve this problem in O(nlogk) by using a min-heap.
 * The idea is to construct a min-heap of size k and insert first k elements of array (A[0..k-1]) into the heap.
 * Then for each of the remaining element of the array (A[k..n-1]),
 * if that element is more than the root of the heap, we replace the root with current element.
 * We repeat this process till array is exhausted.
 * Now we will be left with k largest elements of the array in the min-heap and k’th largest element will reside at the root of the min-heap.
 */
int FindKthLargest(vector<int> const &A, int k)
{
    priority_queue<int, vector<int>, greater<>> pq(A.begin(), A.begin() + k);

    for (int i = k; i < A.size(); i++)
    {
        if (A[i] > pq.top())
        {
            pq.pop();
            pq.push(A[i]);
        }
    }

    return pq.top();
}

int main()
{
    vector<int> A  = { 7, 4, 6, 3, 9, 1 };
    int k = 2;

    cout << "K'th largest element in the array is " <<
         FindKthLargest(A, k);

    return 0;
}