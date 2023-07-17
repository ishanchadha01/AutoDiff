#include "variable.hpp"


Variable::Variable() {

};


Variable::Variable(data_type aVal) {
    this->val = aVal;
};


NodeType Variable::get_type() {
    return VARIABLE;
}