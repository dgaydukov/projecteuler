/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

 */

/**
 * Solution algorithm
 * You can use brute force, just take every number, and check if it can be divided by 1..10 and increment one by one 
 * until you get your desired number
 * But there is a better way to do this
 * 
 * 1. Remove all numbers that are divisors inside sequence (we have 1,2,3,4,5,6,7,8,9,10), 
 * we can easily remove 2 cause it divisors of 4, 
 * 3 cause it divisor of 9, 
 * 4 cause it divisor of 8 and so on. After we got number 6,7,8,9,10
 * 2. Multiply all primes and remove them from vector (cause they have no divisors except themselves)
 * 3. Find LCM (least common multiple) of remaining number
 * 4. Multiple LCM from step 3 and primes from step 2
 */

#include <iostream>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <string.h>

std::vector<int> getBaseNumbers(int upToNum)
{
    std::vector<int> v;
    for (int i = 2; i <= upToNum; i++)
    {
        bool noHigherDivider = true;
        for (int j = 2; j <= upToNum; j++)
        {
            if (i != j && j % i == 0)
            {
                noHigherDivider = false;
                break;
            }
        }
        if (noHigherDivider)
        {
            v.push_back(i);
        }
    }
    return v;
}

std::vector<int> getPrimes(int upToNum)
{
    std::vector<int> primes;
    int arr[upToNum];
    memset(arr, 1, sizeof(arr));
    for (int i = 2; i <= upToNum; i++)
    {
        if (arr[i])
        {
            for (int j = 2 * i; j <= upToNum; j = j + i)
            {
                arr[j] = 0;
            }
        }
    }
    for (int i = 2; i <= upToNum; i++)
    {
        if (arr[i])
        {
            primes.push_back(i);
        }
    }
    return primes;
}

int getGCD(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    return getGCD(b, a % b);
}

int getLCM(int a, int b)
{
    return a * b / getGCD(a, b);
}

int getVectorLCM(std::vector<int> v)
{
    int lcm = getLCM(v[0], v[1]);
    int len = v.size();
    for (int i = 2; i < len; i++)
    {
        lcm = getLCM(lcm, v[i]);
    }
    return lcm;
}

int run(int upToNum)
{
    std::vector<int> nums = getBaseNumbers(upToNum);
    std::vector<int> primes = getPrimes(upToNum);
    std::unordered_map<int, bool> umap;
    for (auto x : primes)
    {
        umap[x] = true;
    }
    int product = 1;
    int len = nums.size();
    for (int i = 0; i < len; i++)
    {
        if (umap[nums[i]])
        {
            product *= nums[i];
            nums.erase(nums.begin() + i);
        }
    }
    product *= getVectorLCM(nums);

    return product;
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