#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class FluidResistanceUnit : std::uint8_t
    {
        PascalSecondsPerLiter,
        PascalMinutesPerLiter,
        PascalSecondsPerMilliliter,
        PascalMinutesPerMilliliter,
        PascalSecondsPerCubicMeter,
        MegapascalSecondsPerCubicMeter,
        PascalMinutesPerCubicMeter,
        PascalSecondsPerCubicCentimeter,
        PascalMinutesPerCubicCentimeter,
        DyneSecondsPerCentimeterToTheFifth,
        MillimeterMercurySecondsPerLiter,
        MillimeterMercuryMinutesPerLiter,
        MillimeterMercurySecondsPerMilliliter,
        MillimeterMercuryMinutesPerMilliliter,
        MillimeterMercurySecondsPerCubicCentimeter,
        MillimeterMercuryMinutesPerCubicCentimeter,
        MillimeterMercurySecondsPerCubicMeter,
        MillimeterMercuryMinutesPerCubicMeter,
        WoodUnits,
    };

    /// <summary>Fluid Resistance is a force acting opposite to the relative motion of any object moving with respect to a surrounding fluid. Fluid Resistance is sometimes referred to as drag or fluid friction.</summary>
    class FluidResistance
    {
    public:
        constexpr explicit FluidResistance(
            const un_scalar_t value,
            const FluidResistanceUnit unit = FluidResistanceUnit::PascalSecondsPerCubicMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const FluidResistanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr FluidResistance operator+(const FluidResistance other) const noexcept
        {
            return FluidResistance(value_ + other.value_);
        }

        [[nodiscard]] constexpr FluidResistance operator-(const FluidResistance other) const noexcept
        {
            return FluidResistance(value_ - other.value_);
        }

        [[nodiscard]] constexpr FluidResistance operator*(const un_scalar_t scalar) const noexcept
        {
            return FluidResistance(value_ * scalar);
        }

        [[nodiscard]] constexpr FluidResistance operator/(const un_scalar_t scalar) const noexcept
        {
            return FluidResistance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const FluidResistance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const FluidResistance other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t pascal_seconds_per_liter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalSecondsPerLiter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_seconds_per_liter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalSecondsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t pascal_minutes_per_liter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalMinutesPerLiter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_minutes_per_liter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalMinutesPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t pascal_seconds_per_milliliter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalSecondsPerMilliliter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_seconds_per_milliliter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalSecondsPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t pascal_minutes_per_milliliter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalMinutesPerMilliliter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_minutes_per_milliliter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalMinutesPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t pascal_seconds_per_cubic_meter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalSecondsPerCubicMeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_seconds_per_cubic_meter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalSecondsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t megapascal_seconds_per_cubic_meter() const
        {
            return convert_from_base(FluidResistanceUnit::MegapascalSecondsPerCubicMeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_megapascal_seconds_per_cubic_meter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MegapascalSecondsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t pascal_minutes_per_cubic_meter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalMinutesPerCubicMeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_minutes_per_cubic_meter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalMinutesPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t pascal_seconds_per_cubic_centimeter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalSecondsPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_seconds_per_cubic_centimeter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalSecondsPerCubicCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t pascal_minutes_per_cubic_centimeter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalMinutesPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_minutes_per_cubic_centimeter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalMinutesPerCubicCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t dyne_seconds_per_centimeter_to_the_fifth() const
        {
            return convert_from_base(FluidResistanceUnit::DyneSecondsPerCentimeterToTheFifth);
        }

        [[nodiscard]] static constexpr FluidResistance from_dyne_seconds_per_centimeter_to_the_fifth(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::DyneSecondsPerCentimeterToTheFifth);
        }


        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_seconds_per_liter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercurySecondsPerLiter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_seconds_per_liter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercurySecondsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_minutes_per_liter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercuryMinutesPerLiter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_minutes_per_liter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercuryMinutesPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_seconds_per_milliliter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercurySecondsPerMilliliter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_seconds_per_milliliter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercurySecondsPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_minutes_per_milliliter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercuryMinutesPerMilliliter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_minutes_per_milliliter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercuryMinutesPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_seconds_per_cubic_centimeter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercurySecondsPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_seconds_per_cubic_centimeter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercurySecondsPerCubicCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_minutes_per_cubic_centimeter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercuryMinutesPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_minutes_per_cubic_centimeter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercuryMinutesPerCubicCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_seconds_per_cubic_meter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercurySecondsPerCubicMeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_seconds_per_cubic_meter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercurySecondsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t millimeter_mercury_minutes_per_cubic_meter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercuryMinutesPerCubicMeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_minutes_per_cubic_meter(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercuryMinutesPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t wood_units() const
        {
            return convert_from_base(FluidResistanceUnit::WoodUnits);
        }

        [[nodiscard]] static constexpr FluidResistance from_wood_units(const un_scalar_t value)
        {
            return FluidResistance(value, FluidResistanceUnit::WoodUnits);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, FluidResistanceUnit unit)
        {
            switch (unit)
            {

            case FluidResistanceUnit::PascalSecondsPerLiter:
                return value * 1e3;

            case FluidResistanceUnit::PascalMinutesPerLiter:
                return value * 6e4;

            case FluidResistanceUnit::PascalSecondsPerMilliliter:
                return value * 1e6;

            case FluidResistanceUnit::PascalMinutesPerMilliliter:
                return value * 6e7;

            case FluidResistanceUnit::PascalSecondsPerCubicMeter:
                return value;

            case FluidResistanceUnit::MegapascalSecondsPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case FluidResistanceUnit::PascalMinutesPerCubicMeter:
                return value * 60;

            case FluidResistanceUnit::PascalSecondsPerCubicCentimeter:
                return value * 1e6;

            case FluidResistanceUnit::PascalMinutesPerCubicCentimeter:
                return value * 6e7;

            case FluidResistanceUnit::DyneSecondsPerCentimeterToTheFifth:
                return value * 1e5;

            case FluidResistanceUnit::MillimeterMercurySecondsPerLiter:
                return value * 1.33322368e5;

            case FluidResistanceUnit::MillimeterMercuryMinutesPerLiter:
                return value * 7.99934208e6;

            case FluidResistanceUnit::MillimeterMercurySecondsPerMilliliter:
                return value * 1.33322368e8;

            case FluidResistanceUnit::MillimeterMercuryMinutesPerMilliliter:
                return value * 7.99934208e9;

            case FluidResistanceUnit::MillimeterMercurySecondsPerCubicCentimeter:
                return value * 1.33322368e8;

            case FluidResistanceUnit::MillimeterMercuryMinutesPerCubicCentimeter:
                return value * 7.99934208e9;

            case FluidResistanceUnit::MillimeterMercurySecondsPerCubicMeter:
                return value * 133.322368;

            case FluidResistanceUnit::MillimeterMercuryMinutesPerCubicMeter:
                return value * 7.99934208e3;

            case FluidResistanceUnit::WoodUnits:
                return value * 7.99934208e6;

            }

            throw std::invalid_argument("Unknown FluidResistance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const FluidResistanceUnit unit) const
        {
            switch (unit)
            {

            case FluidResistanceUnit::PascalSecondsPerLiter:
                return value_ / 1e3;

            case FluidResistanceUnit::PascalMinutesPerLiter:
                return value_ / 6e4;

            case FluidResistanceUnit::PascalSecondsPerMilliliter:
                return value_ / 1e6;

            case FluidResistanceUnit::PascalMinutesPerMilliliter:
                return value_ / 6e7;

            case FluidResistanceUnit::PascalSecondsPerCubicMeter:
                return value_;

            case FluidResistanceUnit::MegapascalSecondsPerCubicMeter:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case FluidResistanceUnit::PascalMinutesPerCubicMeter:
                return value_ / 60;

            case FluidResistanceUnit::PascalSecondsPerCubicCentimeter:
                return value_ / 1e6;

            case FluidResistanceUnit::PascalMinutesPerCubicCentimeter:
                return value_ / 6e7;

            case FluidResistanceUnit::DyneSecondsPerCentimeterToTheFifth:
                return value_ / 1e5;

            case FluidResistanceUnit::MillimeterMercurySecondsPerLiter:
                return value_ / 1.33322368e5;

            case FluidResistanceUnit::MillimeterMercuryMinutesPerLiter:
                return value_ / 7.99934208e6;

            case FluidResistanceUnit::MillimeterMercurySecondsPerMilliliter:
                return value_ / 1.33322368e8;

            case FluidResistanceUnit::MillimeterMercuryMinutesPerMilliliter:
                return value_ / 7.99934208e9;

            case FluidResistanceUnit::MillimeterMercurySecondsPerCubicCentimeter:
                return value_ / 1.33322368e8;

            case FluidResistanceUnit::MillimeterMercuryMinutesPerCubicCentimeter:
                return value_ / 7.99934208e9;

            case FluidResistanceUnit::MillimeterMercurySecondsPerCubicMeter:
                return value_ / 133.322368;

            case FluidResistanceUnit::MillimeterMercuryMinutesPerCubicMeter:
                return value_ / 7.99934208e3;

            case FluidResistanceUnit::WoodUnits:
                return value_ / 7.99934208e6;

            }

            throw std::invalid_argument("Unknown FluidResistance unit.");
        }

        un_scalar_t value_;
    };
}
