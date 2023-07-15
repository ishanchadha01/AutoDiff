#include "divide.hpp"


Divide::Divide() {
  
};


data_type Divide::forward() {
	std::pair<data_type, data_type> inputs = this->inputs;
	return std::get<double>(inputs.first) / std::get<double>(inputs.second);
};


std::pair<data_type, data_type> Divide::backward(double d_out) {
	std::pair<data_type, data_type> inputs = this->inputs;
	double a = std::get<double>(inputs.first);
	double b = std::get<double>(inputs.second);
	return {d_out / b, -1 * d_out * std::pow(b, 2) * a};
}