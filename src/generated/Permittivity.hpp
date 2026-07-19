#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class PermittivityUnit : std::uint8_t
    {
        FaradsPerMeter,
    };

    /// <summary>In electromagnetism, permittivity is the measure of resistance that is encountered when forming an electric field in a particular medium.</summary>
    class Permittivity
    {
    public:
        constexpr explicit Permittivity(
            const un_scalar_t value,
            const PermittivityUnit unit = PermittivityUnit::FaradsPerMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const PermittivityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Permittivity operator+(const Permittivity other) const noexcept
        {
            return Permittivity(value_ + other.value_);
        }

        [[nodiscard]] constexpr Permittivity operator-(const Permittivity other) const noexcept
        {
            return Permittivity(value_ - other.value_);
        }

        [[nodiscard]] constexpr Permittivity operator*(const un_scalar_t scalar) const noexcept
        {
            return Permittivity(value_ * scalar);
        }

        [[nodiscard]] constexpr Permittivity operator/(const un_scalar_t scalar) const noexcept
        {
            return Permittivity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Permittivity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Permittivity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t farads_per_meter() const
        {
            return convert_from_base(PermittivityUnit::FaradsPerMeter);
        }

        [[nodiscard]] static constexpr Permittivity from_farads_per_meter(const un_scalar_t value)
        {
            return Permittivity(value, PermittivityUnit::FaradsPerMeter);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, PermittivityUnit unit)
        {
            switch (unit)
            {

            case PermittivityUnit::FaradsPerMeter:
                return value;

            }

            throw std::invalid_argument("Unknown Permittivity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const PermittivityUnit unit) const
        {
            switch (unit)
            {

            case PermittivityUnit::FaradsPerMeter:
                return value_;

            }

            throw std::invalid_argument("Unknown Permittivity unit.");
        }

        un_scalar_t value_;
    };
}
