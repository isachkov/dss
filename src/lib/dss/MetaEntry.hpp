#pragma once

#include "Types.hpp"
#include <optional>

namespace dss {
template <typename TDecorated> struct MetaEntry final : TDecorated {
  template <typename... TArgs>
  MetaEntry(TArgs &&...args) : TDecorated(std::forward<TArgs>(args)...) {}

  TransactionID modified;
  TransactionID created;
  std::optional<NodeID> locked_by;
};
} // namespace dss