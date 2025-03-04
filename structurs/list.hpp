#include <memory>

template <class T>
struct Node {
public:
    Node(const T& data) : data_(data), next_(nullptr) {}

    T data_;
    std::unique_ptr<Node<T>> next_;
};

template <class T>
class ForwardList {
public:
    ForwardList() : size_(0), head_(nullptr) {}

    void push_front(const T& data);
    T front();
    // // void insert(int pos, T &data);
    void print();

private:
    std::unique_ptr<Node<T>> head_;
    int size_ {0};
};

template <class T>
void ForwardList<T>::push_front(const T& data) {
    this->size_++;
    auto new_head = std::make_unique<Node<T>>(data);
    new_head->next_ = std::move(this->head_);
    this->head_ = std::move(new_head);
}

template <class T>
T ForwardList<T>::front() {
    return head_->data_;
}

template <class T>
void ForwardList<T>::print() {
    Node<T> *node = this->head_.get();
    while(node) {
        std::cout << node->data_ << " ";
        node = node->next_.get();
    }
}
