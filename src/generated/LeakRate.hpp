#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class LeakRateUnit : std::uint16_t
    {
        PascalCubicMetersPerSecond,
        MillibarLitersPerSecond,
        TorrLitersPerSecond,
        AtmCubicCentimetersPerSecond,
    };

    /// <summary>A leakage rate of QL = 1 Pa-m³/s is given when the pressure in a closed, evacuated container with a volume of 1 m³ rises by 1 Pa per second or when the pressure in the container drops by 1 Pa in the event of overpressure.</summary>
    class LeakRate
    {
    public:
        constexpr explicit LeakRate(
            double value,
            LeakRateUnit unit = LeakRateUnit::PascalCubicMetersPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(LeakRateUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr LeakRate operator+(LeakRate other) const noexcept
        {
            return LeakRate(value_ + other.value_);
        }

        [[nodiscard]] constexpr LeakRate operator-(LeakRate other) const noexcept
        {
            return LeakRate(value_ - other.value_);
        }

        [[nodiscard]] constexpr LeakRate operator*(double scalar) const noexcept
        {
            return LeakRate(value_ * scalar);
        }

        [[nodiscard]] constexpr LeakRate operator/(double scalar) const noexcept
        {
            return LeakRate(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(LeakRate other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(LeakRate other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double pascal_cubic_meters_per_second() const
        {
            return convert_from_base(LeakRateUnit::PascalCubicMetersPerSecond);
        }

        [[nodiscard]] static constexpr LeakRate from_pascal_cubic_meters_per_second(double value)
        {
            return LeakRate(value, LeakRateUnit::PascalCubicMetersPerSecond);
        }


        [[nodiscard]] constexpr double millibar_liters_per_second() const
        {
            return convert_from_base(LeakRateUnit::MillibarLitersPerSecond);
        }

        [[nodiscard]] static constexpr LeakRate from_millibar_liters_per_second(double value)
        {
            return LeakRate(value, LeakRateUnit::MillibarLitersPerSecond);
        }


        [[nodiscard]] constexpr double torr_liters_per_second() const
        {
            return convert_from_base(LeakRateUnit::TorrLitersPerSecond);
        }

        [[nodiscard]] static constexpr LeakRate from_torr_liters_per_second(double value)
        {
            return LeakRate(value, LeakRateUnit::TorrLitersPerSecond);
        }


        [[nodiscard]] constexpr double atm_cubic_centimeters_per_second() const
        {
            return convert_from_base(LeakRateUnit::AtmCubicCentimetersPerSecond);
        }

        [[nodiscard]] static constexpr LeakRate from_atm_cubic_centimeters_per_second(double value)
        {
            return LeakRate(value, LeakRateUnit::AtmCubicCentimetersPerSecond);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, LeakRateUnit unit)
        {
            switch (unit)
            {

            case LeakRateUnit::PascalCubicMetersPerSecond:
                return value;

            case LeakRateUnit::MillibarLitersPerSecond:
                return value / 10;

            case LeakRateUnit::TorrLitersPerSecond:
                return value / 7.5;

            case LeakRateUnit::AtmCubicCentimetersPerSecond:
                return value / (1e6 / 101325);

            }

            throw std::invalid_argument("Unknown LeakRate unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(LeakRateUnit unit) const
        {
            switch (unit)
            {

            case LeakRateUnit::PascalCubicMetersPerSecond:
                return value_;

            case LeakRateUnit::MillibarLitersPerSecond:
                return value_ * 10;

            case LeakRateUnit::TorrLitersPerSecond:
                return value_ * 7.5;

            case LeakRateUnit::AtmCubicCentimetersPerSecond:
                return value_ * (1e6 / 101325);

            }

            throw std::invalid_argument("Unknown LeakRate unit.");
        }

        double value_;
    };
}
