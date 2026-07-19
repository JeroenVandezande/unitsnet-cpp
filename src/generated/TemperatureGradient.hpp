#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class TemperatureGradientUnit : std::uint8_t
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
            const un_scalar_t value,
            const TemperatureGradientUnit unit = TemperatureGradientUnit::KelvinsPerMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const TemperatureGradientUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr TemperatureGradient operator+(const TemperatureGradient other) const noexcept
        {
            return TemperatureGradient(value_ + other.value_);
        }

        [[nodiscard]] constexpr TemperatureGradient operator-(const TemperatureGradient other) const noexcept
        {
            return TemperatureGradient(value_ - other.value_);
        }

        [[nodiscard]] constexpr TemperatureGradient operator*(const un_scalar_t scalar) const noexcept
        {
            return TemperatureGradient(value_ * scalar);
        }

        [[nodiscard]] constexpr TemperatureGradient operator/(const un_scalar_t scalar) const noexcept
        {
            return TemperatureGradient(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const TemperatureGradient other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const TemperatureGradient other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t kelvins_per_meter() const
        {
            return convert_from_base(TemperatureGradientUnit::KelvinsPerMeter);
        }

        [[nodiscard]] static constexpr TemperatureGradient from_kelvins_per_meter(const un_scalar_t value)
        {
            return TemperatureGradient(value, TemperatureGradientUnit::KelvinsPerMeter);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_celsius_per_meter() const
        {
            return convert_from_base(TemperatureGradientUnit::DegreesCelsiusPerMeter);
        }

        [[nodiscard]] static constexpr TemperatureGradient from_degrees_celsius_per_meter(const un_scalar_t value)
        {
            return TemperatureGradient(value, TemperatureGradientUnit::DegreesCelsiusPerMeter);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_fahrenheit_per_foot() const
        {
            return convert_from_base(TemperatureGradientUnit::DegreesFahrenheitPerFoot);
        }

        [[nodiscard]] static constexpr TemperatureGradient from_degrees_fahrenheit_per_foot(const un_scalar_t value)
        {
            return TemperatureGradient(value, TemperatureGradientUnit::DegreesFahrenheitPerFoot);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_celsius_per_kilometer() const
        {
            return convert_from_base(TemperatureGradientUnit::DegreesCelsiusPerKilometer);
        }

        [[nodiscard]] static constexpr TemperatureGradient from_degrees_celsius_per_kilometer(const un_scalar_t value)
        {
            return TemperatureGradient(value, TemperatureGradientUnit::DegreesCelsiusPerKilometer);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, TemperatureGradientUnit unit)
        {
            switch (unit)
            {

            case TemperatureGradientUnit::KelvinsPerMeter:
                return value;

            case TemperatureGradientUnit::DegreesCelsiusPerMeter:
                return value;

            case TemperatureGradientUnit::DegreesFahrenheitPerFoot:
                return (value / static_cast<un_scalar_t>(0.3048)) * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(9);

            case TemperatureGradientUnit::DegreesCelsiusPerKilometer:
                return value / static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown TemperatureGradient unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const TemperatureGradientUnit unit) const
        {
            switch (unit)
            {

            case TemperatureGradientUnit::KelvinsPerMeter:
                return value_;

            case TemperatureGradientUnit::DegreesCelsiusPerMeter:
                return value_;

            case TemperatureGradientUnit::DegreesFahrenheitPerFoot:
                return (value_ * static_cast<un_scalar_t>(0.3048)) * static_cast<un_scalar_t>(9) / static_cast<un_scalar_t>(5);

            case TemperatureGradientUnit::DegreesCelsiusPerKilometer:
                return value_ * static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown TemperatureGradient unit.");
        }

        un_scalar_t value_;
    };
}
