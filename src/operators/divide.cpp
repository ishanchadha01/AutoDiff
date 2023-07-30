#include "divide.hpp"
#include <iostream>


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
        std::cout << "Error, ivision only supports double right now!" << std::endl;
    }
	return 0.;
};


std::vector<data_type> Divide::backward(data_type d) {

    // Check type of variant
    double d_out = std::get<double>(d);
    std::vector<data_type> outputs;
    data_type input1 = this->inputs[0]->val;
    data_type input2 = this->inputs[1]->val;
    std::visit(
        overload{
            [d_out, &outputs](double& a, double& b) {
                outputs.push_back(d_out/b);
                outputs.push_back(-1.0 * d_out * std::pow(b, 2) * a);
            },
            [d_out, &outputs](Eigen::MatrixXd& a, Eigen::MatrixXd& b) {
                outputs = {0., 0.};
                std::cout << "Error, division only supports double right now!" << std::endl;
            },
            [d_out, &outputs](Eigen::MatrixXd& a, double& b) {
                outputs = {0., 0.};
                std::cout << "Error, division only supports double right now!" << std::endl;
            },
            [d_out, &outputs](double& a, Eigen::MatrixXd& b) {
                outputs = {0., 0.};
                std::cout << "Error, division only supports double right now!" << std::endl;
            }
        },
        input1, input2
    );
    return outputs;
}