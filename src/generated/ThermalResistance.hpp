#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class ThermalResistanceUnit : std::uint8_t
    {
        KelvinsPerWatt,
        DegreesCelsiusPerWatt,
    };

    /// <summary>Thermal resistance (R) measures the opposition to the heat current in a material or system. It is measured in units of kelvins per watt (K/W) and indicates how much temperature difference (in kelvins) is required to transfer a unit of heat current (in watts) through the material or object. It is essential to optimize the building insulation, evaluate the efficiency of electronic devices, and enhance the performance of heat sinks in various applications.</summary>
    class ThermalResistance
    {
    public:
        constexpr explicit ThermalResistance(
            const un_scalar_t value,
            const ThermalResistanceUnit unit = ThermalResistanceUnit::KelvinsPerWatt)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit ThermalResistance(const bool isValid)
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

        [[nodiscard]] constexpr un_scalar_t value(const ThermalResistanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ThermalResistance operator+(const ThermalResistance other) const noexcept
        {
            return ThermalResistance(value_ + other.value_);
        }

        [[nodiscard]] constexpr ThermalResistance operator-(const ThermalResistance other) const noexcept
        {
            return ThermalResistance(value_ - other.value_);
        }

        [[nodiscard]] constexpr ThermalResistance operator*(const un_scalar_t scalar) const noexcept
        {
            return ThermalResistance(value_ * scalar);
        }

        [[nodiscard]] constexpr ThermalResistance operator/(const un_scalar_t scalar) const noexcept
        {
            return ThermalResistance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ThermalResistance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const ThermalResistance other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const ThermalResistance other) const noexcept
        {
            return value_ > other.value_;
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
        bool _isInvalid = false;
    
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
            switch (unit)
            {

            case ThermalResistanceUnit::KelvinsPerWatt:
                return value_;

            case ThermalResistanceUnit::DegreesCelsiusPerWatt:
                return value_;

            }

            throw std::invalid_argument("Unknown ThermalResistance unit.");
        }

        un_scalar_t value_;
    };
}
