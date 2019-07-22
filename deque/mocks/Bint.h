//
// Created by Alex Chi on 2019-07-22.
//

#ifndef DEQUE_BINT_H
#define DEQUE_BINT_H


#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <stdexcept>

namespace Util {

    const size_t MIN_CAPACITY = 2048;

    class Bint {
        class NewSpaceFailed : public std::runtime_error {
        public:
            NewSpaceFailed();
        };

        class BadCast : public std::invalid_argument {
        public:
            BadCast();
        };

        bool isMinus = false;
        size_t length;
        int *data = nullptr;
        size_t capacity = MIN_CAPACITY;

        void _DoubleSpace();

        void _SafeNewSpace(int *&p, const size_t &len);

        explicit Bint(const size_t &capa);

    public:
        Bint();

        Bint(int x);

        Bint(long long x);

        Bint(std::string x);

        Bint(const Bint &b);

        Bint(Bint &&b) noexcept;

        Bint &operator=(int rhs);

        Bint &operator=(long long rhs);

        Bint &operator=(const Bint &rhs);

        Bint &operator=(Bint &&rhs) noexcept;

        friend Bint abs(const Bint &x);

        friend Bint abs(Bint &&x);

        friend bool operator==(const Bint &lhs, const Bint &rhs);

        friend bool operator!=(const Bint &lhs, const Bint &rhs);

        friend bool operator<(const Bint &lhs, const Bint &rhs);

        friend bool operator>(const Bint &lhs, const Bint &rhs);

        friend bool operator<=(const Bint &lhs, const Bint &rhs);

        friend bool operator>=(const Bint &lhs, const Bint &rhs);

        friend Bint operator+(const Bint &lhs, const Bint &rhs);

        friend Bint operator-(const Bint &b);

        friend Bint operator-(Bint &&b);

        friend Bint operator-(const Bint &lhs, const Bint &rhs);

        friend Bint operator*(const Bint &lhs, const Bint &rhs);

        friend std::istream &operator>>(std::istream &is, Bint &b);

        friend std::ostream &operator<<(std::ostream &os, const Bint &b);

        ~Bint();
    };
}


#endif //DEQUE_BINT_H
