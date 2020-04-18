#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>
#include<time.h>
using namespace std;
struct minHeapNode{
    int data;
    int noOfArray;
};
struct comp{
    bool operator()(const minHeapNode lhs,const minHeapNode rhs){
        return lhs.data > rhs.data;
    }
};


FILE* openFile(char* fileName, char const * mode)
{
    FILE* fp = fopen(fileName, mode);
    if (fp == NULL){
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    return fp;
}

void mergeFiles(char * output_file,int sizeOfPartitions,int  partitions){
    FILE * in[partitions];
    char  filename[2];
    for (int i =0; i <partitions; ++i) {
        snprintf(filename, sizeof(filename),"%d",i); // converting i to string
        in[i] = openFile(filename,"r");
    }

    FILE *out = openFile(output_file, "w");

    minHeapNode harr[partitions];
    priority_queue<minHeapNode,vector<minHeapNode>,comp> pq;

    int i;
    for (i = 0; i < partitions; i++)
    {

        if (fscanf(in[i], "%d ", &harr[i].data) != 1)
            break;
        harr[i].noOfArray = i;
        pq.push(harr[i]);
    }

    int count = 0;

    while (count != i)
    {

        minHeapNode root = pq.top();
        pq.pop();
        fprintf(out, "%d ", root.data);

        if (fscanf(in[root.noOfArray], "%d ", &root.data) != 1 )
        {
            root.data = numeric_limits<int>::max();
            count++;
        }

        pq.push(root);
    }

    for (int i = 0; i < partitions; i++)
        fclose(in[i]);

    fclose(out);
}

void createInitialRuns(char * input_file,int sizeOfPartitions,int partitions){
    FILE * in = openFile(input_file,"r");
    FILE * out[partitions];
    char  filename[2];
    for (int i =0; i <partitions; ++i) {
        snprintf(filename, sizeof(filename),"%d",i); // converting i to string
        out[i] = openFile(filename,"w");
    }
    int * arr = new int[sizeOfPartitions];
    int cond = 1;
    int nextfile = 0;
    int i ;
    while(cond){
        for (i = 0; i < sizeOfPartitions; i++)
        {
            if (fscanf(in, "%d ", &arr[i]) != 1)
            {
                cond = false;
                break;
            }
        }
        sort(arr,arr+i);
        for (int j = 0; j < i; j++)
            fprintf(out[nextfile], "%d ", arr[j]);

        nextfile++;
    }
    delete(arr);
    for (int i = 0; i < partitions; i++)
        fclose(out[i]);

    fclose(in);
}
int main()
{
    int partitions = 10;
    int sizeOfPartitions = 1000;
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";

    FILE* in = openFile(input_file, "w");

    srand(time(NULL));

    for (int i = 0; i <partitions * sizeOfPartitions ; ++i) fprintf(in,"%d ",rand());
    fclose(in);

    createInitialRuns(input_file,sizeOfPartitions,partitions);

    mergeFiles(output_file, sizeOfPartitions, partitions);
    return 0;
}