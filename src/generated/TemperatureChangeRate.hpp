#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

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
    class TemperatureChangeRate : public UnitsNetBase
    {
    public:
        constexpr explicit TemperatureChangeRate(
            const un_scalar_t value,
            const TemperatureChangeRateUnit unit = TemperatureChangeRateUnit::DegreesCelsiusPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == TemperatureChangeRateUnit::DegreesCelsiusPerSecond)
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
            if(!base_value_exists_)
            {
                base_value_ = convert_to_base(value_, value_unit_type_);
                base_value_exists_ = true;
            }
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            create_base_value_if_needed();    
            return base_value_;    
        }

        [[nodiscard]] constexpr un_scalar_t value(const TemperatureChangeRateUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr TemperatureChangeRate operator+(const TemperatureChangeRate& other) const noexcept
        {
            return TemperatureChangeRate(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr TemperatureChangeRate operator-(const TemperatureChangeRate& other)const noexcept
        {
            return TemperatureChangeRate(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr TemperatureChangeRate operator*(const un_scalar_t scalar) const noexcept
        {
            return TemperatureChangeRate(base_value() * scalar);
        }

        [[nodiscard]] constexpr TemperatureChangeRate operator/(const un_scalar_t scalar) const noexcept
        {
            return TemperatureChangeRate(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const TemperatureChangeRate& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const TemperatureChangeRate& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const TemperatureChangeRate& other) const noexcept
        {
            return base_value() > other.base_value();
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


        [[nodiscard]] static constexpr TemperatureChangeRate from_invalid()
        {
            return TemperatureChangeRate(false);
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
                return value / static_cast<un_scalar_t>(60);

            case TemperatureChangeRateUnit::DegreesKelvinPerMinute:
                return value / static_cast<un_scalar_t>(60);

            case TemperatureChangeRateUnit::DegreesFahrenheitPerMinute:
                return value * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(9) / static_cast<un_scalar_t>(60);

            case TemperatureChangeRateUnit::DegreesFahrenheitPerSecond:
                return value * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(9);

            case TemperatureChangeRateUnit::DegreesKelvinPerSecond:
                return value;

            case TemperatureChangeRateUnit::DegreesCelsiusPerHour:
                return value / static_cast<un_scalar_t>(3600);

            case TemperatureChangeRateUnit::DegreesKelvinPerHour:
                return value / static_cast<un_scalar_t>(3600);

            case TemperatureChangeRateUnit::DegreesFahrenheitPerHour:
                return value * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(9) / static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown TemperatureChangeRate unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const TemperatureChangeRateUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case TemperatureChangeRateUnit::DegreesCelsiusPerSecond:
                return base_value_;

            case TemperatureChangeRateUnit::NanodegreesCelsiusPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e-9);

            case TemperatureChangeRateUnit::MicrodegreesCelsiusPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e-6);

            case TemperatureChangeRateUnit::MillidegreesCelsiusPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e-3);

            case TemperatureChangeRateUnit::CentidegreesCelsiusPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e-2);

            case TemperatureChangeRateUnit::DecidegreesCelsiusPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e-1);

            case TemperatureChangeRateUnit::DecadegreesCelsiusPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e1);

            case TemperatureChangeRateUnit::HectodegreesCelsiusPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e2);

            case TemperatureChangeRateUnit::KilodegreesCelsiusPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e3);

            case TemperatureChangeRateUnit::DegreesCelsiusPerMinute:
                return base_value_ * static_cast<un_scalar_t>(60);

            case TemperatureChangeRateUnit::DegreesKelvinPerMinute:
                return base_value_ * static_cast<un_scalar_t>(60);

            case TemperatureChangeRateUnit::DegreesFahrenheitPerMinute:
                return base_value_ * static_cast<un_scalar_t>(9) / static_cast<un_scalar_t>(5) * static_cast<un_scalar_t>(60);

            case TemperatureChangeRateUnit::DegreesFahrenheitPerSecond:
                return base_value_ * static_cast<un_scalar_t>(9) / static_cast<un_scalar_t>(5);

            case TemperatureChangeRateUnit::DegreesKelvinPerSecond:
                return base_value_;

            case TemperatureChangeRateUnit::DegreesCelsiusPerHour:
                return base_value_ * static_cast<un_scalar_t>(3600);

            case TemperatureChangeRateUnit::DegreesKelvinPerHour:
                return base_value_ * static_cast<un_scalar_t>(3600);

            case TemperatureChangeRateUnit::DegreesFahrenheitPerHour:
                return base_value_ * static_cast<un_scalar_t>(9) / static_cast<un_scalar_t>(5) * static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown TemperatureChangeRate unit.");
        }

        un_scalar_t value_;
        TemperatureChangeRateUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
