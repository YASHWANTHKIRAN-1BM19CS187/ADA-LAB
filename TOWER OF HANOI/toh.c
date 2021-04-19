#include <stdio.h>
void towerfun(int, char, char, char);
int main()
{
    int n;// defined to store the number disc
    printf("Enter the number of disks : ");
    scanf("%d", &n);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towerfun(n, 'A', 'C', 'B'); // A, B, C are tower
    return 0;
}
 
void towerfun(int n, char fr, char tr, char ar)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", fr, tr);
        return;
    }
    towerfun(n - 1, fr, ar, tr);
    printf("\n Move disk %d from rod %c to rod %c", n, fr, tr);
    towerfun(n - 1, ar, tr, fr);
}