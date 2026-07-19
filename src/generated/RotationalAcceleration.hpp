#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class RotationalAccelerationUnit : std::uint8_t
    {
        RadiansPerSecondSquared,
        DegreesPerSecondSquared,
        RevolutionsPerMinutePerSecond,
        RevolutionsPerSecondSquared,
    };

    /// <summary>Angular acceleration is the rate of change of rotational speed.</summary>
    class RotationalAcceleration : public UnitsNetBase
    {
    public:
        constexpr explicit RotationalAcceleration(
            const un_scalar_t value,
            const RotationalAccelerationUnit unit = RotationalAccelerationUnit::RadiansPerSecondSquared)
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
           return "RotationalAcceleration"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case RotationalAccelerationUnit::RadiansPerSecondSquared:
                return "RadiansPerSecondSquared";

            case RotationalAccelerationUnit::DegreesPerSecondSquared:
                return "DegreesPerSecondSquared";

            case RotationalAccelerationUnit::RevolutionsPerMinutePerSecond:
                return "RevolutionsPerMinutePerSecond";

            case RotationalAccelerationUnit::RevolutionsPerSecondSquared:
                return "RevolutionsPerSecondSquared";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const RotationalAccelerationUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RotationalAcceleration operator+(const RotationalAcceleration& other) const noexcept
        {
            return RotationalAcceleration(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr RotationalAcceleration operator-(const RotationalAcceleration& other)const noexcept
        {
            return RotationalAcceleration(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr RotationalAcceleration operator*(const un_scalar_t scalar) const noexcept
        {
            return RotationalAcceleration(base_value() * scalar);
        }

        [[nodiscard]] constexpr RotationalAcceleration operator/(const un_scalar_t scalar) const noexcept
        {
            return RotationalAcceleration(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RotationalAcceleration& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const RotationalAcceleration& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const RotationalAcceleration& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t radians_per_second_squared() const
        {
            return convert_from_base(RotationalAccelerationUnit::RadiansPerSecondSquared);
        }

        [[nodiscard]] static constexpr RotationalAcceleration from_radians_per_second_squared(const un_scalar_t value)
        {
            return RotationalAcceleration(value, RotationalAccelerationUnit::RadiansPerSecondSquared);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_per_second_squared() const
        {
            return convert_from_base(RotationalAccelerationUnit::DegreesPerSecondSquared);
        }

        [[nodiscard]] static constexpr RotationalAcceleration from_degrees_per_second_squared(const un_scalar_t value)
        {
            return RotationalAcceleration(value, RotationalAccelerationUnit::DegreesPerSecondSquared);
        }

        [[nodiscard]] constexpr un_scalar_t revolutions_per_minute_per_second() const
        {
            return convert_from_base(RotationalAccelerationUnit::RevolutionsPerMinutePerSecond);
        }

        [[nodiscard]] static constexpr RotationalAcceleration from_revolutions_per_minute_per_second(const un_scalar_t value)
        {
            return RotationalAcceleration(value, RotationalAccelerationUnit::RevolutionsPerMinutePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t revolutions_per_second_squared() const
        {
            return convert_from_base(RotationalAccelerationUnit::RevolutionsPerSecondSquared);
        }

        [[nodiscard]] static constexpr RotationalAcceleration from_revolutions_per_second_squared(const un_scalar_t value)
        {
            return RotationalAcceleration(value, RotationalAccelerationUnit::RevolutionsPerSecondSquared);
        }

        [[nodiscard]] static constexpr RotationalAcceleration from_invalid()
        {
            return RotationalAcceleration(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RotationalAccelerationUnit unit)
        {
            switch (unit)
            {

            case RotationalAccelerationUnit::RadiansPerSecondSquared:
                return value;

            case RotationalAccelerationUnit::DegreesPerSecondSquared:
                return (std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(180)) * value;

            case RotationalAccelerationUnit::RevolutionsPerMinutePerSecond:
                return ((static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>) / static_cast<un_scalar_t>(60)) * value;

            case RotationalAccelerationUnit::RevolutionsPerSecondSquared:
                return (static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>) * value;

            }

            throw std::invalid_argument("Unknown RotationalAcceleration unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RotationalAccelerationUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case RotationalAccelerationUnit::RadiansPerSecondSquared:
                return base_value;

            case RotationalAccelerationUnit::DegreesPerSecondSquared:
                return (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>) * base_value;

            case RotationalAccelerationUnit::RevolutionsPerMinutePerSecond:
                return (static_cast<un_scalar_t>(60) / (static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>)) * base_value;

            case RotationalAccelerationUnit::RevolutionsPerSecondSquared:
                return (static_cast<un_scalar_t>(1) / (static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>)) * base_value;

            }

            throw std::invalid_argument("Unknown RotationalAcceleration unit.");
        }

        un_scalar_t value_;
        RotationalAccelerationUnit value_unit_type_;       
    };
}
