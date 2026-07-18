#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class PressureUnit : std::uint16_t
    {
        Pascals,
        Micropascals,
        Millipascals,
        Decapascals,
        Hectopascals,
        Kilopascals,
        Megapascals,
        Gigapascals,
        Atmospheres,
        Bars,
        Microbars,
        Millibars,
        Centibars,
        Decibars,
        Kilobars,
        Megabars,
        KilogramsForcePerSquareMeter,
        KilogramsForcePerSquareCentimeter,
        KilogramsForcePerSquareMillimeter,
        NewtonsPerSquareMeter,
        KilonewtonsPerSquareMeter,
        MeganewtonsPerSquareMeter,
        NewtonsPerSquareCentimeter,
        KilonewtonsPerSquareCentimeter,
        NewtonsPerSquareMillimeter,
        KilonewtonsPerSquareMillimeter,
        TechnicalAtmospheres,
        Torrs,
        Millitorrs,
        PoundsForcePerSquareInch,
        KilopoundsForcePerSquareInch,
        PoundsForcePerSquareMil,
        KilopoundsForcePerSquareMil,
        PoundsForcePerSquareFoot,
        KilopoundsForcePerSquareFoot,
        TonnesForcePerSquareMillimeter,
        TonnesForcePerSquareMeter,
        MetersOfHead,
        TonnesForcePerSquareCentimeter,
        FeetOfHead,
        MillimetersOfMercury,
        InchesOfMercury,
        DynesPerSquareCentimeter,
        PoundsPerInchSecondSquared,
        MetersOfWaterColumn,
        MillimetersOfWaterColumn,
        CentimetersOfWaterColumn,
        InchesOfWaterColumn,
        MilligramsForcePerSquareMeter,
        MilligramsForcePerSquareFoot,
    };

    /// <summary>Pressure (symbol: P or p) is the ratio of force to the area over which that force is distributed. Pressure is force per unit area applied in a direction perpendicular to the surface of an object. Gauge pressure (also spelled gage pressure)[a] is the pressure relative to the local atmospheric or ambient pressure. Pressure is measured in any unit of force divided by any unit of area. The SI unit of pressure is the newton per square metre, which is called the pascal (Pa) after the seventeenth-century philosopher and scientist Blaise Pascal. A pressure of 1 Pa is small; it approximately equals the pressure exerted by a dollar bill resting flat on a table. Everyday pressures are often stated in kilopascals (1 kPa = 1000 Pa).</summary>
    class Pressure
    {
    public:
        constexpr explicit Pressure(
            double value,
            PressureUnit unit = PressureUnit::Pascals)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(PressureUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Pressure operator+(Pressure other) const noexcept
        {
            return Pressure(value_ + other.value_);
        }

        [[nodiscard]] constexpr Pressure operator-(Pressure other) const noexcept
        {
            return Pressure(value_ - other.value_);
        }

        [[nodiscard]] constexpr Pressure operator*(double scalar) const noexcept
        {
            return Pressure(value_ * scalar);
        }

        [[nodiscard]] constexpr Pressure operator/(double scalar) const noexcept
        {
            return Pressure(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Pressure other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Pressure other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double pascals() const
        {
            return convert_from_base(PressureUnit::Pascals);
        }

        [[nodiscard]] static constexpr Pressure from_pascals(double value)
        {
            return Pressure(value, PressureUnit::Pascals);
        }


        [[nodiscard]] constexpr double micropascals() const
        {
            return convert_from_base(PressureUnit::Micropascals);
        }

        [[nodiscard]] static constexpr Pressure from_micropascals(double value)
        {
            return Pressure(value, PressureUnit::Micropascals);
        }


        [[nodiscard]] constexpr double millipascals() const
        {
            return convert_from_base(PressureUnit::Millipascals);
        }

        [[nodiscard]] static constexpr Pressure from_millipascals(double value)
        {
            return Pressure(value, PressureUnit::Millipascals);
        }


        [[nodiscard]] constexpr double decapascals() const
        {
            return convert_from_base(PressureUnit::Decapascals);
        }

        [[nodiscard]] static constexpr Pressure from_decapascals(double value)
        {
            return Pressure(value, PressureUnit::Decapascals);
        }


        [[nodiscard]] constexpr double hectopascals() const
        {
            return convert_from_base(PressureUnit::Hectopascals);
        }

        [[nodiscard]] static constexpr Pressure from_hectopascals(double value)
        {
            return Pressure(value, PressureUnit::Hectopascals);
        }


        [[nodiscard]] constexpr double kilopascals() const
        {
            return convert_from_base(PressureUnit::Kilopascals);
        }

        [[nodiscard]] static constexpr Pressure from_kilopascals(double value)
        {
            return Pressure(value, PressureUnit::Kilopascals);
        }


        [[nodiscard]] constexpr double megapascals() const
        {
            return convert_from_base(PressureUnit::Megapascals);
        }

        [[nodiscard]] static constexpr Pressure from_megapascals(double value)
        {
            return Pressure(value, PressureUnit::Megapascals);
        }


        [[nodiscard]] constexpr double gigapascals() const
        {
            return convert_from_base(PressureUnit::Gigapascals);
        }

        [[nodiscard]] static constexpr Pressure from_gigapascals(double value)
        {
            return Pressure(value, PressureUnit::Gigapascals);
        }


        [[nodiscard]] constexpr double atmospheres() const
        {
            return convert_from_base(PressureUnit::Atmospheres);
        }

        [[nodiscard]] static constexpr Pressure from_atmospheres(double value)
        {
            return Pressure(value, PressureUnit::Atmospheres);
        }


        [[nodiscard]] constexpr double bars() const
        {
            return convert_from_base(PressureUnit::Bars);
        }

        [[nodiscard]] static constexpr Pressure from_bars(double value)
        {
            return Pressure(value, PressureUnit::Bars);
        }


        [[nodiscard]] constexpr double microbars() const
        {
            return convert_from_base(PressureUnit::Microbars);
        }

        [[nodiscard]] static constexpr Pressure from_microbars(double value)
        {
            return Pressure(value, PressureUnit::Microbars);
        }


        [[nodiscard]] constexpr double millibars() const
        {
            return convert_from_base(PressureUnit::Millibars);
        }

        [[nodiscard]] static constexpr Pressure from_millibars(double value)
        {
            return Pressure(value, PressureUnit::Millibars);
        }


        [[nodiscard]] constexpr double centibars() const
        {
            return convert_from_base(PressureUnit::Centibars);
        }

        [[nodiscard]] static constexpr Pressure from_centibars(double value)
        {
            return Pressure(value, PressureUnit::Centibars);
        }


        [[nodiscard]] constexpr double decibars() const
        {
            return convert_from_base(PressureUnit::Decibars);
        }

        [[nodiscard]] static constexpr Pressure from_decibars(double value)
        {
            return Pressure(value, PressureUnit::Decibars);
        }


        [[nodiscard]] constexpr double kilobars() const
        {
            return convert_from_base(PressureUnit::Kilobars);
        }

        [[nodiscard]] static constexpr Pressure from_kilobars(double value)
        {
            return Pressure(value, PressureUnit::Kilobars);
        }


        [[nodiscard]] constexpr double megabars() const
        {
            return convert_from_base(PressureUnit::Megabars);
        }

        [[nodiscard]] static constexpr Pressure from_megabars(double value)
        {
            return Pressure(value, PressureUnit::Megabars);
        }


        [[nodiscard]] constexpr double kilograms_force_per_square_meter() const
        {
            return convert_from_base(PressureUnit::KilogramsForcePerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilograms_force_per_square_meter(double value)
        {
            return Pressure(value, PressureUnit::KilogramsForcePerSquareMeter);
        }


        [[nodiscard]] constexpr double kilograms_force_per_square_centimeter() const
        {
            return convert_from_base(PressureUnit::KilogramsForcePerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilograms_force_per_square_centimeter(double value)
        {
            return Pressure(value, PressureUnit::KilogramsForcePerSquareCentimeter);
        }


        [[nodiscard]] constexpr double kilograms_force_per_square_millimeter() const
        {
            return convert_from_base(PressureUnit::KilogramsForcePerSquareMillimeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilograms_force_per_square_millimeter(double value)
        {
            return Pressure(value, PressureUnit::KilogramsForcePerSquareMillimeter);
        }


        [[nodiscard]] constexpr double newtons_per_square_meter() const
        {
            return convert_from_base(PressureUnit::NewtonsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_newtons_per_square_meter(double value)
        {
            return Pressure(value, PressureUnit::NewtonsPerSquareMeter);
        }


        [[nodiscard]] constexpr double kilonewtons_per_square_meter() const
        {
            return convert_from_base(PressureUnit::KilonewtonsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilonewtons_per_square_meter(double value)
        {
            return Pressure(value, PressureUnit::KilonewtonsPerSquareMeter);
        }


        [[nodiscard]] constexpr double meganewtons_per_square_meter() const
        {
            return convert_from_base(PressureUnit::MeganewtonsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_meganewtons_per_square_meter(double value)
        {
            return Pressure(value, PressureUnit::MeganewtonsPerSquareMeter);
        }


        [[nodiscard]] constexpr double newtons_per_square_centimeter() const
        {
            return convert_from_base(PressureUnit::NewtonsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Pressure from_newtons_per_square_centimeter(double value)
        {
            return Pressure(value, PressureUnit::NewtonsPerSquareCentimeter);
        }


        [[nodiscard]] constexpr double kilonewtons_per_square_centimeter() const
        {
            return convert_from_base(PressureUnit::KilonewtonsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilonewtons_per_square_centimeter(double value)
        {
            return Pressure(value, PressureUnit::KilonewtonsPerSquareCentimeter);
        }


        [[nodiscard]] constexpr double newtons_per_square_millimeter() const
        {
            return convert_from_base(PressureUnit::NewtonsPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr Pressure from_newtons_per_square_millimeter(double value)
        {
            return Pressure(value, PressureUnit::NewtonsPerSquareMillimeter);
        }


        [[nodiscard]] constexpr double kilonewtons_per_square_millimeter() const
        {
            return convert_from_base(PressureUnit::KilonewtonsPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilonewtons_per_square_millimeter(double value)
        {
            return Pressure(value, PressureUnit::KilonewtonsPerSquareMillimeter);
        }


        [[nodiscard]] constexpr double technical_atmospheres() const
        {
            return convert_from_base(PressureUnit::TechnicalAtmospheres);
        }

        [[nodiscard]] static constexpr Pressure from_technical_atmospheres(double value)
        {
            return Pressure(value, PressureUnit::TechnicalAtmospheres);
        }


        [[nodiscard]] constexpr double torrs() const
        {
            return convert_from_base(PressureUnit::Torrs);
        }

        [[nodiscard]] static constexpr Pressure from_torrs(double value)
        {
            return Pressure(value, PressureUnit::Torrs);
        }


        [[nodiscard]] constexpr double millitorrs() const
        {
            return convert_from_base(PressureUnit::Millitorrs);
        }

        [[nodiscard]] static constexpr Pressure from_millitorrs(double value)
        {
            return Pressure(value, PressureUnit::Millitorrs);
        }


        [[nodiscard]] constexpr double pounds_force_per_square_inch() const
        {
            return convert_from_base(PressureUnit::PoundsForcePerSquareInch);
        }

        [[nodiscard]] static constexpr Pressure from_pounds_force_per_square_inch(double value)
        {
            return Pressure(value, PressureUnit::PoundsForcePerSquareInch);
        }


        [[nodiscard]] constexpr double kilopounds_force_per_square_inch() const
        {
            return convert_from_base(PressureUnit::KilopoundsForcePerSquareInch);
        }

        [[nodiscard]] static constexpr Pressure from_kilopounds_force_per_square_inch(double value)
        {
            return Pressure(value, PressureUnit::KilopoundsForcePerSquareInch);
        }


        [[nodiscard]] constexpr double pounds_force_per_square_mil() const
        {
            return convert_from_base(PressureUnit::PoundsForcePerSquareMil);
        }

        [[nodiscard]] static constexpr Pressure from_pounds_force_per_square_mil(double value)
        {
            return Pressure(value, PressureUnit::PoundsForcePerSquareMil);
        }


        [[nodiscard]] constexpr double kilopounds_force_per_square_mil() const
        {
            return convert_from_base(PressureUnit::KilopoundsForcePerSquareMil);
        }

        [[nodiscard]] static constexpr Pressure from_kilopounds_force_per_square_mil(double value)
        {
            return Pressure(value, PressureUnit::KilopoundsForcePerSquareMil);
        }


        [[nodiscard]] constexpr double pounds_force_per_square_foot() const
        {
            return convert_from_base(PressureUnit::PoundsForcePerSquareFoot);
        }

        [[nodiscard]] static constexpr Pressure from_pounds_force_per_square_foot(double value)
        {
            return Pressure(value, PressureUnit::PoundsForcePerSquareFoot);
        }


        [[nodiscard]] constexpr double kilopounds_force_per_square_foot() const
        {
            return convert_from_base(PressureUnit::KilopoundsForcePerSquareFoot);
        }

        [[nodiscard]] static constexpr Pressure from_kilopounds_force_per_square_foot(double value)
        {
            return Pressure(value, PressureUnit::KilopoundsForcePerSquareFoot);
        }


        [[nodiscard]] constexpr double tonnes_force_per_square_millimeter() const
        {
            return convert_from_base(PressureUnit::TonnesForcePerSquareMillimeter);
        }

        [[nodiscard]] static constexpr Pressure from_tonnes_force_per_square_millimeter(double value)
        {
            return Pressure(value, PressureUnit::TonnesForcePerSquareMillimeter);
        }


        [[nodiscard]] constexpr double tonnes_force_per_square_meter() const
        {
            return convert_from_base(PressureUnit::TonnesForcePerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_tonnes_force_per_square_meter(double value)
        {
            return Pressure(value, PressureUnit::TonnesForcePerSquareMeter);
        }


        [[nodiscard]] constexpr double meters_of_head() const
        {
            return convert_from_base(PressureUnit::MetersOfHead);
        }

        [[nodiscard]] static constexpr Pressure from_meters_of_head(double value)
        {
            return Pressure(value, PressureUnit::MetersOfHead);
        }


        [[nodiscard]] constexpr double tonnes_force_per_square_centimeter() const
        {
            return convert_from_base(PressureUnit::TonnesForcePerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Pressure from_tonnes_force_per_square_centimeter(double value)
        {
            return Pressure(value, PressureUnit::TonnesForcePerSquareCentimeter);
        }


        [[nodiscard]] constexpr double feet_of_head() const
        {
            return convert_from_base(PressureUnit::FeetOfHead);
        }

        [[nodiscard]] static constexpr Pressure from_feet_of_head(double value)
        {
            return Pressure(value, PressureUnit::FeetOfHead);
        }


        [[nodiscard]] constexpr double millimeters_of_mercury() const
        {
            return convert_from_base(PressureUnit::MillimetersOfMercury);
        }

        [[nodiscard]] static constexpr Pressure from_millimeters_of_mercury(double value)
        {
            return Pressure(value, PressureUnit::MillimetersOfMercury);
        }


        [[nodiscard]] constexpr double inches_of_mercury() const
        {
            return convert_from_base(PressureUnit::InchesOfMercury);
        }

        [[nodiscard]] static constexpr Pressure from_inches_of_mercury(double value)
        {
            return Pressure(value, PressureUnit::InchesOfMercury);
        }


        [[nodiscard]] constexpr double dynes_per_square_centimeter() const
        {
            return convert_from_base(PressureUnit::DynesPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Pressure from_dynes_per_square_centimeter(double value)
        {
            return Pressure(value, PressureUnit::DynesPerSquareCentimeter);
        }


        [[nodiscard]] constexpr double pounds_per_inch_second_squared() const
        {
            return convert_from_base(PressureUnit::PoundsPerInchSecondSquared);
        }

        [[nodiscard]] static constexpr Pressure from_pounds_per_inch_second_squared(double value)
        {
            return Pressure(value, PressureUnit::PoundsPerInchSecondSquared);
        }


        [[nodiscard]] constexpr double meters_of_water_column() const
        {
            return convert_from_base(PressureUnit::MetersOfWaterColumn);
        }

        [[nodiscard]] static constexpr Pressure from_meters_of_water_column(double value)
        {
            return Pressure(value, PressureUnit::MetersOfWaterColumn);
        }


        [[nodiscard]] constexpr double millimeters_of_water_column() const
        {
            return convert_from_base(PressureUnit::MillimetersOfWaterColumn);
        }

        [[nodiscard]] static constexpr Pressure from_millimeters_of_water_column(double value)
        {
            return Pressure(value, PressureUnit::MillimetersOfWaterColumn);
        }


        [[nodiscard]] constexpr double centimeters_of_water_column() const
        {
            return convert_from_base(PressureUnit::CentimetersOfWaterColumn);
        }

        [[nodiscard]] static constexpr Pressure from_centimeters_of_water_column(double value)
        {
            return Pressure(value, PressureUnit::CentimetersOfWaterColumn);
        }


        [[nodiscard]] constexpr double inches_of_water_column() const
        {
            return convert_from_base(PressureUnit::InchesOfWaterColumn);
        }

        [[nodiscard]] static constexpr Pressure from_inches_of_water_column(double value)
        {
            return Pressure(value, PressureUnit::InchesOfWaterColumn);
        }


        [[nodiscard]] constexpr double milligrams_force_per_square_meter() const
        {
            return convert_from_base(PressureUnit::MilligramsForcePerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_milligrams_force_per_square_meter(double value)
        {
            return Pressure(value, PressureUnit::MilligramsForcePerSquareMeter);
        }


        [[nodiscard]] constexpr double milligrams_force_per_square_foot() const
        {
            return convert_from_base(PressureUnit::MilligramsForcePerSquareFoot);
        }

        [[nodiscard]] static constexpr Pressure from_milligrams_force_per_square_foot(double value)
        {
            return Pressure(value, PressureUnit::MilligramsForcePerSquareFoot);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, PressureUnit unit)
        {
            switch (unit)
            {

            case PressureUnit::Pascals:
                return value;

            case PressureUnit::Micropascals:
                return (value * 1e-6);

            case PressureUnit::Millipascals:
                return (value * 1e-3);

            case PressureUnit::Decapascals:
                return (value * 1e1);

            case PressureUnit::Hectopascals:
                return (value * 1e2);

            case PressureUnit::Kilopascals:
                return (value * 1e3);

            case PressureUnit::Megapascals:
                return (value * 1e6);

            case PressureUnit::Gigapascals:
                return (value * 1e9);

            case PressureUnit::Atmospheres:
                return value * 1.01325 * 1e5;

            case PressureUnit::Bars:
                return value * 1e5;

            case PressureUnit::Microbars:
                return (value * 1e-6) * 1e5;

            case PressureUnit::Millibars:
                return (value * 1e-3) * 1e5;

            case PressureUnit::Centibars:
                return (value * 1e-2) * 1e5;

            case PressureUnit::Decibars:
                return (value * 1e-1) * 1e5;

            case PressureUnit::Kilobars:
                return (value * 1e3) * 1e5;

            case PressureUnit::Megabars:
                return (value * 1e6) * 1e5;

            case PressureUnit::KilogramsForcePerSquareMeter:
                return value * 9.80665;

            case PressureUnit::KilogramsForcePerSquareCentimeter:
                return value * 9.80665e4;

            case PressureUnit::KilogramsForcePerSquareMillimeter:
                return value * 9.80665e6;

            case PressureUnit::NewtonsPerSquareMeter:
                return value;

            case PressureUnit::KilonewtonsPerSquareMeter:
                return (value * 1e3);

            case PressureUnit::MeganewtonsPerSquareMeter:
                return (value * 1e6);

            case PressureUnit::NewtonsPerSquareCentimeter:
                return value * 1e4;

            case PressureUnit::KilonewtonsPerSquareCentimeter:
                return (value * 1e3) * 1e4;

            case PressureUnit::NewtonsPerSquareMillimeter:
                return value * 1e6;

            case PressureUnit::KilonewtonsPerSquareMillimeter:
                return (value * 1e3) * 1e6;

            case PressureUnit::TechnicalAtmospheres:
                return value * 9.80665e4;

            case PressureUnit::Torrs:
                return value * 101325 / 760;

            case PressureUnit::Millitorrs:
                return (value * 1e-3) * 101325 / 760;

            case PressureUnit::PoundsForcePerSquareInch:
                return value * 4.4482216152605 / 0.00064516;

            case PressureUnit::KilopoundsForcePerSquareInch:
                return (value * 1e3) * 4.4482216152605 / 0.00064516;

            case PressureUnit::PoundsForcePerSquareMil:
                return value * 4.4482216152605 / (2.54e-5 * 2.54e-5);

            case PressureUnit::KilopoundsForcePerSquareMil:
                return (value * 1e3) * 4.4482216152605 / (2.54e-5 * 2.54e-5);

            case PressureUnit::PoundsForcePerSquareFoot:
                return value * 4.4482216152605 / 9.290304e-2;

            case PressureUnit::KilopoundsForcePerSquareFoot:
                return (value * 1e3) * 4.4482216152605 / 9.290304e-2;

            case PressureUnit::TonnesForcePerSquareMillimeter:
                return value * 9.80665e9;

            case PressureUnit::TonnesForcePerSquareMeter:
                return value * 9.80665e3;

            case PressureUnit::MetersOfHead:
                return value * 9804.139432;

            case PressureUnit::TonnesForcePerSquareCentimeter:
                return value * 9.80665e7;

            case PressureUnit::FeetOfHead:
                return value * 9804.139432 * 0.3048;

            case PressureUnit::MillimetersOfMercury:
                return value * 133.322387415;

            case PressureUnit::InchesOfMercury:
                return value * 2.54e1 * 133.322387415;

            case PressureUnit::DynesPerSquareCentimeter:
                return value * 1.0e-1;

            case PressureUnit::PoundsPerInchSecondSquared:
                return value * (4.4482216152605 / 0.00064516) / 386.0886;

            case PressureUnit::MetersOfWaterColumn:
                return value * 9.80665e3;

            case PressureUnit::MillimetersOfWaterColumn:
                return (value * 1e-3) * 9.80665e3;

            case PressureUnit::CentimetersOfWaterColumn:
                return (value * 1e-2) * 9.80665e3;

            case PressureUnit::InchesOfWaterColumn:
                return value * 2.54e-2 * 9.80665e3;

            case PressureUnit::MilligramsForcePerSquareMeter:
                return value * 9.80665e-6;

            case PressureUnit::MilligramsForcePerSquareFoot:
                return value * 9.80665e-6 / 9.290304e-2;

            }

            throw std::invalid_argument("Unknown Pressure unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(PressureUnit unit) const
        {
            switch (unit)
            {

            case PressureUnit::Pascals:
                return value_;

            case PressureUnit::Micropascals:
                return (value_) / 1e-6;

            case PressureUnit::Millipascals:
                return (value_) / 1e-3;

            case PressureUnit::Decapascals:
                return (value_) / 1e1;

            case PressureUnit::Hectopascals:
                return (value_) / 1e2;

            case PressureUnit::Kilopascals:
                return (value_) / 1e3;

            case PressureUnit::Megapascals:
                return (value_) / 1e6;

            case PressureUnit::Gigapascals:
                return (value_) / 1e9;

            case PressureUnit::Atmospheres:
                return value_ / (1.01325 * 1e5);

            case PressureUnit::Bars:
                return value_ / 1e5;

            case PressureUnit::Microbars:
                return (value_ / 1e5) / 1e-6;

            case PressureUnit::Millibars:
                return (value_ / 1e5) / 1e-3;

            case PressureUnit::Centibars:
                return (value_ / 1e5) / 1e-2;

            case PressureUnit::Decibars:
                return (value_ / 1e5) / 1e-1;

            case PressureUnit::Kilobars:
                return (value_ / 1e5) / 1e3;

            case PressureUnit::Megabars:
                return (value_ / 1e5) / 1e6;

            case PressureUnit::KilogramsForcePerSquareMeter:
                return value_ / 9.80665;

            case PressureUnit::KilogramsForcePerSquareCentimeter:
                return value_ / 9.80665e4;

            case PressureUnit::KilogramsForcePerSquareMillimeter:
                return value_ / 9.80665e6;

            case PressureUnit::NewtonsPerSquareMeter:
                return value_;

            case PressureUnit::KilonewtonsPerSquareMeter:
                return (value_) / 1e3;

            case PressureUnit::MeganewtonsPerSquareMeter:
                return (value_) / 1e6;

            case PressureUnit::NewtonsPerSquareCentimeter:
                return value_ / 1e4;

            case PressureUnit::KilonewtonsPerSquareCentimeter:
                return (value_ / 1e4) / 1e3;

            case PressureUnit::NewtonsPerSquareMillimeter:
                return value_ / 1e6;

            case PressureUnit::KilonewtonsPerSquareMillimeter:
                return (value_ / 1e6) / 1e3;

            case PressureUnit::TechnicalAtmospheres:
                return value_ / 9.80665e4;

            case PressureUnit::Torrs:
                return value_ * 760 / 101325;

            case PressureUnit::Millitorrs:
                return (value_ * 760 / 101325) / 1e-3;

            case PressureUnit::PoundsForcePerSquareInch:
                return value_ * 0.00064516 / 4.4482216152605;

            case PressureUnit::KilopoundsForcePerSquareInch:
                return (value_ * 0.00064516 / 4.4482216152605) / 1e3;

            case PressureUnit::PoundsForcePerSquareMil:
                return value_ * (2.54e-5 * 2.54e-5) / 4.4482216152605;

            case PressureUnit::KilopoundsForcePerSquareMil:
                return (value_ * (2.54e-5 * 2.54e-5) / 4.4482216152605) / 1e3;

            case PressureUnit::PoundsForcePerSquareFoot:
                return value_ * 9.290304e-2 / 4.4482216152605;

            case PressureUnit::KilopoundsForcePerSquareFoot:
                return (value_ * 9.290304e-2 / 4.4482216152605) / 1e3;

            case PressureUnit::TonnesForcePerSquareMillimeter:
                return value_ / 9.80665e9;

            case PressureUnit::TonnesForcePerSquareMeter:
                return value_ / 9.80665e3;

            case PressureUnit::MetersOfHead:
                return value_ / 9804.139432;

            case PressureUnit::TonnesForcePerSquareCentimeter:
                return value_ / 9.80665e7;

            case PressureUnit::FeetOfHead:
                return value_ / (9804.139432 * 0.3048);

            case PressureUnit::MillimetersOfMercury:
                return value_ / 133.322387415;

            case PressureUnit::InchesOfMercury:
                return value_ / (2.54e1 * 133.322387415);

            case PressureUnit::DynesPerSquareCentimeter:
                return value_ / 1.0e-1;

            case PressureUnit::PoundsPerInchSecondSquared:
                return value_ * 386.0886 / (4.4482216152605 / 0.00064516);

            case PressureUnit::MetersOfWaterColumn:
                return value_ / 9.80665e3;

            case PressureUnit::MillimetersOfWaterColumn:
                return (value_ / 9.80665e3) / 1e-3;

            case PressureUnit::CentimetersOfWaterColumn:
                return (value_ / 9.80665e3) / 1e-2;

            case PressureUnit::InchesOfWaterColumn:
                return value_ / (2.54e-2 * 9.80665e3);

            case PressureUnit::MilligramsForcePerSquareMeter:
                return value_ / 9.80665e-6;

            case PressureUnit::MilligramsForcePerSquareFoot:
                return value_ / 9.80665e-6 * 9.290304e-2;

            }

            throw std::invalid_argument("Unknown Pressure unit.");
        }

        double value_;
    };
}
