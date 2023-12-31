#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include <variant>
#include <eigen3/Eigen/Dense>
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
        
        AutoDiffNode(data_type aVal) : val(aVal) {};
        NodeType virtual get_type() = 0;

        NodeType type;
        data_type val;
        data_type gradient = 1.;
        std::string id;
        std::vector<AutoDiffNode*> inputs; // children of this node in the computation tree
        bool is_placeholder = false;
};