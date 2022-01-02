#include <iostream>
#include <memory>
#include <functional>

namespace my_std {
    template<typename T>
    class forward_list {
    private:
        struct Node;
    public:
        using SplitPredicate = std::function<bool(const T& value)>;
        forward_list() {}
        forward_list(std::initializer_list<T> init) {
            for (const auto& i : init) {
                push_back(i);
            }
        }
        forward_list(forward_list&& obj) : head_(std::move(obj.head_)), tail_(std::move(obj.tail_)), size_(std::move(obj.size_)) {}
        forward_list& operator=(const forward_list& obj) {
            if (&obj == this)
                return *this;

            head_ = obj.head_;
            size_ = obj.size_;
        }
        class iterator {
        public:
            friend forward_list;
            iterator(std::shared_ptr<Node> node) {
                node_ = node;
            }
            iterator& operator++() {
                node_ = node_->next;
                return *this;
            }
            T operator*() {
                return node_->data;
            }
            friend bool operator==(const iterator& left, const iterator& right) {
                return left.node_ == right.node_;
            }
            friend bool operator!=(const iterator& left, const iterator& right) {
                return !(left == right);
            }
        private:
            std::shared_ptr<Node> node_;
        };
        void push_front(const T& value) {
            std::shared_ptr<Node> tmp_node = std::make_shared<Node>();
            tmp_node->data = value;
            push_front(tmp_node);
        }
        void push_front(T&& value) {
            std::shared_ptr<Node> tmp_node = std::make_shared<Node>();
            tmp_node->data = std::move(value);
            push_front(tmp_node);
        }
        void push_back(const T& value) {
            std::shared_ptr<Node> tmp_node = std::make_shared<Node>();

            tmp_node->data = value;
            tmp_node->next = nullptr;

            if (empty()) {
                tail_ = tmp_node;
                head_ = tmp_node;
            }
            else {
                tail_->next = tmp_node;
                tail_ = tmp_node;
            }
            size_++;
        }
        int size() {
            return size_;
        }
        bool empty() {
            return size_ == 0;
        }
        void pop_front() {
            if (empty()) return;
            head_ = std::move(head_->next);
            size_--;
        }
        void remove(const T& value) {
            if (empty()) return;

            std::shared_ptr<Node> tmp_node = head_;

            while (head_ != nullptr && head_->data == value) {
                head_ = head_->next;
                if (size() <= 2) {
                    if (head_ != nullptr) tail_ = head_->next;
                    else tail_ = nullptr;
                }
                size_--;
            }

            while (tmp_node->next != nullptr) {
                if ((tmp_node->next)->data == value) {
                    tmp_node->next = tmp_node->next->next;
                    if (tmp_node->next == nullptr) tail_ = tmp_node;
                    size_--;
                }
                if (tmp_node->next != nullptr) tmp_node = tmp_node->next;
            }
        }
        iterator begin() {
            iterator iter(head_);
            return iter;
        }
        iterator end() {
            iterator iter(nullptr);
            return iter;
        }
        void print() {
            for (auto val: *this) {
                std::cout << val << " ";
            }
        }
        forward_list<T> split_when(SplitPredicate condition){
            my_std::forward_list<T> new_list;
            if (empty()) return new_list;

            int size_old_list = 0;
            iterator prev_iter = end();
            for (auto iter = begin(); iter != end(); ++iter) {
                if (condition(*iter)) {
                    new_list.head_ = iter.node_;
                    new_list.tail_ = tail_;
                    new_list.size_ = size_ - size_old_list;
                    size_ = size_old_list;
                    tail_ = prev_iter.node_;
                    if (size_old_list == 0) {
                        head_ = nullptr;
                    }
                    else {
                        tail_->next = nullptr;
                    }
                    return new_list;
                }
                size_old_list++;
                prev_iter = iter;
            }
            return new_list;
        }
    private:
        struct Node {
            T data;
            std::shared_ptr<Node> next = nullptr;
        };
        void push_front(std::shared_ptr<Node> tmp_node) {
            tmp_node->next = std::move(head_);
            tail_ = std::move(head_);
            head_ = std::move(tmp_node);
            size_++;
        }
        std::shared_ptr<Node> head_ = nullptr;
        std::shared_ptr<Node> tail_ = nullptr;
        int size_ = 0;
    };
}

bool six_nine(const int& a) {
    return a == 69;
}

int main() {
   
    my_std::forward_list <int> a{404, 99, 67, 69, 33, 666};

    my_std::forward_list <int> b = a.split_when(six_nine);
    
    a.print();
    std::cout << std::endl;
    std::cout << a.size();
    std::cout << std::endl;
    b.print();
    std::cout << std::endl;
    std::cout << b.size();
    return 0;
}