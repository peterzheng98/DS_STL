//
// Created by Alex Chi on 2019-07-22.
//

#ifndef DEQUE_INTEGER_H
#define DEQUE_INTEGER_H

class Integer {
private:
    int data;
public:
    Integer(const int &value);

    Integer(const Integer &other);

    bool operator==(const Integer &t) const;
};

#endif //DEQUE_INTEGER_H
