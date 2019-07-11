/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.



 */

#include <iostream>
#include <ctime>
#include <string.h>

long run(int n)
{
    int primes[n];
    memset(primes, 1, sizeof(primes));
    for (int i = 2; i <= n; i++)
    {
        if (primes[i])
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                primes[j] = 0;
            }
        }
    }
    long sum = 0;
    for (int i = 2; i <= n; i++)
    {
        if (primes[i])
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    std::clock_t begin = std::clock();
    long result = run(2000000);
    std::cout << "Result: " << result << std::endl;
    std::clock_t end = std::clock();
    std::cout << "Time taken: " << (end - begin) / CLOCKS_PER_SEC << std::endl;
    return 0;
}