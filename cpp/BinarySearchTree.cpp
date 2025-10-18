#include <iostream>

using std::string, std::cout, std::endl;

struct Node {
    int key;
    int ;
    string name;
    
    Node *left = nullptr;
    Node *rigth = nullptr;

    // Altura dos nos

    Node(int k, string n): key(k), name(n) {};
    
    bool is_leaf() {
        return left == nullptr && rigth == nullptr;
    };

    void print() {
        cout << "N: " << "Key: " << key << " Name: " << name << endl;

        if (left != nullptr) {
            cout << "L: " << "Key: " << left->key << " Name: " << left->name << endl;
        } else {
            cout << "L: " << "Key: " << "Null" << " Name: " << "Null" << endl;
        }

        if (rigth != nullptr) {
            cout << "R: " << "Key: " << rigth->key << " Name: " << rigth->name << endl;
        } else {
            cout << "R: " << "Key: " << "Null" << " Name: " << "Null" << endl;
        }
    }
};

class BinaryTree {

public:
    
    Node *root;

    
    BinaryTree() {
        root = nullptr;
    }


    void add(int key, string name) {

        if (root == nullptr || key == root->key) {
            root = new Node(key, name);
            return;
        }

        add_rec(key, name, root);

    }

    
    string find (int key) {
        if (key == root->key) return root->name;
        return find_rec(key, root)->name;
    }
    

    void show_order() {
        show_order_rec(root);
    }

    void remove(int key) {
        // Para remover são 3 casos
        // Quando for uma folha, quando tiver um filho ou quando tiver 2 filhos
        // Quando tiver dois filhos precisamos encontrar o menor da direita OU o maior da esquerda para não perder.
        // Para escolher precisamos verificar a profundidade da arvore    
    }

    Node *return_parent(int key) {
        if (root == nullptr || root->key == key) {
            return nullptr;
        } 

        return return_parent_rec(key, root);
    }

    Node *get_less(Node *pos = nullptr) {
        if (pos == nullptr) pos = root;
        return get_less_parent_rec(pos);
    }

private:

    void add_rec(int key, string name, Node *pos) {
        
        // Quando as chaves forem iguais só atualiza o valor.
        if (pos->key == key) {
            pos->name = name;
            return;
        }

        // Verificar o caminho para ir.
        // Aqui para a direita com key menor que a key da posição.
        if (key < pos->key) {
            
            if (pos->left == nullptr) {
                cout << "L" << endl;
                pos->left = new Node(key, name);
                return;
            }
            
            add_rec(key, name, pos->left);
        }
    
        // Aqui para verificar com key maior que key da posição.
        if (key > pos->key) {
            
            cout << "R" << endl;
            if (pos->rigth == nullptr) {
                pos->rigth = new Node(key, name);           
                return;
            }

            add_rec(key, name, pos->rigth);
        }

        cout << "Desempilhando" << endl;

    }


    Node *find_rec(int key, Node *pos) {

        if (pos == nullptr) return nullptr;
        if (pos->key == key) return pos; 

        if (key < pos->key) {
            return find_rec(key, pos->left);            
        }

        if (key > pos->key) {
            return find_rec(key, pos->rigth);
        }

        return nullptr;
    
    }
    

    void show_order_rec(Node *pos) {

        if(pos == nullptr) return; 
        cout << "Key: " << pos->key << " Nome: " << pos->name << endl;
        show_order_rec(pos->left);
        show_order_rec(pos->rigth);
    
    }

    void remove_rec(int key, Node *pos) {
        // Até achar o nó

        if (key < pos->key) remove_rec(key, pos->left);
        if (key > pos->key) remove_rec(key, pos->rigth);
        
        if (key == pos->key) {
            
            // Caso 1 Quando for folha (quando não tiver filhos)
            if (pos->is_leaf()) {

            }
        }
    }

    Node *return_parent_rec(int key, Node *pos) {

        // Quando pos for nullptr ou quando for igual a chave [Porque não tem parentes].
        if (pos == nullptr || pos->key == key) {
            return nullptr;
        }

        // Para pegar o nodo quando o filho está à esquerda.
        if (pos->left != nullptr && pos->left->key == key) {
            return pos;
        }

        // Para pegar o nodo quando o filho está à direita.
        if (pos->rigth != nullptr && pos->rigth->key == key) {
            return pos;
        }

        // Chamada recursiva.
        if (key < pos->key) {
            return return_parent_rec(key, pos->left);
        } else if (key > pos->key) {
            return return_parent_rec(key, pos->rigth);
        }

        return nullptr;
    }


    Node *get_less_parent_rec(Node *pos) {

        if (pos->left != nullptr) {
            return get_less_parent_rec(pos->left);
        } 

        return pos;
    }


};



int main() {
    BinaryTree bn = BinaryTree();
    bn.add(5, "5");
    bn.add(10, "10");
    // bn.add(30, "30");
    // bn.add(3, "3");
    // bn.add(25, "25");
    // bn.add(4, "4");

    // bn.remove(5);

    // bn.root->print();

    return 0;
}
