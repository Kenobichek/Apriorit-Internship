#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

int GetProductsAmount(std::vector<int> prices, int amountOfMoney)
{
    std::sort(prices.begin(), prices.end());
    int sum = 0;
    for (int i = 0; i < prices.size(); ++i)
    {
        sum += prices[i];
        if (sum > amountOfMoney)
        {
            return i;
        }
    }

    return prices.size();
}

bool IsLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
        else return true;
    }
    else return false;
}