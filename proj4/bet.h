#ifndef PROJ$_BET_H
#define PROJ4_BET_H

#include <cctype>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

template <typename T>
class BET {
  public:
    //constructors
    BET() : root{nullptr} {}
    BET(const std::string postfix) {
      std::stack<BinaryNode * > tokenStack;
      std::vector<char> tokens;
      BinaryNode * newNode;
      BinaryNode * operand1;
      BinaryNode * operand2;
      // get cstring version of postfix
      char * cpostfix = new char [postfix.length() + 1];
      std::strcpy(cpostfix, postfix.c_str());
      char * ch = strtok(cpostfix, ' ');
      // tokenize postfix
      while (ch != nullptr) {
        ch = strtok(nullptr, ' '); 
        tokens.push_back(*ch);
      }
      // build expression tree
      for (auto itr = tokens.begin(); itr != tokens.end(); itr++) {
        // if token is an operand
        if (std::isalnum(*itr)) {
          newNode = new BinaryNode(*itr);
          tokenStack.push(newNode);
        // if token is an operator
        } else if (!std::isspace(*itr)) {
          operand1 = tokenStack.top();
          tokenStack.pop();
          operand2 = tokenStack.top();
          tokenStack.pop();
          newNode = new BinaryNode(*itr, operand1, operand2);
          tokenStack.push(newNode);
        }
      }
      root = tokenStack.top();
    }
    BET(const BET & bet) { clone(bet.root); }
    ~BET() { makeEmpty(root); }
    const BET & operator=(const BET & bet) { 
      BET newBet(bet);
      return newBet;
    }
    bool buildFromPostfix(const std::string postfix);
    void makeEmpty() { makeEmpty(root); }
    void insert(const T & data) { insert(data, root); };
    void insert(T && data) { insert(std::move(data), root); };

    // getters
    size_t size();
    size_t leaf_nodes();
    bool empty();
 
    // print functions
    void printInfixExpression();
    void printPostfixExpression();

  private:
    // BinaryNode
    struct BinaryNode {
      // BinaryNode member data
      T data;
      BinaryNode * left ;
      BinaryNode * right;
      
      // BinaryNode constructors
      BinaryNode(const T & data,
          BinaryNode * left = nullptr,
          BinaryNode * right = nullptr)
          : data{data},
            left{left},
            right{right} {}
      BinaryNode(const T && data,
          BinaryNode * left = nullptr,
          BinaryNode * right = nullptr)
          : data{std::move(data)},
            left{left},
            right{right} {}
    };
   
    // member data 
    BinaryNode * root;
   
    // private functions
    // insertions
    void insert(const T & data, BinaryNode * & node) {
      if (node == nullptr) {
        node = new BinaryNode(data);
      } else if (this->node.left == nullptr) {
        insert(data, node->left);
      } else if (this->node.right == nullptr) {
        insert(data, node->right);
      }
    }
    void insert(T && data, BinaryNode * & node) {
      if (node == nullptr) {
        node = new BinaryNode(std::move(data));
      } else if (this->node.left == nullptr) {
        insert(std::move(data), node->left);
      } else if (this->node.right == nullptr) {
        insert(std::move(data), node->right);
      }
    }
    void printInfixExpression(BinaryNode * node);
    // lazy deletion
    void makeEmpty(BinaryNode * & node) {
      if (node != nullptr) {
        makeEmpty(node->left);
        makeEmpty(node->right);
        delete node;
      }
      node = nullptr;
    }
    BinaryNode * clone(BinaryNode * node) const {
      if (node == nullptr) {
        return nullptr;
      } else {
        return new BinaryNode(node->data, clone(node->left), clone(node->right));
      }
    };
    void printPostfixExpression(BinaryNode * n);
    size_t size(BinaryNode * t);
    size_t leaf_nodes(BinaryNode * t);
};

#include "bet.hpp"

#endif
