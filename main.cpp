#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

std::vector<unsigned long long> WringNumber(unsigned long long num) {
  std::vector<int> numbers;
  std::vector<unsigned long long> returning;
  while (num != 0) {
    numbers.push_back(num % 10);
    num /= 10;
  }
  std::sort(numbers.begin(), numbers.end());
  do {
    unsigned long long number = 0;
    for (int i = 0; i < numbers.size() - 1; i++) {
      number += numbers[i];
      number*=10;
    }
    number += numbers[numbers.size() - 1];
    returning.push_back(number);
  } while (std::next_permutation(numbers.begin(), numbers.end()));
  return returning;
}

bool IsPrime(unsigned long long num) {
  for (unsigned long long i = 2; i < (unsigned long long) (std::sqrt(num) + 1);
       i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

bool AllIsPrime(unsigned long long num) {
  std::vector<unsigned long long> nums = WringNumber(num);
  for (int i = 0; i < nums.size(); i++) {
    if (!IsPrime(nums[i])) {
      return false;
    }
  }
  return true;
}

int main() {
  std::vector<unsigned long long> beautiful_prime;
//  for (unsigned long long i = 2; i < ULONG_LONG_MAX; i++) {
  for (unsigned long long i = 2; i < UINT16_MAX; i++) {
    if (AllIsPrime(i)) {
      beautiful_prime.push_back(i);
    }
  }
  while (!beautiful_prime.empty()) {
    std::vector<unsigned long long> nums = WringNumber(beautiful_prime[0]);
    for (int i = 0; i < nums.size(); i++) {
      auto it = std::find(beautiful_prime.begin(),
                          beautiful_prime.end(),
                          nums[i]);
      if (it != beautiful_prime.end()) {
        std::cout << *it << " ";
        beautiful_prime.erase(it);
      }
    }
    std::cout << "\n";
  }
  return 0;
}
