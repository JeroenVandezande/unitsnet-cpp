#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ThermalResistanceUnit : std::uint8_t
    {
        KelvinsPerWatt,
        DegreesCelsiusPerWatt,
    };

    /// <summary>Thermal resistance (R) measures the opposition to the heat current in a material or system. It is measured in units of kelvins per watt (K/W) and indicates how much temperature difference (in kelvins) is required to transfer a unit of heat current (in watts) through the material or object. It is essential to optimize the building insulation, evaluate the efficiency of electronic devices, and enhance the performance of heat sinks in various applications.</summary>
    class ThermalResistance : public UnitsNetBase
    {
    public:
        constexpr explicit ThermalResistance(
            const un_scalar_t value,
            const ThermalResistanceUnit unit = ThermalResistanceUnit::KelvinsPerWatt)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == ThermalResistanceUnit::KelvinsPerWatt)
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

        [[nodiscard]] constexpr un_scalar_t value(const ThermalResistanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ThermalResistance operator+(const ThermalResistance& other) const noexcept
        {
            return ThermalResistance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ThermalResistance operator-(const ThermalResistance& other)const noexcept
        {
            return ThermalResistance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ThermalResistance operator*(const un_scalar_t scalar) const noexcept
        {
            return ThermalResistance(base_value() * scalar);
        }

        [[nodiscard]] constexpr ThermalResistance operator/(const un_scalar_t scalar) const noexcept
        {
            return ThermalResistance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ThermalResistance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ThermalResistance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ThermalResistance& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t kelvins_per_watt() const
        {
            return convert_from_base(ThermalResistanceUnit::KelvinsPerWatt);
        }

        [[nodiscard]] static constexpr ThermalResistance from_kelvins_per_watt(const un_scalar_t value)
        {
            return ThermalResistance(value, ThermalResistanceUnit::KelvinsPerWatt);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_celsius_per_watt() const
        {
            return convert_from_base(ThermalResistanceUnit::DegreesCelsiusPerWatt);
        }

        [[nodiscard]] static constexpr ThermalResistance from_degrees_celsius_per_watt(const un_scalar_t value)
        {
            return ThermalResistance(value, ThermalResistanceUnit::DegreesCelsiusPerWatt);
        }


        [[nodiscard]] static constexpr ThermalResistance from_invalid()
        {
            return ThermalResistance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ThermalResistanceUnit unit)
        {
            switch (unit)
            {

            case ThermalResistanceUnit::KelvinsPerWatt:
                return value;

            case ThermalResistanceUnit::DegreesCelsiusPerWatt:
                return value;

            }

            throw std::invalid_argument("Unknown ThermalResistance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ThermalResistanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case ThermalResistanceUnit::KelvinsPerWatt:
                return base_value_;

            case ThermalResistanceUnit::DegreesCelsiusPerWatt:
                return base_value_;

            }

            throw std::invalid_argument("Unknown ThermalResistance unit.");
        }

        un_scalar_t value_;
        ThermalResistanceUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
