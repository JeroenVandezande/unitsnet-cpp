#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class SolidAngleUnit : std::uint8_t
    {
        Steradians,
    };

    /// <summary>In geometry, a solid angle is the two-dimensional angle in three-dimensional space that an object subtends at a point.</summary>
    class SolidAngle : public UnitsNetBase
    {
    public:
        constexpr explicit SolidAngle(
            const un_scalar_t value,
            const SolidAngleUnit unit = SolidAngleUnit::Steradians)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == SolidAngleUnit::Steradians)
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
            if(base_value_exists_)
            {
                return;
            }
            else
            {
                base_value_ = convert_to_base(value_, value_unit_type_);
                base_value_exists_ = true;
                return;
            }
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            create_base_value_if_needed();    
            return base_value_;    
        }

        [[nodiscard]] constexpr un_scalar_t value(const SolidAngleUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr SolidAngle operator+(const SolidAngle& other) const noexcept
        {
            return SolidAngle(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr SolidAngle operator-(const SolidAngle& other)const noexcept
        {
            return SolidAngle(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr SolidAngle operator*(const un_scalar_t scalar) const noexcept
        {
            return SolidAngle(base_value() * scalar);
        }

        [[nodiscard]] constexpr SolidAngle operator/(const un_scalar_t scalar) const noexcept
        {
            return SolidAngle(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const SolidAngle& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const SolidAngle& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const SolidAngle& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t steradians() const
        {
            return convert_from_base(SolidAngleUnit::Steradians);
        }

        [[nodiscard]] static constexpr SolidAngle from_steradians(const un_scalar_t value)
        {
            return SolidAngle(value, SolidAngleUnit::Steradians);
        }


        [[nodiscard]] static constexpr SolidAngle from_invalid()
        {
            return SolidAngle(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, SolidAngleUnit unit)
        {
            switch (unit)
            {

            case SolidAngleUnit::Steradians:
                return value;

            }

            throw std::invalid_argument("Unknown SolidAngle unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const SolidAngleUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case SolidAngleUnit::Steradians:
                return base_value_;

            }

            throw std::invalid_argument("Unknown SolidAngle unit.");
        }

        un_scalar_t value_;
        SolidAngleUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
