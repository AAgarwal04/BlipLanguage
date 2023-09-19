#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "parse.h"
#include "node.cpp"

class Util{
public:
    static int h(const char* val){             //By placing h function in class, can use h function in other places
        int total = 0;
        while(*val){
            total += *val;
            val++;
        }
        return total;
    }    
};

class HT {
private:
    int n;
    Node **buckets;

public:
    HT(int pn):n(pn){
       buckets = new Node*[n];          //new Type[n]
        for(int i = 0; i < n; i++){
            buckets[i] = nullptr;
        }
    }

    ~HT(){
        for(int i = 0; i < n; i++){
            Node *head = buckets[i];

            Node *prev = nullptr;
            while(head != nullptr){
                prev = head;
                head = head->getPost();
                delete prev;
            }
        }
        delete [] buckets;
    }

    int getVal(const char* val){
        int ix = Util::h(val) %n;
        Node *head = buckets[ix];
        while(head != nullptr){
            if(Node::compString(head->getVal(), val)){
                return head->getValInt();
            }
            head = head->getPost();
        }
        return NULL;
    }

    Node* getNode(const char* val){
        int ix = Util::h(val) %n;
        Node *head = buckets[ix];
        while(head != nullptr){
            if(Node::compString(head->getVal(), val)){
                return head;
            }
            head = head->getPost();
        }
        return NULL;
    }

    void insert(char* val, int amnt){
        int ix = Util::h(val) % n;
        Node *n = new Node(val, amnt, buckets[ix]);
        buckets[ix] = n;
    }

    static Node makeNode(Node &pre, HT &tab){
        read_next_token();
        if(next_token_type == NUMBER){
            int val = token_number_value;
            Node* num = new Node(val);
            num->setPre(pre);
            return *num;
        } else if(next_token_type == SYMBOL){
            const char* next = next_token();
            if(Node::compString(next, "//")){
                skip_line();
                read_next_token();
                next = next_token();
            }
            char* val = Node::strcpy(next);
            Node* op = new Node (val);
            op->setPre(pre);
            return *op;
        } else{
            const char* variable = next_token();
            int num = tab.getVal(variable);
            Node* var = new Node(num);
            var->setPre(pre);
            return *var;
        }
    }

};