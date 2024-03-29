#include <stdio.h>

// A function to calculate factorial of a given number
int factorial(int n)
{
    int f = 1;
    for (int i = 1; i <= n; i++)
        f = f * i;
    return f;
}

// A function to calculate binomial coefficient C(k,n) using the formula
int binomial(int k, int n)
{
    int num = factorial(n); // numerator
    int den = factorial(n-k) * factorial(k); // denominator
    int res = num / den; // result
    return res;
}

int main()
{
    int k, n;
    scanf("%d %d", &k, &n);
    printf("%d\n", k, n, binomial(k,n));
    return 0;
}