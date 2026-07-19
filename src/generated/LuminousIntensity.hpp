#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class LuminousIntensityUnit : std::uint8_t
    {
        Candela,
    };

    /// <summary>In photometry, luminous intensity is a measure of the wavelength-weighted power emitted by a light source in a particular direction per unit solid angle, based on the luminosity function, a standardized model of the sensitivity of the human eye.</summary>
    class LuminousIntensity : public UnitsNetBase
    {
    public:
        constexpr explicit LuminousIntensity(
            const un_scalar_t value,
            const LuminousIntensityUnit unit = LuminousIntensityUnit::Candela)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const LuminousIntensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr LuminousIntensity operator+(const LuminousIntensity& other) const noexcept
        {
            return LuminousIntensity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr LuminousIntensity operator-(const LuminousIntensity& other)const noexcept
        {
            return LuminousIntensity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr LuminousIntensity operator*(const un_scalar_t scalar) const noexcept
        {
            return LuminousIntensity(base_value() * scalar);
        }

        [[nodiscard]] constexpr LuminousIntensity operator/(const un_scalar_t scalar) const noexcept
        {
            return LuminousIntensity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const LuminousIntensity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const LuminousIntensity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const LuminousIntensity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t candela() const
        {
            return convert_from_base(LuminousIntensityUnit::Candela);
        }

        [[nodiscard]] static constexpr LuminousIntensity from_candela(const un_scalar_t value)
        {
            return LuminousIntensity(value, LuminousIntensityUnit::Candela);
        }

        [[nodiscard]] static constexpr LuminousIntensity from_invalid()
        {
            return LuminousIntensity(false);
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
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case LuminousIntensityUnit::Candela:
                return base_value;

            }

            throw std::invalid_argument("Unknown LuminousIntensity unit.");
        }

        un_scalar_t value_;
        LuminousIntensityUnit value_unit_type_;       
    };
}
