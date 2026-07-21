#include <Angle.hpp>
#include <ElectricResistance.hpp>
#include <Information.hpp>
#include <Length.hpp>
#include <Pressure.hpp>
#include <Speed.hpp>
#include <Temperature.hpp>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <nlohmann/json.hpp>

#include <algorithm>
#include <cmath>
#include <numbers>
#include <stdexcept>
#include <string>
#include <type_traits>

#ifdef UNITSNET_CPP_USE_FLOAT
static_assert(std::is_same_v<unitsnet_cpp::un_scalar_t, float>);
#else
static_assert(std::is_same_v<unitsnet_cpp::un_scalar_t, double>);
#endif

namespace
{
    double adjusted_tolerance(const double expected, const double tolerance)
    {
        if constexpr (std::is_same_v<unitsnet_cpp::un_scalar_t, float>)
        {
            const auto magnitude = std::max(4.0, std::abs(expected));
            return std::max(tolerance, 1e-5 * magnitude);
        }

        return tolerance;
    }

    void check_near(const double actual, const double expected, const double tolerance)
    {
        CHECK_THAT(
            actual,
            Catch::Matchers::WithinAbs(expected, adjusted_tolerance(expected, tolerance)));
    }
}

TEST_CASE("Length conversions and arithmetic", "[length][arithmetic]")
{
    using namespace unitsnet_cpp;

    constexpr auto trip = Length::from_kilometers(5.0);
    static_assert(trip.meters() == 5000.0);

    const auto mile = Length::from_miles(1.0);
    check_near(mile.meters(), 1609.344, 1e-9);
    check_near(mile.value(LengthUnit::Yard), 1760.0, 1e-9);

    const auto total = trip + Length::from_meters(250.0);
    check_near(total.kilometers(), 5.25, 1e-12);
    check_near((total - Length::from_meters(250.0)).kilometers(), 5.0, 1e-12);
    check_near((trip * 2.0).kilometers(), 10.0, 1e-12);
    check_near((trip / 2.0).kilometers(), 2.5, 1e-12);
    CHECK(trip == Length::from_meters(5000.0));
    CHECK(trip < total);
}

TEST_CASE("Temperature conversions", "[temperature]")
{
    using namespace unitsnet_cpp;

    const auto room_temperature = Temperature::from_degrees_celsius(20.0);
    check_near(room_temperature.degrees_celsius(), 20.0, 1e-10);
    check_near(room_temperature.degrees_fahrenheit(), 68.0, 1e-10);
    check_near(room_temperature.kelvins(), 293.15, 1e-12);

    const auto freezing = Temperature::from_degrees_fahrenheit(32.0);
    check_near(freezing.degrees_celsius(), 0.0, 1e-12);
}

TEST_CASE("Representative quantities convert correctly", "[quantities]")
{
    using namespace unitsnet_cpp;

    check_near(Speed::from_kilometers_per_hour(90.0).meters_per_second(), 25.0, 1e-12);
    check_near(Pressure::from_bars(1.0).kilopascals(), 100.0, 1e-12);
    check_near(ElectricResistance::from_kiloohms(4.7).ohms(), 4700.0, 1e-12);
    check_near(Information::from_bytes(1.0).bits(), 8.0, 1e-12);
    check_near(Angle::from_degrees(180.0).radians(), std::numbers::pi, 1e-12);
}

TEST_CASE("DTOs round-trip and use stable unit names", "[dto][magic_enum]")
{
    using namespace unitsnet_cpp;

    const auto original = Length::from_kilometers(5.25);
    const auto dto = original.to_dto(LengthUnit::Kilometer);

    CHECK(std::string(dto.unit_name()) == "Kilometer");
    CHECK(LengthDto::unit_from_name("Kilometer") == LengthUnit::Kilometer);
    check_near(Length::from_dto(dto).meters(), 5250.0, 1e-9);
    CHECK_THROWS_AS(LengthDto::unit_from_name("NotAUnit"), std::invalid_argument);
}

TEST_CASE("DTO and quantity JSON APIs round-trip", "[dto][json]")
{
    using namespace unitsnet_cpp;

    const auto original = Length::from_kilometers(5.25);
    const LengthDto dto = original.to_dto(LengthUnit::Kilometer);
    const nlohmann::json dto_json = dto.to_json();

    check_near(dto_json.at("value").get<double>(), 5.25, 1e-12);
    CHECK(dto_json.at("unit").get<std::string>() == "Kilometer");

    const auto restored_dto = LengthDto::from_json(dto_json);
    check_near(Length::from_dto(restored_dto).meters(), 5250.0, 1e-9);

    const auto quantity_json = original.to_json(LengthUnit::Kilometer);
    check_near(Length::from_json(quantity_json).meters(), 5250.0, 1e-9);

    const auto invalid = nlohmann::json{
        {"value", 1.0},
        {"unit", "NotAUnit"}
    };
    CHECK_THROWS_AS(LengthDto::from_json(invalid), std::invalid_argument);
}
