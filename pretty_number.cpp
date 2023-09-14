#include "pretty_number.h"

std::vector<int64_t>PrettyNumber::simple_numbers =
    {7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 151};

PrettyNumber::PrettyNumber(int64_t ones_count,
                           int64_t threes_count,
                           int64_t sevens_count,
                           int64_t nines_count) : ones_count_(ones_count),
                                                  threes_count_(threes_count),
                                                  sevens_count_(sevens_count),
                                                  nines_count_(nines_count) {}

bool PrettyNumber::IsSimplyPretty() const {
  if ((ones_count_ + threes_count_ * 3 + sevens_count_ * 7
      + nines_count_ * 9) % (int64_t) 3 == 0) {
    return false;
  }
  if (!(ones_count_ > 0
      && threes_count_ == 0 && sevens_count_ == 0 && nines_count_ == 0)
      && std::__gcd(std::__gcd(ones_count_, threes_count_),
                    std::__gcd(sevens_count_, nines_count_)) != 1) {
    return false;
  }

  std::string permutation = ToString();
  do {
    int64_t value = std::stoll(permutation);
    for (int64_t simple_number : simple_numbers) {
      if (simple_number > value / simple_number) break;
      if (value % simple_number == 0) return false;
    }
  } while (std::next_permutation(permutation.begin(),
                                 permutation.end()));
  return true;
}

std::string PrettyNumber::ToString() const {
  return std::string(ones_count_, '1')
      + std::string(threes_count_, '3')
      + std::string(sevens_count_, '7')
      + std::string(nines_count_, '9');
}
