#include "nodedata.h"

//-------------------------- constructors ------------------------------------
NodeData::NodeData() { data = ""; }                         // default

NodeData::~NodeData() { }                         

NodeData::NodeData(const NodeData& nd) { data = nd.data; }  // copy

NodeData::NodeData(const string& s) { data = s; }    // cast string to NodeData

//------------------------- operator= ----------------------------------------
const NodeData& NodeData::operator=(const NodeData& rhs) {
   if (this != &rhs) {
      data = rhs.data;
   }
   return *this;
}

//------------------------- operator==,!= ------------------------------------
bool NodeData::operator==(const NodeData& rhs) const {
   return data == rhs.data;
}

bool NodeData::operator!=(const NodeData& rhs) const {
   return data != rhs.data;
}

//------------------------ operator<,>,<=,>= ---------------------------------
bool NodeData::operator<(const NodeData& rhs) const {
   return data < rhs.data;
}

bool NodeData::operator>(const NodeData& rhs) const {
   return data > rhs.data;
}

bool NodeData::operator<=(const NodeData& rhs) const {
   return data <= rhs.data;
}

bool NodeData::operator>=(const NodeData& rhs) const {
   return data >= rhs.data;
}

//------------------------ getData/setData ------------------------------------
string NodeData::getData() const { return data; }

void NodeData::setData(string s) { data = s; }

//-------------------------- operator<< --------------------------------------
ostream& operator<<(ostream& output, NodeData& nd) {
   output << nd.data;
   return output;
}
