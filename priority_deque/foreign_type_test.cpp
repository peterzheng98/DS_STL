//
// Created by Alex Chi on 2019-07-23.
//

#include <gtest/gtest.h>

#include <iostream>
#include <queue>
#include <vector>
#include "priority_queue.hpp"

namespace {
    /**
     * These tests are originally test data three,
     * I modified it to compare with std::priority_queue
    */
    long long aa = 13131, bb = 5353, MOD = 1e9 + 7, now = 1;

    int rand() {
        for (int i = 1; i < 3; i++)
            now = (now * aa + bb) % MOD;
        return now;
    }

    class T1//no_construct
    {
    public:
        int data;

        T1(int key) : data(key) {}
    };

    bool operator==(const T1 &a, const T1 &b) {
        return a.data == b.data;
    }

    std::ostream &operator<<(std::ostream &os, const T1 &a) {
        os << a.data;
        return os;
    }

    class T2//pointer + no_construct
    {
    public:
        int *data;

        T2(int key) : data(new int(key)) {}

        T2(const T2 &other) : data(new int(*(other.data))) {}

        T2 &operator=(const T2 &other) {
            if (this == &other) return *this;
            delete data;
            data = new int(*(other.data));
            return *this;
        }

        ~T2() { delete data; }
    };

    bool operator==(const T2 &a, const T2 &b) {
        return *(a.data) == *(b.data);
    }

    std::ostream &operator<<(std::ostream &os, const T2 &a) {
        os << *(a.data);
        return os;
    }

    class T3 {
    public:
        int data;

        T3() : data(0) {}

        T3(int key) : data(key) {}
    };

    bool operator==(const T3 &a, const T3 &b) {
        return a.data == b.data;
    }

    std::ostream &operator<<(std::ostream &os, const T3 &a) {
        os << a.data;
        return os;
    }

    class T4//pointer
    {
    public:
        int *data;

        T4() : data(new int(0)) {}

        T4(int key) : data(new int(key)) {}

        T4(const T4 &other) : data(new int(*(other.data))) {}

        T4 &operator=(const T4 &other) {
            if (this == &other) return *this;
            delete data;
            data = new int(*(other.data));
            return *this;
        }

        ~T4() { delete data; }
    };

    bool operator==(const T4 &a, const T4 &b) {
        return *(a.data) == *(b.data);
    }

    std::ostream &operator<<(std::ostream &os, const T4 &a) {
        os << *(a.data);
        return os;
    }

    struct cmp {
        bool operator()(const T1 &a, const T1 &b) const { return a.data < b.data; }

        bool operator()(const T2 &a, const T2 &b) const { return *(a.data) < *(b.data); }

        bool operator()(const T3 &a, const T3 &b) const { return a.data < b.data; }

        bool operator()(const T4 &a, const T4 &b) const { return *(a.data) < *(b.data); }

        bool operator()(const int &a, const int &b) const { return a < b; }
    };

    template<class T>
    void run_a_test_helper() {
        sjtu::priority_queue<T, cmp> q;
        std::priority_queue<T, std::vector<T>, cmp> q_;
        int test_num = 10000;
        for (int i = 1; i <= test_num; i++) {
            auto rnd = rand();
            q.push(T(rnd));
            q_.push(T(rnd));
            if (i % 100 == 0) {
                EXPECT_EQ(q.top(), q_.top());
                EXPECT_EQ(q.size(), q_.size());
                EXPECT_EQ(q.empty(), q_.empty());
            }
            if (i % 100 > 900) {
                q.pop();
                q_.pop();
            }
        }
    }

    template<class T>
    void run_a_copy_test_helper() {
        sjtu::priority_queue<T, cmp> q;
        std::priority_queue<T, std::vector<T>, cmp> q_;
        int num = 5000;
        for (int i = 1; i <= num; i++) {
            auto rnd = rand();
            q.push(T(rnd));
            q_.push(T(rnd));
        }
        for (int j = 1; j <= 5; j++) {
            sjtu::priority_queue<T, cmp> t(q);
            std::priority_queue<T, std::vector<T>, cmp> t_(q_);
            for (int i = 1; i <= 100; i++) {
                auto rnd = rand();
                t.push(T(rnd));
                t_.push(T(rnd));
            }
            for (int k = 1; k <= 10; k++) {
                EXPECT_EQ(t.top(), t_.top());
                EXPECT_EQ(t.size(), t_.size());
                EXPECT_EQ(t.empty(), t_.empty());
                t.pop();
                t_.pop();
            }
            sjtu::priority_queue<T, cmp> p;
            std::priority_queue<T, std::vector<T>, cmp> p_;
            p = t;
            p_ = t_;
            p = p = p = p;
            p_ = p_ = p_ = p_;
            for (int i = 1; i <= 100; i++) {
                auto rnd = rand();
                p.push(T(rnd));
                p_.push(T(rnd));
            }
            for (int k = 1; k <= 10; k++) {
                EXPECT_EQ(t.top(), t_.top());
                EXPECT_EQ(t.size(), t_.size());
                EXPECT_EQ(t.empty(), t_.empty());
                p.pop();
                p_.pop();
            }
        }
    }

    TEST(Foreign, Normal) {
        run_a_test_helper<int>();
        run_a_test_helper<T3>();
        run_a_test_helper<T4>();
    }

    TEST(Foreign, Advanced) {
        run_a_test_helper<T1>();
        run_a_test_helper<T2>();
    }

    TEST(Foreign, CopyNormal) {
        printf("Normal copy&= test...");
        run_a_copy_test_helper<int>();
        run_a_copy_test_helper<T3>();
        run_a_copy_test_helper<T4>();
    }

    TEST(Foreign, CopyAdvanced) {
        printf("Advanced copy&= test...");
        run_a_copy_test_helper<T1>();
        run_a_copy_test_helper<T2>();
    }

    TEST(Foreign, Exception) {
        bool flag = 0;
        printf("Exception test...");
        sjtu::priority_queue<int, cmp> q;
        for (int i = 1; i <= 100; i++)
            q.push(rand());
        for (int i = 1; i <= 100; i++)
            q.pop();
        EXPECT_THROW(q.pop(), sjtu::container_is_empty);
        EXPECT_THROW((int) q.top(), sjtu::container_is_empty);
    }
}
