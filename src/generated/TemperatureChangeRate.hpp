#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class TemperatureChangeRateUnit : std::uint8_t
    {
        DegreesCelsiusPerSecond,
        NanodegreesCelsiusPerSecond,
        MicrodegreesCelsiusPerSecond,
        MillidegreesCelsiusPerSecond,
        CentidegreesCelsiusPerSecond,
        DecidegreesCelsiusPerSecond,
        DecadegreesCelsiusPerSecond,
        HectodegreesCelsiusPerSecond,
        KilodegreesCelsiusPerSecond,
        DegreesCelsiusPerMinute,
        DegreesKelvinPerMinute,
        DegreesFahrenheitPerMinute,
        DegreesFahrenheitPerSecond,
        DegreesKelvinPerSecond,
        DegreesCelsiusPerHour,
        DegreesKelvinPerHour,
        DegreesFahrenheitPerHour,
    };

    /// <summary>Temperature change rate is the ratio of the temperature change to the time during which the change occurred (value of temperature changes per unit time).</summary>
    class TemperatureChangeRate
    {
    public:
        constexpr explicit TemperatureChangeRate(
            const un_scalar_t value,
            const TemperatureChangeRateUnit unit = TemperatureChangeRateUnit::DegreesCelsiusPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const TemperatureChangeRateUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr TemperatureChangeRate operator+(const TemperatureChangeRate other) const noexcept
        {
            return TemperatureChangeRate(value_ + other.value_);
        }

        [[nodiscard]] constexpr TemperatureChangeRate operator-(const TemperatureChangeRate other) const noexcept
        {
            return TemperatureChangeRate(value_ - other.value_);
        }

        [[nodiscard]] constexpr TemperatureChangeRate operator*(const un_scalar_t scalar) const noexcept
        {
            return TemperatureChangeRate(value_ * scalar);
        }

        [[nodiscard]] constexpr TemperatureChangeRate operator/(const un_scalar_t scalar) const noexcept
        {
            return TemperatureChangeRate(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const TemperatureChangeRate other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const TemperatureChangeRate other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t degrees_celsius_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DegreesCelsiusPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_degrees_celsius_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DegreesCelsiusPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t nanodegrees_celsius_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::NanodegreesCelsiusPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_nanodegrees_celsius_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::NanodegreesCelsiusPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t microdegrees_celsius_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::MicrodegreesCelsiusPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_microdegrees_celsius_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::MicrodegreesCelsiusPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t millidegrees_celsius_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::MillidegreesCelsiusPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_millidegrees_celsius_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::MillidegreesCelsiusPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t centidegrees_celsius_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::CentidegreesCelsiusPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_centidegrees_celsius_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::CentidegreesCelsiusPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t decidegrees_celsius_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DecidegreesCelsiusPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_decidegrees_celsius_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DecidegreesCelsiusPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t decadegrees_celsius_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DecadegreesCelsiusPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_decadegrees_celsius_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DecadegreesCelsiusPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t hectodegrees_celsius_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::HectodegreesCelsiusPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_hectodegrees_celsius_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::HectodegreesCelsiusPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t kilodegrees_celsius_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::KilodegreesCelsiusPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_kilodegrees_celsius_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::KilodegreesCelsiusPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_celsius_per_minute() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DegreesCelsiusPerMinute);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_degrees_celsius_per_minute(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DegreesCelsiusPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_kelvin_per_minute() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DegreesKelvinPerMinute);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_degrees_kelvin_per_minute(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DegreesKelvinPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_fahrenheit_per_minute() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DegreesFahrenheitPerMinute);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_degrees_fahrenheit_per_minute(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DegreesFahrenheitPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_fahrenheit_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DegreesFahrenheitPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_degrees_fahrenheit_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DegreesFahrenheitPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_kelvin_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DegreesKelvinPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_degrees_kelvin_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DegreesKelvinPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_celsius_per_hour() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DegreesCelsiusPerHour);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_degrees_celsius_per_hour(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DegreesCelsiusPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_kelvin_per_hour() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DegreesKelvinPerHour);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_degrees_kelvin_per_hour(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DegreesKelvinPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t degrees_fahrenheit_per_hour() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DegreesFahrenheitPerHour);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_degrees_fahrenheit_per_hour(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DegreesFahrenheitPerHour);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, TemperatureChangeRateUnit unit)
        {
            switch (unit)
            {

            case TemperatureChangeRateUnit::DegreesCelsiusPerSecond:
                return value;

            case TemperatureChangeRateUnit::NanodegreesCelsiusPerSecond:
                return (value * static_cast<un_scalar_t>(1e-9));

            case TemperatureChangeRateUnit::MicrodegreesCelsiusPerSecond:
                return (value * static_cast<un_scalar_t>(1e-6));

            case TemperatureChangeRateUnit::MillidegreesCelsiusPerSecond:
                return (value * static_cast<un_scalar_t>(1e-3));

            case TemperatureChangeRateUnit::CentidegreesCelsiusPerSecond:
                return (value * static_cast<un_scalar_t>(1e-2));

            case TemperatureChangeRateUnit::DecidegreesCelsiusPerSecond:
                return (value * static_cast<un_scalar_t>(1e-1));

            case TemperatureChangeRateUnit::DecadegreesCelsiusPerSecond:
                return (value * static_cast<un_scalar_t>(1e1));

            case TemperatureChangeRateUnit::HectodegreesCelsiusPerSecond:
                return (value * static_cast<un_scalar_t>(1e2));

            case TemperatureChangeRateUnit::KilodegreesCelsiusPerSecond:
                return (value * static_cast<un_scalar_t>(1e3));

            case TemperatureChangeRateUnit::DegreesCelsiusPerMinute:
                return value / 60;

            case TemperatureChangeRateUnit::DegreesKelvinPerMinute:
                return value / 60;

            case TemperatureChangeRateUnit::DegreesFahrenheitPerMinute:
                return value * 5 / 9 / 60;

            case TemperatureChangeRateUnit::DegreesFahrenheitPerSecond:
                return value * 5 / 9;

            case TemperatureChangeRateUnit::DegreesKelvinPerSecond:
                return value;

            case TemperatureChangeRateUnit::DegreesCelsiusPerHour:
                return value / 3600;

            case TemperatureChangeRateUnit::DegreesKelvinPerHour:
                return value / 3600;

            case TemperatureChangeRateUnit::DegreesFahrenheitPerHour:
                return value * 5 / 9 / 3600;

            }

            throw std::invalid_argument("Unknown TemperatureChangeRate unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const TemperatureChangeRateUnit unit) const
        {
            switch (unit)
            {

            case TemperatureChangeRateUnit::DegreesCelsiusPerSecond:
                return value_;

            case TemperatureChangeRateUnit::NanodegreesCelsiusPerSecond:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case TemperatureChangeRateUnit::MicrodegreesCelsiusPerSecond:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case TemperatureChangeRateUnit::MillidegreesCelsiusPerSecond:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case TemperatureChangeRateUnit::CentidegreesCelsiusPerSecond:
                return (value_) / static_cast<un_scalar_t>(1e-2);

            case TemperatureChangeRateUnit::DecidegreesCelsiusPerSecond:
                return (value_) / static_cast<un_scalar_t>(1e-1);

            case TemperatureChangeRateUnit::DecadegreesCelsiusPerSecond:
                return (value_) / static_cast<un_scalar_t>(1e1);

            case TemperatureChangeRateUnit::HectodegreesCelsiusPerSecond:
                return (value_) / static_cast<un_scalar_t>(1e2);

            case TemperatureChangeRateUnit::KilodegreesCelsiusPerSecond:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case TemperatureChangeRateUnit::DegreesCelsiusPerMinute:
                return value_ * 60;

            case TemperatureChangeRateUnit::DegreesKelvinPerMinute:
                return value_ * 60;

            case TemperatureChangeRateUnit::DegreesFahrenheitPerMinute:
                return value_ * 9 / 5 * 60;

            case TemperatureChangeRateUnit::DegreesFahrenheitPerSecond:
                return value_ * 9 / 5;

            case TemperatureChangeRateUnit::DegreesKelvinPerSecond:
                return value_;

            case TemperatureChangeRateUnit::DegreesCelsiusPerHour:
                return value_ * 3600;

            case TemperatureChangeRateUnit::DegreesKelvinPerHour:
                return value_ * 3600;

            case TemperatureChangeRateUnit::DegreesFahrenheitPerHour:
                return value_ * 9 / 5 * 3600;

            }

            throw std::invalid_argument("Unknown TemperatureChangeRate unit.");
        }

        un_scalar_t value_;
    };
}
