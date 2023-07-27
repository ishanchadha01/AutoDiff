#pragma once

#include <numeric>
#include "operator.hpp"

class Mult : public Operator {
	public:
		Mult(AutoDiffNode* node1, AutoDiffNode* node2);
		virtual data_type forward();
		virtual std::vector<data_type> backward(data_type d_out);
};