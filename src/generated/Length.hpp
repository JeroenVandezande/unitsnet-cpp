#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class LengthUnit : std::uint8_t
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
            const un_scalar_t value,
            const LengthUnit unit = LengthUnit::Meters)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit Length(const bool isValid)
        {
            _isInvalid = !isValid;
        }
        
        void SetValueAsInvalid()
        {
            _isInvalid = true;
        }
        
        void SetValueAsValid()
        {
            _isInvalid = false;
        }
        
        [[nodiscard]] bool GetValueIsValid() const
        {
            return _isInvalid;
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const LengthUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Length operator+(const Length other) const noexcept
        {
            return Length(value_ + other.value_);
        }

        [[nodiscard]] constexpr Length operator-(const Length other) const noexcept
        {
            return Length(value_ - other.value_);
        }

        [[nodiscard]] constexpr Length operator*(const un_scalar_t scalar) const noexcept
        {
            return Length(value_ * scalar);
        }

        [[nodiscard]] constexpr Length operator/(const un_scalar_t scalar) const noexcept
        {
            return Length(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Length other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Length other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const Length other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t meters() const
        {
            return convert_from_base(LengthUnit::Meters);
        }

        [[nodiscard]] static constexpr Length from_meters(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Meters);
        }


        [[nodiscard]] constexpr un_scalar_t femtometers() const
        {
            return convert_from_base(LengthUnit::Femtometers);
        }

        [[nodiscard]] static constexpr Length from_femtometers(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Femtometers);
        }


        [[nodiscard]] constexpr un_scalar_t picometers() const
        {
            return convert_from_base(LengthUnit::Picometers);
        }

        [[nodiscard]] static constexpr Length from_picometers(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Picometers);
        }


        [[nodiscard]] constexpr un_scalar_t nanometers() const
        {
            return convert_from_base(LengthUnit::Nanometers);
        }

        [[nodiscard]] static constexpr Length from_nanometers(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Nanometers);
        }


        [[nodiscard]] constexpr un_scalar_t micrometers() const
        {
            return convert_from_base(LengthUnit::Micrometers);
        }

        [[nodiscard]] static constexpr Length from_micrometers(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Micrometers);
        }


        [[nodiscard]] constexpr un_scalar_t millimeters() const
        {
            return convert_from_base(LengthUnit::Millimeters);
        }

        [[nodiscard]] static constexpr Length from_millimeters(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Millimeters);
        }


        [[nodiscard]] constexpr un_scalar_t centimeters() const
        {
            return convert_from_base(LengthUnit::Centimeters);
        }

        [[nodiscard]] static constexpr Length from_centimeters(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Centimeters);
        }


        [[nodiscard]] constexpr un_scalar_t decimeters() const
        {
            return convert_from_base(LengthUnit::Decimeters);
        }

        [[nodiscard]] static constexpr Length from_decimeters(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Decimeters);
        }


        [[nodiscard]] constexpr un_scalar_t decameters() const
        {
            return convert_from_base(LengthUnit::Decameters);
        }

        [[nodiscard]] static constexpr Length from_decameters(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Decameters);
        }


        [[nodiscard]] constexpr un_scalar_t hectometers() const
        {
            return convert_from_base(LengthUnit::Hectometers);
        }

        [[nodiscard]] static constexpr Length from_hectometers(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Hectometers);
        }


        [[nodiscard]] constexpr un_scalar_t kilometers() const
        {
            return convert_from_base(LengthUnit::Kilometers);
        }

        [[nodiscard]] static constexpr Length from_kilometers(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Kilometers);
        }


        [[nodiscard]] constexpr un_scalar_t megameters() const
        {
            return convert_from_base(LengthUnit::Megameters);
        }

        [[nodiscard]] static constexpr Length from_megameters(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Megameters);
        }


        [[nodiscard]] constexpr un_scalar_t gigameters() const
        {
            return convert_from_base(LengthUnit::Gigameters);
        }

        [[nodiscard]] static constexpr Length from_gigameters(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Gigameters);
        }


        [[nodiscard]] constexpr un_scalar_t miles() const
        {
            return convert_from_base(LengthUnit::Miles);
        }

        [[nodiscard]] static constexpr Length from_miles(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Miles);
        }


        [[nodiscard]] constexpr un_scalar_t yards() const
        {
            return convert_from_base(LengthUnit::Yards);
        }

        [[nodiscard]] static constexpr Length from_yards(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Yards);
        }


        [[nodiscard]] constexpr un_scalar_t kiloyards() const
        {
            return convert_from_base(LengthUnit::Kiloyards);
        }

        [[nodiscard]] static constexpr Length from_kiloyards(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Kiloyards);
        }


        [[nodiscard]] constexpr un_scalar_t feet() const
        {
            return convert_from_base(LengthUnit::Feet);
        }

        [[nodiscard]] static constexpr Length from_feet(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Feet);
        }


        [[nodiscard]] constexpr un_scalar_t kilofeet() const
        {
            return convert_from_base(LengthUnit::Kilofeet);
        }

        [[nodiscard]] static constexpr Length from_kilofeet(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Kilofeet);
        }


        [[nodiscard]] constexpr un_scalar_t us_survey_feet() const
        {
            return convert_from_base(LengthUnit::UsSurveyFeet);
        }

        [[nodiscard]] static constexpr Length from_us_survey_feet(const un_scalar_t value)
        {
            return Length(value, LengthUnit::UsSurveyFeet);
        }


        [[nodiscard]] constexpr un_scalar_t inches() const
        {
            return convert_from_base(LengthUnit::Inches);
        }

        [[nodiscard]] static constexpr Length from_inches(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Inches);
        }


        [[nodiscard]] constexpr un_scalar_t mils() const
        {
            return convert_from_base(LengthUnit::Mils);
        }

        [[nodiscard]] static constexpr Length from_mils(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Mils);
        }


        [[nodiscard]] constexpr un_scalar_t nautical_miles() const
        {
            return convert_from_base(LengthUnit::NauticalMiles);
        }

        [[nodiscard]] static constexpr Length from_nautical_miles(const un_scalar_t value)
        {
            return Length(value, LengthUnit::NauticalMiles);
        }


        [[nodiscard]] constexpr un_scalar_t fathoms() const
        {
            return convert_from_base(LengthUnit::Fathoms);
        }

        [[nodiscard]] static constexpr Length from_fathoms(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Fathoms);
        }


        [[nodiscard]] constexpr un_scalar_t shackles() const
        {
            return convert_from_base(LengthUnit::Shackles);
        }

        [[nodiscard]] static constexpr Length from_shackles(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Shackles);
        }


        [[nodiscard]] constexpr un_scalar_t microinches() const
        {
            return convert_from_base(LengthUnit::Microinches);
        }

        [[nodiscard]] static constexpr Length from_microinches(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Microinches);
        }


        [[nodiscard]] constexpr un_scalar_t printer_points() const
        {
            return convert_from_base(LengthUnit::PrinterPoints);
        }

        [[nodiscard]] static constexpr Length from_printer_points(const un_scalar_t value)
        {
            return Length(value, LengthUnit::PrinterPoints);
        }


        [[nodiscard]] constexpr un_scalar_t dtp_points() const
        {
            return convert_from_base(LengthUnit::DtpPoints);
        }

        [[nodiscard]] static constexpr Length from_dtp_points(const un_scalar_t value)
        {
            return Length(value, LengthUnit::DtpPoints);
        }


        [[nodiscard]] constexpr un_scalar_t printer_picas() const
        {
            return convert_from_base(LengthUnit::PrinterPicas);
        }

        [[nodiscard]] static constexpr Length from_printer_picas(const un_scalar_t value)
        {
            return Length(value, LengthUnit::PrinterPicas);
        }


        [[nodiscard]] constexpr un_scalar_t dtp_picas() const
        {
            return convert_from_base(LengthUnit::DtpPicas);
        }

        [[nodiscard]] static constexpr Length from_dtp_picas(const un_scalar_t value)
        {
            return Length(value, LengthUnit::DtpPicas);
        }


        [[nodiscard]] constexpr un_scalar_t twips() const
        {
            return convert_from_base(LengthUnit::Twips);
        }

        [[nodiscard]] static constexpr Length from_twips(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Twips);
        }


        [[nodiscard]] constexpr un_scalar_t hands() const
        {
            return convert_from_base(LengthUnit::Hands);
        }

        [[nodiscard]] static constexpr Length from_hands(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Hands);
        }


        [[nodiscard]] constexpr un_scalar_t astronomical_units() const
        {
            return convert_from_base(LengthUnit::AstronomicalUnits);
        }

        [[nodiscard]] static constexpr Length from_astronomical_units(const un_scalar_t value)
        {
            return Length(value, LengthUnit::AstronomicalUnits);
        }


        [[nodiscard]] constexpr un_scalar_t parsecs() const
        {
            return convert_from_base(LengthUnit::Parsecs);
        }

        [[nodiscard]] static constexpr Length from_parsecs(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Parsecs);
        }


        [[nodiscard]] constexpr un_scalar_t kiloparsecs() const
        {
            return convert_from_base(LengthUnit::Kiloparsecs);
        }

        [[nodiscard]] static constexpr Length from_kiloparsecs(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Kiloparsecs);
        }


        [[nodiscard]] constexpr un_scalar_t megaparsecs() const
        {
            return convert_from_base(LengthUnit::Megaparsecs);
        }

        [[nodiscard]] static constexpr Length from_megaparsecs(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Megaparsecs);
        }


        [[nodiscard]] constexpr un_scalar_t light_years() const
        {
            return convert_from_base(LengthUnit::LightYears);
        }

        [[nodiscard]] static constexpr Length from_light_years(const un_scalar_t value)
        {
            return Length(value, LengthUnit::LightYears);
        }


        [[nodiscard]] constexpr un_scalar_t kilolight_years() const
        {
            return convert_from_base(LengthUnit::KilolightYears);
        }

        [[nodiscard]] static constexpr Length from_kilolight_years(const un_scalar_t value)
        {
            return Length(value, LengthUnit::KilolightYears);
        }


        [[nodiscard]] constexpr un_scalar_t megalight_years() const
        {
            return convert_from_base(LengthUnit::MegalightYears);
        }

        [[nodiscard]] static constexpr Length from_megalight_years(const un_scalar_t value)
        {
            return Length(value, LengthUnit::MegalightYears);
        }


        [[nodiscard]] constexpr un_scalar_t solar_radiuses() const
        {
            return convert_from_base(LengthUnit::SolarRadiuses);
        }

        [[nodiscard]] static constexpr Length from_solar_radiuses(const un_scalar_t value)
        {
            return Length(value, LengthUnit::SolarRadiuses);
        }


        [[nodiscard]] constexpr un_scalar_t chains() const
        {
            return convert_from_base(LengthUnit::Chains);
        }

        [[nodiscard]] static constexpr Length from_chains(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Chains);
        }


        [[nodiscard]] constexpr un_scalar_t angstroms() const
        {
            return convert_from_base(LengthUnit::Angstroms);
        }

        [[nodiscard]] static constexpr Length from_angstroms(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Angstroms);
        }


        [[nodiscard]] constexpr un_scalar_t data_miles() const
        {
            return convert_from_base(LengthUnit::DataMiles);
        }

        [[nodiscard]] static constexpr Length from_data_miles(const un_scalar_t value)
        {
            return Length(value, LengthUnit::DataMiles);
        }


        [[nodiscard]] static constexpr Length from_invalid()
        {
            return Length(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, LengthUnit unit)
        {
            switch (unit)
            {

            case LengthUnit::Meters:
                return value;

            case LengthUnit::Femtometers:
                return (value * static_cast<un_scalar_t>(1e-15));

            case LengthUnit::Picometers:
                return (value * static_cast<un_scalar_t>(1e-12));

            case LengthUnit::Nanometers:
                return (value * static_cast<un_scalar_t>(1e-9));

            case LengthUnit::Micrometers:
                return (value * static_cast<un_scalar_t>(1e-6));

            case LengthUnit::Millimeters:
                return (value * static_cast<un_scalar_t>(1e-3));

            case LengthUnit::Centimeters:
                return (value * static_cast<un_scalar_t>(1e-2));

            case LengthUnit::Decimeters:
                return (value * static_cast<un_scalar_t>(1e-1));

            case LengthUnit::Decameters:
                return (value * static_cast<un_scalar_t>(1e1));

            case LengthUnit::Hectometers:
                return (value * static_cast<un_scalar_t>(1e2));

            case LengthUnit::Kilometers:
                return (value * static_cast<un_scalar_t>(1e3));

            case LengthUnit::Megameters:
                return (value * static_cast<un_scalar_t>(1e6));

            case LengthUnit::Gigameters:
                return (value * static_cast<un_scalar_t>(1e9));

            case LengthUnit::Miles:
                return value * static_cast<un_scalar_t>(1609.344);

            case LengthUnit::Yards:
                return value * static_cast<un_scalar_t>(0.9144);

            case LengthUnit::Kiloyards:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.9144);

            case LengthUnit::Feet:
                return value * static_cast<un_scalar_t>(0.3048);

            case LengthUnit::Kilofeet:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.3048);

            case LengthUnit::UsSurveyFeet:
                return value * static_cast<un_scalar_t>(1200) / static_cast<un_scalar_t>(3937);

            case LengthUnit::Inches:
                return value * static_cast<un_scalar_t>(2.54e-2);

            case LengthUnit::Mils:
                return value * static_cast<un_scalar_t>(2.54e-5);

            case LengthUnit::NauticalMiles:
                return value * static_cast<un_scalar_t>(1852);

            case LengthUnit::Fathoms:
                return value * static_cast<un_scalar_t>(1.8288);

            case LengthUnit::Shackles:
                return value * static_cast<un_scalar_t>(27.432);

            case LengthUnit::Microinches:
                return value * static_cast<un_scalar_t>(2.54e-8);

            case LengthUnit::PrinterPoints:
                return value * static_cast<un_scalar_t>(2.54e-2) / static_cast<un_scalar_t>(72.27) ;

            case LengthUnit::DtpPoints:
                return value * static_cast<un_scalar_t>(2.54e-2) / static_cast<un_scalar_t>(72);

            case LengthUnit::PrinterPicas:
                return value * static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(400) / static_cast<un_scalar_t>(2409);

            case LengthUnit::DtpPicas:
                return value * static_cast<un_scalar_t>(2.54e-2) / static_cast<un_scalar_t>(6);

            case LengthUnit::Twips:
                return value * static_cast<un_scalar_t>(2.54e-2) / static_cast<un_scalar_t>(1440);

            case LengthUnit::Hands:
                return value * static_cast<un_scalar_t>(1.016e-1);

            case LengthUnit::AstronomicalUnits:
                return value * static_cast<un_scalar_t>(1.4959787070e11);

            case LengthUnit::Parsecs:
                return value * static_cast<un_scalar_t>(3.08567758128e16);

            case LengthUnit::Kiloparsecs:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(3.08567758128e16);

            case LengthUnit::Megaparsecs:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(3.08567758128e16);

            case LengthUnit::LightYears:
                return value * static_cast<un_scalar_t>(9.46073047258e15);

            case LengthUnit::KilolightYears:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(9.46073047258e15);

            case LengthUnit::MegalightYears:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(9.46073047258e15);

            case LengthUnit::SolarRadiuses:
                return value * static_cast<un_scalar_t>(6.95700e8);

            case LengthUnit::Chains:
                return value * static_cast<un_scalar_t>(20.1168);

            case LengthUnit::Angstroms:
                return value * static_cast<un_scalar_t>(1e-10);

            case LengthUnit::DataMiles:
                return value * static_cast<un_scalar_t>(1828.8);

            }

            throw std::invalid_argument("Unknown Length unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const LengthUnit unit) const
        {
            switch (unit)
            {

            case LengthUnit::Meters:
                return value_;

            case LengthUnit::Femtometers:
                return (value_) / static_cast<un_scalar_t>(1e-15);

            case LengthUnit::Picometers:
                return (value_) / static_cast<un_scalar_t>(1e-12);

            case LengthUnit::Nanometers:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case LengthUnit::Micrometers:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case LengthUnit::Millimeters:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case LengthUnit::Centimeters:
                return (value_) / static_cast<un_scalar_t>(1e-2);

            case LengthUnit::Decimeters:
                return (value_) / static_cast<un_scalar_t>(1e-1);

            case LengthUnit::Decameters:
                return (value_) / static_cast<un_scalar_t>(1e1);

            case LengthUnit::Hectometers:
                return (value_) / static_cast<un_scalar_t>(1e2);

            case LengthUnit::Kilometers:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case LengthUnit::Megameters:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case LengthUnit::Gigameters:
                return (value_) / static_cast<un_scalar_t>(1e9);

            case LengthUnit::Miles:
                return value_ / static_cast<un_scalar_t>(1609.344);

            case LengthUnit::Yards:
                return value_ / static_cast<un_scalar_t>(0.9144);

            case LengthUnit::Kiloyards:
                return (value_ / static_cast<un_scalar_t>(0.9144)) / static_cast<un_scalar_t>(1e3);

            case LengthUnit::Feet:
                return value_ / static_cast<un_scalar_t>(0.3048);

            case LengthUnit::Kilofeet:
                return (value_ / static_cast<un_scalar_t>(0.3048)) / static_cast<un_scalar_t>(1e3);

            case LengthUnit::UsSurveyFeet:
                return value_ * static_cast<un_scalar_t>(3937) / static_cast<un_scalar_t>(1200);

            case LengthUnit::Inches:
                return value_ / static_cast<un_scalar_t>(2.54e-2);

            case LengthUnit::Mils:
                return value_ / static_cast<un_scalar_t>(2.54e-5);

            case LengthUnit::NauticalMiles:
                return value_ / static_cast<un_scalar_t>(1852);

            case LengthUnit::Fathoms:
                return value_ / static_cast<un_scalar_t>(1.8288);

            case LengthUnit::Shackles:
                return value_ / static_cast<un_scalar_t>(27.432);

            case LengthUnit::Microinches:
                return value_ / static_cast<un_scalar_t>(2.54e-8);

            case LengthUnit::PrinterPoints:
                return value_ * static_cast<un_scalar_t>(72.27) / static_cast<un_scalar_t>(2.54e-2);

            case LengthUnit::DtpPoints:
                return value_ * static_cast<un_scalar_t>(72) / static_cast<un_scalar_t>(2.54e-2);

            case LengthUnit::PrinterPicas:
                return value_ / (static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(400) / static_cast<un_scalar_t>(2409));

            case LengthUnit::DtpPicas:
                return value_ * static_cast<un_scalar_t>(6) / static_cast<un_scalar_t>(2.54e-2);

            case LengthUnit::Twips:
                return value_ * static_cast<un_scalar_t>(1440) / static_cast<un_scalar_t>(2.54e-2);

            case LengthUnit::Hands:
                return value_ / static_cast<un_scalar_t>(1.016e-1);

            case LengthUnit::AstronomicalUnits:
                return value_ / static_cast<un_scalar_t>(1.4959787070e11);

            case LengthUnit::Parsecs:
                return value_ / static_cast<un_scalar_t>(3.08567758128e16);

            case LengthUnit::Kiloparsecs:
                return (value_ / static_cast<un_scalar_t>(3.08567758128e16)) / static_cast<un_scalar_t>(1e3);

            case LengthUnit::Megaparsecs:
                return (value_ / static_cast<un_scalar_t>(3.08567758128e16)) / static_cast<un_scalar_t>(1e6);

            case LengthUnit::LightYears:
                return value_ / static_cast<un_scalar_t>(9.46073047258e15);

            case LengthUnit::KilolightYears:
                return (value_ / static_cast<un_scalar_t>(9.46073047258e15)) / static_cast<un_scalar_t>(1e3);

            case LengthUnit::MegalightYears:
                return (value_ / static_cast<un_scalar_t>(9.46073047258e15)) / static_cast<un_scalar_t>(1e6);

            case LengthUnit::SolarRadiuses:
                return value_ / static_cast<un_scalar_t>(6.95700e8);

            case LengthUnit::Chains:
                return value_ / static_cast<un_scalar_t>(20.1168);

            case LengthUnit::Angstroms:
                return value_ / static_cast<un_scalar_t>(1e-10);

            case LengthUnit::DataMiles:
                return value_ / static_cast<un_scalar_t>(1828.8);

            }

            throw std::invalid_argument("Unknown Length unit.");
        }

        un_scalar_t value_;
    };
}
