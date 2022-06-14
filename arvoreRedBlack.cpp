#include <iostream>
#include <fstream>
using namespace std;

#define VERMELHO 1
#define PRETO 0

struct Node {
    unsigned int chave;
    Node *pai;
    Node *esquerda;
    Node *direita;
    int cor; // 1 -> Vermelho ou 0 -> Preto
};

typedef Node *NodePtr;

class TreeRedBlack {
private:
    NodePtr T_raiz;
    NodePtr T_nil;

     // Para equilibrar a árvore após a inserção
    void rb_Insert_Fixup(NodePtr z) {
        NodePtr y;
        while (z->pai->cor == VERMELHO) {
            if (z->pai == z->pai->pai->esquerda) {
                y = z->pai->pai->direita;
                if (y->cor == VERMELHO) {
                    z->pai->cor = PRETO;
                    y->cor = PRETO;
                    z->pai->pai->cor = VERMELHO;
                    z = z->pai->pai;
                }
                else {
                    if (z == z->pai->direita) {
                        z = z->pai;
                        left_rotate(z);
                    }
                    z->pai->cor = PRETO;
                    z->pai->pai->cor = VERMELHO;
                    right_rotate(z->pai->pai);
                }
            }
            else {
                y = z->pai->pai->esquerda;
                if (y->cor == VERMELHO) {
                    z->pai->cor = PRETO;
                    y->cor = PRETO;
                    z->pai->pai->cor = VERMELHO;
                    z = z->pai->pai;
                }
                else {
                    if (z == z->pai->esquerda) {
                        z = z->pai;
                        right_rotate(z);
                    }
                    z->pai->cor = PRETO;
                    z->pai->pai->cor = VERMELHO;
                    left_rotate(z->pai->pai);
                }
            }
        }
        T_raiz->cor = PRETO;
    }


    void printHelper(NodePtr T_raiz, std::string indent, bool last) {
        if (T_raiz != T_nil) {
            std::cout << indent;
            if (last) {
                std::cout << "R----";
                indent += "   ";
            }
            else {
                std::cout << "L----";
                indent += "   ";
            }

            std::string scor = T_raiz->cor ? "RED" : "BLACK";
            std::cout << T_raiz->chave << "(" << scor << ")" << std::endl;
            printHelper(T_raiz->esquerda, indent, false);
            printHelper(T_raiz->direita, indent, true);
        }
    }

public:
    TreeRedBlack() {
        T_nil = new Node;
        T_nil->cor = PRETO;
        T_nil->esquerda = nullptr;
        T_nil->direita = nullptr;
        T_raiz = T_nil;
    }

    void left_rotate(NodePtr x) {
        NodePtr y = x->direita; // define y
        x->direita = y->esquerda;   // transforma a subárvore à esquerda de y na subárvore à direita de x
        if (y->esquerda != T_nil)
            y->esquerda->pai = x;

        y->pai = x->pai; // liga o pai de x a y
        if (x->pai == T_nil)
            this->T_raiz = y;
        else if (x == x->pai->esquerda)
            x->pai->esquerda = y;
        else
            x->pai->direita = y;

        y->esquerda = x; // coloca x à esquerda de y
        x->pai = y;
    }

    void right_rotate(NodePtr x) {
        NodePtr y = x->esquerda; // define y
        x->esquerda = y->direita;  // transforma a subárvore à direita de y na subárvore à esquerda de x
        if (y->direita != T_nil)
            y->direita->pai = x;

        y->pai = x->pai; // liga o pai de x a y
        if (x->pai == T_nil)
            this->T_raiz = y;
        else if (x == x->pai->direita)
            x->pai->direita = y;
        else
            x->pai->esquerda = y;

        y->direita = x; // coloca x à esquerda de y
        x->pai = y;
    }

    void rb_Insert(int key) {
        NodePtr z = new Node;
        z->pai = nullptr;
        z->chave = key;

        NodePtr y = T_nil;
        NodePtr x = this->T_raiz;

        while (x != T_nil) {
            y = x;
            if (z->chave < x->chave)
                x = x->esquerda;
            else
                x = x->direita;
        }

        z->pai = y;
        if (y == T_nil)
            T_raiz = z;
        else if (z->chave < y->chave)
            y->esquerda = z;
        else
            y->direita = z;

        z->esquerda = T_nil;
        z->direita = T_nil;
        z->cor = VERMELHO;

        rb_Insert_Fixup(z);
    }

    void prettyPrint() {
        if (T_raiz)
            printHelper(this->T_raiz, "", true);
    }
};

int main(int argc, char *argv[]) {

    TreeRedBlack rbt; // Árvore vazia

    ifstream arq_in;
    arq_in.open(argv[1]);

    string token;
    while (!arq_in.eof()) {
        arq_in >> token;
        rbt.rb_Insert(stoi(token));
    }

    arq_in.close();

    return 0;
}
