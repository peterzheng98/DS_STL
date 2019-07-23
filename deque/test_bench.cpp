//
// Created by Alex Chi on 2019-07-22.
//

#include "deque.hpp"
#include <benchmark/benchmark.h>

namespace {
    static const int N_SPEED = 50000;

    sjtu::deque<int> a;

    static void BM_PushPopBack(benchmark::State& state) {
        a.clear();
        for (int i = 0; i < N_SPEED; i++) {
            int op = rand() % 3;
            if (op == 0) a.push_back(rand());
            else if (op == 1) a.push_front(rand());
            else if (op == 2)
                a.insert(a.begin() + rand() % (a.size() + 1), rand());
        }
        for (auto _ : state) { a.push_back(rand()); a.pop_back(); }
    }

    BENCHMARK(BM_PushPopBack);

    static void BM_PushPopFront(benchmark::State& state) {
        a.clear();
        for (int i = 0; i < N_SPEED; i++) {
            int op = rand() % 3;
            if (op == 0) a.push_back(rand());
            else if (op == 1) a.push_front(rand());
            else if (op == 2)
                a.insert(a.begin() + rand() % (a.size() + 1), rand());
        }
        for (auto _ : state) { a.push_front(rand()); a.pop_front(); }
    }

    BENCHMARK(BM_PushPopFront);

    static void BM_Front(benchmark::State& state) {
        sjtu::deque<int> a;
        for (int i = 0; i < N_SPEED; i++) {
            int op = rand() % 3;
            if (op == 0) a.push_back(rand());
            else if (op == 1) a.push_front(rand());
            else if (op == 2)
                a.insert(a.begin() + rand() % (a.size() + 1), rand());
        }
        for (auto _ : state) { a.front(); }
    }

    BENCHMARK(BM_Front);

    static void BM_Back(benchmark::State& state) {
        sjtu::deque<int> a;
        for (int i = 0; i < N_SPEED; i++) {
            int op = rand() % 3;
            if (op == 0) a.push_back(rand());
            else if (op == 1) a.push_front(rand());
            else if (op == 2)
                a.insert(a.begin() + rand() % (a.size() + 1), rand());
        }
        for (auto _ : state) { a.back(); }
    }

    BENCHMARK(BM_Back);

    static void BM_Begin(benchmark::State& state) {
        sjtu::deque<int> a;
        for (int i = 0; i < N_SPEED; i++) {
            int op = rand() % 3;
            if (op == 0) a.push_back(rand());
            else if (op == 1) a.push_front(rand());
            else if (op == 2)
                a.insert(a.begin() + rand() % (a.size() + 1), rand());
        }
        for (auto _ : state) { a.begin(); }
    }

    BENCHMARK(BM_Begin);

    static void BM_End(benchmark::State& state) {
        sjtu::deque<int> a;
        for (int i = 0; i < N_SPEED; i++) {
            int op = rand() % 3;
            if (op == 0) a.push_back(rand());
            else if (op == 1) a.push_front(rand());
            else if (op == 2)
                a.insert(a.begin() + rand() % (a.size() + 1), rand());
        }
        for (auto _ : state) { a.end(); }
    }

    BENCHMARK(BM_End);

    static void BM_IteratorAddOne(benchmark::State& state) {
        sjtu::deque<int> a;
        for (int i = 0; i < N_SPEED; i++) {
            int op = rand() % 3;
            if (op == 0) a.push_back(rand());
            else if (op == 1) a.push_front(rand());
            else if (op == 2)
                a.insert(a.begin() + rand() % (a.size() + 1), rand());
        }
        auto itA = a.begin();
        for (auto _ : state) {
            itA++;
            if (itA == a.end()) itA = a.begin();
        }
    }

    BENCHMARK(BM_IteratorAddOne);

    static void BM_IteratorRedOne(benchmark::State& state) {
        sjtu::deque<int> a;
        for (int i = 0; i < N_SPEED; i++) {
            int op = rand() % 3;
            if (op == 0) a.push_back(rand());
            else if (op == 1) a.push_front(rand());
            else if (op == 2)
                a.insert(a.begin() + rand() % (a.size() + 1), rand());
        }
        auto itA = a.end();
        for (auto _ : state) {
            itA--;
            if (itA == a.begin()) itA = a.end();
        }
    }

    BENCHMARK(BM_IteratorRedOne);

    static void BM_IteratorAddN(benchmark::State& state) {
        sjtu::deque<int> a;
        for (int i = 0; i < N_SPEED; i++) {
            int op = rand() % 3;
            if (op == 0) a.push_back(rand());
            else if (op == 1) a.push_front(rand());
            else if (op == 2)
                a.insert(a.begin() + rand() % (a.size() + 1), rand());
        }
        auto itA = a.begin();
        for (auto _ : state) { itA = a.begin() + rand() % N_SPEED; }
    }

    BENCHMARK(BM_IteratorAddN);

    static void BM_IteratorRedN(benchmark::State& state) {
        sjtu::deque<int> a;
        for (int i = 0; i < N_SPEED; i++) {
            int op = rand() % 3;
            if (op == 0) a.push_back(rand());
            else if (op == 1) a.push_front(rand());
            else if (op == 2)
                a.insert(a.begin() + rand() % (a.size() + 1), rand());
        }
        auto itA = a.end();
        for (auto _ : state) { itA = a.end() - rand() % N_SPEED; }
    }

    BENCHMARK(BM_IteratorRedN);

    static void BM_Insert(benchmark::State& state) {
        sjtu::deque<int> a;
        auto itA = a.begin();
        for (auto _ : state) { a.insert(a.begin() + rand() % (a.size() + 1), rand()); a.pop_back(); }
    }

    BENCHMARK(BM_Insert);

    static void BM_Erase(benchmark::State& state) {
        sjtu::deque<int> a;
        for (int i = 0; i < N_SPEED; i++) {
            int op = rand() % 3;
            if (op == 0) a.push_back(rand());
            else if (op == 1) a.push_front(rand());
            else if (op == 2)
                a.insert(a.begin() + rand() % (a.size() + 1), rand());
        }
        for (auto _ : state) { a.erase(a.begin() + (rand() % a.size())); a.push_back(rand()); }
    }

    BENCHMARK(BM_Erase);

    static void BM_CopyConstructor(benchmark::State& state) {
        sjtu::deque<int> a;
        for (int i = 0; i < N_SPEED; i++) {
            int op = rand() % 3;
            if (op == 0) a.push_back(rand());
            else if (op == 1) a.push_front(rand());
            else if (op == 2)
                a.insert(a.begin() + rand() % (a.size() + 1), rand());
        }
        for (auto _ : state) { sjtu::deque<int> b(a); }
    }

    BENCHMARK(BM_CopyConstructor);

    static void BM_EqualOperator(benchmark::State& state) {
        sjtu::deque<int> a;
        for (int i = 0; i < N_SPEED; i++) {
            int op = rand() % 3;
            if (op == 0) a.push_back(rand());
            else if (op == 1) a.push_front(rand());
            else if (op == 2)
                a.insert(a.begin() + rand() % (a.size() + 1), rand());
        }
        sjtu::deque<int> b;
        for (auto _ : state) { b = a; }
    }

    BENCHMARK(BM_EqualOperator);

    static void BM_At(benchmark::State& state) {
        sjtu::deque<int> a;
        for (int i = 0; i < N_SPEED; i++) {
            int op = rand() % 3;
            if (op == 0) a.push_back(rand());
            else if (op == 1) a.push_front(rand());
            else if (op == 2)
                a.insert(a.begin() + rand() % (a.size() + 1), rand());
        }
        for (auto _ : state) { a.at(rand() % N_SPEED) = rand(); }
    }

    BENCHMARK(BM_At);

    static void BM_Bracket(benchmark::State& state) {
        sjtu::deque<int> a;
        for (int i = 0; i < N_SPEED; i++) {
            int op = rand() % 3;
            if (op == 0) a.push_back(rand());
            else if (op == 1) a.push_front(rand());
            else if (op == 2)
                a.insert(a.begin() + rand() % (a.size() + 1), rand());
        }
        for (auto _ : state) { a[rand() % N_SPEED] = rand(); }
    }

    BENCHMARK(BM_Bracket);
}


BENCHMARK_MAIN();
