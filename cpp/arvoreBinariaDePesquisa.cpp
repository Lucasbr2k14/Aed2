#include <iostream>

using std::string;


template<typename K, typename D>
struct Node {
    K key;
    D data;
    int level;
    Node* left;
    Node* rigth;

    Node(K key, D data, int level): key(key), data(data), level(level), left(nullptr), rigth(nullptr) {};
    
    void update(Node<K,D> *node) {
        key = node->key;
        data = node->data;
        level = node->level;
        left = node->left; 
        rigth = node->rigth;
    }

    bool leaf() {
        return left == nullptr && rigth == nullptr;
    }
};

template<typename K, typename D>
class BinaryTree {
public:
    Node<K,D> *root;

    BinaryTree() {
        root = nullptr;
        size = 0;
    }

    ~BinaryTree() {
    
    }

    void add(K key, D data) {
        if (root == nullptr) {
            root = new Node<K, D>(key, data, 0);
            size += 1;
            return;
        }
        add_rec(key, data, root, root->level + 1);
    }

    Node<K,D> *search(K key) {
        if (root != nullptr)
            return search_rec(key, root);
        return nullptr;
    }

    void remove(K key) {
        if (root == nullptr) return;
        
        if (key == root->key) {
            // Remove quando o nodo for folha 
            if (root->leaf()) { 
                delete root;
                root = nullptr;
                return;
            }

            // Remover quando o nodo tiver um filho só
            if ((root->left != nullptr && root->rigth == nullptr) || (root->rigth != nullptr && root->left == nullptr)) {
            
                // Verificar se o filho é a esquerda
                if (root->left != nullptr) {
                    Node<K,D> *left_node = root->left;
                    root->update(left_node);
                    delete left_node;
                }

                // Verificar se o filho é a direita
                if (root->rigth != nullptr) {
                    Node<K,D> *rigth_node = root->rigth;
                    root->update(rigth_node);
                    delete rigth_node;
                }
            
            }

            return;
        }

        remove_rec(key, root);
        
    }

    void print() {
        print_preorder(root);
        std::cout << "#" << std::endl;
    }

private:
    int size;

    void add_rec(K key, D data, Node<K,D> *pos, int level) {
        
        if (key < pos->key) {
            if (pos->left == nullptr) {
                pos->left = new Node<K,D>(key, data, level);
                size += 1;
                return;
            }
            add_rec(key, data, pos->left, level+1);
        } 

        if (key > pos->key) {
            if (pos->rigth == nullptr) {
                pos->rigth = new Node<K,D>(key, data, level);
                size += 1;
                return;
            }
            add_rec(key, data, pos->rigth, level+1);
        }

        if (key == pos->key) {
            pos->data = data;
        }
    }

    void remove_rec(K key, Node<K,D> *pos) {
        
        if (pos == nullptr) return;
        
        // Verificar se algum dos nos é o filho a se removido
        if ((pos->left != nullptr && pos->left->key == key) || (pos->rigth != nullptr && pos->rigth->key == key)) {

            if (pos->left != nullptr && pos->left->key == key) {
                
                // Caso nodo folha
                if (pos->left->leaf()) {
                    delete pos->left;
                    pos->left = nullptr;
                    return;
                }

                // Caso um filho
                if ((pos->left->left != nullptr && pos->left->rigth == nullptr) || (pos->left->rigth != nullptr && pos->left->left == nullptr)) {
                    
                    if (pos->left->left != nullptr) {
                        Node<K,D> *left_node = pos->left->left;
                        pos->left->update(pos->left->left);
                        delete left_node;
                    }
                    
                    if (pos->left->rigth != nullptr) {
                        Node<K,D> *rigth_node = pos->left->rigth;
                        pos->left->update(pos->left->rigth);
                        delete rigth_node;
                    }
                
                }
            
            }

            if (pos->rigth != nullptr && pos->rigth->key == key) {
                
                // Caso nodo folha
                if (pos->rigth->leaf()) {
                    delete pos->rigth;
                    pos->rigth = nullptr;
                    return;
                }
        
                // Caso um filho
                if ((pos->rigth->left != nullptr && pos->rigth->rigth == nullptr) || (pos->rigth->rigth != nullptr && pos->rigth->left == nullptr)) {
                    
                    if (pos->rigth->left != nullptr) {
                        Node<K,D> *left_node = pos->rigth->left;
                        pos->rigth->update(left_node);
                        delete left_node;
                    }

                    if (pos->rigth->rigth != nullptr) {
                        Node<K,D> *rigth_node = pos->rigth->rigth;
                        pos->rigth->update(rigth_node);
                        delete rigth_node;
                    }

                }
                
            }
        
        }

        if (key < pos->key) {
            remove_rec(key, pos->left);
        }

        if (key > pos->key) {
            remove_rec(key, pos->rigth);
        }

    } 

    Node<K,D> *search_rec(K key, Node<K,D> *pos) {
        if (pos == nullptr) return nullptr;

        if (key == pos->key) return pos;
        if (key < pos->key) 
            return search_rec(key, pos->left);
        if(key > pos->key)
            return search_rec(key, pos->rigth);
        
        return nullptr;
    }

    void print_preorder(Node<K,D> *pos) {
        if (pos == nullptr) return;
        std::cout << pos->key << "->";
        print_preorder(pos->left);
        print_preorder(pos->rigth);
    }

};

int main() {
    BinaryTree<int, string> bn;

    bn.add(100, "Lucas");
    bn.add(50, "Angelo");
    bn.add(75, "joão");
    bn.add(200, "Cristiane");
    bn.add(300, "Chiquinha");
    bn.print();
    bn.remove(75);
    bn.print();
    

    return 0;
}