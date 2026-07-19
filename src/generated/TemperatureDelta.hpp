#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class TemperatureDeltaUnit : std::uint8_t
    {
        Kelvins,
        DegreesCelsius,
        MillidegreesCelsius,
        DegreesDelisle,
        DegreesFahrenheit,
        DegreesNewton,
        DegreesRankine,
        DegreesReaumur,
        DegreesRoemer,
    };

    /// <summary>Difference between two temperatures. The conversions are different than for Temperature.</summary>
    class TemperatureDelta : public UnitsNetBase
    {
    public:
        constexpr explicit TemperatureDelta(
            const un_scalar_t value,
            const TemperatureDeltaUnit unit = TemperatureDeltaUnit::Kelvins)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const TemperatureDeltaUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr TemperatureDelta operator+(const TemperatureDelta& other) const noexcept
        {
            return TemperatureDelta(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr TemperatureDelta operator-(const TemperatureDelta& other)const noexcept
        {
            return TemperatureDelta(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr TemperatureDelta operator*(const un_scalar_t scalar) const noexcept
        {
            return TemperatureDelta(base_value() * scalar);
        }

        [[nodiscard]] constexpr TemperatureDelta operator/(const un_scalar_t scalar) const noexcept
        {
            return TemperatureDelta(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const TemperatureDelta& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const TemperatureDelta& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const TemperatureDelta& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t kelvins() const
        {
            return convert_from_base(TemperatureDeltaUnit::Kelvins);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_kelvins(const un_scalar_t value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::Kelvins);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_celsius() const
        {
            return convert_from_base(TemperatureDeltaUnit::DegreesCelsius);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_degrees_celsius(const un_scalar_t value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::DegreesCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t millidegrees_celsius() const
        {
            return convert_from_base(TemperatureDeltaUnit::MillidegreesCelsius);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_millidegrees_celsius(const un_scalar_t value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::MillidegreesCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_delisle() const
        {
            return convert_from_base(TemperatureDeltaUnit::DegreesDelisle);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_degrees_delisle(const un_scalar_t value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::DegreesDelisle);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_fahrenheit() const
        {
            return convert_from_base(TemperatureDeltaUnit::DegreesFahrenheit);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_degrees_fahrenheit(const un_scalar_t value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::DegreesFahrenheit);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_newton() const
        {
            return convert_from_base(TemperatureDeltaUnit::DegreesNewton);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_degrees_newton(const un_scalar_t value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::DegreesNewton);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_rankine() const
        {
            return convert_from_base(TemperatureDeltaUnit::DegreesRankine);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_degrees_rankine(const un_scalar_t value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::DegreesRankine);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_reaumur() const
        {
            return convert_from_base(TemperatureDeltaUnit::DegreesReaumur);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_degrees_reaumur(const un_scalar_t value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::DegreesReaumur);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_roemer() const
        {
            return convert_from_base(TemperatureDeltaUnit::DegreesRoemer);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_degrees_roemer(const un_scalar_t value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::DegreesRoemer);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_invalid()
        {
            return TemperatureDelta(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, TemperatureDeltaUnit unit)
        {
            switch (unit)
            {

            case TemperatureDeltaUnit::Kelvins:
                return value;

            case TemperatureDeltaUnit::DegreesCelsius:
                return value;

            case TemperatureDeltaUnit::MillidegreesCelsius:
                return (value * static_cast<un_scalar_t>(1e-3));

            case TemperatureDeltaUnit::DegreesDelisle:
                return value * static_cast<un_scalar_t>(-2) / static_cast<un_scalar_t>(3);

            case TemperatureDeltaUnit::DegreesFahrenheit:
                return value * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(9);

            case TemperatureDeltaUnit::DegreesNewton:
                return value * static_cast<un_scalar_t>(100) / static_cast<un_scalar_t>(33);

            case TemperatureDeltaUnit::DegreesRankine:
                return value * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(9);

            case TemperatureDeltaUnit::DegreesReaumur:
                return value * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(4);

            case TemperatureDeltaUnit::DegreesRoemer:
                return value * static_cast<un_scalar_t>(40) / static_cast<un_scalar_t>(21);

            }

            throw std::invalid_argument("Unknown TemperatureDelta unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const TemperatureDeltaUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case TemperatureDeltaUnit::Kelvins:
                return base_value;

            case TemperatureDeltaUnit::DegreesCelsius:
                return base_value;

            case TemperatureDeltaUnit::MillidegreesCelsius:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case TemperatureDeltaUnit::DegreesDelisle:
                return base_value * static_cast<un_scalar_t>(-3) / static_cast<un_scalar_t>(2);

            case TemperatureDeltaUnit::DegreesFahrenheit:
                return base_value * static_cast<un_scalar_t>(9) / static_cast<un_scalar_t>(5);

            case TemperatureDeltaUnit::DegreesNewton:
                return base_value * static_cast<un_scalar_t>(33) / static_cast<un_scalar_t>(100);

            case TemperatureDeltaUnit::DegreesRankine:
                return base_value * static_cast<un_scalar_t>(9) / static_cast<un_scalar_t>(5);

            case TemperatureDeltaUnit::DegreesReaumur:
                return base_value * static_cast<un_scalar_t>(4) / static_cast<un_scalar_t>(5);

            case TemperatureDeltaUnit::DegreesRoemer:
                return base_value * static_cast<un_scalar_t>(21) / static_cast<un_scalar_t>(40);

            }

            throw std::invalid_argument("Unknown TemperatureDelta unit.");
        }

        un_scalar_t value_;
        TemperatureDeltaUnit value_unit_type_;       
    };
}
