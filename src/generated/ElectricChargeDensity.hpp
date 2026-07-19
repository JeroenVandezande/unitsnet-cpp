#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ElectricChargeDensityUnit : std::uint8_t
    {
        CoulombsPerCubicMeter,
    };

    /// <summary>In electromagnetism, charge density is a measure of the amount of electric charge per volume.</summary>
    class ElectricChargeDensity : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricChargeDensity(
            const un_scalar_t value,
            const ElectricChargeDensityUnit unit = ElectricChargeDensityUnit::CoulombsPerCubicMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == ElectricChargeDensityUnit::CoulombsPerCubicMeter)
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

        [[nodiscard]] constexpr un_scalar_t value(const ElectricChargeDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricChargeDensity operator+(const ElectricChargeDensity& other) const noexcept
        {
            return ElectricChargeDensity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricChargeDensity operator-(const ElectricChargeDensity& other)const noexcept
        {
            return ElectricChargeDensity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricChargeDensity operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricChargeDensity(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricChargeDensity operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricChargeDensity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricChargeDensity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricChargeDensity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricChargeDensity& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t coulombs_per_cubic_meter() const
        {
            return convert_from_base(ElectricChargeDensityUnit::CoulombsPerCubicMeter);
        }

        [[nodiscard]] static constexpr ElectricChargeDensity from_coulombs_per_cubic_meter(const un_scalar_t value)
        {
            return ElectricChargeDensity(value, ElectricChargeDensityUnit::CoulombsPerCubicMeter);
        }


        [[nodiscard]] static constexpr ElectricChargeDensity from_invalid()
        {
            return ElectricChargeDensity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricChargeDensityUnit unit)
        {
            switch (unit)
            {

            case ElectricChargeDensityUnit::CoulombsPerCubicMeter:
                return value;

            }

            throw std::invalid_argument("Unknown ElectricChargeDensity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricChargeDensityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case ElectricChargeDensityUnit::CoulombsPerCubicMeter:
                return base_value_;

            }

            throw std::invalid_argument("Unknown ElectricChargeDensity unit.");
        }

        un_scalar_t value_;
        ElectricChargeDensityUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
