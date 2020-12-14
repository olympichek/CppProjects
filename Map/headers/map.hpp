#ifndef MY_MAP
#define MY_MAP

#include <string>
#include <sstream>

namespace my {
    template<typename key_type, typename value_type>
    class map {

    private:

        typedef std::pair<key_type, value_type> pair_type;

        struct map_tree {
            pair_type root;
            map_tree* left;
            map_tree* right;

            map_tree(key_type key, value_type value):
            root({key, value}), left(nullptr), right(nullptr) {}

            explicit map_tree(const pair_type &pair):
            root(pair), left(nullptr), right(nullptr) {}

            ~map_tree() {
                delete left;
                delete right;
            };
        };

        map_tree* tree;
        std::size_t length;

    public:
        map(): tree(nullptr), length(0) {}

        map(std::initializer_list<pair_type> init):
        tree(nullptr), length(0) {
            for(auto &pair : init)
                insert(pair);
        }

        ~map() {
            delete tree;
        }

        std::size_t size() {
            return length;
        }

        value_type& at(key_type key, map_tree* current_tree) {
            std::string error = "There is no element with this key...";
            if(current_tree == nullptr)
                throw std::out_of_range(error);
            if(key == current_tree->root.first)
                return current_tree->root.second;
            if(key > current_tree->root.first)
                return at(key, current_tree->right);
            if(key < current_tree->root.first)
                return at(key, current_tree->left);
            throw std::out_of_range(error);
        }

        value_type& at(key_type key) {
            return at(key, tree);
        }

        void insert(const pair_type &pair, map_tree* &current_tree) {
            if(current_tree == nullptr) {
                current_tree = new map_tree(pair);
                return;
            }
            if(pair.first > current_tree->root.first) {
                insert(pair, current_tree->right);
                return;
            }
            if(pair.first < current_tree->root.first) {
                insert(pair, current_tree->left);
                return;
            }
        }

        void insert(const pair_type &pair) {
            insert(pair, tree);
            length++;
        }

//        value_type& operator[](const key_type &key) {
//            try {
//                return at(key);
//            }
//            catch(std::out_of_range &e) {
//                insert({key, });
//            }
//        }

    };
}

#endif //MY_MAP