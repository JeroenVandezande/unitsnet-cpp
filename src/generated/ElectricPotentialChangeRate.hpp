#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricPotentialChangeRateUnit : std::uint16_t
    {
        VoltsPerSecond,
        MicrovoltsPerSecond,
        MillivoltsPerSecond,
        KilovoltsPerSecond,
        MegavoltsPerSecond,
        VoltsPerMicrosecond,
        MicrovoltsPerMicrosecond,
        MillivoltsPerMicrosecond,
        KilovoltsPerMicrosecond,
        MegavoltsPerMicrosecond,
        VoltsPerMinute,
        MicrovoltsPerMinute,
        MillivoltsPerMinute,
        KilovoltsPerMinute,
        MegavoltsPerMinute,
        VoltsPerHour,
        MicrovoltsPerHour,
        MillivoltsPerHour,
        KilovoltsPerHour,
        MegavoltsPerHour,
    };

    /// <summary>ElectricPotential change rate is the ratio of the electric potential change to the time during which the change occurred (value of electric potential changes per unit time).</summary>
    class ElectricPotentialChangeRate
    {
    public:
        constexpr explicit ElectricPotentialChangeRate(
            double value,
            ElectricPotentialChangeRateUnit unit = ElectricPotentialChangeRateUnit::VoltsPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricPotentialChangeRateUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricPotentialChangeRate operator+(ElectricPotentialChangeRate other) const noexcept
        {
            return ElectricPotentialChangeRate(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricPotentialChangeRate operator-(ElectricPotentialChangeRate other) const noexcept
        {
            return ElectricPotentialChangeRate(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricPotentialChangeRate operator*(double scalar) const noexcept
        {
            return ElectricPotentialChangeRate(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricPotentialChangeRate operator/(double scalar) const noexcept
        {
            return ElectricPotentialChangeRate(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricPotentialChangeRate other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricPotentialChangeRate other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double volts_per_second() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::VoltsPerSecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_volts_per_second(double value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::VoltsPerSecond);
        }


        [[nodiscard]] constexpr double microvolts_per_second() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MicrovoltsPerSecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_microvolts_per_second(double value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MicrovoltsPerSecond);
        }


        [[nodiscard]] constexpr double millivolts_per_second() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MillivoltsPerSecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_millivolts_per_second(double value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MillivoltsPerSecond);
        }


        [[nodiscard]] constexpr double kilovolts_per_second() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::KilovoltsPerSecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_kilovolts_per_second(double value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::KilovoltsPerSecond);
        }


        [[nodiscard]] constexpr double megavolts_per_second() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MegavoltsPerSecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_megavolts_per_second(double value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MegavoltsPerSecond);
        }


        [[nodiscard]] constexpr double volts_per_microsecond() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::VoltsPerMicrosecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_volts_per_microsecond(double value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::VoltsPerMicrosecond);
        }


        [[nodiscard]] constexpr double microvolts_per_microsecond() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MicrovoltsPerMicrosecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_microvolts_per_microsecond(double value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MicrovoltsPerMicrosecond);
        }


        [[nodiscard]] constexpr double millivolts_per_microsecond() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MillivoltsPerMicrosecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_millivolts_per_microsecond(double value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MillivoltsPerMicrosecond);
        }


        [[nodiscard]] constexpr double kilovolts_per_microsecond() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::KilovoltsPerMicrosecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_kilovolts_per_microsecond(double value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::KilovoltsPerMicrosecond);
        }


        [[nodiscard]] constexpr double megavolts_per_microsecond() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MegavoltsPerMicrosecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_megavolts_per_microsecond(double value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MegavoltsPerMicrosecond);
        }


        [[nodiscard]] constexpr double volts_per_minute() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::VoltsPerMinute);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_volts_per_minute(double value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::VoltsPerMinute);
        }


        [[nodiscard]] constexpr double microvolts_per_minute() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MicrovoltsPerMinute);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_microvolts_per_minute(double value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MicrovoltsPerMinute);
        }


        [[nodiscard]] constexpr double millivolts_per_minute() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MillivoltsPerMinute);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_millivolts_per_minute(double value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MillivoltsPerMinute);
        }


        [[nodiscard]] constexpr double kilovolts_per_minute() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::KilovoltsPerMinute);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_kilovolts_per_minute(double value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::KilovoltsPerMinute);
        }


        [[nodiscard]] constexpr double megavolts_per_minute() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MegavoltsPerMinute);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_megavolts_per_minute(double value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MegavoltsPerMinute);
        }


        [[nodiscard]] constexpr double volts_per_hour() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::VoltsPerHour);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_volts_per_hour(double value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::VoltsPerHour);
        }


        [[nodiscard]] constexpr double microvolts_per_hour() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MicrovoltsPerHour);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_microvolts_per_hour(double value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MicrovoltsPerHour);
        }


        [[nodiscard]] constexpr double millivolts_per_hour() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MillivoltsPerHour);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_millivolts_per_hour(double value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MillivoltsPerHour);
        }


        [[nodiscard]] constexpr double kilovolts_per_hour() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::KilovoltsPerHour);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_kilovolts_per_hour(double value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::KilovoltsPerHour);
        }


        [[nodiscard]] constexpr double megavolts_per_hour() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MegavoltsPerHour);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_megavolts_per_hour(double value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MegavoltsPerHour);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricPotentialChangeRateUnit unit)
        {
            switch (unit)
            {

            case ElectricPotentialChangeRateUnit::VoltsPerSecond:
                return value;

            case ElectricPotentialChangeRateUnit::MicrovoltsPerSecond:
                return (value * 1e-6);

            case ElectricPotentialChangeRateUnit::MillivoltsPerSecond:
                return (value * 1e-3);

            case ElectricPotentialChangeRateUnit::KilovoltsPerSecond:
                return (value * 1e3);

            case ElectricPotentialChangeRateUnit::MegavoltsPerSecond:
                return (value * 1e6);

            case ElectricPotentialChangeRateUnit::VoltsPerMicrosecond:
                return value * 1E6;

            case ElectricPotentialChangeRateUnit::MicrovoltsPerMicrosecond:
                return (value * 1e-6) * 1E6;

            case ElectricPotentialChangeRateUnit::MillivoltsPerMicrosecond:
                return (value * 1e-3) * 1E6;

            case ElectricPotentialChangeRateUnit::KilovoltsPerMicrosecond:
                return (value * 1e3) * 1E6;

            case ElectricPotentialChangeRateUnit::MegavoltsPerMicrosecond:
                return (value * 1e6) * 1E6;

            case ElectricPotentialChangeRateUnit::VoltsPerMinute:
                return value / 60;

            case ElectricPotentialChangeRateUnit::MicrovoltsPerMinute:
                return (value * 1e-6) / 60;

            case ElectricPotentialChangeRateUnit::MillivoltsPerMinute:
                return (value * 1e-3) / 60;

            case ElectricPotentialChangeRateUnit::KilovoltsPerMinute:
                return (value * 1e3) / 60;

            case ElectricPotentialChangeRateUnit::MegavoltsPerMinute:
                return (value * 1e6) / 60;

            case ElectricPotentialChangeRateUnit::VoltsPerHour:
                return value / 3600;

            case ElectricPotentialChangeRateUnit::MicrovoltsPerHour:
                return (value * 1e-6) / 3600;

            case ElectricPotentialChangeRateUnit::MillivoltsPerHour:
                return (value * 1e-3) / 3600;

            case ElectricPotentialChangeRateUnit::KilovoltsPerHour:
                return (value * 1e3) / 3600;

            case ElectricPotentialChangeRateUnit::MegavoltsPerHour:
                return (value * 1e6) / 3600;

            }

            throw std::invalid_argument("Unknown ElectricPotentialChangeRate unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricPotentialChangeRateUnit unit) const
        {
            switch (unit)
            {

            case ElectricPotentialChangeRateUnit::VoltsPerSecond:
                return value_;

            case ElectricPotentialChangeRateUnit::MicrovoltsPerSecond:
                return (value_) / 1e-6;

            case ElectricPotentialChangeRateUnit::MillivoltsPerSecond:
                return (value_) / 1e-3;

            case ElectricPotentialChangeRateUnit::KilovoltsPerSecond:
                return (value_) / 1e3;

            case ElectricPotentialChangeRateUnit::MegavoltsPerSecond:
                return (value_) / 1e6;

            case ElectricPotentialChangeRateUnit::VoltsPerMicrosecond:
                return value_ / 1E6;

            case ElectricPotentialChangeRateUnit::MicrovoltsPerMicrosecond:
                return (value_ / 1E6) / 1e-6;

            case ElectricPotentialChangeRateUnit::MillivoltsPerMicrosecond:
                return (value_ / 1E6) / 1e-3;

            case ElectricPotentialChangeRateUnit::KilovoltsPerMicrosecond:
                return (value_ / 1E6) / 1e3;

            case ElectricPotentialChangeRateUnit::MegavoltsPerMicrosecond:
                return (value_ / 1E6) / 1e6;

            case ElectricPotentialChangeRateUnit::VoltsPerMinute:
                return value_ * 60;

            case ElectricPotentialChangeRateUnit::MicrovoltsPerMinute:
                return (value_ * 60) / 1e-6;

            case ElectricPotentialChangeRateUnit::MillivoltsPerMinute:
                return (value_ * 60) / 1e-3;

            case ElectricPotentialChangeRateUnit::KilovoltsPerMinute:
                return (value_ * 60) / 1e3;

            case ElectricPotentialChangeRateUnit::MegavoltsPerMinute:
                return (value_ * 60) / 1e6;

            case ElectricPotentialChangeRateUnit::VoltsPerHour:
                return value_ * 3600;

            case ElectricPotentialChangeRateUnit::MicrovoltsPerHour:
                return (value_ * 3600) / 1e-6;

            case ElectricPotentialChangeRateUnit::MillivoltsPerHour:
                return (value_ * 3600) / 1e-3;

            case ElectricPotentialChangeRateUnit::KilovoltsPerHour:
                return (value_ * 3600) / 1e3;

            case ElectricPotentialChangeRateUnit::MegavoltsPerHour:
                return (value_ * 3600) / 1e6;

            }

            throw std::invalid_argument("Unknown ElectricPotentialChangeRate unit.");
        }

        double value_;
    };
}
