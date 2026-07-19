#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class AccelerationUnit : std::uint8_t
    {
        MetersPerSecondSquared,
        NanometersPerSecondSquared,
        MicrometersPerSecondSquared,
        MillimetersPerSecondSquared,
        CentimetersPerSecondSquared,
        DecimetersPerSecondSquared,
        KilometersPerSecondSquared,
        InchesPerSecondSquared,
        FeetPerSecondSquared,
        KnotsPerSecond,
        KnotsPerMinute,
        KnotsPerHour,
        StandardGravity,
        MillistandardGravity,
    };

    /// <summary>Acceleration, in physics, is the rate at which the velocity of an object changes over time. An object's acceleration is the net result of any and all forces acting on the object, as described by Newton's Second Law. The SI unit for acceleration is the Meter per second squared (m/s²). Accelerations are vector quantities (they have magnitude and direction) and add according to the parallelogram law. As a vector, the calculated net force is equal to the product of the object's mass (a scalar quantity) and the acceleration.</summary>
    class Acceleration
    {
    public:
        constexpr explicit Acceleration(
            const un_scalar_t value,
            const AccelerationUnit unit = AccelerationUnit::MetersPerSecondSquared)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit Acceleration(const bool isValid)
        {
            _isInvalid = !isValid;
        }
        
        void SetValueAsInvalid()
        {
            _isInvalid = true;
        }
        
        void SetValueAsValid()
        {
            _isInvalid = false;
        }
        
        [[nodiscard]] bool GetValueIsValid() const
        {
            return _isInvalid;
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const AccelerationUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Acceleration operator+(const Acceleration other) const noexcept
        {
            return Acceleration(value_ + other.value_);
        }

        [[nodiscard]] constexpr Acceleration operator-(const Acceleration other) const noexcept
        {
            return Acceleration(value_ - other.value_);
        }

        [[nodiscard]] constexpr Acceleration operator*(const un_scalar_t scalar) const noexcept
        {
            return Acceleration(value_ * scalar);
        }

        [[nodiscard]] constexpr Acceleration operator/(const un_scalar_t scalar) const noexcept
        {
            return Acceleration(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Acceleration other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Acceleration other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const Acceleration other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t meters_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::MetersPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_meters_per_second_squared(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::MetersPerSecondSquared);
        }


        [[nodiscard]] constexpr un_scalar_t nanometers_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::NanometersPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_nanometers_per_second_squared(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::NanometersPerSecondSquared);
        }


        [[nodiscard]] constexpr un_scalar_t micrometers_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::MicrometersPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_micrometers_per_second_squared(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::MicrometersPerSecondSquared);
        }


        [[nodiscard]] constexpr un_scalar_t millimeters_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::MillimetersPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_millimeters_per_second_squared(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::MillimetersPerSecondSquared);
        }


        [[nodiscard]] constexpr un_scalar_t centimeters_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::CentimetersPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_centimeters_per_second_squared(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::CentimetersPerSecondSquared);
        }


        [[nodiscard]] constexpr un_scalar_t decimeters_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::DecimetersPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_decimeters_per_second_squared(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::DecimetersPerSecondSquared);
        }


        [[nodiscard]] constexpr un_scalar_t kilometers_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::KilometersPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_kilometers_per_second_squared(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::KilometersPerSecondSquared);
        }


        [[nodiscard]] constexpr un_scalar_t inches_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::InchesPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_inches_per_second_squared(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::InchesPerSecondSquared);
        }


        [[nodiscard]] constexpr un_scalar_t feet_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::FeetPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_feet_per_second_squared(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::FeetPerSecondSquared);
        }


        [[nodiscard]] constexpr un_scalar_t knots_per_second() const
        {
            return convert_from_base(AccelerationUnit::KnotsPerSecond);
        }

        [[nodiscard]] static constexpr Acceleration from_knots_per_second(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::KnotsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t knots_per_minute() const
        {
            return convert_from_base(AccelerationUnit::KnotsPerMinute);
        }

        [[nodiscard]] static constexpr Acceleration from_knots_per_minute(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::KnotsPerMinute);
        }


        [[nodiscard]] constexpr un_scalar_t knots_per_hour() const
        {
            return convert_from_base(AccelerationUnit::KnotsPerHour);
        }

        [[nodiscard]] static constexpr Acceleration from_knots_per_hour(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::KnotsPerHour);
        }


        [[nodiscard]] constexpr un_scalar_t standard_gravity() const
        {
            return convert_from_base(AccelerationUnit::StandardGravity);
        }

        [[nodiscard]] static constexpr Acceleration from_standard_gravity(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::StandardGravity);
        }


        [[nodiscard]] constexpr un_scalar_t millistandard_gravity() const
        {
            return convert_from_base(AccelerationUnit::MillistandardGravity);
        }

        [[nodiscard]] static constexpr Acceleration from_millistandard_gravity(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::MillistandardGravity);
        }


        [[nodiscard]] static constexpr Acceleration from_invalid()
        {
            return Acceleration(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, AccelerationUnit unit)
        {
            switch (unit)
            {

            case AccelerationUnit::MetersPerSecondSquared:
                return value;

            case AccelerationUnit::NanometersPerSecondSquared:
                return (value * static_cast<un_scalar_t>(1e-9));

            case AccelerationUnit::MicrometersPerSecondSquared:
                return (value * static_cast<un_scalar_t>(1e-6));

            case AccelerationUnit::MillimetersPerSecondSquared:
                return (value * static_cast<un_scalar_t>(1e-3));

            case AccelerationUnit::CentimetersPerSecondSquared:
                return (value * static_cast<un_scalar_t>(1e-2));

            case AccelerationUnit::DecimetersPerSecondSquared:
                return (value * static_cast<un_scalar_t>(1e-1));

            case AccelerationUnit::KilometersPerSecondSquared:
                return (value * static_cast<un_scalar_t>(1e3));

            case AccelerationUnit::InchesPerSecondSquared:
                return value * static_cast<un_scalar_t>(0.0254);

            case AccelerationUnit::FeetPerSecondSquared:
                return value * static_cast<un_scalar_t>(0.304800);

            case AccelerationUnit::KnotsPerSecond:
                return value * (static_cast<un_scalar_t>(1852.0) / static_cast<un_scalar_t>(3600.0));

            case AccelerationUnit::KnotsPerMinute:
                return value * (static_cast<un_scalar_t>(1852.0) / static_cast<un_scalar_t>(3600.0)) / static_cast<un_scalar_t>(60);

            case AccelerationUnit::KnotsPerHour:
                return value * (static_cast<un_scalar_t>(1852.0) / static_cast<un_scalar_t>(3600.0)) / static_cast<un_scalar_t>(3600);

            case AccelerationUnit::StandardGravity:
                return value * static_cast<un_scalar_t>(9.80665);

            case AccelerationUnit::MillistandardGravity:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(9.80665);

            }

            throw std::invalid_argument("Unknown Acceleration unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const AccelerationUnit unit) const
        {
            switch (unit)
            {

            case AccelerationUnit::MetersPerSecondSquared:
                return value_;

            case AccelerationUnit::NanometersPerSecondSquared:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case AccelerationUnit::MicrometersPerSecondSquared:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case AccelerationUnit::MillimetersPerSecondSquared:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case AccelerationUnit::CentimetersPerSecondSquared:
                return (value_) / static_cast<un_scalar_t>(1e-2);

            case AccelerationUnit::DecimetersPerSecondSquared:
                return (value_) / static_cast<un_scalar_t>(1e-1);

            case AccelerationUnit::KilometersPerSecondSquared:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case AccelerationUnit::InchesPerSecondSquared:
                return value_ / static_cast<un_scalar_t>(0.0254);

            case AccelerationUnit::FeetPerSecondSquared:
                return value_ / static_cast<un_scalar_t>(0.304800);

            case AccelerationUnit::KnotsPerSecond:
                return value_ / (static_cast<un_scalar_t>(1852.0) / static_cast<un_scalar_t>(3600.0));

            case AccelerationUnit::KnotsPerMinute:
                return value_ * static_cast<un_scalar_t>(60) / (static_cast<un_scalar_t>(1852.0) / static_cast<un_scalar_t>(3600.0));

            case AccelerationUnit::KnotsPerHour:
                return value_ * static_cast<un_scalar_t>(3600) / (static_cast<un_scalar_t>(1852.0) / static_cast<un_scalar_t>(3600.0));

            case AccelerationUnit::StandardGravity:
                return value_ / static_cast<un_scalar_t>(9.80665);

            case AccelerationUnit::MillistandardGravity:
                return (value_ / static_cast<un_scalar_t>(9.80665)) / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown Acceleration unit.");
        }

        un_scalar_t value_;
    };
}
