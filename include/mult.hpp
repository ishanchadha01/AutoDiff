#include <numeric>

#include "operator.hpp"

class Mult : Operator {
	public:
		Mult();
		data_type forward();
		std::pair<data_type, data_type> backward(double d_out);
};