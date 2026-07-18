#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class TemperatureDeltaUnit : std::uint16_t
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
    };

    /// <summary>Difference between two temperatures. The conversions are different than for Temperature.</summary>
    class TemperatureDelta
    {
    public:
        constexpr explicit TemperatureDelta(
            double value,
            TemperatureDeltaUnit unit = TemperatureDeltaUnit::Kelvins)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(TemperatureDeltaUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr TemperatureDelta operator+(TemperatureDelta other) const noexcept
        {
            return TemperatureDelta(value_ + other.value_);
        }

        [[nodiscard]] constexpr TemperatureDelta operator-(TemperatureDelta other) const noexcept
        {
            return TemperatureDelta(value_ - other.value_);
        }

        [[nodiscard]] constexpr TemperatureDelta operator*(double scalar) const noexcept
        {
            return TemperatureDelta(value_ * scalar);
        }

        [[nodiscard]] constexpr TemperatureDelta operator/(double scalar) const noexcept
        {
            return TemperatureDelta(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(TemperatureDelta other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(TemperatureDelta other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double kelvins() const
        {
            return convert_from_base(TemperatureDeltaUnit::Kelvins);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_kelvins(double value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::Kelvins);
        }


        [[nodiscard]] constexpr double degrees_celsius() const
        {
            return convert_from_base(TemperatureDeltaUnit::DegreesCelsius);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_degrees_celsius(double value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::DegreesCelsius);
        }


        [[nodiscard]] constexpr double millidegrees_celsius() const
        {
            return convert_from_base(TemperatureDeltaUnit::MillidegreesCelsius);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_millidegrees_celsius(double value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::MillidegreesCelsius);
        }


        [[nodiscard]] constexpr double degrees_delisle() const
        {
            return convert_from_base(TemperatureDeltaUnit::DegreesDelisle);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_degrees_delisle(double value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::DegreesDelisle);
        }


        [[nodiscard]] constexpr double degrees_fahrenheit() const
        {
            return convert_from_base(TemperatureDeltaUnit::DegreesFahrenheit);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_degrees_fahrenheit(double value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::DegreesFahrenheit);
        }


        [[nodiscard]] constexpr double degrees_newton() const
        {
            return convert_from_base(TemperatureDeltaUnit::DegreesNewton);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_degrees_newton(double value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::DegreesNewton);
        }


        [[nodiscard]] constexpr double degrees_rankine() const
        {
            return convert_from_base(TemperatureDeltaUnit::DegreesRankine);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_degrees_rankine(double value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::DegreesRankine);
        }


        [[nodiscard]] constexpr double degrees_reaumur() const
        {
            return convert_from_base(TemperatureDeltaUnit::DegreesReaumur);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_degrees_reaumur(double value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::DegreesReaumur);
        }


        [[nodiscard]] constexpr double degrees_roemer() const
        {
            return convert_from_base(TemperatureDeltaUnit::DegreesRoemer);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_degrees_roemer(double value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::DegreesRoemer);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, TemperatureDeltaUnit unit)
        {
            switch (unit)
            {

            case TemperatureDeltaUnit::Kelvins:
                return value;

            case TemperatureDeltaUnit::DegreesCelsius:
                return value;

            case TemperatureDeltaUnit::MillidegreesCelsius:
                return (value * 1e-3);

            case TemperatureDeltaUnit::DegreesDelisle:
                return value * -2 / 3;

            case TemperatureDeltaUnit::DegreesFahrenheit:
                return value * 5 / 9;

            case TemperatureDeltaUnit::DegreesNewton:
                return value * 100 / 33;

            case TemperatureDeltaUnit::DegreesRankine:
                return value * 5 / 9;

            case TemperatureDeltaUnit::DegreesReaumur:
                return value * 5 / 4;

            case TemperatureDeltaUnit::DegreesRoemer:
                return value * 40 / 21;

            }

            throw std::invalid_argument("Unknown TemperatureDelta unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(TemperatureDeltaUnit unit) const
        {
            switch (unit)
            {

            case TemperatureDeltaUnit::Kelvins:
                return value_;

            case TemperatureDeltaUnit::DegreesCelsius:
                return value_;

            case TemperatureDeltaUnit::MillidegreesCelsius:
                return (value_) / 1e-3;

            case TemperatureDeltaUnit::DegreesDelisle:
                return value_ * -3 / 2;

            case TemperatureDeltaUnit::DegreesFahrenheit:
                return value_ * 9 / 5;

            case TemperatureDeltaUnit::DegreesNewton:
                return value_ * 33 / 100;

            case TemperatureDeltaUnit::DegreesRankine:
                return value_ * 9 / 5;

            case TemperatureDeltaUnit::DegreesReaumur:
                return value_ * 4 / 5;

            case TemperatureDeltaUnit::DegreesRoemer:
                return value_ * 21 / 40;

            }

            throw std::invalid_argument("Unknown TemperatureDelta unit.");
        }

        double value_;
    };
}
