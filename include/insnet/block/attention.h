#ifndef INSNET_ATTENTION_H
#define INSNET_ATTENTION_H

#include "insnet/operator/linear.h"
#include "insnet/computation-graph/graph.h"
#include "insnet/param/base-param.h"

namespace insnet {

std::pair<BatchedNode *, BatchedNode *> dotAttention(BatchedNode &key_matrix,
        BatchedNode &value_matrix,
        BatchedNode &query_matrix,
        int q_col,
        bool is_decoder);

Node * dotAttentionWeights(Node& key_matrix, Node& guide);

struct AdditiveAttentionParams : TunableCombination<BaseParam>
#if USE_GPU
, public cuda::TransferableComponents
#endif
{
    LinearParams k, q, vt;

    AdditiveAttentionParams(const std::string &name);

    template<typename Archive>
    void serialize(Archive &ar) {
        ar(k, q, vt);
    }

    void init(int k_size, int q_size);

#if USE_GPU
    std::vector<Transferable *> transferablePtrs() override {
        return {&k, &q, &vt};
    }
#endif

protected:
    std::vector<Tunable<BaseParam> *> tunableComponents() override;
};

std::pair<Node *, Node *> additiveAttention(Node &guide, Node &value, int value_col,
        AdditiveAttentionParams &params);

}

#endif
