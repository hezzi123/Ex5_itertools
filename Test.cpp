#include "range.hpp"
#include "doctest.h"
TEST_CASE("range check")
{
    for (int j=0;j<101;j++)
    {
        for (int i: itertools::range(2,3))
        {
            CHECK(i==2);
        }
    }
}