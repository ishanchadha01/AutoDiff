#include "variable.hpp"


Variable::Variable() {
    this->val = 0.;
    this->is_placeholder = false;
};


Variable::Variable(data_type aVal) {
    this->val = aVal;
};


NodeType Variable::get_type() {
    return VARIABLE;
}