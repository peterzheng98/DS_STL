//
// Created by Alex Chi on 2019-07-23.
//

#include <gtest/gtest.h>

#include <queue>
#include "priority_queue.hpp"


namespace {
    /**
     * These tests are originally test data one
    */
    TEST(Basic, ConstructorAndPush) {
        sjtu::priority_queue<int> pq;
        for (int i = 100; i > 0; --i) {
            pq.push(i);
        }
        int i = 100;
        while (!pq.empty()) {
            EXPECT_EQ(pq.top(), i--);
            pq.pop();
        }
        std::cout << std::endl;
        for (int i = 1000; i > 100; --i) {
            pq.push(i);
        }
        sjtu::priority_queue<int> pqBack(pq);
        EXPECT_EQ(pqBack.size(), 900);
        sjtu::priority_queue<int> pqBB;
        for (int i = 10; i <= 10000; ++i) {
            pqBB.push(i);
        }
        EXPECT_EQ(pqBB.size(), 9991);
        pqBB = pq;
        EXPECT_EQ(pqBB.size(), 900);
    }

    TEST(Basic, Size) {
        sjtu::priority_queue<long long> pq;
        for (int i = 1; i <= 1000; ++i) {
            pq.push(rand());
        }
        EXPECT_EQ(pq.size(), 1000);
    }

    TEST(Basic, Exception) {
        sjtu::priority_queue<int> pq;
        EXPECT_ANY_THROW(pq.top());
    }
}

namespace {
    /**
     * These tests are originally test data four
     * which contain the following credit message:
     * > provided by 徐植天
     * And here I modified all tests to compare with
     * std::priority_queue
    */

    TEST(Std, ConstructorAndPush) {
        sjtu::priority_queue<int> q;
        std::priority_queue<int> q_;
        int up = 600;
        for (int i = 0; i < up; i++) {
            q.push(i);
            q_.push(i);
        }
        for (int i = 0; i < up / 2; i++) {
            EXPECT_EQ(q.top(), q_.top());
            q.pop();
            q_.pop();
        }
        EXPECT_EQ(q.size(), q_.size());
        sjtu::priority_queue<int> nq(q);
        std::priority_queue<int> nq_(q_);
        EXPECT_EQ(nq.size(), nq_.size());
        for (int i = up * 2; i < up * 2 + 10; i++) {
            nq.push(i);
            nq_.push(i);
        }
        EXPECT_EQ(nq_.size(), nq.size());
        for (int i = 0; i < 5; i++) {
            EXPECT_EQ(nq_.top(), nq.top());
            nq.pop();
            nq_.pop();
        }
        nq = q;
        nq_ = q_;
        EXPECT_EQ(nq_.size(), nq.size());
    }

    TEST(Std, Size) {
        sjtu::priority_queue<int> q, q2;
        std::priority_queue<int> q_, q2_;
        while (!q.empty()) q.pop();
        for (int i = 0; i < 100; i++) {
            q.push(i);
            q_.push(i);
        }
        q2 = q;
        q2_ = q_;
        q2.push(101), q2.push(102);
        q2_.push(101), q2_.push(102);
        EXPECT_EQ(q.size(), q_.size());
        EXPECT_EQ(q2.size(), q2_.size());
        q2 = q2;
        q2_ = q2_;
        EXPECT_EQ(q2.size(), q2_.size());
    }

    TEST(Std, Exception) {
        std::cout << "Testing Exception" << std::endl;
        sjtu::priority_queue<int> q, q2;
        while (!q.empty()) q.pop();
        for (int i = 0; i < 100; i++) q.push(i);
        q2 = q;
        for (int i = 0; i < 100; i++) q2.pop();
        int s = 0;
        EXPECT_ANY_THROW(q2.pop());
        EXPECT_ANY_THROW(q2.top());
    }

    struct guest {
        int x, y;

        int getvalue() const {
            return x * 10 + y;
        }

        guest() : x(0), y(0) {}

        guest(int a, int b) : x(a), y(b) {}

        guest(const guest &other) {
            x = other.x;
            y = other.y;
        }

        guest &operator=(const guest &other) {
            x = other.x;
            y = other.y;
            return *this;
        }
    };

    bool operator<(const guest &a, const guest &b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }

    void test_guest_helper(sjtu::priority_queue<guest> tmp, std::priority_queue<guest> tmp_) {
        for (int i = 90; i < 95; i++) {
            int x = i / 10;
            int y = i % 10;
            tmp.push(guest(x, y));
            tmp_.push(guest(x, y));
        }
        EXPECT_EQ(tmp.size(), tmp_.size());
        EXPECT_EQ(tmp.top().getvalue(), tmp_.top().getvalue());
    }

    TEST(Std, Guest) {
        sjtu::priority_queue<guest> q, q2;
        std::priority_queue<guest> q_, q2_;
        while (!q.empty()) q.pop();
        for (int i = 0; i < 100; i++) {
            int x = i / 10;
            int y = i % 10;
            q.push(guest(x, y));
            q_.push(guest(x, y));
        }
        EXPECT_EQ(q.size(), q_.size());
        q2 = q;
        q2_ = q_;
        for (int i = 0; i < 10; i++) {
            q2.pop();
            q2_.pop();
        }
        EXPECT_EQ(q2.size(), q2_.size());
        EXPECT_EQ(q2.top().getvalue(), q2_.top().getvalue());
        test_guest_helper(q2, q2_);
        EXPECT_EQ(q2.size(), q2_.size());
        EXPECT_EQ(q2.top().getvalue(), q2_.top().getvalue());
    }

    TEST(Std, SameCopy) {
        sjtu::priority_queue<guest> q;
        std::priority_queue<guest> q_;
        for (int i = 0; i < 50; i++) {
            int x = i * 2 / 10;
            int y = i * 2 % 10;
            q.push(guest(x, y));
            q_.push(guest(x, y));
        }
        EXPECT_EQ(q.size(), q_.size());
        for (int i = 0; i < q.size(); i++) {
            EXPECT_EQ(q.top().getvalue(), q_.top().getvalue());
        }
        q = q;
        q_ = q_;
        for (int i = 0; i < 10; i++) {
            q.pop();
            q_.pop();
        }
        EXPECT_EQ(q.size(), q_.size());
        for (int i = 0; i < q.size(); i++) {
            EXPECT_EQ(q.top().getvalue(), q_.top().getvalue());
        }
    }

    TEST(Std, Sort) {
        sjtu::priority_queue<guest> q;
        std::priority_queue<guest> q_;
        for (int i = 0; i < 50; i++) {
            int x = i / 10;
            int y = i % 10;
            q.push(guest(x, y));
            q_.push(guest(x, y));
        }
        for (int i = 0; i < 50; i++) {
            EXPECT_EQ(q.top().getvalue(), q_.top().getvalue());
            q.pop();
            q_.pop();
        }
    }

    struct binary {
        int len;
        int number[10];

        std::string getexpression() const {
            std::string ret = "";
            for (int i = 0; i < len; i++) ret += char(48 + number[i]);
            return ret;
        }

        binary(int *p = NULL, int l = 0) {
            len = l;
            for (int i = 0; i < l; i++) number[i] = p[i];
        }

        binary(const binary &other) {
            len = other.len;
            for (int i = 0; i < len; i++) number[i] = other.number[i];
        }

        binary &operator=(const binary &other) {
            len = other.len;
            for (int i = 0; i < len; i++) number[i] = other.number[i];
            return *this;
        }
    };

    bool operator<(const binary &a, const binary &b) {
        if (a.len != b.len) return a.len < b.len;
        for (int i = 0; i < a.len; i++) {
            if (a.number[i] < b.number[i]) return true;
            if (a.number[i] > b.number[i]) return false;
        }
        return false;
    }

    TEST(Std, Extra) {
        sjtu::priority_queue<binary> q;
        std::priority_queue<binary> q_;
        int e[10];
        for (int i = 1; i < 1000; i++) {
            int len = 0, t = i;
            while (t) {
                e[len++] = t % 2;
                t /= 2;
            }
            for (int j = 0; j < len / 2; j++) {
                int tmp = e[j];
                e[j] = e[len - 1 - j];
                e[len - 1 - j] = tmp;
            }
            q.push(binary(e, len));
            q_.push(binary(e, len));
        }
        for (int i = 1; i < 1000; i++) {
            EXPECT_EQ(q.top().getexpression(), q_.top().getexpression());
            q.pop();
            q_.pop();
        }
    }
}

namespace {
    /**
     * These tests are originally test data two
     * which contain the following credit message:
     * > provided by 林伟鸿
     * And here I modified all tests to compare with
     * std::priority_queue
    */
    int A = 325, B = 2336, last = 233, mod = 1000007;

    int Rand() {
        return last = (A * last + B) % mod;
    }

    //测试 push 以及 top 访问
    TEST(Simple, Push) {
        sjtu::priority_queue<int> Q;
        std::priority_queue<int> q;
        for (int i = 1; i <= 5000; i++) {
            int x = Rand();
            Q.push(x);
            q.push(x);
            EXPECT_EQ(Q.top(), q.top());
        }
    }

    //测试 pop 以及 top 访问
    TEST(Simple, Pop) {
        sjtu::priority_queue<int> Q;
        std::priority_queue<int> q;
        for (int i = 1; i <= 5000; i++) {
            int x = Rand();
            Q.push(x);
            q.push(x);
        }
        EXPECT_EQ(q.size(), Q.size());
        while (!Q.empty()) {
            EXPECT_EQ(Q.top(), q.top());
            q.pop();
            Q.pop();
        }
    }

    //测试 push pop 同时操作
    TEST(Simple, PushAndPop) {
        sjtu::priority_queue<int> Q;
        std::priority_queue<int> q;
        int size = 0;
        for (int i = 1; i <= 6000; i++) {
            if (!size) {
                int x = Rand();
                Q.push(x);
                q.push(x);
                size++;
            } else {
                int p = Rand() % 2;
                if (!p) {
                    Q.pop();
                    q.pop();
                    size--;
                } else {
                    int x = Rand();
                    Q.push(x);
                    q.push(x);
                    size++;
                }
            }
            if (size) {
                EXPECT_EQ(q.top(), Q.top());
            }
        }
    }

    //测试拷贝构造
    TEST(Simple, CopyConstructor) {
        sjtu::priority_queue<int> Q;
        std::priority_queue<int> q;
        for (int i = 1; i <= 5000; i++) {
            int x = Rand();
            Q.push(x);
            q.push(x);
        }
        sjtu::priority_queue<int> Q2(Q);
        std::priority_queue<int> q2(q);
        EXPECT_EQ(Q2.size(), q2.size());
        while (!Q2.empty()) {
            EXPECT_EQ(Q2.top(), q2.top());
            Q2.pop();
            q2.pop();
        }
    }

    TEST(Simple, EqualOperator) {//测试"="
        sjtu::priority_queue<int> Q;
        std::priority_queue<int> q;
        for (int i = 1; i <= 5000; i++) {
            int x = Rand();
            Q.push(x);
            q.push(x);
        }
        sjtu::priority_queue<int> Q2;
        std::priority_queue<int> q2;
        Q2 = Q;
        q2 = q;
        EXPECT_EQ(Q2.size(), q2.size());
        while (!Q2.empty()) {
            EXPECT_EQ(Q2.top(), q2.top());
            Q2.pop();
            q2.pop();
        }
    }

    //测试堆为空时top是否报错
    TEST(Simple, TopThrow) {
        sjtu::priority_queue<int> Q;
        for (int i = 1; i <= 100; i++) Q.push(Rand());
        EXPECT_ANY_THROW({
                             while (!Q.empty()) {
                                 Q.pop();
                             }
                             Q.top();
                         });
    }

    //测试堆为空时pop是否报错
    TEST(Simple, PopThrow) {
        sjtu::priority_queue<int> Q;
        for (int i = 1; i <= 100; i++) Q.push(Rand());
        EXPECT_ANY_THROW({
                             while (!Q.empty()) {
                                 Q.pop();
                             }
                             Q.pop();
                         });
    }

    //check8用于测试拷贝构造时是否在复制之前new出新的堆，若堆在pop是回收节点内存，那么会出现第二次回收时崩溃
    TEST(Simple, CopyConstructorMemory) {
        sjtu::priority_queue<int> Q;
        for (int i = 1; i <= 30000; i++) {
            Q.push(Rand());
        }
        sjtu::priority_queue<int> Q2(Q);
        while (!Q.empty()) {
            Q.pop();
        }
        while (!Q2.empty()) {
            Q2.pop();
        }
    }

    //check9与check8同理，测试的是"="操作执行是是否new出新节点
    TEST(Simple, EqualOperatorMemory) {
        sjtu::priority_queue<int> Q;
        for (int i = 1; i <= 30000; i++) {
            Q.push(Rand());
        }
        sjtu::priority_queue<int> Q2;
        Q2 = Q;
        while (!Q.empty()) {
            Q.pop();
        }
        while (!Q2.empty()) {
            Q2.pop();
        }
    }

    struct intnum {
        int num;

        intnum(int p = 0) : num(p) {}

        bool operator<(const intnum &b) const {
            return num < b.num;
        }
    };

    //考察传到自己的类是否能正常工作
    TEST(Simple, ForeignClass) {
        sjtu::priority_queue<intnum> Q;
        std::priority_queue<intnum> q;
        int size = 0;
        for (int i = 1; i <= 3000; i++) {
            if (!size) {
                int x = Rand();
                Q.push(intnum(x));
                q.push(intnum(x));
                size++;
            } else {
                int p = Rand() % 2;
                if (!p) {
                    Q.pop();
                    q.pop();
                    size--;
                } else {
                    int x = Rand();
                    Q.push(intnum(x));
                    q.push(intnum(x));
                    size++;
                }
            }
            if (size) {
                EXPECT_EQ(Q.top().num, q.top().num);
            }
        }
        printf("\n");
    }



    //check11 为 CE test 将注释代码进行编译，如果没有 CE 则通过该测试点

    struct node {
        int num;

        node(int p) : num(p) {}

        bool operator<(const node &b) const {
            return num < b.num;
        }
    };

    TEST(Simple, ShouldCompile) {
        sjtu::priority_queue<node> Q;
        for (int i = 1; i <= 30000; i++)
            Q.push(node(Rand()));
        while (!Q.empty()) {
            Q.top();
            Q.pop();
        }
    }
}