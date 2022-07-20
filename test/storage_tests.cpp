#include "dss/Entry.hpp"
#include <catch2/catch_test_macros.hpp>
#include <dss/ExpressionPredicates.hpp>
#include <dss/Storage.hpp>
#include <tuple>

template <typename TDecorated> struct Item final : TDecorated {
  int number{0};
};

TEST_CASE("insert, read, update, remove from the storage", "[storage]") {
  using Storage = dss::Storage<dss::Entry>;
  using dss::Entry;
  Storage storage;

  SECTION("Insert some and retrieve") {
    const auto v0 = Entry{"SomeKey", "SomeValue"};
    const auto v1 = Entry{"12314", "AnotherValue"};

    storage.insert(v0);
    storage.insert(v1);

    auto selected = storage.select(dss::all<Entry>);

    REQUIRE(selected.size() == 2);

    REQUIRE(
        std::find_if(selected.begin(), selected.end(),
                     [key = v0.key(), value = v0.value()](const auto &object) {
                       return object.key() == key and object.value() == value;
                     }) != selected.end());

    REQUIRE(
        std::find_if(selected.begin(), selected.end(),
                     [key = v1.key(), value = v1.value()](const auto &object) {
                       return object.key() == key and object.value() == value;
                     }) != selected.end());
  }

  SECTION("Insert and update") {
    const auto v0 = Entry{"SomeKey", "SomeValue"};

    storage.insert(v0);

    REQUIRE(storage.select(dss::all<Entry>).size() == 1);

    const auto v0_update = Entry{"SomeKey", "ButAnotherValue"};

    storage.insert(v0_update);

    auto selected = storage.select(
        [key = v0_update.key()](auto object) { return object.key() == key; });

    REQUIRE_FALSE(selected.empty());

    // Some Catch2 oddity with string_view comparison
    REQUIRE(std::string{selected[0].value()} == std::string{v0_update.value()});
  }

  SECTION("Insert and remove") {
    const auto v0 = Entry{"SomeKey", "SomeValue"};

    storage.insert(v0);

    REQUIRE(storage.select(dss::all<Entry>).size() == 1);

    storage.remove(v0);

    REQUIRE(storage.select(dss::all<Entry>).empty());
  }
}