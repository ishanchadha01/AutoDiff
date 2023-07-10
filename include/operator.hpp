#include <unordered_map>
#include <string>
#include <vector>
#include <variant>
// #include <eigen3/Eigen/Dense>
// #include <Eigen/Dense>


// using input = std::variant<double, Eigen::MatrixXd>;
using input = std::variant<double>;

class Operator {
  public:
		Operator();
		std::string get_id();
		void set_id(std::string new_type);
		std::pair<input, input> get_inputs();
		// void set_inputs(std::vector<double> new_inputs);

		double virtual forward() = 0;
		std::pair<input, input> virtual backward(double d_out) = 0;

	private:
		std::string id;
		std::pair<input, input> inputs; // Can add more types to variant as more operators created
};