#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class LuminousFluxUnit : std::uint8_t
    {
        Lumens,
    };

    /// <summary>In photometry, luminous flux or luminous power is the measure of the perceived power of light.</summary>
    class LuminousFlux : public UnitsNetBase
    {
    public:
        constexpr explicit LuminousFlux(
            const un_scalar_t value,
            const LuminousFluxUnit unit = LuminousFluxUnit::Lumens)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == LuminousFluxUnit::Lumens)
            {
                base_value_ = value;
                base_value_exists_ = true;
            }
            else
            {
                base_value_ = 0;
                base_value_exists_ = false;
            }
        }
        
        constexpr void create_base_value_if_needed() const noexcept
        {
            if(!base_value_exists_)
            {
                base_value_ = convert_to_base(value_, value_unit_type_);
                base_value_exists_ = true;
            }
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            create_base_value_if_needed();    
            return base_value_;    
        }

        [[nodiscard]] constexpr un_scalar_t value(const LuminousFluxUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr LuminousFlux operator+(const LuminousFlux& other) const noexcept
        {
            return LuminousFlux(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr LuminousFlux operator-(const LuminousFlux& other)const noexcept
        {
            return LuminousFlux(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr LuminousFlux operator*(const un_scalar_t scalar) const noexcept
        {
            return LuminousFlux(base_value() * scalar);
        }

        [[nodiscard]] constexpr LuminousFlux operator/(const un_scalar_t scalar) const noexcept
        {
            return LuminousFlux(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const LuminousFlux& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const LuminousFlux& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const LuminousFlux& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t lumens() const
        {
            return convert_from_base(LuminousFluxUnit::Lumens);
        }

        [[nodiscard]] static constexpr LuminousFlux from_lumens(const un_scalar_t value)
        {
            return LuminousFlux(value, LuminousFluxUnit::Lumens);
        }


        [[nodiscard]] static constexpr LuminousFlux from_invalid()
        {
            return LuminousFlux(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, LuminousFluxUnit unit)
        {
            switch (unit)
            {

            case LuminousFluxUnit::Lumens:
                return value;

            }

            throw std::invalid_argument("Unknown LuminousFlux unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const LuminousFluxUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case LuminousFluxUnit::Lumens:
                return base_value_;

            }

            throw std::invalid_argument("Unknown LuminousFlux unit.");
        }

        un_scalar_t value_;
        LuminousFluxUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
