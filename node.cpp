#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "parse.h"

class Node{
private:
    Node* pre;
    Node* post;
    const char* value;
    int valInt;
    bool isNum;
    bool isHead;

public:
    Node(const char* v): value(v), valInt(NULL), pre(nullptr), post(nullptr), isNum(false), isHead(false) {}     //For char type inputs
    Node(int v): value(nullptr), valInt(v), pre(nullptr), post(nullptr), isNum(true), isHead(false) {}             //For int type inputs
    Node(char c): value(nullptr), valInt((int) c), pre(nullptr), post(nullptr), isNum(false), isHead(true) {}
    Node(const char* val, int num, Node *next): value(val), valInt(num), pre(nullptr), post(next), isNum(true), isHead(false) {}
    

    //Getter
    Node* getPre(void){
        return this->pre;
    }

    Node* getPost(void){
        return this->pre;
    }

    const char* getVal(void){
        return this->value;
    }

    int getValInt(void){
        return this->valInt;
    }

    bool getIsNum(void){
        return this->isNum;
    }

    bool getIsHead(void){
        return this->isHead;
    }

    //Setter
    void setPre(Node &pre){
        this->pre = &pre;
    }

    void setIsNum(void){
        this->isNum = true;
    }

    void setIsHead(void){
        this->isHead = true;
    }

    void setIntVal(int val){
        this->valInt = val;
        this->isNum = true;
    }

    static char* strcpy(const char* str){
        int len = 0;
        int i = 0;
        while(str[i] != '\0'){
            len++;
            i++;
        }
        char* word = new char[len];
        for(int i = 0; i < len; i++){
            word[i] = str[i];
        }
        return word;
    }

    static int compString(const char* char1, const char* char2){
        while(*char1 != '\0'){
            if(*char1 != *char2){
                return 0;
            }
            char1++;
            char2++;
        }
        if(*char2 == '\0'){
            return 1;
        }
        return 0;
    }

};