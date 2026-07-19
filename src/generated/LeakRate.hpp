#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class LeakRateUnit : std::uint8_t
    {
        PascalCubicMetersPerSecond,
        MillibarLitersPerSecond,
        TorrLitersPerSecond,
        AtmCubicCentimetersPerSecond,
    };

    /// <summary>A leakage rate of QL = 1 Pa-m³/s is given when the pressure in a closed, evacuated container with a volume of 1 m³ rises by 1 Pa per second or when the pressure in the container drops by 1 Pa in the event of overpressure.</summary>
    class LeakRate : public UnitsNetBase
    {
    public:
        constexpr explicit LeakRate(
            const un_scalar_t value,
            const LeakRateUnit unit = LeakRateUnit::PascalCubicMetersPerSecond)
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
           return "LeakRate"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case LeakRateUnit::PascalCubicMetersPerSecond:
                return "PascalCubicMetersPerSecond";

            case LeakRateUnit::MillibarLitersPerSecond:
                return "MillibarLitersPerSecond";

            case LeakRateUnit::TorrLitersPerSecond:
                return "TorrLitersPerSecond";

            case LeakRateUnit::AtmCubicCentimetersPerSecond:
                return "AtmCubicCentimetersPerSecond";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const LeakRateUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr LeakRate operator+(const LeakRate& other) const noexcept
        {
            return LeakRate(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr LeakRate operator-(const LeakRate& other)const noexcept
        {
            return LeakRate(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr LeakRate operator*(const un_scalar_t scalar) const noexcept
        {
            return LeakRate(base_value() * scalar);
        }

        [[nodiscard]] constexpr LeakRate operator/(const un_scalar_t scalar) const noexcept
        {
            return LeakRate(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const LeakRate& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const LeakRate& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const LeakRate& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t pascal_cubic_meters_per_second() const
        {
            return convert_from_base(LeakRateUnit::PascalCubicMetersPerSecond);
        }

        [[nodiscard]] static constexpr LeakRate from_pascal_cubic_meters_per_second(const un_scalar_t value)
        {
            return LeakRate(value, LeakRateUnit::PascalCubicMetersPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t millibar_liters_per_second() const
        {
            return convert_from_base(LeakRateUnit::MillibarLitersPerSecond);
        }

        [[nodiscard]] static constexpr LeakRate from_millibar_liters_per_second(const un_scalar_t value)
        {
            return LeakRate(value, LeakRateUnit::MillibarLitersPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t torr_liters_per_second() const
        {
            return convert_from_base(LeakRateUnit::TorrLitersPerSecond);
        }

        [[nodiscard]] static constexpr LeakRate from_torr_liters_per_second(const un_scalar_t value)
        {
            return LeakRate(value, LeakRateUnit::TorrLitersPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t atm_cubic_centimeters_per_second() const
        {
            return convert_from_base(LeakRateUnit::AtmCubicCentimetersPerSecond);
        }

        [[nodiscard]] static constexpr LeakRate from_atm_cubic_centimeters_per_second(const un_scalar_t value)
        {
            return LeakRate(value, LeakRateUnit::AtmCubicCentimetersPerSecond);
        }

        [[nodiscard]] static constexpr LeakRate from_invalid()
        {
            return LeakRate(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, LeakRateUnit unit)
        {
            switch (unit)
            {

            case LeakRateUnit::PascalCubicMetersPerSecond:
                return value;

            case LeakRateUnit::MillibarLitersPerSecond:
                return value / static_cast<un_scalar_t>(10);

            case LeakRateUnit::TorrLitersPerSecond:
                return value / static_cast<un_scalar_t>(7.5);

            case LeakRateUnit::AtmCubicCentimetersPerSecond:
                return value / (static_cast<un_scalar_t>(1e6) / static_cast<un_scalar_t>(101325));

            }

            throw std::invalid_argument("Unknown LeakRate unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const LeakRateUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case LeakRateUnit::PascalCubicMetersPerSecond:
                return base_value;

            case LeakRateUnit::MillibarLitersPerSecond:
                return base_value * static_cast<un_scalar_t>(10);

            case LeakRateUnit::TorrLitersPerSecond:
                return base_value * static_cast<un_scalar_t>(7.5);

            case LeakRateUnit::AtmCubicCentimetersPerSecond:
                return base_value * (static_cast<un_scalar_t>(1e6) / static_cast<un_scalar_t>(101325));

            }

            throw std::invalid_argument("Unknown LeakRate unit.");
        }

        un_scalar_t value_;
        LeakRateUnit value_unit_type_;       
    };
}
