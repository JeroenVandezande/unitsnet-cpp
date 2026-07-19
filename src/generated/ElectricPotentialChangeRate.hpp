#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ElectricPotentialChangeRateUnit : std::uint8_t
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
    class ElectricPotentialChangeRate : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricPotentialChangeRate(
            const un_scalar_t value,
            const ElectricPotentialChangeRateUnit unit = ElectricPotentialChangeRateUnit::VoltsPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == ElectricPotentialChangeRateUnit::VoltsPerSecond)
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

        [[nodiscard]] constexpr un_scalar_t value(const ElectricPotentialChangeRateUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricPotentialChangeRate operator+(const ElectricPotentialChangeRate& other) const noexcept
        {
            return ElectricPotentialChangeRate(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricPotentialChangeRate operator-(const ElectricPotentialChangeRate& other)const noexcept
        {
            return ElectricPotentialChangeRate(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricPotentialChangeRate operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricPotentialChangeRate(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricPotentialChangeRate operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricPotentialChangeRate(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricPotentialChangeRate& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricPotentialChangeRate& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricPotentialChangeRate& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t volts_per_second() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::VoltsPerSecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_volts_per_second(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::VoltsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t microvolts_per_second() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MicrovoltsPerSecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_microvolts_per_second(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MicrovoltsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t millivolts_per_second() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MillivoltsPerSecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_millivolts_per_second(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MillivoltsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t kilovolts_per_second() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::KilovoltsPerSecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_kilovolts_per_second(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::KilovoltsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t megavolts_per_second() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MegavoltsPerSecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_megavolts_per_second(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MegavoltsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t volts_per_microsecond() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::VoltsPerMicrosecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_volts_per_microsecond(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::VoltsPerMicrosecond);
        }


        [[nodiscard]] constexpr un_scalar_t microvolts_per_microsecond() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MicrovoltsPerMicrosecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_microvolts_per_microsecond(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MicrovoltsPerMicrosecond);
        }


        [[nodiscard]] constexpr un_scalar_t millivolts_per_microsecond() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MillivoltsPerMicrosecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_millivolts_per_microsecond(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MillivoltsPerMicrosecond);
        }


        [[nodiscard]] constexpr un_scalar_t kilovolts_per_microsecond() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::KilovoltsPerMicrosecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_kilovolts_per_microsecond(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::KilovoltsPerMicrosecond);
        }


        [[nodiscard]] constexpr un_scalar_t megavolts_per_microsecond() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MegavoltsPerMicrosecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_megavolts_per_microsecond(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MegavoltsPerMicrosecond);
        }


        [[nodiscard]] constexpr un_scalar_t volts_per_minute() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::VoltsPerMinute);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_volts_per_minute(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::VoltsPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t microvolts_per_minute() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MicrovoltsPerMinute);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_microvolts_per_minute(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MicrovoltsPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t millivolts_per_minute() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MillivoltsPerMinute);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_millivolts_per_minute(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MillivoltsPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t kilovolts_per_minute() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::KilovoltsPerMinute);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_kilovolts_per_minute(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::KilovoltsPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t megavolts_per_minute() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MegavoltsPerMinute);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_megavolts_per_minute(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MegavoltsPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t volts_per_hour() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::VoltsPerHour);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_volts_per_hour(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::VoltsPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t microvolts_per_hour() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MicrovoltsPerHour);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_microvolts_per_hour(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MicrovoltsPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t millivolts_per_hour() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MillivoltsPerHour);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_millivolts_per_hour(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MillivoltsPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t kilovolts_per_hour() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::KilovoltsPerHour);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_kilovolts_per_hour(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::KilovoltsPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t megavolts_per_hour() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MegavoltsPerHour);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_megavolts_per_hour(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MegavoltsPerHour);
        }


        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_invalid()
        {
            return ElectricPotentialChangeRate(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricPotentialChangeRateUnit unit)
        {
            switch (unit)
            {

            case ElectricPotentialChangeRateUnit::VoltsPerSecond:
                return value;

            case ElectricPotentialChangeRateUnit::MicrovoltsPerSecond:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricPotentialChangeRateUnit::MillivoltsPerSecond:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricPotentialChangeRateUnit::KilovoltsPerSecond:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricPotentialChangeRateUnit::MegavoltsPerSecond:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricPotentialChangeRateUnit::VoltsPerMicrosecond:
                return value * static_cast<un_scalar_t>(1E6);

            case ElectricPotentialChangeRateUnit::MicrovoltsPerMicrosecond:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(1E6);

            case ElectricPotentialChangeRateUnit::MillivoltsPerMicrosecond:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1E6);

            case ElectricPotentialChangeRateUnit::KilovoltsPerMicrosecond:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1E6);

            case ElectricPotentialChangeRateUnit::MegavoltsPerMicrosecond:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1E6);

            case ElectricPotentialChangeRateUnit::VoltsPerMinute:
                return value / static_cast<un_scalar_t>(60);

            case ElectricPotentialChangeRateUnit::MicrovoltsPerMinute:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(60);

            case ElectricPotentialChangeRateUnit::MillivoltsPerMinute:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(60);

            case ElectricPotentialChangeRateUnit::KilovoltsPerMinute:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(60);

            case ElectricPotentialChangeRateUnit::MegavoltsPerMinute:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(60);

            case ElectricPotentialChangeRateUnit::VoltsPerHour:
                return value / static_cast<un_scalar_t>(3600);

            case ElectricPotentialChangeRateUnit::MicrovoltsPerHour:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(3600);

            case ElectricPotentialChangeRateUnit::MillivoltsPerHour:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(3600);

            case ElectricPotentialChangeRateUnit::KilovoltsPerHour:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(3600);

            case ElectricPotentialChangeRateUnit::MegavoltsPerHour:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown ElectricPotentialChangeRate unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricPotentialChangeRateUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case ElectricPotentialChangeRateUnit::VoltsPerSecond:
                return base_value_;

            case ElectricPotentialChangeRateUnit::MicrovoltsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e-6);

            case ElectricPotentialChangeRateUnit::MillivoltsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e-3);

            case ElectricPotentialChangeRateUnit::KilovoltsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e3);

            case ElectricPotentialChangeRateUnit::MegavoltsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e6);

            case ElectricPotentialChangeRateUnit::VoltsPerMicrosecond:
                return base_value_ / static_cast<un_scalar_t>(1E6);

            case ElectricPotentialChangeRateUnit::MicrovoltsPerMicrosecond:
                return (base_value_ / static_cast<un_scalar_t>(1E6)) / static_cast<un_scalar_t>(1e-6);

            case ElectricPotentialChangeRateUnit::MillivoltsPerMicrosecond:
                return (base_value_ / static_cast<un_scalar_t>(1E6)) / static_cast<un_scalar_t>(1e-3);

            case ElectricPotentialChangeRateUnit::KilovoltsPerMicrosecond:
                return (base_value_ / static_cast<un_scalar_t>(1E6)) / static_cast<un_scalar_t>(1e3);

            case ElectricPotentialChangeRateUnit::MegavoltsPerMicrosecond:
                return (base_value_ / static_cast<un_scalar_t>(1E6)) / static_cast<un_scalar_t>(1e6);

            case ElectricPotentialChangeRateUnit::VoltsPerMinute:
                return base_value_ * static_cast<un_scalar_t>(60);

            case ElectricPotentialChangeRateUnit::MicrovoltsPerMinute:
                return (base_value_ * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e-6);

            case ElectricPotentialChangeRateUnit::MillivoltsPerMinute:
                return (base_value_ * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e-3);

            case ElectricPotentialChangeRateUnit::KilovoltsPerMinute:
                return (base_value_ * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e3);

            case ElectricPotentialChangeRateUnit::MegavoltsPerMinute:
                return (base_value_ * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e6);

            case ElectricPotentialChangeRateUnit::VoltsPerHour:
                return base_value_ * static_cast<un_scalar_t>(3600);

            case ElectricPotentialChangeRateUnit::MicrovoltsPerHour:
                return (base_value_ * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e-6);

            case ElectricPotentialChangeRateUnit::MillivoltsPerHour:
                return (base_value_ * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e-3);

            case ElectricPotentialChangeRateUnit::KilovoltsPerHour:
                return (base_value_ * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e3);

            case ElectricPotentialChangeRateUnit::MegavoltsPerHour:
                return (base_value_ * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown ElectricPotentialChangeRate unit.");
        }

        un_scalar_t value_;
        ElectricPotentialChangeRateUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
