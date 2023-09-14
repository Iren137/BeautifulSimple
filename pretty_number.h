#pragma  once
#include <string>
#include <vector>

class PrettyNumber {
 public:
  explicit PrettyNumber(int64_t ones_count,
                        int64_t threes_count,
                        int64_t sevens_count,
                        int64_t nines_count);

  [[nodiscard]] bool IsSimplyPretty() const;

  [[nodiscard]] std::string ToString() const;

 private:
  static std::vector<int64_t> simple_numbers;

  int64_t ones_count_, threes_count_, sevens_count_, nines_count_;
};
