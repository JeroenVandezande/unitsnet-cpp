#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class PermeabilityUnit : std::uint8_t
    {
        HenriesPerMeter,
    };

    /// <summary>In electromagnetism, permeability is the measure of the ability of a material to support the formation of a magnetic field within itself.</summary>
    class Permeability : public UnitsNetBase
    {
    public:
        constexpr explicit Permeability(
            const un_scalar_t value,
            const PermeabilityUnit unit = PermeabilityUnit::HenriesPerMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == PermeabilityUnit::HenriesPerMeter)
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

        [[nodiscard]] constexpr un_scalar_t value(const PermeabilityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Permeability operator+(const Permeability& other) const noexcept
        {
            return Permeability(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Permeability operator-(const Permeability& other)const noexcept
        {
            return Permeability(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Permeability operator*(const un_scalar_t scalar) const noexcept
        {
            return Permeability(base_value() * scalar);
        }

        [[nodiscard]] constexpr Permeability operator/(const un_scalar_t scalar) const noexcept
        {
            return Permeability(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Permeability& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Permeability& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Permeability& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t henries_per_meter() const
        {
            return convert_from_base(PermeabilityUnit::HenriesPerMeter);
        }

        [[nodiscard]] static constexpr Permeability from_henries_per_meter(const un_scalar_t value)
        {
            return Permeability(value, PermeabilityUnit::HenriesPerMeter);
        }


        [[nodiscard]] static constexpr Permeability from_invalid()
        {
            return Permeability(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, PermeabilityUnit unit)
        {
            switch (unit)
            {

            case PermeabilityUnit::HenriesPerMeter:
                return value;

            }

            throw std::invalid_argument("Unknown Permeability unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const PermeabilityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case PermeabilityUnit::HenriesPerMeter:
                return base_value_;

            }

            throw std::invalid_argument("Unknown Permeability unit.");
        }

        un_scalar_t value_;
        PermeabilityUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
