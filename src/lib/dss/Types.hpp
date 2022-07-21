#pragma once

#include "details/StrongType.hpp"
#include <cstddef>
#include <numeric>

namespace dss {
using TransactionID = details::StrongType<std::size_t, struct TransactionIDTag>;
using LockID = details::StrongType<std::size_t, struct LockIDTag>;
using NodeID = details::StrongType<std::size_t, struct NodeIDTag>;
} // namespace dss