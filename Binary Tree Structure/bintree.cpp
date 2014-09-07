#include "bintree.h"

BinTree::BinTree() {
	root = NULL;
}

// copy constructor
BinTree::BinTree( const BinTree& otherTree ) {
	if (this != &otherTree) {
		root = copyHelper( otherTree.root );	// Starts recursively copying Nodes from
												// otherTree, starting with root Node.
	}
}

// copyHelper, recursive helper function for copy constructor
BinTree::Node* BinTree::copyHelper( const Node* otherNode ) {
	Node* tempNode = new Node;  // create a new Node
    NodeData* tempData = new NodeData;	// create a new NodeData to put the data in
    *tempData = *otherNode->data;		// copy over the data
	tempNode->data = tempData;
	if(otherNode->left != NULL){
    tempNode->left = copyHelper(otherNode->left);	// recursively copy left
	} else {
		tempNode->left = NULL;
	}
	if(otherNode->right){
    tempNode->right = copyHelper(otherNode->right); // recursively copy right
	} else {
		tempNode->right = NULL;
	}
    return tempNode; // Returns after child nodes have been linked to newNode.
}

// destructor, simply calls make empty
BinTree::~BinTree() {
	makeEmpty();
}

// returns true if root is NULL
bool BinTree::isEmpty() const {
	return ( root==NULL );
}

void BinTree::makeEmpty(){
 // only delete the tree if it isn't already empty
 if ( !isEmpty() ) {
  makeEmptyHelper( root ); // start deleting from the root, recursively
 }
 root = NULL;
}

void BinTree::makeEmptyHelper( Node* currentNode ) {
 // check that their is something in the data location to delete
 if ( currentNode->left != NULL ) {
  makeEmptyHelper( currentNode->left );
 }
 if ( currentNode->right != NULL ) {
  makeEmptyHelper( currentNode->right );
 }
 delete currentNode->data;
 delete currentNode;
}

// overloaded assignment operator =
BinTree& BinTree::operator=(const BinTree &rhs){
	// check for self-assignment
	if(this != &rhs){
		makeEmpty();
		root = copyHelper( rhs.root );
	}
	return *this;
}

// overloaded equality operator ==
bool BinTree::operator==(const BinTree &otherTree) const {
 // case 1: both trees are empty
 if ( isEmpty() && otherTree.isEmpty() ) {
  return true;
 } else if (isEmpty() || otherTree.isEmpty()){
	 return false;
 } else {
	 return equalityHelper(root,otherTree.root);
 }
}

// equalyHelper function, compares Node data and structure, returns
// false when a descrepency is found
bool BinTree::equalityHelper( const Node* currNode, const Node* currOtherNode ) const {
 // check that the data is the same, and the structure is the same
 if(*currNode->data != *currOtherNode->data) {
	 return false;
 }
 if(currNode->left != NULL && currOtherNode->left != NULL){
	 equalityHelper(currNode->left,currOtherNode->left);
 } else if(currNode->left != NULL || currOtherNode->left != NULL){
	 return false;
 }
 if(currNode->right != NULL && currOtherNode->right != NULL){
	 equalityHelper(currNode->right,currOtherNode->right);
 } else if(currNode->right != NULL || currOtherNode->right != NULL){
	 return false;
 }
 return true;
}

// overloaded inequality operator !=
bool BinTree::operator!=(const BinTree &rhs) const {
	// return opposite of ==
	return !( *this == rhs );
}

// insert
bool BinTree::insert(NodeData* dataptr) {
   Node* ptr = new Node;
   ptr->data = dataptr;
   dataptr = NULL;
   ptr->left = NULL;
   ptr->right = NULL;

   if(isEmpty()) {
      root = ptr;
   }
   else {
      Node* current = root;
	  bool inserted = false;
      while (!inserted) {
		if(*ptr->data == *current->data){
			delete ptr;
			return false;
		} else if (*ptr->data < *current->data) {
            if (current->left == NULL) {
               current->left = ptr;
               inserted = true;
            }
            else
               current = current->left;
         } else {
            if (current->right == NULL) {
               current->right = ptr;
               inserted = true;
            }
            else {
               current = current->right;
				}
			}
		}
	}
	return true;
}

// retrieve
bool BinTree::retrieve( const NodeData& source, NodeData*& target) const {
   if(isEmpty()) {
      return false;
   }
   else {
      Node* current = root;
	  bool found = false;
      while (!found) {
		if(source == *current->data){
			target = current->data;
			found = true;
		} else if (source < *current->data) {
            if (current->left == NULL) {
               return false;
            }
            else
               current = current->left;
         } else {
            if (current->right == NULL) {
               return false;
            }
            else {
               current = current->right;
				}
			}
		}
	}
	return true;
}

int BinTree::getHeight(const NodeData &source) const {
	Node* target = NULL;
	find(root,source,target);
	if(target != NULL){
		return heightHelper(target);
	} else {
		return -1;
	}
}

int BinTree::heightHelper(const Node* target) const{
   if(target == NULL){
        return 0;
   }
   else {
        return max(heightHelper(target->left), heightHelper(target->right)) + 1;
   }
}

void BinTree::find(Node* current, const NodeData &source,Node*& target) const {
	if(*current->data == source){
		target = current;
	}
	if(current->left != NULL){
		find(current->left,source,target);
	}
	if(current->right != NULL){
		find(current->right, source,target);
	}
}

void BinTree::displaySideways( void ) const {
	   sideways(root, 0);
}

void BinTree::sideways(Node* current, int level) const {
   if (current != NULL) {
      level++;
      sideways(current->right, level);
      for(int i = level; i >= 0; i--) {
          cout << "    ";
      }
      cout << *current->data << endl;
      sideways(current->left, level);
   }
}

ostream& operator<<(ostream &output, const BinTree &r) {
		return output;
	}
void BinTree::bstreeToArray(NodeData* bsarray[]){
	index = 0;
	toArrayHelper(root,bsarray,index);
	root = NULL;
}
void BinTree::toArrayHelper(const Node* current,NodeData* bsarray[], int &index) const {
	if(current->left != NULL){
		toArrayHelper(current->left,bsarray, index);
	}
	bsarray[index] = current->data;
	index++;
	if(current->right != NULL){
		toArrayHelper(current->right, bsarray,index);
	}
	delete [] current;
}
void BinTree::arrayToBSTree(NodeData* bsarray[]){
	root = fromArrayHelper(bsarray,0,index-1);
}
BinTree::Node* BinTree::fromArrayHelper(NodeData* bsarray[], int start, int end){
  if (start > end){
	  return NULL;
  }
  int mid = start + (end - start) / 2;
  Node* temp = new Node();
  temp->data = bsarray[mid];
  bsarray[mid] = NULL;
  temp->left = fromArrayHelper(bsarray, start, mid-1);
  temp->right = fromArrayHelper(bsarray, mid+1, end);
  return temp;
}