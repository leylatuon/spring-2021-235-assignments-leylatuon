#include <iostream>
/*
6! = 6*5!
  5! = 5*4!
  4! = 4*6
  3! = 3*2
  2! = 2*1
  1! = 1 *1
  0! = 1
  fact(n) = {  1 if n = 0
               n * (n-1)! otherwise
Things to look for in a recursive solution:
1. Base case <-- when you just know the answer without recurring
2. reduction <-- the recursive call that will eventually get to the base case
Things to consider
1. Try small examples by hand
2. look for self similarity - smaller simpler problems 
*/
int fact(int n){ //factorial example 
  if (n == 0){
    return 1;
  } else {
    return n * fact(n-1);
  }
}

/*
 *
 1 1 2 3 5 8 13 21 34
 the next fib number is the sum of the previous two fib numbers
*/

int fib(int n){ //fibonacci example w/recursion

  if (n <2){
    return 1;
  } else {
  return fib(n-1) + fib(n-2);
  }
}

int fib2(int n) //fibonacci without recursion
{
    int sum, num1=1, num2=1;
    if(n<2)
    {
        return 1;
    }
    for (int i=2; i<=n; i++)
    {
        sum = num1 + num2;
        num1 = num2;
        num2 = sum;
    }
        return sum;
}

int main()
{
    int i;
    for (i=0; i < 10 ; i++){
        std::cout << i << "! = " << fact(i) << "\n";
    }

    for (i=0; i < 10 ; i++){
        std::cout << fib(i) << ", ";
    }

    std::cout << "\n";
    for (i=0; i < 10; i++)
    {
        std::cout << fib2(i) << ", ";
    }
    std::cout << "\n";
  return 0;
}
