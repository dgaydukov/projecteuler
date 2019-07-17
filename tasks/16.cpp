/*
215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 21000?


 */

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

std::vector<int> mul(std::vector<int> v, int n)
{
    std::vector<int> p;
    int left = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        int res = v[i] * n + left;
        p.push_back(res % 10);
        left = res / 10;
    };
    while (left > 0)
    {
        p.push_back(left % 10);
        left = left / 10;
    }
    std::reverse(p.begin(), p.end());
    return p;
}

int run(int a, int b)
{
    int sum = 0;
    std::vector<int> v;
    v.push_back(a);
    for (int i = 0; i < b - 1; i++)
    {
        v = mul(v, a);
    }
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    return sum;
}

int main()
{
    std::clock_t begin = std::clock();
    int result = run(2, 1000);
    std::cout << "Result: " << result << std::endl;
    std::clock_t end = std::clock();
    std::cout << "Time taken: " << (end - begin) / CLOCKS_PER_SEC << std::endl;
    return 0;
}