#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class ElectricCurrentDensityUnit : std::uint8_t
    {
        AmperesPerSquareMeter,
        AmperesPerSquareInch,
        AmperesPerSquareFoot,
    };

    /// <summary>In electromagnetism, current density is the electric current per unit area of cross section.</summary>
    class ElectricCurrentDensity
    {
    public:
        constexpr explicit ElectricCurrentDensity(
            const un_scalar_t value,
            const ElectricCurrentDensityUnit unit = ElectricCurrentDensityUnit::AmperesPerSquareMeter)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit ElectricCurrentDensity(const bool isValid)
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

        [[nodiscard]] constexpr un_scalar_t value(const ElectricCurrentDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricCurrentDensity operator+(const ElectricCurrentDensity other) const noexcept
        {
            return ElectricCurrentDensity(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricCurrentDensity operator-(const ElectricCurrentDensity other) const noexcept
        {
            return ElectricCurrentDensity(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricCurrentDensity operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricCurrentDensity(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricCurrentDensity operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricCurrentDensity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricCurrentDensity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const ElectricCurrentDensity other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricCurrentDensity other) const noexcept
        {
            return value_ > other.value_;
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
        bool _isInvalid = false;
    
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
            switch (unit)
            {

            case ElectricCurrentDensityUnit::AmperesPerSquareMeter:
                return value_;

            case ElectricCurrentDensityUnit::AmperesPerSquareInch:
                return value_ * static_cast<un_scalar_t>(0.00064516);

            case ElectricCurrentDensityUnit::AmperesPerSquareFoot:
                return value_ * static_cast<un_scalar_t>(9.290304e-2);

            }

            throw std::invalid_argument("Unknown ElectricCurrentDensity unit.");
        }

        un_scalar_t value_;
    };
}
