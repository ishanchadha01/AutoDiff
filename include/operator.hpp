#include <unordered_map>
#include <string>
#include <vector>
#include <variant>
#include <Eigen/Dense>
#include <iostream>


using input = std::variant<double, Eigen::MatrixXd>;
template<class... Ts> struct overload : Ts... { using Ts::operator()...; };
template<class... Ts> overload(Ts...) -> overload<Ts...>;

class Operator {
  public:
		Operator();
		std::string get_id();
		void set_id(std::string new_type);
		std::pair<input, input> get_inputs();
		// void set_inputs(std::vector<double> new_inputs);

		input virtual forward() = 0;
		std::pair<input, input> virtual backward(double d_out) = 0;

	private:
		std::string id;
		std::pair<input, input> inputs; // Can add more types to variant as more operators created
};