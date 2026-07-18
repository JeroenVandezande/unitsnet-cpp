#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class PermeabilityUnit : std::uint16_t
    {
        HenriesPerMeter,
    };

    /// <summary>In electromagnetism, permeability is the measure of the ability of a material to support the formation of a magnetic field within itself.</summary>
    class Permeability
    {
    public:
        constexpr explicit Permeability(
            double value,
            PermeabilityUnit unit = PermeabilityUnit::HenriesPerMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(PermeabilityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Permeability operator+(Permeability other) const noexcept
        {
            return Permeability(value_ + other.value_);
        }

        [[nodiscard]] constexpr Permeability operator-(Permeability other) const noexcept
        {
            return Permeability(value_ - other.value_);
        }

        [[nodiscard]] constexpr Permeability operator*(double scalar) const noexcept
        {
            return Permeability(value_ * scalar);
        }

        [[nodiscard]] constexpr Permeability operator/(double scalar) const noexcept
        {
            return Permeability(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Permeability other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Permeability other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double henries_per_meter() const
        {
            return convert_from_base(PermeabilityUnit::HenriesPerMeter);
        }

        [[nodiscard]] static constexpr Permeability from_henries_per_meter(double value)
        {
            return Permeability(value, PermeabilityUnit::HenriesPerMeter);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, PermeabilityUnit unit)
        {
            switch (unit)
            {

            case PermeabilityUnit::HenriesPerMeter:
                return value;

            }

            throw std::invalid_argument("Unknown Permeability unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(PermeabilityUnit unit) const
        {
            switch (unit)
            {

            case PermeabilityUnit::HenriesPerMeter:
                return value_;

            }

            throw std::invalid_argument("Unknown Permeability unit.");
        }

        double value_;
    };
}
