#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

template<typename T>
bool IsPrime(T num) {
  for (T i = 2; i < static_cast<T>(std::sqrt(num) + 1); i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

template<typename T>
std::pair<bool, std::vector<int>> GetNumbers(T num) {
  bool out = true;
  std::vector<int> numbers;
  while (num != 0) {
    int t = num % 10;
    if (t == 5 || t % 2 == 0) {
      out = false;
      break;
    }
    numbers.push_back(t);
    num /= 10;
  }
  int sum = 0;
  for (int number: numbers) {
    sum += number;
  }
  if (sum % 3 == 0) {
    out = false;
  }
  return std::make_pair(out, numbers);
}

template<typename T>
std::pair<bool, std::vector<T>> WringNumber(std::vector<int> numbers) {
  bool out = true;
  std::vector<T> returning;
  std::sort(numbers.begin(), numbers.end());
  do {
    T number = 0;
    for (int i = 0; i < numbers.size() - 1; i++) {
      number += numbers[i];
      number *= 10;
    }
    number += numbers.back();
    if (!IsPrime(number)) {
      out = false;
      break;
    }
    returning.push_back(number);
  } while (std::next_permutation(numbers.begin(), numbers.end())); // смущает
  // эта функция (мб надо не ее)
  return std::make_pair(out, returning);
}

int main() {

  std::vector<int> beautiful_primes; // в перспективе - сделать еще для
  // unsigne int, ..., unsigned long long. Для этого в функциях стоят template-ы
  for (int i = 0; i < 10'000'000; i++) {
    if (IsPrime(i)) {
      std::pair<bool, std::vector<int>> pair = GetNumbers(i);
      if (pair.first) {
        std::pair<bool, std::vector<int>> pair2 = WringNumber<int>(pair.second);
        if (pair2.first) {
          beautiful_primes.push_back(i);
        }
      }
    }
  }

  while (!beautiful_primes.empty()) {
    std::vector<int>
        nums = WringNumber<int>(GetNumbers(beautiful_primes[0]).second).second;
    for (int& num: nums) {
      auto it = std::find(beautiful_primes.begin(),
                          beautiful_primes.end(),
                          num);
      if (it != beautiful_primes.end()) {
        std::cout << *it << " ";
        beautiful_primes.erase(it);
      }
    }
    std::cout << "\n";
  }
  return 0;
}
