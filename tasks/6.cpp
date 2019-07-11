/*
The sum of the squares of the first ten natural numbers is,

12 + 22 + ... + 102 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

 */


#include <iostream>
#include <ctime>
#include <math.h>



int run(int upToNum)
{
    int sumSquares, squareSum;
    squareSum = pow((1+upToNum) * upToNum / 2, 2);
    for(int i = 1; i <= upToNum; i++){
        sumSquares += pow(i, 2);
    }
    return squareSum - sumSquares;
}

int main()
{
    std::clock_t begin = std::clock();
    int result = run(100);
    std::cout << "Result: " << result << std::endl;
    std::clock_t end = std::clock();
    std::cout << "Time taken: " << (end - begin) / CLOCKS_PER_SEC << std::endl;
    return 0;
}