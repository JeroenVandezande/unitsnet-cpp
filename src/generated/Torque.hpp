#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class TorqueUnit : std::uint16_t
    {
        NewtonMillimeters,
        KilonewtonMillimeters,
        MeganewtonMillimeters,
        NewtonCentimeters,
        KilonewtonCentimeters,
        MeganewtonCentimeters,
        NewtonMeters,
        KilonewtonMeters,
        MeganewtonMeters,
        PoundalFeet,
        PoundForceInches,
        KilopoundForceInches,
        MegapoundForceInches,
        PoundForceFeet,
        KilopoundForceFeet,
        MegapoundForceFeet,
        GramForceMillimeters,
        GramForceCentimeters,
        GramForceMeters,
        KilogramForceMillimeters,
        KilogramForceCentimeters,
        KilogramForceMeters,
        TonneForceMillimeters,
        TonneForceCentimeters,
        TonneForceMeters,
    };

    /// <summary>Torque, moment or moment of force (see the terminology below), is the tendency of a force to rotate an object about an axis,[1] fulcrum, or pivot. Just as a force is a push or a pull, a torque can be thought of as a twist to an object. Mathematically, torque is defined as the cross product of the lever-arm distance and force, which tends to produce rotation. Loosely speaking, torque is a measure of the turning force on an object such as a bolt or a flywheel. For example, pushing or pulling the handle of a wrench connected to a nut or bolt produces a torque (turning force) that loosens or tightens the nut or bolt.</summary>
    class Torque
    {
    public:
        constexpr explicit Torque(
            double value,
            TorqueUnit unit = TorqueUnit::NewtonMeters)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(TorqueUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Torque operator+(Torque other) const noexcept
        {
            return Torque(value_ + other.value_);
        }

        [[nodiscard]] constexpr Torque operator-(Torque other) const noexcept
        {
            return Torque(value_ - other.value_);
        }

        [[nodiscard]] constexpr Torque operator*(double scalar) const noexcept
        {
            return Torque(value_ * scalar);
        }

        [[nodiscard]] constexpr Torque operator/(double scalar) const noexcept
        {
            return Torque(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Torque other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Torque other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double newton_millimeters() const
        {
            return convert_from_base(TorqueUnit::NewtonMillimeters);
        }

        [[nodiscard]] static constexpr Torque from_newton_millimeters(double value)
        {
            return Torque(value, TorqueUnit::NewtonMillimeters);
        }


        [[nodiscard]] constexpr double kilonewton_millimeters() const
        {
            return convert_from_base(TorqueUnit::KilonewtonMillimeters);
        }

        [[nodiscard]] static constexpr Torque from_kilonewton_millimeters(double value)
        {
            return Torque(value, TorqueUnit::KilonewtonMillimeters);
        }


        [[nodiscard]] constexpr double meganewton_millimeters() const
        {
            return convert_from_base(TorqueUnit::MeganewtonMillimeters);
        }

        [[nodiscard]] static constexpr Torque from_meganewton_millimeters(double value)
        {
            return Torque(value, TorqueUnit::MeganewtonMillimeters);
        }


        [[nodiscard]] constexpr double newton_centimeters() const
        {
            return convert_from_base(TorqueUnit::NewtonCentimeters);
        }

        [[nodiscard]] static constexpr Torque from_newton_centimeters(double value)
        {
            return Torque(value, TorqueUnit::NewtonCentimeters);
        }


        [[nodiscard]] constexpr double kilonewton_centimeters() const
        {
            return convert_from_base(TorqueUnit::KilonewtonCentimeters);
        }

        [[nodiscard]] static constexpr Torque from_kilonewton_centimeters(double value)
        {
            return Torque(value, TorqueUnit::KilonewtonCentimeters);
        }


        [[nodiscard]] constexpr double meganewton_centimeters() const
        {
            return convert_from_base(TorqueUnit::MeganewtonCentimeters);
        }

        [[nodiscard]] static constexpr Torque from_meganewton_centimeters(double value)
        {
            return Torque(value, TorqueUnit::MeganewtonCentimeters);
        }


        [[nodiscard]] constexpr double newton_meters() const
        {
            return convert_from_base(TorqueUnit::NewtonMeters);
        }

        [[nodiscard]] static constexpr Torque from_newton_meters(double value)
        {
            return Torque(value, TorqueUnit::NewtonMeters);
        }


        [[nodiscard]] constexpr double kilonewton_meters() const
        {
            return convert_from_base(TorqueUnit::KilonewtonMeters);
        }

        [[nodiscard]] static constexpr Torque from_kilonewton_meters(double value)
        {
            return Torque(value, TorqueUnit::KilonewtonMeters);
        }


        [[nodiscard]] constexpr double meganewton_meters() const
        {
            return convert_from_base(TorqueUnit::MeganewtonMeters);
        }

        [[nodiscard]] static constexpr Torque from_meganewton_meters(double value)
        {
            return Torque(value, TorqueUnit::MeganewtonMeters);
        }


        [[nodiscard]] constexpr double poundal_feet() const
        {
            return convert_from_base(TorqueUnit::PoundalFeet);
        }

        [[nodiscard]] static constexpr Torque from_poundal_feet(double value)
        {
            return Torque(value, TorqueUnit::PoundalFeet);
        }


        [[nodiscard]] constexpr double pound_force_inches() const
        {
            return convert_from_base(TorqueUnit::PoundForceInches);
        }

        [[nodiscard]] static constexpr Torque from_pound_force_inches(double value)
        {
            return Torque(value, TorqueUnit::PoundForceInches);
        }


        [[nodiscard]] constexpr double kilopound_force_inches() const
        {
            return convert_from_base(TorqueUnit::KilopoundForceInches);
        }

        [[nodiscard]] static constexpr Torque from_kilopound_force_inches(double value)
        {
            return Torque(value, TorqueUnit::KilopoundForceInches);
        }


        [[nodiscard]] constexpr double megapound_force_inches() const
        {
            return convert_from_base(TorqueUnit::MegapoundForceInches);
        }

        [[nodiscard]] static constexpr Torque from_megapound_force_inches(double value)
        {
            return Torque(value, TorqueUnit::MegapoundForceInches);
        }


        [[nodiscard]] constexpr double pound_force_feet() const
        {
            return convert_from_base(TorqueUnit::PoundForceFeet);
        }

        [[nodiscard]] static constexpr Torque from_pound_force_feet(double value)
        {
            return Torque(value, TorqueUnit::PoundForceFeet);
        }


        [[nodiscard]] constexpr double kilopound_force_feet() const
        {
            return convert_from_base(TorqueUnit::KilopoundForceFeet);
        }

        [[nodiscard]] static constexpr Torque from_kilopound_force_feet(double value)
        {
            return Torque(value, TorqueUnit::KilopoundForceFeet);
        }


        [[nodiscard]] constexpr double megapound_force_feet() const
        {
            return convert_from_base(TorqueUnit::MegapoundForceFeet);
        }

        [[nodiscard]] static constexpr Torque from_megapound_force_feet(double value)
        {
            return Torque(value, TorqueUnit::MegapoundForceFeet);
        }


        [[nodiscard]] constexpr double gram_force_millimeters() const
        {
            return convert_from_base(TorqueUnit::GramForceMillimeters);
        }

        [[nodiscard]] static constexpr Torque from_gram_force_millimeters(double value)
        {
            return Torque(value, TorqueUnit::GramForceMillimeters);
        }


        [[nodiscard]] constexpr double gram_force_centimeters() const
        {
            return convert_from_base(TorqueUnit::GramForceCentimeters);
        }

        [[nodiscard]] static constexpr Torque from_gram_force_centimeters(double value)
        {
            return Torque(value, TorqueUnit::GramForceCentimeters);
        }


        [[nodiscard]] constexpr double gram_force_meters() const
        {
            return convert_from_base(TorqueUnit::GramForceMeters);
        }

        [[nodiscard]] static constexpr Torque from_gram_force_meters(double value)
        {
            return Torque(value, TorqueUnit::GramForceMeters);
        }


        [[nodiscard]] constexpr double kilogram_force_millimeters() const
        {
            return convert_from_base(TorqueUnit::KilogramForceMillimeters);
        }

        [[nodiscard]] static constexpr Torque from_kilogram_force_millimeters(double value)
        {
            return Torque(value, TorqueUnit::KilogramForceMillimeters);
        }


        [[nodiscard]] constexpr double kilogram_force_centimeters() const
        {
            return convert_from_base(TorqueUnit::KilogramForceCentimeters);
        }

        [[nodiscard]] static constexpr Torque from_kilogram_force_centimeters(double value)
        {
            return Torque(value, TorqueUnit::KilogramForceCentimeters);
        }


        [[nodiscard]] constexpr double kilogram_force_meters() const
        {
            return convert_from_base(TorqueUnit::KilogramForceMeters);
        }

        [[nodiscard]] static constexpr Torque from_kilogram_force_meters(double value)
        {
            return Torque(value, TorqueUnit::KilogramForceMeters);
        }


        [[nodiscard]] constexpr double tonne_force_millimeters() const
        {
            return convert_from_base(TorqueUnit::TonneForceMillimeters);
        }

        [[nodiscard]] static constexpr Torque from_tonne_force_millimeters(double value)
        {
            return Torque(value, TorqueUnit::TonneForceMillimeters);
        }


        [[nodiscard]] constexpr double tonne_force_centimeters() const
        {
            return convert_from_base(TorqueUnit::TonneForceCentimeters);
        }

        [[nodiscard]] static constexpr Torque from_tonne_force_centimeters(double value)
        {
            return Torque(value, TorqueUnit::TonneForceCentimeters);
        }


        [[nodiscard]] constexpr double tonne_force_meters() const
        {
            return convert_from_base(TorqueUnit::TonneForceMeters);
        }

        [[nodiscard]] static constexpr Torque from_tonne_force_meters(double value)
        {
            return Torque(value, TorqueUnit::TonneForceMeters);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, TorqueUnit unit)
        {
            switch (unit)
            {

            case TorqueUnit::NewtonMillimeters:
                return value * 0.001;

            case TorqueUnit::KilonewtonMillimeters:
                return (value * 1e3) * 0.001;

            case TorqueUnit::MeganewtonMillimeters:
                return (value * 1e6) * 0.001;

            case TorqueUnit::NewtonCentimeters:
                return value * 0.01;

            case TorqueUnit::KilonewtonCentimeters:
                return (value * 1e3) * 0.01;

            case TorqueUnit::MeganewtonCentimeters:
                return (value * 1e6) * 0.01;

            case TorqueUnit::NewtonMeters:
                return value;

            case TorqueUnit::KilonewtonMeters:
                return (value * 1e3);

            case TorqueUnit::MeganewtonMeters:
                return (value * 1e6);

            case TorqueUnit::PoundalFeet:
                return value * 0.138254954376 * 0.3048;

            case TorqueUnit::PoundForceInches:
                return value * 4.4482216152605 * 2.54e-2;

            case TorqueUnit::KilopoundForceInches:
                return (value * 1e3) * 4.4482216152605 * 2.54e-2;

            case TorqueUnit::MegapoundForceInches:
                return (value * 1e6) * 4.4482216152605 * 2.54e-2;

            case TorqueUnit::PoundForceFeet:
                return value * 4.4482216152605 * 0.3048;

            case TorqueUnit::KilopoundForceFeet:
                return (value * 1e3) * 4.4482216152605 * 0.3048;

            case TorqueUnit::MegapoundForceFeet:
                return (value * 1e6) * 4.4482216152605 * 0.3048;

            case TorqueUnit::GramForceMillimeters:
                return value * 9.80665e-6;

            case TorqueUnit::GramForceCentimeters:
                return value * 9.80665e-5;

            case TorqueUnit::GramForceMeters:
                return value * 9.80665e-3;

            case TorqueUnit::KilogramForceMillimeters:
                return value * 9.80665e-3;

            case TorqueUnit::KilogramForceCentimeters:
                return value * 9.80665e-2;

            case TorqueUnit::KilogramForceMeters:
                return value * 9.80665;

            case TorqueUnit::TonneForceMillimeters:
                return value * 9.80665;

            case TorqueUnit::TonneForceCentimeters:
                return value * 9.80665e1;

            case TorqueUnit::TonneForceMeters:
                return value * 9.80665e3;

            }

            throw std::invalid_argument("Unknown Torque unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(TorqueUnit unit) const
        {
            switch (unit)
            {

            case TorqueUnit::NewtonMillimeters:
                return value_ * 1000;

            case TorqueUnit::KilonewtonMillimeters:
                return (value_ * 1000) / 1e3;

            case TorqueUnit::MeganewtonMillimeters:
                return (value_ * 1000) / 1e6;

            case TorqueUnit::NewtonCentimeters:
                return value_ * 100;

            case TorqueUnit::KilonewtonCentimeters:
                return (value_ * 100) / 1e3;

            case TorqueUnit::MeganewtonCentimeters:
                return (value_ * 100) / 1e6;

            case TorqueUnit::NewtonMeters:
                return value_;

            case TorqueUnit::KilonewtonMeters:
                return (value_) / 1e3;

            case TorqueUnit::MeganewtonMeters:
                return (value_) / 1e6;

            case TorqueUnit::PoundalFeet:
                return value_ / (0.138254954376 * 0.3048);

            case TorqueUnit::PoundForceInches:
                return value_ / (4.4482216152605 * 2.54e-2);

            case TorqueUnit::KilopoundForceInches:
                return (value_ / (4.4482216152605 * 2.54e-2)) / 1e3;

            case TorqueUnit::MegapoundForceInches:
                return (value_ / (4.4482216152605 * 2.54e-2)) / 1e6;

            case TorqueUnit::PoundForceFeet:
                return value_ / (4.4482216152605 * 0.3048);

            case TorqueUnit::KilopoundForceFeet:
                return (value_ / (4.4482216152605 * 0.3048)) / 1e3;

            case TorqueUnit::MegapoundForceFeet:
                return (value_ / (4.4482216152605 * 0.3048)) / 1e6;

            case TorqueUnit::GramForceMillimeters:
                return value_ / 9.80665e-6;

            case TorqueUnit::GramForceCentimeters:
                return value_ / 9.80665e-5;

            case TorqueUnit::GramForceMeters:
                return value_ / 9.80665e-3;

            case TorqueUnit::KilogramForceMillimeters:
                return value_ / 9.80665e-3;

            case TorqueUnit::KilogramForceCentimeters:
                return value_ / 9.80665e-2;

            case TorqueUnit::KilogramForceMeters:
                return value_ / 9.80665;

            case TorqueUnit::TonneForceMillimeters:
                return value_ / 9.80665;

            case TorqueUnit::TonneForceCentimeters:
                return value_ / 9.80665e1;

            case TorqueUnit::TonneForceMeters:
                return value_ / 9.80665e3;

            }

            throw std::invalid_argument("Unknown Torque unit.");
        }

        double value_;
    };
}
