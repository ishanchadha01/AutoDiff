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


std::vector<data_type> Mult::backward(data_type d) {

    // Check type of variant
    double d_out = std::get<double>(d);
    std::vector<data_type> outputs;
    data_type input1 = this->inputs[0]->val;
    data_type input2 = this->inputs[1]->val;
    std::visit(
        overload{
            [d_out, &outputs](double& a, double& b) {
                outputs.push_back(d_out * b);
                outputs.push_back(d_out * a);
            },
            [d_out, &outputs](Eigen::MatrixXd& a, Eigen::MatrixXd& b) {
                outputs.push_back(d_out * b.transpose());
                outputs.push_back(a.transpose() * d_out);
            },
            [d_out, &outputs](Eigen::MatrixXd& a, double& b) {
                outputs = {0., 0.};
                std::cout << "Error, Mult types don't match!" << std::endl;
            },
            [d_out, &outputs](double& a, Eigen::MatrixXd& b) {
                outputs = {0., 0.};
                std::cout << "Error, Mult types don't match!" << std::endl;
            }
        },
        input1, input2
    );
    return outputs;
}