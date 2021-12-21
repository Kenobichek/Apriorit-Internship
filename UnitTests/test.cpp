#include "pch.h"
#include "../main/funk.h"

TEST(GetProductsAmount, Standart) {
	std::vector<int> prices = { 12, 7, 66, 69 };
	int count = GetProductsAmount(prices, 10);
	EXPECT_EQ(count, 1);
}

TEST(GetProductsAmount, SumLessAmount) {
	std::vector<int> prices = { 12, 7, 66, 69 };
	int count = GetProductsAmount(prices, 100000);
	EXPECT_EQ(count, prices.size());
}

TEST(GetProductsAmount, SortTest) {
	std::vector<int> prices = { 404, 403, 401, 34, 999 };
	int count = GetProductsAmount(prices, 35);
	EXPECT_EQ(count, 1);
}

TEST(GetProductsAmount, SortEdgeCase) {
	std::vector<int> prices = { 404, 403, 401, 34, 999 };
	int count = GetProductsAmount(prices, 34);
	EXPECT_EQ(count, 1);
}

TEST(GetProductsAmount, NotEnoughMoney) {
	std::vector<int> prices = { 404, 403, 401, 34, 999 };
	int count = GetProductsAmount(prices, 20);
	EXPECT_EQ(count, 0);
}

TEST(GetProductsAmount, EnoughMoneyVectorEmpty) {
	std::vector<int> prices = {};
	int count = GetProductsAmount(prices, 50000);
	EXPECT_EQ(count, 0);
}

TEST(IsLeapYear, NegativeYear) {
	EXPECT_FALSE(IsLeapYear(-2282));
	EXPECT_FALSE(IsLeapYear(0));
	EXPECT_FALSE(IsLeapYear(-1999));

}

TEST(IsLeapYear, YearsDivisibleBy4) {
	EXPECT_TRUE(IsLeapYear(2016));
	EXPECT_TRUE(IsLeapYear(2008));
}

TEST(IsLeapYear, YearsDivisibleBy400) {
	EXPECT_TRUE(IsLeapYear(2000));
	EXPECT_TRUE(IsLeapYear(4000));
}

TEST(IsLeapYear, YearsDivisibleBy100) {
	EXPECT_FALSE(IsLeapYear(1900));
	EXPECT_FALSE(IsLeapYear(500));
	EXPECT_FALSE(IsLeapYear(2100));
}

TEST(IsLeapYear, StandartYear) {
	EXPECT_FALSE(IsLeapYear(2021));
	EXPECT_FALSE(IsLeapYear(2003));
	EXPECT_FALSE(IsLeapYear(2005));
	EXPECT_FALSE(IsLeapYear(2002));
	EXPECT_FALSE(IsLeapYear(1999));
}
