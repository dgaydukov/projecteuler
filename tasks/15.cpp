/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.


How many such routes are there through a 20×20 grid?

 */

#include <iostream>
#include <ctime>
#include <unordered_map>
#include <string.h>
#include <math.h>

int run(int size, int pos = 1)
{
    if (pos == size * size)
    {
        return 1;
    }
    int paths = 0;
    if ((pos + 1) % size != 1)
    {
        paths += run(size, pos + 1);
    }
    if (pos + size <= size * size)
    {
        paths += run(size, pos + size);
    }
    return paths;
}

int main()
{
    std::clock_t begin = std::clock();
    int result = run(3);
    std::cout << "Result: " << result << std::endl;
    std::clock_t end = std::clock();
    std::cout << "Time taken: " << (end - begin) / CLOCKS_PER_SEC << std::endl;
    return 0;
}