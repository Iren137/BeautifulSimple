#include "pretty_number.h"

#include <iostream>

bool IsSimple(int64_t number) {
  for (int i = 2; i <= number / i; ++i) {
    if (number % i == 0) {
      // std::cout << "\t\t\tMistake: " << number << " / " << i << "\n";
      return false;
    }
  }
  return true;
}

bool IsPretty(PrettyNumber number) {
  std::string permutation = number.ToString();
  do {
    if (!IsSimple(std::stoll(permutation))) {
      return false;
    }
  } while (std::next_permutation(permutation.begin(),
                                 permutation.end()));
  return true;
}

std::vector<PrettyNumber> GetAllPrettyNumbersWithFixedSize(int64_t size) {
  std::vector<PrettyNumber> results;
  for (int64_t ones_count = 0; ones_count <= size; ++ones_count) {
    int64_t size_379 = size - ones_count;
    for (int64_t threes_count = 0; threes_count <= size_379; ++threes_count) {
      int64_t size_79 = size_379 - threes_count;
      for (int64_t sevens_count = 0; sevens_count <= size_79; ++sevens_count) {
        PrettyNumber new_number(ones_count,
                                threes_count,
                                sevens_count,
                                size_79 - sevens_count);
        if (!new_number.IsSimplyPretty()) continue;
        if (IsPretty(new_number)) {
          results.push_back(new_number);
        }
      }
    }
  }
  return results;
}

int main() {
  int64_t max_size = 17;
  std::vector<PrettyNumber> pretty_numbers;
  for (int64_t size = 1; size <= max_size; ++size) {
    auto new_numbers = GetAllPrettyNumbersWithFixedSize(size);
    for (const auto& new_number : new_numbers) {
      pretty_numbers.push_back(new_number);
    }
  }

  for (const auto& number : pretty_numbers) {
    std::cout << number.ToString() << "\n";
  }
  return 0;
}
