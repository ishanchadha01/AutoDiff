#include <numeric>

#include "operator.hpp"

class Divide : Operator {
	public:
		Divide();
		double forward();
		std::pair<input, input> backward(double d_out);
};