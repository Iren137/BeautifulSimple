#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>

bool IsPrime(uint64_t num) {
  for (uint64_t i = 2; i < (std::sqrt(num) + 1); i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

std::pair<bool, std::vector<int8_t>> GetNumbers(uint64_t num) {
  bool out = true;
  std::vector<int8_t> numbers;
  while (num != 0) {
    int t = num % 10;
    if (t == 5 || t % 2 == 0) {
      out = false;
      break;
    }
    numbers.push_back(t);
    num /= 10;
  }
  return std::make_pair(out, numbers);
}

bool BinFind(const std::vector<uint64_t>& numbers, uint64_t value) {
  int midd = 0;
  int left = 0;
  int right = numbers.size();
  while (left <= right) {
    midd = (left + right) / 2;

    if (value < numbers[midd])
      right = midd - 1;
    else if (value > numbers[midd])
      left = midd + 1;
    else
      return true;
  }
  return false;
}

void WringNumber(const std::vector<uint64_t>& numbers) {
  for (auto number: numbers) {
    if (!GetNumbers(number).first) break;

    bool is_beautiful = true;
    std::string s{std::to_string(number)};
    std::sort(s.begin(), s.end());
    do {
      unsigned long value{std::stoul(s)};
      if (!BinFind(numbers, value)) {
        is_beautiful = false;
        break;
      }
    } while (std::next_permutation(s.begin(), s.end()));
    if (is_beautiful) {
      std::cout << number << '\n';
    }
  }
}

int main() {
  // todo

  std::vector<uint64_t> primes;
  std::fstream fin;
  uint64_t prime;
  while (!fin.eof()) {
    std::cin >> prime;
    primes.emplace_back(prime);
  }
  WringNumber(primes);
  return 0;
}
