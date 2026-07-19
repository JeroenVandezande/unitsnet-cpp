#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ElectricCurrentGradientUnit : std::uint8_t
    {
        AmperesPerSecond,
        MilliamperesPerSecond,
        AmperesPerMinute,
        MilliamperesPerMinute,
        AmperesPerMillisecond,
        AmperesPerMicrosecond,
        AmperesPerNanosecond,
    };

    /// <summary>In electromagnetism, the current gradient describes how the current changes in time.</summary>
    class ElectricCurrentGradient : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricCurrentGradient(
            const un_scalar_t value,
            const ElectricCurrentGradientUnit unit = ElectricCurrentGradientUnit::AmperesPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricCurrentGradientUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricCurrentGradient operator+(const ElectricCurrentGradient& other) const noexcept
        {
            return ElectricCurrentGradient(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricCurrentGradient operator-(const ElectricCurrentGradient& other)const noexcept
        {
            return ElectricCurrentGradient(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricCurrentGradient operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricCurrentGradient(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricCurrentGradient operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricCurrentGradient(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricCurrentGradient& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricCurrentGradient& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricCurrentGradient& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t amperes_per_second() const
        {
            return convert_from_base(ElectricCurrentGradientUnit::AmperesPerSecond);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_amperes_per_second(const un_scalar_t value)
        {
            return ElectricCurrentGradient(value, ElectricCurrentGradientUnit::AmperesPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t milliamperes_per_second() const
        {
            return convert_from_base(ElectricCurrentGradientUnit::MilliamperesPerSecond);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_milliamperes_per_second(const un_scalar_t value)
        {
            return ElectricCurrentGradient(value, ElectricCurrentGradientUnit::MilliamperesPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t amperes_per_minute() const
        {
            return convert_from_base(ElectricCurrentGradientUnit::AmperesPerMinute);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_amperes_per_minute(const un_scalar_t value)
        {
            return ElectricCurrentGradient(value, ElectricCurrentGradientUnit::AmperesPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t milliamperes_per_minute() const
        {
            return convert_from_base(ElectricCurrentGradientUnit::MilliamperesPerMinute);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_milliamperes_per_minute(const un_scalar_t value)
        {
            return ElectricCurrentGradient(value, ElectricCurrentGradientUnit::MilliamperesPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t amperes_per_millisecond() const
        {
            return convert_from_base(ElectricCurrentGradientUnit::AmperesPerMillisecond);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_amperes_per_millisecond(const un_scalar_t value)
        {
            return ElectricCurrentGradient(value, ElectricCurrentGradientUnit::AmperesPerMillisecond);
        }

        [[nodiscard]] constexpr un_scalar_t amperes_per_microsecond() const
        {
            return convert_from_base(ElectricCurrentGradientUnit::AmperesPerMicrosecond);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_amperes_per_microsecond(const un_scalar_t value)
        {
            return ElectricCurrentGradient(value, ElectricCurrentGradientUnit::AmperesPerMicrosecond);
        }

        [[nodiscard]] constexpr un_scalar_t amperes_per_nanosecond() const
        {
            return convert_from_base(ElectricCurrentGradientUnit::AmperesPerNanosecond);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_amperes_per_nanosecond(const un_scalar_t value)
        {
            return ElectricCurrentGradient(value, ElectricCurrentGradientUnit::AmperesPerNanosecond);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_invalid()
        {
            return ElectricCurrentGradient(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricCurrentGradientUnit unit)
        {
            switch (unit)
            {

            case ElectricCurrentGradientUnit::AmperesPerSecond:
                return value;

            case ElectricCurrentGradientUnit::MilliamperesPerSecond:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricCurrentGradientUnit::AmperesPerMinute:
                return value / static_cast<un_scalar_t>(60);

            case ElectricCurrentGradientUnit::MilliamperesPerMinute:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(60);

            case ElectricCurrentGradientUnit::AmperesPerMillisecond:
                return value * static_cast<un_scalar_t>(1E3);

            case ElectricCurrentGradientUnit::AmperesPerMicrosecond:
                return value * static_cast<un_scalar_t>(1E6);

            case ElectricCurrentGradientUnit::AmperesPerNanosecond:
                return value * static_cast<un_scalar_t>(1E9);

            }

            throw std::invalid_argument("Unknown ElectricCurrentGradient unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricCurrentGradientUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricCurrentGradientUnit::AmperesPerSecond:
                return base_value;

            case ElectricCurrentGradientUnit::MilliamperesPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricCurrentGradientUnit::AmperesPerMinute:
                return base_value * static_cast<un_scalar_t>(60);

            case ElectricCurrentGradientUnit::MilliamperesPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e-3);

            case ElectricCurrentGradientUnit::AmperesPerMillisecond:
                return base_value / static_cast<un_scalar_t>(1E3);

            case ElectricCurrentGradientUnit::AmperesPerMicrosecond:
                return base_value / static_cast<un_scalar_t>(1E6);

            case ElectricCurrentGradientUnit::AmperesPerNanosecond:
                return base_value / static_cast<un_scalar_t>(1E9);

            }

            throw std::invalid_argument("Unknown ElectricCurrentGradient unit.");
        }

        un_scalar_t value_;
        ElectricCurrentGradientUnit value_unit_type_;       
    };
}
