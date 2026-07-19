#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class TemperatureUnit : std::uint8_t
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
            const un_scalar_t value,
            const TemperatureUnit unit = TemperatureUnit::Kelvins)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const TemperatureUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Temperature operator+(const Temperature other) const noexcept
        {
            return Temperature(value_ + other.value_);
        }

        [[nodiscard]] constexpr Temperature operator-(const Temperature other) const noexcept
        {
            return Temperature(value_ - other.value_);
        }

        [[nodiscard]] constexpr Temperature operator*(const un_scalar_t scalar) const noexcept
        {
            return Temperature(value_ * scalar);
        }

        [[nodiscard]] constexpr Temperature operator/(const un_scalar_t scalar) const noexcept
        {
            return Temperature(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Temperature other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Temperature other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t kelvins() const
        {
            return convert_from_base(TemperatureUnit::Kelvins);
        }

        [[nodiscard]] static constexpr Temperature from_kelvins(const un_scalar_t value)
        {
            return Temperature(value, TemperatureUnit::Kelvins);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_celsius() const
        {
            return convert_from_base(TemperatureUnit::DegreesCelsius);
        }

        [[nodiscard]] static constexpr Temperature from_degrees_celsius(const un_scalar_t value)
        {
            return Temperature(value, TemperatureUnit::DegreesCelsius);
        }


        [[nodiscard]] constexpr un_scalar_t millidegrees_celsius() const
        {
            return convert_from_base(TemperatureUnit::MillidegreesCelsius);
        }

        [[nodiscard]] static constexpr Temperature from_millidegrees_celsius(const un_scalar_t value)
        {
            return Temperature(value, TemperatureUnit::MillidegreesCelsius);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_delisle() const
        {
            return convert_from_base(TemperatureUnit::DegreesDelisle);
        }

        [[nodiscard]] static constexpr Temperature from_degrees_delisle(const un_scalar_t value)
        {
            return Temperature(value, TemperatureUnit::DegreesDelisle);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_fahrenheit() const
        {
            return convert_from_base(TemperatureUnit::DegreesFahrenheit);
        }

        [[nodiscard]] static constexpr Temperature from_degrees_fahrenheit(const un_scalar_t value)
        {
            return Temperature(value, TemperatureUnit::DegreesFahrenheit);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_newton() const
        {
            return convert_from_base(TemperatureUnit::DegreesNewton);
        }

        [[nodiscard]] static constexpr Temperature from_degrees_newton(const un_scalar_t value)
        {
            return Temperature(value, TemperatureUnit::DegreesNewton);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_rankine() const
        {
            return convert_from_base(TemperatureUnit::DegreesRankine);
        }

        [[nodiscard]] static constexpr Temperature from_degrees_rankine(const un_scalar_t value)
        {
            return Temperature(value, TemperatureUnit::DegreesRankine);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_reaumur() const
        {
            return convert_from_base(TemperatureUnit::DegreesReaumur);
        }

        [[nodiscard]] static constexpr Temperature from_degrees_reaumur(const un_scalar_t value)
        {
            return Temperature(value, TemperatureUnit::DegreesReaumur);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_roemer() const
        {
            return convert_from_base(TemperatureUnit::DegreesRoemer);
        }

        [[nodiscard]] static constexpr Temperature from_degrees_roemer(const un_scalar_t value)
        {
            return Temperature(value, TemperatureUnit::DegreesRoemer);
        }


        [[nodiscard]] constexpr un_scalar_t solar_temperatures() const
        {
            return convert_from_base(TemperatureUnit::SolarTemperatures);
        }

        [[nodiscard]] static constexpr Temperature from_solar_temperatures(const un_scalar_t value)
        {
            return Temperature(value, TemperatureUnit::SolarTemperatures);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, TemperatureUnit unit)
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

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const TemperatureUnit unit) const
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

        un_scalar_t value_;
    };
}
