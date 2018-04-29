#pragma once
#include <vector>

class Solver {
 public:
  Solver(std::vector<int> &&vec);
  int Solve(const std::vector<int> &input);
  std::vector<int> FindPeaks();
  std::pair<int, bool> LoopOverPeaks(size_t start);

 private:
  std::vector<int> valley_;
};
