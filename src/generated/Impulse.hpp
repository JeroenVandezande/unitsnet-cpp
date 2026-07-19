#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ImpulseUnit : std::uint8_t
    {
        KilogramMetersPerSecond,
        NewtonSeconds,
        NanonewtonSeconds,
        MicronewtonSeconds,
        MillinewtonSeconds,
        CentinewtonSeconds,
        DecinewtonSeconds,
        DecanewtonSeconds,
        KilonewtonSeconds,
        MeganewtonSeconds,
        PoundFeetPerSecond,
        PoundForceSeconds,
        SlugFeetPerSecond,
    };

    /// <summary>In classical mechanics, impulse is the integral of a force, F, over the time interval, t, for which it acts. Impulse applied to an object produces an equivalent vector change in its linear momentum, also in the resultant direction.</summary>
    class Impulse : public UnitsNetBase
    {
    public:
        constexpr explicit Impulse(
            const un_scalar_t value,
            const ImpulseUnit unit = ImpulseUnit::NewtonSeconds)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == ImpulseUnit::NewtonSeconds)
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

        [[nodiscard]] constexpr un_scalar_t value(const ImpulseUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Impulse operator+(const Impulse& other) const noexcept
        {
            return Impulse(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Impulse operator-(const Impulse& other)const noexcept
        {
            return Impulse(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Impulse operator*(const un_scalar_t scalar) const noexcept
        {
            return Impulse(base_value() * scalar);
        }

        [[nodiscard]] constexpr Impulse operator/(const un_scalar_t scalar) const noexcept
        {
            return Impulse(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Impulse& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Impulse& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Impulse& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t kilogram_meters_per_second() const
        {
            return convert_from_base(ImpulseUnit::KilogramMetersPerSecond);
        }

        [[nodiscard]] static constexpr Impulse from_kilogram_meters_per_second(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::KilogramMetersPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t newton_seconds() const
        {
            return convert_from_base(ImpulseUnit::NewtonSeconds);
        }

        [[nodiscard]] static constexpr Impulse from_newton_seconds(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::NewtonSeconds);
        }


        [[nodiscard]] constexpr un_scalar_t nanonewton_seconds() const
        {
            return convert_from_base(ImpulseUnit::NanonewtonSeconds);
        }

        [[nodiscard]] static constexpr Impulse from_nanonewton_seconds(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::NanonewtonSeconds);
        }


        [[nodiscard]] constexpr un_scalar_t micronewton_seconds() const
        {
            return convert_from_base(ImpulseUnit::MicronewtonSeconds);
        }

        [[nodiscard]] static constexpr Impulse from_micronewton_seconds(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::MicronewtonSeconds);
        }


        [[nodiscard]] constexpr un_scalar_t millinewton_seconds() const
        {
            return convert_from_base(ImpulseUnit::MillinewtonSeconds);
        }

        [[nodiscard]] static constexpr Impulse from_millinewton_seconds(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::MillinewtonSeconds);
        }


        [[nodiscard]] constexpr un_scalar_t centinewton_seconds() const
        {
            return convert_from_base(ImpulseUnit::CentinewtonSeconds);
        }

        [[nodiscard]] static constexpr Impulse from_centinewton_seconds(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::CentinewtonSeconds);
        }


        [[nodiscard]] constexpr un_scalar_t decinewton_seconds() const
        {
            return convert_from_base(ImpulseUnit::DecinewtonSeconds);
        }

        [[nodiscard]] static constexpr Impulse from_decinewton_seconds(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::DecinewtonSeconds);
        }


        [[nodiscard]] constexpr un_scalar_t decanewton_seconds() const
        {
            return convert_from_base(ImpulseUnit::DecanewtonSeconds);
        }

        [[nodiscard]] static constexpr Impulse from_decanewton_seconds(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::DecanewtonSeconds);
        }


        [[nodiscard]] constexpr un_scalar_t kilonewton_seconds() const
        {
            return convert_from_base(ImpulseUnit::KilonewtonSeconds);
        }

        [[nodiscard]] static constexpr Impulse from_kilonewton_seconds(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::KilonewtonSeconds);
        }


        [[nodiscard]] constexpr un_scalar_t meganewton_seconds() const
        {
            return convert_from_base(ImpulseUnit::MeganewtonSeconds);
        }

        [[nodiscard]] static constexpr Impulse from_meganewton_seconds(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::MeganewtonSeconds);
        }


        [[nodiscard]] constexpr un_scalar_t pound_feet_per_second() const
        {
            return convert_from_base(ImpulseUnit::PoundFeetPerSecond);
        }

        [[nodiscard]] static constexpr Impulse from_pound_feet_per_second(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::PoundFeetPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t pound_force_seconds() const
        {
            return convert_from_base(ImpulseUnit::PoundForceSeconds);
        }

        [[nodiscard]] static constexpr Impulse from_pound_force_seconds(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::PoundForceSeconds);
        }


        [[nodiscard]] constexpr un_scalar_t slug_feet_per_second() const
        {
            return convert_from_base(ImpulseUnit::SlugFeetPerSecond);
        }

        [[nodiscard]] static constexpr Impulse from_slug_feet_per_second(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::SlugFeetPerSecond);
        }


        [[nodiscard]] static constexpr Impulse from_invalid()
        {
            return Impulse(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ImpulseUnit unit)
        {
            switch (unit)
            {

            case ImpulseUnit::KilogramMetersPerSecond:
                return value;

            case ImpulseUnit::NewtonSeconds:
                return value;

            case ImpulseUnit::NanonewtonSeconds:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ImpulseUnit::MicronewtonSeconds:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ImpulseUnit::MillinewtonSeconds:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ImpulseUnit::CentinewtonSeconds:
                return (value * static_cast<un_scalar_t>(1e-2));

            case ImpulseUnit::DecinewtonSeconds:
                return (value * static_cast<un_scalar_t>(1e-1));

            case ImpulseUnit::DecanewtonSeconds:
                return (value * static_cast<un_scalar_t>(1e1));

            case ImpulseUnit::KilonewtonSeconds:
                return (value * static_cast<un_scalar_t>(1e3));

            case ImpulseUnit::MeganewtonSeconds:
                return (value * static_cast<un_scalar_t>(1e6));

            case ImpulseUnit::PoundFeetPerSecond:
                return value * (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(0.3048));

            case ImpulseUnit::PoundForceSeconds:
                return value * static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665);

            case ImpulseUnit::SlugFeetPerSecond:
                return value * (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665));

            }

            throw std::invalid_argument("Unknown Impulse unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ImpulseUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case ImpulseUnit::KilogramMetersPerSecond:
                return base_value_;

            case ImpulseUnit::NewtonSeconds:
                return base_value_;

            case ImpulseUnit::NanonewtonSeconds:
                return (base_value_) / static_cast<un_scalar_t>(1e-9);

            case ImpulseUnit::MicronewtonSeconds:
                return (base_value_) / static_cast<un_scalar_t>(1e-6);

            case ImpulseUnit::MillinewtonSeconds:
                return (base_value_) / static_cast<un_scalar_t>(1e-3);

            case ImpulseUnit::CentinewtonSeconds:
                return (base_value_) / static_cast<un_scalar_t>(1e-2);

            case ImpulseUnit::DecinewtonSeconds:
                return (base_value_) / static_cast<un_scalar_t>(1e-1);

            case ImpulseUnit::DecanewtonSeconds:
                return (base_value_) / static_cast<un_scalar_t>(1e1);

            case ImpulseUnit::KilonewtonSeconds:
                return (base_value_) / static_cast<un_scalar_t>(1e3);

            case ImpulseUnit::MeganewtonSeconds:
                return (base_value_) / static_cast<un_scalar_t>(1e6);

            case ImpulseUnit::PoundFeetPerSecond:
                return base_value_ / (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(0.3048));

            case ImpulseUnit::PoundForceSeconds:
                return base_value_ / (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665));

            case ImpulseUnit::SlugFeetPerSecond:
                return base_value_ / (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665));

            }

            throw std::invalid_argument("Unknown Impulse unit.");
        }

        un_scalar_t value_;
        ImpulseUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
