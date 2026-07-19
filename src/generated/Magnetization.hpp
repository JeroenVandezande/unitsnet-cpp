#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class MagnetizationUnit : std::uint8_t
    {
        AmperesPerMeter,
    };

    /// <summary>In classical electromagnetism, magnetization is the vector field that expresses the density of permanent or induced magnetic dipole moments in a magnetic material.</summary>
    class Magnetization : public UnitsNetBase
    {
    public:
        constexpr explicit Magnetization(
            const un_scalar_t value,
            const MagnetizationUnit unit = MagnetizationUnit::AmperesPerMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == MagnetizationUnit::AmperesPerMeter)
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

        [[nodiscard]] constexpr un_scalar_t value(const MagnetizationUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Magnetization operator+(const Magnetization& other) const noexcept
        {
            return Magnetization(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Magnetization operator-(const Magnetization& other)const noexcept
        {
            return Magnetization(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Magnetization operator*(const un_scalar_t scalar) const noexcept
        {
            return Magnetization(base_value() * scalar);
        }

        [[nodiscard]] constexpr Magnetization operator/(const un_scalar_t scalar) const noexcept
        {
            return Magnetization(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Magnetization& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Magnetization& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Magnetization& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t amperes_per_meter() const
        {
            return convert_from_base(MagnetizationUnit::AmperesPerMeter);
        }

        [[nodiscard]] static constexpr Magnetization from_amperes_per_meter(const un_scalar_t value)
        {
            return Magnetization(value, MagnetizationUnit::AmperesPerMeter);
        }


        [[nodiscard]] static constexpr Magnetization from_invalid()
        {
            return Magnetization(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MagnetizationUnit unit)
        {
            switch (unit)
            {

            case MagnetizationUnit::AmperesPerMeter:
                return value;

            }

            throw std::invalid_argument("Unknown Magnetization unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MagnetizationUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case MagnetizationUnit::AmperesPerMeter:
                return base_value_;

            }

            throw std::invalid_argument("Unknown Magnetization unit.");
        }

        un_scalar_t value_;
        MagnetizationUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
