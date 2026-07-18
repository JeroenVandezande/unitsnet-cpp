#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class TemperatureGradientUnit : std::uint16_t
    {
        KelvinsPerMeter,
        DegreesCelsiusPerMeter,
        DegreesFahrenheitPerFoot,
        DegreesCelsiusPerKilometer,
    };

    /// <summary></summary>
    class TemperatureGradient
    {
    public:
        constexpr explicit TemperatureGradient(
            double value,
            TemperatureGradientUnit unit = TemperatureGradientUnit::KelvinsPerMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(TemperatureGradientUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr TemperatureGradient operator+(TemperatureGradient other) const noexcept
        {
            return TemperatureGradient(value_ + other.value_);
        }

        [[nodiscard]] constexpr TemperatureGradient operator-(TemperatureGradient other) const noexcept
        {
            return TemperatureGradient(value_ - other.value_);
        }

        [[nodiscard]] constexpr TemperatureGradient operator*(double scalar) const noexcept
        {
            return TemperatureGradient(value_ * scalar);
        }

        [[nodiscard]] constexpr TemperatureGradient operator/(double scalar) const noexcept
        {
            return TemperatureGradient(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(TemperatureGradient other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(TemperatureGradient other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double kelvins_per_meter() const
        {
            return convert_from_base(TemperatureGradientUnit::KelvinsPerMeter);
        }

        [[nodiscard]] static constexpr TemperatureGradient from_kelvins_per_meter(double value)
        {
            return TemperatureGradient(value, TemperatureGradientUnit::KelvinsPerMeter);
        }


        [[nodiscard]] constexpr double degrees_celsius_per_meter() const
        {
            return convert_from_base(TemperatureGradientUnit::DegreesCelsiusPerMeter);
        }

        [[nodiscard]] static constexpr TemperatureGradient from_degrees_celsius_per_meter(double value)
        {
            return TemperatureGradient(value, TemperatureGradientUnit::DegreesCelsiusPerMeter);
        }


        [[nodiscard]] constexpr double degrees_fahrenheit_per_foot() const
        {
            return convert_from_base(TemperatureGradientUnit::DegreesFahrenheitPerFoot);
        }

        [[nodiscard]] static constexpr TemperatureGradient from_degrees_fahrenheit_per_foot(double value)
        {
            return TemperatureGradient(value, TemperatureGradientUnit::DegreesFahrenheitPerFoot);
        }


        [[nodiscard]] constexpr double degrees_celsius_per_kilometer() const
        {
            return convert_from_base(TemperatureGradientUnit::DegreesCelsiusPerKilometer);
        }

        [[nodiscard]] static constexpr TemperatureGradient from_degrees_celsius_per_kilometer(double value)
        {
            return TemperatureGradient(value, TemperatureGradientUnit::DegreesCelsiusPerKilometer);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, TemperatureGradientUnit unit)
        {
            switch (unit)
            {

            case TemperatureGradientUnit::KelvinsPerMeter:
                return value;

            case TemperatureGradientUnit::DegreesCelsiusPerMeter:
                return value;

            case TemperatureGradientUnit::DegreesFahrenheitPerFoot:
                return (value / 0.3048) * 5 / 9;

            case TemperatureGradientUnit::DegreesCelsiusPerKilometer:
                return value / 1e3;

            }

            throw std::invalid_argument("Unknown TemperatureGradient unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(TemperatureGradientUnit unit) const
        {
            switch (unit)
            {

            case TemperatureGradientUnit::KelvinsPerMeter:
                return value_;

            case TemperatureGradientUnit::DegreesCelsiusPerMeter:
                return value_;

            case TemperatureGradientUnit::DegreesFahrenheitPerFoot:
                return (value_ * 0.3048) * 9 / 5;

            case TemperatureGradientUnit::DegreesCelsiusPerKilometer:
                return value_ * 1e3;

            }

            throw std::invalid_argument("Unknown TemperatureGradient unit.");
        }

        double value_;
    };
}
