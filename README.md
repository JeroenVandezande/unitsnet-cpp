# unitsnet-cpp

[![Tests](https://github.com/JeroenVandezande/unitsnet-cpp/actions/workflows/tests.yml/badge.svg)](https://github.com/JeroenVandezande/unitsnet-cpp/actions/workflows/tests.yml)
[![CPM.cmake ready](https://img.shields.io/badge/CPM.cmake-ready-blue.svg)](https://github.com/cpm-cmake/CPM.cmake)

A header-only C++20 port of [UnitsNet](https://github.com/angularsen/UnitsNet), inspired by the API and approach of [unitsnet-js](https://github.com/haimkastner/unitsnet-js).

`unitsnet-cpp` provides strongly typed quantities and unit conversions without a runtime dependency. The quantity headers are generated from the upstream UnitsNet definitions.

> [!NOTE]
> This is an independent, early-stage port and is not affiliated with or endorsed by the UnitsNet maintainers. The API may change before a stable release.

## Features

- 128 generated quantity types, including length, mass, temperature, speed, energy, pressure, and electrical quantities
- Type-safe values: a `Length` cannot accidentally be used as a `Mass`
- `constexpr` construction, conversion, arithmetic, and comparison
- Named factories and accessors such as `Length::from_kilometers()` and `Length::miles()`
- Generic conversion through each quantity's unit enum
- Optional DTOs and nlohmann/json serialization for cross-language exchange
- CPM-ready, header-only CMake target with no runtime dependencies

## Requirements

- A C++20-compatible compiler
- CMake 3.31.6 or newer when using the supplied CMake project

## Add with CPM.cmake

The intended way to consume `unitsnet-cpp` is with [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake). This example downloads a fixed CPM version, adds `unitsnet-cpp` 1.0.0, and links its interface target:

```cmake
# Download CPM.cmake
set(CPM_VERSION 0.42.0)
message("Downloading CPM Package Manager version ${CPM_VERSION}")
file(
    DOWNLOAD
    https://github.com/cpm-cmake/CPM.cmake/releases/download/v${CPM_VERSION}/CPM.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/CPM_${CPM_VERSION}.cmake
)
include("${CMAKE_CURRENT_BINARY_DIR}/CPM_${CPM_VERSION}.cmake")

# Include unitsnet-cpp
CPMAddPackage("gh:JeroenVandezande/unitsnet-cpp@1.0.0")

target_link_libraries(your_target
    PRIVATE
        UnitsNet::UnitsNet
)
```

CPM downloads and configures the repository during CMake configuration. Linking `UnitsNet::UnitsNet` supplies the generated include directory and enables C++20 for the consuming target; there is no binary library to build or install.

The `@1.0.0` suffix selects the `v1.0.0` Git tag, keeping dependency resolution reproducible. Update that version explicitly when adopting a newer release.

## Usage

Include the header for the quantity you need:

```cpp
#include <Length.hpp>
#include <Temperature.hpp>

#include <iostream>

int main()
{
    using namespace unitsnet_cpp;

    constexpr auto trip = Length::from_kilometers(5.0);
    static_assert(trip.meters() == 5000.0);

    const auto extra = Length(250.0, LengthUnit::Meter);
    const auto total = trip + extra;

    std::cout << total.kilometers() << " km\n";

    constexpr auto room_temperature =
        Temperature::from_degrees_celsius(21.0);
    std::cout << room_temperature.degrees_fahrenheit() << " deg F\n";
}
```

Every quantity follows the same basic API:

```cpp
using namespace unitsnet_cpp;

constexpr auto distance = Length::from_miles(1.0);       // Named factory
constexpr auto meters = distance.meters();               // Named accessor
constexpr auto yards = distance.value(LengthUnit::Yard); // Enum-based conversion
constexpr auto base = distance.base_value();              // SI/base-unit value
```

Quantities of the same type support `+`, `-`, multiplication and division by a scalar, equality, and less-than comparison.

## Optional JSON serialization

DTO and [nlohmann/json](https://github.com/nlohmann/json) support is disabled by default. Enable it before adding `unitsnet-cpp` with CPM:

```cmake
set(UNITSNET_ENABLE_NLOHMANN_JSON ON CACHE BOOL "" FORCE)
CPMAddPackage("gh:JeroenVandezande/unitsnet-cpp@1.0.0")
```

The option downloads nlohmann/json, enables the generated DTO types, and propagates both requirements through `UnitsNet::UnitsNet`:

```cpp
#include <Length.hpp>
#include <nlohmann/json.hpp>

using namespace unitsnet_cpp;

const auto distance = Length::from_kilometers(5.25);
const nlohmann::json json = distance.to_json(LengthUnit::Kilometer);
// {"unit":"Kilometer","value":5.25}

const auto restored = Length::from_json(json);

const auto dto_json = distance.to_dto(LengthUnit::Kilometer).to_json();
const auto dto = LengthDto::from_json(dto_json);
```

When `UNITSNET_ENABLE_NLOHMANN_JSON` is off, nlohmann/json is neither downloaded nor included. If only DTOs are needed, enable them before adding the package:

```cmake
set(UNITSNET_ENABLE_DTO ON CACHE BOOL "" FORCE)
```

DTO support uses the header-only [magic_enum](https://github.com/Neargye/magic_enum) library for stable enum name conversion. Both optional dependencies remain disabled in the default configuration.

## Local CMake integration

When developing against a local checkout instead of CPM, add the repository directly and link the same interface target:

```cmake
add_subdirectory(path/to/unitsnet-cpp)

target_link_libraries(your_target
    PRIVATE
        UnitsNet::UnitsNet
)
```

To compile-check every generated header:

```sh
cmake -S . -B build
cmake --build build --target unitsnet_cpp_compile_check
```

## Tests

The Catch2 test suite covers representative linear and affine conversions, enum-based conversion, arithmetic, comparisons, DTOs, `magic_enum`, JSON round-trips, and invalid-unit handling. Every test is compiled and run twice: once with the default `double` representation and once with `UNITSNET_CPP_USE_FLOAT`. Catch2 discovers the individual cases through CTest, which is also used by the GitHub Actions workflow.

Tests are enabled by default when building `unitsnet-cpp` directly and disabled by default when it is included as a dependency through CPM. To build and run them explicitly:

```sh
cmake -S . -B build -DUNITSNET_CPP_BUILD_TESTS=ON
cmake --build build
ctest --test-dir build --output-on-failure
```

The tests are a standalone CMake project and can also be configured directly:

```sh
cmake -S tests -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

Test-only DTO and JSON definitions and dependencies are injected through an interface fixture target in [`tests/CMakeLists.txt`](tests/CMakeLists.txt). They do not change the normal `UnitsNet::UnitsNet` configuration.

## Code generation

The quantity headers are generated from the JSON definitions in [UnitsNet's `Common/UnitDefinitions` directory](https://github.com/angularsen/UnitsNet/tree/master/Common/UnitDefinitions). Each definition describes a quantity's base unit, supported units, prefixes, conversion expressions, and metadata.

The generator in [`codegen`](codegen) is a small C# console application targeting .NET 10. It:

1. Downloads the current JSON definitions from the upstream UnitsNet `master` branch.
2. Deserializes each quantity definition and expands its supported metric and binary prefixes.
3. Translates the UnitsNet conversion expressions into C++ expressions.
4. Renders the [`unit.hpp.scriban`](codegen/Templates/unit.hpp.scriban) template using [Scriban](https://github.com/scriban/scriban).
5. Writes one C++ header per quantity into [`src/generated`](src/generated).

The C# generator is a maintainer tool only. It is not configured, built, or executed when this library is added through CPM. All generated C++ headers are committed to the repository, so consumers need only CMake and a C++20 compiler—no .NET SDK, C# runtime, Scriban package, or network access is required to compile the library after CPM has fetched it.

Maintainers who want to update the generated headers need the .NET 10 SDK. NuGet restores the generator's Scriban dependency from [`codegen.csproj`](codegen/codegen.csproj).

## Project status

The current release focuses on generated quantity types, conversions, same-quantity arithmetic, comparisons, and optional DTO serialization. Some functionality available in UnitsNet—such as string parsing, formatting, localization, runtime quantity discovery, and cross-quantity operators—is not yet implemented.

## Acknowledgements

- [UnitsNet](https://github.com/angularsen/UnitsNet) for the original library and unit definitions
- [unitsnet-js](https://github.com/haimkastner/unitsnet-js) for demonstrating a generated port of UnitsNet to another language

## License

This project is licensed under the [MIT License](LICENSE).
