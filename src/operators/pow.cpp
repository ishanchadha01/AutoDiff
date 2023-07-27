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


std::vector<data_type> Pow::backward(data_type d) {

    // Check type of variant
    double d_out = std::get<double>(d);
    std::vector<data_type> outputs;
    data_type input1 = this->inputs[0]->val;
    data_type input2 = this->inputs[1]->val;
    std::visit(
        overload{
            [d_out, &outputs](double& a, double& b) {
                outputs[0] = d_out * b * std::pow(a, b-1);
                outputs[1] = d_out * std::pow(a, b) * std::log(a);
            },
            [d_out, &outputs](Eigen::MatrixXd& a, Eigen::MatrixXd& b) {
                outputs[0] = 0.;
                outputs[1] = 0.;
                std::cout << "Error, Pow only supports doubles right now!" << std::endl;
            },
            [d_out, &outputs](Eigen::MatrixXd& a, double& b) {
                outputs[0] = 0.;
                outputs[1] = 0.;
                std::cout << "Error, Pow only supports doubles right now!" << std::endl;
            },
            [d_out, &outputs](double& a, Eigen::MatrixXd& b) {
                outputs[0] = 0.;
                outputs[1] = 0.;
                std::cout << "Error, Mult types don't match!" << std::endl;
            }
        },
        input1, input2
    );
    return outputs;
}