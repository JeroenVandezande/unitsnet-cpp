#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class LuminousIntensityUnit : std::uint16_t
    {
        Candela,
    };

    /// <summary>In photometry, luminous intensity is a measure of the wavelength-weighted power emitted by a light source in a particular direction per unit solid angle, based on the luminosity function, a standardized model of the sensitivity of the human eye.</summary>
    class LuminousIntensity
    {
    public:
        constexpr explicit LuminousIntensity(
            double value,
            LuminousIntensityUnit unit = LuminousIntensityUnit::Candela)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(LuminousIntensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr LuminousIntensity operator+(LuminousIntensity other) const noexcept
        {
            return LuminousIntensity(value_ + other.value_);
        }

        [[nodiscard]] constexpr LuminousIntensity operator-(LuminousIntensity other) const noexcept
        {
            return LuminousIntensity(value_ - other.value_);
        }

        [[nodiscard]] constexpr LuminousIntensity operator*(double scalar) const noexcept
        {
            return LuminousIntensity(value_ * scalar);
        }

        [[nodiscard]] constexpr LuminousIntensity operator/(double scalar) const noexcept
        {
            return LuminousIntensity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(LuminousIntensity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(LuminousIntensity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double candela() const
        {
            return convert_from_base(LuminousIntensityUnit::Candela);
        }

        [[nodiscard]] static constexpr LuminousIntensity from_candela(double value)
        {
            return LuminousIntensity(value, LuminousIntensityUnit::Candela);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, LuminousIntensityUnit unit)
        {
            switch (unit)
            {

            case LuminousIntensityUnit::Candela:
                return value;

            }

            throw std::invalid_argument("Unknown LuminousIntensity unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(LuminousIntensityUnit unit) const
        {
            switch (unit)
            {

            case LuminousIntensityUnit::Candela:
                return value_;

            }

            throw std::invalid_argument("Unknown LuminousIntensity unit.");
        }

        double value_;
    };
}
