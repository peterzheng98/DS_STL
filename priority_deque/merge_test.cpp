//
// Created by Alex Chi on 2019-07-23.
//

#include <gtest/gtest.h>

#include "priority_queue.hpp"


namespace {
    /**
     * These tests are originally test data five
    */
    TEST(Merge, Merge) {
        sjtu::priority_queue<int> pq1, pq2;
        static int buffer[900000];
        int pointer = 0;
        const int MAXA = 400000;
        const int MAXB = 400000;
        for (int i = 1; i <= MAXA; i++) {
            pq1.push(buffer[++pointer] = rand());
        }
        for (int i = 1; i <= MAXB; i++) {
            pq2.push(buffer[++pointer] = rand());
        }
        pq1.merge(pq2);
        ASSERT_TRUE(pq2.empty());
        std::sort(buffer + 1, buffer + pointer + 1);
        while (pointer > 0) {
            EXPECT_EQ(pq1.top(), buffer[pointer]);
            pq1.pop();
            pointer--;
        }
    }
}
