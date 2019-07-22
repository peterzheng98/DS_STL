//
// Created by Alex Chi on 2019-07-22.
//

#ifndef DEQUE_INT_HPP
#define DEQUE_INT_HPP


class Int {
public:
    int data;

    Int() = default;

    Int(const int &data) : data(data) {}

    Int &operator=(const Int &rhs) = default;

    bool operator<(const Int &rhs) = delete;

    bool operator>(const Int &rhs) = delete;

    bool operator<=(const Int &rhs) = delete;

    bool operator>=(const Int &rhs) = delete;

    bool operator==(const Int &rhs) const {
        return data == rhs.data;
    }

    bool operator!=(const Int &rhs) const {
        return data != rhs.data;
    }

};

#endif //DEQUE_INT_HPP
