//
// Created by Alex Chi on 2019-07-22.
//

#include "DynamicType.h"

DynamicType::DynamicType(int *p) : pct(p), data(new double[2]) {
    (*pct)++;
}

DynamicType::DynamicType(const DynamicType &other) : pct(other.pct), data(new double[2]) {
    (*pct)++;
}

DynamicType &DynamicType::operator=(const DynamicType &other) {
    if (this == &other) return *this;
    (*pct)--;
    pct = other.pct;
    (*pct)++;
    delete[] data;
    data = new double[2];
    return *this;
}

DynamicType::~DynamicType() {
    delete[] data;
    (*pct)--;
}

bool DynamicType::operator==(const DynamicType &rhs) const { return true; }
