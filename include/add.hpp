#include <numeric>

#include "operator.hpp"

class Add : Operator {
	public:
		Add();
		double forward();
		inputs_pair backward(double d_out);
};