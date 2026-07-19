#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class PowerRatioUnit : std::uint8_t
    {
        DecibelWatts,
        DecibelMilliwatts,
    };

    /// <summary>The strength of a signal expressed in decibels (dB) relative to one watt.</summary>
    class PowerRatio : public UnitsNetBase
    {
    public:
        constexpr explicit PowerRatio(
            const un_scalar_t value,
            const PowerRatioUnit unit = PowerRatioUnit::DecibelWatts)
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
           return "PowerRatio"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case PowerRatioUnit::DecibelWatts:
                return "DecibelWatts";

            case PowerRatioUnit::DecibelMilliwatts:
                return "DecibelMilliwatts";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const PowerRatioUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr PowerRatio operator+(const PowerRatio& other) const noexcept
        {
            return PowerRatio(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr PowerRatio operator-(const PowerRatio& other)const noexcept
        {
            return PowerRatio(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr PowerRatio operator*(const un_scalar_t scalar) const noexcept
        {
            return PowerRatio(base_value() * scalar);
        }

        [[nodiscard]] constexpr PowerRatio operator/(const un_scalar_t scalar) const noexcept
        {
            return PowerRatio(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const PowerRatio& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const PowerRatio& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const PowerRatio& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t decibel_watts() const
        {
            return convert_from_base(PowerRatioUnit::DecibelWatts);
        }

        [[nodiscard]] static constexpr PowerRatio from_decibel_watts(const un_scalar_t value)
        {
            return PowerRatio(value, PowerRatioUnit::DecibelWatts);
        }

        [[nodiscard]] constexpr un_scalar_t decibel_milliwatts() const
        {
            return convert_from_base(PowerRatioUnit::DecibelMilliwatts);
        }

        [[nodiscard]] static constexpr PowerRatio from_decibel_milliwatts(const un_scalar_t value)
        {
            return PowerRatio(value, PowerRatioUnit::DecibelMilliwatts);
        }

        [[nodiscard]] static constexpr PowerRatio from_invalid()
        {
            return PowerRatio(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, PowerRatioUnit unit)
        {
            switch (unit)
            {

            case PowerRatioUnit::DecibelWatts:
                return value;

            case PowerRatioUnit::DecibelMilliwatts:
                return value - static_cast<un_scalar_t>(30);

            }

            throw std::invalid_argument("Unknown PowerRatio unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const PowerRatioUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case PowerRatioUnit::DecibelWatts:
                return base_value;

            case PowerRatioUnit::DecibelMilliwatts:
                return base_value + static_cast<un_scalar_t>(30);

            }

            throw std::invalid_argument("Unknown PowerRatio unit.");
        }

        un_scalar_t value_;
        PowerRatioUnit value_unit_type_;       
    };
}
