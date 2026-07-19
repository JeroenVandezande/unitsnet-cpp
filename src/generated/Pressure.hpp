#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class PressureUnit : std::uint8_t
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
            const un_scalar_t value,
            const PressureUnit unit = PressureUnit::Pascals)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const PressureUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Pressure operator+(const Pressure other) const noexcept
        {
            return Pressure(value_ + other.value_);
        }

        [[nodiscard]] constexpr Pressure operator-(const Pressure other) const noexcept
        {
            return Pressure(value_ - other.value_);
        }

        [[nodiscard]] constexpr Pressure operator*(const un_scalar_t scalar) const noexcept
        {
            return Pressure(value_ * scalar);
        }

        [[nodiscard]] constexpr Pressure operator/(const un_scalar_t scalar) const noexcept
        {
            return Pressure(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Pressure other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Pressure other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t pascals() const
        {
            return convert_from_base(PressureUnit::Pascals);
        }

        [[nodiscard]] static constexpr Pressure from_pascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Pascals);
        }


        [[nodiscard]] constexpr un_scalar_t micropascals() const
        {
            return convert_from_base(PressureUnit::Micropascals);
        }

        [[nodiscard]] static constexpr Pressure from_micropascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Micropascals);
        }


        [[nodiscard]] constexpr un_scalar_t millipascals() const
        {
            return convert_from_base(PressureUnit::Millipascals);
        }

        [[nodiscard]] static constexpr Pressure from_millipascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Millipascals);
        }


        [[nodiscard]] constexpr un_scalar_t decapascals() const
        {
            return convert_from_base(PressureUnit::Decapascals);
        }

        [[nodiscard]] static constexpr Pressure from_decapascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Decapascals);
        }


        [[nodiscard]] constexpr un_scalar_t hectopascals() const
        {
            return convert_from_base(PressureUnit::Hectopascals);
        }

        [[nodiscard]] static constexpr Pressure from_hectopascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Hectopascals);
        }


        [[nodiscard]] constexpr un_scalar_t kilopascals() const
        {
            return convert_from_base(PressureUnit::Kilopascals);
        }

        [[nodiscard]] static constexpr Pressure from_kilopascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Kilopascals);
        }


        [[nodiscard]] constexpr un_scalar_t megapascals() const
        {
            return convert_from_base(PressureUnit::Megapascals);
        }

        [[nodiscard]] static constexpr Pressure from_megapascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Megapascals);
        }


        [[nodiscard]] constexpr un_scalar_t gigapascals() const
        {
            return convert_from_base(PressureUnit::Gigapascals);
        }

        [[nodiscard]] static constexpr Pressure from_gigapascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Gigapascals);
        }


        [[nodiscard]] constexpr un_scalar_t atmospheres() const
        {
            return convert_from_base(PressureUnit::Atmospheres);
        }

        [[nodiscard]] static constexpr Pressure from_atmospheres(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Atmospheres);
        }


        [[nodiscard]] constexpr un_scalar_t bars() const
        {
            return convert_from_base(PressureUnit::Bars);
        }

        [[nodiscard]] static constexpr Pressure from_bars(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Bars);
        }


        [[nodiscard]] constexpr un_scalar_t microbars() const
        {
            return convert_from_base(PressureUnit::Microbars);
        }

        [[nodiscard]] static constexpr Pressure from_microbars(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Microbars);
        }


        [[nodiscard]] constexpr un_scalar_t millibars() const
        {
            return convert_from_base(PressureUnit::Millibars);
        }

        [[nodiscard]] static constexpr Pressure from_millibars(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Millibars);
        }


        [[nodiscard]] constexpr un_scalar_t centibars() const
        {
            return convert_from_base(PressureUnit::Centibars);
        }

        [[nodiscard]] static constexpr Pressure from_centibars(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Centibars);
        }


        [[nodiscard]] constexpr un_scalar_t decibars() const
        {
            return convert_from_base(PressureUnit::Decibars);
        }

        [[nodiscard]] static constexpr Pressure from_decibars(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Decibars);
        }


        [[nodiscard]] constexpr un_scalar_t kilobars() const
        {
            return convert_from_base(PressureUnit::Kilobars);
        }

        [[nodiscard]] static constexpr Pressure from_kilobars(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Kilobars);
        }


        [[nodiscard]] constexpr un_scalar_t megabars() const
        {
            return convert_from_base(PressureUnit::Megabars);
        }

        [[nodiscard]] static constexpr Pressure from_megabars(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Megabars);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_square_meter() const
        {
            return convert_from_base(PressureUnit::KilogramsForcePerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilograms_force_per_square_meter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilogramsForcePerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_square_centimeter() const
        {
            return convert_from_base(PressureUnit::KilogramsForcePerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilograms_force_per_square_centimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilogramsForcePerSquareCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_square_millimeter() const
        {
            return convert_from_base(PressureUnit::KilogramsForcePerSquareMillimeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilograms_force_per_square_millimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilogramsForcePerSquareMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t newtons_per_square_meter() const
        {
            return convert_from_base(PressureUnit::NewtonsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_newtons_per_square_meter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::NewtonsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_square_meter() const
        {
            return convert_from_base(PressureUnit::KilonewtonsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilonewtons_per_square_meter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilonewtonsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t meganewtons_per_square_meter() const
        {
            return convert_from_base(PressureUnit::MeganewtonsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_meganewtons_per_square_meter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::MeganewtonsPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t newtons_per_square_centimeter() const
        {
            return convert_from_base(PressureUnit::NewtonsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Pressure from_newtons_per_square_centimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::NewtonsPerSquareCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_square_centimeter() const
        {
            return convert_from_base(PressureUnit::KilonewtonsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilonewtons_per_square_centimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilonewtonsPerSquareCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t newtons_per_square_millimeter() const
        {
            return convert_from_base(PressureUnit::NewtonsPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr Pressure from_newtons_per_square_millimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::NewtonsPerSquareMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_square_millimeter() const
        {
            return convert_from_base(PressureUnit::KilonewtonsPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilonewtons_per_square_millimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilonewtonsPerSquareMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t technical_atmospheres() const
        {
            return convert_from_base(PressureUnit::TechnicalAtmospheres);
        }

        [[nodiscard]] static constexpr Pressure from_technical_atmospheres(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::TechnicalAtmospheres);
        }


        [[nodiscard]] constexpr un_scalar_t torrs() const
        {
            return convert_from_base(PressureUnit::Torrs);
        }

        [[nodiscard]] static constexpr Pressure from_torrs(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Torrs);
        }


        [[nodiscard]] constexpr un_scalar_t millitorrs() const
        {
            return convert_from_base(PressureUnit::Millitorrs);
        }

        [[nodiscard]] static constexpr Pressure from_millitorrs(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Millitorrs);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_force_per_square_inch() const
        {
            return convert_from_base(PressureUnit::PoundsForcePerSquareInch);
        }

        [[nodiscard]] static constexpr Pressure from_pounds_force_per_square_inch(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::PoundsForcePerSquareInch);
        }


        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_square_inch() const
        {
            return convert_from_base(PressureUnit::KilopoundsForcePerSquareInch);
        }

        [[nodiscard]] static constexpr Pressure from_kilopounds_force_per_square_inch(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilopoundsForcePerSquareInch);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_force_per_square_mil() const
        {
            return convert_from_base(PressureUnit::PoundsForcePerSquareMil);
        }

        [[nodiscard]] static constexpr Pressure from_pounds_force_per_square_mil(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::PoundsForcePerSquareMil);
        }


        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_square_mil() const
        {
            return convert_from_base(PressureUnit::KilopoundsForcePerSquareMil);
        }

        [[nodiscard]] static constexpr Pressure from_kilopounds_force_per_square_mil(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilopoundsForcePerSquareMil);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_force_per_square_foot() const
        {
            return convert_from_base(PressureUnit::PoundsForcePerSquareFoot);
        }

        [[nodiscard]] static constexpr Pressure from_pounds_force_per_square_foot(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::PoundsForcePerSquareFoot);
        }


        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_square_foot() const
        {
            return convert_from_base(PressureUnit::KilopoundsForcePerSquareFoot);
        }

        [[nodiscard]] static constexpr Pressure from_kilopounds_force_per_square_foot(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilopoundsForcePerSquareFoot);
        }


        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_square_millimeter() const
        {
            return convert_from_base(PressureUnit::TonnesForcePerSquareMillimeter);
        }

        [[nodiscard]] static constexpr Pressure from_tonnes_force_per_square_millimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::TonnesForcePerSquareMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_square_meter() const
        {
            return convert_from_base(PressureUnit::TonnesForcePerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_tonnes_force_per_square_meter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::TonnesForcePerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t meters_of_head() const
        {
            return convert_from_base(PressureUnit::MetersOfHead);
        }

        [[nodiscard]] static constexpr Pressure from_meters_of_head(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::MetersOfHead);
        }


        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_square_centimeter() const
        {
            return convert_from_base(PressureUnit::TonnesForcePerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Pressure from_tonnes_force_per_square_centimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::TonnesForcePerSquareCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t feet_of_head() const
        {
            return convert_from_base(PressureUnit::FeetOfHead);
        }

        [[nodiscard]] static constexpr Pressure from_feet_of_head(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::FeetOfHead);
        }


        [[nodiscard]] constexpr un_scalar_t millimeters_of_mercury() const
        {
            return convert_from_base(PressureUnit::MillimetersOfMercury);
        }

        [[nodiscard]] static constexpr Pressure from_millimeters_of_mercury(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::MillimetersOfMercury);
        }


        [[nodiscard]] constexpr un_scalar_t inches_of_mercury() const
        {
            return convert_from_base(PressureUnit::InchesOfMercury);
        }

        [[nodiscard]] static constexpr Pressure from_inches_of_mercury(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::InchesOfMercury);
        }


        [[nodiscard]] constexpr un_scalar_t dynes_per_square_centimeter() const
        {
            return convert_from_base(PressureUnit::DynesPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Pressure from_dynes_per_square_centimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::DynesPerSquareCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_inch_second_squared() const
        {
            return convert_from_base(PressureUnit::PoundsPerInchSecondSquared);
        }

        [[nodiscard]] static constexpr Pressure from_pounds_per_inch_second_squared(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::PoundsPerInchSecondSquared);
        }


        [[nodiscard]] constexpr un_scalar_t meters_of_water_column() const
        {
            return convert_from_base(PressureUnit::MetersOfWaterColumn);
        }

        [[nodiscard]] static constexpr Pressure from_meters_of_water_column(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::MetersOfWaterColumn);
        }


        [[nodiscard]] constexpr un_scalar_t millimeters_of_water_column() const
        {
            return convert_from_base(PressureUnit::MillimetersOfWaterColumn);
        }

        [[nodiscard]] static constexpr Pressure from_millimeters_of_water_column(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::MillimetersOfWaterColumn);
        }


        [[nodiscard]] constexpr un_scalar_t centimeters_of_water_column() const
        {
            return convert_from_base(PressureUnit::CentimetersOfWaterColumn);
        }

        [[nodiscard]] static constexpr Pressure from_centimeters_of_water_column(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::CentimetersOfWaterColumn);
        }


        [[nodiscard]] constexpr un_scalar_t inches_of_water_column() const
        {
            return convert_from_base(PressureUnit::InchesOfWaterColumn);
        }

        [[nodiscard]] static constexpr Pressure from_inches_of_water_column(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::InchesOfWaterColumn);
        }


        [[nodiscard]] constexpr un_scalar_t milligrams_force_per_square_meter() const
        {
            return convert_from_base(PressureUnit::MilligramsForcePerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_milligrams_force_per_square_meter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::MilligramsForcePerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t milligrams_force_per_square_foot() const
        {
            return convert_from_base(PressureUnit::MilligramsForcePerSquareFoot);
        }

        [[nodiscard]] static constexpr Pressure from_milligrams_force_per_square_foot(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::MilligramsForcePerSquareFoot);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, PressureUnit unit)
        {
            switch (unit)
            {

            case PressureUnit::Pascals:
                return value;

            case PressureUnit::Micropascals:
                return (value * static_cast<un_scalar_t>(1e-6));

            case PressureUnit::Millipascals:
                return (value * static_cast<un_scalar_t>(1e-3));

            case PressureUnit::Decapascals:
                return (value * static_cast<un_scalar_t>(1e1));

            case PressureUnit::Hectopascals:
                return (value * static_cast<un_scalar_t>(1e2));

            case PressureUnit::Kilopascals:
                return (value * static_cast<un_scalar_t>(1e3));

            case PressureUnit::Megapascals:
                return (value * static_cast<un_scalar_t>(1e6));

            case PressureUnit::Gigapascals:
                return (value * static_cast<un_scalar_t>(1e9));

            case PressureUnit::Atmospheres:
                return value * static_cast<un_scalar_t>(1.01325) * static_cast<un_scalar_t>(1e5);

            case PressureUnit::Bars:
                return value * static_cast<un_scalar_t>(1e5);

            case PressureUnit::Microbars:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(1e5);

            case PressureUnit::Millibars:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e5);

            case PressureUnit::Centibars:
                return (value * static_cast<un_scalar_t>(1e-2)) * static_cast<un_scalar_t>(1e5);

            case PressureUnit::Decibars:
                return (value * static_cast<un_scalar_t>(1e-1)) * static_cast<un_scalar_t>(1e5);

            case PressureUnit::Kilobars:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e5);

            case PressureUnit::Megabars:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1e5);

            case PressureUnit::KilogramsForcePerSquareMeter:
                return value * static_cast<un_scalar_t>(9.80665);

            case PressureUnit::KilogramsForcePerSquareCentimeter:
                return value * static_cast<un_scalar_t>(9.80665e4);

            case PressureUnit::KilogramsForcePerSquareMillimeter:
                return value * static_cast<un_scalar_t>(9.80665e6);

            case PressureUnit::NewtonsPerSquareMeter:
                return value;

            case PressureUnit::KilonewtonsPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case PressureUnit::MeganewtonsPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case PressureUnit::NewtonsPerSquareCentimeter:
                return value * static_cast<un_scalar_t>(1e4);

            case PressureUnit::KilonewtonsPerSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e4);

            case PressureUnit::NewtonsPerSquareMillimeter:
                return value * static_cast<un_scalar_t>(1e6);

            case PressureUnit::KilonewtonsPerSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e6);

            case PressureUnit::TechnicalAtmospheres:
                return value * static_cast<un_scalar_t>(9.80665e4);

            case PressureUnit::Torrs:
                return value * static_cast<un_scalar_t>(101325) / static_cast<un_scalar_t>(760);

            case PressureUnit::Millitorrs:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(101325) / static_cast<un_scalar_t>(760);

            case PressureUnit::PoundsForcePerSquareInch:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516);

            case PressureUnit::KilopoundsForcePerSquareInch:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516);

            case PressureUnit::PoundsForcePerSquareMil:
                return value * static_cast<un_scalar_t>(4.4482216152605) / (static_cast<un_scalar_t>(2.54e-5) * static_cast<un_scalar_t>(2.54e-5));

            case PressureUnit::KilopoundsForcePerSquareMil:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605) / (static_cast<un_scalar_t>(2.54e-5) * static_cast<un_scalar_t>(2.54e-5));

            case PressureUnit::PoundsForcePerSquareFoot:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(9.290304e-2);

            case PressureUnit::KilopoundsForcePerSquareFoot:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(9.290304e-2);

            case PressureUnit::TonnesForcePerSquareMillimeter:
                return value * static_cast<un_scalar_t>(9.80665e9);

            case PressureUnit::TonnesForcePerSquareMeter:
                return value * static_cast<un_scalar_t>(9.80665e3);

            case PressureUnit::MetersOfHead:
                return value * static_cast<un_scalar_t>(9804.139432);

            case PressureUnit::TonnesForcePerSquareCentimeter:
                return value * static_cast<un_scalar_t>(9.80665e7);

            case PressureUnit::FeetOfHead:
                return value * static_cast<un_scalar_t>(9804.139432) * static_cast<un_scalar_t>(0.3048);

            case PressureUnit::MillimetersOfMercury:
                return value * static_cast<un_scalar_t>(133.322387415);

            case PressureUnit::InchesOfMercury:
                return value * static_cast<un_scalar_t>(2.54e1) * static_cast<un_scalar_t>(133.322387415);

            case PressureUnit::DynesPerSquareCentimeter:
                return value * static_cast<un_scalar_t>(1.0e-1);

            case PressureUnit::PoundsPerInchSecondSquared:
                return value * (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516)) / static_cast<un_scalar_t>(386.0886);

            case PressureUnit::MetersOfWaterColumn:
                return value * static_cast<un_scalar_t>(9.80665e3);

            case PressureUnit::MillimetersOfWaterColumn:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(9.80665e3);

            case PressureUnit::CentimetersOfWaterColumn:
                return (value * static_cast<un_scalar_t>(1e-2)) * static_cast<un_scalar_t>(9.80665e3);

            case PressureUnit::InchesOfWaterColumn:
                return value * static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(9.80665e3);

            case PressureUnit::MilligramsForcePerSquareMeter:
                return value * static_cast<un_scalar_t>(9.80665e-6);

            case PressureUnit::MilligramsForcePerSquareFoot:
                return value * static_cast<un_scalar_t>(9.80665e-6) / static_cast<un_scalar_t>(9.290304e-2);

            }

            throw std::invalid_argument("Unknown Pressure unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const PressureUnit unit) const
        {
            switch (unit)
            {

            case PressureUnit::Pascals:
                return value_;

            case PressureUnit::Micropascals:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case PressureUnit::Millipascals:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case PressureUnit::Decapascals:
                return (value_) / static_cast<un_scalar_t>(1e1);

            case PressureUnit::Hectopascals:
                return (value_) / static_cast<un_scalar_t>(1e2);

            case PressureUnit::Kilopascals:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::Megapascals:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case PressureUnit::Gigapascals:
                return (value_) / static_cast<un_scalar_t>(1e9);

            case PressureUnit::Atmospheres:
                return value_ / (static_cast<un_scalar_t>(1.01325) * static_cast<un_scalar_t>(1e5));

            case PressureUnit::Bars:
                return value_ / static_cast<un_scalar_t>(1e5);

            case PressureUnit::Microbars:
                return (value_ / static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e-6);

            case PressureUnit::Millibars:
                return (value_ / static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e-3);

            case PressureUnit::Centibars:
                return (value_ / static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e-2);

            case PressureUnit::Decibars:
                return (value_ / static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e-1);

            case PressureUnit::Kilobars:
                return (value_ / static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::Megabars:
                return (value_ / static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e6);

            case PressureUnit::KilogramsForcePerSquareMeter:
                return value_ / static_cast<un_scalar_t>(9.80665);

            case PressureUnit::KilogramsForcePerSquareCentimeter:
                return value_ / static_cast<un_scalar_t>(9.80665e4);

            case PressureUnit::KilogramsForcePerSquareMillimeter:
                return value_ / static_cast<un_scalar_t>(9.80665e6);

            case PressureUnit::NewtonsPerSquareMeter:
                return value_;

            case PressureUnit::KilonewtonsPerSquareMeter:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::MeganewtonsPerSquareMeter:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case PressureUnit::NewtonsPerSquareCentimeter:
                return value_ / static_cast<un_scalar_t>(1e4);

            case PressureUnit::KilonewtonsPerSquareCentimeter:
                return (value_ / static_cast<un_scalar_t>(1e4)) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::NewtonsPerSquareMillimeter:
                return value_ / static_cast<un_scalar_t>(1e6);

            case PressureUnit::KilonewtonsPerSquareMillimeter:
                return (value_ / static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::TechnicalAtmospheres:
                return value_ / static_cast<un_scalar_t>(9.80665e4);

            case PressureUnit::Torrs:
                return value_ * static_cast<un_scalar_t>(760) / static_cast<un_scalar_t>(101325);

            case PressureUnit::Millitorrs:
                return (value_ * static_cast<un_scalar_t>(760) / static_cast<un_scalar_t>(101325)) / static_cast<un_scalar_t>(1e-3);

            case PressureUnit::PoundsForcePerSquareInch:
                return value_ * static_cast<un_scalar_t>(0.00064516) / static_cast<un_scalar_t>(4.4482216152605);

            case PressureUnit::KilopoundsForcePerSquareInch:
                return (value_ * static_cast<un_scalar_t>(0.00064516) / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::PoundsForcePerSquareMil:
                return value_ * (static_cast<un_scalar_t>(2.54e-5) * static_cast<un_scalar_t>(2.54e-5)) / static_cast<un_scalar_t>(4.4482216152605);

            case PressureUnit::KilopoundsForcePerSquareMil:
                return (value_ * (static_cast<un_scalar_t>(2.54e-5) * static_cast<un_scalar_t>(2.54e-5)) / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::PoundsForcePerSquareFoot:
                return value_ * static_cast<un_scalar_t>(9.290304e-2) / static_cast<un_scalar_t>(4.4482216152605);

            case PressureUnit::KilopoundsForcePerSquareFoot:
                return (value_ * static_cast<un_scalar_t>(9.290304e-2) / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::TonnesForcePerSquareMillimeter:
                return value_ / static_cast<un_scalar_t>(9.80665e9);

            case PressureUnit::TonnesForcePerSquareMeter:
                return value_ / static_cast<un_scalar_t>(9.80665e3);

            case PressureUnit::MetersOfHead:
                return value_ / static_cast<un_scalar_t>(9804.139432);

            case PressureUnit::TonnesForcePerSquareCentimeter:
                return value_ / static_cast<un_scalar_t>(9.80665e7);

            case PressureUnit::FeetOfHead:
                return value_ / (static_cast<un_scalar_t>(9804.139432) * static_cast<un_scalar_t>(0.3048));

            case PressureUnit::MillimetersOfMercury:
                return value_ / static_cast<un_scalar_t>(133.322387415);

            case PressureUnit::InchesOfMercury:
                return value_ / (static_cast<un_scalar_t>(2.54e1) * static_cast<un_scalar_t>(133.322387415));

            case PressureUnit::DynesPerSquareCentimeter:
                return value_ / static_cast<un_scalar_t>(1.0e-1);

            case PressureUnit::PoundsPerInchSecondSquared:
                return value_ * static_cast<un_scalar_t>(386.0886) / (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516));

            case PressureUnit::MetersOfWaterColumn:
                return value_ / static_cast<un_scalar_t>(9.80665e3);

            case PressureUnit::MillimetersOfWaterColumn:
                return (value_ / static_cast<un_scalar_t>(9.80665e3)) / static_cast<un_scalar_t>(1e-3);

            case PressureUnit::CentimetersOfWaterColumn:
                return (value_ / static_cast<un_scalar_t>(9.80665e3)) / static_cast<un_scalar_t>(1e-2);

            case PressureUnit::InchesOfWaterColumn:
                return value_ / (static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(9.80665e3));

            case PressureUnit::MilligramsForcePerSquareMeter:
                return value_ / static_cast<un_scalar_t>(9.80665e-6);

            case PressureUnit::MilligramsForcePerSquareFoot:
                return value_ / static_cast<un_scalar_t>(9.80665e-6) * static_cast<un_scalar_t>(9.290304e-2);

            }

            throw std::invalid_argument("Unknown Pressure unit.");
        }

        un_scalar_t value_;
    };
}
