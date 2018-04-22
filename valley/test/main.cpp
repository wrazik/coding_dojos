#include <gtest/gtest.h> 

TEST(ExampleTestSuite, ExampleTest)
{   
	ASSERT_EQ (0==0, true);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
