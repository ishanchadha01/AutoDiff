#include "variable.hpp"


Variable::Variable() {
    this->val = 0.;
    this->is_placeholder = false;
};


Variable::Variable(data_type aVal) {
    this->val = aVal;
    std::cout << std::get<double>(aVal) << std::endl;
};


NodeType Variable::get_type() {
    return VARIABLE;
}