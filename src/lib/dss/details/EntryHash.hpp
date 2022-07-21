#pragma once

#include <functional>
#include <sys/types.h>

namespace dss::details {
template <typename Entry> struct EntryHash final {
  constexpr std::size_t operator()(const Entry &entry) const noexcept {
    return std::hash<decltype(entry.key())>{}(entry.key());
  }

  constexpr bool operator()(const Entry &lv, const Entry &rv) const noexcept {
    return lv.key() == rv.key();
  }
};
} // namespace dss::details