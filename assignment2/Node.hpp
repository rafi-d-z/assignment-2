//
// Created by csar on 7/2/22.
//

#ifndef ASSIGNMENT_2_NODE_H
#define ASSIGNMENT_2_NODE_H

#include <variant>

namespace assignment2 {

    struct Node {
        std::variant<char, int> data;
        Node *next;
    };
}
#endif // ASSIGNMENT_2_NODE_H
