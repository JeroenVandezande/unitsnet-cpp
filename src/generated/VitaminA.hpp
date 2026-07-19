#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class VitaminAUnit : std::uint8_t
    {
        InternationalUnits,
    };

    /// <summary>Vitamin A: 1 IU is the biological equivalent of 0.3 µg retinol, or of 0.6 µg beta-carotene.</summary>
    class VitaminA : public UnitsNetBase
    {
    public:
        constexpr explicit VitaminA(
            const un_scalar_t value,
            const VitaminAUnit unit = VitaminAUnit::InternationalUnits)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == VitaminAUnit::InternationalUnits)
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

        [[nodiscard]] constexpr un_scalar_t value(const VitaminAUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr VitaminA operator+(const VitaminA& other) const noexcept
        {
            return VitaminA(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr VitaminA operator-(const VitaminA& other)const noexcept
        {
            return VitaminA(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr VitaminA operator*(const un_scalar_t scalar) const noexcept
        {
            return VitaminA(base_value() * scalar);
        }

        [[nodiscard]] constexpr VitaminA operator/(const un_scalar_t scalar) const noexcept
        {
            return VitaminA(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const VitaminA& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const VitaminA& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const VitaminA& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t international_units() const
        {
            return convert_from_base(VitaminAUnit::InternationalUnits);
        }

        [[nodiscard]] static constexpr VitaminA from_international_units(const un_scalar_t value)
        {
            return VitaminA(value, VitaminAUnit::InternationalUnits);
        }


        [[nodiscard]] static constexpr VitaminA from_invalid()
        {
            return VitaminA(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, VitaminAUnit unit)
        {
            switch (unit)
            {

            case VitaminAUnit::InternationalUnits:
                return value;

            }

            throw std::invalid_argument("Unknown VitaminA unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const VitaminAUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case VitaminAUnit::InternationalUnits:
                return base_value_;

            }

            throw std::invalid_argument("Unknown VitaminA unit.");
        }

        un_scalar_t value_;
        VitaminAUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
