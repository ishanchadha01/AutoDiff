#include "pow.hpp"


Pow::Pow() {
	
}

data_type Pow::forward() {
	std::pair<data_type, data_type> inputs = this->inputs;
	return std::pow(std::get<double>(inputs.first), std::get<double>(inputs.second));
};


std::pair<data_type, data_type> Pow::backward(double d_out) {
	std::pair<data_type, data_type> inputs = this->inputs;
	double a = std::get<double>(inputs.first);
	double b = std::get<double>(inputs.second);
	return {d_out * b * std::pow(a, b-1), d_out * std::pow(a, b) * std::log(a)};
}