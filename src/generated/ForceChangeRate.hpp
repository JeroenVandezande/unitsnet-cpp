#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ForceChangeRateUnit : std::uint16_t
    {
        NewtonsPerMinute,
        DecanewtonsPerMinute,
        KilonewtonsPerMinute,
        NewtonsPerSecond,
        NanonewtonsPerSecond,
        MicronewtonsPerSecond,
        MillinewtonsPerSecond,
        CentinewtonsPerSecond,
        DecinewtonsPerSecond,
        DecanewtonsPerSecond,
        KilonewtonsPerSecond,
        PoundsForcePerMinute,
        KilopoundsForcePerMinute,
        PoundsForcePerSecond,
        KilopoundsForcePerSecond,
    };

    /// <summary>Force change rate is the ratio of the force change to the time during which the change occurred (value of force changes per unit time).</summary>
    class ForceChangeRate
    {
    public:
        constexpr explicit ForceChangeRate(
            double value,
            ForceChangeRateUnit unit = ForceChangeRateUnit::NewtonsPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ForceChangeRateUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ForceChangeRate operator+(ForceChangeRate other) const noexcept
        {
            return ForceChangeRate(value_ + other.value_);
        }

        [[nodiscard]] constexpr ForceChangeRate operator-(ForceChangeRate other) const noexcept
        {
            return ForceChangeRate(value_ - other.value_);
        }

        [[nodiscard]] constexpr ForceChangeRate operator*(double scalar) const noexcept
        {
            return ForceChangeRate(value_ * scalar);
        }

        [[nodiscard]] constexpr ForceChangeRate operator/(double scalar) const noexcept
        {
            return ForceChangeRate(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ForceChangeRate other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ForceChangeRate other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double newtons_per_minute() const
        {
            return convert_from_base(ForceChangeRateUnit::NewtonsPerMinute);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_newtons_per_minute(double value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::NewtonsPerMinute);
        }


        [[nodiscard]] constexpr double decanewtons_per_minute() const
        {
            return convert_from_base(ForceChangeRateUnit::DecanewtonsPerMinute);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_decanewtons_per_minute(double value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::DecanewtonsPerMinute);
        }


        [[nodiscard]] constexpr double kilonewtons_per_minute() const
        {
            return convert_from_base(ForceChangeRateUnit::KilonewtonsPerMinute);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_kilonewtons_per_minute(double value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::KilonewtonsPerMinute);
        }


        [[nodiscard]] constexpr double newtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::NewtonsPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_newtons_per_second(double value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::NewtonsPerSecond);
        }


        [[nodiscard]] constexpr double nanonewtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::NanonewtonsPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_nanonewtons_per_second(double value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::NanonewtonsPerSecond);
        }


        [[nodiscard]] constexpr double micronewtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::MicronewtonsPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_micronewtons_per_second(double value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::MicronewtonsPerSecond);
        }


        [[nodiscard]] constexpr double millinewtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::MillinewtonsPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_millinewtons_per_second(double value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::MillinewtonsPerSecond);
        }


        [[nodiscard]] constexpr double centinewtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::CentinewtonsPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_centinewtons_per_second(double value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::CentinewtonsPerSecond);
        }


        [[nodiscard]] constexpr double decinewtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::DecinewtonsPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_decinewtons_per_second(double value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::DecinewtonsPerSecond);
        }


        [[nodiscard]] constexpr double decanewtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::DecanewtonsPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_decanewtons_per_second(double value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::DecanewtonsPerSecond);
        }


        [[nodiscard]] constexpr double kilonewtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::KilonewtonsPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_kilonewtons_per_second(double value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::KilonewtonsPerSecond);
        }


        [[nodiscard]] constexpr double pounds_force_per_minute() const
        {
            return convert_from_base(ForceChangeRateUnit::PoundsForcePerMinute);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_pounds_force_per_minute(double value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::PoundsForcePerMinute);
        }


        [[nodiscard]] constexpr double kilopounds_force_per_minute() const
        {
            return convert_from_base(ForceChangeRateUnit::KilopoundsForcePerMinute);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_kilopounds_force_per_minute(double value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::KilopoundsForcePerMinute);
        }


        [[nodiscard]] constexpr double pounds_force_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::PoundsForcePerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_pounds_force_per_second(double value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::PoundsForcePerSecond);
        }


        [[nodiscard]] constexpr double kilopounds_force_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::KilopoundsForcePerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_kilopounds_force_per_second(double value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::KilopoundsForcePerSecond);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ForceChangeRateUnit unit)
        {
            switch (unit)
            {

            case ForceChangeRateUnit::NewtonsPerMinute:
                return value / 60;

            case ForceChangeRateUnit::DecanewtonsPerMinute:
                return (value * 1e1) / 60;

            case ForceChangeRateUnit::KilonewtonsPerMinute:
                return (value * 1e3) / 60;

            case ForceChangeRateUnit::NewtonsPerSecond:
                return value;

            case ForceChangeRateUnit::NanonewtonsPerSecond:
                return (value * 1e-9);

            case ForceChangeRateUnit::MicronewtonsPerSecond:
                return (value * 1e-6);

            case ForceChangeRateUnit::MillinewtonsPerSecond:
                return (value * 1e-3);

            case ForceChangeRateUnit::CentinewtonsPerSecond:
                return (value * 1e-2);

            case ForceChangeRateUnit::DecinewtonsPerSecond:
                return (value * 1e-1);

            case ForceChangeRateUnit::DecanewtonsPerSecond:
                return (value * 1e1);

            case ForceChangeRateUnit::KilonewtonsPerSecond:
                return (value * 1e3);

            case ForceChangeRateUnit::PoundsForcePerMinute:
                return value * 4.4482216152605 / 60;

            case ForceChangeRateUnit::KilopoundsForcePerMinute:
                return (value * 1e3) * 4.4482216152605 / 60;

            case ForceChangeRateUnit::PoundsForcePerSecond:
                return value * 4.4482216152605;

            case ForceChangeRateUnit::KilopoundsForcePerSecond:
                return (value * 1e3) * 4.4482216152605;

            }

            throw std::invalid_argument("Unknown ForceChangeRate unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ForceChangeRateUnit unit) const
        {
            switch (unit)
            {

            case ForceChangeRateUnit::NewtonsPerMinute:
                return value_ * 60;

            case ForceChangeRateUnit::DecanewtonsPerMinute:
                return (value_ * 60) / 1e1;

            case ForceChangeRateUnit::KilonewtonsPerMinute:
                return (value_ * 60) / 1e3;

            case ForceChangeRateUnit::NewtonsPerSecond:
                return value_;

            case ForceChangeRateUnit::NanonewtonsPerSecond:
                return (value_) / 1e-9;

            case ForceChangeRateUnit::MicronewtonsPerSecond:
                return (value_) / 1e-6;

            case ForceChangeRateUnit::MillinewtonsPerSecond:
                return (value_) / 1e-3;

            case ForceChangeRateUnit::CentinewtonsPerSecond:
                return (value_) / 1e-2;

            case ForceChangeRateUnit::DecinewtonsPerSecond:
                return (value_) / 1e-1;

            case ForceChangeRateUnit::DecanewtonsPerSecond:
                return (value_) / 1e1;

            case ForceChangeRateUnit::KilonewtonsPerSecond:
                return (value_) / 1e3;

            case ForceChangeRateUnit::PoundsForcePerMinute:
                return value_ / 4.4482216152605 * 60;

            case ForceChangeRateUnit::KilopoundsForcePerMinute:
                return (value_ / 4.4482216152605 * 60) / 1e3;

            case ForceChangeRateUnit::PoundsForcePerSecond:
                return value_ / 4.4482216152605;

            case ForceChangeRateUnit::KilopoundsForcePerSecond:
                return (value_ / 4.4482216152605) / 1e3;

            }

            throw std::invalid_argument("Unknown ForceChangeRate unit.");
        }

        double value_;
    };
}
