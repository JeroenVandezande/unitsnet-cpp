#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ThermalConductivityUnit : std::uint8_t
    {
        WattsPerMeterKelvin,
        BtusPerHourFootFahrenheit,
        BtusPerSecondInchFahrenheit,
    };

    /// <summary>Thermal conductivity is the property of a material to conduct heat.</summary>
    class ThermalConductivity : public UnitsNetBase
    {
    public:
        constexpr explicit ThermalConductivity(
            const un_scalar_t value,
            const ThermalConductivityUnit unit = ThermalConductivityUnit::WattsPerMeterKelvin)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ThermalConductivityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ThermalConductivity operator+(const ThermalConductivity& other) const noexcept
        {
            return ThermalConductivity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ThermalConductivity operator-(const ThermalConductivity& other)const noexcept
        {
            return ThermalConductivity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ThermalConductivity operator*(const un_scalar_t scalar) const noexcept
        {
            return ThermalConductivity(base_value() * scalar);
        }

        [[nodiscard]] constexpr ThermalConductivity operator/(const un_scalar_t scalar) const noexcept
        {
            return ThermalConductivity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ThermalConductivity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ThermalConductivity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ThermalConductivity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_meter_kelvin() const
        {
            return convert_from_base(ThermalConductivityUnit::WattsPerMeterKelvin);
        }

        [[nodiscard]] static constexpr ThermalConductivity from_watts_per_meter_kelvin(const un_scalar_t value)
        {
            return ThermalConductivity(value, ThermalConductivityUnit::WattsPerMeterKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t btus_per_hour_foot_fahrenheit() const
        {
            return convert_from_base(ThermalConductivityUnit::BtusPerHourFootFahrenheit);
        }

        [[nodiscard]] static constexpr ThermalConductivity from_btus_per_hour_foot_fahrenheit(const un_scalar_t value)
        {
            return ThermalConductivity(value, ThermalConductivityUnit::BtusPerHourFootFahrenheit);
        }

        [[nodiscard]] constexpr un_scalar_t btus_per_second_inch_fahrenheit() const
        {
            return convert_from_base(ThermalConductivityUnit::BtusPerSecondInchFahrenheit);
        }

        [[nodiscard]] static constexpr ThermalConductivity from_btus_per_second_inch_fahrenheit(const un_scalar_t value)
        {
            return ThermalConductivity(value, ThermalConductivityUnit::BtusPerSecondInchFahrenheit);
        }

        [[nodiscard]] static constexpr ThermalConductivity from_invalid()
        {
            return ThermalConductivity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ThermalConductivityUnit unit)
        {
            switch (unit)
            {

            case ThermalConductivityUnit::WattsPerMeterKelvin:
                return value;

            case ThermalConductivityUnit::BtusPerHourFootFahrenheit:
                return value * ((static_cast<un_scalar_t>(1055.05585262) / (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(3600))) * static_cast<un_scalar_t>(1.8));

            case ThermalConductivityUnit::BtusPerSecondInchFahrenheit:
                return value * ((static_cast<un_scalar_t>(1055.05585262) / static_cast<un_scalar_t>(2.54e-2)) * static_cast<un_scalar_t>(1.8));

            }

            throw std::invalid_argument("Unknown ThermalConductivity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ThermalConductivityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ThermalConductivityUnit::WattsPerMeterKelvin:
                return base_value;

            case ThermalConductivityUnit::BtusPerHourFootFahrenheit:
                return base_value / ((static_cast<un_scalar_t>(1055.05585262) / (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(3600))) * static_cast<un_scalar_t>(1.8));

            case ThermalConductivityUnit::BtusPerSecondInchFahrenheit:
                return base_value / ((static_cast<un_scalar_t>(1055.05585262) / static_cast<un_scalar_t>(2.54e-2)) * static_cast<un_scalar_t>(1.8));

            }

            throw std::invalid_argument("Unknown ThermalConductivity unit.");
        }

        un_scalar_t value_;
        ThermalConductivityUnit value_unit_type_;       
    };
}
