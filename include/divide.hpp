#pragma once

#include <numeric>
#include "operator.hpp"

class Divide : public Operator {
	public:
		Divide(AutoDiffNode node1, AutoDiffNode node2);
		data_type forward();
		std::pair<data_type, data_type> backward(double d_out);
};