#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include <variant>
#include <Eigen/Dense>
#include <iostream>


using data_type = std::variant<double, Eigen::MatrixXd>;
template<class... Ts> struct overload : Ts... { using Ts::operator()...; };
template<class... Ts> overload(Ts...) -> overload<Ts...>;

enum NodeType {
    VARIABLE = 0,
    OPERATOR = 1
};

class AutoDiffNode {
    public:
		AutoDiffNode();

        AutoDiffNode* operator+(AutoDiffNode* addend);
        AutoDiffNode* operator*(AutoDiffNode* multiplier);
        AutoDiffNode* operator/(AutoDiffNode* divisor);
        AutoDiffNode* power(AutoDiffNode* exponent);
        NodeType virtual get_type() = 0;

        NodeType type;
        data_type val;
        std::string id;
        std::vector<AutoDiffNode*> inputs; // children of this node in the computation tree
};