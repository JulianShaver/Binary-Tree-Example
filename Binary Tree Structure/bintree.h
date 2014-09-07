// a Rational object holds one Rational number, one fraction  // Carol Zander

#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include "nodedata.h"
#include <algorithm>
using namespace std;

//---------------------------------------------------------------------------
//   
//  
//    
//    
//
// Assumptions:
//   -- Rationals are stored as integer numerators and denominators
//   -- if the rational number is negative, the numerator is the negative
//   -- all stored rationals are reduced to lowest terms
//   -- all arithmetic operators return Rationals reduced to lowest terms
//---------------------------------------------------------------------------
class BinTree {               // you add class/method comments and assumptions  
	friend ostream& operator<<(ostream&, const BinTree&);
public: 
   BinTree();                                // constructor 
   BinTree(const BinTree &);                 // copy constructor 
   ~BinTree();                               // destructor, calls makeEmpty 
   bool isEmpty() const;                     // true if tree is empty, otherwise false 
   void makeEmpty();                         // make the tree empty so isEmpty returns true 
   BinTree& operator=(const BinTree &); 
   bool operator==(const BinTree &) const;   
   bool operator!=(const BinTree &) const;  
   bool insert(NodeData*); 
   bool retrieve( const NodeData&, NodeData*& ) const; 
   void displaySideways() const;             // provided, displays the tree sideways
   int getHeight(const NodeData &) const;
   void bstreeToArray(NodeData* []);
   void arrayToBSTree(NodeData* []); 
	
private: 
   struct Node { 
      NodeData* data;                        // pointer to data object  
      Node* left;                            // left subtree pointer  
      Node* right;                           // right subtree pointer  
   }; 
   Node* root;                               // root of the tree 
   int index;								 // value for array index
   // utility functions 
   void inorderHelper( ... ) const; 
   void sideways(Node*, int) const;          // provided, helper for displaySideways()
   Node* copyHelper( const Node* );	// copy helper function
   void makeEmptyHelper( Node* );  // makeEmpty helper function (recursive)
   bool equalityHelper( const Node*, const Node* ) const; // returns true if a Node is the same
   int heightHelper(const Node* ) const;
   void find(Node*,const NodeData &,Node*&) const;
   void toArrayHelper(const Node*, NodeData* [], int &) const;
   Node* fromArrayHelper(NodeData* [], int, int);
}; 
#endif
