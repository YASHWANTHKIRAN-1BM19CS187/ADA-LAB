#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void displaySubset(int subset[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", subset[i]);
    printf("\n");
}

void subsetSum(int set[], int subset[], int n, int subsize, int total, int nodecount, int sum){
    if(total == sum)
    {
        displaySubset(subset, subsize);
        subsetSum(set, subset, n, subsize - 1, total - set[nodecount], nodecount + 1, sum);
        return;
    }
    else
    {
        for(int i = nodecount; i < n; i++)
        {
            subset[subsize] = set[i];
            subsetSum(set, subset, n, subsize + 1, total + set[i], i + 1, sum);
        }
    }
}

void findSubset(int set[], int size, int sum)
{
    int subset[size];
    subsetSum(set, subset, size, 0, 0, 0, sum);
}

int main()
{
    freopen("output.txt","w",stdout);
    int weights[] = {10, 7, 5, 18, 12, 20, 15};
    int size = 7;
    findSubset(weights, size, 35);
}