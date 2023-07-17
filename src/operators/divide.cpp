#include "divide.hpp"


Divide::Divide(AutoDiffNode* node1, AutoDiffNode* node2) {
	this->inputs = {node1, node2};
}


data_type Divide::forward() {
    data_type input1 = this->inputs[0]->val;
    data_type input2 = this->inputs[1]->val;
    try {
        double a = std::get<double>(input1);
        double b = std::get<double>(input2);
        return a/b;
    } catch (std::exception& e) {
        std::cout << "Division only supports double right now" << std::endl;
    }
	return 0.;
};


std::pair<data_type, data_type> Divide::backward(double d_out) {
    data_type input1 = this->inputs[0]->val;
    data_type input2 = this->inputs[1]->val;
    try {
        double a = std::get<double>(input1);
        double b = std::get<double>(input2);
	    return {d_out / b, -1 * d_out * std::pow(b, 2) * a};
    } catch (std::exception& e) {
        std::cout << "Division only supports double right now" << std::endl;
    }
    return {0., 0.};
}