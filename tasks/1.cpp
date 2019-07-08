/**

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

 */

 #include <iostream>
 #include <ctime>

 int run(int max, int* arr, int len){
     int sum = 0;
     for(int i = 0; i < max; i++){
         for(int j = 0; j < len; j++){
             if(i%arr[j]==0){
                sum += i;
                break;
             }
         }
     }
     return sum;
 }

 int main(){
     std::clock_t begin = std::clock();
     int len = 2;
     int dividers[len] = {3, 5};
     int max = 1000;
     int result = run(max, dividers, len);
     std::cout << "Result: " << result <<  std::endl;
     std::clock_t end = std::clock();
     std::cout << "Time taken: " << (end - begin) / CLOCKS_PER_SEC <<  std::endl;
     return 0;
 }