#ifndef MAZE_SOLVER_QUEUE_H
#define MAZE_SOLVER_QUEUE_H

#include <iostream>
#include <utility>

struct Data {
    int _index;
};
std::ostream& operator<<(std::ostream& output, const Data& data);

struct Node {
    Data _data{};
    Node* _next {nullptr};
};

class Queue final {
    Node* _front {nullptr};
    Node* _back {nullptr};
    size_t _size {0};

public:
    // Adds a node of data onto the queue.
    void push_back(Node data);

    // Shows the data of the node at the front of the queue.
    [[nodiscard]] Data peek() const;

    // Returns the size of the queue.
    [[nodiscard]] size_t size() const;

    // Removes the node at the front of the queue.
    void pop_front();

    // displays the contents of the queue.
    friend std::ostream& operator<<(std::ostream& output, const Queue& queue);
};

#endif //MAZE_SOLVER_QUEUE_H