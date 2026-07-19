#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class ElectricFieldUnit : std::uint8_t
    {
        VoltsPerMeter,
    };

    /// <summary>An electric field is a force field that surrounds electric charges that attracts or repels other electric charges.</summary>
    class ElectricField
    {
    public:
        constexpr explicit ElectricField(
            const un_scalar_t value,
            const ElectricFieldUnit unit = ElectricFieldUnit::VoltsPerMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricFieldUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricField operator+(const ElectricField other) const noexcept
        {
            return ElectricField(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricField operator-(const ElectricField other) const noexcept
        {
            return ElectricField(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricField operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricField(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricField operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricField(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricField other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const ElectricField other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t volts_per_meter() const
        {
            return convert_from_base(ElectricFieldUnit::VoltsPerMeter);
        }

        [[nodiscard]] static constexpr ElectricField from_volts_per_meter(const un_scalar_t value)
        {
            return ElectricField(value, ElectricFieldUnit::VoltsPerMeter);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricFieldUnit unit)
        {
            switch (unit)
            {

            case ElectricFieldUnit::VoltsPerMeter:
                return value;

            }

            throw std::invalid_argument("Unknown ElectricField unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricFieldUnit unit) const
        {
            switch (unit)
            {

            case ElectricFieldUnit::VoltsPerMeter:
                return value_;

            }

            throw std::invalid_argument("Unknown ElectricField unit.");
        }

        un_scalar_t value_;
    };
}
