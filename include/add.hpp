#include <numeric>

#include "operator.hpp"

class Add : Operator {
	public:
		Add();
		data_type forward();
		std::pair<data_type, data_type> backward(double d_out);
};