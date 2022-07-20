#include "Entry.hpp"

namespace dss {
Entry::Entry(std::string key_buffer, std::string value_buffer)
    : key_buffer_(std::move(key_buffer)),
      value_buffer_(std::move(value_buffer)) {}

auto Entry::get_key() const noexcept -> std::string_view { return key_buffer_; }

auto Entry::get_value() const noexcept -> std::string_view {
  return value_buffer_;
}

} // namespace dss