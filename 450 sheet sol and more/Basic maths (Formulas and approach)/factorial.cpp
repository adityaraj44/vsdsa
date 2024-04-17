#include <iostream>

int factorial(int n)
{

    // base case
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int power(int n, int m)
{
    if (m == 0) 
    {
        return 1;
    }

    return n * power(n, m - 1);
}

int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    // std::cout << factorial(25) << std::endl;
    // std::cout << power(25, 2);
    std::cout << fibonacci(2) << std::endl;
    // expected output is 1
    return 0;
}