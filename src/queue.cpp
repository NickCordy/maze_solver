#include "../inc/queue.h"

void Queue::push_back(Node data) {
    auto node = new Node(data);

    // Check if the queue is empty.
    if (_front == nullptr) {
        // Queue is empty.
        _front = node;
    } else {
        // Queue is not empty.
        _back->_next = node;
    }

    _back = node;
    _size++;
}

Data Queue::peek() const {
    // returns data with an _index of -1 if the queue is empty.
    return _front != nullptr ? _front->_data : Data({-1});
}

size_t Queue::size() const {
    return _size;
}

void Queue::pop_front() {
    // Check if the queue is empty first.
    if (_size == 0) return;

    auto node = _front;
    _front = node->_next;

    // Update _back if the queue is empty.
    if (_front == nullptr) _back = nullptr;

    delete node;
    _size--;
}

std::ostream &operator<<(std::ostream &output, const Queue &queue) {
    auto node = queue._front;

    // Output the data for each node in the queue.
    while (node != nullptr) {
        output << node->_data << " ";
        node = node->_next;
    }

    return output;
}

std::ostream& operator<<(std::ostream& output, const Data& data) {
    // Outputs the index of the data.
    output << data._index << "\n";
    return output;
}