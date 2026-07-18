#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class AngleUnit : std::uint16_t
    {
        Radians,
        Nanoradians,
        Microradians,
        Milliradians,
        Centiradians,
        Deciradians,
        Degrees,
        Nanodegrees,
        Microdegrees,
        Millidegrees,
        Arcminutes,
        Arcseconds,
        Gradians,
        NatoMils,
        Revolutions,
    };

    /// <summary>In geometry, an angle is the figure formed by two rays, called the sides of the angle, sharing a common endpoint, called the vertex of the angle.</summary>
    class Angle
    {
    public:
        constexpr explicit Angle(
            double value,
            AngleUnit unit = AngleUnit::Radians)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(AngleUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Angle operator+(Angle other) const noexcept
        {
            return Angle(value_ + other.value_);
        }

        [[nodiscard]] constexpr Angle operator-(Angle other) const noexcept
        {
            return Angle(value_ - other.value_);
        }

        [[nodiscard]] constexpr Angle operator*(double scalar) const noexcept
        {
            return Angle(value_ * scalar);
        }

        [[nodiscard]] constexpr Angle operator/(double scalar) const noexcept
        {
            return Angle(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Angle other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Angle other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double radians() const
        {
            return convert_from_base(AngleUnit::Radians);
        }

        [[nodiscard]] static constexpr Angle from_radians(double value)
        {
            return Angle(value, AngleUnit::Radians);
        }


        [[nodiscard]] constexpr double nanoradians() const
        {
            return convert_from_base(AngleUnit::Nanoradians);
        }

        [[nodiscard]] static constexpr Angle from_nanoradians(double value)
        {
            return Angle(value, AngleUnit::Nanoradians);
        }


        [[nodiscard]] constexpr double microradians() const
        {
            return convert_from_base(AngleUnit::Microradians);
        }

        [[nodiscard]] static constexpr Angle from_microradians(double value)
        {
            return Angle(value, AngleUnit::Microradians);
        }


        [[nodiscard]] constexpr double milliradians() const
        {
            return convert_from_base(AngleUnit::Milliradians);
        }

        [[nodiscard]] static constexpr Angle from_milliradians(double value)
        {
            return Angle(value, AngleUnit::Milliradians);
        }


        [[nodiscard]] constexpr double centiradians() const
        {
            return convert_from_base(AngleUnit::Centiradians);
        }

        [[nodiscard]] static constexpr Angle from_centiradians(double value)
        {
            return Angle(value, AngleUnit::Centiradians);
        }


        [[nodiscard]] constexpr double deciradians() const
        {
            return convert_from_base(AngleUnit::Deciradians);
        }

        [[nodiscard]] static constexpr Angle from_deciradians(double value)
        {
            return Angle(value, AngleUnit::Deciradians);
        }


        [[nodiscard]] constexpr double degrees() const
        {
            return convert_from_base(AngleUnit::Degrees);
        }

        [[nodiscard]] static constexpr Angle from_degrees(double value)
        {
            return Angle(value, AngleUnit::Degrees);
        }


        [[nodiscard]] constexpr double nanodegrees() const
        {
            return convert_from_base(AngleUnit::Nanodegrees);
        }

        [[nodiscard]] static constexpr Angle from_nanodegrees(double value)
        {
            return Angle(value, AngleUnit::Nanodegrees);
        }


        [[nodiscard]] constexpr double microdegrees() const
        {
            return convert_from_base(AngleUnit::Microdegrees);
        }

        [[nodiscard]] static constexpr Angle from_microdegrees(double value)
        {
            return Angle(value, AngleUnit::Microdegrees);
        }


        [[nodiscard]] constexpr double millidegrees() const
        {
            return convert_from_base(AngleUnit::Millidegrees);
        }

        [[nodiscard]] static constexpr Angle from_millidegrees(double value)
        {
            return Angle(value, AngleUnit::Millidegrees);
        }


        [[nodiscard]] constexpr double arcminutes() const
        {
            return convert_from_base(AngleUnit::Arcminutes);
        }

        [[nodiscard]] static constexpr Angle from_arcminutes(double value)
        {
            return Angle(value, AngleUnit::Arcminutes);
        }


        [[nodiscard]] constexpr double arcseconds() const
        {
            return convert_from_base(AngleUnit::Arcseconds);
        }

        [[nodiscard]] static constexpr Angle from_arcseconds(double value)
        {
            return Angle(value, AngleUnit::Arcseconds);
        }


        [[nodiscard]] constexpr double gradians() const
        {
            return convert_from_base(AngleUnit::Gradians);
        }

        [[nodiscard]] static constexpr Angle from_gradians(double value)
        {
            return Angle(value, AngleUnit::Gradians);
        }


        [[nodiscard]] constexpr double nato_mils() const
        {
            return convert_from_base(AngleUnit::NatoMils);
        }

        [[nodiscard]] static constexpr Angle from_nato_mils(double value)
        {
            return Angle(value, AngleUnit::NatoMils);
        }


        [[nodiscard]] constexpr double revolutions() const
        {
            return convert_from_base(AngleUnit::Revolutions);
        }

        [[nodiscard]] static constexpr Angle from_revolutions(double value)
        {
            return Angle(value, AngleUnit::Revolutions);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, AngleUnit unit)
        {
            switch (unit)
            {

            case AngleUnit::Radians:
                return value;

            case AngleUnit::Nanoradians:
                return (value * 1e-9);

            case AngleUnit::Microradians:
                return (value * 1e-6);

            case AngleUnit::Milliradians:
                return (value * 1e-3);

            case AngleUnit::Centiradians:
                return (value * 1e-2);

            case AngleUnit::Deciradians:
                return (value * 1e-1);

            case AngleUnit::Degrees:
                return value * std::numbers::pi / 180;

            case AngleUnit::Nanodegrees:
                return (value * 1e-9) * std::numbers::pi / 180;

            case AngleUnit::Microdegrees:
                return (value * 1e-6) * std::numbers::pi / 180;

            case AngleUnit::Millidegrees:
                return (value * 1e-3) * std::numbers::pi / 180;

            case AngleUnit::Arcminutes:
                return value * std::numbers::pi / (60 * 180);

            case AngleUnit::Arcseconds:
                return value * std::numbers::pi / (3600 * 180);

            case AngleUnit::Gradians:
                return value * std::numbers::pi / 200;

            case AngleUnit::NatoMils:
                return value * std::numbers::pi / 3200;

            case AngleUnit::Revolutions:
                return value * 2 * std::numbers::pi;

            }

            throw std::invalid_argument("Unknown Angle unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(AngleUnit unit) const
        {
            switch (unit)
            {

            case AngleUnit::Radians:
                return value_;

            case AngleUnit::Nanoradians:
                return (value_) / 1e-9;

            case AngleUnit::Microradians:
                return (value_) / 1e-6;

            case AngleUnit::Milliradians:
                return (value_) / 1e-3;

            case AngleUnit::Centiradians:
                return (value_) / 1e-2;

            case AngleUnit::Deciradians:
                return (value_) / 1e-1;

            case AngleUnit::Degrees:
                return value_ * 180 / std::numbers::pi;

            case AngleUnit::Nanodegrees:
                return (value_ * 180 / std::numbers::pi) / 1e-9;

            case AngleUnit::Microdegrees:
                return (value_ * 180 / std::numbers::pi) / 1e-6;

            case AngleUnit::Millidegrees:
                return (value_ * 180 / std::numbers::pi) / 1e-3;

            case AngleUnit::Arcminutes:
                return value_ * 60 * 180 / std::numbers::pi;

            case AngleUnit::Arcseconds:
                return value_ * 3600 * 180 / std::numbers::pi;

            case AngleUnit::Gradians:
                return value_ * 200 / std::numbers::pi;

            case AngleUnit::NatoMils:
                return value_ * 3200 / std::numbers::pi;

            case AngleUnit::Revolutions:
                return value_ / (2 * std::numbers::pi);

            }

            throw std::invalid_argument("Unknown Angle unit.");
        }

        double value_;
    };
}
