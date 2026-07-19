#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class RelativeHumidityUnit : std::uint8_t
    {
        Percent,
    };

    /// <summary>Relative humidity is a ratio of the actual water vapor present in the air to the maximum water vapor in the air at the given temperature.</summary>
    class RelativeHumidity : public UnitsNetBase
    {
    public:
        constexpr explicit RelativeHumidity(
            const un_scalar_t value,
            const RelativeHumidityUnit unit = RelativeHumidityUnit::Percent)
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
           return "RelativeHumidity"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case RelativeHumidityUnit::Percent:
                return "Percent";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const RelativeHumidityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RelativeHumidity operator+(const RelativeHumidity& other) const noexcept
        {
            return RelativeHumidity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr RelativeHumidity operator-(const RelativeHumidity& other)const noexcept
        {
            return RelativeHumidity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr RelativeHumidity operator*(const un_scalar_t scalar) const noexcept
        {
            return RelativeHumidity(base_value() * scalar);
        }

        [[nodiscard]] constexpr RelativeHumidity operator/(const un_scalar_t scalar) const noexcept
        {
            return RelativeHumidity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RelativeHumidity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const RelativeHumidity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const RelativeHumidity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t percent() const
        {
            return convert_from_base(RelativeHumidityUnit::Percent);
        }

        [[nodiscard]] static constexpr RelativeHumidity from_percent(const un_scalar_t value)
        {
            return RelativeHumidity(value, RelativeHumidityUnit::Percent);
        }

        [[nodiscard]] static constexpr RelativeHumidity from_invalid()
        {
            return RelativeHumidity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RelativeHumidityUnit unit)
        {
            switch (unit)
            {

            case RelativeHumidityUnit::Percent:
                return value;

            }

            throw std::invalid_argument("Unknown RelativeHumidity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RelativeHumidityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case RelativeHumidityUnit::Percent:
                return base_value;

            }

            throw std::invalid_argument("Unknown RelativeHumidity unit.");
        }

        un_scalar_t value_;
        RelativeHumidityUnit value_unit_type_;       
    };
}
