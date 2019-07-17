/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.


 */

#include <iostream>
#include <ctime>
#include <unordered_map>
#include <string.h>
#include <math.h>

int getLetterCount(int n)
{
    std::unordered_map<int, int> umap({
        {1, strlen("one")},
        {2, strlen("two")},
        {3, strlen("three")},
        {4, strlen("four")},
        {5, strlen("five")},
        {6, strlen("six")},
        {7, strlen("seven")},
        {8, strlen("eight")},
        {9, strlen("nine")},
        {10, strlen("ten")},
        {11, strlen("eleven")},
        {12, strlen("twelve")},
        {13, strlen("thirteen")},
        {14, strlen("fourteen")},
        {15, strlen("fifteen")},
        {16, strlen("sixteen")},
        {17, strlen("seventeen")},
        {18, strlen("eighteen")},
        {19, strlen("nineteen")},
        {20, strlen("twenty")},
        {30, strlen("thirty")},
        {40, strlen("forty")},
        {50, strlen("fifty")},
        {60, strlen("sixty")},
        {70, strlen("seventy")},
        {80, strlen("eighty")},
        {90, strlen("ninety")},
        {100, strlen("hundred")},
        {1000, strlen("thousand")},
    });
    if (umap[n])
    {
        if (n == 100 || n == 1000)
        {
            return umap[n] + 3;
        }
        return umap[n];
    }
    int count = 0;
    int power = 0;
    int prev;
    while (n > 0)
    {
        int order = pow(10, power);
        int num = (n % 10) * order;
        int len = umap[num];
        if (power == 1)
        {
            if (umap[prev + num])
            {
                len = umap[prev + num] - count;
            }
        }
        prev = num;
        if (power == 2)
        {
            if (num > 0)
            {
                len = umap[num / order] + umap[order];
            }
            if (count > 0)
            {
                len += 3;
            }
        }
        count += len;
        n /= 10;
        power++;
    }
    return count;
}

int run(int size)
{
    int letters = 0;
    for (int i = 1; i <= size; i++)
    {
        letters += getLetterCount(i);
    }
    return letters;
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