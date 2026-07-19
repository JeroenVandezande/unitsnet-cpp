#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ElectricFieldUnit : std::uint8_t
    {
        VoltsPerMeter,
    };

    /// <summary>An electric field is a force field that surrounds electric charges that attracts or repels other electric charges.</summary>
    class ElectricField : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricField(
            const un_scalar_t value,
            const ElectricFieldUnit unit = ElectricFieldUnit::VoltsPerMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
        
        [[nodiscard]] constexpr un_scalar_t stored_value() const noexcept override
        {
           return value_; 
        }
        
        [[nodiscard]] constexpr std::string_view quantity_name() const noexcept override
        {
           return "ElectricField"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case ElectricFieldUnit::VoltsPerMeter:
                return "VoltsPerMeter";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricFieldUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricField operator+(const ElectricField& other) const noexcept
        {
            return ElectricField(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricField operator-(const ElectricField& other)const noexcept
        {
            return ElectricField(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricField operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricField(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricField operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricField(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricField& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricField& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricField& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t volts_per_meter() const
        {
            return convert_from_base(ElectricFieldUnit::VoltsPerMeter);
        }

        [[nodiscard]] static constexpr ElectricField from_volts_per_meter(const un_scalar_t value)
        {
            return ElectricField(value, ElectricFieldUnit::VoltsPerMeter);
        }

        [[nodiscard]] static constexpr ElectricField from_invalid()
        {
            return ElectricField(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricFieldUnit unit)
        {
            switch (unit)
            {

            case ElectricFieldUnit::VoltsPerMeter:
                return value;

            }

            throw std::invalid_argument("Unknown ElectricField unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricFieldUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricFieldUnit::VoltsPerMeter:
                return base_value;

            }

            throw std::invalid_argument("Unknown ElectricField unit.");
        }

        un_scalar_t value_;
        ElectricFieldUnit value_unit_type_;       
    };
}
