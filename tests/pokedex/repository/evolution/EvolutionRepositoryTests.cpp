#include <catch2/catch_test_macros.hpp>

#include "pokedex/repository/evolution/EvolutionRepository.h"

namespace indigo
{

TEST_CASE("EvolutionRepository returns a level evolution")
{
    indigo::EvolutionRepository repository;

    // Bulbasaur evolution should only return 1 evolution
    auto result = repository.get(1);

    REQUIRE(result.size() == 1);

    const auto& evolution = result.front();
    const auto method = evolution.method();

    CHECK(evolution.to() == 2);
    CHECK(method.type() == EvolutionMethodType::LEVEL);
    CHECK(method.level() == 16);
}

TEST_CASE("EvolutionRepository returns an item evolution")
{
    indigo::EvolutionRepository repository;

    // Pikachu evolution should only return 1 evolution
    auto result = repository.get(25);

    REQUIRE(result.size() == 1);

    const auto& evolution = result.front();
    const auto method = evolution.method();

    CHECK(evolution.to() == 26);
    CHECK(method.type() == EvolutionMethodType::ITEM);
    CHECK(method.item() == Item::THUNDER_STONE);
}

TEST_CASE("EvolutionRepository returns no evolutions for a Pokemon without evolutions")
{
    indigo::EvolutionRepository repository;

    // Venusaur evolution should return 0 evolutions
    auto result = repository.get(3);

    CHECK(result.empty());
}

}
