#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class FrequencyUnit : std::uint8_t
    {
        Hertz,
        Microhertz,
        Millihertz,
        Kilohertz,
        Megahertz,
        Gigahertz,
        Terahertz,
        RadiansPerSecond,
        CyclesPerMinute,
        CyclesPerHour,
        BeatsPerMinute,
        PerSecond,
    };

    /// <summary>The number of occurrences of a repeating event per unit time.</summary>
    class Frequency
    {
    public:
        constexpr explicit Frequency(
            const un_scalar_t value,
            const FrequencyUnit unit = FrequencyUnit::Hertz)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const FrequencyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Frequency operator+(const Frequency other) const noexcept
        {
            return Frequency(value_ + other.value_);
        }

        [[nodiscard]] constexpr Frequency operator-(const Frequency other) const noexcept
        {
            return Frequency(value_ - other.value_);
        }

        [[nodiscard]] constexpr Frequency operator*(const un_scalar_t scalar) const noexcept
        {
            return Frequency(value_ * scalar);
        }

        [[nodiscard]] constexpr Frequency operator/(const un_scalar_t scalar) const noexcept
        {
            return Frequency(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Frequency other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Frequency other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t hertz() const
        {
            return convert_from_base(FrequencyUnit::Hertz);
        }

        [[nodiscard]] static constexpr Frequency from_hertz(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::Hertz);
        }


        [[nodiscard]] constexpr un_scalar_t microhertz() const
        {
            return convert_from_base(FrequencyUnit::Microhertz);
        }

        [[nodiscard]] static constexpr Frequency from_microhertz(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::Microhertz);
        }


        [[nodiscard]] constexpr un_scalar_t millihertz() const
        {
            return convert_from_base(FrequencyUnit::Millihertz);
        }

        [[nodiscard]] static constexpr Frequency from_millihertz(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::Millihertz);
        }


        [[nodiscard]] constexpr un_scalar_t kilohertz() const
        {
            return convert_from_base(FrequencyUnit::Kilohertz);
        }

        [[nodiscard]] static constexpr Frequency from_kilohertz(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::Kilohertz);
        }


        [[nodiscard]] constexpr un_scalar_t megahertz() const
        {
            return convert_from_base(FrequencyUnit::Megahertz);
        }

        [[nodiscard]] static constexpr Frequency from_megahertz(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::Megahertz);
        }


        [[nodiscard]] constexpr un_scalar_t gigahertz() const
        {
            return convert_from_base(FrequencyUnit::Gigahertz);
        }

        [[nodiscard]] static constexpr Frequency from_gigahertz(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::Gigahertz);
        }


        [[nodiscard]] constexpr un_scalar_t terahertz() const
        {
            return convert_from_base(FrequencyUnit::Terahertz);
        }

        [[nodiscard]] static constexpr Frequency from_terahertz(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::Terahertz);
        }


        [[nodiscard]] constexpr un_scalar_t radians_per_second() const
        {
            return convert_from_base(FrequencyUnit::RadiansPerSecond);
        }

        [[nodiscard]] static constexpr Frequency from_radians_per_second(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::RadiansPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t cycles_per_minute() const
        {
            return convert_from_base(FrequencyUnit::CyclesPerMinute);
        }

        [[nodiscard]] static constexpr Frequency from_cycles_per_minute(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::CyclesPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t cycles_per_hour() const
        {
            return convert_from_base(FrequencyUnit::CyclesPerHour);
        }

        [[nodiscard]] static constexpr Frequency from_cycles_per_hour(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::CyclesPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t beats_per_minute() const
        {
            return convert_from_base(FrequencyUnit::BeatsPerMinute);
        }

        [[nodiscard]] static constexpr Frequency from_beats_per_minute(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::BeatsPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t per_second() const
        {
            return convert_from_base(FrequencyUnit::PerSecond);
        }

        [[nodiscard]] static constexpr Frequency from_per_second(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::PerSecond);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, FrequencyUnit unit)
        {
            switch (unit)
            {

            case FrequencyUnit::Hertz:
                return value;

            case FrequencyUnit::Microhertz:
                return (value * static_cast<un_scalar_t>(1e-6));

            case FrequencyUnit::Millihertz:
                return (value * static_cast<un_scalar_t>(1e-3));

            case FrequencyUnit::Kilohertz:
                return (value * static_cast<un_scalar_t>(1e3));

            case FrequencyUnit::Megahertz:
                return (value * static_cast<un_scalar_t>(1e6));

            case FrequencyUnit::Gigahertz:
                return (value * static_cast<un_scalar_t>(1e9));

            case FrequencyUnit::Terahertz:
                return (value * static_cast<un_scalar_t>(1e12));

            case FrequencyUnit::RadiansPerSecond:
                return value / (static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>);

            case FrequencyUnit::CyclesPerMinute:
                return value / static_cast<un_scalar_t>(60);

            case FrequencyUnit::CyclesPerHour:
                return value / static_cast<un_scalar_t>(3600);

            case FrequencyUnit::BeatsPerMinute:
                return value / static_cast<un_scalar_t>(60);

            case FrequencyUnit::PerSecond:
                return value;

            }

            throw std::invalid_argument("Unknown Frequency unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const FrequencyUnit unit) const
        {
            switch (unit)
            {

            case FrequencyUnit::Hertz:
                return value_;

            case FrequencyUnit::Microhertz:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case FrequencyUnit::Millihertz:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case FrequencyUnit::Kilohertz:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case FrequencyUnit::Megahertz:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case FrequencyUnit::Gigahertz:
                return (value_) / static_cast<un_scalar_t>(1e9);

            case FrequencyUnit::Terahertz:
                return (value_) / static_cast<un_scalar_t>(1e12);

            case FrequencyUnit::RadiansPerSecond:
                return value_ * (static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>);

            case FrequencyUnit::CyclesPerMinute:
                return value_ * static_cast<un_scalar_t>(60);

            case FrequencyUnit::CyclesPerHour:
                return value_ * static_cast<un_scalar_t>(3600);

            case FrequencyUnit::BeatsPerMinute:
                return value_ * static_cast<un_scalar_t>(60);

            case FrequencyUnit::PerSecond:
                return value_;

            }

            throw std::invalid_argument("Unknown Frequency unit.");
        }

        un_scalar_t value_;
    };
}
