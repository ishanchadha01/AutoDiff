#include "pow.hpp"


Pow::Pow() {
	
}

input Pow::forward() {
	std::pair<input, input> inputs = this->get_inputs();
	return std::pow(std::get<double>(inputs.first), std::get<double>(inputs.second));
};


std::pair<input, input> Pow::backward(double d_out) {
	std::pair<input, input> inputs = this->get_inputs();
	double a = std::get<double>(inputs.first);
	double b = std::get<double>(inputs.second);
	return {d_out * b * std::pow(a, b-1), d_out * std::pow(a, b) * std::log(a)};
}