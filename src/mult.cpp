#include "mult.hpp"


Mult::Mult() {
	
}

double Mult::forward() {
	std::pair<input, input> inputs = this->get_inputs();
	return std::get<double>(inputs.first) * std::get<double>(inputs.second);
};


std::pair<input, input> Mult::backward(double d_out) {

    // Check type of variant
    std::pair<input, input> outputs;
    std::pair<input, input> inputs = this->get_inputs();
    std::visit(
        overload{
             [d_out, &outputs](double& a, double& b) {
                outputs.first = d_out * b;
                outputs.second = d_out * a;
            },
            [d_out, &outputs](Eigen::MatrixXd& a, Eigen::MatrixXd& b) {
                outputs.first = d_out * b;
                outputs.second = d_out * a;
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

	// double a = std::get<double>(inputs.first);
	// double b = std::get<double>(inputs.second);
	// return {d_out * b, d_out * a};
}