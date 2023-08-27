#include "pch.h"
#include "../i22-2462_LAB-1/hospital.h"
#include "../i22-2462_LAB-1/patient.h"
TEST(TestCaseName, TestName)
{
	Hospital h1;
  EXPECT_EQ(100, h1.Total(10,10));
  EXPECT_TRUE(true);
}
TEST(TestCase2, TestName2)
{
	Hospital h1;
	Patient p1;
	EXPECT_EQ(0, h1.Total(p1, 10,5,0));
	EXPECT_TRUE(true);
}