#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class IlluminanceUnit : std::uint16_t
    {
        Lux,
        Millilux,
        Kilolux,
        Megalux,
    };

    /// <summary>In photometry, illuminance is the total luminous flux incident on a surface, per unit area.</summary>
    class Illuminance
    {
    public:
        constexpr explicit Illuminance(
            double value,
            IlluminanceUnit unit = IlluminanceUnit::Lux)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(IlluminanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Illuminance operator+(Illuminance other) const noexcept
        {
            return Illuminance(value_ + other.value_);
        }

        [[nodiscard]] constexpr Illuminance operator-(Illuminance other) const noexcept
        {
            return Illuminance(value_ - other.value_);
        }

        [[nodiscard]] constexpr Illuminance operator*(double scalar) const noexcept
        {
            return Illuminance(value_ * scalar);
        }

        [[nodiscard]] constexpr Illuminance operator/(double scalar) const noexcept
        {
            return Illuminance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Illuminance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Illuminance other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double lux() const
        {
            return convert_from_base(IlluminanceUnit::Lux);
        }

        [[nodiscard]] static constexpr Illuminance from_lux(double value)
        {
            return Illuminance(value, IlluminanceUnit::Lux);
        }


        [[nodiscard]] constexpr double millilux() const
        {
            return convert_from_base(IlluminanceUnit::Millilux);
        }

        [[nodiscard]] static constexpr Illuminance from_millilux(double value)
        {
            return Illuminance(value, IlluminanceUnit::Millilux);
        }


        [[nodiscard]] constexpr double kilolux() const
        {
            return convert_from_base(IlluminanceUnit::Kilolux);
        }

        [[nodiscard]] static constexpr Illuminance from_kilolux(double value)
        {
            return Illuminance(value, IlluminanceUnit::Kilolux);
        }


        [[nodiscard]] constexpr double megalux() const
        {
            return convert_from_base(IlluminanceUnit::Megalux);
        }

        [[nodiscard]] static constexpr Illuminance from_megalux(double value)
        {
            return Illuminance(value, IlluminanceUnit::Megalux);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, IlluminanceUnit unit)
        {
            switch (unit)
            {

            case IlluminanceUnit::Lux:
                return value;

            case IlluminanceUnit::Millilux:
                return (value * 1e-3);

            case IlluminanceUnit::Kilolux:
                return (value * 1e3);

            case IlluminanceUnit::Megalux:
                return (value * 1e6);

            }

            throw std::invalid_argument("Unknown Illuminance unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(IlluminanceUnit unit) const
        {
            switch (unit)
            {

            case IlluminanceUnit::Lux:
                return value_;

            case IlluminanceUnit::Millilux:
                return (value_) / 1e-3;

            case IlluminanceUnit::Kilolux:
                return (value_) / 1e3;

            case IlluminanceUnit::Megalux:
                return (value_) / 1e6;

            }

            throw std::invalid_argument("Unknown Illuminance unit.");
        }

        double value_;
    };
}
