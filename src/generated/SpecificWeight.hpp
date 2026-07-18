#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class SpecificWeightUnit : std::uint16_t
    {
        NewtonsPerCubicMillimeter,
        KilonewtonsPerCubicMillimeter,
        NewtonsPerCubicCentimeter,
        KilonewtonsPerCubicCentimeter,
        NewtonsPerCubicMeter,
        KilonewtonsPerCubicMeter,
        MeganewtonsPerCubicMeter,
        KilogramsForcePerCubicMillimeter,
        KilogramsForcePerCubicCentimeter,
        KilogramsForcePerCubicMeter,
        PoundsForcePerCubicInch,
        KilopoundsForcePerCubicInch,
        PoundsForcePerCubicFoot,
        KilopoundsForcePerCubicFoot,
        TonnesForcePerCubicMillimeter,
        TonnesForcePerCubicCentimeter,
        TonnesForcePerCubicMeter,
    };

    /// <summary>The SpecificWeight, or more precisely, the volumetric weight density, of a substance is its weight per unit volume.</summary>
    class SpecificWeight
    {
    public:
        constexpr explicit SpecificWeight(
            double value,
            SpecificWeightUnit unit = SpecificWeightUnit::NewtonsPerCubicMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(SpecificWeightUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr SpecificWeight operator+(SpecificWeight other) const noexcept
        {
            return SpecificWeight(value_ + other.value_);
        }

        [[nodiscard]] constexpr SpecificWeight operator-(SpecificWeight other) const noexcept
        {
            return SpecificWeight(value_ - other.value_);
        }

        [[nodiscard]] constexpr SpecificWeight operator*(double scalar) const noexcept
        {
            return SpecificWeight(value_ * scalar);
        }

        [[nodiscard]] constexpr SpecificWeight operator/(double scalar) const noexcept
        {
            return SpecificWeight(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(SpecificWeight other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(SpecificWeight other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double newtons_per_cubic_millimeter() const
        {
            return convert_from_base(SpecificWeightUnit::NewtonsPerCubicMillimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_newtons_per_cubic_millimeter(double value)
        {
            return SpecificWeight(value, SpecificWeightUnit::NewtonsPerCubicMillimeter);
        }


        [[nodiscard]] constexpr double kilonewtons_per_cubic_millimeter() const
        {
            return convert_from_base(SpecificWeightUnit::KilonewtonsPerCubicMillimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilonewtons_per_cubic_millimeter(double value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilonewtonsPerCubicMillimeter);
        }


        [[nodiscard]] constexpr double newtons_per_cubic_centimeter() const
        {
            return convert_from_base(SpecificWeightUnit::NewtonsPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_newtons_per_cubic_centimeter(double value)
        {
            return SpecificWeight(value, SpecificWeightUnit::NewtonsPerCubicCentimeter);
        }


        [[nodiscard]] constexpr double kilonewtons_per_cubic_centimeter() const
        {
            return convert_from_base(SpecificWeightUnit::KilonewtonsPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilonewtons_per_cubic_centimeter(double value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilonewtonsPerCubicCentimeter);
        }


        [[nodiscard]] constexpr double newtons_per_cubic_meter() const
        {
            return convert_from_base(SpecificWeightUnit::NewtonsPerCubicMeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_newtons_per_cubic_meter(double value)
        {
            return SpecificWeight(value, SpecificWeightUnit::NewtonsPerCubicMeter);
        }


        [[nodiscard]] constexpr double kilonewtons_per_cubic_meter() const
        {
            return convert_from_base(SpecificWeightUnit::KilonewtonsPerCubicMeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilonewtons_per_cubic_meter(double value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilonewtonsPerCubicMeter);
        }


        [[nodiscard]] constexpr double meganewtons_per_cubic_meter() const
        {
            return convert_from_base(SpecificWeightUnit::MeganewtonsPerCubicMeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_meganewtons_per_cubic_meter(double value)
        {
            return SpecificWeight(value, SpecificWeightUnit::MeganewtonsPerCubicMeter);
        }


        [[nodiscard]] constexpr double kilograms_force_per_cubic_millimeter() const
        {
            return convert_from_base(SpecificWeightUnit::KilogramsForcePerCubicMillimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilograms_force_per_cubic_millimeter(double value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilogramsForcePerCubicMillimeter);
        }


        [[nodiscard]] constexpr double kilograms_force_per_cubic_centimeter() const
        {
            return convert_from_base(SpecificWeightUnit::KilogramsForcePerCubicCentimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilograms_force_per_cubic_centimeter(double value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilogramsForcePerCubicCentimeter);
        }


        [[nodiscard]] constexpr double kilograms_force_per_cubic_meter() const
        {
            return convert_from_base(SpecificWeightUnit::KilogramsForcePerCubicMeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilograms_force_per_cubic_meter(double value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilogramsForcePerCubicMeter);
        }


        [[nodiscard]] constexpr double pounds_force_per_cubic_inch() const
        {
            return convert_from_base(SpecificWeightUnit::PoundsForcePerCubicInch);
        }

        [[nodiscard]] static constexpr SpecificWeight from_pounds_force_per_cubic_inch(double value)
        {
            return SpecificWeight(value, SpecificWeightUnit::PoundsForcePerCubicInch);
        }


        [[nodiscard]] constexpr double kilopounds_force_per_cubic_inch() const
        {
            return convert_from_base(SpecificWeightUnit::KilopoundsForcePerCubicInch);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilopounds_force_per_cubic_inch(double value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilopoundsForcePerCubicInch);
        }


        [[nodiscard]] constexpr double pounds_force_per_cubic_foot() const
        {
            return convert_from_base(SpecificWeightUnit::PoundsForcePerCubicFoot);
        }

        [[nodiscard]] static constexpr SpecificWeight from_pounds_force_per_cubic_foot(double value)
        {
            return SpecificWeight(value, SpecificWeightUnit::PoundsForcePerCubicFoot);
        }


        [[nodiscard]] constexpr double kilopounds_force_per_cubic_foot() const
        {
            return convert_from_base(SpecificWeightUnit::KilopoundsForcePerCubicFoot);
        }

        [[nodiscard]] static constexpr SpecificWeight from_kilopounds_force_per_cubic_foot(double value)
        {
            return SpecificWeight(value, SpecificWeightUnit::KilopoundsForcePerCubicFoot);
        }


        [[nodiscard]] constexpr double tonnes_force_per_cubic_millimeter() const
        {
            return convert_from_base(SpecificWeightUnit::TonnesForcePerCubicMillimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_tonnes_force_per_cubic_millimeter(double value)
        {
            return SpecificWeight(value, SpecificWeightUnit::TonnesForcePerCubicMillimeter);
        }


        [[nodiscard]] constexpr double tonnes_force_per_cubic_centimeter() const
        {
            return convert_from_base(SpecificWeightUnit::TonnesForcePerCubicCentimeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_tonnes_force_per_cubic_centimeter(double value)
        {
            return SpecificWeight(value, SpecificWeightUnit::TonnesForcePerCubicCentimeter);
        }


        [[nodiscard]] constexpr double tonnes_force_per_cubic_meter() const
        {
            return convert_from_base(SpecificWeightUnit::TonnesForcePerCubicMeter);
        }

        [[nodiscard]] static constexpr SpecificWeight from_tonnes_force_per_cubic_meter(double value)
        {
            return SpecificWeight(value, SpecificWeightUnit::TonnesForcePerCubicMeter);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, SpecificWeightUnit unit)
        {
            switch (unit)
            {

            case SpecificWeightUnit::NewtonsPerCubicMillimeter:
                return value * 1000000000;

            case SpecificWeightUnit::KilonewtonsPerCubicMillimeter:
                return (value * 1e3) * 1000000000;

            case SpecificWeightUnit::NewtonsPerCubicCentimeter:
                return value * 1000000;

            case SpecificWeightUnit::KilonewtonsPerCubicCentimeter:
                return (value * 1e3) * 1000000;

            case SpecificWeightUnit::NewtonsPerCubicMeter:
                return value;

            case SpecificWeightUnit::KilonewtonsPerCubicMeter:
                return (value * 1e3);

            case SpecificWeightUnit::MeganewtonsPerCubicMeter:
                return (value * 1e6);

            case SpecificWeightUnit::KilogramsForcePerCubicMillimeter:
                return value * 9.80665e9;

            case SpecificWeightUnit::KilogramsForcePerCubicCentimeter:
                return value * 9.80665e6;

            case SpecificWeightUnit::KilogramsForcePerCubicMeter:
                return value * 9.80665;

            case SpecificWeightUnit::PoundsForcePerCubicInch:
                return value * 4.4482216152605 / 1.6387064e-5;

            case SpecificWeightUnit::KilopoundsForcePerCubicInch:
                return (value * 1e3) * 4.4482216152605 / 1.6387064e-5;

            case SpecificWeightUnit::PoundsForcePerCubicFoot:
                return value * 4.4482216152605 / 0.028316846592;

            case SpecificWeightUnit::KilopoundsForcePerCubicFoot:
                return (value * 1e3) * 4.4482216152605 / 0.028316846592;

            case SpecificWeightUnit::TonnesForcePerCubicMillimeter:
                return value * 9.80665e12;

            case SpecificWeightUnit::TonnesForcePerCubicCentimeter:
                return value * 9.80665e9;

            case SpecificWeightUnit::TonnesForcePerCubicMeter:
                return value * 9.80665e3;

            }

            throw std::invalid_argument("Unknown SpecificWeight unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(SpecificWeightUnit unit) const
        {
            switch (unit)
            {

            case SpecificWeightUnit::NewtonsPerCubicMillimeter:
                return value_ * 0.000000001;

            case SpecificWeightUnit::KilonewtonsPerCubicMillimeter:
                return (value_ * 0.000000001) / 1e3;

            case SpecificWeightUnit::NewtonsPerCubicCentimeter:
                return value_ * 0.000001;

            case SpecificWeightUnit::KilonewtonsPerCubicCentimeter:
                return (value_ * 0.000001) / 1e3;

            case SpecificWeightUnit::NewtonsPerCubicMeter:
                return value_;

            case SpecificWeightUnit::KilonewtonsPerCubicMeter:
                return (value_) / 1e3;

            case SpecificWeightUnit::MeganewtonsPerCubicMeter:
                return (value_) / 1e6;

            case SpecificWeightUnit::KilogramsForcePerCubicMillimeter:
                return value_ / 9.80665e9;

            case SpecificWeightUnit::KilogramsForcePerCubicCentimeter:
                return value_ / 9.80665e6;

            case SpecificWeightUnit::KilogramsForcePerCubicMeter:
                return value_ / 9.80665;

            case SpecificWeightUnit::PoundsForcePerCubicInch:
                return value_ * 1.6387064e-5 / 4.4482216152605;

            case SpecificWeightUnit::KilopoundsForcePerCubicInch:
                return (value_ * 1.6387064e-5 / 4.4482216152605) / 1e3;

            case SpecificWeightUnit::PoundsForcePerCubicFoot:
                return value_ * 0.028316846592 / 4.4482216152605;

            case SpecificWeightUnit::KilopoundsForcePerCubicFoot:
                return (value_ * 0.028316846592 / 4.4482216152605) / 1e3;

            case SpecificWeightUnit::TonnesForcePerCubicMillimeter:
                return value_ / 9.80665e12;

            case SpecificWeightUnit::TonnesForcePerCubicCentimeter:
                return value_ / 9.80665e9;

            case SpecificWeightUnit::TonnesForcePerCubicMeter:
                return value_ / 9.80665e3;

            }

            throw std::invalid_argument("Unknown SpecificWeight unit.");
        }

        double value_;
    };
}
