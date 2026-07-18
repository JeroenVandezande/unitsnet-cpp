#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class LengthUnit : std::uint16_t
    {
        Meters,
        Femtometers,
        Picometers,
        Nanometers,
        Micrometers,
        Millimeters,
        Centimeters,
        Decimeters,
        Decameters,
        Hectometers,
        Kilometers,
        Megameters,
        Gigameters,
        Miles,
        Yards,
        Kiloyards,
        Feet,
        Kilofeet,
        UsSurveyFeet,
        Inches,
        Mils,
        NauticalMiles,
        Fathoms,
        Shackles,
        Microinches,
        PrinterPoints,
        DtpPoints,
        PrinterPicas,
        DtpPicas,
        Twips,
        Hands,
        AstronomicalUnits,
        Parsecs,
        Kiloparsecs,
        Megaparsecs,
        LightYears,
        KilolightYears,
        MegalightYears,
        SolarRadiuses,
        Chains,
        Angstroms,
        DataMiles,
    };

    /// <summary>Many different units of length have been used around the world. The main units in modern use are U.S. customary units in the United States and the Metric system elsewhere. British Imperial units are still used for some purposes in the United Kingdom and some other countries. The metric system is sub-divided into SI and non-SI units.</summary>
    class Length
    {
    public:
        constexpr explicit Length(
            double value,
            LengthUnit unit = LengthUnit::Meters)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(LengthUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Length operator+(Length other) const noexcept
        {
            return Length(value_ + other.value_);
        }

        [[nodiscard]] constexpr Length operator-(Length other) const noexcept
        {
            return Length(value_ - other.value_);
        }

        [[nodiscard]] constexpr Length operator*(double scalar) const noexcept
        {
            return Length(value_ * scalar);
        }

        [[nodiscard]] constexpr Length operator/(double scalar) const noexcept
        {
            return Length(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Length other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Length other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double meters() const
        {
            return convert_from_base(LengthUnit::Meters);
        }

        [[nodiscard]] static constexpr Length from_meters(double value)
        {
            return Length(value, LengthUnit::Meters);
        }


        [[nodiscard]] constexpr double femtometers() const
        {
            return convert_from_base(LengthUnit::Femtometers);
        }

        [[nodiscard]] static constexpr Length from_femtometers(double value)
        {
            return Length(value, LengthUnit::Femtometers);
        }


        [[nodiscard]] constexpr double picometers() const
        {
            return convert_from_base(LengthUnit::Picometers);
        }

        [[nodiscard]] static constexpr Length from_picometers(double value)
        {
            return Length(value, LengthUnit::Picometers);
        }


        [[nodiscard]] constexpr double nanometers() const
        {
            return convert_from_base(LengthUnit::Nanometers);
        }

        [[nodiscard]] static constexpr Length from_nanometers(double value)
        {
            return Length(value, LengthUnit::Nanometers);
        }


        [[nodiscard]] constexpr double micrometers() const
        {
            return convert_from_base(LengthUnit::Micrometers);
        }

        [[nodiscard]] static constexpr Length from_micrometers(double value)
        {
            return Length(value, LengthUnit::Micrometers);
        }


        [[nodiscard]] constexpr double millimeters() const
        {
            return convert_from_base(LengthUnit::Millimeters);
        }

        [[nodiscard]] static constexpr Length from_millimeters(double value)
        {
            return Length(value, LengthUnit::Millimeters);
        }


        [[nodiscard]] constexpr double centimeters() const
        {
            return convert_from_base(LengthUnit::Centimeters);
        }

        [[nodiscard]] static constexpr Length from_centimeters(double value)
        {
            return Length(value, LengthUnit::Centimeters);
        }


        [[nodiscard]] constexpr double decimeters() const
        {
            return convert_from_base(LengthUnit::Decimeters);
        }

        [[nodiscard]] static constexpr Length from_decimeters(double value)
        {
            return Length(value, LengthUnit::Decimeters);
        }


        [[nodiscard]] constexpr double decameters() const
        {
            return convert_from_base(LengthUnit::Decameters);
        }

        [[nodiscard]] static constexpr Length from_decameters(double value)
        {
            return Length(value, LengthUnit::Decameters);
        }


        [[nodiscard]] constexpr double hectometers() const
        {
            return convert_from_base(LengthUnit::Hectometers);
        }

        [[nodiscard]] static constexpr Length from_hectometers(double value)
        {
            return Length(value, LengthUnit::Hectometers);
        }


        [[nodiscard]] constexpr double kilometers() const
        {
            return convert_from_base(LengthUnit::Kilometers);
        }

        [[nodiscard]] static constexpr Length from_kilometers(double value)
        {
            return Length(value, LengthUnit::Kilometers);
        }


        [[nodiscard]] constexpr double megameters() const
        {
            return convert_from_base(LengthUnit::Megameters);
        }

        [[nodiscard]] static constexpr Length from_megameters(double value)
        {
            return Length(value, LengthUnit::Megameters);
        }


        [[nodiscard]] constexpr double gigameters() const
        {
            return convert_from_base(LengthUnit::Gigameters);
        }

        [[nodiscard]] static constexpr Length from_gigameters(double value)
        {
            return Length(value, LengthUnit::Gigameters);
        }


        [[nodiscard]] constexpr double miles() const
        {
            return convert_from_base(LengthUnit::Miles);
        }

        [[nodiscard]] static constexpr Length from_miles(double value)
        {
            return Length(value, LengthUnit::Miles);
        }


        [[nodiscard]] constexpr double yards() const
        {
            return convert_from_base(LengthUnit::Yards);
        }

        [[nodiscard]] static constexpr Length from_yards(double value)
        {
            return Length(value, LengthUnit::Yards);
        }


        [[nodiscard]] constexpr double kiloyards() const
        {
            return convert_from_base(LengthUnit::Kiloyards);
        }

        [[nodiscard]] static constexpr Length from_kiloyards(double value)
        {
            return Length(value, LengthUnit::Kiloyards);
        }


        [[nodiscard]] constexpr double feet() const
        {
            return convert_from_base(LengthUnit::Feet);
        }

        [[nodiscard]] static constexpr Length from_feet(double value)
        {
            return Length(value, LengthUnit::Feet);
        }


        [[nodiscard]] constexpr double kilofeet() const
        {
            return convert_from_base(LengthUnit::Kilofeet);
        }

        [[nodiscard]] static constexpr Length from_kilofeet(double value)
        {
            return Length(value, LengthUnit::Kilofeet);
        }


        [[nodiscard]] constexpr double us_survey_feet() const
        {
            return convert_from_base(LengthUnit::UsSurveyFeet);
        }

        [[nodiscard]] static constexpr Length from_us_survey_feet(double value)
        {
            return Length(value, LengthUnit::UsSurveyFeet);
        }


        [[nodiscard]] constexpr double inches() const
        {
            return convert_from_base(LengthUnit::Inches);
        }

        [[nodiscard]] static constexpr Length from_inches(double value)
        {
            return Length(value, LengthUnit::Inches);
        }


        [[nodiscard]] constexpr double mils() const
        {
            return convert_from_base(LengthUnit::Mils);
        }

        [[nodiscard]] static constexpr Length from_mils(double value)
        {
            return Length(value, LengthUnit::Mils);
        }


        [[nodiscard]] constexpr double nautical_miles() const
        {
            return convert_from_base(LengthUnit::NauticalMiles);
        }

        [[nodiscard]] static constexpr Length from_nautical_miles(double value)
        {
            return Length(value, LengthUnit::NauticalMiles);
        }


        [[nodiscard]] constexpr double fathoms() const
        {
            return convert_from_base(LengthUnit::Fathoms);
        }

        [[nodiscard]] static constexpr Length from_fathoms(double value)
        {
            return Length(value, LengthUnit::Fathoms);
        }


        [[nodiscard]] constexpr double shackles() const
        {
            return convert_from_base(LengthUnit::Shackles);
        }

        [[nodiscard]] static constexpr Length from_shackles(double value)
        {
            return Length(value, LengthUnit::Shackles);
        }


        [[nodiscard]] constexpr double microinches() const
        {
            return convert_from_base(LengthUnit::Microinches);
        }

        [[nodiscard]] static constexpr Length from_microinches(double value)
        {
            return Length(value, LengthUnit::Microinches);
        }


        [[nodiscard]] constexpr double printer_points() const
        {
            return convert_from_base(LengthUnit::PrinterPoints);
        }

        [[nodiscard]] static constexpr Length from_printer_points(double value)
        {
            return Length(value, LengthUnit::PrinterPoints);
        }


        [[nodiscard]] constexpr double dtp_points() const
        {
            return convert_from_base(LengthUnit::DtpPoints);
        }

        [[nodiscard]] static constexpr Length from_dtp_points(double value)
        {
            return Length(value, LengthUnit::DtpPoints);
        }


        [[nodiscard]] constexpr double printer_picas() const
        {
            return convert_from_base(LengthUnit::PrinterPicas);
        }

        [[nodiscard]] static constexpr Length from_printer_picas(double value)
        {
            return Length(value, LengthUnit::PrinterPicas);
        }


        [[nodiscard]] constexpr double dtp_picas() const
        {
            return convert_from_base(LengthUnit::DtpPicas);
        }

        [[nodiscard]] static constexpr Length from_dtp_picas(double value)
        {
            return Length(value, LengthUnit::DtpPicas);
        }


        [[nodiscard]] constexpr double twips() const
        {
            return convert_from_base(LengthUnit::Twips);
        }

        [[nodiscard]] static constexpr Length from_twips(double value)
        {
            return Length(value, LengthUnit::Twips);
        }


        [[nodiscard]] constexpr double hands() const
        {
            return convert_from_base(LengthUnit::Hands);
        }

        [[nodiscard]] static constexpr Length from_hands(double value)
        {
            return Length(value, LengthUnit::Hands);
        }


        [[nodiscard]] constexpr double astronomical_units() const
        {
            return convert_from_base(LengthUnit::AstronomicalUnits);
        }

        [[nodiscard]] static constexpr Length from_astronomical_units(double value)
        {
            return Length(value, LengthUnit::AstronomicalUnits);
        }


        [[nodiscard]] constexpr double parsecs() const
        {
            return convert_from_base(LengthUnit::Parsecs);
        }

        [[nodiscard]] static constexpr Length from_parsecs(double value)
        {
            return Length(value, LengthUnit::Parsecs);
        }


        [[nodiscard]] constexpr double kiloparsecs() const
        {
            return convert_from_base(LengthUnit::Kiloparsecs);
        }

        [[nodiscard]] static constexpr Length from_kiloparsecs(double value)
        {
            return Length(value, LengthUnit::Kiloparsecs);
        }


        [[nodiscard]] constexpr double megaparsecs() const
        {
            return convert_from_base(LengthUnit::Megaparsecs);
        }

        [[nodiscard]] static constexpr Length from_megaparsecs(double value)
        {
            return Length(value, LengthUnit::Megaparsecs);
        }


        [[nodiscard]] constexpr double light_years() const
        {
            return convert_from_base(LengthUnit::LightYears);
        }

        [[nodiscard]] static constexpr Length from_light_years(double value)
        {
            return Length(value, LengthUnit::LightYears);
        }


        [[nodiscard]] constexpr double kilolight_years() const
        {
            return convert_from_base(LengthUnit::KilolightYears);
        }

        [[nodiscard]] static constexpr Length from_kilolight_years(double value)
        {
            return Length(value, LengthUnit::KilolightYears);
        }


        [[nodiscard]] constexpr double megalight_years() const
        {
            return convert_from_base(LengthUnit::MegalightYears);
        }

        [[nodiscard]] static constexpr Length from_megalight_years(double value)
        {
            return Length(value, LengthUnit::MegalightYears);
        }


        [[nodiscard]] constexpr double solar_radiuses() const
        {
            return convert_from_base(LengthUnit::SolarRadiuses);
        }

        [[nodiscard]] static constexpr Length from_solar_radiuses(double value)
        {
            return Length(value, LengthUnit::SolarRadiuses);
        }


        [[nodiscard]] constexpr double chains() const
        {
            return convert_from_base(LengthUnit::Chains);
        }

        [[nodiscard]] static constexpr Length from_chains(double value)
        {
            return Length(value, LengthUnit::Chains);
        }


        [[nodiscard]] constexpr double angstroms() const
        {
            return convert_from_base(LengthUnit::Angstroms);
        }

        [[nodiscard]] static constexpr Length from_angstroms(double value)
        {
            return Length(value, LengthUnit::Angstroms);
        }


        [[nodiscard]] constexpr double data_miles() const
        {
            return convert_from_base(LengthUnit::DataMiles);
        }

        [[nodiscard]] static constexpr Length from_data_miles(double value)
        {
            return Length(value, LengthUnit::DataMiles);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, LengthUnit unit)
        {
            switch (unit)
            {

            case LengthUnit::Meters:
                return value;

            case LengthUnit::Femtometers:
                return (value * 1e-15);

            case LengthUnit::Picometers:
                return (value * 1e-12);

            case LengthUnit::Nanometers:
                return (value * 1e-9);

            case LengthUnit::Micrometers:
                return (value * 1e-6);

            case LengthUnit::Millimeters:
                return (value * 1e-3);

            case LengthUnit::Centimeters:
                return (value * 1e-2);

            case LengthUnit::Decimeters:
                return (value * 1e-1);

            case LengthUnit::Decameters:
                return (value * 1e1);

            case LengthUnit::Hectometers:
                return (value * 1e2);

            case LengthUnit::Kilometers:
                return (value * 1e3);

            case LengthUnit::Megameters:
                return (value * 1e6);

            case LengthUnit::Gigameters:
                return (value * 1e9);

            case LengthUnit::Miles:
                return value * 1609.344;

            case LengthUnit::Yards:
                return value * 0.9144;

            case LengthUnit::Kiloyards:
                return (value * 1e3) * 0.9144;

            case LengthUnit::Feet:
                return value * 0.3048;

            case LengthUnit::Kilofeet:
                return (value * 1e3) * 0.3048;

            case LengthUnit::UsSurveyFeet:
                return value * 1200 / 3937;

            case LengthUnit::Inches:
                return value * 2.54e-2;

            case LengthUnit::Mils:
                return value * 2.54e-5;

            case LengthUnit::NauticalMiles:
                return value * 1852;

            case LengthUnit::Fathoms:
                return value * 1.8288;

            case LengthUnit::Shackles:
                return value * 27.432;

            case LengthUnit::Microinches:
                return value * 2.54e-8;

            case LengthUnit::PrinterPoints:
                return value * 2.54e-2 / 72.27 ;

            case LengthUnit::DtpPoints:
                return value * 2.54e-2 / 72;

            case LengthUnit::PrinterPicas:
                return value * 2.54e-2 * 400 / 2409;

            case LengthUnit::DtpPicas:
                return value * 2.54e-2 / 6;

            case LengthUnit::Twips:
                return value * 2.54e-2 / 1440;

            case LengthUnit::Hands:
                return value * 1.016e-1;

            case LengthUnit::AstronomicalUnits:
                return value * 1.4959787070e11;

            case LengthUnit::Parsecs:
                return value * 3.08567758128e16;

            case LengthUnit::Kiloparsecs:
                return (value * 1e3) * 3.08567758128e16;

            case LengthUnit::Megaparsecs:
                return (value * 1e6) * 3.08567758128e16;

            case LengthUnit::LightYears:
                return value * 9.46073047258e15;

            case LengthUnit::KilolightYears:
                return (value * 1e3) * 9.46073047258e15;

            case LengthUnit::MegalightYears:
                return (value * 1e6) * 9.46073047258e15;

            case LengthUnit::SolarRadiuses:
                return value * 6.95700e8;

            case LengthUnit::Chains:
                return value * 20.1168;

            case LengthUnit::Angstroms:
                return value * 1e-10;

            case LengthUnit::DataMiles:
                return value * 1828.8;

            }

            throw std::invalid_argument("Unknown Length unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(LengthUnit unit) const
        {
            switch (unit)
            {

            case LengthUnit::Meters:
                return value_;

            case LengthUnit::Femtometers:
                return (value_) / 1e-15;

            case LengthUnit::Picometers:
                return (value_) / 1e-12;

            case LengthUnit::Nanometers:
                return (value_) / 1e-9;

            case LengthUnit::Micrometers:
                return (value_) / 1e-6;

            case LengthUnit::Millimeters:
                return (value_) / 1e-3;

            case LengthUnit::Centimeters:
                return (value_) / 1e-2;

            case LengthUnit::Decimeters:
                return (value_) / 1e-1;

            case LengthUnit::Decameters:
                return (value_) / 1e1;

            case LengthUnit::Hectometers:
                return (value_) / 1e2;

            case LengthUnit::Kilometers:
                return (value_) / 1e3;

            case LengthUnit::Megameters:
                return (value_) / 1e6;

            case LengthUnit::Gigameters:
                return (value_) / 1e9;

            case LengthUnit::Miles:
                return value_ / 1609.344;

            case LengthUnit::Yards:
                return value_ / 0.9144;

            case LengthUnit::Kiloyards:
                return (value_ / 0.9144) / 1e3;

            case LengthUnit::Feet:
                return value_ / 0.3048;

            case LengthUnit::Kilofeet:
                return (value_ / 0.3048) / 1e3;

            case LengthUnit::UsSurveyFeet:
                return value_ * 3937 / 1200;

            case LengthUnit::Inches:
                return value_ / 2.54e-2;

            case LengthUnit::Mils:
                return value_ / 2.54e-5;

            case LengthUnit::NauticalMiles:
                return value_ / 1852;

            case LengthUnit::Fathoms:
                return value_ / 1.8288;

            case LengthUnit::Shackles:
                return value_ / 27.432;

            case LengthUnit::Microinches:
                return value_ / 2.54e-8;

            case LengthUnit::PrinterPoints:
                return value_ * 72.27 / 2.54e-2;

            case LengthUnit::DtpPoints:
                return value_ * 72 / 2.54e-2;

            case LengthUnit::PrinterPicas:
                return value_ / (2.54e-2 * 400 / 2409);

            case LengthUnit::DtpPicas:
                return value_ * 6 / 2.54e-2;

            case LengthUnit::Twips:
                return value_ * 1440 / 2.54e-2;

            case LengthUnit::Hands:
                return value_ / 1.016e-1;

            case LengthUnit::AstronomicalUnits:
                return value_ / 1.4959787070e11;

            case LengthUnit::Parsecs:
                return value_ / 3.08567758128e16;

            case LengthUnit::Kiloparsecs:
                return (value_ / 3.08567758128e16) / 1e3;

            case LengthUnit::Megaparsecs:
                return (value_ / 3.08567758128e16) / 1e6;

            case LengthUnit::LightYears:
                return value_ / 9.46073047258e15;

            case LengthUnit::KilolightYears:
                return (value_ / 9.46073047258e15) / 1e3;

            case LengthUnit::MegalightYears:
                return (value_ / 9.46073047258e15) / 1e6;

            case LengthUnit::SolarRadiuses:
                return value_ / 6.95700e8;

            case LengthUnit::Chains:
                return value_ / 20.1168;

            case LengthUnit::Angstroms:
                return value_ / 1e-10;

            case LengthUnit::DataMiles:
                return value_ / 1828.8;

            }

            throw std::invalid_argument("Unknown Length unit.");
        }

        double value_;
    };
}
