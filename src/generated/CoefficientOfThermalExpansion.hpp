#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

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
    class CoefficientOfThermalExpansion
    {
    public:
        constexpr explicit CoefficientOfThermalExpansion(
            const un_scalar_t value,
            const CoefficientOfThermalExpansionUnit unit = CoefficientOfThermalExpansionUnit::PerKelvin)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit CoefficientOfThermalExpansion(const bool isValid)
        {
            _isInvalid = !isValid;
        }
        
        void SetValueAsInvalid()
        {
            _isInvalid = true;
        }
        
        void SetValueAsValid()
        {
            _isInvalid = false;
        }
        
        [[nodiscard]] bool GetValueIsValid() const
        {
            return _isInvalid;
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const CoefficientOfThermalExpansionUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr CoefficientOfThermalExpansion operator+(const CoefficientOfThermalExpansion other) const noexcept
        {
            return CoefficientOfThermalExpansion(value_ + other.value_);
        }

        [[nodiscard]] constexpr CoefficientOfThermalExpansion operator-(const CoefficientOfThermalExpansion other) const noexcept
        {
            return CoefficientOfThermalExpansion(value_ - other.value_);
        }

        [[nodiscard]] constexpr CoefficientOfThermalExpansion operator*(const un_scalar_t scalar) const noexcept
        {
            return CoefficientOfThermalExpansion(value_ * scalar);
        }

        [[nodiscard]] constexpr CoefficientOfThermalExpansion operator/(const un_scalar_t scalar) const noexcept
        {
            return CoefficientOfThermalExpansion(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const CoefficientOfThermalExpansion other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const CoefficientOfThermalExpansion other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const CoefficientOfThermalExpansion other) const noexcept
        {
            return value_ > other.value_;
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
        bool _isInvalid = false;
    
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
            switch (unit)
            {

            case CoefficientOfThermalExpansionUnit::PerKelvin:
                return value_;

            case CoefficientOfThermalExpansionUnit::PerDegreeCelsius:
                return value_;

            case CoefficientOfThermalExpansionUnit::PerDegreeFahrenheit:
                return value_ * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(9);

            case CoefficientOfThermalExpansionUnit::PpmPerKelvin:
                return value_ * static_cast<un_scalar_t>(1e6);

            case CoefficientOfThermalExpansionUnit::PpmPerDegreeCelsius:
                return value_ * static_cast<un_scalar_t>(1e6);

            case CoefficientOfThermalExpansionUnit::PpmPerDegreeFahrenheit:
                return value_ * static_cast<un_scalar_t>(5e6) / static_cast<un_scalar_t>(9);

            }

            throw std::invalid_argument("Unknown CoefficientOfThermalExpansion unit.");
        }

        un_scalar_t value_;
    };
}
