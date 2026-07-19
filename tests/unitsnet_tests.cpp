#include <Angle.hpp>
#include <ElectricResistance.hpp>
#include <Information.hpp>
#include <Length.hpp>
#include <Pressure.hpp>
#include <Speed.hpp>
#include <Temperature.hpp>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numbers>
#include <stdexcept>
#include <string_view>
#include <type_traits>

#ifdef UNITSNET_CPP_USE_FLOAT
static_assert(std::is_same_v<unitsnet_cpp::un_scalar_t, float>);
#else
static_assert(std::is_same_v<unitsnet_cpp::un_scalar_t, double>);
#endif

namespace
{
    int failure_count = 0;

    void expect_true(bool condition, std::string_view description)
    {
        if (!condition)
        {
            std::cerr << "FAIL: " << description << '\n';
            ++failure_count;
        }
    }

    void expect_near(
        double actual,
        double expected,
        double tolerance,
        std::string_view description)
    {
        if constexpr (std::is_same_v<unitsnet_cpp::un_scalar_t, float>)
        {
            const auto magnitude = std::max(1.0, std::abs(expected));
            tolerance = std::max(tolerance, 1e-5 * magnitude);
        }

        if (std::abs(actual - expected) > tolerance)
        {
            std::cerr << "FAIL: " << description
                      << " (expected " << expected
                      << ", got " << actual << ")\n";
            ++failure_count;
        }
    }

    template<typename Callback>
    void expect_invalid_argument(Callback callback, std::string_view description)
    {
        try
        {
            callback();
            std::cerr << "FAIL: " << description
                      << " (no exception was thrown)\n";
            ++failure_count;
        }
        catch (const std::invalid_argument&)
        {
        }
        catch (...)
        {
            std::cerr << "FAIL: " << description
                      << " (unexpected exception type)\n";
            ++failure_count;
        }
    }

    void test_length_conversions_and_arithmetic()
    {
        using namespace unitsnet_cpp;

        constexpr auto trip = Length::from_kilometers(5.0);
        static_assert(trip.meters() == 5000.0);

        const auto mile = Length::from_miles(1.0);
        expect_near(mile.meters(), 1609.344, 1e-9, "miles convert to meters");
        expect_near(
            mile.value(LengthUnit::Yards),
            1760.0,
            1e-9,
            "enum-based length conversion");

        const auto total = trip + Length::from_meters(250.0);
        expect_near(total.kilometers(), 5.25, 1e-12, "length addition");
        expect_near(
            (total - Length::from_meters(250.0)).kilometers(),
            5.0,
            1e-12,
            "length subtraction");
        expect_near((trip * 2.0).kilometers(), 10.0, 1e-12, "scalar multiplication");
        expect_near((trip / 2.0).kilometers(), 2.5, 1e-12, "scalar division");
        expect_true(trip == Length::from_meters(5000.0), "equivalent lengths compare equal");
        expect_true(trip < total, "length less-than comparison");
    }

    void test_temperature_conversions()
    {
        using namespace unitsnet_cpp;

        const auto room_temperature = Temperature::from_degrees_celsius(20.0);
        expect_near(
            room_temperature.degrees_fahrenheit(),
            68.0,
            1e-10,
            "Celsius converts to Fahrenheit");
        expect_near(
            room_temperature.kelvins(),
            293.15,
            1e-12,
            "Celsius converts to kelvins");

        const auto freezing = Temperature::from_degrees_fahrenheit(32.0);
        expect_near(
            freezing.degrees_celsius(),
            0.0,
            1e-12,
            "Fahrenheit converts to Celsius");
    }

    void test_representative_quantities()
    {
        using namespace unitsnet_cpp;

        expect_near(
            Speed::from_kilometers_per_hour(90.0).meters_per_second(),
            25.0,
            1e-12,
            "kilometers per hour convert to meters per second");
        expect_near(
            Pressure::from_bars(1.0).kilopascals(),
            100.0,
            1e-12,
            "bars convert to kilopascals");
        expect_near(
            ElectricResistance::from_kiloohms(4.7).ohms(),
            4700.0,
            1e-12,
            "kiloohms convert to ohms");
        expect_near(
            Information::from_bytes(1.0).bits(),
            8.0,
            1e-12,
            "bytes convert to bits");
        expect_near(
            Angle::from_degrees(180.0).radians(),
            std::numbers::pi,
            1e-12,
            "degrees convert to radians");
    }

    void test_invalid_unit_rejected()
    {
        using namespace unitsnet_cpp;

        expect_invalid_argument(
            []
            {
                static_cast<void>(Length(
                    1.0,
                    static_cast<LengthUnit>(65535)));
            },
            "invalid unit is rejected");
    }
}

int main()
{
    test_length_conversions_and_arithmetic();
    test_temperature_conversions();
    test_representative_quantities();
    test_invalid_unit_rejected();

    if (failure_count != 0)
    {
        std::cerr << failure_count << " test(s) failed.\n";
        return 1;
    }

    constexpr std::string_view scalar_name =
        std::is_same_v<unitsnet_cpp::un_scalar_t, float> ? "float" : "double";
    std::cout << "All unitsnet-cpp tests passed with " << scalar_name << ".\n";
    return 0;
}
