#include "mult.hpp"


Mult::Mult() {
	
}

double Mult::forward() {
	std::pair<input, input> inputs = this->get_inputs();
	return std::get<double>(inputs.first) * std::get<double>(inputs.second);
};


std::pair<input, input> Mult::backward(double d_out) {
	std::pair<input, input> inputs = this->get_inputs();
	double a = std::get<double>(inputs.first);
	double b = std::get<double>(inputs.second);
	return {d_out * b, d_out * a};
}