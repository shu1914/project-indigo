# Catch2 Testing Guidelines

This document defines the conventions used when writing unit tests with Catch2.

---

## Philosophy

Tests should verify **behavior**, not implementation.

A good test answers:

> "Given this situation, when this action occurs, what should happen?"

Avoid testing implementation details such as private members, internal algorithms, or temporary variables. Refactoring the implementation should not require rewriting tests if the externally observable behavior remains unchanged.

---

## Choosing Between `TEST_CASE` and `SCENARIO`

Catch2 provides multiple ways to structure tests. The two primary styles used in this project are:

- `TEST_CASE`
- `SCENARIO`

Choose the one that best communicates the behavior being tested.

---

## `TEST_CASE`

Use `TEST_CASE` when verifying a **single piece of behavior** or a **simple contract**.

Characteristics:

- Simple input → output
- Little or no setup
- No sequence of events
- Easy to understand without additional context

Examples:

- Constructing an object
- Calling one function
- Verifying one return value
- Validating an invariant
- Testing a utility function
- Testing a value object

Example:

```cpp
TEST_CASE("Absolute value of a positive number")
{
    CHECK(abs(5) == 5);
}
```

Another example:

```cpp
TEST_CASE("Creating a point initializes its coordinates")
{
    Point point(10, 20);

    CHECK(point.x() == 10);
    CHECK(point.y() == 20);
}
```

---

## `SCENARIO`

Use `SCENARIO` when testing **behavior described as a workflow**.

A scenario answers:

> Given some initial state,
> When an action occurs,
> Then an observable outcome should happen.

BDD syntax makes the test read almost like documentation.

Structure:

```cpp
SCENARIO("...")
{
    GIVEN("...")
    {
        WHEN("...")
        {
            THEN("...")
            {
            }
        }
    }
}
```

Typical uses:

- User interactions
- Service orchestration
- Business workflows
- State transitions
- Multi-step operations
- Component collaboration

Example:

```cpp
SCENARIO("Adding an item to an empty cart")
{
    GIVEN("an empty shopping cart")
    {
        WHEN("an item is added")
        {
            THEN("the cart contains one item")
            {
            }
        }
    }
}
```

---

## When NOT to use `SCENARIO`

Do not force BDD syntax when there is no meaningful setup or sequence.

Avoid:

```cpp
SCENARIO("Adding two numbers")
{
    GIVEN("a calculator")
    {
        ...
    }
}
```

The `GIVEN` adds no value.

Instead:

```cpp
TEST_CASE("Calculator adds two numbers")
{
    CHECK(add(2, 3) == 5);
}
```

---

## Optional `GIVEN`

`GIVEN` is optional.

If there is no meaningful precondition, it is acceptable to omit it.

Example:

```cpp
SCENARIO("Looking up an existing record")
{
    WHEN("requesting an existing identifier")
    {
        THEN("the corresponding record is returned")
        {
        }
    }
}
```

---

## Multiple `WHEN`s

A single scenario may contain multiple independent actions.

Example:

```cpp
SCENARIO("Looking up records")
{
    GIVEN("a populated repository")
    {
        WHEN("requesting an existing identifier")
        {
            THEN("the record is returned")
            {
            }
        }

        WHEN("requesting an unknown identifier")
        {
            THEN("no record is returned")
            {
            }
        }
    }
}
```

This avoids duplicating common setup.

---

## Naming Guidelines

Test names should describe observable behavior.

Prefer:

- "Creating an object initializes its state"
- "Looking up an existing record returns the record"
- "Requesting an unknown identifier returns no result"

Avoid:

- "Test constructor"
- "Function works"
- "Testing get()"

A reader should understand the expected behavior without reading the implementation.

---

## Assertions

Use the appropriate assertion for the situation.

Use:

```cpp
REQUIRE(...)
```

when the test cannot continue if the condition fails.

Example:

```cpp
REQUIRE(result.has_value());
```

Use:

```cpp
CHECK(...)
```

for subsequent validations.

Example:

```cpp
CHECK(result->id() == 1);
CHECK(result->name() == "Example");
```

---

## One Behavior Per Test

Each test should verify a single behavior.

Avoid combining unrelated concerns into one test. Separate success and failure paths into different test cases.

Prefer:

- one test for successful lookup
- one test for failed lookup

instead of a single test that covers both scenarios.

```cpp
TEST_CASE("find() returns the Pokémon when it exists")
{
    // Arrange

    // Act

    // Assert
}

TEST_CASE("find() returns std::nullopt when the Pokémon does not exist")
{
    // Arrange

    // Act

    // Assert
}
```

---

## Keep Tests Independent

Tests must not depend on execution order.

Every test should be executable in isolation.

Avoid:

- shared mutable state
- reliance on previous tests
- hidden global state

---

## Test the Public API

Tests should interact only with the public interface.

Avoid testing:

- private members
- private helper functions
- implementation details

Instead, verify the observable behavior exposed by the public API.

---

## Prefer Readability Over Cleverness

Tests serve as executable documentation.

Prioritize:

- descriptive names
- simple structure
- minimal setup

over reducing the number of lines.

A test that is easy to read is easier to maintain.