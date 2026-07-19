#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ElectricCurrentDensityUnit : std::uint8_t
    {
        AmperesPerSquareMeter,
        AmperesPerSquareInch,
        AmperesPerSquareFoot,
    };

    /// <summary>In electromagnetism, current density is the electric current per unit area of cross section.</summary>
    class ElectricCurrentDensity : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricCurrentDensity(
            const un_scalar_t value,
            const ElectricCurrentDensityUnit unit = ElectricCurrentDensityUnit::AmperesPerSquareMeter)
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
           return "ElectricCurrentDensity"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case ElectricCurrentDensityUnit::AmperesPerSquareMeter:
                return "AmperesPerSquareMeter";

            case ElectricCurrentDensityUnit::AmperesPerSquareInch:
                return "AmperesPerSquareInch";

            case ElectricCurrentDensityUnit::AmperesPerSquareFoot:
                return "AmperesPerSquareFoot";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricCurrentDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricCurrentDensity operator+(const ElectricCurrentDensity& other) const noexcept
        {
            return ElectricCurrentDensity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricCurrentDensity operator-(const ElectricCurrentDensity& other)const noexcept
        {
            return ElectricCurrentDensity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricCurrentDensity operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricCurrentDensity(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricCurrentDensity operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricCurrentDensity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricCurrentDensity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricCurrentDensity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricCurrentDensity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t amperes_per_square_meter() const
        {
            return convert_from_base(ElectricCurrentDensityUnit::AmperesPerSquareMeter);
        }

        [[nodiscard]] static constexpr ElectricCurrentDensity from_amperes_per_square_meter(const un_scalar_t value)
        {
            return ElectricCurrentDensity(value, ElectricCurrentDensityUnit::AmperesPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t amperes_per_square_inch() const
        {
            return convert_from_base(ElectricCurrentDensityUnit::AmperesPerSquareInch);
        }

        [[nodiscard]] static constexpr ElectricCurrentDensity from_amperes_per_square_inch(const un_scalar_t value)
        {
            return ElectricCurrentDensity(value, ElectricCurrentDensityUnit::AmperesPerSquareInch);
        }

        [[nodiscard]] constexpr un_scalar_t amperes_per_square_foot() const
        {
            return convert_from_base(ElectricCurrentDensityUnit::AmperesPerSquareFoot);
        }

        [[nodiscard]] static constexpr ElectricCurrentDensity from_amperes_per_square_foot(const un_scalar_t value)
        {
            return ElectricCurrentDensity(value, ElectricCurrentDensityUnit::AmperesPerSquareFoot);
        }

        [[nodiscard]] static constexpr ElectricCurrentDensity from_invalid()
        {
            return ElectricCurrentDensity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricCurrentDensityUnit unit)
        {
            switch (unit)
            {

            case ElectricCurrentDensityUnit::AmperesPerSquareMeter:
                return value;

            case ElectricCurrentDensityUnit::AmperesPerSquareInch:
                return value / static_cast<un_scalar_t>(0.00064516);

            case ElectricCurrentDensityUnit::AmperesPerSquareFoot:
                return value / static_cast<un_scalar_t>(9.290304e-2);

            }

            throw std::invalid_argument("Unknown ElectricCurrentDensity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricCurrentDensityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricCurrentDensityUnit::AmperesPerSquareMeter:
                return base_value;

            case ElectricCurrentDensityUnit::AmperesPerSquareInch:
                return base_value * static_cast<un_scalar_t>(0.00064516);

            case ElectricCurrentDensityUnit::AmperesPerSquareFoot:
                return base_value * static_cast<un_scalar_t>(9.290304e-2);

            }

            throw std::invalid_argument("Unknown ElectricCurrentDensity unit.");
        }

        un_scalar_t value_;
        ElectricCurrentDensityUnit value_unit_type_;       
    };
}
