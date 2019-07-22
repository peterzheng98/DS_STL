//
// Created by Alex Chi on 2019-07-22.
//

#include "Integer.h"

Integer::Integer(const int &value) : data(value) {}

Integer::Integer(const Integer &other) : data(other.data) {}

bool Integer::operator==(const Integer &t) const {
    return data == t.data;
}
