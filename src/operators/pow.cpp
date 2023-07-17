#include "pow.hpp"


Pow::Pow(AutoDiffNode* node1, AutoDiffNode* node2) {
	this->inputs = {node1, node2};
}

data_type Pow::forward() {
    data_type input1 = this->inputs[0]->val;
    data_type input2 = this->inputs[1]->val;
    try {
        double a = std::get<double>(input1);
        double b = std::get<double>(input2);
	    return std::pow(a, b);
    } catch (std::exception& e) {
        std::cout << "Power only supports double right now" << std::endl;
    }
    return 0.;
};


std::pair<data_type, data_type> Pow::backward(double d_out) {
    data_type input1 = this->inputs[0]->val;
    data_type input2 = this->inputs[1]->val;
    try {
        double a = std::get<double>(input1);
        double b = std::get<double>(input2);
	    return {d_out * b * std::pow(a, b-1), d_out * std::pow(a, b) * std::log(a)};
    } catch (std::exception& e) {
        std::cout << "Power only supports double right now" << std::endl;
    }
    return {0., 0.};
}