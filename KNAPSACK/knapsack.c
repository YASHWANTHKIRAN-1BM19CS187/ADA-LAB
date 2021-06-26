#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b)? a: b;
}

void knapSack(int W, int weight[], int val[], int n)
{
    int k[n+1][W+1];
    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= W; w++)
        {
            if(i == 0 || w == 0)
                k[i][w] = 0;
            else if(weight[i-1] <= w)
                k[i][w] = max(val[i-1] + k[i-1][w - weight[i-1]], k[i-1][w]);
            else
                k[i][w] = k[i-1][w];
        }
    }

    int res = k[n][W];
    printf("Total value: %d\n",res);
    printf("Weights: ");
    int w = W;
    for(int i = n; i > 0 && res > 0; i--)
    {
        if(res == k[i-1][w])
            continue;
        printf("%d ",weight[i-1]);
        res -= val[i-1];
        w -= weight[i-1];
    }
}

int main()
{
    int n, W;
    printf("Enter the number of items\n");
    scanf("%d",&n);
    int val[n], weight[n];

    printf("Enter the value and weight of each item\n");
    for(int i = 0; i < n; i++)
        scanf("%d %d", &val[i], &weight[i]);
    
    printf("Enter the maximum weight\n");
    scanf("%d",&W);
    
    knapSack(W, weight, val, n);
    return 0;
}