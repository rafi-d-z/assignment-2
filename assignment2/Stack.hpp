//
// Created by csar on 7/2/22.
//

#ifndef ASSIGNMENT_2_LINKEDLIST_HPP
#define ASSIGNMENT_2_LINKEDLIST_HPP

#include "Node.hpp"

namespace assignment2 {
    class Stack {
    private:
        Node* head;

    public:
        void push(Node* node);
        Node* pop();
    };
}
#endif //ASSIGNMENT_2_LINKEDLIST_HPP
