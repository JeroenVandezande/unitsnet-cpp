#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class LuminousIntensityUnit : std::uint8_t
    {
        Candela,
    };

    /// <summary>In photometry, luminous intensity is a measure of the wavelength-weighted power emitted by a light source in a particular direction per unit solid angle, based on the luminosity function, a standardized model of the sensitivity of the human eye.</summary>
    class LuminousIntensity
    {
    public:
        constexpr explicit LuminousIntensity(
            const un_scalar_t value,
            const LuminousIntensityUnit unit = LuminousIntensityUnit::Candela)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const LuminousIntensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr LuminousIntensity operator+(const LuminousIntensity other) const noexcept
        {
            return LuminousIntensity(value_ + other.value_);
        }

        [[nodiscard]] constexpr LuminousIntensity operator-(const LuminousIntensity other) const noexcept
        {
            return LuminousIntensity(value_ - other.value_);
        }

        [[nodiscard]] constexpr LuminousIntensity operator*(const un_scalar_t scalar) const noexcept
        {
            return LuminousIntensity(value_ * scalar);
        }

        [[nodiscard]] constexpr LuminousIntensity operator/(const un_scalar_t scalar) const noexcept
        {
            return LuminousIntensity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const LuminousIntensity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const LuminousIntensity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t candela() const
        {
            return convert_from_base(LuminousIntensityUnit::Candela);
        }

        [[nodiscard]] static constexpr LuminousIntensity from_candela(const un_scalar_t value)
        {
            return LuminousIntensity(value, LuminousIntensityUnit::Candela);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, LuminousIntensityUnit unit)
        {
            switch (unit)
            {

            case LuminousIntensityUnit::Candela:
                return value;

            }

            throw std::invalid_argument("Unknown LuminousIntensity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const LuminousIntensityUnit unit) const
        {
            switch (unit)
            {

            case LuminousIntensityUnit::Candela:
                return value_;

            }

            throw std::invalid_argument("Unknown LuminousIntensity unit.");
        }

        un_scalar_t value_;
    };
}
