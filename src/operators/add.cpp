#include "add.hpp"


Add::Add(AutoDiffNode* node1, AutoDiffNode* node2) {
	this->inputs = {node1, node2};
}


data_type Add::forward() {
    data_type input1 = this->inputs[0]->val;
    data_type input2 = this->inputs[1]->val;
	return std::get<double>(input1) + std::get<double>(input2);
};


std::vector<data_type> Add::backward(data_type d_out) {
	return {d_out, d_out};
}