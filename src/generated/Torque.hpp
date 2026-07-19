#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class TorqueUnit : std::uint8_t
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
            const un_scalar_t value,
            const TorqueUnit unit = TorqueUnit::NewtonMeters)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const TorqueUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Torque operator+(const Torque other) const noexcept
        {
            return Torque(value_ + other.value_);
        }

        [[nodiscard]] constexpr Torque operator-(const Torque other) const noexcept
        {
            return Torque(value_ - other.value_);
        }

        [[nodiscard]] constexpr Torque operator*(const un_scalar_t scalar) const noexcept
        {
            return Torque(value_ * scalar);
        }

        [[nodiscard]] constexpr Torque operator/(const un_scalar_t scalar) const noexcept
        {
            return Torque(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Torque other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Torque other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t newton_millimeters() const
        {
            return convert_from_base(TorqueUnit::NewtonMillimeters);
        }

        [[nodiscard]] static constexpr Torque from_newton_millimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::NewtonMillimeters);
        }


        [[nodiscard]] constexpr un_scalar_t kilonewton_millimeters() const
        {
            return convert_from_base(TorqueUnit::KilonewtonMillimeters);
        }

        [[nodiscard]] static constexpr Torque from_kilonewton_millimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::KilonewtonMillimeters);
        }


        [[nodiscard]] constexpr un_scalar_t meganewton_millimeters() const
        {
            return convert_from_base(TorqueUnit::MeganewtonMillimeters);
        }

        [[nodiscard]] static constexpr Torque from_meganewton_millimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::MeganewtonMillimeters);
        }


        [[nodiscard]] constexpr un_scalar_t newton_centimeters() const
        {
            return convert_from_base(TorqueUnit::NewtonCentimeters);
        }

        [[nodiscard]] static constexpr Torque from_newton_centimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::NewtonCentimeters);
        }


        [[nodiscard]] constexpr un_scalar_t kilonewton_centimeters() const
        {
            return convert_from_base(TorqueUnit::KilonewtonCentimeters);
        }

        [[nodiscard]] static constexpr Torque from_kilonewton_centimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::KilonewtonCentimeters);
        }


        [[nodiscard]] constexpr un_scalar_t meganewton_centimeters() const
        {
            return convert_from_base(TorqueUnit::MeganewtonCentimeters);
        }

        [[nodiscard]] static constexpr Torque from_meganewton_centimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::MeganewtonCentimeters);
        }


        [[nodiscard]] constexpr un_scalar_t newton_meters() const
        {
            return convert_from_base(TorqueUnit::NewtonMeters);
        }

        [[nodiscard]] static constexpr Torque from_newton_meters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::NewtonMeters);
        }


        [[nodiscard]] constexpr un_scalar_t kilonewton_meters() const
        {
            return convert_from_base(TorqueUnit::KilonewtonMeters);
        }

        [[nodiscard]] static constexpr Torque from_kilonewton_meters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::KilonewtonMeters);
        }


        [[nodiscard]] constexpr un_scalar_t meganewton_meters() const
        {
            return convert_from_base(TorqueUnit::MeganewtonMeters);
        }

        [[nodiscard]] static constexpr Torque from_meganewton_meters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::MeganewtonMeters);
        }


        [[nodiscard]] constexpr un_scalar_t poundal_feet() const
        {
            return convert_from_base(TorqueUnit::PoundalFeet);
        }

        [[nodiscard]] static constexpr Torque from_poundal_feet(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::PoundalFeet);
        }


        [[nodiscard]] constexpr un_scalar_t pound_force_inches() const
        {
            return convert_from_base(TorqueUnit::PoundForceInches);
        }

        [[nodiscard]] static constexpr Torque from_pound_force_inches(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::PoundForceInches);
        }


        [[nodiscard]] constexpr un_scalar_t kilopound_force_inches() const
        {
            return convert_from_base(TorqueUnit::KilopoundForceInches);
        }

        [[nodiscard]] static constexpr Torque from_kilopound_force_inches(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::KilopoundForceInches);
        }


        [[nodiscard]] constexpr un_scalar_t megapound_force_inches() const
        {
            return convert_from_base(TorqueUnit::MegapoundForceInches);
        }

        [[nodiscard]] static constexpr Torque from_megapound_force_inches(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::MegapoundForceInches);
        }


        [[nodiscard]] constexpr un_scalar_t pound_force_feet() const
        {
            return convert_from_base(TorqueUnit::PoundForceFeet);
        }

        [[nodiscard]] static constexpr Torque from_pound_force_feet(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::PoundForceFeet);
        }


        [[nodiscard]] constexpr un_scalar_t kilopound_force_feet() const
        {
            return convert_from_base(TorqueUnit::KilopoundForceFeet);
        }

        [[nodiscard]] static constexpr Torque from_kilopound_force_feet(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::KilopoundForceFeet);
        }


        [[nodiscard]] constexpr un_scalar_t megapound_force_feet() const
        {
            return convert_from_base(TorqueUnit::MegapoundForceFeet);
        }

        [[nodiscard]] static constexpr Torque from_megapound_force_feet(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::MegapoundForceFeet);
        }


        [[nodiscard]] constexpr un_scalar_t gram_force_millimeters() const
        {
            return convert_from_base(TorqueUnit::GramForceMillimeters);
        }

        [[nodiscard]] static constexpr Torque from_gram_force_millimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::GramForceMillimeters);
        }


        [[nodiscard]] constexpr un_scalar_t gram_force_centimeters() const
        {
            return convert_from_base(TorqueUnit::GramForceCentimeters);
        }

        [[nodiscard]] static constexpr Torque from_gram_force_centimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::GramForceCentimeters);
        }


        [[nodiscard]] constexpr un_scalar_t gram_force_meters() const
        {
            return convert_from_base(TorqueUnit::GramForceMeters);
        }

        [[nodiscard]] static constexpr Torque from_gram_force_meters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::GramForceMeters);
        }


        [[nodiscard]] constexpr un_scalar_t kilogram_force_millimeters() const
        {
            return convert_from_base(TorqueUnit::KilogramForceMillimeters);
        }

        [[nodiscard]] static constexpr Torque from_kilogram_force_millimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::KilogramForceMillimeters);
        }


        [[nodiscard]] constexpr un_scalar_t kilogram_force_centimeters() const
        {
            return convert_from_base(TorqueUnit::KilogramForceCentimeters);
        }

        [[nodiscard]] static constexpr Torque from_kilogram_force_centimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::KilogramForceCentimeters);
        }


        [[nodiscard]] constexpr un_scalar_t kilogram_force_meters() const
        {
            return convert_from_base(TorqueUnit::KilogramForceMeters);
        }

        [[nodiscard]] static constexpr Torque from_kilogram_force_meters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::KilogramForceMeters);
        }


        [[nodiscard]] constexpr un_scalar_t tonne_force_millimeters() const
        {
            return convert_from_base(TorqueUnit::TonneForceMillimeters);
        }

        [[nodiscard]] static constexpr Torque from_tonne_force_millimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::TonneForceMillimeters);
        }


        [[nodiscard]] constexpr un_scalar_t tonne_force_centimeters() const
        {
            return convert_from_base(TorqueUnit::TonneForceCentimeters);
        }

        [[nodiscard]] static constexpr Torque from_tonne_force_centimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::TonneForceCentimeters);
        }


        [[nodiscard]] constexpr un_scalar_t tonne_force_meters() const
        {
            return convert_from_base(TorqueUnit::TonneForceMeters);
        }

        [[nodiscard]] static constexpr Torque from_tonne_force_meters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::TonneForceMeters);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, TorqueUnit unit)
        {
            switch (unit)
            {

            case TorqueUnit::NewtonMillimeters:
                return value * static_cast<un_scalar_t>(0.001);

            case TorqueUnit::KilonewtonMillimeters:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.001);

            case TorqueUnit::MeganewtonMillimeters:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.001);

            case TorqueUnit::NewtonCentimeters:
                return value * static_cast<un_scalar_t>(0.01);

            case TorqueUnit::KilonewtonCentimeters:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.01);

            case TorqueUnit::MeganewtonCentimeters:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.01);

            case TorqueUnit::NewtonMeters:
                return value;

            case TorqueUnit::KilonewtonMeters:
                return (value * static_cast<un_scalar_t>(1e3));

            case TorqueUnit::MeganewtonMeters:
                return (value * static_cast<un_scalar_t>(1e6));

            case TorqueUnit::PoundalFeet:
                return value * static_cast<un_scalar_t>(0.138254954376) * static_cast<un_scalar_t>(0.3048);

            case TorqueUnit::PoundForceInches:
                return value * static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(2.54e-2);

            case TorqueUnit::KilopoundForceInches:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(2.54e-2);

            case TorqueUnit::MegapoundForceInches:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(2.54e-2);

            case TorqueUnit::PoundForceFeet:
                return value * static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(0.3048);

            case TorqueUnit::KilopoundForceFeet:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(0.3048);

            case TorqueUnit::MegapoundForceFeet:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(0.3048);

            case TorqueUnit::GramForceMillimeters:
                return value * static_cast<un_scalar_t>(9.80665e-6);

            case TorqueUnit::GramForceCentimeters:
                return value * static_cast<un_scalar_t>(9.80665e-5);

            case TorqueUnit::GramForceMeters:
                return value * static_cast<un_scalar_t>(9.80665e-3);

            case TorqueUnit::KilogramForceMillimeters:
                return value * static_cast<un_scalar_t>(9.80665e-3);

            case TorqueUnit::KilogramForceCentimeters:
                return value * static_cast<un_scalar_t>(9.80665e-2);

            case TorqueUnit::KilogramForceMeters:
                return value * static_cast<un_scalar_t>(9.80665);

            case TorqueUnit::TonneForceMillimeters:
                return value * static_cast<un_scalar_t>(9.80665);

            case TorqueUnit::TonneForceCentimeters:
                return value * static_cast<un_scalar_t>(9.80665e1);

            case TorqueUnit::TonneForceMeters:
                return value * static_cast<un_scalar_t>(9.80665e3);

            }

            throw std::invalid_argument("Unknown Torque unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const TorqueUnit unit) const
        {
            switch (unit)
            {

            case TorqueUnit::NewtonMillimeters:
                return value_ * static_cast<un_scalar_t>(1000);

            case TorqueUnit::KilonewtonMillimeters:
                return (value_ * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e3);

            case TorqueUnit::MeganewtonMillimeters:
                return (value_ * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e6);

            case TorqueUnit::NewtonCentimeters:
                return value_ * static_cast<un_scalar_t>(100);

            case TorqueUnit::KilonewtonCentimeters:
                return (value_ * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e3);

            case TorqueUnit::MeganewtonCentimeters:
                return (value_ * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e6);

            case TorqueUnit::NewtonMeters:
                return value_;

            case TorqueUnit::KilonewtonMeters:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case TorqueUnit::MeganewtonMeters:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case TorqueUnit::PoundalFeet:
                return value_ / (static_cast<un_scalar_t>(0.138254954376) * static_cast<un_scalar_t>(0.3048));

            case TorqueUnit::PoundForceInches:
                return value_ / (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(2.54e-2));

            case TorqueUnit::KilopoundForceInches:
                return (value_ / (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(2.54e-2))) / static_cast<un_scalar_t>(1e3);

            case TorqueUnit::MegapoundForceInches:
                return (value_ / (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(2.54e-2))) / static_cast<un_scalar_t>(1e6);

            case TorqueUnit::PoundForceFeet:
                return value_ / (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(0.3048));

            case TorqueUnit::KilopoundForceFeet:
                return (value_ / (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(0.3048))) / static_cast<un_scalar_t>(1e3);

            case TorqueUnit::MegapoundForceFeet:
                return (value_ / (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(0.3048))) / static_cast<un_scalar_t>(1e6);

            case TorqueUnit::GramForceMillimeters:
                return value_ / static_cast<un_scalar_t>(9.80665e-6);

            case TorqueUnit::GramForceCentimeters:
                return value_ / static_cast<un_scalar_t>(9.80665e-5);

            case TorqueUnit::GramForceMeters:
                return value_ / static_cast<un_scalar_t>(9.80665e-3);

            case TorqueUnit::KilogramForceMillimeters:
                return value_ / static_cast<un_scalar_t>(9.80665e-3);

            case TorqueUnit::KilogramForceCentimeters:
                return value_ / static_cast<un_scalar_t>(9.80665e-2);

            case TorqueUnit::KilogramForceMeters:
                return value_ / static_cast<un_scalar_t>(9.80665);

            case TorqueUnit::TonneForceMillimeters:
                return value_ / static_cast<un_scalar_t>(9.80665);

            case TorqueUnit::TonneForceCentimeters:
                return value_ / static_cast<un_scalar_t>(9.80665e1);

            case TorqueUnit::TonneForceMeters:
                return value_ / static_cast<un_scalar_t>(9.80665e3);

            }

            throw std::invalid_argument("Unknown Torque unit.");
        }

        un_scalar_t value_;
    };
}
