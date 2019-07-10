/*
Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.


 */

#include <iostream>
#include <ctime>

int run(int limit)
{
    int v1 = 1;
    int v2 = 1;
    int n = v1 + v2;
    int sum = 0;
    while (n < limit)
    {
        std::cout << n << std::endl;
        if (n % 2 == 0)
        {
            sum += n;
        }
        v1 = v2;
        v2 = n;
        n = v1 + v2;
    }
    return sum;
}

int main()
{
    std::clock_t begin = std::clock();
    int result = run(4000000);
    std::cout << "Result: " << result << std::endl;
    std::clock_t end = std::clock();
    std::cout << "Time taken: " << (end - begin) / CLOCKS_PER_SEC << std::endl;
    return 0;
}