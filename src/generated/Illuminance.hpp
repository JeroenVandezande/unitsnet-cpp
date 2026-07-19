#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class IlluminanceUnit : std::uint8_t
    {
        Lux,
        Millilux,
        Kilolux,
        Megalux,
    };

    /// <summary>In photometry, illuminance is the total luminous flux incident on a surface, per unit area.</summary>
    class Illuminance
    {
    public:
        constexpr explicit Illuminance(
            const un_scalar_t value,
            const IlluminanceUnit unit = IlluminanceUnit::Lux)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit Illuminance(const bool isValid)
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

        [[nodiscard]] constexpr un_scalar_t value(const IlluminanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Illuminance operator+(const Illuminance other) const noexcept
        {
            return Illuminance(value_ + other.value_);
        }

        [[nodiscard]] constexpr Illuminance operator-(const Illuminance other) const noexcept
        {
            return Illuminance(value_ - other.value_);
        }

        [[nodiscard]] constexpr Illuminance operator*(const un_scalar_t scalar) const noexcept
        {
            return Illuminance(value_ * scalar);
        }

        [[nodiscard]] constexpr Illuminance operator/(const un_scalar_t scalar) const noexcept
        {
            return Illuminance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Illuminance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Illuminance other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const Illuminance other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t lux() const
        {
            return convert_from_base(IlluminanceUnit::Lux);
        }

        [[nodiscard]] static constexpr Illuminance from_lux(const un_scalar_t value)
        {
            return Illuminance(value, IlluminanceUnit::Lux);
        }


        [[nodiscard]] constexpr un_scalar_t millilux() const
        {
            return convert_from_base(IlluminanceUnit::Millilux);
        }

        [[nodiscard]] static constexpr Illuminance from_millilux(const un_scalar_t value)
        {
            return Illuminance(value, IlluminanceUnit::Millilux);
        }


        [[nodiscard]] constexpr un_scalar_t kilolux() const
        {
            return convert_from_base(IlluminanceUnit::Kilolux);
        }

        [[nodiscard]] static constexpr Illuminance from_kilolux(const un_scalar_t value)
        {
            return Illuminance(value, IlluminanceUnit::Kilolux);
        }


        [[nodiscard]] constexpr un_scalar_t megalux() const
        {
            return convert_from_base(IlluminanceUnit::Megalux);
        }

        [[nodiscard]] static constexpr Illuminance from_megalux(const un_scalar_t value)
        {
            return Illuminance(value, IlluminanceUnit::Megalux);
        }


        [[nodiscard]] static constexpr Illuminance from_invalid()
        {
            return Illuminance(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, IlluminanceUnit unit)
        {
            switch (unit)
            {

            case IlluminanceUnit::Lux:
                return value;

            case IlluminanceUnit::Millilux:
                return (value * static_cast<un_scalar_t>(1e-3));

            case IlluminanceUnit::Kilolux:
                return (value * static_cast<un_scalar_t>(1e3));

            case IlluminanceUnit::Megalux:
                return (value * static_cast<un_scalar_t>(1e6));

            }

            throw std::invalid_argument("Unknown Illuminance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const IlluminanceUnit unit) const
        {
            switch (unit)
            {

            case IlluminanceUnit::Lux:
                return value_;

            case IlluminanceUnit::Millilux:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case IlluminanceUnit::Kilolux:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case IlluminanceUnit::Megalux:
                return (value_) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown Illuminance unit.");
        }

        un_scalar_t value_;
    };
}
