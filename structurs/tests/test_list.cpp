#include <gtest/gtest.h>
#include "list.hpp"

TEST(List, PushFront) {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);
    EXPECT_EQ(list.front(), 2);
}
