#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class ScalarUnit : std::uint8_t
    {
        Amount,
    };

    /// <summary>A way of representing a number of items.</summary>
    class Scalar
    {
    public:
        constexpr explicit Scalar(
            const un_scalar_t value,
            const ScalarUnit unit = ScalarUnit::Amount)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit Scalar(const bool isValid)
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

        [[nodiscard]] constexpr un_scalar_t value(const ScalarUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Scalar operator+(const Scalar other) const noexcept
        {
            return Scalar(value_ + other.value_);
        }

        [[nodiscard]] constexpr Scalar operator-(const Scalar other) const noexcept
        {
            return Scalar(value_ - other.value_);
        }

        [[nodiscard]] constexpr Scalar operator*(const un_scalar_t scalar) const noexcept
        {
            return Scalar(value_ * scalar);
        }

        [[nodiscard]] constexpr Scalar operator/(const un_scalar_t scalar) const noexcept
        {
            return Scalar(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Scalar other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Scalar other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const Scalar other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t amount() const
        {
            return convert_from_base(ScalarUnit::Amount);
        }

        [[nodiscard]] static constexpr Scalar from_amount(const un_scalar_t value)
        {
            return Scalar(value, ScalarUnit::Amount);
        }


        [[nodiscard]] static constexpr Scalar from_invalid()
        {
            return Scalar(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ScalarUnit unit)
        {
            switch (unit)
            {

            case ScalarUnit::Amount:
                return value;

            }

            throw std::invalid_argument("Unknown Scalar unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ScalarUnit unit) const
        {
            switch (unit)
            {

            case ScalarUnit::Amount:
                return value_;

            }

            throw std::invalid_argument("Unknown Scalar unit.");
        }

        un_scalar_t value_;
    };
}
