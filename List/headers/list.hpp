#ifndef MY_LIST
#define MY_LIST

#include <string>
#include <sstream>

namespace my {
    template<typename type>
    class list {

    private:
        struct list_node {
            type value;
            list_node* next;
            list_node* prev;
            explicit list_node(const type &value):
            value(value), next(nullptr), prev(nullptr) {};
            ~list_node() {
                delete next;
            };
        };

        std::size_t length;
        list_node* first;
        list_node* last;

    public:
        list():
        first(nullptr), last(nullptr), length(0) {}

        list(std::initializer_list<type> init):
        first(nullptr), last(nullptr), length(0) {
            for(auto &it : init)
                push_back(it);
        }

        ~list() {
            delete first;
        }

        std::size_t size() const {
            return length;
        }

        bool empty() const {
            return length == 0;
        }

        void push_back(const type &value) {
            auto* node = new list_node(value);
            if(first == nullptr) {
                first = node;
            }
            else if(last == nullptr) {
                first->next = node;
                last = node;
                last->prev = first;
            }
            else {
                last->next = node;
                node->prev = last;
                last = node;
            }
            length++;
        }

        void push_top(const type &value) {
            auto* node = new list_node(value);
            if(first == nullptr) {
                first = node;
            }
            else if(last == nullptr) {
                last = first;
                first = node;
                first->next = last;
                last->prev = first;
            }
            else {
                first->prev = node;
                node->next = first;
                first = node;
            }
            length++;
        }

        void pop_back() {
            if(first != nullptr) {
                if(last == nullptr) {
                    delete first;
                }
                else {
                    list_node* node = last;
                    last = last->prev;
                    last->next = nullptr;
                    node->prev = nullptr;
                    delete node;
                }
                length--;
            }
        }

        void pop_top() {
            if(first != nullptr) {
                if(last == nullptr) {
                    delete first;
                }
                else {
                    list_node* node = first;
                    first = first->next;
                    first->prev = nullptr;
                    node->next = nullptr;
                    delete node;
                }
                length--;
            }
        }

        std::string to_string() const {
            std::stringstream ss;
            list_node* node = first;
            ss << "{";
            while (node != nullptr) {
                ss << node->value;
                if(node != last && last != nullptr)
                    ss << ", ";
                node = node->next;
            }
            ss << "}";
            return ss.str();
        }

        class iterator {
        private:
            list_node* node;
        public:
            explicit iterator(list_node* node): node(node) {}
            iterator& operator++() {
                node = node->next;
                return *this;
            }
            iterator& operator--() {
                node = node->prev;
                return *this;
            }
            bool operator==(iterator other) const {
                return node == other.node;
            }
            bool operator!=(iterator other) const {
                return node != other.node;
            }
            type& operator*() const {
                return node->value;
            }
        };

        iterator begin() {
            return iterator(first);
        }

        iterator end() {
            return iterator(last->next);
        }

        class reverse_iterator {
        private:
            list_node* node;
        public:
            explicit reverse_iterator(list_node* node): node(node) {}
            void operator++() {
                node = node->prev;
            }
            void operator--() {
                node = node->next;
            }
            bool operator==(reverse_iterator other) const {
                return node == other.node;
            }
            bool operator!=(reverse_iterator other) const {
                return node != other.node;
            }
            type& operator*() const {
                return node->value;
            }
        };

        reverse_iterator rbegin() {
            return reverse_iterator(last);
        }

        reverse_iterator rend() {
            return reverse_iterator(first->prev);
        }
    };
}

#endif//MY_LIST
