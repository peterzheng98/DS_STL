//
// Created by Alex Chi on 2019-07-22.
//

#include <gtest/gtest.h>
#include <deque>
#include <ctime>
#include <vector>
#include <deque>
#include <random>
#include "deque.hpp"
#include "mocks/Bint.h"
#include "mocks/Integer.h"
#include "mocks/Matrix.hpp"
#include "mocks/DynamicType.h"
#include "mocks/Int.hpp"
#include "utility.hpp"
#include "exceptions.hpp"

namespace {
    static const int N = 10000;
    static const int N_SPEED = 33500;

    bool ExpectEqual(std::deque<Int> &a, sjtu::deque<Int> &b) {
        static std::vector<Int> resultA, resultB;
        resultA.clear();
        resultB.clear();
        for (auto x : a) resultA.push_back(x);
        for (auto x : b) resultB.push_back(x);
        EXPECT_EQ(resultA.size(), resultB.size());
        for (int i = 0; i < (int) resultA.size(); i++) { EXPECT_EQ(resultA[i], resultB[i]); }
        return true;
    }

    TEST(Series, PushBack) {
        std::deque<Int> a;
        sjtu::deque<Int> b;
        for (int i = 0; i < N; i++) {
            int tmp = rand();
            a.push_back(tmp);
            b.push_back(tmp);
        }
        ExpectEqual(a, b);
    }

    TEST(Series, PushFront) {
        std::deque<Int> a;
        sjtu::deque<Int> b;
        for (int i = 0; i < N; i++) {
            int tmp = rand();
            a.push_front(tmp);
            b.push_front(tmp);
        }
        ExpectEqual(a, b);
    }

    TEST(Series, Insert) {
        std::deque<Int> a;
        sjtu::deque<Int> b;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (a.size() + 1);
            int tmp = rand();
            a.push_back(tmp);
            b.push_back(tmp);
        }
        ExpectEqual(a, b);
    }

    TEST(Series, PopBack) {
        std::deque<Int> a;
        sjtu::deque<Int> b;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (a.size() + 1);
            int tmp = rand();
            a.push_back(tmp);
            b.push_back(tmp);
        }
        for (int i = 0; i < N; i++) {
            a.pop_back();
            b.pop_back();
        }
        ExpectEqual(a, b);
    }

    TEST(Series, PopFront) {
        std::deque<Int> a;
        sjtu::deque<Int> b;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (a.size() + 1);
            int tmp = rand();
            a.push_back(tmp);
            b.push_back(tmp);
        }
        for (int i = 0; i < N; i++) {
            a.pop_front();
            b.pop_front();
        }
        ExpectEqual(a, b);
    }

    TEST(Series, Erase) {
        std::deque<Int> a;
        sjtu::deque<Int> b;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (b.size() + 1);
            int tmp = rand();
            a.push_back(tmp);
            b.push_back(tmp);
        }
        for (int i = 0; i < N; i++) {
            int pos = rand() % b.size();
            a.erase(a.begin() + pos);
            b.erase(b.begin() + pos);
        }
        ExpectEqual(a, b);
    }

    TEST(Series, At) {
        std::deque<Int> a;
        sjtu::deque<Int> b;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (a.size() + 1);
            int tmp = rand();
            a.push_back(tmp);
            b.push_back(tmp);
        }
        for (int i = 0; i < N; i++) EXPECT_EQ(a.at(i), b.at(i));
    }

    TEST(Series, ConstAt) {
        std::deque<Int> basea;
        sjtu::deque<Int> baseb;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (basea.size() + 1);
            int tmp = rand();
            basea.push_back(tmp);
            baseb.push_back(tmp);
        }
        const std::deque<Int> a(basea);
        const sjtu::deque<Int> b(baseb);
        for (int i = 0; i < N; i++) EXPECT_EQ(a.at(i), b.at(i));
    }

    TEST(Series, Bracket) {
        std::deque<Int> a;
        sjtu::deque<Int> b;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (a.size() + 1);
            int tmp = rand();
            a.push_back(tmp);
            b.push_back(tmp);
        }
        for (int i = 0; i < N; i++) EXPECT_EQ(a[i], b[i]);
    }

    TEST(Series, ConstBracket) {
        std::deque<Int> basea;
        sjtu::deque<Int> baseb;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (basea.size() + 1);
            int tmp = rand();
            basea.push_back(tmp);
            baseb.push_back(tmp);
        }
        const std::deque<Int> a(basea);
        const sjtu::deque<Int> b(baseb);
        for (int i = 0; i < N; i++) EXPECT_EQ(a[i], b[i]);
    }

    TEST(Series, Front) {
        std::deque<Int> a;
        sjtu::deque<Int> b;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (a.size() + 1);
            int tmp = rand();
            a.push_back(tmp);
            b.push_back(tmp);
            for (int i = 0; i < N; i++) EXPECT_EQ(a.front(), b.front());
        }
    }

    TEST(Series, Back) {
        std::deque<Int> a;
        sjtu::deque<Int> b;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (a.size() + 1);
            int tmp = rand();
            a.push_back(tmp);
            b.push_back(tmp);
            for (int i = 0; i < N; i++) EXPECT_EQ(a.back(), b.back());
        }
    }

    TEST(Series, IteratorAddN) {
        std::deque<Int> a;
        sjtu::deque<Int> b;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (a.size() + 1);
            int tmp = rand();
            a.insert(a.begin() + pos, tmp);
            b.insert(b.begin() + pos, tmp);
        }
        for (int i = 0; i < N; i++) {
            EXPECT_EQ(*(a.begin() + i), *(b.begin() + i));
            int tmp = rand();
            *(a.begin() + i) = tmp;
            *(b.begin() + i) = tmp;
        }
        for (int i = 1; i <= N; i++) EXPECT_EQ(*(a.end() + (-i)), *(b.end() + (-i)));
        ExpectEqual(a, b);
    }

    TEST(Series, IteratorRedN) {
        std::deque<Int> a;
        sjtu::deque<Int> b;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (a.size() + 1);
            int tmp = rand();
            a.insert(a.begin() + pos, tmp);
            b.insert(b.begin() + pos, tmp);
        }
        for (int i = 1; i <= N; i++) {
            int pos = rand() % (a.size());
            int tmp = rand();
            EXPECT_EQ(*(a.end() - i), *(b.end() - i));
            *(a.end() - i) = tmp;
            *(b.end() - i) = tmp;
        }
        for (int i = 0; i < N; i++) {
            int pos = rand() % (a.size());
            EXPECT_EQ(*(a.begin() - (-i)), *(b.begin() - (-i)));
        }
        ExpectEqual(a, b);
    }


    TEST(Series, IteratorAddEN) {
        std::deque<Int> a;
        sjtu::deque<Int> b;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (a.size() + 1);
            int tmp = rand();
            a.insert(a.begin() += pos, tmp);
            b.insert(b.begin() += pos, tmp);
        }
        for (int i = 0; i < N; i++) {
            EXPECT_EQ(*(a.begin() += i), *(b.begin() += i));
            int tmp = rand();
            *(a.begin() + i) = tmp;
            *(b.begin() + i) = tmp;
        }
        for (int i = 1; i <= N; i++) {
            EXPECT_EQ(*(a.end() += (-i)), *(b.end() += (-i)));
        }
        ExpectEqual(a, b);
    }

    TEST(Series, IteratorRedEN) {
        std::deque<Int> a;
        sjtu::deque<Int> b;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (a.size() + 1);
            int tmp = rand();
            a.insert(a.begin() += pos, tmp);
            b.insert(b.begin() += pos, tmp);
        }
        for (int i = 1; i <= N; i++) {
            int pos = rand() % (a.size());
            EXPECT_EQ(*(a.end() -= i), *(b.end() -= i));
            int tmp = rand();
            *(a.end() - i) = tmp;
            *(b.end() - i) = tmp;
        }
        for (int i = 0; i < N; i++) {
            int pos = rand() % (a.size());
            EXPECT_EQ(*(a.begin() -= (-i)), *(b.begin() -= (-i)));
        }
        ExpectEqual(a, b);
    }

    TEST(Series, IteratorPAddOne) {
        std::deque<Int> a;
        sjtu::deque<Int> b;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (a.size() + 1);
            int tmp = rand();
            a.insert(a.begin() + pos, tmp);
            b.insert(b.begin() + pos, tmp);
        }
        auto itB = b.begin(), tB = itB;
        for (auto itA = a.begin(), tA = itA; itA != a.end(); tA = ++itA, tB = ++itB) {
            EXPECT_EQ(*itA, *itB);
            if (tB != b.end()) EXPECT_EQ(*tA, *tB);
            *tA = *tB = rand();
        }
        ExpectEqual(a, b);
    }

    TEST(Series, IteratorPRedOne) {
        std::deque<Int> a;
        sjtu::deque<Int> b;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (a.size() + 1);
            int tmp = rand();
            a.insert(a.begin() + pos, tmp);
            b.insert(b.begin() + pos, tmp);
        }
        auto itB = --b.end(), tB = itB;
        for (auto itA = --a.end(), tA = itA;; tA = --itA, tB = --itB) {
            EXPECT_EQ(*itA, *itB);
            if (tB != b.end()) EXPECT_EQ(*tA, *tB);
            *tA = *tB = rand();
            if (itA == a.begin()) break;
        }
        ExpectEqual(a, b);
    }

    TEST(Series, IteratorSAddOne) {
        std::deque<Int> a;
        sjtu::deque<Int> b;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (a.size() + 1);
            int tmp = rand();
            a.insert(a.begin() + pos, tmp);
            b.insert(b.begin() + pos, tmp);
        }
        auto itB = b.begin(), tB = itB;
        for (auto itA = a.begin(), tA = itA; itA != a.end(); tA = itA++, tB = itB++) {
            EXPECT_EQ(*itA, *itB);
            if (tB != b.end()) EXPECT_EQ(*tA, *tB);
            *tA = *tB = rand();
        }
        ExpectEqual(a, b);
    }

    TEST(Series, IteratorSRedOne) {
        std::deque<Int> a;
        sjtu::deque<Int> b;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (a.size() + 1);
            int tmp = rand();
            a.insert(a.begin() + pos, tmp);
            b.insert(b.begin() + pos, tmp);
        }
        auto itB = b.end(), tB = itB;
        auto itA = a.end(), tA = itA;
        tB = itB--;
        tA = itA--;
        for (;; tA = itA--, tB = itB--) {
            EXPECT_EQ(*itA, *itB);
            if (tB != b.end()) EXPECT_EQ(*tA, *tB);
            *itA = *itB = rand();
            if (itA == a.begin()) break;
        }
        ExpectEqual(a, b);
    }


    TEST(Series, IteratorMinusOperator) {
        std::deque<Int> a;
        sjtu::deque<Int> b;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (a.size() + 1);
            int tmp = rand();
            a.push_back(tmp);
            b.push_back(tmp);
        }
        auto itA1 = a.begin(), itA2 = a.begin();
        auto itB1 = b.begin(), itB2 = b.begin();
        int tmp1 = rand() % (a.size() + 1), tmp2 = rand() % (a.size() + 1);
        for (int i = 0; i < tmp1; i++) itA1++, itB1++;
        for (int i = 0; i < tmp2; i++) itA2++, itB2++;
        EXPECT_EQ (itA2 - itA1, itB2 - itB1);
        EXPECT_EQ (a.end() - a.begin(), b.end() - b.begin());
        EXPECT_EQ(itB1 + (itB2 - itB1), itB2);
    }

    TEST(Series, ErrorBracket) {
        sjtu::deque<Int> a;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (a.size() + 1);
            int tmp = rand();
            a.push_back(tmp);
        }
        int successCounter = 0;
        EXPECT_ANY_THROW(a[a.size()] = 0);
        EXPECT_ANY_THROW(a[-1] = 0);
    }

    TEST(Series, ErrorAt) {
        sjtu::deque<Int> a;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (a.size() + 1);
            int tmp = rand();
            a.push_back(tmp);
        }
        EXPECT_ANY_THROW(a.at(a.size()) = 0);
        EXPECT_ANY_THROW(a.at(-1) = 0);
    }

    TEST(Series, ErrorIterator) {
        sjtu::deque<Int> a;
        for (int i = 0; i < N; i++) {
            int pos = rand() % (a.size() + 1);
            int tmp = rand();
            a.push_back(tmp);
        }
        EXPECT_ANY_THROW(*a.end() = 0);
        EXPECT_ANY_THROW(*--a.begin());
        EXPECT_ANY_THROW(*++a.end());
    }

    TEST(Series, ErrorInsert) {
        sjtu::deque<Int> a, b;
        for (int i = 0; i < N; i++) {
            int tmp = rand();
            a.push_back(tmp);
        }
        EXPECT_ANY_THROW(b.insert(a.begin(), 0););
        EXPECT_ANY_THROW(b.insert(a.end(), 0));
        EXPECT_ANY_THROW(b.insert(a.begin() + N / 2, 0));
    }


    TEST(Series, ErrorErase) {
        sjtu::deque<Int> a, b;
        for (int i = 0; i < N; i++) {
            int tmp = rand();
            a.push_back(tmp);
        }
        EXPECT_ANY_THROW(b.erase(a.begin()));
        EXPECT_ANY_THROW(b.erase(a.end()));
        EXPECT_ANY_THROW(b.erase(a.begin() + N / 2));
        EXPECT_ANY_THROW(b.erase(b.end()));
    }

    TEST(Series, Size) {
        sjtu::deque<Int> a;
        std::deque<Int> b;
        for (int i = 0; i < N; i++) {
            int tmp = rand();
            a.push_back(tmp);
            b.push_back(tmp);
            EXPECT_EQ(a.size(), b.size());
        }
    }

    TEST(Series, Empty) {
        sjtu::deque<Int> a;
        std::deque<Int> b;
        for (int i = 0; i < N; i++) {
            EXPECT_EQ(a.empty(), b.empty());
            int tmp = rand();
            a.push_back(tmp);
            b.push_back(tmp);
        }
    }

    TEST(Series, CopyConstructor) {
        std::deque<DynamicType> a;
        sjtu::deque<DynamicType> b;
        int stdCounter = 0;
        int srcCounter = 0;
        for (int i = 0; i < N; i++) {
            a.push_back(DynamicType(&stdCounter));
            b.push_back(DynamicType(&srcCounter));
        }
        EXPECT_EQ(stdCounter, srcCounter);
        std::deque<DynamicType> tmpA(a);
        sjtu::deque<DynamicType> tmpB(b);
        EXPECT_EQ(stdCounter, srcCounter);
        a.clear();
        b.clear();
        EXPECT_EQ(stdCounter, srcCounter);
        a = tmpA = tmpA = a;
        b = tmpB = tmpB = b;
        EXPECT_EQ(stdCounter, srcCounter);
        a.clear();
        b.clear();
        tmpA.clear();
        tmpB.clear();
        EXPECT_EQ(stdCounter, srcCounter);
    }

    TEST(Series, EqualOperator) {
        std::deque<DynamicType> a;
        sjtu::deque<DynamicType> b;
        int stdCounter = 0;
        int srcCounter = 0;
        for (int i = 0; i < N; i++) {
            a.push_back(DynamicType(&stdCounter));
            b.push_back(DynamicType(&srcCounter));
        }
        EXPECT_EQ(stdCounter, srcCounter);
        std::deque<DynamicType> tmpA;
        sjtu::deque<DynamicType> tmpB;
        a = tmpA = tmpA = a = tmpA = a = a = a = a;
        b = tmpB = tmpB = b = tmpB = b = b = b = b;
        EXPECT_EQ(stdCounter, srcCounter);
        a.clear();
        b.clear();
        EXPECT_EQ(stdCounter, srcCounter);
        tmpA.clear();
        tmpB.clear();
        EXPECT_EQ(stdCounter, srcCounter);
    }

    TEST(Series, MemoryLeak) {
        sjtu::deque<DynamicType> *a = new sjtu::deque<DynamicType>;
        int srcCounter = 0;
        for (int i = 0; i < N; i++) {
            a->push_back(DynamicType(&srcCounter));
            a->insert(a->begin() + rand() % (a->size() + 1), DynamicType(&srcCounter));
            a->push_front(DynamicType(&srcCounter));
        }
        a->clear();
        EXPECT_EQ(srcCounter, 0);
        for (int i = 0; i < N; i++) {
            a->push_back(DynamicType(&srcCounter));
            a->insert(a->begin() + rand() % (a->size() + 1), DynamicType(&srcCounter));
            a->push_front(DynamicType(&srcCounter));
        }
        for (int i = 0; i < 3 * N; i++) { a->pop_front(); }
        EXPECT_EQ(srcCounter, 0);
        for (int i = 0; i < N; i++) {
            a->push_back(DynamicType(&srcCounter));
            a->insert(a->begin() + rand() % (a->size() + 1), DynamicType(&srcCounter));
            a->push_front(DynamicType(&srcCounter));
        }
        delete a;
        EXPECT_EQ(srcCounter, 0);
    }

    TEST(Series, DISABLED_Synthesis) {
        std::deque<Int> a, tA(a), ttA(tA);
        sjtu::deque<Int> b, tB(b), ttB(tB);
        for (int i = 0; i < N; i++) {
            int tmp = 0;
            a.push_back(tmp);
            b.push_back(tmp);
        }
        ExpectEqual(tA, tB);
        tA = ttA;
        tB = ttB;
        ExpectEqual(tA, tB);
        tA = a = a;
        tB = b = b;
        ExpectEqual(tA, tB);
        a.clear();
        b.clear();
        ExpectEqual(tA, tB);
        tA = a = tA = tA;
        tB = b = tB = tB;
        ExpectEqual(a, b);
        const std::deque<Int> cA = a;
        const sjtu::deque<Int> cB = b;
        std::deque<Int>::iterator itA;
        sjtu::deque<Int>::iterator itB;
        itA = a.end();
        itB = b.end();
        for (int i = 0, delta; i < N; i++) {
            int tmp = rand();
            delta = itA - a.begin();
            EXPECT_EQ(b.begin() + delta, itB);
            if (rand() % 2) {
                if (itA != a.begin()) {
                    int offset = rand() % (itA - a.begin());
                    itA -= offset;
                    itB -= offset;
                }
            } else {
                if (itA != a.end()) {
                    int offset = rand() % (a.end() - itA);
                    itA += offset;
                    itB += offset;
                }
            }
            delta = itA - a.begin();
            EXPECT_EQ(b.begin() + delta, itB);
            itA = a.insert(itA, tmp);
            itB = b.insert(itB, tmp);
            delta = itA - a.begin();
            EXPECT_EQ(b.begin() + delta, itB);
            EXPECT_EQ(*itA, *itB);
        }
        tA = a = a = a;
        tB = b = b = b;
        a.clear();
        b.clear();
        ttA = a = a = a;
        ttB = b = b = b;
        std::deque<Int> tttA(tA);
        sjtu::deque<Int> tttB(tB);
        ExpectEqual(a, b);
        ExpectEqual(tA, tB);
        ExpectEqual(ttA, ttB);
        ExpectEqual(tttA, tttB);
        for (int i = 0; i < N; i++) {
            int tmp = rand();
            a.push_back(tmp);
            b.push_back(tmp);
        }
        itA = a.end();
        itB = b.end();
        for (int i = 0, delta; i < N; i++) {
            int tmp = rand();
            delta = itA - a.begin();
            EXPECT_EQ(b.begin() + delta, itB);
            if (rand() % 2) {
                if (itA != a.begin()) {
                    int offset = rand() % (itA - a.begin());
                    itA -= offset;
                    itB -= offset;
                }
            } else {
                if (itA != a.end()) {
                    int offset = rand() % (a.end() - itA);
                    itA += offset;
                    itB += offset;
                }
            }
            delta = itA - a.begin();
            EXPECT_EQ(b.begin() + delta, itB);
            if (itA == a.end()) {
                itA--;
                itB--;
            }
            itA = a.erase(itA);
            itB = b.erase(itB);
            delta = itA - a.begin();
            EXPECT_EQ(b.begin() + delta, itB);
        }
        ExpectEqual(a, b);
        ExpectEqual(tA, tB);
        ExpectEqual(ttA, ttB);

        auto citA = cA.cbegin();
        auto citB = cB.cbegin();
        // TODO: there may be something wrong with this test
        for (; citA != cA.end(); citA++, citB++) {
            EXPECT_EQ(*citA, *citB);
        }
        ttA.clear();
        ttB.clear();
        a.clear();
        b.clear();
        ttA.clear();
        ttB.clear();
    }

    TEST(Series, IteratorInsertPersistence) {
        std::deque<Int> a;
        sjtu::deque<Int> b;
        std::deque<Int>::iterator itA;
        sjtu::deque<Int>::iterator itB;
        itA = a.end();
        itB = b.end();
        for (int i = 0, delta; i < N; i++) {
            int tmp = rand();
            delta = itA - a.begin();
            EXPECT_EQ(b.begin() + delta, itB);
            if (rand() % 2) {
                if (itA != a.begin()) {
                    int offset = rand() % (itA - a.begin());
                    itA -= offset;
                    itB -= offset;
                }
            } else {
                if (itA != a.end()) {
                    int offset = rand() % (a.end() - itA);
                    itA += offset;
                    itB += offset;
                }
            }
            delta = itA - a.begin();
            EXPECT_EQ(b.begin() + delta, itB);
            itA = a.insert(itA, tmp);
            itB = b.insert(itB, tmp);
            delta = itA - a.begin();
            EXPECT_EQ(b.begin() + delta, itB);
            EXPECT_EQ(*itA, *itB);
        }
        ExpectEqual(a, b);
    }

    TEST(Series, IteratorErasePersistence) {
        std::deque<Int> a;
        sjtu::deque<Int> b;
        for (int i = 0; i < N; i++) {
            int tmp = rand();
            a.push_back(tmp);
            b.push_back(tmp);
        }
        std::deque<Int>::iterator itA;
        sjtu::deque<Int>::iterator itB;
        itA = a.end();
        itB = b.end();
        for (int i = 0, delta; i < N; i++) {
            int tmp = rand();
            delta = itA - a.begin();
            EXPECT_EQ(b.begin() + delta, itB);
            if (rand() % 2) {
                if (itA != a.begin()) {
                    int offset = rand() % (itA - a.begin());
                    itA -= offset;
                    itB -= offset;
                }
            } else {
                if (itA != a.end()) {
                    int offset = rand() % (a.end() - itA);
                    itA += offset;
                    itB += offset;
                }
            }
            delta = itA - a.begin();
            EXPECT_EQ(b.begin() + delta, itB);
            if (itA == a.end()) {
                itA--;
                itB--;
            }
            itA = a.erase(itA);
            itB = b.erase(itB);
            delta = itA - a.begin();
            EXPECT_EQ(b.begin() + delta, itB);
        }
        ExpectEqual(a, b);
    }
}