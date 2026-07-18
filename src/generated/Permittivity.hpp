#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class PermittivityUnit : std::uint16_t
    {
        FaradsPerMeter,
    };

    /// <summary>In electromagnetism, permittivity is the measure of resistance that is encountered when forming an electric field in a particular medium.</summary>
    class Permittivity
    {
    public:
        constexpr explicit Permittivity(
            double value,
            PermittivityUnit unit = PermittivityUnit::FaradsPerMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(PermittivityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Permittivity operator+(Permittivity other) const noexcept
        {
            return Permittivity(value_ + other.value_);
        }

        [[nodiscard]] constexpr Permittivity operator-(Permittivity other) const noexcept
        {
            return Permittivity(value_ - other.value_);
        }

        [[nodiscard]] constexpr Permittivity operator*(double scalar) const noexcept
        {
            return Permittivity(value_ * scalar);
        }

        [[nodiscard]] constexpr Permittivity operator/(double scalar) const noexcept
        {
            return Permittivity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Permittivity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Permittivity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double farads_per_meter() const
        {
            return convert_from_base(PermittivityUnit::FaradsPerMeter);
        }

        [[nodiscard]] static constexpr Permittivity from_farads_per_meter(double value)
        {
            return Permittivity(value, PermittivityUnit::FaradsPerMeter);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, PermittivityUnit unit)
        {
            switch (unit)
            {

            case PermittivityUnit::FaradsPerMeter:
                return value;

            }

            throw std::invalid_argument("Unknown Permittivity unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(PermittivityUnit unit) const
        {
            switch (unit)
            {

            case PermittivityUnit::FaradsPerMeter:
                return value_;

            }

            throw std::invalid_argument("Unknown Permittivity unit.");
        }

        double value_;
    };
}
