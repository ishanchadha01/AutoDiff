#pragma once

#include "auto_diff_node.hpp"


class Variable : public AutoDiffNode {
  public:
		Variable();
        Variable(data_type aVal);

		std::string id;
        data_type val;
};