#ifndef INSNET_ADD_H
#define INSNET_ADD_H

#include "insnet/computation-graph/graph.h"

namespace insnet {

/// \ingroup operator
/// Add input tensors.
///
/// **The add operators that have the same number of inputs will be executed in batch.** For example, [0.1, 0.1] + [0.2, 0.2] and [0.3, 0.3, 0.3] + [0.4, 0.4, 0.4] will be executed in batch, but [0.1, 0.1] + [0.2, 0.2] and [0.1, 0.1] + [0.2, 0.2] + [0.3, 0.3] will not. If the latter is your case, use *sumPool* instead.
/// \param inputs The input tensors to be added. Note that their sizes should be equal.
/// \return The sum of the input tensors. Its size is equal to the size of any input tensor.
Node *add(const std::vector<Node*> &inputs);

}

#endif
