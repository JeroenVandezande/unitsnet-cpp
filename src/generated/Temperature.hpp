#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class TemperatureUnit : std::uint16_t
    {
        Kelvins,
        DegreesCelsius,
        MillidegreesCelsius,
        DegreesDelisle,
        DegreesFahrenheit,
        DegreesNewton,
        DegreesRankine,
        DegreesReaumur,
        DegreesRoemer,
        SolarTemperatures,
    };

    /// <summary>A temperature is a numerical measure of hot or cold. Its measurement is by detection of heat radiation or particle velocity or kinetic energy, or by the bulk behavior of a thermometric material. It may be calibrated in any of various temperature scales, Celsius, Fahrenheit, Kelvin, etc. The fundamental physical definition of temperature is provided by thermodynamics.</summary>
    class Temperature
    {
    public:
        constexpr explicit Temperature(
            double value,
            TemperatureUnit unit = TemperatureUnit::Kelvins)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(TemperatureUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Temperature operator+(Temperature other) const noexcept
        {
            return Temperature(value_ + other.value_);
        }

        [[nodiscard]] constexpr Temperature operator-(Temperature other) const noexcept
        {
            return Temperature(value_ - other.value_);
        }

        [[nodiscard]] constexpr Temperature operator*(double scalar) const noexcept
        {
            return Temperature(value_ * scalar);
        }

        [[nodiscard]] constexpr Temperature operator/(double scalar) const noexcept
        {
            return Temperature(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Temperature other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Temperature other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double kelvins() const
        {
            return convert_from_base(TemperatureUnit::Kelvins);
        }

        [[nodiscard]] static constexpr Temperature from_kelvins(double value)
        {
            return Temperature(value, TemperatureUnit::Kelvins);
        }


        [[nodiscard]] constexpr double degrees_celsius() const
        {
            return convert_from_base(TemperatureUnit::DegreesCelsius);
        }

        [[nodiscard]] static constexpr Temperature from_degrees_celsius(double value)
        {
            return Temperature(value, TemperatureUnit::DegreesCelsius);
        }


        [[nodiscard]] constexpr double millidegrees_celsius() const
        {
            return convert_from_base(TemperatureUnit::MillidegreesCelsius);
        }

        [[nodiscard]] static constexpr Temperature from_millidegrees_celsius(double value)
        {
            return Temperature(value, TemperatureUnit::MillidegreesCelsius);
        }


        [[nodiscard]] constexpr double degrees_delisle() const
        {
            return convert_from_base(TemperatureUnit::DegreesDelisle);
        }

        [[nodiscard]] static constexpr Temperature from_degrees_delisle(double value)
        {
            return Temperature(value, TemperatureUnit::DegreesDelisle);
        }


        [[nodiscard]] constexpr double degrees_fahrenheit() const
        {
            return convert_from_base(TemperatureUnit::DegreesFahrenheit);
        }

        [[nodiscard]] static constexpr Temperature from_degrees_fahrenheit(double value)
        {
            return Temperature(value, TemperatureUnit::DegreesFahrenheit);
        }


        [[nodiscard]] constexpr double degrees_newton() const
        {
            return convert_from_base(TemperatureUnit::DegreesNewton);
        }

        [[nodiscard]] static constexpr Temperature from_degrees_newton(double value)
        {
            return Temperature(value, TemperatureUnit::DegreesNewton);
        }


        [[nodiscard]] constexpr double degrees_rankine() const
        {
            return convert_from_base(TemperatureUnit::DegreesRankine);
        }

        [[nodiscard]] static constexpr Temperature from_degrees_rankine(double value)
        {
            return Temperature(value, TemperatureUnit::DegreesRankine);
        }


        [[nodiscard]] constexpr double degrees_reaumur() const
        {
            return convert_from_base(TemperatureUnit::DegreesReaumur);
        }

        [[nodiscard]] static constexpr Temperature from_degrees_reaumur(double value)
        {
            return Temperature(value, TemperatureUnit::DegreesReaumur);
        }


        [[nodiscard]] constexpr double degrees_roemer() const
        {
            return convert_from_base(TemperatureUnit::DegreesRoemer);
        }

        [[nodiscard]] static constexpr Temperature from_degrees_roemer(double value)
        {
            return Temperature(value, TemperatureUnit::DegreesRoemer);
        }


        [[nodiscard]] constexpr double solar_temperatures() const
        {
            return convert_from_base(TemperatureUnit::SolarTemperatures);
        }

        [[nodiscard]] static constexpr Temperature from_solar_temperatures(double value)
        {
            return Temperature(value, TemperatureUnit::SolarTemperatures);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, TemperatureUnit unit)
        {
            switch (unit)
            {

            case TemperatureUnit::Kelvins:
                return value;

            case TemperatureUnit::DegreesCelsius:
                return value + 273.15;

            case TemperatureUnit::MillidegreesCelsius:
                return value / 1000 + 273.15;

            case TemperatureUnit::DegreesDelisle:
                return value * -2 / 3 + 373.15;

            case TemperatureUnit::DegreesFahrenheit:
                return value * 5 / 9 + 459.67 * 5 / 9;

            case TemperatureUnit::DegreesNewton:
                return value * 100 / 33 + 273.15;

            case TemperatureUnit::DegreesRankine:
                return value * 5 / 9;

            case TemperatureUnit::DegreesReaumur:
                return value * 5 / 4 + 273.15;

            case TemperatureUnit::DegreesRoemer:
                return value * 40 / 21 + 273.15 - 7.5 * 40 / 21;

            case TemperatureUnit::SolarTemperatures:
                return value * 5778;

            }

            throw std::invalid_argument("Unknown Temperature unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(TemperatureUnit unit) const
        {
            switch (unit)
            {

            case TemperatureUnit::Kelvins:
                return value_;

            case TemperatureUnit::DegreesCelsius:
                return value_ - 273.15;

            case TemperatureUnit::MillidegreesCelsius:
                return (value_ - 273.15) * 1000;

            case TemperatureUnit::DegreesDelisle:
                return (value_ - 373.15) * -3 / 2;

            case TemperatureUnit::DegreesFahrenheit:
                return (value_ - 459.67 * 5 / 9) * 9 / 5;

            case TemperatureUnit::DegreesNewton:
                return (value_ - 273.15) * 33 / 100;

            case TemperatureUnit::DegreesRankine:
                return value_ * 9 / 5;

            case TemperatureUnit::DegreesReaumur:
                return (value_ - 273.15) * 4 / 5;

            case TemperatureUnit::DegreesRoemer:
                return (value_ - (273.15 - 7.5 * 40 / 21)) * 21 / 40;

            case TemperatureUnit::SolarTemperatures:
                return value_ / 5778;

            }

            throw std::invalid_argument("Unknown Temperature unit.");
        }

        double value_;
    };
}
