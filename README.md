# unitsnet-cpp

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
- Header-only CMake target with no runtime dependencies

## Requirements

- A C++20-compatible compiler
- CMake 3.31.6 or newer when using the supplied CMake project

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

    const auto extra = Length(250.0, LengthUnit::Meters);
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
constexpr auto yards = distance.value(LengthUnit::Yards); // Enum-based conversion
constexpr auto base = distance.base_value();              // SI/base-unit value
```

Quantities of the same type support `+`, `-`, multiplication and division by a scalar, equality, and less-than comparison.

## CMake integration

Add the repository to your project and link the interface target:

```cmake
add_subdirectory(path/to/unitsnet-cpp)

target_link_libraries(your_target
    PRIVATE
        UnitsNet::UnitsNet
)
```

The target supplies the generated include directory and enables C++20 for consumers.

To compile-check every generated header:

```sh
cmake -S . -B build
cmake --build build --target unitsnet_cpp_compile_check
```

## Project status

The current release focuses on generated quantity types, conversions, same-quantity arithmetic, and comparisons. Some functionality available in UnitsNet—such as string parsing, formatting, localization, runtime quantity discovery, serialization, and cross-quantity operators—is not yet implemented.

Generated headers live in [`src/generated`](src/generated). The generator lives in [`codegen`](codegen) and consumes the unit definitions from the upstream UnitsNet repository.

## Acknowledgements

- [UnitsNet](https://github.com/angularsen/UnitsNet) for the original library and unit definitions
- [unitsnet-js](https://github.com/haimkastner/unitsnet-js) for demonstrating a generated port of UnitsNet to another language

## License

This project is licensed under the [MIT License](LICENSE).
