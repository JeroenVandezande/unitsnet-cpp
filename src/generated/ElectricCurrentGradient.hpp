#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

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
    class ElectricCurrentGradient
    {
    public:
        constexpr explicit ElectricCurrentGradient(
            const un_scalar_t value,
            const ElectricCurrentGradientUnit unit = ElectricCurrentGradientUnit::AmperesPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricCurrentGradientUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricCurrentGradient operator+(const ElectricCurrentGradient other) const noexcept
        {
            return ElectricCurrentGradient(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricCurrentGradient operator-(const ElectricCurrentGradient other) const noexcept
        {
            return ElectricCurrentGradient(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricCurrentGradient operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricCurrentGradient(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricCurrentGradient operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricCurrentGradient(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricCurrentGradient other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const ElectricCurrentGradient other) const noexcept
        {
            return value_ < other.value_;
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
                return value / 60;

            case ElectricCurrentGradientUnit::MilliamperesPerMinute:
                return (value * static_cast<un_scalar_t>(1e-3)) / 60;

            case ElectricCurrentGradientUnit::AmperesPerMillisecond:
                return value * 1E3;

            case ElectricCurrentGradientUnit::AmperesPerMicrosecond:
                return value * 1E6;

            case ElectricCurrentGradientUnit::AmperesPerNanosecond:
                return value * 1E9;

            }

            throw std::invalid_argument("Unknown ElectricCurrentGradient unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricCurrentGradientUnit unit) const
        {
            switch (unit)
            {

            case ElectricCurrentGradientUnit::AmperesPerSecond:
                return value_;

            case ElectricCurrentGradientUnit::MilliamperesPerSecond:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case ElectricCurrentGradientUnit::AmperesPerMinute:
                return value_ * 60;

            case ElectricCurrentGradientUnit::MilliamperesPerMinute:
                return (value_ * 60) / static_cast<un_scalar_t>(1e-3);

            case ElectricCurrentGradientUnit::AmperesPerMillisecond:
                return value_ / 1E3;

            case ElectricCurrentGradientUnit::AmperesPerMicrosecond:
                return value_ / 1E6;

            case ElectricCurrentGradientUnit::AmperesPerNanosecond:
                return value_ / 1E9;

            }

            throw std::invalid_argument("Unknown ElectricCurrentGradient unit.");
        }

        un_scalar_t value_;
    };
}
