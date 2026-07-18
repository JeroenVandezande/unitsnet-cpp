#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class FrequencyUnit : std::uint16_t
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
            double value,
            FrequencyUnit unit = FrequencyUnit::Hertz)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(FrequencyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Frequency operator+(Frequency other) const noexcept
        {
            return Frequency(value_ + other.value_);
        }

        [[nodiscard]] constexpr Frequency operator-(Frequency other) const noexcept
        {
            return Frequency(value_ - other.value_);
        }

        [[nodiscard]] constexpr Frequency operator*(double scalar) const noexcept
        {
            return Frequency(value_ * scalar);
        }

        [[nodiscard]] constexpr Frequency operator/(double scalar) const noexcept
        {
            return Frequency(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Frequency other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Frequency other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double hertz() const
        {
            return convert_from_base(FrequencyUnit::Hertz);
        }

        [[nodiscard]] static constexpr Frequency from_hertz(double value)
        {
            return Frequency(value, FrequencyUnit::Hertz);
        }


        [[nodiscard]] constexpr double microhertz() const
        {
            return convert_from_base(FrequencyUnit::Microhertz);
        }

        [[nodiscard]] static constexpr Frequency from_microhertz(double value)
        {
            return Frequency(value, FrequencyUnit::Microhertz);
        }


        [[nodiscard]] constexpr double millihertz() const
        {
            return convert_from_base(FrequencyUnit::Millihertz);
        }

        [[nodiscard]] static constexpr Frequency from_millihertz(double value)
        {
            return Frequency(value, FrequencyUnit::Millihertz);
        }


        [[nodiscard]] constexpr double kilohertz() const
        {
            return convert_from_base(FrequencyUnit::Kilohertz);
        }

        [[nodiscard]] static constexpr Frequency from_kilohertz(double value)
        {
            return Frequency(value, FrequencyUnit::Kilohertz);
        }


        [[nodiscard]] constexpr double megahertz() const
        {
            return convert_from_base(FrequencyUnit::Megahertz);
        }

        [[nodiscard]] static constexpr Frequency from_megahertz(double value)
        {
            return Frequency(value, FrequencyUnit::Megahertz);
        }


        [[nodiscard]] constexpr double gigahertz() const
        {
            return convert_from_base(FrequencyUnit::Gigahertz);
        }

        [[nodiscard]] static constexpr Frequency from_gigahertz(double value)
        {
            return Frequency(value, FrequencyUnit::Gigahertz);
        }


        [[nodiscard]] constexpr double terahertz() const
        {
            return convert_from_base(FrequencyUnit::Terahertz);
        }

        [[nodiscard]] static constexpr Frequency from_terahertz(double value)
        {
            return Frequency(value, FrequencyUnit::Terahertz);
        }


        [[nodiscard]] constexpr double radians_per_second() const
        {
            return convert_from_base(FrequencyUnit::RadiansPerSecond);
        }

        [[nodiscard]] static constexpr Frequency from_radians_per_second(double value)
        {
            return Frequency(value, FrequencyUnit::RadiansPerSecond);
        }


        [[nodiscard]] constexpr double cycles_per_minute() const
        {
            return convert_from_base(FrequencyUnit::CyclesPerMinute);
        }

        [[nodiscard]] static constexpr Frequency from_cycles_per_minute(double value)
        {
            return Frequency(value, FrequencyUnit::CyclesPerMinute);
        }


        [[nodiscard]] constexpr double cycles_per_hour() const
        {
            return convert_from_base(FrequencyUnit::CyclesPerHour);
        }

        [[nodiscard]] static constexpr Frequency from_cycles_per_hour(double value)
        {
            return Frequency(value, FrequencyUnit::CyclesPerHour);
        }


        [[nodiscard]] constexpr double beats_per_minute() const
        {
            return convert_from_base(FrequencyUnit::BeatsPerMinute);
        }

        [[nodiscard]] static constexpr Frequency from_beats_per_minute(double value)
        {
            return Frequency(value, FrequencyUnit::BeatsPerMinute);
        }


        [[nodiscard]] constexpr double per_second() const
        {
            return convert_from_base(FrequencyUnit::PerSecond);
        }

        [[nodiscard]] static constexpr Frequency from_per_second(double value)
        {
            return Frequency(value, FrequencyUnit::PerSecond);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, FrequencyUnit unit)
        {
            switch (unit)
            {

            case FrequencyUnit::Hertz:
                return value;

            case FrequencyUnit::Microhertz:
                return (value * 1e-6);

            case FrequencyUnit::Millihertz:
                return (value * 1e-3);

            case FrequencyUnit::Kilohertz:
                return (value * 1e3);

            case FrequencyUnit::Megahertz:
                return (value * 1e6);

            case FrequencyUnit::Gigahertz:
                return (value * 1e9);

            case FrequencyUnit::Terahertz:
                return (value * 1e12);

            case FrequencyUnit::RadiansPerSecond:
                return value / (2 * std::numbers::pi);

            case FrequencyUnit::CyclesPerMinute:
                return value / 60;

            case FrequencyUnit::CyclesPerHour:
                return value / 3600;

            case FrequencyUnit::BeatsPerMinute:
                return value / 60;

            case FrequencyUnit::PerSecond:
                return value;

            }

            throw std::invalid_argument("Unknown Frequency unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(FrequencyUnit unit) const
        {
            switch (unit)
            {

            case FrequencyUnit::Hertz:
                return value_;

            case FrequencyUnit::Microhertz:
                return (value_) / 1e-6;

            case FrequencyUnit::Millihertz:
                return (value_) / 1e-3;

            case FrequencyUnit::Kilohertz:
                return (value_) / 1e3;

            case FrequencyUnit::Megahertz:
                return (value_) / 1e6;

            case FrequencyUnit::Gigahertz:
                return (value_) / 1e9;

            case FrequencyUnit::Terahertz:
                return (value_) / 1e12;

            case FrequencyUnit::RadiansPerSecond:
                return value_ * (2 * std::numbers::pi);

            case FrequencyUnit::CyclesPerMinute:
                return value_ * 60;

            case FrequencyUnit::CyclesPerHour:
                return value_ * 3600;

            case FrequencyUnit::BeatsPerMinute:
                return value_ * 60;

            case FrequencyUnit::PerSecond:
                return value_;

            }

            throw std::invalid_argument("Unknown Frequency unit.");
        }

        double value_;
    };
}
