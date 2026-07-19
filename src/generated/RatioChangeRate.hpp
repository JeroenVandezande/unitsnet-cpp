#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class RatioChangeRateUnit : std::uint8_t
    {
        PercentsPerSecond,
        DecimalFractionsPerSecond,
    };

    /// <summary>The change in ratio per unit of time.</summary>
    class RatioChangeRate : public UnitsNetBase
    {
    public:
        constexpr explicit RatioChangeRate(
            const un_scalar_t value,
            const RatioChangeRateUnit unit = RatioChangeRateUnit::DecimalFractionsPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == RatioChangeRateUnit::DecimalFractionsPerSecond)
            {
                base_value_ = value;
                base_value_exists_ = true;
            }
            else
            {
                base_value_ = 0;
                base_value_exists_ = false;
            }
        }
        
        constexpr void create_base_value_if_needed() const noexcept
        {
            if(base_value_exists_)
            {
                return;
            }
            else
            {
                base_value_ = convert_to_base(value_, value_unit_type_);
                base_value_exists_ = true;
                return;
            }
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            create_base_value_if_needed();    
            return base_value_;    
        }

        [[nodiscard]] constexpr un_scalar_t value(const RatioChangeRateUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RatioChangeRate operator+(const RatioChangeRate& other) const noexcept
        {
            return RatioChangeRate(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr RatioChangeRate operator-(const RatioChangeRate& other)const noexcept
        {
            return RatioChangeRate(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr RatioChangeRate operator*(const un_scalar_t scalar) const noexcept
        {
            return RatioChangeRate(base_value() * scalar);
        }

        [[nodiscard]] constexpr RatioChangeRate operator/(const un_scalar_t scalar) const noexcept
        {
            return RatioChangeRate(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RatioChangeRate& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const RatioChangeRate& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const RatioChangeRate& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t percents_per_second() const
        {
            return convert_from_base(RatioChangeRateUnit::PercentsPerSecond);
        }

        [[nodiscard]] static constexpr RatioChangeRate from_percents_per_second(const un_scalar_t value)
        {
            return RatioChangeRate(value, RatioChangeRateUnit::PercentsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t decimal_fractions_per_second() const
        {
            return convert_from_base(RatioChangeRateUnit::DecimalFractionsPerSecond);
        }

        [[nodiscard]] static constexpr RatioChangeRate from_decimal_fractions_per_second(const un_scalar_t value)
        {
            return RatioChangeRate(value, RatioChangeRateUnit::DecimalFractionsPerSecond);
        }


        [[nodiscard]] static constexpr RatioChangeRate from_invalid()
        {
            return RatioChangeRate(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RatioChangeRateUnit unit)
        {
            switch (unit)
            {

            case RatioChangeRateUnit::PercentsPerSecond:
                return value / static_cast<un_scalar_t>(1e2);

            case RatioChangeRateUnit::DecimalFractionsPerSecond:
                return value;

            }

            throw std::invalid_argument("Unknown RatioChangeRate unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RatioChangeRateUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case RatioChangeRateUnit::PercentsPerSecond:
                return base_value_ * static_cast<un_scalar_t>(1e2);

            case RatioChangeRateUnit::DecimalFractionsPerSecond:
                return base_value_;

            }

            throw std::invalid_argument("Unknown RatioChangeRate unit.");
        }

        un_scalar_t value_;
        RatioChangeRateUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
