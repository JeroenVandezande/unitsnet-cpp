#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include <string>
#include <string_view>
#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
#include <magic_enum/magic_enum.hpp>
#endif
#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
#include <nlohmann/json.hpp>
#endif
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class LengthUnit : std::uint8_t
    {
        Meter,
        Femtometer,
        Picometer,
        Nanometer,
        Micrometer,
        Millimeter,
        Centimeter,
        Decimeter,
        Decameter,
        Hectometer,
        Kilometer,
        Megameter,
        Gigameter,
        Mile,
        Yard,
        Kiloyard,
        Foot,
        Kilofoot,
        UsSurveyFoot,
        Inch,
        Mil,
        NauticalMile,
        Fathom,
        Shackle,
        Microinch,
        PrinterPoint,
        DtpPoint,
        PrinterPica,
        DtpPica,
        Twip,
        Hand,
        AstronomicalUnit,
        Parsec,
        Kiloparsec,
        Megaparsec,
        LightYear,
        KilolightYear,
        MegalightYear,
        SolarRadius,
        Chain,
        Angstrom,
        DataMile,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Length.</summary>
    class LengthDto
    {
    public:
        constexpr LengthDto() noexcept
            : value{}, unit(LengthUnit::Meter)
        {
        }

        constexpr LengthDto(
            const un_scalar_t value,
            const LengthUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        LengthUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr LengthUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<LengthUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Length unit name.");
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this DTO to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json() const
        {
            return nlohmann::json{
                {"value", value},
                {"unit", unit_name()}
            };
        }

        /// <summary>Creates a DTO from a nlohmann JSON object.</summary>
        [[nodiscard]] static LengthDto from_json(const nlohmann::json& json)
        {
            return LengthDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Many different units of length have been used around the world. The main units in modern use are U.S. customary units in the United States and the Metric system elsewhere. British Imperial units are still used for some purposes in the United Kingdom and some other countries. The metric system is sub-divided into SI and non-SI units.</summary>
    class Length : public UnitsNetBase
    {
    public:
        constexpr explicit Length(
            const un_scalar_t value,
            const LengthUnit unit = LengthUnit::Meter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const LengthUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr LengthDto to_dto(
            const LengthUnit unit = LengthUnit::Meter) const
        {
            return LengthDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Length from_dto(const LengthDto& dto)
        {
            return Length(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const LengthUnit unit = LengthUnit::Meter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Length from_json(const nlohmann::json& json)
        {
            return from_dto(LengthDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Length operator+(const Length& other) const noexcept
        {
            return Length(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Length operator-(const Length& other)const noexcept
        {
            return Length(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Length operator*(const un_scalar_t scalar) const noexcept
        {
            return Length(base_value() * scalar);
        }

        [[nodiscard]] constexpr Length operator/(const un_scalar_t scalar) const noexcept
        {
            return Length(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Length& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Length& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Length& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t meters() const
        {
            return convert_from_base(LengthUnit::Meter);
        }

        [[nodiscard]] static constexpr Length from_meters(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Meter);
        }

        [[nodiscard]] constexpr un_scalar_t femtometers() const
        {
            return convert_from_base(LengthUnit::Femtometer);
        }

        [[nodiscard]] static constexpr Length from_femtometers(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Femtometer);
        }

        [[nodiscard]] constexpr un_scalar_t picometers() const
        {
            return convert_from_base(LengthUnit::Picometer);
        }

        [[nodiscard]] static constexpr Length from_picometers(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Picometer);
        }

        [[nodiscard]] constexpr un_scalar_t nanometers() const
        {
            return convert_from_base(LengthUnit::Nanometer);
        }

        [[nodiscard]] static constexpr Length from_nanometers(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Nanometer);
        }

        [[nodiscard]] constexpr un_scalar_t micrometers() const
        {
            return convert_from_base(LengthUnit::Micrometer);
        }

        [[nodiscard]] static constexpr Length from_micrometers(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Micrometer);
        }

        [[nodiscard]] constexpr un_scalar_t millimeters() const
        {
            return convert_from_base(LengthUnit::Millimeter);
        }

        [[nodiscard]] static constexpr Length from_millimeters(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Millimeter);
        }

        [[nodiscard]] constexpr un_scalar_t centimeters() const
        {
            return convert_from_base(LengthUnit::Centimeter);
        }

        [[nodiscard]] static constexpr Length from_centimeters(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Centimeter);
        }

        [[nodiscard]] constexpr un_scalar_t decimeters() const
        {
            return convert_from_base(LengthUnit::Decimeter);
        }

        [[nodiscard]] static constexpr Length from_decimeters(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Decimeter);
        }

        [[nodiscard]] constexpr un_scalar_t decameters() const
        {
            return convert_from_base(LengthUnit::Decameter);
        }

        [[nodiscard]] static constexpr Length from_decameters(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Decameter);
        }

        [[nodiscard]] constexpr un_scalar_t hectometers() const
        {
            return convert_from_base(LengthUnit::Hectometer);
        }

        [[nodiscard]] static constexpr Length from_hectometers(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Hectometer);
        }

        [[nodiscard]] constexpr un_scalar_t kilometers() const
        {
            return convert_from_base(LengthUnit::Kilometer);
        }

        [[nodiscard]] static constexpr Length from_kilometers(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Kilometer);
        }

        [[nodiscard]] constexpr un_scalar_t megameters() const
        {
            return convert_from_base(LengthUnit::Megameter);
        }

        [[nodiscard]] static constexpr Length from_megameters(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Megameter);
        }

        [[nodiscard]] constexpr un_scalar_t gigameters() const
        {
            return convert_from_base(LengthUnit::Gigameter);
        }

        [[nodiscard]] static constexpr Length from_gigameters(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Gigameter);
        }

        /// <summary>The statute mile was standardised between the British Commonwealth and the United States by an international agreement in 1959, when it was formally redefined with respect to SI units as exactly 1,609.344 metres.</summary>
        [[nodiscard]] constexpr un_scalar_t miles() const
        {
            return convert_from_base(LengthUnit::Mile);
        }

        /// <summary>The statute mile was standardised between the British Commonwealth and the United States by an international agreement in 1959, when it was formally redefined with respect to SI units as exactly 1,609.344 metres.</summary>
        [[nodiscard]] static constexpr Length from_miles(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Mile);
        }

        /// <summary>The yard (symbol: yd) is an English unit of length in both the British imperial and US customary systems of measurement equalling 3 feet (or 36 inches). Since 1959 the yard has been by international agreement standardized as exactly 0.9144 meter. A distance of 1,760 yards is equal to 1 mile.</summary>
        [[nodiscard]] constexpr un_scalar_t yards() const
        {
            return convert_from_base(LengthUnit::Yard);
        }

        /// <summary>The yard (symbol: yd) is an English unit of length in both the British imperial and US customary systems of measurement equalling 3 feet (or 36 inches). Since 1959 the yard has been by international agreement standardized as exactly 0.9144 meter. A distance of 1,760 yards is equal to 1 mile.</summary>
        [[nodiscard]] static constexpr Length from_yards(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Yard);
        }

        /// <summary>The yard (symbol: yd) is an English unit of length in both the British imperial and US customary systems of measurement equalling 3 feet (or 36 inches). Since 1959 the yard has been by international agreement standardized as exactly 0.9144 meter. A distance of 1,760 yards is equal to 1 mile.</summary>
        [[nodiscard]] constexpr un_scalar_t kiloyards() const
        {
            return convert_from_base(LengthUnit::Kiloyard);
        }

        /// <summary>The yard (symbol: yd) is an English unit of length in both the British imperial and US customary systems of measurement equalling 3 feet (or 36 inches). Since 1959 the yard has been by international agreement standardized as exactly 0.9144 meter. A distance of 1,760 yards is equal to 1 mile.</summary>
        [[nodiscard]] static constexpr Length from_kiloyards(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Kiloyard);
        }

        /// <summary>The foot (pl. feet; standard symbol: ft) is a unit of length in the British imperial and United States customary systems of measurement. The prime symbol, ′, is commonly used to represent the foot. In both customary and imperial units, one foot comprises 12 inches, and one yard comprises three feet. Since an international agreement in 1959, the foot is defined as equal to exactly 0.3048 meters.</summary>
        [[nodiscard]] constexpr un_scalar_t feet() const
        {
            return convert_from_base(LengthUnit::Foot);
        }

        /// <summary>The foot (pl. feet; standard symbol: ft) is a unit of length in the British imperial and United States customary systems of measurement. The prime symbol, ′, is commonly used to represent the foot. In both customary and imperial units, one foot comprises 12 inches, and one yard comprises three feet. Since an international agreement in 1959, the foot is defined as equal to exactly 0.3048 meters.</summary>
        [[nodiscard]] static constexpr Length from_feet(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Foot);
        }

        /// <summary>The foot (pl. feet; standard symbol: ft) is a unit of length in the British imperial and United States customary systems of measurement. The prime symbol, ′, is commonly used to represent the foot. In both customary and imperial units, one foot comprises 12 inches, and one yard comprises three feet. Since an international agreement in 1959, the foot is defined as equal to exactly 0.3048 meters.</summary>
        [[nodiscard]] constexpr un_scalar_t kilofeet() const
        {
            return convert_from_base(LengthUnit::Kilofoot);
        }

        /// <summary>The foot (pl. feet; standard symbol: ft) is a unit of length in the British imperial and United States customary systems of measurement. The prime symbol, ′, is commonly used to represent the foot. In both customary and imperial units, one foot comprises 12 inches, and one yard comprises three feet. Since an international agreement in 1959, the foot is defined as equal to exactly 0.3048 meters.</summary>
        [[nodiscard]] static constexpr Length from_kilofeet(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Kilofoot);
        }

        /// <summary>In the United States, the foot was defined as 12 inches, with the inch being defined by the Mendenhall Order of 1893 as 39.37 inches = 1 m. This makes a U.S. survey foot exactly 1200/3937 meters.</summary>
        [[nodiscard]] constexpr un_scalar_t us_survey_feet() const
        {
            return convert_from_base(LengthUnit::UsSurveyFoot);
        }

        /// <summary>In the United States, the foot was defined as 12 inches, with the inch being defined by the Mendenhall Order of 1893 as 39.37 inches = 1 m. This makes a U.S. survey foot exactly 1200/3937 meters.</summary>
        [[nodiscard]] static constexpr Length from_us_survey_feet(const un_scalar_t value)
        {
            return Length(value, LengthUnit::UsSurveyFoot);
        }

        /// <summary>The inch (symbol: in or ″) is a unit of length in the British Imperial and the United States customary systems of measurement. It is equal to 1/36 yard or 1/12 of a foot. Derived from the Roman uncia ("twelfth"), the word inch is also sometimes used to translate similar units in other measurement systems, usually understood as deriving from the width of the human thumb.</summary>
        [[nodiscard]] constexpr un_scalar_t inches() const
        {
            return convert_from_base(LengthUnit::Inch);
        }

        /// <summary>The inch (symbol: in or ″) is a unit of length in the British Imperial and the United States customary systems of measurement. It is equal to 1/36 yard or 1/12 of a foot. Derived from the Roman uncia ("twelfth"), the word inch is also sometimes used to translate similar units in other measurement systems, usually understood as deriving from the width of the human thumb.</summary>
        [[nodiscard]] static constexpr Length from_inches(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Inch);
        }

        [[nodiscard]] constexpr un_scalar_t mils() const
        {
            return convert_from_base(LengthUnit::Mil);
        }

        [[nodiscard]] static constexpr Length from_mils(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Mil);
        }

        [[nodiscard]] constexpr un_scalar_t nautical_miles() const
        {
            return convert_from_base(LengthUnit::NauticalMile);
        }

        [[nodiscard]] static constexpr Length from_nautical_miles(const un_scalar_t value)
        {
            return Length(value, LengthUnit::NauticalMile);
        }

        [[nodiscard]] constexpr un_scalar_t fathoms() const
        {
            return convert_from_base(LengthUnit::Fathom);
        }

        [[nodiscard]] static constexpr Length from_fathoms(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Fathom);
        }

        [[nodiscard]] constexpr un_scalar_t shackles() const
        {
            return convert_from_base(LengthUnit::Shackle);
        }

        [[nodiscard]] static constexpr Length from_shackles(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Shackle);
        }

        [[nodiscard]] constexpr un_scalar_t microinches() const
        {
            return convert_from_base(LengthUnit::Microinch);
        }

        [[nodiscard]] static constexpr Length from_microinches(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Microinch);
        }

        /// <summary>In typography, the point is the smallest unit of measure. It is used for measuring font size, leading, and other items on a printed page. In modern times this size of the point has been approximated as exactly 1⁄72.27 (0.01383700013837) of the inch by Donald Knuth for the default unit of his TeX computer typesetting system and is thus sometimes known as the TeX point.</summary>
        [[nodiscard]] constexpr un_scalar_t printer_points() const
        {
            return convert_from_base(LengthUnit::PrinterPoint);
        }

        /// <summary>In typography, the point is the smallest unit of measure. It is used for measuring font size, leading, and other items on a printed page. In modern times this size of the point has been approximated as exactly 1⁄72.27 (0.01383700013837) of the inch by Donald Knuth for the default unit of his TeX computer typesetting system and is thus sometimes known as the TeX point.</summary>
        [[nodiscard]] static constexpr Length from_printer_points(const un_scalar_t value)
        {
            return Length(value, LengthUnit::PrinterPoint);
        }

        /// <summary>The desktop publishing point (DTP) is defined as 1⁄72 of an inch (1/72 × 25.4 mm ≈ 0.353 mm) and, as with earlier American point sizes, is considered to be 1⁄12 of a pica.</summary>
        [[nodiscard]] constexpr un_scalar_t dtp_points() const
        {
            return convert_from_base(LengthUnit::DtpPoint);
        }

        /// <summary>The desktop publishing point (DTP) is defined as 1⁄72 of an inch (1/72 × 25.4 mm ≈ 0.353 mm) and, as with earlier American point sizes, is considered to be 1⁄12 of a pica.</summary>
        [[nodiscard]] static constexpr Length from_dtp_points(const un_scalar_t value)
        {
            return Length(value, LengthUnit::DtpPoint);
        }

        /// <summary>The American pica of 0.16604 inches (~4.217 mm) was established by the United States Type Founders' Association in 1886. In TeX one pica is 400⁄2409 of an inch.</summary>
        [[nodiscard]] constexpr un_scalar_t printer_picas() const
        {
            return convert_from_base(LengthUnit::PrinterPica);
        }

        /// <summary>The American pica of 0.16604 inches (~4.217 mm) was established by the United States Type Founders' Association in 1886. In TeX one pica is 400⁄2409 of an inch.</summary>
        [[nodiscard]] static constexpr Length from_printer_picas(const un_scalar_t value)
        {
            return Length(value, LengthUnit::PrinterPica);
        }

        /// <summary>The pica is a typographic unit of measure corresponding to approximately 1⁄6 of an inch, or from 1⁄68 to 1⁄73 of a foot. One pica is further divided into 12 points.</summary>
        [[nodiscard]] constexpr un_scalar_t dtp_picas() const
        {
            return convert_from_base(LengthUnit::DtpPica);
        }

        /// <summary>The pica is a typographic unit of measure corresponding to approximately 1⁄6 of an inch, or from 1⁄68 to 1⁄73 of a foot. One pica is further divided into 12 points.</summary>
        [[nodiscard]] static constexpr Length from_dtp_picas(const un_scalar_t value)
        {
            return Length(value, LengthUnit::DtpPica);
        }

        /// <summary>A twip (abbreviating "twentieth of a point" or "twentieth of an inch point") is a typographical measurement, defined as 1⁄20 of a typographical point. One twip is 1⁄1440 inch, or ~17.64 μm.</summary>
        [[nodiscard]] constexpr un_scalar_t twips() const
        {
            return convert_from_base(LengthUnit::Twip);
        }

        /// <summary>A twip (abbreviating "twentieth of a point" or "twentieth of an inch point") is a typographical measurement, defined as 1⁄20 of a typographical point. One twip is 1⁄1440 inch, or ~17.64 μm.</summary>
        [[nodiscard]] static constexpr Length from_twips(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Twip);
        }

        /// <summary>The hand is a non-SI unit of measurement of length standardized to 4 in (101.6 mm). It is used to measure the height of horses in many English-speaking countries, including Australia, Canada, Ireland, the United Kingdom, and the United States. It was originally based on the breadth of a human hand.</summary>
        [[nodiscard]] constexpr un_scalar_t hands() const
        {
            return convert_from_base(LengthUnit::Hand);
        }

        /// <summary>The hand is a non-SI unit of measurement of length standardized to 4 in (101.6 mm). It is used to measure the height of horses in many English-speaking countries, including Australia, Canada, Ireland, the United Kingdom, and the United States. It was originally based on the breadth of a human hand.</summary>
        [[nodiscard]] static constexpr Length from_hands(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Hand);
        }

        /// <summary>One Astronomical Unit is the distance from the solar system Star, the sun, to planet Earth.</summary>
        [[nodiscard]] constexpr un_scalar_t astronomical_units() const
        {
            return convert_from_base(LengthUnit::AstronomicalUnit);
        }

        /// <summary>One Astronomical Unit is the distance from the solar system Star, the sun, to planet Earth.</summary>
        [[nodiscard]] static constexpr Length from_astronomical_units(const un_scalar_t value)
        {
            return Length(value, LengthUnit::AstronomicalUnit);
        }

        /// <summary>A parsec is defined as the distance at which one astronomical unit (AU) subtends an angle of one arcsecond.</summary>
        [[nodiscard]] constexpr un_scalar_t parsecs() const
        {
            return convert_from_base(LengthUnit::Parsec);
        }

        /// <summary>A parsec is defined as the distance at which one astronomical unit (AU) subtends an angle of one arcsecond.</summary>
        [[nodiscard]] static constexpr Length from_parsecs(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Parsec);
        }

        /// <summary>A parsec is defined as the distance at which one astronomical unit (AU) subtends an angle of one arcsecond.</summary>
        [[nodiscard]] constexpr un_scalar_t kiloparsecs() const
        {
            return convert_from_base(LengthUnit::Kiloparsec);
        }

        /// <summary>A parsec is defined as the distance at which one astronomical unit (AU) subtends an angle of one arcsecond.</summary>
        [[nodiscard]] static constexpr Length from_kiloparsecs(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Kiloparsec);
        }

        /// <summary>A parsec is defined as the distance at which one astronomical unit (AU) subtends an angle of one arcsecond.</summary>
        [[nodiscard]] constexpr un_scalar_t megaparsecs() const
        {
            return convert_from_base(LengthUnit::Megaparsec);
        }

        /// <summary>A parsec is defined as the distance at which one astronomical unit (AU) subtends an angle of one arcsecond.</summary>
        [[nodiscard]] static constexpr Length from_megaparsecs(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Megaparsec);
        }

        /// <summary>A Light Year (ly) is the distance that light travel during an Earth year, ie 365 days.</summary>
        [[nodiscard]] constexpr un_scalar_t light_years() const
        {
            return convert_from_base(LengthUnit::LightYear);
        }

        /// <summary>A Light Year (ly) is the distance that light travel during an Earth year, ie 365 days.</summary>
        [[nodiscard]] static constexpr Length from_light_years(const un_scalar_t value)
        {
            return Length(value, LengthUnit::LightYear);
        }

        /// <summary>A Light Year (ly) is the distance that light travel during an Earth year, ie 365 days.</summary>
        [[nodiscard]] constexpr un_scalar_t kilolight_years() const
        {
            return convert_from_base(LengthUnit::KilolightYear);
        }

        /// <summary>A Light Year (ly) is the distance that light travel during an Earth year, ie 365 days.</summary>
        [[nodiscard]] static constexpr Length from_kilolight_years(const un_scalar_t value)
        {
            return Length(value, LengthUnit::KilolightYear);
        }

        /// <summary>A Light Year (ly) is the distance that light travel during an Earth year, ie 365 days.</summary>
        [[nodiscard]] constexpr un_scalar_t megalight_years() const
        {
            return convert_from_base(LengthUnit::MegalightYear);
        }

        /// <summary>A Light Year (ly) is the distance that light travel during an Earth year, ie 365 days.</summary>
        [[nodiscard]] static constexpr Length from_megalight_years(const un_scalar_t value)
        {
            return Length(value, LengthUnit::MegalightYear);
        }

        /// <summary>Solar radius is a ratio unit to the radius of the solar system star, the sun.</summary>
        [[nodiscard]] constexpr un_scalar_t solar_radiuses() const
        {
            return convert_from_base(LengthUnit::SolarRadius);
        }

        /// <summary>Solar radius is a ratio unit to the radius of the solar system star, the sun.</summary>
        [[nodiscard]] static constexpr Length from_solar_radiuses(const un_scalar_t value)
        {
            return Length(value, LengthUnit::SolarRadius);
        }

        /// <summary>The chain (abbreviated ch) is a unit of length equal to 66 feet (22 yards), used in both the US customary and Imperial unit systems. It is subdivided into 100 links. There are 10 chains in a furlong, and 80 chains in one statute mile. In metric terms, it is 20.1168 m long.</summary>
        [[nodiscard]] constexpr un_scalar_t chains() const
        {
            return convert_from_base(LengthUnit::Chain);
        }

        /// <summary>The chain (abbreviated ch) is a unit of length equal to 66 feet (22 yards), used in both the US customary and Imperial unit systems. It is subdivided into 100 links. There are 10 chains in a furlong, and 80 chains in one statute mile. In metric terms, it is 20.1168 m long.</summary>
        [[nodiscard]] static constexpr Length from_chains(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Chain);
        }

        /// <summary>Angstrom is a metric unit of length equal to 1e-10 meter</summary>
        [[nodiscard]] constexpr un_scalar_t angstroms() const
        {
            return convert_from_base(LengthUnit::Angstrom);
        }

        /// <summary>Angstrom is a metric unit of length equal to 1e-10 meter</summary>
        [[nodiscard]] static constexpr Length from_angstroms(const un_scalar_t value)
        {
            return Length(value, LengthUnit::Angstrom);
        }

        /// <summary>In radar-related subjects and in JTIDS, a data mile is a unit of distance equal to 6000 feet (1.8288 kilometres or 0.987 nautical miles).</summary>
        [[nodiscard]] constexpr un_scalar_t data_miles() const
        {
            return convert_from_base(LengthUnit::DataMile);
        }

        /// <summary>In radar-related subjects and in JTIDS, a data mile is a unit of distance equal to 6000 feet (1.8288 kilometres or 0.987 nautical miles).</summary>
        [[nodiscard]] static constexpr Length from_data_miles(const un_scalar_t value)
        {
            return Length(value, LengthUnit::DataMile);
        }

        [[nodiscard]] static constexpr Length from_invalid()
        {
            return Length(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, LengthUnit unit)
        {
            switch (unit)
            {

            case LengthUnit::Meter:
                return value;

            case LengthUnit::Femtometer:
                return (value * static_cast<un_scalar_t>(1e-15));

            case LengthUnit::Picometer:
                return (value * static_cast<un_scalar_t>(1e-12));

            case LengthUnit::Nanometer:
                return (value * static_cast<un_scalar_t>(1e-9));

            case LengthUnit::Micrometer:
                return (value * static_cast<un_scalar_t>(1e-6));

            case LengthUnit::Millimeter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case LengthUnit::Centimeter:
                return (value * static_cast<un_scalar_t>(1e-2));

            case LengthUnit::Decimeter:
                return (value * static_cast<un_scalar_t>(1e-1));

            case LengthUnit::Decameter:
                return (value * static_cast<un_scalar_t>(1e1));

            case LengthUnit::Hectometer:
                return (value * static_cast<un_scalar_t>(1e2));

            case LengthUnit::Kilometer:
                return (value * static_cast<un_scalar_t>(1e3));

            case LengthUnit::Megameter:
                return (value * static_cast<un_scalar_t>(1e6));

            case LengthUnit::Gigameter:
                return (value * static_cast<un_scalar_t>(1e9));

            case LengthUnit::Mile:
                return value * static_cast<un_scalar_t>(1609.344);

            case LengthUnit::Yard:
                return value * static_cast<un_scalar_t>(0.9144);

            case LengthUnit::Kiloyard:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.9144);

            case LengthUnit::Foot:
                return value * static_cast<un_scalar_t>(0.3048);

            case LengthUnit::Kilofoot:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.3048);

            case LengthUnit::UsSurveyFoot:
                return value * static_cast<un_scalar_t>(1200) / static_cast<un_scalar_t>(3937);

            case LengthUnit::Inch:
                return value * static_cast<un_scalar_t>(2.54e-2);

            case LengthUnit::Mil:
                return value * static_cast<un_scalar_t>(2.54e-5);

            case LengthUnit::NauticalMile:
                return value * static_cast<un_scalar_t>(1852);

            case LengthUnit::Fathom:
                return value * static_cast<un_scalar_t>(1.8288);

            case LengthUnit::Shackle:
                return value * static_cast<un_scalar_t>(27.432);

            case LengthUnit::Microinch:
                return value * static_cast<un_scalar_t>(2.54e-8);

            case LengthUnit::PrinterPoint:
                return value * static_cast<un_scalar_t>(2.54e-2) / static_cast<un_scalar_t>(72.27) ;

            case LengthUnit::DtpPoint:
                return value * static_cast<un_scalar_t>(2.54e-2) / static_cast<un_scalar_t>(72);

            case LengthUnit::PrinterPica:
                return value * static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(400) / static_cast<un_scalar_t>(2409);

            case LengthUnit::DtpPica:
                return value * static_cast<un_scalar_t>(2.54e-2) / static_cast<un_scalar_t>(6);

            case LengthUnit::Twip:
                return value * static_cast<un_scalar_t>(2.54e-2) / static_cast<un_scalar_t>(1440);

            case LengthUnit::Hand:
                return value * static_cast<un_scalar_t>(1.016e-1);

            case LengthUnit::AstronomicalUnit:
                return value * static_cast<un_scalar_t>(1.4959787070e11);

            case LengthUnit::Parsec:
                return value * static_cast<un_scalar_t>(3.08567758128e16);

            case LengthUnit::Kiloparsec:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(3.08567758128e16);

            case LengthUnit::Megaparsec:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(3.08567758128e16);

            case LengthUnit::LightYear:
                return value * static_cast<un_scalar_t>(9.46073047258e15);

            case LengthUnit::KilolightYear:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(9.46073047258e15);

            case LengthUnit::MegalightYear:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(9.46073047258e15);

            case LengthUnit::SolarRadius:
                return value * static_cast<un_scalar_t>(6.95700e8);

            case LengthUnit::Chain:
                return value * static_cast<un_scalar_t>(20.1168);

            case LengthUnit::Angstrom:
                return value * static_cast<un_scalar_t>(1e-10);

            case LengthUnit::DataMile:
                return value * static_cast<un_scalar_t>(1828.8);

            }

            throw std::invalid_argument("Unknown Length unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const LengthUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case LengthUnit::Meter:
                return base_value;

            case LengthUnit::Femtometer:
                return (base_value) / static_cast<un_scalar_t>(1e-15);

            case LengthUnit::Picometer:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case LengthUnit::Nanometer:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case LengthUnit::Micrometer:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case LengthUnit::Millimeter:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case LengthUnit::Centimeter:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case LengthUnit::Decimeter:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case LengthUnit::Decameter:
                return (base_value) / static_cast<un_scalar_t>(1e1);

            case LengthUnit::Hectometer:
                return (base_value) / static_cast<un_scalar_t>(1e2);

            case LengthUnit::Kilometer:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case LengthUnit::Megameter:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case LengthUnit::Gigameter:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case LengthUnit::Mile:
                return base_value / static_cast<un_scalar_t>(1609.344);

            case LengthUnit::Yard:
                return base_value / static_cast<un_scalar_t>(0.9144);

            case LengthUnit::Kiloyard:
                return (base_value / static_cast<un_scalar_t>(0.9144)) / static_cast<un_scalar_t>(1e3);

            case LengthUnit::Foot:
                return base_value / static_cast<un_scalar_t>(0.3048);

            case LengthUnit::Kilofoot:
                return (base_value / static_cast<un_scalar_t>(0.3048)) / static_cast<un_scalar_t>(1e3);

            case LengthUnit::UsSurveyFoot:
                return base_value * static_cast<un_scalar_t>(3937) / static_cast<un_scalar_t>(1200);

            case LengthUnit::Inch:
                return base_value / static_cast<un_scalar_t>(2.54e-2);

            case LengthUnit::Mil:
                return base_value / static_cast<un_scalar_t>(2.54e-5);

            case LengthUnit::NauticalMile:
                return base_value / static_cast<un_scalar_t>(1852);

            case LengthUnit::Fathom:
                return base_value / static_cast<un_scalar_t>(1.8288);

            case LengthUnit::Shackle:
                return base_value / static_cast<un_scalar_t>(27.432);

            case LengthUnit::Microinch:
                return base_value / static_cast<un_scalar_t>(2.54e-8);

            case LengthUnit::PrinterPoint:
                return base_value * static_cast<un_scalar_t>(72.27) / static_cast<un_scalar_t>(2.54e-2);

            case LengthUnit::DtpPoint:
                return base_value * static_cast<un_scalar_t>(72) / static_cast<un_scalar_t>(2.54e-2);

            case LengthUnit::PrinterPica:
                return base_value / (static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(400) / static_cast<un_scalar_t>(2409));

            case LengthUnit::DtpPica:
                return base_value * static_cast<un_scalar_t>(6) / static_cast<un_scalar_t>(2.54e-2);

            case LengthUnit::Twip:
                return base_value * static_cast<un_scalar_t>(1440) / static_cast<un_scalar_t>(2.54e-2);

            case LengthUnit::Hand:
                return base_value / static_cast<un_scalar_t>(1.016e-1);

            case LengthUnit::AstronomicalUnit:
                return base_value / static_cast<un_scalar_t>(1.4959787070e11);

            case LengthUnit::Parsec:
                return base_value / static_cast<un_scalar_t>(3.08567758128e16);

            case LengthUnit::Kiloparsec:
                return (base_value / static_cast<un_scalar_t>(3.08567758128e16)) / static_cast<un_scalar_t>(1e3);

            case LengthUnit::Megaparsec:
                return (base_value / static_cast<un_scalar_t>(3.08567758128e16)) / static_cast<un_scalar_t>(1e6);

            case LengthUnit::LightYear:
                return base_value / static_cast<un_scalar_t>(9.46073047258e15);

            case LengthUnit::KilolightYear:
                return (base_value / static_cast<un_scalar_t>(9.46073047258e15)) / static_cast<un_scalar_t>(1e3);

            case LengthUnit::MegalightYear:
                return (base_value / static_cast<un_scalar_t>(9.46073047258e15)) / static_cast<un_scalar_t>(1e6);

            case LengthUnit::SolarRadius:
                return base_value / static_cast<un_scalar_t>(6.95700e8);

            case LengthUnit::Chain:
                return base_value / static_cast<un_scalar_t>(20.1168);

            case LengthUnit::Angstrom:
                return base_value / static_cast<un_scalar_t>(1e-10);

            case LengthUnit::DataMile:
                return base_value / static_cast<un_scalar_t>(1828.8);

            }

            throw std::invalid_argument("Unknown Length unit.");
        }

        un_scalar_t value_;
        LengthUnit value_unit_type_;       
    };
}
