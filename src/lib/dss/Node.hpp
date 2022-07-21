#pragma once

#include "Executor.hpp"
#include "MetaEntry.hpp"
#include "Storage.hpp"
#include "Transport.hpp"

namespace dss {
class Node {
public:
  using entry_t = MetaEntry<Entry>;
  using storage_t = Storage<entry_t>;
  using transport_t = Transport;
  using executor_t = Executor<storage_t, transport_t>;

  void run();

private:
  storage_t storage_;
  transport_t transport_;
  executor_t executor_{storage_, transport_};

  bool is_runnig_{true};
};
} // namespace dss