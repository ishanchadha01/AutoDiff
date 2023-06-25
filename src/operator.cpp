#include "add.hpp"


Operator::Operator() {
  this->id = "operator/undefined";
}


std::string Operator::get_id() {
	return this->id;
}


void Operator::set_id(std::string new_id) {
	this->id = new_id;
}


inputs_pair Operator::get_inputs() {
	return this->inputs;
}


Add::Add() {
	
}


double Add::forward() {
	inputs_pair inputs = this->get_inputs();
	return std::get<double>(inputs.first) + std::get<double>(inputs.second);
};


inputs_pair Add::backward(double d_out) {
	return {d_out, d_out};
}



