#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class RelativeHumidityUnit : std::uint8_t
    {
        Percent,
    };

    /// <summary>Relative humidity is a ratio of the actual water vapor present in the air to the maximum water vapor in the air at the given temperature.</summary>
    class RelativeHumidity
    {
    public:
        constexpr explicit RelativeHumidity(
            const un_scalar_t value,
            const RelativeHumidityUnit unit = RelativeHumidityUnit::Percent)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit RelativeHumidity(const bool isValid)
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

        [[nodiscard]] constexpr un_scalar_t value(const RelativeHumidityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RelativeHumidity operator+(const RelativeHumidity other) const noexcept
        {
            return RelativeHumidity(value_ + other.value_);
        }

        [[nodiscard]] constexpr RelativeHumidity operator-(const RelativeHumidity other) const noexcept
        {
            return RelativeHumidity(value_ - other.value_);
        }

        [[nodiscard]] constexpr RelativeHumidity operator*(const un_scalar_t scalar) const noexcept
        {
            return RelativeHumidity(value_ * scalar);
        }

        [[nodiscard]] constexpr RelativeHumidity operator/(const un_scalar_t scalar) const noexcept
        {
            return RelativeHumidity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RelativeHumidity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const RelativeHumidity other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const RelativeHumidity other) const noexcept
        {
            return value_ > other.value_;
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
        bool _isInvalid = false;
    
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
            switch (unit)
            {

            case RelativeHumidityUnit::Percent:
                return value_;

            }

            throw std::invalid_argument("Unknown RelativeHumidity unit.");
        }

        un_scalar_t value_;
    };
}
