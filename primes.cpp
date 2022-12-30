#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

// uint64_t NumberOfLastPrimeToCheck(
//     uint64_t number, const std::vector<uint64_t>& less_primes) {
//   auto high_border = static_cast<uint64_t>(std::sqrt(number));
//   uint64_t middle;
//   uint64_t left = 0;
//   uint64_t right = less_primes.size();
//
//   while (left < right) {
//     middle = (left + right) / 2;
//
//     if (high_border < less_primes[middle]) {
//       right = middle;
//     }
//     else if (high_border > less_primes[middle]) {
//       left = middle + 1;
//     }
//     else {
//       return middle;
//     }
//   }
//   return right;
// }
//
// bool IsPrime(uint64_t number, const std::vector<uint64_t>& less_primes) {
//   for (int64_t i = 0; i <= NumberOfLastPrimeToCheck(number, less_primes); ++i) {
//     if (number % less_primes[i] == 0) {
//       return false;
//     }
//   }
//   return true;
// }

bool IsPrime(uint64_t number, const std::vector<uint64_t>& less_primes) {
  auto high_border = static_cast<uint64_t>(std::sqrt(number));
  for (auto prime : less_primes) {
    if (prime > high_border) break;
    if (number % prime == 0) {
      return false;
    }
  }
  return true;
}

// bool IsPrime(uint64_t number) {
//   auto high_border = static_cast<uint64_t>(std::sqrt(number)) + 1;
//   for (uint64_t i = 3; i <= high_border; i += 2) {
//     if (number % i == 0) {
//       return false;
//     }
//   }
//   return true;
// }

int main() {
  std::ofstream write("primes.txt");
  std::vector<uint64_t> primes;
  primes.push_back(2);
  primes.reserve(40'000'000);

  auto start = std::chrono::high_resolution_clock::now();

  for (uint64_t number = 3; number <= UINT32_MAX; number += 2) {
    if (IsPrime(number, primes)) {
    // if (IsPrime(number)) {
      primes.push_back(number);
    }
  }

  auto finish = std::chrono::high_resolution_clock::now();
  auto work_time = std::chrono::duration<double>(finish - start).count() * 1000;
  std::cout << "work time is " << work_time << " milliseconds\n";

  write << primes.size() << "\n";
  for (uint64_t prime : primes) {
    write << prime << " ";
  }
  return 0;
}
