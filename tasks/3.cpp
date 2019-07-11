/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

 */

#include <iostream>
#include <ctime>
#include <string.h>
#include <math.h>

typedef unsigned long long int superlong;

int run(superlong max)
{
    int s = sqrt(max);
    int maxPrimeDivider = 1;
    int arr[s];
    memset(arr, 1, sizeof(arr));

    for (int i = 2; i < s; i++)
    {
        if (arr[i])
        {
            //std::cout << i << std::endl;
            if (max % i == 0)
            {
                maxPrimeDivider = i;
            }
            for (int j = 2 * i; j < s; j += i)
            {
                arr[j] = 0;
            }
        }
    }
    return maxPrimeDivider;
}

int main()
{
    std::clock_t begin = std::clock();
    int result = run(600851475143);
    std::cout << "Result: " << result << std::endl;
    std::clock_t end = std::clock();
    std::cout << "Time taken: " << (end - begin) / CLOCKS_PER_SEC << std::endl;
    return 0;
}