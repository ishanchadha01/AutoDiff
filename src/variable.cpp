#include "variable.hpp"


Variable::Variable() {
    this->val = 0.;
    this->is_placeholder = false;
};


NodeType Variable::get_type() {
    return VARIABLE;
}