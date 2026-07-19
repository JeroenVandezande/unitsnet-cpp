#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class DurationUnit : std::uint8_t
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
    class Duration : public UnitsNetBase
    {
    public:
        constexpr explicit Duration(
            const un_scalar_t value,
            const DurationUnit unit = DurationUnit::Seconds)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == DurationUnit::Seconds)
            {
                base_value_ = value;
                base_value_exists_ = true;
            }
            else
            {
                base_value_ = 0;
                base_value_exists_ = false;
            }
        }
        
        constexpr void create_base_value_if_needed() const noexcept
        {
            if(base_value_exists_)
            {
                return;
            }
            else
            {
                base_value_ = convert_to_base(value_, value_unit_type_);
                base_value_exists_ = true;
                return;
            }
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            create_base_value_if_needed();    
            return base_value_;    
        }

        [[nodiscard]] constexpr un_scalar_t value(const DurationUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Duration operator+(const Duration& other) const noexcept
        {
            return Duration(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Duration operator-(const Duration& other)const noexcept
        {
            return Duration(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Duration operator*(const un_scalar_t scalar) const noexcept
        {
            return Duration(base_value() * scalar);
        }

        [[nodiscard]] constexpr Duration operator/(const un_scalar_t scalar) const noexcept
        {
            return Duration(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Duration& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Duration& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Duration& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t years365() const
        {
            return convert_from_base(DurationUnit::Years365);
        }

        [[nodiscard]] static constexpr Duration from_years365(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Years365);
        }


        [[nodiscard]] constexpr un_scalar_t months30() const
        {
            return convert_from_base(DurationUnit::Months30);
        }

        [[nodiscard]] static constexpr Duration from_months30(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Months30);
        }


        [[nodiscard]] constexpr un_scalar_t weeks() const
        {
            return convert_from_base(DurationUnit::Weeks);
        }

        [[nodiscard]] static constexpr Duration from_weeks(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Weeks);
        }


        [[nodiscard]] constexpr un_scalar_t days() const
        {
            return convert_from_base(DurationUnit::Days);
        }

        [[nodiscard]] static constexpr Duration from_days(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Days);
        }


        [[nodiscard]] constexpr un_scalar_t hours() const
        {
            return convert_from_base(DurationUnit::Hours);
        }

        [[nodiscard]] static constexpr Duration from_hours(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Hours);
        }


        [[nodiscard]] constexpr un_scalar_t minutes() const
        {
            return convert_from_base(DurationUnit::Minutes);
        }

        [[nodiscard]] static constexpr Duration from_minutes(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Minutes);
        }


        [[nodiscard]] constexpr un_scalar_t seconds() const
        {
            return convert_from_base(DurationUnit::Seconds);
        }

        [[nodiscard]] static constexpr Duration from_seconds(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Seconds);
        }


        [[nodiscard]] constexpr un_scalar_t picoseconds() const
        {
            return convert_from_base(DurationUnit::Picoseconds);
        }

        [[nodiscard]] static constexpr Duration from_picoseconds(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Picoseconds);
        }


        [[nodiscard]] constexpr un_scalar_t nanoseconds() const
        {
            return convert_from_base(DurationUnit::Nanoseconds);
        }

        [[nodiscard]] static constexpr Duration from_nanoseconds(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Nanoseconds);
        }


        [[nodiscard]] constexpr un_scalar_t microseconds() const
        {
            return convert_from_base(DurationUnit::Microseconds);
        }

        [[nodiscard]] static constexpr Duration from_microseconds(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Microseconds);
        }


        [[nodiscard]] constexpr un_scalar_t milliseconds() const
        {
            return convert_from_base(DurationUnit::Milliseconds);
        }

        [[nodiscard]] static constexpr Duration from_milliseconds(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Milliseconds);
        }


        [[nodiscard]] constexpr un_scalar_t julian_years() const
        {
            return convert_from_base(DurationUnit::JulianYears);
        }

        [[nodiscard]] static constexpr Duration from_julian_years(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::JulianYears);
        }


        [[nodiscard]] constexpr un_scalar_t sols() const
        {
            return convert_from_base(DurationUnit::Sols);
        }

        [[nodiscard]] static constexpr Duration from_sols(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Sols);
        }


        [[nodiscard]] static constexpr Duration from_invalid()
        {
            return Duration(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, DurationUnit unit)
        {
            switch (unit)
            {

            case DurationUnit::Years365:
                return value * static_cast<un_scalar_t>(365) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600);

            case DurationUnit::Months30:
                return value * static_cast<un_scalar_t>(30) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600);

            case DurationUnit::Weeks:
                return value * static_cast<un_scalar_t>(7) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600);

            case DurationUnit::Days:
                return value * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600);

            case DurationUnit::Hours:
                return value * static_cast<un_scalar_t>(3600);

            case DurationUnit::Minutes:
                return value * static_cast<un_scalar_t>(60);

            case DurationUnit::Seconds:
                return value;

            case DurationUnit::Picoseconds:
                return (value * static_cast<un_scalar_t>(1e-12));

            case DurationUnit::Nanoseconds:
                return (value * static_cast<un_scalar_t>(1e-9));

            case DurationUnit::Microseconds:
                return (value * static_cast<un_scalar_t>(1e-6));

            case DurationUnit::Milliseconds:
                return (value * static_cast<un_scalar_t>(1e-3));

            case DurationUnit::JulianYears:
                return value * static_cast<un_scalar_t>(365.25) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600);

            case DurationUnit::Sols:
                return value * static_cast<un_scalar_t>(88775.244);

            }

            throw std::invalid_argument("Unknown Duration unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const DurationUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case DurationUnit::Years365:
                return base_value_ / (static_cast<un_scalar_t>(365) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600));

            case DurationUnit::Months30:
                return base_value_ / (static_cast<un_scalar_t>(30) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600));

            case DurationUnit::Weeks:
                return base_value_ / (static_cast<un_scalar_t>(7) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600));

            case DurationUnit::Days:
                return base_value_ / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600));

            case DurationUnit::Hours:
                return base_value_ / static_cast<un_scalar_t>(3600);

            case DurationUnit::Minutes:
                return base_value_ / static_cast<un_scalar_t>(60);

            case DurationUnit::Seconds:
                return base_value_;

            case DurationUnit::Picoseconds:
                return (base_value_) / static_cast<un_scalar_t>(1e-12);

            case DurationUnit::Nanoseconds:
                return (base_value_) / static_cast<un_scalar_t>(1e-9);

            case DurationUnit::Microseconds:
                return (base_value_) / static_cast<un_scalar_t>(1e-6);

            case DurationUnit::Milliseconds:
                return (base_value_) / static_cast<un_scalar_t>(1e-3);

            case DurationUnit::JulianYears:
                return base_value_ / (static_cast<un_scalar_t>(365.25) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600));

            case DurationUnit::Sols:
                return base_value_ / static_cast<un_scalar_t>(88775.244);

            }

            throw std::invalid_argument("Unknown Duration unit.");
        }

        un_scalar_t value_;
        DurationUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
