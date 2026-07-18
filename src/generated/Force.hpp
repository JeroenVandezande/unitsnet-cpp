#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ForceUnit : std::uint16_t
    {
        Dyne,
        GramsForce,
        KilogramsForce,
        TonnesForce,
        Newtons,
        Micronewtons,
        Millinewtons,
        Decanewtons,
        Kilonewtons,
        Meganewtons,
        Kiloponds,
        Poundals,
        PoundsForce,
        KilopoundsForce,
        OunceForce,
        ShortTonsForce,
    };

    /// <summary>In physics, a force is any influence that causes an object to undergo a certain change, either concerning its movement, direction, or geometrical construction. In other words, a force can cause an object with mass to change its velocity (which includes to begin moving from a state of rest), i.e., to accelerate, or a flexible object to deform, or both. Force can also be described by intuitive concepts such as a push or a pull. A force has both magnitude and direction, making it a vector quantity. It is measured in the SI unit of newtons and represented by the symbol F.</summary>
    class Force
    {
    public:
        constexpr explicit Force(
            double value,
            ForceUnit unit = ForceUnit::Newtons)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ForceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Force operator+(Force other) const noexcept
        {
            return Force(value_ + other.value_);
        }

        [[nodiscard]] constexpr Force operator-(Force other) const noexcept
        {
            return Force(value_ - other.value_);
        }

        [[nodiscard]] constexpr Force operator*(double scalar) const noexcept
        {
            return Force(value_ * scalar);
        }

        [[nodiscard]] constexpr Force operator/(double scalar) const noexcept
        {
            return Force(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Force other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Force other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double dyne() const
        {
            return convert_from_base(ForceUnit::Dyne);
        }

        [[nodiscard]] static constexpr Force from_dyne(double value)
        {
            return Force(value, ForceUnit::Dyne);
        }


        [[nodiscard]] constexpr double grams_force() const
        {
            return convert_from_base(ForceUnit::GramsForce);
        }

        [[nodiscard]] static constexpr Force from_grams_force(double value)
        {
            return Force(value, ForceUnit::GramsForce);
        }


        [[nodiscard]] constexpr double kilograms_force() const
        {
            return convert_from_base(ForceUnit::KilogramsForce);
        }

        [[nodiscard]] static constexpr Force from_kilograms_force(double value)
        {
            return Force(value, ForceUnit::KilogramsForce);
        }


        [[nodiscard]] constexpr double tonnes_force() const
        {
            return convert_from_base(ForceUnit::TonnesForce);
        }

        [[nodiscard]] static constexpr Force from_tonnes_force(double value)
        {
            return Force(value, ForceUnit::TonnesForce);
        }


        [[nodiscard]] constexpr double newtons() const
        {
            return convert_from_base(ForceUnit::Newtons);
        }

        [[nodiscard]] static constexpr Force from_newtons(double value)
        {
            return Force(value, ForceUnit::Newtons);
        }


        [[nodiscard]] constexpr double micronewtons() const
        {
            return convert_from_base(ForceUnit::Micronewtons);
        }

        [[nodiscard]] static constexpr Force from_micronewtons(double value)
        {
            return Force(value, ForceUnit::Micronewtons);
        }


        [[nodiscard]] constexpr double millinewtons() const
        {
            return convert_from_base(ForceUnit::Millinewtons);
        }

        [[nodiscard]] static constexpr Force from_millinewtons(double value)
        {
            return Force(value, ForceUnit::Millinewtons);
        }


        [[nodiscard]] constexpr double decanewtons() const
        {
            return convert_from_base(ForceUnit::Decanewtons);
        }

        [[nodiscard]] static constexpr Force from_decanewtons(double value)
        {
            return Force(value, ForceUnit::Decanewtons);
        }


        [[nodiscard]] constexpr double kilonewtons() const
        {
            return convert_from_base(ForceUnit::Kilonewtons);
        }

        [[nodiscard]] static constexpr Force from_kilonewtons(double value)
        {
            return Force(value, ForceUnit::Kilonewtons);
        }


        [[nodiscard]] constexpr double meganewtons() const
        {
            return convert_from_base(ForceUnit::Meganewtons);
        }

        [[nodiscard]] static constexpr Force from_meganewtons(double value)
        {
            return Force(value, ForceUnit::Meganewtons);
        }


        [[nodiscard]] constexpr double kiloponds() const
        {
            return convert_from_base(ForceUnit::Kiloponds);
        }

        [[nodiscard]] static constexpr Force from_kiloponds(double value)
        {
            return Force(value, ForceUnit::Kiloponds);
        }


        [[nodiscard]] constexpr double poundals() const
        {
            return convert_from_base(ForceUnit::Poundals);
        }

        [[nodiscard]] static constexpr Force from_poundals(double value)
        {
            return Force(value, ForceUnit::Poundals);
        }


        [[nodiscard]] constexpr double pounds_force() const
        {
            return convert_from_base(ForceUnit::PoundsForce);
        }

        [[nodiscard]] static constexpr Force from_pounds_force(double value)
        {
            return Force(value, ForceUnit::PoundsForce);
        }


        [[nodiscard]] constexpr double kilopounds_force() const
        {
            return convert_from_base(ForceUnit::KilopoundsForce);
        }

        [[nodiscard]] static constexpr Force from_kilopounds_force(double value)
        {
            return Force(value, ForceUnit::KilopoundsForce);
        }


        [[nodiscard]] constexpr double ounce_force() const
        {
            return convert_from_base(ForceUnit::OunceForce);
        }

        [[nodiscard]] static constexpr Force from_ounce_force(double value)
        {
            return Force(value, ForceUnit::OunceForce);
        }


        [[nodiscard]] constexpr double short_tons_force() const
        {
            return convert_from_base(ForceUnit::ShortTonsForce);
        }

        [[nodiscard]] static constexpr Force from_short_tons_force(double value)
        {
            return Force(value, ForceUnit::ShortTonsForce);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ForceUnit unit)
        {
            switch (unit)
            {

            case ForceUnit::Dyne:
                return value / 1e5;

            case ForceUnit::GramsForce:
                return value * 9.80665e-3;

            case ForceUnit::KilogramsForce:
                return value * 9.80665;

            case ForceUnit::TonnesForce:
                return value * (9.80665 * 1000);

            case ForceUnit::Newtons:
                return value;

            case ForceUnit::Micronewtons:
                return (value * 1e-6);

            case ForceUnit::Millinewtons:
                return (value * 1e-3);

            case ForceUnit::Decanewtons:
                return (value * 1e1);

            case ForceUnit::Kilonewtons:
                return (value * 1e3);

            case ForceUnit::Meganewtons:
                return (value * 1e6);

            case ForceUnit::Kiloponds:
                return value * 9.80665;

            case ForceUnit::Poundals:
                return value * 0.138254954376;

            case ForceUnit::PoundsForce:
                return value * 4.4482216152605;

            case ForceUnit::KilopoundsForce:
                return (value * 1e3) * 4.4482216152605;

            case ForceUnit::OunceForce:
                return value * (4.4482216152605 / 16);

            case ForceUnit::ShortTonsForce:
                return value * (4.4482216152605 * 2000);

            }

            throw std::invalid_argument("Unknown Force unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ForceUnit unit) const
        {
            switch (unit)
            {

            case ForceUnit::Dyne:
                return value_ * 1e5;

            case ForceUnit::GramsForce:
                return value_ / 9.80665e-3;

            case ForceUnit::KilogramsForce:
                return value_ / 9.80665;

            case ForceUnit::TonnesForce:
                return value_ / (9.80665 * 1000);

            case ForceUnit::Newtons:
                return value_;

            case ForceUnit::Micronewtons:
                return (value_) / 1e-6;

            case ForceUnit::Millinewtons:
                return (value_) / 1e-3;

            case ForceUnit::Decanewtons:
                return (value_) / 1e1;

            case ForceUnit::Kilonewtons:
                return (value_) / 1e3;

            case ForceUnit::Meganewtons:
                return (value_) / 1e6;

            case ForceUnit::Kiloponds:
                return value_ / 9.80665;

            case ForceUnit::Poundals:
                return value_ / 0.138254954376;

            case ForceUnit::PoundsForce:
                return value_ / 4.4482216152605;

            case ForceUnit::KilopoundsForce:
                return (value_ / 4.4482216152605) / 1e3;

            case ForceUnit::OunceForce:
                return value_ / (4.4482216152605 / 16);

            case ForceUnit::ShortTonsForce:
                return value_ / (4.4482216152605 * 2000);

            }

            throw std::invalid_argument("Unknown Force unit.");
        }

        double value_;
    };
}
