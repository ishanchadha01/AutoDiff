#include "add.hpp"


Add::Add() {
	
}


double Add::forward() {
	std::pair<input, input> inputs = this->get_inputs();
	return std::get<double>(inputs.first) + std::get<double>(inputs.second);
};


std::pair<input, input> Add::backward(double d_out) {
	return {d_out, d_out};
}