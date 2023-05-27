/*
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time. push(x) -- Push element x onto stack. pop() --
 * Removes the element on top of the stack. top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 */

#include <cstdint>
#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    stack<int> inner_;
    int64_t min_elem_;
    stack<int64_t> large_inner_;

  public:
    void push(int x) {
        if (inner_.empty()) {
            min_elem_ = x;
            inner_.push(0);
        } else {
            int64_t diff = int64_t(x) - int64_t(min_elem_);
            if (diff >= INT_MAX || diff <= INT_MIN) {
                inner_.push(INT_MAX);
                large_inner_.push(diff);
            } else {
                inner_.push((int)(x - min_elem_));
            }

            if (x < min_elem_) {
                min_elem_ = x;
            }
        }
    }

    void pop() {
        if (inner_.empty()) {
            return;
        }
        int64_t e = inner_.top();
        if (e == INT_MAX) {
            e = large_inner_.top();
            large_inner_.pop();
        }
        if (e < 0) {
            min_elem_ = min_elem_ - e;
        }
        inner_.pop();
    }

    int top() {
        int64_t e = inner_.top();
        if (e == INT_MAX) {
            e = large_inner_.top();
        }
        if (e > 0) {
            return (int)(e + min_elem_);
        } else {
            return (int)min_elem_;
        }
    }

    int getMin() {
        if (inner_.empty()) {
            return 0;
        }
        return (int)min_elem_;
    }
};

int main() { return 0; }
