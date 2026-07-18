#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class DurationUnit : std::uint16_t
    {
        Years365,
        Months30,
        Weeks,
        Days,
        Hours,
        Minutes,
        Seconds,
        Picoseconds,
        Nanoseconds,
        Microseconds,
        Milliseconds,
        JulianYears,
        Sols,
    };

    /// <summary>Time is a dimension in which events can be ordered from the past through the present into the future, and also the measure of durations of events and the intervals between them.</summary>
    class Duration
    {
    public:
        constexpr explicit Duration(
            double value,
            DurationUnit unit = DurationUnit::Seconds)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(DurationUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Duration operator+(Duration other) const noexcept
        {
            return Duration(value_ + other.value_);
        }

        [[nodiscard]] constexpr Duration operator-(Duration other) const noexcept
        {
            return Duration(value_ - other.value_);
        }

        [[nodiscard]] constexpr Duration operator*(double scalar) const noexcept
        {
            return Duration(value_ * scalar);
        }

        [[nodiscard]] constexpr Duration operator/(double scalar) const noexcept
        {
            return Duration(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Duration other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Duration other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double years365() const
        {
            return convert_from_base(DurationUnit::Years365);
        }

        [[nodiscard]] static constexpr Duration from_years365(double value)
        {
            return Duration(value, DurationUnit::Years365);
        }


        [[nodiscard]] constexpr double months30() const
        {
            return convert_from_base(DurationUnit::Months30);
        }

        [[nodiscard]] static constexpr Duration from_months30(double value)
        {
            return Duration(value, DurationUnit::Months30);
        }


        [[nodiscard]] constexpr double weeks() const
        {
            return convert_from_base(DurationUnit::Weeks);
        }

        [[nodiscard]] static constexpr Duration from_weeks(double value)
        {
            return Duration(value, DurationUnit::Weeks);
        }


        [[nodiscard]] constexpr double days() const
        {
            return convert_from_base(DurationUnit::Days);
        }

        [[nodiscard]] static constexpr Duration from_days(double value)
        {
            return Duration(value, DurationUnit::Days);
        }


        [[nodiscard]] constexpr double hours() const
        {
            return convert_from_base(DurationUnit::Hours);
        }

        [[nodiscard]] static constexpr Duration from_hours(double value)
        {
            return Duration(value, DurationUnit::Hours);
        }


        [[nodiscard]] constexpr double minutes() const
        {
            return convert_from_base(DurationUnit::Minutes);
        }

        [[nodiscard]] static constexpr Duration from_minutes(double value)
        {
            return Duration(value, DurationUnit::Minutes);
        }


        [[nodiscard]] constexpr double seconds() const
        {
            return convert_from_base(DurationUnit::Seconds);
        }

        [[nodiscard]] static constexpr Duration from_seconds(double value)
        {
            return Duration(value, DurationUnit::Seconds);
        }


        [[nodiscard]] constexpr double picoseconds() const
        {
            return convert_from_base(DurationUnit::Picoseconds);
        }

        [[nodiscard]] static constexpr Duration from_picoseconds(double value)
        {
            return Duration(value, DurationUnit::Picoseconds);
        }


        [[nodiscard]] constexpr double nanoseconds() const
        {
            return convert_from_base(DurationUnit::Nanoseconds);
        }

        [[nodiscard]] static constexpr Duration from_nanoseconds(double value)
        {
            return Duration(value, DurationUnit::Nanoseconds);
        }


        [[nodiscard]] constexpr double microseconds() const
        {
            return convert_from_base(DurationUnit::Microseconds);
        }

        [[nodiscard]] static constexpr Duration from_microseconds(double value)
        {
            return Duration(value, DurationUnit::Microseconds);
        }


        [[nodiscard]] constexpr double milliseconds() const
        {
            return convert_from_base(DurationUnit::Milliseconds);
        }

        [[nodiscard]] static constexpr Duration from_milliseconds(double value)
        {
            return Duration(value, DurationUnit::Milliseconds);
        }


        [[nodiscard]] constexpr double julian_years() const
        {
            return convert_from_base(DurationUnit::JulianYears);
        }

        [[nodiscard]] static constexpr Duration from_julian_years(double value)
        {
            return Duration(value, DurationUnit::JulianYears);
        }


        [[nodiscard]] constexpr double sols() const
        {
            return convert_from_base(DurationUnit::Sols);
        }

        [[nodiscard]] static constexpr Duration from_sols(double value)
        {
            return Duration(value, DurationUnit::Sols);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, DurationUnit unit)
        {
            switch (unit)
            {

            case DurationUnit::Years365:
                return value * 365 * 24 * 3600;

            case DurationUnit::Months30:
                return value * 30 * 24 * 3600;

            case DurationUnit::Weeks:
                return value * 7 * 24 * 3600;

            case DurationUnit::Days:
                return value * 24 * 3600;

            case DurationUnit::Hours:
                return value * 3600;

            case DurationUnit::Minutes:
                return value * 60;

            case DurationUnit::Seconds:
                return value;

            case DurationUnit::Picoseconds:
                return (value * 1e-12);

            case DurationUnit::Nanoseconds:
                return (value * 1e-9);

            case DurationUnit::Microseconds:
                return (value * 1e-6);

            case DurationUnit::Milliseconds:
                return (value * 1e-3);

            case DurationUnit::JulianYears:
                return value * 365.25 * 24 * 3600;

            case DurationUnit::Sols:
                return value * 88775.244;

            }

            throw std::invalid_argument("Unknown Duration unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(DurationUnit unit) const
        {
            switch (unit)
            {

            case DurationUnit::Years365:
                return value_ / (365 * 24 * 3600);

            case DurationUnit::Months30:
                return value_ / (30 * 24 * 3600);

            case DurationUnit::Weeks:
                return value_ / (7 * 24 * 3600);

            case DurationUnit::Days:
                return value_ / (24 * 3600);

            case DurationUnit::Hours:
                return value_ / 3600;

            case DurationUnit::Minutes:
                return value_ / 60;

            case DurationUnit::Seconds:
                return value_;

            case DurationUnit::Picoseconds:
                return (value_) / 1e-12;

            case DurationUnit::Nanoseconds:
                return (value_) / 1e-9;

            case DurationUnit::Microseconds:
                return (value_) / 1e-6;

            case DurationUnit::Milliseconds:
                return (value_) / 1e-3;

            case DurationUnit::JulianYears:
                return value_ / (365.25 * 24 * 3600);

            case DurationUnit::Sols:
                return value_ / 88775.244;

            }

            throw std::invalid_argument("Unknown Duration unit.");
        }

        double value_;
    };
}
