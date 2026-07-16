#include <catch2/catch_test_macros.hpp>

#include "pokedex/repository/pokemon/PokemonRepository.h"

TEST_CASE("PokemonRepository returns the Pokemon for a valid ID")
{
    indigo::PokemonRepository repository;

    auto result = repository.get(1);

    REQUIRE(result.has_value());
    CHECK(result->id() == 1);
    CHECK(result->name() == "Bulbasaur");
}

TEST_CASE("PokemonRepository returns nothing for invalid ID")
{
    indigo::PokemonRepository repository;

    auto result = repository.get(9999);

    REQUIRE_FALSE(result);
}
