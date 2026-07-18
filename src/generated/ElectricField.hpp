#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricFieldUnit : std::uint16_t
    {
        VoltsPerMeter,
    };

    /// <summary>An electric field is a force field that surrounds electric charges that attracts or repels other electric charges.</summary>
    class ElectricField
    {
    public:
        constexpr explicit ElectricField(
            double value,
            ElectricFieldUnit unit = ElectricFieldUnit::VoltsPerMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricFieldUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricField operator+(ElectricField other) const noexcept
        {
            return ElectricField(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricField operator-(ElectricField other) const noexcept
        {
            return ElectricField(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricField operator*(double scalar) const noexcept
        {
            return ElectricField(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricField operator/(double scalar) const noexcept
        {
            return ElectricField(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricField other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricField other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double volts_per_meter() const
        {
            return convert_from_base(ElectricFieldUnit::VoltsPerMeter);
        }

        [[nodiscard]] static constexpr ElectricField from_volts_per_meter(double value)
        {
            return ElectricField(value, ElectricFieldUnit::VoltsPerMeter);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricFieldUnit unit)
        {
            switch (unit)
            {

            case ElectricFieldUnit::VoltsPerMeter:
                return value;

            }

            throw std::invalid_argument("Unknown ElectricField unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricFieldUnit unit) const
        {
            switch (unit)
            {

            case ElectricFieldUnit::VoltsPerMeter:
                return value_;

            }

            throw std::invalid_argument("Unknown ElectricField unit.");
        }

        double value_;
    };
}
