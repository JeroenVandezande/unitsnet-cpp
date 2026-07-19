#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class CoefficientOfThermalExpansionUnit : std::uint8_t
    {
        PerKelvin,
        PerDegreeCelsius,
        PerDegreeFahrenheit,
        PpmPerKelvin,
        PpmPerDegreeCelsius,
        PpmPerDegreeFahrenheit,
    };

    /// <summary>A unit that represents a fractional change in size in response to a change in temperature.</summary>
    class CoefficientOfThermalExpansion : public UnitsNetBase
    {
    public:
        constexpr explicit CoefficientOfThermalExpansion(
            const un_scalar_t value,
            const CoefficientOfThermalExpansionUnit unit = CoefficientOfThermalExpansionUnit::PerKelvin)
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
           return "CoefficientOfThermalExpansion"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case CoefficientOfThermalExpansionUnit::PerKelvin:
                return "PerKelvin";

            case CoefficientOfThermalExpansionUnit::PerDegreeCelsius:
                return "PerDegreeCelsius";

            case CoefficientOfThermalExpansionUnit::PerDegreeFahrenheit:
                return "PerDegreeFahrenheit";

            case CoefficientOfThermalExpansionUnit::PpmPerKelvin:
                return "PpmPerKelvin";

            case CoefficientOfThermalExpansionUnit::PpmPerDegreeCelsius:
                return "PpmPerDegreeCelsius";

            case CoefficientOfThermalExpansionUnit::PpmPerDegreeFahrenheit:
                return "PpmPerDegreeFahrenheit";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const CoefficientOfThermalExpansionUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr CoefficientOfThermalExpansion operator+(const CoefficientOfThermalExpansion& other) const noexcept
        {
            return CoefficientOfThermalExpansion(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr CoefficientOfThermalExpansion operator-(const CoefficientOfThermalExpansion& other)const noexcept
        {
            return CoefficientOfThermalExpansion(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr CoefficientOfThermalExpansion operator*(const un_scalar_t scalar) const noexcept
        {
            return CoefficientOfThermalExpansion(base_value() * scalar);
        }

        [[nodiscard]] constexpr CoefficientOfThermalExpansion operator/(const un_scalar_t scalar) const noexcept
        {
            return CoefficientOfThermalExpansion(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const CoefficientOfThermalExpansion& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const CoefficientOfThermalExpansion& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const CoefficientOfThermalExpansion& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t per_kelvin() const
        {
            return convert_from_base(CoefficientOfThermalExpansionUnit::PerKelvin);
        }

        [[nodiscard]] static constexpr CoefficientOfThermalExpansion from_per_kelvin(const un_scalar_t value)
        {
            return CoefficientOfThermalExpansion(value, CoefficientOfThermalExpansionUnit::PerKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t per_degree_celsius() const
        {
            return convert_from_base(CoefficientOfThermalExpansionUnit::PerDegreeCelsius);
        }

        [[nodiscard]] static constexpr CoefficientOfThermalExpansion from_per_degree_celsius(const un_scalar_t value)
        {
            return CoefficientOfThermalExpansion(value, CoefficientOfThermalExpansionUnit::PerDegreeCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t per_degree_fahrenheit() const
        {
            return convert_from_base(CoefficientOfThermalExpansionUnit::PerDegreeFahrenheit);
        }

        [[nodiscard]] static constexpr CoefficientOfThermalExpansion from_per_degree_fahrenheit(const un_scalar_t value)
        {
            return CoefficientOfThermalExpansion(value, CoefficientOfThermalExpansionUnit::PerDegreeFahrenheit);
        }

        [[nodiscard]] constexpr un_scalar_t ppm_per_kelvin() const
        {
            return convert_from_base(CoefficientOfThermalExpansionUnit::PpmPerKelvin);
        }

        [[nodiscard]] static constexpr CoefficientOfThermalExpansion from_ppm_per_kelvin(const un_scalar_t value)
        {
            return CoefficientOfThermalExpansion(value, CoefficientOfThermalExpansionUnit::PpmPerKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t ppm_per_degree_celsius() const
        {
            return convert_from_base(CoefficientOfThermalExpansionUnit::PpmPerDegreeCelsius);
        }

        [[nodiscard]] static constexpr CoefficientOfThermalExpansion from_ppm_per_degree_celsius(const un_scalar_t value)
        {
            return CoefficientOfThermalExpansion(value, CoefficientOfThermalExpansionUnit::PpmPerDegreeCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t ppm_per_degree_fahrenheit() const
        {
            return convert_from_base(CoefficientOfThermalExpansionUnit::PpmPerDegreeFahrenheit);
        }

        [[nodiscard]] static constexpr CoefficientOfThermalExpansion from_ppm_per_degree_fahrenheit(const un_scalar_t value)
        {
            return CoefficientOfThermalExpansion(value, CoefficientOfThermalExpansionUnit::PpmPerDegreeFahrenheit);
        }

        [[nodiscard]] static constexpr CoefficientOfThermalExpansion from_invalid()
        {
            return CoefficientOfThermalExpansion(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, CoefficientOfThermalExpansionUnit unit)
        {
            switch (unit)
            {

            case CoefficientOfThermalExpansionUnit::PerKelvin:
                return value;

            case CoefficientOfThermalExpansionUnit::PerDegreeCelsius:
                return value;

            case CoefficientOfThermalExpansionUnit::PerDegreeFahrenheit:
                return value * static_cast<un_scalar_t>(9) / static_cast<un_scalar_t>(5);

            case CoefficientOfThermalExpansionUnit::PpmPerKelvin:
                return value / static_cast<un_scalar_t>(1e6);

            case CoefficientOfThermalExpansionUnit::PpmPerDegreeCelsius:
                return value / static_cast<un_scalar_t>(1e6);

            case CoefficientOfThermalExpansionUnit::PpmPerDegreeFahrenheit:
                return value * static_cast<un_scalar_t>(9) / static_cast<un_scalar_t>(5e6);

            }

            throw std::invalid_argument("Unknown CoefficientOfThermalExpansion unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const CoefficientOfThermalExpansionUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case CoefficientOfThermalExpansionUnit::PerKelvin:
                return base_value;

            case CoefficientOfThermalExpansionUnit::PerDegreeCelsius:
                return base_value;

            case CoefficientOfThermalExpansionUnit::PerDegreeFahrenheit:
                return base_value * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(9);

            case CoefficientOfThermalExpansionUnit::PpmPerKelvin:
                return base_value * static_cast<un_scalar_t>(1e6);

            case CoefficientOfThermalExpansionUnit::PpmPerDegreeCelsius:
                return base_value * static_cast<un_scalar_t>(1e6);

            case CoefficientOfThermalExpansionUnit::PpmPerDegreeFahrenheit:
                return base_value * static_cast<un_scalar_t>(5e6) / static_cast<un_scalar_t>(9);

            }

            throw std::invalid_argument("Unknown CoefficientOfThermalExpansion unit.");
        }

        un_scalar_t value_;
        CoefficientOfThermalExpansionUnit value_unit_type_;       
    };
}
