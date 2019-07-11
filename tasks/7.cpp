/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

 */

#include <iostream>
#include <ctime>
#include <math.h>

bool isPrime(int n)
{
    int max = sqrt(n) + 1;
    for (int i = 3; i < max; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int run(int upToNum)
{
    int counter = 1;
    int num = 3;
    while (true)
    {
        if (isPrime(num))
        {
            counter++;
            if (counter == upToNum)
            {
                return num;
            }
        }
        num += 2;
    }
}

int main()
{
    std::clock_t begin = std::clock();
    int result = run(10001);
    std::cout << "Result: " << result << std::endl;
    std::clock_t end = std::clock();
    std::cout << "Time taken: " << (end - begin) / CLOCKS_PER_SEC << std::endl;
    return 0;
}