#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class TemperatureGradientUnit : std::uint8_t
    {
        KelvinsPerMeter,
        DegreesCelsiusPerMeter,
        DegreesFahrenheitPerFoot,
        DegreesCelsiusPerKilometer,
    };

    /// <summary></summary>
    class TemperatureGradient : public UnitsNetBase
    {
    public:
        constexpr explicit TemperatureGradient(
            const un_scalar_t value,
            const TemperatureGradientUnit unit = TemperatureGradientUnit::KelvinsPerMeter)
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
           return "TemperatureGradient"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case TemperatureGradientUnit::KelvinsPerMeter:
                return "KelvinsPerMeter";

            case TemperatureGradientUnit::DegreesCelsiusPerMeter:
                return "DegreesCelsiusPerMeter";

            case TemperatureGradientUnit::DegreesFahrenheitPerFoot:
                return "DegreesFahrenheitPerFoot";

            case TemperatureGradientUnit::DegreesCelsiusPerKilometer:
                return "DegreesCelsiusPerKilometer";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const TemperatureGradientUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr TemperatureGradient operator+(const TemperatureGradient& other) const noexcept
        {
            return TemperatureGradient(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr TemperatureGradient operator-(const TemperatureGradient& other)const noexcept
        {
            return TemperatureGradient(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr TemperatureGradient operator*(const un_scalar_t scalar) const noexcept
        {
            return TemperatureGradient(base_value() * scalar);
        }

        [[nodiscard]] constexpr TemperatureGradient operator/(const un_scalar_t scalar) const noexcept
        {
            return TemperatureGradient(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const TemperatureGradient& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const TemperatureGradient& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const TemperatureGradient& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t kelvins_per_meter() const
        {
            return convert_from_base(TemperatureGradientUnit::KelvinsPerMeter);
        }

        [[nodiscard]] static constexpr TemperatureGradient from_kelvins_per_meter(const un_scalar_t value)
        {
            return TemperatureGradient(value, TemperatureGradientUnit::KelvinsPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_celsius_per_meter() const
        {
            return convert_from_base(TemperatureGradientUnit::DegreesCelsiusPerMeter);
        }

        [[nodiscard]] static constexpr TemperatureGradient from_degrees_celsius_per_meter(const un_scalar_t value)
        {
            return TemperatureGradient(value, TemperatureGradientUnit::DegreesCelsiusPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_fahrenheit_per_foot() const
        {
            return convert_from_base(TemperatureGradientUnit::DegreesFahrenheitPerFoot);
        }

        [[nodiscard]] static constexpr TemperatureGradient from_degrees_fahrenheit_per_foot(const un_scalar_t value)
        {
            return TemperatureGradient(value, TemperatureGradientUnit::DegreesFahrenheitPerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_celsius_per_kilometer() const
        {
            return convert_from_base(TemperatureGradientUnit::DegreesCelsiusPerKilometer);
        }

        [[nodiscard]] static constexpr TemperatureGradient from_degrees_celsius_per_kilometer(const un_scalar_t value)
        {
            return TemperatureGradient(value, TemperatureGradientUnit::DegreesCelsiusPerKilometer);
        }

        [[nodiscard]] static constexpr TemperatureGradient from_invalid()
        {
            return TemperatureGradient(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, TemperatureGradientUnit unit)
        {
            switch (unit)
            {

            case TemperatureGradientUnit::KelvinsPerMeter:
                return value;

            case TemperatureGradientUnit::DegreesCelsiusPerMeter:
                return value;

            case TemperatureGradientUnit::DegreesFahrenheitPerFoot:
                return (value / static_cast<un_scalar_t>(0.3048)) * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(9);

            case TemperatureGradientUnit::DegreesCelsiusPerKilometer:
                return value / static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown TemperatureGradient unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const TemperatureGradientUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case TemperatureGradientUnit::KelvinsPerMeter:
                return base_value;

            case TemperatureGradientUnit::DegreesCelsiusPerMeter:
                return base_value;

            case TemperatureGradientUnit::DegreesFahrenheitPerFoot:
                return (base_value * static_cast<un_scalar_t>(0.3048)) * static_cast<un_scalar_t>(9) / static_cast<un_scalar_t>(5);

            case TemperatureGradientUnit::DegreesCelsiusPerKilometer:
                return base_value * static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown TemperatureGradient unit.");
        }

        un_scalar_t value_;
        TemperatureGradientUnit value_unit_type_;       
    };
}
