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


        /// <summary>The statute mile was standardised between the British Commonwealth and the United States by an international agreement in 1959, when it was formally redefined with respect to SI units as exactly 1,609.344 metres.</summary>
        [[nodiscard]] constexpr un_scalar_t miles() const
        {
            return convert_from_base(LengthUnit::Miles);
        }

        /// <summary>The statute mile was standardised between the British Commonwealth and the United States by an international agreement in 1959, when it was formally redefined with respect to SI units as exactly 1,609.344 metres.</summary>
        [[nodiscard]] static constexpr Length from_miles(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Miles);
        }


        /// <summary>The yard (symbol: yd) is an English unit of length in both the British imperial and US customary systems of measurement equalling 3 feet (or 36 inches). Since 1959 the yard has been by international agreement standardized as exactly 0.9144 meter. A distance of 1,760 yards is equal to 1 mile.</summary>
        [[nodiscard]] constexpr un_scalar_t yards() const
        {
            return convert_from_base(LengthUnit::Yards);
        }

        /// <summary>The yard (symbol: yd) is an English unit of length in both the British imperial and US customary systems of measurement equalling 3 feet (or 36 inches). Since 1959 the yard has been by international agreement standardized as exactly 0.9144 meter. A distance of 1,760 yards is equal to 1 mile.</summary>
        [[nodiscard]] static constexpr Length from_yards(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Yards);
        }


        /// <summary>The yard (symbol: yd) is an English unit of length in both the British imperial and US customary systems of measurement equalling 3 feet (or 36 inches). Since 1959 the yard has been by international agreement standardized as exactly 0.9144 meter. A distance of 1,760 yards is equal to 1 mile.</summary>
        [[nodiscard]] constexpr un_scalar_t kiloyards() const
        {
            return convert_from_base(LengthUnit::Kiloyards);
        }

        /// <summary>The yard (symbol: yd) is an English unit of length in both the British imperial and US customary systems of measurement equalling 3 feet (or 36 inches). Since 1959 the yard has been by international agreement standardized as exactly 0.9144 meter. A distance of 1,760 yards is equal to 1 mile.</summary>
        [[nodiscard]] static constexpr Length from_kiloyards(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Kiloyards);
        }


        /// <summary>The foot (pl. feet; standard symbol: ft) is a unit of length in the British imperial and United States customary systems of measurement. The prime symbol, ′, is commonly used to represent the foot. In both customary and imperial units, one foot comprises 12 inches, and one yard comprises three feet. Since an international agreement in 1959, the foot is defined as equal to exactly 0.3048 meters.</summary>
        [[nodiscard]] constexpr un_scalar_t feet() const
        {
            return convert_from_base(LengthUnit::Feet);
        }

        /// <summary>The foot (pl. feet; standard symbol: ft) is a unit of length in the British imperial and United States customary systems of measurement. The prime symbol, ′, is commonly used to represent the foot. In both customary and imperial units, one foot comprises 12 inches, and one yard comprises three feet. Since an international agreement in 1959, the foot is defined as equal to exactly 0.3048 meters.</summary>
        [[nodiscard]] static constexpr Length from_feet(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Feet);
        }


        /// <summary>The foot (pl. feet; standard symbol: ft) is a unit of length in the British imperial and United States customary systems of measurement. The prime symbol, ′, is commonly used to represent the foot. In both customary and imperial units, one foot comprises 12 inches, and one yard comprises three feet. Since an international agreement in 1959, the foot is defined as equal to exactly 0.3048 meters.</summary>
        [[nodiscard]] constexpr un_scalar_t kilofeet() const
        {
            return convert_from_base(LengthUnit::Kilofeet);
        }

        /// <summary>The foot (pl. feet; standard symbol: ft) is a unit of length in the British imperial and United States customary systems of measurement. The prime symbol, ′, is commonly used to represent the foot. In both customary and imperial units, one foot comprises 12 inches, and one yard comprises three feet. Since an international agreement in 1959, the foot is defined as equal to exactly 0.3048 meters.</summary>
        [[nodiscard]] static constexpr Length from_kilofeet(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Kilofeet);
        }


        /// <summary>In the United States, the foot was defined as 12 inches, with the inch being defined by the Mendenhall Order of 1893 as 39.37 inches = 1 m. This makes a U.S. survey foot exactly 1200/3937 meters.</summary>
        [[nodiscard]] constexpr un_scalar_t us_survey_feet() const
        {
            return convert_from_base(LengthUnit::UsSurveyFeet);
        }

        /// <summary>In the United States, the foot was defined as 12 inches, with the inch being defined by the Mendenhall Order of 1893 as 39.37 inches = 1 m. This makes a U.S. survey foot exactly 1200/3937 meters.</summary>
        [[nodiscard]] static constexpr Length from_us_survey_feet(const un_scalar_t value)
        {
            return Length(value, LengthUnit::UsSurveyFeet);
        }


        /// <summary>The inch (symbol: in or ″) is a unit of length in the British Imperial and the United States customary systems of measurement. It is equal to 1/36 yard or 1/12 of a foot. Derived from the Roman uncia ("twelfth"), the word inch is also sometimes used to translate similar units in other measurement systems, usually understood as deriving from the width of the human thumb.</summary>
        [[nodiscard]] constexpr un_scalar_t inches() const
        {
            return convert_from_base(LengthUnit::Inches);
        }

        /// <summary>The inch (symbol: in or ″) is a unit of length in the British Imperial and the United States customary systems of measurement. It is equal to 1/36 yard or 1/12 of a foot. Derived from the Roman uncia ("twelfth"), the word inch is also sometimes used to translate similar units in other measurement systems, usually understood as deriving from the width of the human thumb.</summary>
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


        /// <summary>In typography, the point is the smallest unit of measure. It is used for measuring font size, leading, and other items on a printed page. In modern times this size of the point has been approximated as exactly 1⁄72.27 (0.01383700013837) of the inch by Donald Knuth for the default unit of his TeX computer typesetting system and is thus sometimes known as the TeX point.</summary>
        [[nodiscard]] constexpr un_scalar_t printer_points() const
        {
            return convert_from_base(LengthUnit::PrinterPoints);
        }

        /// <summary>In typography, the point is the smallest unit of measure. It is used for measuring font size, leading, and other items on a printed page. In modern times this size of the point has been approximated as exactly 1⁄72.27 (0.01383700013837) of the inch by Donald Knuth for the default unit of his TeX computer typesetting system and is thus sometimes known as the TeX point.</summary>
        [[nodiscard]] static constexpr Length from_printer_points(const un_scalar_t value)
        {
            return Length(value, LengthUnit::PrinterPoints);
        }


        /// <summary>The desktop publishing point (DTP) is defined as 1⁄72 of an inch (1/72 × 25.4 mm ≈ 0.353 mm) and, as with earlier American point sizes, is considered to be 1⁄12 of a pica.</summary>
        [[nodiscard]] constexpr un_scalar_t dtp_points() const
        {
            return convert_from_base(LengthUnit::DtpPoints);
        }

        /// <summary>The desktop publishing point (DTP) is defined as 1⁄72 of an inch (1/72 × 25.4 mm ≈ 0.353 mm) and, as with earlier American point sizes, is considered to be 1⁄12 of a pica.</summary>
        [[nodiscard]] static constexpr Length from_dtp_points(const un_scalar_t value)
        {
            return Length(value, LengthUnit::DtpPoints);
        }


        /// <summary>The American pica of 0.16604 inches (~4.217 mm) was established by the United States Type Founders' Association in 1886. In TeX one pica is 400⁄2409 of an inch.</summary>
        [[nodiscard]] constexpr un_scalar_t printer_picas() const
        {
            return convert_from_base(LengthUnit::PrinterPicas);
        }

        /// <summary>The American pica of 0.16604 inches (~4.217 mm) was established by the United States Type Founders' Association in 1886. In TeX one pica is 400⁄2409 of an inch.</summary>
        [[nodiscard]] static constexpr Length from_printer_picas(const un_scalar_t value)
        {
            return Length(value, LengthUnit::PrinterPicas);
        }


        /// <summary>The pica is a typographic unit of measure corresponding to approximately 1⁄6 of an inch, or from 1⁄68 to 1⁄73 of a foot. One pica is further divided into 12 points.</summary>
        [[nodiscard]] constexpr un_scalar_t dtp_picas() const
        {
            return convert_from_base(LengthUnit::DtpPicas);
        }

        /// <summary>The pica is a typographic unit of measure corresponding to approximately 1⁄6 of an inch, or from 1⁄68 to 1⁄73 of a foot. One pica is further divided into 12 points.</summary>
        [[nodiscard]] static constexpr Length from_dtp_picas(const un_scalar_t value)
        {
            return Length(value, LengthUnit::DtpPicas);
        }


        /// <summary>A twip (abbreviating "twentieth of a point" or "twentieth of an inch point") is a typographical measurement, defined as 1⁄20 of a typographical point. One twip is 1⁄1440 inch, or ~17.64 μm.</summary>
        [[nodiscard]] constexpr un_scalar_t twips() const
        {
            return convert_from_base(LengthUnit::Twips);
        }

        /// <summary>A twip (abbreviating "twentieth of a point" or "twentieth of an inch point") is a typographical measurement, defined as 1⁄20 of a typographical point. One twip is 1⁄1440 inch, or ~17.64 μm.</summary>
        [[nodiscard]] static constexpr Length from_twips(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Twips);
        }


        /// <summary>The hand is a non-SI unit of measurement of length standardized to 4 in (101.6 mm). It is used to measure the height of horses in many English-speaking countries, including Australia, Canada, Ireland, the United Kingdom, and the United States. It was originally based on the breadth of a human hand.</summary>
        [[nodiscard]] constexpr un_scalar_t hands() const
        {
            return convert_from_base(LengthUnit::Hands);
        }

        /// <summary>The hand is a non-SI unit of measurement of length standardized to 4 in (101.6 mm). It is used to measure the height of horses in many English-speaking countries, including Australia, Canada, Ireland, the United Kingdom, and the United States. It was originally based on the breadth of a human hand.</summary>
        [[nodiscard]] static constexpr Length from_hands(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Hands);
        }


        /// <summary>One Astronomical Unit is the distance from the solar system Star, the sun, to planet Earth.</summary>
        [[nodiscard]] constexpr un_scalar_t astronomical_units() const
        {
            return convert_from_base(LengthUnit::AstronomicalUnits);
        }

        /// <summary>One Astronomical Unit is the distance from the solar system Star, the sun, to planet Earth.</summary>
        [[nodiscard]] static constexpr Length from_astronomical_units(const un_scalar_t value)
        {
            return Length(value, LengthUnit::AstronomicalUnits);
        }


        /// <summary>A parsec is defined as the distance at which one astronomical unit (AU) subtends an angle of one arcsecond.</summary>
        [[nodiscard]] constexpr un_scalar_t parsecs() const
        {
            return convert_from_base(LengthUnit::Parsecs);
        }

        /// <summary>A parsec is defined as the distance at which one astronomical unit (AU) subtends an angle of one arcsecond.</summary>
        [[nodiscard]] static constexpr Length from_parsecs(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Parsecs);
        }


        /// <summary>A parsec is defined as the distance at which one astronomical unit (AU) subtends an angle of one arcsecond.</summary>
        [[nodiscard]] constexpr un_scalar_t kiloparsecs() const
        {
            return convert_from_base(LengthUnit::Kiloparsecs);
        }

        /// <summary>A parsec is defined as the distance at which one astronomical unit (AU) subtends an angle of one arcsecond.</summary>
        [[nodiscard]] static constexpr Length from_kiloparsecs(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Kiloparsecs);
        }


        /// <summary>A parsec is defined as the distance at which one astronomical unit (AU) subtends an angle of one arcsecond.</summary>
        [[nodiscard]] constexpr un_scalar_t megaparsecs() const
        {
            return convert_from_base(LengthUnit::Megaparsecs);
        }

        /// <summary>A parsec is defined as the distance at which one astronomical unit (AU) subtends an angle of one arcsecond.</summary>
        [[nodiscard]] static constexpr Length from_megaparsecs(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Megaparsecs);
        }


        /// <summary>A Light Year (ly) is the distance that light travel during an Earth year, ie 365 days.</summary>
        [[nodiscard]] constexpr un_scalar_t light_years() const
        {
            return convert_from_base(LengthUnit::LightYears);
        }

        /// <summary>A Light Year (ly) is the distance that light travel during an Earth year, ie 365 days.</summary>
        [[nodiscard]] static constexpr Length from_light_years(const un_scalar_t value)
        {
            return Length(value, LengthUnit::LightYears);
        }


        /// <summary>A Light Year (ly) is the distance that light travel during an Earth year, ie 365 days.</summary>
        [[nodiscard]] constexpr un_scalar_t kilolight_years() const
        {
            return convert_from_base(LengthUnit::KilolightYears);
        }

        /// <summary>A Light Year (ly) is the distance that light travel during an Earth year, ie 365 days.</summary>
        [[nodiscard]] static constexpr Length from_kilolight_years(const un_scalar_t value)
        {
            return Length(value, LengthUnit::KilolightYears);
        }


        /// <summary>A Light Year (ly) is the distance that light travel during an Earth year, ie 365 days.</summary>
        [[nodiscard]] constexpr un_scalar_t megalight_years() const
        {
            return convert_from_base(LengthUnit::MegalightYears);
        }

        /// <summary>A Light Year (ly) is the distance that light travel during an Earth year, ie 365 days.</summary>
        [[nodiscard]] static constexpr Length from_megalight_years(const un_scalar_t value)
        {
            return Length(value, LengthUnit::MegalightYears);
        }


        /// <summary>Solar radius is a ratio unit to the radius of the solar system star, the sun.</summary>
        [[nodiscard]] constexpr un_scalar_t solar_radiuses() const
        {
            return convert_from_base(LengthUnit::SolarRadiuses);
        }

        /// <summary>Solar radius is a ratio unit to the radius of the solar system star, the sun.</summary>
        [[nodiscard]] static constexpr Length from_solar_radiuses(const un_scalar_t value)
        {
            return Length(value, LengthUnit::SolarRadiuses);
        }


        /// <summary>The chain (abbreviated ch) is a unit of length equal to 66 feet (22 yards), used in both the US customary and Imperial unit systems. It is subdivided into 100 links. There are 10 chains in a furlong, and 80 chains in one statute mile. In metric terms, it is 20.1168 m long.</summary>
        [[nodiscard]] constexpr un_scalar_t chains() const
        {
            return convert_from_base(LengthUnit::Chains);
        }

        /// <summary>The chain (abbreviated ch) is a unit of length equal to 66 feet (22 yards), used in both the US customary and Imperial unit systems. It is subdivided into 100 links. There are 10 chains in a furlong, and 80 chains in one statute mile. In metric terms, it is 20.1168 m long.</summary>
        [[nodiscard]] static constexpr Length from_chains(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Chains);
        }


        /// <summary>Angstrom is a metric unit of length equal to 1e-10 meter</summary>
        [[nodiscard]] constexpr un_scalar_t angstroms() const
        {
            return convert_from_base(LengthUnit::Angstroms);
        }

        /// <summary>Angstrom is a metric unit of length equal to 1e-10 meter</summary>
        [[nodiscard]] static constexpr Length from_angstroms(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Angstroms);
        }


        /// <summary>In radar-related subjects and in JTIDS, a data mile is a unit of distance equal to 6000 feet (1.8288 kilometres or 0.987 nautical miles).</summary>
        [[nodiscard]] constexpr un_scalar_t data_miles() const
        {
            return convert_from_base(LengthUnit::DataMiles);
        }

        /// <summary>In radar-related subjects and in JTIDS, a data mile is a unit of distance equal to 6000 feet (1.8288 kilometres or 0.987 nautical miles).</summary>
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
