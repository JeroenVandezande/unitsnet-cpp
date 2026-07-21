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
    enum class MassUnit : std::uint8_t
    {
        Gram,
        Femtogram,
        Picogram,
        Nanogram,
        Microgram,
        Milligram,
        Centigram,
        Decigram,
        Decagram,
        Hectogram,
        Kilogram,
        Tonne,
        Kilotonne,
        Megatonne,
        ShortTon,
        LongTon,
        Pound,
        Kilopound,
        Megapound,
        Ounce,
        Slug,
        Stone,
        ShortHundredweight,
        LongHundredweight,
        Grain,
        SolarMass,
        EarthMass,
        Dalton,
        Kilodalton,
        Megadalton,
        Gigadalton,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Mass.</summary>
    class MassDto
    {
    public:
        constexpr MassDto() noexcept
            : value{}, unit(MassUnit::Kilogram)
        {
        }

        constexpr MassDto(
            const un_scalar_t value,
            const MassUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        MassUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr MassUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<MassUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Mass unit name.");
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
        [[nodiscard]] static MassDto from_json(const nlohmann::json& json)
        {
            return MassDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In physics, mass (from Greek μᾶζα "barley cake, lump [of dough]") is a property of a physical system or body, giving rise to the phenomena of the body's resistance to being accelerated by a force and the strength of its mutual gravitational attraction with other bodies. Instruments such as mass balances or scales use those phenomena to measure mass. The SI unit of mass is the kilogram (kg).</summary>
    class Mass : public UnitsNetBase
    {
    public:
        constexpr explicit Mass(
            const un_scalar_t value,
            const MassUnit unit = MassUnit::Kilogram)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MassUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr MassDto to_dto(
            const MassUnit unit = MassUnit::Kilogram) const
        {
            return MassDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Mass from_dto(const MassDto& dto)
        {
            return Mass(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const MassUnit unit = MassUnit::Kilogram) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Mass from_json(const nlohmann::json& json)
        {
            return from_dto(MassDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Mass operator+(const Mass& other) const noexcept
        {
            return Mass(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Mass operator-(const Mass& other)const noexcept
        {
            return Mass(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Mass operator*(const un_scalar_t scalar) const noexcept
        {
            return Mass(base_value() * scalar);
        }

        [[nodiscard]] constexpr Mass operator/(const un_scalar_t scalar) const noexcept
        {
            return Mass(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Mass& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Mass& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Mass& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t grams() const
        {
            return convert_from_base(MassUnit::Gram);
        }

        [[nodiscard]] static constexpr Mass from_grams(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Gram);
        }

        [[nodiscard]] constexpr un_scalar_t femtograms() const
        {
            return convert_from_base(MassUnit::Femtogram);
        }

        [[nodiscard]] static constexpr Mass from_femtograms(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Femtogram);
        }

        [[nodiscard]] constexpr un_scalar_t picograms() const
        {
            return convert_from_base(MassUnit::Picogram);
        }

        [[nodiscard]] static constexpr Mass from_picograms(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Picogram);
        }

        [[nodiscard]] constexpr un_scalar_t nanograms() const
        {
            return convert_from_base(MassUnit::Nanogram);
        }

        [[nodiscard]] static constexpr Mass from_nanograms(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Nanogram);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms() const
        {
            return convert_from_base(MassUnit::Microgram);
        }

        [[nodiscard]] static constexpr Mass from_micrograms(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Microgram);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams() const
        {
            return convert_from_base(MassUnit::Milligram);
        }

        [[nodiscard]] static constexpr Mass from_milligrams(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Milligram);
        }

        [[nodiscard]] constexpr un_scalar_t centigrams() const
        {
            return convert_from_base(MassUnit::Centigram);
        }

        [[nodiscard]] static constexpr Mass from_centigrams(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Centigram);
        }

        [[nodiscard]] constexpr un_scalar_t decigrams() const
        {
            return convert_from_base(MassUnit::Decigram);
        }

        [[nodiscard]] static constexpr Mass from_decigrams(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Decigram);
        }

        [[nodiscard]] constexpr un_scalar_t decagrams() const
        {
            return convert_from_base(MassUnit::Decagram);
        }

        [[nodiscard]] static constexpr Mass from_decagrams(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Decagram);
        }

        [[nodiscard]] constexpr un_scalar_t hectograms() const
        {
            return convert_from_base(MassUnit::Hectogram);
        }

        [[nodiscard]] static constexpr Mass from_hectograms(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Hectogram);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms() const
        {
            return convert_from_base(MassUnit::Kilogram);
        }

        [[nodiscard]] static constexpr Mass from_kilograms(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Kilogram);
        }

        /// <summary>The tonne is a unit of mass equal to 1,000 kilograms. It is a non-SI unit accepted for use with SI. It is also referred to as a metric ton in the United States to distinguish it from the non-metric units of the short ton (United States customary units) and the long ton (British imperial units). It is equivalent to approximately 2,204.6 pounds, 1.102 short tons, and 0.984 long tons.</summary>
        [[nodiscard]] constexpr un_scalar_t tonnes() const
        {
            return convert_from_base(MassUnit::Tonne);
        }

        /// <summary>The tonne is a unit of mass equal to 1,000 kilograms. It is a non-SI unit accepted for use with SI. It is also referred to as a metric ton in the United States to distinguish it from the non-metric units of the short ton (United States customary units) and the long ton (British imperial units). It is equivalent to approximately 2,204.6 pounds, 1.102 short tons, and 0.984 long tons.</summary>
        [[nodiscard]] static constexpr Mass from_tonnes(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Tonne);
        }

        /// <summary>The tonne is a unit of mass equal to 1,000 kilograms. It is a non-SI unit accepted for use with SI. It is also referred to as a metric ton in the United States to distinguish it from the non-metric units of the short ton (United States customary units) and the long ton (British imperial units). It is equivalent to approximately 2,204.6 pounds, 1.102 short tons, and 0.984 long tons.</summary>
        [[nodiscard]] constexpr un_scalar_t kilotonnes() const
        {
            return convert_from_base(MassUnit::Kilotonne);
        }

        /// <summary>The tonne is a unit of mass equal to 1,000 kilograms. It is a non-SI unit accepted for use with SI. It is also referred to as a metric ton in the United States to distinguish it from the non-metric units of the short ton (United States customary units) and the long ton (British imperial units). It is equivalent to approximately 2,204.6 pounds, 1.102 short tons, and 0.984 long tons.</summary>
        [[nodiscard]] static constexpr Mass from_kilotonnes(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Kilotonne);
        }

        /// <summary>The tonne is a unit of mass equal to 1,000 kilograms. It is a non-SI unit accepted for use with SI. It is also referred to as a metric ton in the United States to distinguish it from the non-metric units of the short ton (United States customary units) and the long ton (British imperial units). It is equivalent to approximately 2,204.6 pounds, 1.102 short tons, and 0.984 long tons.</summary>
        [[nodiscard]] constexpr un_scalar_t megatonnes() const
        {
            return convert_from_base(MassUnit::Megatonne);
        }

        /// <summary>The tonne is a unit of mass equal to 1,000 kilograms. It is a non-SI unit accepted for use with SI. It is also referred to as a metric ton in the United States to distinguish it from the non-metric units of the short ton (United States customary units) and the long ton (British imperial units). It is equivalent to approximately 2,204.6 pounds, 1.102 short tons, and 0.984 long tons.</summary>
        [[nodiscard]] static constexpr Mass from_megatonnes(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Megatonne);
        }

        /// <summary>The short ton is a unit of mass equal to 2,000 pounds (907.18474 kg), that is most commonly used in the United States – known there simply as the ton.</summary>
        [[nodiscard]] constexpr un_scalar_t short_tons() const
        {
            return convert_from_base(MassUnit::ShortTon);
        }

        /// <summary>The short ton is a unit of mass equal to 2,000 pounds (907.18474 kg), that is most commonly used in the United States – known there simply as the ton.</summary>
        [[nodiscard]] static constexpr Mass from_short_tons(const un_scalar_t value)
        {
            return Mass(value, MassUnit::ShortTon);
        }

        /// <summary>Long ton (weight ton or Imperial ton) is a unit of mass equal to 2,240 pounds (1,016 kg) and is the name for the unit called the "ton" in the avoirdupois or Imperial system of measurements that was used in the United Kingdom and several other Commonwealth countries before metrication.</summary>
        [[nodiscard]] constexpr un_scalar_t long_tons() const
        {
            return convert_from_base(MassUnit::LongTon);
        }

        /// <summary>Long ton (weight ton or Imperial ton) is a unit of mass equal to 2,240 pounds (1,016 kg) and is the name for the unit called the "ton" in the avoirdupois or Imperial system of measurements that was used in the United Kingdom and several other Commonwealth countries before metrication.</summary>
        [[nodiscard]] static constexpr Mass from_long_tons(const un_scalar_t value)
        {
            return Mass(value, MassUnit::LongTon);
        }

        /// <summary>The pound or pound-mass (abbreviations: lb, lbm) is a unit of mass used in the imperial, United States customary and other systems of measurement. A number of different definitions have been used, the most common today being the international avoirdupois pound which is legally defined as exactly 0.45359237 kilograms, and which is divided into 16 avoirdupois ounces.</summary>
        [[nodiscard]] constexpr un_scalar_t pounds() const
        {
            return convert_from_base(MassUnit::Pound);
        }

        /// <summary>The pound or pound-mass (abbreviations: lb, lbm) is a unit of mass used in the imperial, United States customary and other systems of measurement. A number of different definitions have been used, the most common today being the international avoirdupois pound which is legally defined as exactly 0.45359237 kilograms, and which is divided into 16 avoirdupois ounces.</summary>
        [[nodiscard]] static constexpr Mass from_pounds(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Pound);
        }

        /// <summary>The pound or pound-mass (abbreviations: lb, lbm) is a unit of mass used in the imperial, United States customary and other systems of measurement. A number of different definitions have been used, the most common today being the international avoirdupois pound which is legally defined as exactly 0.45359237 kilograms, and which is divided into 16 avoirdupois ounces.</summary>
        [[nodiscard]] constexpr un_scalar_t kilopounds() const
        {
            return convert_from_base(MassUnit::Kilopound);
        }

        /// <summary>The pound or pound-mass (abbreviations: lb, lbm) is a unit of mass used in the imperial, United States customary and other systems of measurement. A number of different definitions have been used, the most common today being the international avoirdupois pound which is legally defined as exactly 0.45359237 kilograms, and which is divided into 16 avoirdupois ounces.</summary>
        [[nodiscard]] static constexpr Mass from_kilopounds(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Kilopound);
        }

        /// <summary>The pound or pound-mass (abbreviations: lb, lbm) is a unit of mass used in the imperial, United States customary and other systems of measurement. A number of different definitions have been used, the most common today being the international avoirdupois pound which is legally defined as exactly 0.45359237 kilograms, and which is divided into 16 avoirdupois ounces.</summary>
        [[nodiscard]] constexpr un_scalar_t megapounds() const
        {
            return convert_from_base(MassUnit::Megapound);
        }

        /// <summary>The pound or pound-mass (abbreviations: lb, lbm) is a unit of mass used in the imperial, United States customary and other systems of measurement. A number of different definitions have been used, the most common today being the international avoirdupois pound which is legally defined as exactly 0.45359237 kilograms, and which is divided into 16 avoirdupois ounces.</summary>
        [[nodiscard]] static constexpr Mass from_megapounds(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Megapound);
        }

        /// <summary>The international avoirdupois ounce (abbreviated oz) is defined as exactly 28.349523125 g under the international yard and pound agreement of 1959, signed by the United States and countries of the Commonwealth of Nations. 16 oz make up an avoirdupois pound.</summary>
        [[nodiscard]] constexpr un_scalar_t ounces() const
        {
            return convert_from_base(MassUnit::Ounce);
        }

        /// <summary>The international avoirdupois ounce (abbreviated oz) is defined as exactly 28.349523125 g under the international yard and pound agreement of 1959, signed by the United States and countries of the Commonwealth of Nations. 16 oz make up an avoirdupois pound.</summary>
        [[nodiscard]] static constexpr Mass from_ounces(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Ounce);
        }

        /// <summary>The slug (abbreviation slug) is a unit of mass that is accelerated by 1 ft/s² when a force of one pound (lbf) is exerted on it.</summary>
        [[nodiscard]] constexpr un_scalar_t slugs() const
        {
            return convert_from_base(MassUnit::Slug);
        }

        /// <summary>The slug (abbreviation slug) is a unit of mass that is accelerated by 1 ft/s² when a force of one pound (lbf) is exerted on it.</summary>
        [[nodiscard]] static constexpr Mass from_slugs(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Slug);
        }

        /// <summary>The stone (abbreviation st) is a unit of mass equal to 14 pounds avoirdupois (about 6.35 kilograms) used in Great Britain and Ireland for measuring human body weight.</summary>
        [[nodiscard]] constexpr un_scalar_t stone() const
        {
            return convert_from_base(MassUnit::Stone);
        }

        /// <summary>The stone (abbreviation st) is a unit of mass equal to 14 pounds avoirdupois (about 6.35 kilograms) used in Great Britain and Ireland for measuring human body weight.</summary>
        [[nodiscard]] static constexpr Mass from_stone(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Stone);
        }

        /// <summary>The short hundredweight (abbreviation cwt) is a unit of mass equal to 100 pounds in US and Canada. In British English, the short hundredweight is referred to as the "cental".</summary>
        [[nodiscard]] constexpr un_scalar_t short_hundredweight() const
        {
            return convert_from_base(MassUnit::ShortHundredweight);
        }

        /// <summary>The short hundredweight (abbreviation cwt) is a unit of mass equal to 100 pounds in US and Canada. In British English, the short hundredweight is referred to as the "cental".</summary>
        [[nodiscard]] static constexpr Mass from_short_hundredweight(const un_scalar_t value)
        {
            return Mass(value, MassUnit::ShortHundredweight);
        }

        /// <summary>The long or imperial hundredweight (abbreviation cwt) is a unit of mass equal to 112 pounds in US and Canada.</summary>
        [[nodiscard]] constexpr un_scalar_t long_hundredweight() const
        {
            return convert_from_base(MassUnit::LongHundredweight);
        }

        /// <summary>The long or imperial hundredweight (abbreviation cwt) is a unit of mass equal to 112 pounds in US and Canada.</summary>
        [[nodiscard]] static constexpr Mass from_long_hundredweight(const un_scalar_t value)
        {
            return Mass(value, MassUnit::LongHundredweight);
        }

        /// <summary>A grain is a unit of measurement of mass, and in the troy weight, avoirdupois, and Apothecaries' system, equal to exactly 64.79891 milligrams.</summary>
        [[nodiscard]] constexpr un_scalar_t grains() const
        {
            return convert_from_base(MassUnit::Grain);
        }

        /// <summary>A grain is a unit of measurement of mass, and in the troy weight, avoirdupois, and Apothecaries' system, equal to exactly 64.79891 milligrams.</summary>
        [[nodiscard]] static constexpr Mass from_grains(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Grain);
        }

        /// <summary>Solar mass is a ratio unit to the mass of the solar system star, the sun.</summary>
        [[nodiscard]] constexpr un_scalar_t solar_masses() const
        {
            return convert_from_base(MassUnit::SolarMass);
        }

        /// <summary>Solar mass is a ratio unit to the mass of the solar system star, the sun.</summary>
        [[nodiscard]] static constexpr Mass from_solar_masses(const un_scalar_t value)
        {
            return Mass(value, MassUnit::SolarMass);
        }

        /// <summary>Earth mass is a ratio unit to the mass of planet Earth.</summary>
        [[nodiscard]] constexpr un_scalar_t earth_masses() const
        {
            return convert_from_base(MassUnit::EarthMass);
        }

        /// <summary>Earth mass is a ratio unit to the mass of planet Earth.</summary>
        [[nodiscard]] static constexpr Mass from_earth_masses(const un_scalar_t value)
        {
            return Mass(value, MassUnit::EarthMass);
        }

        /// <summary>The Dalton or unified atomic mass unit (abbreviation Da or u) is a unit of mass defined as 1/12 of the mass of an unbound neutral atom of carbon-12 in its nuclear and electronic ground state and at rest.</summary>
        [[nodiscard]] constexpr un_scalar_t daltons() const
        {
            return convert_from_base(MassUnit::Dalton);
        }

        /// <summary>The Dalton or unified atomic mass unit (abbreviation Da or u) is a unit of mass defined as 1/12 of the mass of an unbound neutral atom of carbon-12 in its nuclear and electronic ground state and at rest.</summary>
        [[nodiscard]] static constexpr Mass from_daltons(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Dalton);
        }

        /// <summary>The Dalton or unified atomic mass unit (abbreviation Da or u) is a unit of mass defined as 1/12 of the mass of an unbound neutral atom of carbon-12 in its nuclear and electronic ground state and at rest.</summary>
        [[nodiscard]] constexpr un_scalar_t kilodaltons() const
        {
            return convert_from_base(MassUnit::Kilodalton);
        }

        /// <summary>The Dalton or unified atomic mass unit (abbreviation Da or u) is a unit of mass defined as 1/12 of the mass of an unbound neutral atom of carbon-12 in its nuclear and electronic ground state and at rest.</summary>
        [[nodiscard]] static constexpr Mass from_kilodaltons(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Kilodalton);
        }

        /// <summary>The Dalton or unified atomic mass unit (abbreviation Da or u) is a unit of mass defined as 1/12 of the mass of an unbound neutral atom of carbon-12 in its nuclear and electronic ground state and at rest.</summary>
        [[nodiscard]] constexpr un_scalar_t megadaltons() const
        {
            return convert_from_base(MassUnit::Megadalton);
        }

        /// <summary>The Dalton or unified atomic mass unit (abbreviation Da or u) is a unit of mass defined as 1/12 of the mass of an unbound neutral atom of carbon-12 in its nuclear and electronic ground state and at rest.</summary>
        [[nodiscard]] static constexpr Mass from_megadaltons(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Megadalton);
        }

        /// <summary>The Dalton or unified atomic mass unit (abbreviation Da or u) is a unit of mass defined as 1/12 of the mass of an unbound neutral atom of carbon-12 in its nuclear and electronic ground state and at rest.</summary>
        [[nodiscard]] constexpr un_scalar_t gigadaltons() const
        {
            return convert_from_base(MassUnit::Gigadalton);
        }

        /// <summary>The Dalton or unified atomic mass unit (abbreviation Da or u) is a unit of mass defined as 1/12 of the mass of an unbound neutral atom of carbon-12 in its nuclear and electronic ground state and at rest.</summary>
        [[nodiscard]] static constexpr Mass from_gigadaltons(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Gigadalton);
        }

        [[nodiscard]] static constexpr Mass from_invalid()
        {
            return Mass(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MassUnit unit)
        {
            switch (unit)
            {

            case MassUnit::Gram:
                return value / static_cast<un_scalar_t>(1e3);

            case MassUnit::Femtogram:
                return (value * static_cast<un_scalar_t>(1e-15)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Picogram:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Nanogram:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Microgram:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Milligram:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Centigram:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Decigram:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Decagram:
                return (value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Hectogram:
                return (value * static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Kilogram:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Tonne:
                return value * static_cast<un_scalar_t>(1e3);

            case MassUnit::Kilotonne:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e3);

            case MassUnit::Megatonne:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1e3);

            case MassUnit::ShortTon:
                return value * static_cast<un_scalar_t>(907.18474);

            case MassUnit::LongTon:
                return value * static_cast<un_scalar_t>(1016.0469088);

            case MassUnit::Pound:
                return value * static_cast<un_scalar_t>(0.45359237);

            case MassUnit::Kilopound:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.45359237);

            case MassUnit::Megapound:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.45359237);

            case MassUnit::Ounce:
                return value * static_cast<un_scalar_t>(0.028349523125);

            case MassUnit::Slug:
                return value * static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665) / static_cast<un_scalar_t>(0.3048);

            case MassUnit::Stone:
                return value * static_cast<un_scalar_t>(6.35029318);

            case MassUnit::ShortHundredweight:
                return value * static_cast<un_scalar_t>(45.359237);

            case MassUnit::LongHundredweight:
                return value * static_cast<un_scalar_t>(50.80234544);

            case MassUnit::Grain:
                return value * static_cast<un_scalar_t>(64.79891e-6);

            case MassUnit::SolarMass:
                return value * static_cast<un_scalar_t>(1.98947e30);

            case MassUnit::EarthMass:
                return value * static_cast<un_scalar_t>(5.9722E+24);

            case MassUnit::Dalton:
                return value *  static_cast<un_scalar_t>(1.66053906660e-27);

            case MassUnit::Kilodalton:
                return (value * static_cast<un_scalar_t>(1e3)) *  static_cast<un_scalar_t>(1.66053906660e-27);

            case MassUnit::Megadalton:
                return (value * static_cast<un_scalar_t>(1e6)) *  static_cast<un_scalar_t>(1.66053906660e-27);

            case MassUnit::Gigadalton:
                return (value * static_cast<un_scalar_t>(1e9)) *  static_cast<un_scalar_t>(1.66053906660e-27);

            }

            throw std::invalid_argument("Unknown Mass unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MassUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case MassUnit::Gram:
                return base_value * static_cast<un_scalar_t>(1e3);

            case MassUnit::Femtogram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-15);

            case MassUnit::Picogram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-12);

            case MassUnit::Nanogram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-9);

            case MassUnit::Microgram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-6);

            case MassUnit::Milligram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case MassUnit::Centigram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-2);

            case MassUnit::Decigram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-1);

            case MassUnit::Decagram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e1);

            case MassUnit::Hectogram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e2);

            case MassUnit::Kilogram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Tonne:
                return base_value / static_cast<un_scalar_t>(1e3);

            case MassUnit::Kilotonne:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Megatonne:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e6);

            case MassUnit::ShortTon:
                return base_value / static_cast<un_scalar_t>(907.18474);

            case MassUnit::LongTon:
                return base_value / static_cast<un_scalar_t>(1016.0469088);

            case MassUnit::Pound:
                return base_value / static_cast<un_scalar_t>(0.45359237);

            case MassUnit::Kilopound:
                return (base_value / static_cast<un_scalar_t>(0.45359237)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Megapound:
                return (base_value / static_cast<un_scalar_t>(0.45359237)) / static_cast<un_scalar_t>(1e6);

            case MassUnit::Ounce:
                return base_value / static_cast<un_scalar_t>(0.028349523125);

            case MassUnit::Slug:
                return base_value * static_cast<un_scalar_t>(0.3048) / (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665));

            case MassUnit::Stone:
                return base_value / static_cast<un_scalar_t>(6.35029318);

            case MassUnit::ShortHundredweight:
                return base_value / static_cast<un_scalar_t>(45.359237);

            case MassUnit::LongHundredweight:
                return base_value / static_cast<un_scalar_t>(50.80234544);

            case MassUnit::Grain:
                return base_value / static_cast<un_scalar_t>(64.79891e-6);

            case MassUnit::SolarMass:
                return base_value / static_cast<un_scalar_t>(1.98947e30);

            case MassUnit::EarthMass:
                return base_value / static_cast<un_scalar_t>(5.9722E+24);

            case MassUnit::Dalton:
                return base_value /  static_cast<un_scalar_t>(1.66053906660e-27);

            case MassUnit::Kilodalton:
                return (base_value /  static_cast<un_scalar_t>(1.66053906660e-27)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Megadalton:
                return (base_value /  static_cast<un_scalar_t>(1.66053906660e-27)) / static_cast<un_scalar_t>(1e6);

            case MassUnit::Gigadalton:
                return (base_value /  static_cast<un_scalar_t>(1.66053906660e-27)) / static_cast<un_scalar_t>(1e9);

            }

            throw std::invalid_argument("Unknown Mass unit.");
        }

        un_scalar_t value_;
        MassUnit value_unit_type_;       
    };
}
