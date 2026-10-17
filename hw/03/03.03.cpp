#include <cassert>
#include <print>

class List {
    private:
        struct Node {
            int value;
            Node* next;
        };

        Node* first_ = nullptr;
        Node* last_ = nullptr;

    public:
        bool empty() {
            return first_ == nullptr;
        }

        void show() {
            for (Node* current = first_; current != nullptr; current = current->next) {
                std::print("{} ", current->value);
            }
            std::print("\n");
        }

        void push_front(int value) {
            Node* node = new Node{value, first_};
            first_ = node;
            if (last_ == nullptr) {
                last_ = node;
            }
        }

        void push_back(int value) {
            Node* node = new Node{value, nullptr};
            if (empty()) {
                first_ = node;
            } else {
                last_->next = node;
            }
            last_ = node;
        }

        void pop_front() {
            if (empty()) {
                return;
            }
            Node* oldFirst = first_;
            first_ = first_->next;
            delete oldFirst;
            if (first_ == nullptr) {
                last_ = nullptr;
            }
        }

        void pop_back() {
            if (empty()) {
                return;
            }
            if (first_ == last_) {
                delete first_;
                first_ = nullptr;
                last_ = nullptr;
                return;
            }

            Node* current = first_;
            while (current->next != last_) {
                current = current->next;
            }
            delete last_;
            last_ = current;
            last_->next = nullptr;
        }

        int get() {
            Node* slow = first_;
            Node* fast = first_;
            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow->value;
        }

        ~List() {
            while (!empty()) {
                pop_front();
            }
        }
};

void testEmptyAndSingleNode() {
    List list;
    assert(list.empty());
    list.pop_front();
    list.pop_back();
    assert(list.empty());

    list.push_front(10);
    assert(!list.empty() && list.get() == 10);
    list.pop_back();
    assert(list.empty());

    list.push_back(20);
    assert(!list.empty() && list.get() == 20);
    list.pop_front();
    assert(list.empty());
}

void testSeveralNodes() {
    List list;
    list.push_back(2);
    list.push_front(1);
    list.push_back(3);
    list.push_back(4);
    assert(list.get() == 3);
    list.show();

    list.pop_front();
    assert(list.get() == 3);
    list.pop_back();
    assert(list.get() == 3);
    list.pop_back();
    assert(list.get() == 2);
    list.pop_front();
    assert(list.empty());

    list.push_back(5);
    assert(list.get() == 5);
}

int main() {
    testEmptyAndSingleNode();
    testSeveralNodes();
}
