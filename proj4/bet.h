#ifndef PROJ$_BET_H
#define PROJ4_BET_H

#include <iostream>
#include <string>

template <typename T>
class BET {
  public:
    //constructors
    BET();
    BET(const std::string postfix);
    BET(const BET &);
    ~BET();
    const BET & operator=(const BET &);
    bool buildFromPostfix(const std::string postfix);
    
    // insertion and deletion
    void makeEmpty();
    void insert(const T & data);
    void insert(T && data);
    void remove(const T & data);

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
    void insert(T && data, BinaryNode * &node) {
      if (node == nullptr) {
        node = new BinaryNode(std::move(data));
      } else if (this->node.left == nullptr) {
        insert(data, node->left);
      } else if (this->node.right == nullptr) {
        insert(data, node->right);
      }
    }
    // deletion
    void remove(const T & data, BinaryNode * node) {
      if (node->left == nullptr && node->right == nullptr) {
        
      }
    }
    void printInfixExpression(BinaryNode * n);
    void makeEmpty(BinaryNode * n);
    BinaryNode * clone(BinaryNode) const;
    void printPostfixExpression(BinaryNode * n);
    size_t size(BinaryNode * t);
    size_t leaf_nodes(BinaryNode * t);
};

#include "bet.hpp"

#endif
