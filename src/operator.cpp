#include "operator.hpp"


Operator::Operator() {
  this->id = "operator/undefined";
}


std::string Operator::get_id() {
	return this->id;
}


void Operator::set_id(std::string new_id) {
	this->id = new_id;
}


std::pair<input, input> Operator::get_inputs() {
	return this->inputs;
}





