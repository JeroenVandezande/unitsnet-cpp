#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class ForcePerLengthUnit : std::uint8_t
    {
        NewtonsPerMeter,
        NanonewtonsPerMeter,
        MicronewtonsPerMeter,
        MillinewtonsPerMeter,
        CentinewtonsPerMeter,
        DecinewtonsPerMeter,
        DecanewtonsPerMeter,
        KilonewtonsPerMeter,
        MeganewtonsPerMeter,
        NewtonsPerCentimeter,
        NanonewtonsPerCentimeter,
        MicronewtonsPerCentimeter,
        MillinewtonsPerCentimeter,
        CentinewtonsPerCentimeter,
        DecinewtonsPerCentimeter,
        DecanewtonsPerCentimeter,
        KilonewtonsPerCentimeter,
        MeganewtonsPerCentimeter,
        NewtonsPerMillimeter,
        NanonewtonsPerMillimeter,
        MicronewtonsPerMillimeter,
        MillinewtonsPerMillimeter,
        CentinewtonsPerMillimeter,
        DecinewtonsPerMillimeter,
        DecanewtonsPerMillimeter,
        KilonewtonsPerMillimeter,
        MeganewtonsPerMillimeter,
        KilogramsForcePerMeter,
        KilogramsForcePerCentimeter,
        KilogramsForcePerMillimeter,
        TonnesForcePerMeter,
        TonnesForcePerCentimeter,
        TonnesForcePerMillimeter,
        PoundsForcePerFoot,
        PoundsForcePerInch,
        PoundsForcePerYard,
        KilopoundsForcePerFoot,
        KilopoundsForcePerInch,
    };

    /// <summary>The magnitude of force per unit length.</summary>
    class ForcePerLength
    {
    public:
        constexpr explicit ForcePerLength(
            const un_scalar_t value,
            const ForcePerLengthUnit unit = ForcePerLengthUnit::NewtonsPerMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const ForcePerLengthUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ForcePerLength operator+(const ForcePerLength other) const noexcept
        {
            return ForcePerLength(value_ + other.value_);
        }

        [[nodiscard]] constexpr ForcePerLength operator-(const ForcePerLength other) const noexcept
        {
            return ForcePerLength(value_ - other.value_);
        }

        [[nodiscard]] constexpr ForcePerLength operator*(const un_scalar_t scalar) const noexcept
        {
            return ForcePerLength(value_ * scalar);
        }

        [[nodiscard]] constexpr ForcePerLength operator/(const un_scalar_t scalar) const noexcept
        {
            return ForcePerLength(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ForcePerLength other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const ForcePerLength other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t newtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::NewtonsPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_newtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::NewtonsPerMeter);
        }


        [[nodiscard]] constexpr un_scalar_t nanonewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::NanonewtonsPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_nanonewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::NanonewtonsPerMeter);
        }


        [[nodiscard]] constexpr un_scalar_t micronewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::MicronewtonsPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_micronewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MicronewtonsPerMeter);
        }


        [[nodiscard]] constexpr un_scalar_t millinewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::MillinewtonsPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_millinewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MillinewtonsPerMeter);
        }


        [[nodiscard]] constexpr un_scalar_t centinewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::CentinewtonsPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_centinewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::CentinewtonsPerMeter);
        }


        [[nodiscard]] constexpr un_scalar_t decinewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::DecinewtonsPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_decinewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::DecinewtonsPerMeter);
        }


        [[nodiscard]] constexpr un_scalar_t decanewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::DecanewtonsPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_decanewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::DecanewtonsPerMeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::KilonewtonsPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilonewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilonewtonsPerMeter);
        }


        [[nodiscard]] constexpr un_scalar_t meganewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::MeganewtonsPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_meganewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MeganewtonsPerMeter);
        }


        [[nodiscard]] constexpr un_scalar_t newtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::NewtonsPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_newtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::NewtonsPerCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t nanonewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::NanonewtonsPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_nanonewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::NanonewtonsPerCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t micronewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::MicronewtonsPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_micronewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MicronewtonsPerCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t millinewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::MillinewtonsPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_millinewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MillinewtonsPerCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t centinewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::CentinewtonsPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_centinewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::CentinewtonsPerCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t decinewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::DecinewtonsPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_decinewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::DecinewtonsPerCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t decanewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::DecanewtonsPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_decanewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::DecanewtonsPerCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::KilonewtonsPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilonewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilonewtonsPerCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t meganewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::MeganewtonsPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_meganewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MeganewtonsPerCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t newtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::NewtonsPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_newtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::NewtonsPerMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t nanonewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::NanonewtonsPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_nanonewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::NanonewtonsPerMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t micronewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::MicronewtonsPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_micronewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MicronewtonsPerMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t millinewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::MillinewtonsPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_millinewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MillinewtonsPerMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t centinewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::CentinewtonsPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_centinewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::CentinewtonsPerMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t decinewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::DecinewtonsPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_decinewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::DecinewtonsPerMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t decanewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::DecanewtonsPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_decanewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::DecanewtonsPerMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::KilonewtonsPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilonewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilonewtonsPerMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t meganewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::MeganewtonsPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_meganewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MeganewtonsPerMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::KilogramsForcePerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilograms_force_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilogramsForcePerMeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::KilogramsForcePerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilograms_force_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilogramsForcePerCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::KilogramsForcePerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilograms_force_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilogramsForcePerMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::TonnesForcePerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_tonnes_force_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::TonnesForcePerMeter);
        }


        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::TonnesForcePerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_tonnes_force_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::TonnesForcePerCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::TonnesForcePerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_tonnes_force_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::TonnesForcePerMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_force_per_foot() const
        {
            return convert_from_base(ForcePerLengthUnit::PoundsForcePerFoot);
        }

        [[nodiscard]] static constexpr ForcePerLength from_pounds_force_per_foot(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::PoundsForcePerFoot);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_force_per_inch() const
        {
            return convert_from_base(ForcePerLengthUnit::PoundsForcePerInch);
        }

        [[nodiscard]] static constexpr ForcePerLength from_pounds_force_per_inch(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::PoundsForcePerInch);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_force_per_yard() const
        {
            return convert_from_base(ForcePerLengthUnit::PoundsForcePerYard);
        }

        [[nodiscard]] static constexpr ForcePerLength from_pounds_force_per_yard(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::PoundsForcePerYard);
        }


        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_foot() const
        {
            return convert_from_base(ForcePerLengthUnit::KilopoundsForcePerFoot);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilopounds_force_per_foot(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilopoundsForcePerFoot);
        }


        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_inch() const
        {
            return convert_from_base(ForcePerLengthUnit::KilopoundsForcePerInch);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilopounds_force_per_inch(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilopoundsForcePerInch);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ForcePerLengthUnit unit)
        {
            switch (unit)
            {

            case ForcePerLengthUnit::NewtonsPerMeter:
                return value;

            case ForcePerLengthUnit::NanonewtonsPerMeter:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ForcePerLengthUnit::MicronewtonsPerMeter:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ForcePerLengthUnit::MillinewtonsPerMeter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ForcePerLengthUnit::CentinewtonsPerMeter:
                return (value * static_cast<un_scalar_t>(1e-2));

            case ForcePerLengthUnit::DecinewtonsPerMeter:
                return (value * static_cast<un_scalar_t>(1e-1));

            case ForcePerLengthUnit::DecanewtonsPerMeter:
                return (value * static_cast<un_scalar_t>(1e1));

            case ForcePerLengthUnit::KilonewtonsPerMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case ForcePerLengthUnit::MeganewtonsPerMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case ForcePerLengthUnit::NewtonsPerCentimeter:
                return value * 1e2;

            case ForcePerLengthUnit::NanonewtonsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-9)) * 1e2;

            case ForcePerLengthUnit::MicronewtonsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-6)) * 1e2;

            case ForcePerLengthUnit::MillinewtonsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) * 1e2;

            case ForcePerLengthUnit::CentinewtonsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-2)) * 1e2;

            case ForcePerLengthUnit::DecinewtonsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-1)) * 1e2;

            case ForcePerLengthUnit::DecanewtonsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e1)) * 1e2;

            case ForcePerLengthUnit::KilonewtonsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * 1e2;

            case ForcePerLengthUnit::MeganewtonsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e6)) * 1e2;

            case ForcePerLengthUnit::NewtonsPerMillimeter:
                return value * 1e3;

            case ForcePerLengthUnit::NanonewtonsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e-9)) * 1e3;

            case ForcePerLengthUnit::MicronewtonsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e-6)) * 1e3;

            case ForcePerLengthUnit::MillinewtonsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) * 1e3;

            case ForcePerLengthUnit::CentinewtonsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e-2)) * 1e3;

            case ForcePerLengthUnit::DecinewtonsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e-1)) * 1e3;

            case ForcePerLengthUnit::DecanewtonsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e1)) * 1e3;

            case ForcePerLengthUnit::KilonewtonsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * 1e3;

            case ForcePerLengthUnit::MeganewtonsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e6)) * 1e3;

            case ForcePerLengthUnit::KilogramsForcePerMeter:
                return value * 9.80665;

            case ForcePerLengthUnit::KilogramsForcePerCentimeter:
                return value * 980.665;

            case ForcePerLengthUnit::KilogramsForcePerMillimeter:
                return value * 9.80665e3;

            case ForcePerLengthUnit::TonnesForcePerMeter:
                return value * 9.80665e3;

            case ForcePerLengthUnit::TonnesForcePerCentimeter:
                return value * 9.80665e5;

            case ForcePerLengthUnit::TonnesForcePerMillimeter:
                return value * 9.80665e6;

            case ForcePerLengthUnit::PoundsForcePerFoot:
                return value * 4.4482216152605 / 0.3048;

            case ForcePerLengthUnit::PoundsForcePerInch:
                return value * 4.4482216152605 / 2.54e-2;

            case ForcePerLengthUnit::PoundsForcePerYard:
                return value * 4.4482216152605 / 0.9144;

            case ForcePerLengthUnit::KilopoundsForcePerFoot:
                return value * 4.4482216152605 / 0.3048e-3;

            case ForcePerLengthUnit::KilopoundsForcePerInch:
                return value * 4.4482216152605 / 2.54e-5;

            }

            throw std::invalid_argument("Unknown ForcePerLength unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ForcePerLengthUnit unit) const
        {
            switch (unit)
            {

            case ForcePerLengthUnit::NewtonsPerMeter:
                return value_;

            case ForcePerLengthUnit::NanonewtonsPerMeter:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case ForcePerLengthUnit::MicronewtonsPerMeter:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case ForcePerLengthUnit::MillinewtonsPerMeter:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case ForcePerLengthUnit::CentinewtonsPerMeter:
                return (value_) / static_cast<un_scalar_t>(1e-2);

            case ForcePerLengthUnit::DecinewtonsPerMeter:
                return (value_) / static_cast<un_scalar_t>(1e-1);

            case ForcePerLengthUnit::DecanewtonsPerMeter:
                return (value_) / static_cast<un_scalar_t>(1e1);

            case ForcePerLengthUnit::KilonewtonsPerMeter:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::MeganewtonsPerMeter:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case ForcePerLengthUnit::NewtonsPerCentimeter:
                return value_ / 1e2;

            case ForcePerLengthUnit::NanonewtonsPerCentimeter:
                return (value_ / 1e2) / static_cast<un_scalar_t>(1e-9);

            case ForcePerLengthUnit::MicronewtonsPerCentimeter:
                return (value_ / 1e2) / static_cast<un_scalar_t>(1e-6);

            case ForcePerLengthUnit::MillinewtonsPerCentimeter:
                return (value_ / 1e2) / static_cast<un_scalar_t>(1e-3);

            case ForcePerLengthUnit::CentinewtonsPerCentimeter:
                return (value_ / 1e2) / static_cast<un_scalar_t>(1e-2);

            case ForcePerLengthUnit::DecinewtonsPerCentimeter:
                return (value_ / 1e2) / static_cast<un_scalar_t>(1e-1);

            case ForcePerLengthUnit::DecanewtonsPerCentimeter:
                return (value_ / 1e2) / static_cast<un_scalar_t>(1e1);

            case ForcePerLengthUnit::KilonewtonsPerCentimeter:
                return (value_ / 1e2) / static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::MeganewtonsPerCentimeter:
                return (value_ / 1e2) / static_cast<un_scalar_t>(1e6);

            case ForcePerLengthUnit::NewtonsPerMillimeter:
                return value_ / 1e3;

            case ForcePerLengthUnit::NanonewtonsPerMillimeter:
                return (value_ / 1e3) / static_cast<un_scalar_t>(1e-9);

            case ForcePerLengthUnit::MicronewtonsPerMillimeter:
                return (value_ / 1e3) / static_cast<un_scalar_t>(1e-6);

            case ForcePerLengthUnit::MillinewtonsPerMillimeter:
                return (value_ / 1e3) / static_cast<un_scalar_t>(1e-3);

            case ForcePerLengthUnit::CentinewtonsPerMillimeter:
                return (value_ / 1e3) / static_cast<un_scalar_t>(1e-2);

            case ForcePerLengthUnit::DecinewtonsPerMillimeter:
                return (value_ / 1e3) / static_cast<un_scalar_t>(1e-1);

            case ForcePerLengthUnit::DecanewtonsPerMillimeter:
                return (value_ / 1e3) / static_cast<un_scalar_t>(1e1);

            case ForcePerLengthUnit::KilonewtonsPerMillimeter:
                return (value_ / 1e3) / static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::MeganewtonsPerMillimeter:
                return (value_ / 1e3) / static_cast<un_scalar_t>(1e6);

            case ForcePerLengthUnit::KilogramsForcePerMeter:
                return value_ / 9.80665;

            case ForcePerLengthUnit::KilogramsForcePerCentimeter:
                return value_ / 980.665;

            case ForcePerLengthUnit::KilogramsForcePerMillimeter:
                return value_ / 9.80665e3;

            case ForcePerLengthUnit::TonnesForcePerMeter:
                return value_ / 9.80665e3;

            case ForcePerLengthUnit::TonnesForcePerCentimeter:
                return value_ / 9.80665e5;

            case ForcePerLengthUnit::TonnesForcePerMillimeter:
                return value_ / 9.80665e6;

            case ForcePerLengthUnit::PoundsForcePerFoot:
                return value_ * 0.3048 / 4.4482216152605;

            case ForcePerLengthUnit::PoundsForcePerInch:
                return value_ * 2.54e-2 / 4.4482216152605;

            case ForcePerLengthUnit::PoundsForcePerYard:
                return value_ * 0.9144 / 4.4482216152605;

            case ForcePerLengthUnit::KilopoundsForcePerFoot:
                return value_ * 0.3048e-3 / 4.4482216152605;

            case ForcePerLengthUnit::KilopoundsForcePerInch:
                return value_ * 2.54e-5 / 4.4482216152605;

            }

            throw std::invalid_argument("Unknown ForcePerLength unit.");
        }

        un_scalar_t value_;
    };
}
