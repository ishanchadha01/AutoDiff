#include <numeric>

#include "operator.hpp"

class Mult : Operator {
	public:
		Mult();
		input forward();
		std::pair<input, input> backward(double d_out);
};