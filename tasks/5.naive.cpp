/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?


Brute force solution, just check that number is divisible to all numbers

 */

#include <iostream>
#include <ctime>

bool IsDivisibleUpTo(int num, int upToNum)
{
    for (int i = upToNum; i > 1; i--)
    {
        if (num % i != 0)
        {
            return false;
        }
    }
    return true;
}

int run(int upToNum)
{
    int num = upToNum;
    while (true)
    {
        if (IsDivisibleUpTo(num, upToNum))
        {
            return num;
        }
        num++;
    }
}

int main()
{
    std::clock_t begin = std::clock();
    int result = run(20);
    std::cout << "Result: " << result << std::endl;
    std::clock_t end = std::clock();
    std::cout << "Time taken: " << (end - begin) / CLOCKS_PER_SEC << std::endl;
    return 0;
}