#include "add.hpp"


Add::Add() {
	
}


data_type Add::forward() {
	std::pair<data_type, data_type> inputs = this->inputs;
	return std::get<double>(inputs.first) + std::get<double>(inputs.second);
};


std::pair<data_type, data_type> Add::backward(double d_out) {
	return {d_out, d_out};
}