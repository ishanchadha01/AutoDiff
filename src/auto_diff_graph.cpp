#include "auto_diff_graph.hpp"
#include <iostream>


AutoDiffGraph::AutoDiffGraph(AutoDiffNode& aHead) {
    this->head = aHead;
    // this->top_sort(aHead);
}
