#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class RatioChangeRateUnit : std::uint8_t
    {
        PercentsPerSecond,
        DecimalFractionsPerSecond,
    };

    /// <summary>The change in ratio per unit of time.</summary>
    class RatioChangeRate
    {
    public:
        constexpr explicit RatioChangeRate(
            const un_scalar_t value,
            const RatioChangeRateUnit unit = RatioChangeRateUnit::DecimalFractionsPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit RatioChangeRate(const bool isValid)
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

        [[nodiscard]] constexpr un_scalar_t value(const RatioChangeRateUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RatioChangeRate operator+(const RatioChangeRate other) const noexcept
        {
            return RatioChangeRate(value_ + other.value_);
        }

        [[nodiscard]] constexpr RatioChangeRate operator-(const RatioChangeRate other) const noexcept
        {
            return RatioChangeRate(value_ - other.value_);
        }

        [[nodiscard]] constexpr RatioChangeRate operator*(const un_scalar_t scalar) const noexcept
        {
            return RatioChangeRate(value_ * scalar);
        }

        [[nodiscard]] constexpr RatioChangeRate operator/(const un_scalar_t scalar) const noexcept
        {
            return RatioChangeRate(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RatioChangeRate other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const RatioChangeRate other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const RatioChangeRate other) const noexcept
        {
            return value_ > other.value_;
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
        bool _isInvalid = false;
    
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
            switch (unit)
            {

            case RatioChangeRateUnit::PercentsPerSecond:
                return value_ * static_cast<un_scalar_t>(1e2);

            case RatioChangeRateUnit::DecimalFractionsPerSecond:
                return value_;

            }

            throw std::invalid_argument("Unknown RatioChangeRate unit.");
        }

        un_scalar_t value_;
    };
}
