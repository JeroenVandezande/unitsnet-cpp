#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class JerkUnit : std::uint16_t
    {
        MetersPerSecondCubed,
        NanometersPerSecondCubed,
        MicrometersPerSecondCubed,
        MillimetersPerSecondCubed,
        CentimetersPerSecondCubed,
        DecimetersPerSecondCubed,
        KilometersPerSecondCubed,
        InchesPerSecondCubed,
        FeetPerSecondCubed,
        StandardGravitiesPerSecond,
        MillistandardGravitiesPerSecond,
    };

    /// <summary></summary>
    class Jerk
    {
    public:
        constexpr explicit Jerk(
            double value,
            JerkUnit unit = JerkUnit::MetersPerSecondCubed)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(JerkUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Jerk operator+(Jerk other) const noexcept
        {
            return Jerk(value_ + other.value_);
        }

        [[nodiscard]] constexpr Jerk operator-(Jerk other) const noexcept
        {
            return Jerk(value_ - other.value_);
        }

        [[nodiscard]] constexpr Jerk operator*(double scalar) const noexcept
        {
            return Jerk(value_ * scalar);
        }

        [[nodiscard]] constexpr Jerk operator/(double scalar) const noexcept
        {
            return Jerk(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Jerk other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Jerk other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double meters_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::MetersPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_meters_per_second_cubed(double value)
        {
            return Jerk(value, JerkUnit::MetersPerSecondCubed);
        }


        [[nodiscard]] constexpr double nanometers_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::NanometersPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_nanometers_per_second_cubed(double value)
        {
            return Jerk(value, JerkUnit::NanometersPerSecondCubed);
        }


        [[nodiscard]] constexpr double micrometers_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::MicrometersPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_micrometers_per_second_cubed(double value)
        {
            return Jerk(value, JerkUnit::MicrometersPerSecondCubed);
        }


        [[nodiscard]] constexpr double millimeters_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::MillimetersPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_millimeters_per_second_cubed(double value)
        {
            return Jerk(value, JerkUnit::MillimetersPerSecondCubed);
        }


        [[nodiscard]] constexpr double centimeters_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::CentimetersPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_centimeters_per_second_cubed(double value)
        {
            return Jerk(value, JerkUnit::CentimetersPerSecondCubed);
        }


        [[nodiscard]] constexpr double decimeters_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::DecimetersPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_decimeters_per_second_cubed(double value)
        {
            return Jerk(value, JerkUnit::DecimetersPerSecondCubed);
        }


        [[nodiscard]] constexpr double kilometers_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::KilometersPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_kilometers_per_second_cubed(double value)
        {
            return Jerk(value, JerkUnit::KilometersPerSecondCubed);
        }


        [[nodiscard]] constexpr double inches_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::InchesPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_inches_per_second_cubed(double value)
        {
            return Jerk(value, JerkUnit::InchesPerSecondCubed);
        }


        [[nodiscard]] constexpr double feet_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::FeetPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_feet_per_second_cubed(double value)
        {
            return Jerk(value, JerkUnit::FeetPerSecondCubed);
        }


        [[nodiscard]] constexpr double standard_gravities_per_second() const
        {
            return convert_from_base(JerkUnit::StandardGravitiesPerSecond);
        }

        [[nodiscard]] static constexpr Jerk from_standard_gravities_per_second(double value)
        {
            return Jerk(value, JerkUnit::StandardGravitiesPerSecond);
        }


        [[nodiscard]] constexpr double millistandard_gravities_per_second() const
        {
            return convert_from_base(JerkUnit::MillistandardGravitiesPerSecond);
        }

        [[nodiscard]] static constexpr Jerk from_millistandard_gravities_per_second(double value)
        {
            return Jerk(value, JerkUnit::MillistandardGravitiesPerSecond);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, JerkUnit unit)
        {
            switch (unit)
            {

            case JerkUnit::MetersPerSecondCubed:
                return value;

            case JerkUnit::NanometersPerSecondCubed:
                return (value * 1e-9);

            case JerkUnit::MicrometersPerSecondCubed:
                return (value * 1e-6);

            case JerkUnit::MillimetersPerSecondCubed:
                return (value * 1e-3);

            case JerkUnit::CentimetersPerSecondCubed:
                return (value * 1e-2);

            case JerkUnit::DecimetersPerSecondCubed:
                return (value * 1e-1);

            case JerkUnit::KilometersPerSecondCubed:
                return (value * 1e3);

            case JerkUnit::InchesPerSecondCubed:
                return value * 0.0254;

            case JerkUnit::FeetPerSecondCubed:
                return value * 0.304800;

            case JerkUnit::StandardGravitiesPerSecond:
                return value * 9.80665;

            case JerkUnit::MillistandardGravitiesPerSecond:
                return (value * 1e-3) * 9.80665;

            }

            throw std::invalid_argument("Unknown Jerk unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(JerkUnit unit) const
        {
            switch (unit)
            {

            case JerkUnit::MetersPerSecondCubed:
                return value_;

            case JerkUnit::NanometersPerSecondCubed:
                return (value_) / 1e-9;

            case JerkUnit::MicrometersPerSecondCubed:
                return (value_) / 1e-6;

            case JerkUnit::MillimetersPerSecondCubed:
                return (value_) / 1e-3;

            case JerkUnit::CentimetersPerSecondCubed:
                return (value_) / 1e-2;

            case JerkUnit::DecimetersPerSecondCubed:
                return (value_) / 1e-1;

            case JerkUnit::KilometersPerSecondCubed:
                return (value_) / 1e3;

            case JerkUnit::InchesPerSecondCubed:
                return value_ / 0.0254;

            case JerkUnit::FeetPerSecondCubed:
                return value_ / 0.304800;

            case JerkUnit::StandardGravitiesPerSecond:
                return value_ / 9.80665;

            case JerkUnit::MillistandardGravitiesPerSecond:
                return (value_ / 9.80665) / 1e-3;

            }

            throw std::invalid_argument("Unknown Jerk unit.");
        }

        double value_;
    };
}
