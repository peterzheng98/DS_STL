//
// Created by Alex Chi on 2019-07-22.
//

#include <gtest/gtest.h>

#include <deque>

#include "deque.hpp"
#include "mocks/Bint.h"
#include "mocks/Integer.h"
#include "mocks/Matrix.hpp"
#include "utility.hpp"
#include "exceptions.hpp"

namespace {
    long long randNum(long long x, long long maxNum) {
        x = (x * 10007) % maxNum;
        return x + 1;
    }

    const size_t N = 10005LL;

    TEST(Basic, Integer) {
        sjtu::deque<Integer> dInt;
        std::vector<Integer> vInt;
        for (int i = 0; i < N; ++i) {
            vInt.push_back(Integer(randNum(i, N + 17)));
            dInt.push_back(vInt[i]);
        }
        for (int i = 0; i < N; ++i) {
            EXPECT_EQ(vInt[i], dInt[i]);
        }
    }

    TEST(Basic, Matrix) {
        sjtu::deque<Diamond::Matrix<double>> dM;
        std::vector<Diamond::Matrix<double>> vM;
        for (int i = 0; i < N; ++i) {
            vM.push_back(Diamond::Matrix<double>(randNum(i + 1, 10 + 7), randNum(i + 2, 10 + 7),
                                                 randNum(i + 3, (100 + 17)) * 1.0 / randNum(i, 17)));
            dM.push_back(vM[i]);
        }
        for (int i = 0; i < N; ++i) {
            EXPECT_EQ(vM[i], dM[i]);
        }
    }

    TEST(Basic, Bint) {
        sjtu::deque<Util::Bint> dBint;
        std::vector<Util::Bint> vBint;
        for (long long i = 1LL << 50; i < (1LL << 50) + N; ++i) {
            vBint.push_back(Util::Bint(i) * randNum(i, (1 << 25)));
            dBint.push_back(vBint.back());
        }

        for (int i = 0; i < N; ++i) {
            EXPECT_EQ(vBint[i], dBint[i]);
        }
    }

    TEST(Basic, ConstructorAndOperatorEq) {
        sjtu::deque<long long> *pInt;
        pInt = new sjtu::deque<long long>;
        for (long long i = 0; i < N; ++i) {
            pInt->push_back(i);
        }
        sjtu::deque<long long> &dInt = *pInt;
        sjtu::deque<long long> dualInt(dInt);
        sjtu::deque<long long> dualInt_oper;
        dualInt_oper = dInt;
        for (long long i = 0; i < N; ++i) {
            EXPECT_EQ(dualInt_oper[i], dInt[i]);
            EXPECT_EQ(dualInt[i], dInt[i]);
        }
        dualInt_oper = dualInt_oper;
        delete pInt;
        for (long long i = 0; i < N; ++i) {
            EXPECT_EQ(dualInt_oper[i], dualInt[i]);
        }
    }

    TEST(Basic, IteratorSequenceAccess) {
        sjtu::deque<long long> dInt;
        for (long long i = 0; i < N; ++i) {
            dInt.push_back(i);
        }
        sjtu::deque<long long>::iterator it;
        it = dInt.begin();
        for (long long i = 0; i < N; ++i) {
            EXPECT_EQ(*it, dInt[i]);
            ++it;
        }
        EXPECT_EQ(it, dInt.end());
    }

    TEST(Basic, TestIteratorRandomAccess) {
        sjtu::deque<long long> dInt;
        std::vector<long long> vInt;
        for (long long i = 0; i < N; ++i) {
            dInt.push_back(i);
            vInt.push_back(i);
        }
        for (long long i = 0; i < N; ++i) {
            EXPECT_EQ(*(dInt.begin() + i), vInt[i]);
        }
    }

    TEST(Basic, InsertAndErase) {
        sjtu::deque<long long> dInt;
        std::vector<long long> vInt;
        for (long long i = 0; i < N; ++i) {
            dInt.push_back(i);
            vInt.push_back(i);
        }
        vInt.insert(vInt.begin() + 2, 2);
        dInt.insert(dInt.begin() + 2, 2);
        vInt.insert(vInt.begin() + 23, 23);
        dInt.insert(dInt.begin() + 23, 23);
        vInt.insert(vInt.begin() + 233, 233);
        dInt.insert(dInt.begin() + 233, 233);
        vInt.erase(vInt.begin() + 2333);
        dInt.erase(dInt.begin() + 2333);
        for (long long i = 0; i < N; ++i) {
            EXPECT_EQ(*(dInt.begin() + i), vInt[i]);
        }
    }

    TEST(Basic, PopAndPush) {
        sjtu::deque<long long> dInt, drInt;
        std::vector<long long> vInt;
        std::vector<long long> rInt;
        for (size_t i = 0; i < 1114LL; ++i) {
            dInt.push_back(i);
            vInt.push_back(i);
        }
        for (size_t i = 0; i < 107LL; ++i) {
            dInt.pop_back();
            vInt.pop_back();
        }
        for (size_t i = 0; i < 1114LL; ++i) {
            drInt.push_front(i);
            rInt.push_back(i);
        }
        for (size_t i = 0; i < 107LL; ++i) {
            drInt.pop_front();
            rInt.pop_back();
        }
        for (size_t i = 0; i < 1007LL; ++i) {
            EXPECT_EQ(dInt[i], vInt[i]);
            EXPECT_EQ(drInt[1006LL - i], rInt[i]);
        }
    }
}
