#include "mult.hpp"


Mult::Mult() {
	
}

data_type Mult::forward() {
	std::pair<data_type, data_type> inputs = this->inputs;
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
        inputs.first, inputs.second
    );
	return product;
};


std::pair<data_type, data_type> Mult::backward(double d_out) {

    // Check type of variant
    std::pair<data_type, data_type> outputs;
    std::pair<data_type, data_type> inputs = this->inputs;
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
        inputs.first, inputs.second
    );
    return outputs;
}