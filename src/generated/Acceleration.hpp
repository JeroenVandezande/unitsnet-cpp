#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class AccelerationUnit : std::uint16_t
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
            double value,
            AccelerationUnit unit = AccelerationUnit::MetersPerSecondSquared)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(AccelerationUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Acceleration operator+(Acceleration other) const noexcept
        {
            return Acceleration(value_ + other.value_);
        }

        [[nodiscard]] constexpr Acceleration operator-(Acceleration other) const noexcept
        {
            return Acceleration(value_ - other.value_);
        }

        [[nodiscard]] constexpr Acceleration operator*(double scalar) const noexcept
        {
            return Acceleration(value_ * scalar);
        }

        [[nodiscard]] constexpr Acceleration operator/(double scalar) const noexcept
        {
            return Acceleration(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Acceleration other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Acceleration other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double meters_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::MetersPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_meters_per_second_squared(double value)
        {
            return Acceleration(value, AccelerationUnit::MetersPerSecondSquared);
        }


        [[nodiscard]] constexpr double nanometers_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::NanometersPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_nanometers_per_second_squared(double value)
        {
            return Acceleration(value, AccelerationUnit::NanometersPerSecondSquared);
        }


        [[nodiscard]] constexpr double micrometers_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::MicrometersPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_micrometers_per_second_squared(double value)
        {
            return Acceleration(value, AccelerationUnit::MicrometersPerSecondSquared);
        }


        [[nodiscard]] constexpr double millimeters_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::MillimetersPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_millimeters_per_second_squared(double value)
        {
            return Acceleration(value, AccelerationUnit::MillimetersPerSecondSquared);
        }


        [[nodiscard]] constexpr double centimeters_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::CentimetersPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_centimeters_per_second_squared(double value)
        {
            return Acceleration(value, AccelerationUnit::CentimetersPerSecondSquared);
        }


        [[nodiscard]] constexpr double decimeters_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::DecimetersPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_decimeters_per_second_squared(double value)
        {
            return Acceleration(value, AccelerationUnit::DecimetersPerSecondSquared);
        }


        [[nodiscard]] constexpr double kilometers_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::KilometersPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_kilometers_per_second_squared(double value)
        {
            return Acceleration(value, AccelerationUnit::KilometersPerSecondSquared);
        }


        [[nodiscard]] constexpr double inches_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::InchesPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_inches_per_second_squared(double value)
        {
            return Acceleration(value, AccelerationUnit::InchesPerSecondSquared);
        }


        [[nodiscard]] constexpr double feet_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::FeetPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_feet_per_second_squared(double value)
        {
            return Acceleration(value, AccelerationUnit::FeetPerSecondSquared);
        }


        [[nodiscard]] constexpr double knots_per_second() const
        {
            return convert_from_base(AccelerationUnit::KnotsPerSecond);
        }

        [[nodiscard]] static constexpr Acceleration from_knots_per_second(double value)
        {
            return Acceleration(value, AccelerationUnit::KnotsPerSecond);
        }


        [[nodiscard]] constexpr double knots_per_minute() const
        {
            return convert_from_base(AccelerationUnit::KnotsPerMinute);
        }

        [[nodiscard]] static constexpr Acceleration from_knots_per_minute(double value)
        {
            return Acceleration(value, AccelerationUnit::KnotsPerMinute);
        }


        [[nodiscard]] constexpr double knots_per_hour() const
        {
            return convert_from_base(AccelerationUnit::KnotsPerHour);
        }

        [[nodiscard]] static constexpr Acceleration from_knots_per_hour(double value)
        {
            return Acceleration(value, AccelerationUnit::KnotsPerHour);
        }


        [[nodiscard]] constexpr double standard_gravity() const
        {
            return convert_from_base(AccelerationUnit::StandardGravity);
        }

        [[nodiscard]] static constexpr Acceleration from_standard_gravity(double value)
        {
            return Acceleration(value, AccelerationUnit::StandardGravity);
        }


        [[nodiscard]] constexpr double millistandard_gravity() const
        {
            return convert_from_base(AccelerationUnit::MillistandardGravity);
        }

        [[nodiscard]] static constexpr Acceleration from_millistandard_gravity(double value)
        {
            return Acceleration(value, AccelerationUnit::MillistandardGravity);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, AccelerationUnit unit)
        {
            switch (unit)
            {

            case AccelerationUnit::MetersPerSecondSquared:
                return value;

            case AccelerationUnit::NanometersPerSecondSquared:
                return (value * 1e-9);

            case AccelerationUnit::MicrometersPerSecondSquared:
                return (value * 1e-6);

            case AccelerationUnit::MillimetersPerSecondSquared:
                return (value * 1e-3);

            case AccelerationUnit::CentimetersPerSecondSquared:
                return (value * 1e-2);

            case AccelerationUnit::DecimetersPerSecondSquared:
                return (value * 1e-1);

            case AccelerationUnit::KilometersPerSecondSquared:
                return (value * 1e3);

            case AccelerationUnit::InchesPerSecondSquared:
                return value * 0.0254;

            case AccelerationUnit::FeetPerSecondSquared:
                return value * 0.304800;

            case AccelerationUnit::KnotsPerSecond:
                return value * (1852.0 / 3600.0);

            case AccelerationUnit::KnotsPerMinute:
                return value * (1852.0 / 3600.0) / 60;

            case AccelerationUnit::KnotsPerHour:
                return value * (1852.0 / 3600.0) / 3600;

            case AccelerationUnit::StandardGravity:
                return value * 9.80665;

            case AccelerationUnit::MillistandardGravity:
                return (value * 1e-3) * 9.80665;

            }

            throw std::invalid_argument("Unknown Acceleration unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(AccelerationUnit unit) const
        {
            switch (unit)
            {

            case AccelerationUnit::MetersPerSecondSquared:
                return value_;

            case AccelerationUnit::NanometersPerSecondSquared:
                return (value_) / 1e-9;

            case AccelerationUnit::MicrometersPerSecondSquared:
                return (value_) / 1e-6;

            case AccelerationUnit::MillimetersPerSecondSquared:
                return (value_) / 1e-3;

            case AccelerationUnit::CentimetersPerSecondSquared:
                return (value_) / 1e-2;

            case AccelerationUnit::DecimetersPerSecondSquared:
                return (value_) / 1e-1;

            case AccelerationUnit::KilometersPerSecondSquared:
                return (value_) / 1e3;

            case AccelerationUnit::InchesPerSecondSquared:
                return value_ / 0.0254;

            case AccelerationUnit::FeetPerSecondSquared:
                return value_ / 0.304800;

            case AccelerationUnit::KnotsPerSecond:
                return value_ / (1852.0 / 3600.0);

            case AccelerationUnit::KnotsPerMinute:
                return value_ * 60 / (1852.0 / 3600.0);

            case AccelerationUnit::KnotsPerHour:
                return value_ * 3600 / (1852.0 / 3600.0);

            case AccelerationUnit::StandardGravity:
                return value_ / 9.80665;

            case AccelerationUnit::MillistandardGravity:
                return (value_ / 9.80665) / 1e-3;

            }

            throw std::invalid_argument("Unknown Acceleration unit.");
        }

        double value_;
    };
}
