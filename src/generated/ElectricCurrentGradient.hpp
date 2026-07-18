#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricCurrentGradientUnit : std::uint16_t
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
            double value,
            ElectricCurrentGradientUnit unit = ElectricCurrentGradientUnit::AmperesPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricCurrentGradientUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricCurrentGradient operator+(ElectricCurrentGradient other) const noexcept
        {
            return ElectricCurrentGradient(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricCurrentGradient operator-(ElectricCurrentGradient other) const noexcept
        {
            return ElectricCurrentGradient(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricCurrentGradient operator*(double scalar) const noexcept
        {
            return ElectricCurrentGradient(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricCurrentGradient operator/(double scalar) const noexcept
        {
            return ElectricCurrentGradient(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricCurrentGradient other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricCurrentGradient other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double amperes_per_second() const
        {
            return convert_from_base(ElectricCurrentGradientUnit::AmperesPerSecond);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_amperes_per_second(double value)
        {
            return ElectricCurrentGradient(value, ElectricCurrentGradientUnit::AmperesPerSecond);
        }


        [[nodiscard]] constexpr double milliamperes_per_second() const
        {
            return convert_from_base(ElectricCurrentGradientUnit::MilliamperesPerSecond);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_milliamperes_per_second(double value)
        {
            return ElectricCurrentGradient(value, ElectricCurrentGradientUnit::MilliamperesPerSecond);
        }


        [[nodiscard]] constexpr double amperes_per_minute() const
        {
            return convert_from_base(ElectricCurrentGradientUnit::AmperesPerMinute);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_amperes_per_minute(double value)
        {
            return ElectricCurrentGradient(value, ElectricCurrentGradientUnit::AmperesPerMinute);
        }


        [[nodiscard]] constexpr double milliamperes_per_minute() const
        {
            return convert_from_base(ElectricCurrentGradientUnit::MilliamperesPerMinute);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_milliamperes_per_minute(double value)
        {
            return ElectricCurrentGradient(value, ElectricCurrentGradientUnit::MilliamperesPerMinute);
        }


        [[nodiscard]] constexpr double amperes_per_millisecond() const
        {
            return convert_from_base(ElectricCurrentGradientUnit::AmperesPerMillisecond);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_amperes_per_millisecond(double value)
        {
            return ElectricCurrentGradient(value, ElectricCurrentGradientUnit::AmperesPerMillisecond);
        }


        [[nodiscard]] constexpr double amperes_per_microsecond() const
        {
            return convert_from_base(ElectricCurrentGradientUnit::AmperesPerMicrosecond);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_amperes_per_microsecond(double value)
        {
            return ElectricCurrentGradient(value, ElectricCurrentGradientUnit::AmperesPerMicrosecond);
        }


        [[nodiscard]] constexpr double amperes_per_nanosecond() const
        {
            return convert_from_base(ElectricCurrentGradientUnit::AmperesPerNanosecond);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_amperes_per_nanosecond(double value)
        {
            return ElectricCurrentGradient(value, ElectricCurrentGradientUnit::AmperesPerNanosecond);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricCurrentGradientUnit unit)
        {
            switch (unit)
            {

            case ElectricCurrentGradientUnit::AmperesPerSecond:
                return value;

            case ElectricCurrentGradientUnit::MilliamperesPerSecond:
                return (value * 1e-3);

            case ElectricCurrentGradientUnit::AmperesPerMinute:
                return value / 60;

            case ElectricCurrentGradientUnit::MilliamperesPerMinute:
                return (value * 1e-3) / 60;

            case ElectricCurrentGradientUnit::AmperesPerMillisecond:
                return value * 1E3;

            case ElectricCurrentGradientUnit::AmperesPerMicrosecond:
                return value * 1E6;

            case ElectricCurrentGradientUnit::AmperesPerNanosecond:
                return value * 1E9;

            }

            throw std::invalid_argument("Unknown ElectricCurrentGradient unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricCurrentGradientUnit unit) const
        {
            switch (unit)
            {

            case ElectricCurrentGradientUnit::AmperesPerSecond:
                return value_;

            case ElectricCurrentGradientUnit::MilliamperesPerSecond:
                return (value_) / 1e-3;

            case ElectricCurrentGradientUnit::AmperesPerMinute:
                return value_ * 60;

            case ElectricCurrentGradientUnit::MilliamperesPerMinute:
                return (value_ * 60) / 1e-3;

            case ElectricCurrentGradientUnit::AmperesPerMillisecond:
                return value_ / 1E3;

            case ElectricCurrentGradientUnit::AmperesPerMicrosecond:
                return value_ / 1E6;

            case ElectricCurrentGradientUnit::AmperesPerNanosecond:
                return value_ / 1E9;

            }

            throw std::invalid_argument("Unknown ElectricCurrentGradient unit.");
        }

        double value_;
    };
}
