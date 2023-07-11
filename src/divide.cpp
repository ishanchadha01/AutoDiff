#include "divide.hpp"


Divide::Divide() {
  
};


input Divide::forward() {
	std::pair<input, input> inputs = this->get_inputs();
	return std::get<double>(inputs.first) / std::get<double>(inputs.second);
};


std::pair<input, input> Divide::backward(double d_out) {
	std::pair<input, input> inputs = this->get_inputs();
	double a = std::get<double>(inputs.first);
	double b = std::get<double>(inputs.second);
	return {d_out / b, -1 * d_out * std::pow(b, 2) * a};
}