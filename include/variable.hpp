#pragma once

#include "auto_diff_node.hpp"


class Variable : public AutoDiffNode {
  public:
		Variable();
        Variable(data_type aVal);
        NodeType get_type();

        data_type val;
};