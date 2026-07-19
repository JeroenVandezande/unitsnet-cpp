#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ElectricSurfaceChargeDensityUnit : std::uint8_t
    {
        CoulombsPerSquareMeter,
        CoulombsPerSquareCentimeter,
        CoulombsPerSquareInch,
    };

    /// <summary>In electromagnetism, surface charge density is a measure of the amount of electric charge per surface area.</summary>
    class ElectricSurfaceChargeDensity : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricSurfaceChargeDensity(
            const un_scalar_t value,
            const ElectricSurfaceChargeDensityUnit unit = ElectricSurfaceChargeDensityUnit::CoulombsPerSquareMeter)
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
           return "ElectricSurfaceChargeDensity"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case ElectricSurfaceChargeDensityUnit::CoulombsPerSquareMeter:
                return "CoulombsPerSquareMeter";

            case ElectricSurfaceChargeDensityUnit::CoulombsPerSquareCentimeter:
                return "CoulombsPerSquareCentimeter";

            case ElectricSurfaceChargeDensityUnit::CoulombsPerSquareInch:
                return "CoulombsPerSquareInch";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricSurfaceChargeDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricSurfaceChargeDensity operator+(const ElectricSurfaceChargeDensity& other) const noexcept
        {
            return ElectricSurfaceChargeDensity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricSurfaceChargeDensity operator-(const ElectricSurfaceChargeDensity& other)const noexcept
        {
            return ElectricSurfaceChargeDensity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricSurfaceChargeDensity operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricSurfaceChargeDensity(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricSurfaceChargeDensity operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricSurfaceChargeDensity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricSurfaceChargeDensity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricSurfaceChargeDensity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricSurfaceChargeDensity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t coulombs_per_square_meter() const
        {
            return convert_from_base(ElectricSurfaceChargeDensityUnit::CoulombsPerSquareMeter);
        }

        [[nodiscard]] static constexpr ElectricSurfaceChargeDensity from_coulombs_per_square_meter(const un_scalar_t value)
        {
            return ElectricSurfaceChargeDensity(value, ElectricSurfaceChargeDensityUnit::CoulombsPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t coulombs_per_square_centimeter() const
        {
            return convert_from_base(ElectricSurfaceChargeDensityUnit::CoulombsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr ElectricSurfaceChargeDensity from_coulombs_per_square_centimeter(const un_scalar_t value)
        {
            return ElectricSurfaceChargeDensity(value, ElectricSurfaceChargeDensityUnit::CoulombsPerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t coulombs_per_square_inch() const
        {
            return convert_from_base(ElectricSurfaceChargeDensityUnit::CoulombsPerSquareInch);
        }

        [[nodiscard]] static constexpr ElectricSurfaceChargeDensity from_coulombs_per_square_inch(const un_scalar_t value)
        {
            return ElectricSurfaceChargeDensity(value, ElectricSurfaceChargeDensityUnit::CoulombsPerSquareInch);
        }

        [[nodiscard]] static constexpr ElectricSurfaceChargeDensity from_invalid()
        {
            return ElectricSurfaceChargeDensity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricSurfaceChargeDensityUnit unit)
        {
            switch (unit)
            {

            case ElectricSurfaceChargeDensityUnit::CoulombsPerSquareMeter:
                return value;

            case ElectricSurfaceChargeDensityUnit::CoulombsPerSquareCentimeter:
                return value * static_cast<un_scalar_t>(1.0e4);

            case ElectricSurfaceChargeDensityUnit::CoulombsPerSquareInch:
                return value / static_cast<un_scalar_t>(0.00064516);

            }

            throw std::invalid_argument("Unknown ElectricSurfaceChargeDensity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricSurfaceChargeDensityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricSurfaceChargeDensityUnit::CoulombsPerSquareMeter:
                return base_value;

            case ElectricSurfaceChargeDensityUnit::CoulombsPerSquareCentimeter:
                return base_value / static_cast<un_scalar_t>(1.0e4);

            case ElectricSurfaceChargeDensityUnit::CoulombsPerSquareInch:
                return base_value * static_cast<un_scalar_t>(0.00064516);

            }

            throw std::invalid_argument("Unknown ElectricSurfaceChargeDensity unit.");
        }

        un_scalar_t value_;
        ElectricSurfaceChargeDensityUnit value_unit_type_;       
    };
}
