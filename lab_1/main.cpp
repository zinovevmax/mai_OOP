#include <iostream>
#include "include/isPerfectSquare.h"

int main()
{
  long long int number;
  std::cout << "What is your number\n";
  std::cin  >> number;

  std::cout << "result: " << isPerfectSquare(number) << std::endl;

  return 0;
}