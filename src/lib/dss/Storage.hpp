#pragma once

#include "Entry.hpp"
#include "details/EntryHash.hpp"
#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <vector>

namespace dss {
template <typename TStored> class Storage final {
public:
  template <typename TPredicate>
  auto select(TPredicate predicate) const -> std::vector<TStored> {
    std::vector<TStored> result;

    std::copy_if(std::cbegin(memory_storage_), std::cend(memory_storage_),
                 std::back_inserter(result), predicate);

    return result;
  };

  void insert(TStored entry) {

    if (auto [where, placed] = memory_storage_.emplace(entry);
        !placed && entry.value() != where->value()) {
      where->value(std::string{entry.value()});
    }
  }
  void remove(TStored entry) { memory_storage_.erase(entry); }

private:
  using Hash = details::EntryHash<TStored>;

  // Decouple memory storage representation from the key
  // and mimic some kind of binary bulk
  std::unordered_set<TStored, Hash, Hash> memory_storage_;
};
} // namespace dss