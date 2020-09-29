#include <stdio.h>

int sum_three_five(int n) //Calculate sum of all multiples of 3 or 5 that are less than n
{
    int sum = 0;
    int x = 3;
    while (x < n)
    {
        sum += x;
        x += 3;
    }
    x = 5;
    while (x < n)
    {
        sum += x;
        x += 5;
    }
    x = 15;
    while (x < n)
    {
        sum -= x;
        x += 15;
    }
    return sum;
}

long gcf(long a, long b) //The Euclidean Algorithm learned in APCSA, calculate the GCF
{
    if (a % b == 0)
        return b;
    else
        gcf(b, a%b);
}

long lcm_helper(long a, long b) //Calculate the LCM between 2 #s
{
    return a * b / gcf(a,b);
}

long lcm(long n) //Calculate the LCM between 1 to n
{
    long x = lcm_helper(n, n-1);
    n -= 2;
    while (n > 1)
    {
        x = lcm_helper(x, n);
        n -= 1;
    }
    return x;
}

int main()
{
    //#1 find the sum of all multiples of 3 or 5 below 1000
    printf("#1: The sum of all the multiples of 3 or 5 below 1000 is: %d\n", sum_three_five(1000));

    //#5 what is the smallest # that is evenly divisible by all #s from 1 to 20
    printf("#5: The smallest # that is evenly divisible by all #s from 1 to 20 is: %ld\n", lcm(20));

    return 0;
}