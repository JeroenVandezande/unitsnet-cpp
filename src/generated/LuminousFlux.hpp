#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class LuminousFluxUnit : std::uint16_t
    {
        Lumens,
    };

    /// <summary>In photometry, luminous flux or luminous power is the measure of the perceived power of light.</summary>
    class LuminousFlux
    {
    public:
        constexpr explicit LuminousFlux(
            double value,
            LuminousFluxUnit unit = LuminousFluxUnit::Lumens)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(LuminousFluxUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr LuminousFlux operator+(LuminousFlux other) const noexcept
        {
            return LuminousFlux(value_ + other.value_);
        }

        [[nodiscard]] constexpr LuminousFlux operator-(LuminousFlux other) const noexcept
        {
            return LuminousFlux(value_ - other.value_);
        }

        [[nodiscard]] constexpr LuminousFlux operator*(double scalar) const noexcept
        {
            return LuminousFlux(value_ * scalar);
        }

        [[nodiscard]] constexpr LuminousFlux operator/(double scalar) const noexcept
        {
            return LuminousFlux(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(LuminousFlux other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(LuminousFlux other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double lumens() const
        {
            return convert_from_base(LuminousFluxUnit::Lumens);
        }

        [[nodiscard]] static constexpr LuminousFlux from_lumens(double value)
        {
            return LuminousFlux(value, LuminousFluxUnit::Lumens);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, LuminousFluxUnit unit)
        {
            switch (unit)
            {

            case LuminousFluxUnit::Lumens:
                return value;

            }

            throw std::invalid_argument("Unknown LuminousFlux unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(LuminousFluxUnit unit) const
        {
            switch (unit)
            {

            case LuminousFluxUnit::Lumens:
                return value_;

            }

            throw std::invalid_argument("Unknown LuminousFlux unit.");
        }

        double value_;
    };
}
