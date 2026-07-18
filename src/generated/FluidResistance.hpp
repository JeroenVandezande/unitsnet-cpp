#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class FluidResistanceUnit : std::uint16_t
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
            double value,
            FluidResistanceUnit unit = FluidResistanceUnit::PascalSecondsPerCubicMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(FluidResistanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr FluidResistance operator+(FluidResistance other) const noexcept
        {
            return FluidResistance(value_ + other.value_);
        }

        [[nodiscard]] constexpr FluidResistance operator-(FluidResistance other) const noexcept
        {
            return FluidResistance(value_ - other.value_);
        }

        [[nodiscard]] constexpr FluidResistance operator*(double scalar) const noexcept
        {
            return FluidResistance(value_ * scalar);
        }

        [[nodiscard]] constexpr FluidResistance operator/(double scalar) const noexcept
        {
            return FluidResistance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(FluidResistance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(FluidResistance other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double pascal_seconds_per_liter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalSecondsPerLiter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_seconds_per_liter(double value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalSecondsPerLiter);
        }


        [[nodiscard]] constexpr double pascal_minutes_per_liter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalMinutesPerLiter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_minutes_per_liter(double value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalMinutesPerLiter);
        }


        [[nodiscard]] constexpr double pascal_seconds_per_milliliter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalSecondsPerMilliliter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_seconds_per_milliliter(double value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalSecondsPerMilliliter);
        }


        [[nodiscard]] constexpr double pascal_minutes_per_milliliter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalMinutesPerMilliliter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_minutes_per_milliliter(double value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalMinutesPerMilliliter);
        }


        [[nodiscard]] constexpr double pascal_seconds_per_cubic_meter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalSecondsPerCubicMeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_seconds_per_cubic_meter(double value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalSecondsPerCubicMeter);
        }


        [[nodiscard]] constexpr double megapascal_seconds_per_cubic_meter() const
        {
            return convert_from_base(FluidResistanceUnit::MegapascalSecondsPerCubicMeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_megapascal_seconds_per_cubic_meter(double value)
        {
            return FluidResistance(value, FluidResistanceUnit::MegapascalSecondsPerCubicMeter);
        }


        [[nodiscard]] constexpr double pascal_minutes_per_cubic_meter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalMinutesPerCubicMeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_minutes_per_cubic_meter(double value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalMinutesPerCubicMeter);
        }


        [[nodiscard]] constexpr double pascal_seconds_per_cubic_centimeter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalSecondsPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_seconds_per_cubic_centimeter(double value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalSecondsPerCubicCentimeter);
        }


        [[nodiscard]] constexpr double pascal_minutes_per_cubic_centimeter() const
        {
            return convert_from_base(FluidResistanceUnit::PascalMinutesPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_pascal_minutes_per_cubic_centimeter(double value)
        {
            return FluidResistance(value, FluidResistanceUnit::PascalMinutesPerCubicCentimeter);
        }


        [[nodiscard]] constexpr double dyne_seconds_per_centimeter_to_the_fifth() const
        {
            return convert_from_base(FluidResistanceUnit::DyneSecondsPerCentimeterToTheFifth);
        }

        [[nodiscard]] static constexpr FluidResistance from_dyne_seconds_per_centimeter_to_the_fifth(double value)
        {
            return FluidResistance(value, FluidResistanceUnit::DyneSecondsPerCentimeterToTheFifth);
        }


        [[nodiscard]] constexpr double millimeter_mercury_seconds_per_liter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercurySecondsPerLiter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_seconds_per_liter(double value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercurySecondsPerLiter);
        }


        [[nodiscard]] constexpr double millimeter_mercury_minutes_per_liter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercuryMinutesPerLiter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_minutes_per_liter(double value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercuryMinutesPerLiter);
        }


        [[nodiscard]] constexpr double millimeter_mercury_seconds_per_milliliter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercurySecondsPerMilliliter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_seconds_per_milliliter(double value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercurySecondsPerMilliliter);
        }


        [[nodiscard]] constexpr double millimeter_mercury_minutes_per_milliliter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercuryMinutesPerMilliliter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_minutes_per_milliliter(double value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercuryMinutesPerMilliliter);
        }


        [[nodiscard]] constexpr double millimeter_mercury_seconds_per_cubic_centimeter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercurySecondsPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_seconds_per_cubic_centimeter(double value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercurySecondsPerCubicCentimeter);
        }


        [[nodiscard]] constexpr double millimeter_mercury_minutes_per_cubic_centimeter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercuryMinutesPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_minutes_per_cubic_centimeter(double value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercuryMinutesPerCubicCentimeter);
        }


        [[nodiscard]] constexpr double millimeter_mercury_seconds_per_cubic_meter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercurySecondsPerCubicMeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_seconds_per_cubic_meter(double value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercurySecondsPerCubicMeter);
        }


        [[nodiscard]] constexpr double millimeter_mercury_minutes_per_cubic_meter() const
        {
            return convert_from_base(FluidResistanceUnit::MillimeterMercuryMinutesPerCubicMeter);
        }

        [[nodiscard]] static constexpr FluidResistance from_millimeter_mercury_minutes_per_cubic_meter(double value)
        {
            return FluidResistance(value, FluidResistanceUnit::MillimeterMercuryMinutesPerCubicMeter);
        }


        [[nodiscard]] constexpr double wood_units() const
        {
            return convert_from_base(FluidResistanceUnit::WoodUnits);
        }

        [[nodiscard]] static constexpr FluidResistance from_wood_units(double value)
        {
            return FluidResistance(value, FluidResistanceUnit::WoodUnits);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, FluidResistanceUnit unit)
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
                return (value * 1e6);

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

        [[nodiscard]] constexpr double convert_from_base(FluidResistanceUnit unit) const
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
                return (value_) / 1e6;

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

        double value_;
    };
}
