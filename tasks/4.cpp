/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

 */


 #include <iostream>
 #include <ctime>
 #include <math.h>

 

int reverseNumber(int num){
    int rev = 0;
    while(num > 0){
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

bool isNumberPalindrome(int num){
    return num == reverseNumber(num);
}

 int run(int n){
     int start = pow(10, n-1) + 1;
     int end = pow(10, n) - 1;
     int max = 0;
     for(int i = start; i <= end; i++){
         for(int j = start; j <= end; j++){
             int res = i * j;
             if(isNumberPalindrome(res)){
                 if(max < res){
                     max = res;
                 }
             }
         }
     }
     return max;
}

 int main(){
     std::clock_t begin = std::clock();
     int result = run(3);
     std::cout << "Result: " << result <<  std::endl;
     std::clock_t end = std::clock();
     std::cout << "Time taken: " << (end - begin) / CLOCKS_PER_SEC <<  std::endl;
     return 0;
 }