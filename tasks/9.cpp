/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a2 + b2 = c2
For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.



 */

#include <iostream>
#include <ctime>
#include <math.h>

long run(int n)
{
    for (int a = 1; a < n; a++)
    {
        for (int b = 1; b < n; b++)
        {
            for (int c = 1; c < n; c++)
            {
                if (a < b && b < c && a + b + c == n && pow(a, 2) + pow(b, 2) == pow(c, 2))
                {
                    std::cout << a << ":" << b << ":" << c << std::endl;
                    return a * b * c;
                }
            }
        }
    }
    return -1;
}

int main()
{
    std::clock_t begin = std::clock();
    int result = run(1000);
    std::cout << "Result: " << result << std::endl;
    std::clock_t end = std::clock();
    std::cout << "Time taken: " << (end - begin) / CLOCKS_PER_SEC << std::endl;
    return 0;
}