#include "mult.hpp"


Mult::Mult(AutoDiffNode* node1, AutoDiffNode* node2) {
	this->inputs = {node1, node2};
}

data_type Mult::forward() {
    data_type input1 = this->inputs[0]->val;
    data_type input2 = this->inputs[1]->val;
    data_type product;
    std::visit(
        overload{
             [&product](double& a, double& b) {
                product = a*b;
            },
            [&product](Eigen::MatrixXd& a, Eigen::MatrixXd& b) {
                product = a*b;
            },
            [&product](Eigen::MatrixXd& a, double& b) {
                product = 0.;
                std::cout << "Error, Mult types don't match!" << std::endl;
            },
            [&product](double& a, Eigen::MatrixXd& b) {
                product = 0.;
                std::cout << "Error, Mult types don't match!" << std::endl;
            }
        },
        input1, input2
    );
	return product;
};


std::pair<data_type, data_type> Mult::backward(double d_out) {

    // Check type of variant
    std::pair<data_type, data_type> outputs;
    data_type input1 = this->inputs[0]->val;
    data_type input2 = this->inputs[1]->val;
    std::visit(
        overload{
             [d_out, &outputs](double& a, double& b) {
                outputs.first = d_out * b;
                outputs.second = d_out * a;
            },
            [d_out, &outputs](Eigen::MatrixXd& a, Eigen::MatrixXd& b) {
                outputs.first = d_out * b.transpose();
                outputs.second = a.transpose() * d_out;
            },
            [d_out, &outputs](Eigen::MatrixXd& a, double& b) {
                outputs.first = 0.;
                outputs.second = 0.;
                std::cout << "Error, Mult types don't match!" << std::endl;
            },
            [d_out, &outputs](double& a, Eigen::MatrixXd& b) {
                outputs.first = 0.;
                outputs.second = 0.;
                std::cout << "Error, Mult types don't match!" << std::endl;
            }
        },
        input1, input2
    );
    return outputs;
}