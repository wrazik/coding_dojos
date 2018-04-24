#include <gtest/gtest.h>
#include "../src/Solver.h"

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

TEST(SolverTests, FindPeeks) {
	Solver solver({1, 0, 3, 5, 4, 0, 1, 2, 1, 3, 0, 1, 2, 0, 1});
	EXPECT_EQ(std::vector<int>({0,3,7,9,12,14}), solver.FindPeaks());
}

TEST(SolverTests, FindPeeksBeforeMountain) {
	Solver solver({1, 0, 3, 5, 4, 0, 2, 2, 2, 3, 0, 1, 2, 0, 1});
	EXPECT_EQ(std::vector<int>({0,3,9,12,14}), solver.FindPeaks());
}

TEST(SolverTests, FindPeeksAfterMountain) {
	Solver solver({1, 0, 3, 5, 4, 0, 3, 2, 2, 2, 0, 1, 2, 0, 1});
	EXPECT_EQ(std::vector<int>({0,3,6,12,14}), solver.FindPeaks());
}

TEST(SolverTests, FindPeeksHighFlat) {
	Solver solver({1, 0, 3, 5, 4, 1, 2, 2, 2, 2, 0, 1, 2, 0, 1});
	EXPECT_EQ(std::vector<int>({0,3,6,12,14}), solver.FindPeaks());
}

TEST(SolverTests, FindPeeksFlatBegin) {
	Solver solver({2, 2, 2, 0, 5});
	EXPECT_EQ(std::vector<int>({0,4}), solver.FindPeaks());
}

TEST(SolverTests, FindPeeksFlatBeginAsceend) {
	Solver solver({2, 2, 2, 4, 5});
	EXPECT_EQ(std::vector<int>({4}), solver.FindPeaks());
}

TEST(SolverTests, FindPeeksHighLandAtTheEnd) {
	Solver solver({2,0, 5, 5});
	EXPECT_EQ(std::vector<int>({0,2}), solver.FindPeaks());
}

TEST(SolverTests, FindPeeksLonelyMountain) {
	Solver solver({2,6,5,5});
	EXPECT_EQ(std::vector<int>({1}), solver.FindPeaks());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
