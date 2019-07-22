//
// Created by Alex Chi on 2019-07-22.
//

#ifndef DEQUE_DYNAMICTYPE_H
#define DEQUE_DYNAMICTYPE_H


class DynamicType {
public:
    int *pct;
    double *data;

    DynamicType(int *p);

    DynamicType(const DynamicType &other);

    DynamicType &operator=(const DynamicType &other);

    ~DynamicType();

    bool operator==(const DynamicType &rhs) const;
};

#endif //DEQUE_DYNAMICTYPE_H
