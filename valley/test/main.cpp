#include <gtest/gtest.h>
#include "../src/Solver.h"
#include <iostream>

/*TEST(SolverTests, DISABLED_EmptyValley)
{

	EXPECT_EQ(Solver::Solve({0, 1, 2, 3, 4, 6}), 0);
	EXPECT_EQ(Solver::Solve({0, 1, 3, 3, 4, 6, 6}), 0);
	EXPECT_EQ(Solver::Solve({0, 1, 3, 3, 4, 6, 6, 7, 5, 3, 3, 2, 1}), 0);
}

TEST(SolverTests, DISABLED_NotEmptyValley)
{
	EXPECT_EQ(Solver::Solve({1, 0, 3, 5, 4, 0, 1, 2, 1, 3, 0, 1, 2, 0, 1}), 8);
	EXPECT_EQ(Solver::Solve({6, 6, 0, 6, 4, 3, 4}), 6);
	EXPECT_EQ(Solver::Solve({6, 6, 0, 6, 4, 3, 4}), 6);
	EXPECT_EQ(Solver::Solve({6, 6, 0, 5, 0, 0, 6}), 19);
	EXPECT_EQ(Solver::Solve({6, 6, 0, 5, 0, 0, 5}), 10);
}*/


using TestData = std::vector<std::string>;

auto parse_test_data(const TestData &data) {
  TestData mountain(data.begin(), std::prev(data.end()));
  std::vector<int> input(data[0].size(), 0);
  std::vector<int> expected;

  for (const auto &row : mountain) {
    for (auto i = 0u; i < input.size(); ++i) {
      if ('#' == row[i]) {
        input[i]++;
      }
    }
  }

  for (auto i = 0u; i < input.size(); ++i) {
    if ('P' == (*data.rbegin())[i]) {
      expected.push_back(i);
    }
  }

  return std::make_tuple(input, expected);
}

struct PictureTests : public testing::TestWithParam<TestData> {};

TEST_P(PictureTests, test) {
  auto [input, expected] = parse_test_data(GetParam());
  EXPECT_EQ(expected, Solver(std::move(input)).FindPeaks());
}

// clang-format off
INSTANTIATE_TEST_CASE_P(Mountains, PictureTests, testing::Values(
  TestData{
	  "   #           ",
	  "   ##          ",
	  "  ###~~~~#     ",
	  "  ###~~#~#~~#  ",
	  "#~###~####~##~#",
	  "P  P   P P  P P"},
  TestData{
		"   #           ",
		"   ##          ",
		"  ###~~~~#     ",
		"  ###~####~~#  ",
		"#~###~####~##~#",
		"P  P     P  P P"}
));
// clang-format on

TEST(SolverTests, FindPeeksAfterMountain) {
  Solver solver({1, 0, 3, 5, 4, 0, 3, 2, 2, 2, 0, 1, 2, 0, 1});
  EXPECT_EQ(std::vector<int>({0, 3, 6, 12, 14}), solver.FindPeaks());
}

TEST(SolverTests, FindPeeksHighFlat) {
  Solver solver({1, 0, 3, 5, 4, 1, 2, 2, 2, 2, 0, 1, 2, 0, 1});
  EXPECT_EQ(std::vector<int>({0, 3, 6, 12, 14}), solver.FindPeaks());
}

TEST(SolverTests, FindPeeksFlatBegin) {
  Solver solver({2, 2, 2, 0, 5});
  EXPECT_EQ(std::vector<int>({0, 4}), solver.FindPeaks());
}

TEST(SolverTests, FindPeeksFlatBeginAsceend) {
  Solver solver({2, 2, 2, 4, 5});
  EXPECT_EQ(std::vector<int>({4}), solver.FindPeaks());
}

TEST(SolverTests, FindPeeksHighLandAtTheEnd) {
  Solver solver({2, 0, 5, 5});
  EXPECT_EQ(std::vector<int>({0, 2}), solver.FindPeaks());
}

TEST(SolverTests, FindPeeksLonelyMountain) {
  Solver solver({2, 6, 5, 5});
  EXPECT_EQ(std::vector<int>({1}), solver.FindPeaks());
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
