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
    enum class VolumeUnit : std::uint8_t
    {
        Liter,
        Nanoliter,
        Microliter,
        Milliliter,
        Centiliter,
        Deciliter,
        Decaliter,
        Hectoliter,
        Kiloliter,
        Megaliter,
        CubicMeter,
        HectocubicMeter,
        KilocubicMeter,
        CubicKilometer,
        CubicHectometer,
        CubicDecimeter,
        CubicCentimeter,
        CubicMillimeter,
        CubicMicrometer,
        CubicMile,
        CubicYard,
        CubicFoot,
        HectocubicFoot,
        KilocubicFoot,
        MegacubicFoot,
        CubicInch,
        ImperialGallon,
        KiloimperialGallon,
        MegaimperialGallon,
        ImperialOunce,
        UsGallon,
        DecausGallon,
        DeciusGallon,
        HectousGallon,
        KilousGallon,
        MegausGallon,
        UsOunce,
        UsTablespoon,
        AuTablespoon,
        MetricTablespoon,
        UkTablespoon,
        MetricTeaspoon,
        UsTeaspoon,
        MetricCup,
        UsCustomaryCup,
        UsLegalCup,
        OilBarrel,
        UsBeerBarrel,
        ImperialBeerBarrel,
        UsQuart,
        ImperialQuart,
        UsPint,
        AcreFoot,
        ImperialPint,
        BoardFoot,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Volume.</summary>
    class VolumeDto
    {
    public:
        constexpr VolumeDto() noexcept
            : value{}, unit(VolumeUnit::CubicMeter)
        {
        }

        constexpr VolumeDto(
            const un_scalar_t value,
            const VolumeUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        VolumeUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr VolumeUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<VolumeUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Volume unit name.");
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
        [[nodiscard]] static VolumeDto from_json(const nlohmann::json& json)
        {
            return VolumeDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Volume is the quantity of three-dimensional space enclosed by some closed boundary, for example, the space that a substance (solid, liquid, gas, or plasma) or shape occupies or contains.[1] Volume is often quantified numerically using the SI derived unit, the cubic metre. The volume of a container is generally understood to be the capacity of the container, i. e. the amount of fluid (gas or liquid) that the container could hold, rather than the amount of space the container itself displaces.</summary>
    class Volume : public UnitsNetBase
    {
    public:
        constexpr explicit Volume(
            const un_scalar_t value,
            const VolumeUnit unit = VolumeUnit::CubicMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const VolumeUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr VolumeDto to_dto(
            const VolumeUnit unit = VolumeUnit::CubicMeter) const
        {
            return VolumeDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Volume from_dto(const VolumeDto& dto)
        {
            return Volume(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const VolumeUnit unit = VolumeUnit::CubicMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Volume from_json(const nlohmann::json& json)
        {
            return from_dto(VolumeDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Volume operator+(const Volume& other) const noexcept
        {
            return Volume(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Volume operator-(const Volume& other)const noexcept
        {
            return Volume(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Volume operator*(const un_scalar_t scalar) const noexcept
        {
            return Volume(base_value() * scalar);
        }

        [[nodiscard]] constexpr Volume operator/(const un_scalar_t scalar) const noexcept
        {
            return Volume(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Volume& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Volume& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Volume& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t liters() const
        {
            return convert_from_base(VolumeUnit::Liter);
        }

        [[nodiscard]] static constexpr Volume from_liters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::Liter);
        }

        [[nodiscard]] constexpr un_scalar_t nanoliters() const
        {
            return convert_from_base(VolumeUnit::Nanoliter);
        }

        [[nodiscard]] static constexpr Volume from_nanoliters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::Nanoliter);
        }

        [[nodiscard]] constexpr un_scalar_t microliters() const
        {
            return convert_from_base(VolumeUnit::Microliter);
        }

        [[nodiscard]] static constexpr Volume from_microliters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::Microliter);
        }

        [[nodiscard]] constexpr un_scalar_t milliliters() const
        {
            return convert_from_base(VolumeUnit::Milliliter);
        }

        [[nodiscard]] static constexpr Volume from_milliliters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::Milliliter);
        }

        [[nodiscard]] constexpr un_scalar_t centiliters() const
        {
            return convert_from_base(VolumeUnit::Centiliter);
        }

        [[nodiscard]] static constexpr Volume from_centiliters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::Centiliter);
        }

        [[nodiscard]] constexpr un_scalar_t deciliters() const
        {
            return convert_from_base(VolumeUnit::Deciliter);
        }

        [[nodiscard]] static constexpr Volume from_deciliters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::Deciliter);
        }

        [[nodiscard]] constexpr un_scalar_t decaliters() const
        {
            return convert_from_base(VolumeUnit::Decaliter);
        }

        [[nodiscard]] static constexpr Volume from_decaliters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::Decaliter);
        }

        [[nodiscard]] constexpr un_scalar_t hectoliters() const
        {
            return convert_from_base(VolumeUnit::Hectoliter);
        }

        [[nodiscard]] static constexpr Volume from_hectoliters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::Hectoliter);
        }

        [[nodiscard]] constexpr un_scalar_t kiloliters() const
        {
            return convert_from_base(VolumeUnit::Kiloliter);
        }

        [[nodiscard]] static constexpr Volume from_kiloliters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::Kiloliter);
        }

        [[nodiscard]] constexpr un_scalar_t megaliters() const
        {
            return convert_from_base(VolumeUnit::Megaliter);
        }

        [[nodiscard]] static constexpr Volume from_megaliters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::Megaliter);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_meters() const
        {
            return convert_from_base(VolumeUnit::CubicMeter);
        }

        [[nodiscard]] static constexpr Volume from_cubic_meters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t hectocubic_meters() const
        {
            return convert_from_base(VolumeUnit::HectocubicMeter);
        }

        [[nodiscard]] static constexpr Volume from_hectocubic_meters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::HectocubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilocubic_meters() const
        {
            return convert_from_base(VolumeUnit::KilocubicMeter);
        }

        [[nodiscard]] static constexpr Volume from_kilocubic_meters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::KilocubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_kilometers() const
        {
            return convert_from_base(VolumeUnit::CubicKilometer);
        }

        [[nodiscard]] static constexpr Volume from_cubic_kilometers(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicKilometer);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_hectometers() const
        {
            return convert_from_base(VolumeUnit::CubicHectometer);
        }

        [[nodiscard]] static constexpr Volume from_cubic_hectometers(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicHectometer);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_decimeters() const
        {
            return convert_from_base(VolumeUnit::CubicDecimeter);
        }

        [[nodiscard]] static constexpr Volume from_cubic_decimeters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicDecimeter);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_centimeters() const
        {
            return convert_from_base(VolumeUnit::CubicCentimeter);
        }

        [[nodiscard]] static constexpr Volume from_cubic_centimeters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_millimeters() const
        {
            return convert_from_base(VolumeUnit::CubicMillimeter);
        }

        [[nodiscard]] static constexpr Volume from_cubic_millimeters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_micrometers() const
        {
            return convert_from_base(VolumeUnit::CubicMicrometer);
        }

        [[nodiscard]] static constexpr Volume from_cubic_micrometers(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicMicrometer);
        }

        /// <summary>A cubic mile (abbreviation: cu mi or mi3) is an imperial and US customary (non-SI non-metric) unit of volume, used in the United States, Canada and the United Kingdom. It is defined as the volume of a cube with sides of 1 mile (63360 inches, 5280 feet, 1760 yards or ~1.609 kilometres) in length.</summary>
        [[nodiscard]] constexpr un_scalar_t cubic_miles() const
        {
            return convert_from_base(VolumeUnit::CubicMile);
        }

        /// <summary>A cubic mile (abbreviation: cu mi or mi3) is an imperial and US customary (non-SI non-metric) unit of volume, used in the United States, Canada and the United Kingdom. It is defined as the volume of a cube with sides of 1 mile (63360 inches, 5280 feet, 1760 yards or ~1.609 kilometres) in length.</summary>
        [[nodiscard]] static constexpr Volume from_cubic_miles(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicMile);
        }

        /// <summary>A cubic yard is an Imperial / U.S. customary (non-SI non-metric) unit of volume, used in Canada and the United States. It is defined as the volume of a cube with sides of 1 yard (3 feet, 36 inches, 0.9144 meters) in length.</summary>
        [[nodiscard]] constexpr un_scalar_t cubic_yards() const
        {
            return convert_from_base(VolumeUnit::CubicYard);
        }

        /// <summary>A cubic yard is an Imperial / U.S. customary (non-SI non-metric) unit of volume, used in Canada and the United States. It is defined as the volume of a cube with sides of 1 yard (3 feet, 36 inches, 0.9144 meters) in length.</summary>
        [[nodiscard]] static constexpr Volume from_cubic_yards(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicYard);
        }

        /// <summary>The cubic foot (symbol ft3 or cu ft) is an imperial and US customary (non-metric) unit of volume, used in the United States and the United Kingdom. It is defined as the volume of a cube with sides of one foot (0.3048 m) in length.</summary>
        [[nodiscard]] constexpr un_scalar_t cubic_feet() const
        {
            return convert_from_base(VolumeUnit::CubicFoot);
        }

        /// <summary>The cubic foot (symbol ft3 or cu ft) is an imperial and US customary (non-metric) unit of volume, used in the United States and the United Kingdom. It is defined as the volume of a cube with sides of one foot (0.3048 m) in length.</summary>
        [[nodiscard]] static constexpr Volume from_cubic_feet(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicFoot);
        }

        /// <summary>The cubic foot (symbol ft3 or cu ft) is an imperial and US customary (non-metric) unit of volume, used in the United States and the United Kingdom. It is defined as the volume of a cube with sides of one foot (0.3048 m) in length.</summary>
        [[nodiscard]] constexpr un_scalar_t hectocubic_feet() const
        {
            return convert_from_base(VolumeUnit::HectocubicFoot);
        }

        /// <summary>The cubic foot (symbol ft3 or cu ft) is an imperial and US customary (non-metric) unit of volume, used in the United States and the United Kingdom. It is defined as the volume of a cube with sides of one foot (0.3048 m) in length.</summary>
        [[nodiscard]] static constexpr Volume from_hectocubic_feet(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::HectocubicFoot);
        }

        /// <summary>The cubic foot (symbol ft3 or cu ft) is an imperial and US customary (non-metric) unit of volume, used in the United States and the United Kingdom. It is defined as the volume of a cube with sides of one foot (0.3048 m) in length.</summary>
        [[nodiscard]] constexpr un_scalar_t kilocubic_feet() const
        {
            return convert_from_base(VolumeUnit::KilocubicFoot);
        }

        /// <summary>The cubic foot (symbol ft3 or cu ft) is an imperial and US customary (non-metric) unit of volume, used in the United States and the United Kingdom. It is defined as the volume of a cube with sides of one foot (0.3048 m) in length.</summary>
        [[nodiscard]] static constexpr Volume from_kilocubic_feet(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::KilocubicFoot);
        }

        /// <summary>The cubic foot (symbol ft3 or cu ft) is an imperial and US customary (non-metric) unit of volume, used in the United States and the United Kingdom. It is defined as the volume of a cube with sides of one foot (0.3048 m) in length.</summary>
        [[nodiscard]] constexpr un_scalar_t megacubic_feet() const
        {
            return convert_from_base(VolumeUnit::MegacubicFoot);
        }

        /// <summary>The cubic foot (symbol ft3 or cu ft) is an imperial and US customary (non-metric) unit of volume, used in the United States and the United Kingdom. It is defined as the volume of a cube with sides of one foot (0.3048 m) in length.</summary>
        [[nodiscard]] static constexpr Volume from_megacubic_feet(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::MegacubicFoot);
        }

        /// <summary>The cubic inch (symbol in3) is a unit of volume in the Imperial units and United States customary units systems. It is the volume of a cube with each of its three dimensions (length, width, and height) being one inch long which is equivalent to 1/231 of a US gallon.</summary>
        [[nodiscard]] constexpr un_scalar_t cubic_inches() const
        {
            return convert_from_base(VolumeUnit::CubicInch);
        }

        /// <summary>The cubic inch (symbol in3) is a unit of volume in the Imperial units and United States customary units systems. It is the volume of a cube with each of its three dimensions (length, width, and height) being one inch long which is equivalent to 1/231 of a US gallon.</summary>
        [[nodiscard]] static constexpr Volume from_cubic_inches(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicInch);
        }

        /// <summary>The British imperial gallon (frequently called simply "gallon") is defined as exactly 4.54609 litres.</summary>
        [[nodiscard]] constexpr un_scalar_t imperial_gallons() const
        {
            return convert_from_base(VolumeUnit::ImperialGallon);
        }

        /// <summary>The British imperial gallon (frequently called simply "gallon") is defined as exactly 4.54609 litres.</summary>
        [[nodiscard]] static constexpr Volume from_imperial_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::ImperialGallon);
        }

        /// <summary>The British imperial gallon (frequently called simply "gallon") is defined as exactly 4.54609 litres.</summary>
        [[nodiscard]] constexpr un_scalar_t kiloimperial_gallons() const
        {
            return convert_from_base(VolumeUnit::KiloimperialGallon);
        }

        /// <summary>The British imperial gallon (frequently called simply "gallon") is defined as exactly 4.54609 litres.</summary>
        [[nodiscard]] static constexpr Volume from_kiloimperial_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::KiloimperialGallon);
        }

        /// <summary>The British imperial gallon (frequently called simply "gallon") is defined as exactly 4.54609 litres.</summary>
        [[nodiscard]] constexpr un_scalar_t megaimperial_gallons() const
        {
            return convert_from_base(VolumeUnit::MegaimperialGallon);
        }

        /// <summary>The British imperial gallon (frequently called simply "gallon") is defined as exactly 4.54609 litres.</summary>
        [[nodiscard]] static constexpr Volume from_megaimperial_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::MegaimperialGallon);
        }

        /// <summary>An imperial fluid ounce is 1⁄20 of an imperial pint, 1⁄160 of an imperial gallon or exactly 28.4130625 mL.</summary>
        [[nodiscard]] constexpr un_scalar_t imperial_ounces() const
        {
            return convert_from_base(VolumeUnit::ImperialOunce);
        }

        /// <summary>An imperial fluid ounce is 1⁄20 of an imperial pint, 1⁄160 of an imperial gallon or exactly 28.4130625 mL.</summary>
        [[nodiscard]] static constexpr Volume from_imperial_ounces(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::ImperialOunce);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] constexpr un_scalar_t us_gallons() const
        {
            return convert_from_base(VolumeUnit::UsGallon);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] static constexpr Volume from_us_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsGallon);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] constexpr un_scalar_t decaus_gallons() const
        {
            return convert_from_base(VolumeUnit::DecausGallon);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] static constexpr Volume from_decaus_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::DecausGallon);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] constexpr un_scalar_t decius_gallons() const
        {
            return convert_from_base(VolumeUnit::DeciusGallon);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] static constexpr Volume from_decius_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::DeciusGallon);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] constexpr un_scalar_t hectous_gallons() const
        {
            return convert_from_base(VolumeUnit::HectousGallon);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] static constexpr Volume from_hectous_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::HectousGallon);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] constexpr un_scalar_t kilous_gallons() const
        {
            return convert_from_base(VolumeUnit::KilousGallon);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] static constexpr Volume from_kilous_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::KilousGallon);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] constexpr un_scalar_t megaus_gallons() const
        {
            return convert_from_base(VolumeUnit::MegausGallon);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] static constexpr Volume from_megaus_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::MegausGallon);
        }

        /// <summary>A US customary fluid ounce is 1⁄16 of a US liquid pint and 1⁄128 of a US liquid gallon or exactly 29.5735295625 mL, making it about 4.08% larger than the imperial fluid ounce.</summary>
        [[nodiscard]] constexpr un_scalar_t us_ounces() const
        {
            return convert_from_base(VolumeUnit::UsOunce);
        }

        /// <summary>A US customary fluid ounce is 1⁄16 of a US liquid pint and 1⁄128 of a US liquid gallon or exactly 29.5735295625 mL, making it about 4.08% larger than the imperial fluid ounce.</summary>
        [[nodiscard]] static constexpr Volume from_us_ounces(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsOunce);
        }

        /// <summary>The traditional U.S. interpretation of the tablespoon as a unit of volume is: 1 US tablespoon = 4 fluid drams, or 3 teaspoons or 1/2 US fluid ounce (≈ 14.8 ml)</summary>
        [[nodiscard]] constexpr un_scalar_t us_tablespoons() const
        {
            return convert_from_base(VolumeUnit::UsTablespoon);
        }

        /// <summary>The traditional U.S. interpretation of the tablespoon as a unit of volume is: 1 US tablespoon = 4 fluid drams, or 3 teaspoons or 1/2 US fluid ounce (≈ 14.8 ml)</summary>
        [[nodiscard]] static constexpr Volume from_us_tablespoons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsTablespoon);
        }

        /// <summary>In Australia, the definition of the tablespoon is 20 ml (0.70 imp fl oz).</summary>
        [[nodiscard]] constexpr un_scalar_t au_tablespoons() const
        {
            return convert_from_base(VolumeUnit::AuTablespoon);
        }

        /// <summary>In Australia, the definition of the tablespoon is 20 ml (0.70 imp fl oz).</summary>
        [[nodiscard]] static constexpr Volume from_au_tablespoons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::AuTablespoon);
        }

        /// <summary>An international metric tablespoon is exactly equal to 15 mL. It is the equivalence of 1⁠ 1/2 metric dessert spoons or 3 metric teaspoons.</summary>
        [[nodiscard]] constexpr un_scalar_t metric_tablespoons() const
        {
            return convert_from_base(VolumeUnit::MetricTablespoon);
        }

        /// <summary>An international metric tablespoon is exactly equal to 15 mL. It is the equivalence of 1⁠ 1/2 metric dessert spoons or 3 metric teaspoons.</summary>
        [[nodiscard]] static constexpr Volume from_metric_tablespoons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::MetricTablespoon);
        }

        /// <summary>In nutrition labeling in the U.S. and the U.K., a tablespoon is defined as 15 ml (0.51 US fl oz). In Australia, the definition of the tablespoon is 20 ml (0.70 imp fl oz).</summary>
        [[nodiscard]] constexpr un_scalar_t uk_tablespoons() const
        {
            return convert_from_base(VolumeUnit::UkTablespoon);
        }

        /// <summary>In nutrition labeling in the U.S. and the U.K., a tablespoon is defined as 15 ml (0.51 US fl oz). In Australia, the definition of the tablespoon is 20 ml (0.70 imp fl oz).</summary>
        [[nodiscard]] static constexpr Volume from_uk_tablespoons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UkTablespoon);
        }

        /// <summary>The metric teaspoon as a unit of culinary measure is 5 ml (0.18 imp fl oz; 0.17 US fl oz),[17] equal to 5 cm3, 1⁄3 UK/Canadian metric tablespoon, or 1⁄4 Australian metric tablespoon.</summary>
        [[nodiscard]] constexpr un_scalar_t metric_teaspoons() const
        {
            return convert_from_base(VolumeUnit::MetricTeaspoon);
        }

        /// <summary>The metric teaspoon as a unit of culinary measure is 5 ml (0.18 imp fl oz; 0.17 US fl oz),[17] equal to 5 cm3, 1⁄3 UK/Canadian metric tablespoon, or 1⁄4 Australian metric tablespoon.</summary>
        [[nodiscard]] static constexpr Volume from_metric_teaspoons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::MetricTeaspoon);
        }

        /// <summary>As a unit of culinary measure, one teaspoon in the United States is 1⁄3 tablespoon, exactly 4.92892159375 ml, 1 1⁄3 US fluid drams, 1⁄6 US fl oz, 1⁄48 US cup, 1⁄768 US liquid gallon, or 77⁄256 (0.30078125) cubic inches.</summary>
        [[nodiscard]] constexpr un_scalar_t us_teaspoons() const
        {
            return convert_from_base(VolumeUnit::UsTeaspoon);
        }

        /// <summary>As a unit of culinary measure, one teaspoon in the United States is 1⁄3 tablespoon, exactly 4.92892159375 ml, 1 1⁄3 US fluid drams, 1⁄6 US fl oz, 1⁄48 US cup, 1⁄768 US liquid gallon, or 77⁄256 (0.30078125) cubic inches.</summary>
        [[nodiscard]] static constexpr Volume from_us_teaspoons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsTeaspoon);
        }

        /// <summary>Australia, Canada, New Zealand, and some other members of the Commonwealth of Nations, being former British colonies that have since metricated, employ a metric cup of 250 millilitres. Although derived from the metric system, it is not an SI unit.</summary>
        [[nodiscard]] constexpr un_scalar_t metric_cups() const
        {
            return convert_from_base(VolumeUnit::MetricCup);
        }

        /// <summary>Australia, Canada, New Zealand, and some other members of the Commonwealth of Nations, being former British colonies that have since metricated, employ a metric cup of 250 millilitres. Although derived from the metric system, it is not an SI unit.</summary>
        [[nodiscard]] static constexpr Volume from_metric_cups(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::MetricCup);
        }

        /// <summary>In the United States, the customary cup is half of a liquid pint or 1⁄16 US customary gallon which is 236.5882365 milliliters exactly.</summary>
        [[nodiscard]] constexpr un_scalar_t us_customary_cups() const
        {
            return convert_from_base(VolumeUnit::UsCustomaryCup);
        }

        /// <summary>In the United States, the customary cup is half of a liquid pint or 1⁄16 US customary gallon which is 236.5882365 milliliters exactly.</summary>
        [[nodiscard]] static constexpr Volume from_us_customary_cups(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsCustomaryCup);
        }

        /// <summary>The cup currently used in the United States for nutrition labelling is defined in United States law as 240 ml.</summary>
        [[nodiscard]] constexpr un_scalar_t us_legal_cups() const
        {
            return convert_from_base(VolumeUnit::UsLegalCup);
        }

        /// <summary>The cup currently used in the United States for nutrition labelling is defined in United States law as 240 ml.</summary>
        [[nodiscard]] static constexpr Volume from_us_legal_cups(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsLegalCup);
        }

        /// <summary>In the oil industry, one barrel (unit symbol bbl) is a unit of volume used for measuring oil defined as exactly 42 US gallons, approximately 159 liters, or 35 imperial gallons.</summary>
        [[nodiscard]] constexpr un_scalar_t oil_barrels() const
        {
            return convert_from_base(VolumeUnit::OilBarrel);
        }

        /// <summary>In the oil industry, one barrel (unit symbol bbl) is a unit of volume used for measuring oil defined as exactly 42 US gallons, approximately 159 liters, or 35 imperial gallons.</summary>
        [[nodiscard]] static constexpr Volume from_oil_barrels(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::OilBarrel);
        }

        /// <summary>Fluid barrels vary depending on what is being measured and where. In the US most fluid barrels (apart from oil) are 31.5 US gallons (26 imp gal; 119 L) (half a hogshead), but a beer barrel is 31 US gallons (26 imp gal; 117 L).</summary>
        [[nodiscard]] constexpr un_scalar_t us_beer_barrels() const
        {
            return convert_from_base(VolumeUnit::UsBeerBarrel);
        }

        /// <summary>Fluid barrels vary depending on what is being measured and where. In the US most fluid barrels (apart from oil) are 31.5 US gallons (26 imp gal; 119 L) (half a hogshead), but a beer barrel is 31 US gallons (26 imp gal; 117 L).</summary>
        [[nodiscard]] static constexpr Volume from_us_beer_barrels(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsBeerBarrel);
        }

        /// <summary>Fluid barrels vary depending on what is being measured and where. In the UK a beer barrel is 36 imperial gallons (43 US gal; ~164 L).</summary>
        [[nodiscard]] constexpr un_scalar_t imperial_beer_barrels() const
        {
            return convert_from_base(VolumeUnit::ImperialBeerBarrel);
        }

        /// <summary>Fluid barrels vary depending on what is being measured and where. In the UK a beer barrel is 36 imperial gallons (43 US gal; ~164 L).</summary>
        [[nodiscard]] static constexpr Volume from_imperial_beer_barrels(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::ImperialBeerBarrel);
        }

        /// <summary>The US liquid quart equals 57.75 cubic inches, which is exactly equal to 0.946352946 L.</summary>
        [[nodiscard]] constexpr un_scalar_t us_quarts() const
        {
            return convert_from_base(VolumeUnit::UsQuart);
        }

        /// <summary>The US liquid quart equals 57.75 cubic inches, which is exactly equal to 0.946352946 L.</summary>
        [[nodiscard]] static constexpr Volume from_us_quarts(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsQuart);
        }

        /// <summary>The imperial quart, which is used for both liquid and dry capacity, is equal to one quarter of an imperial gallon, or exactly 1.1365225 liters.</summary>
        [[nodiscard]] constexpr un_scalar_t imperial_quarts() const
        {
            return convert_from_base(VolumeUnit::ImperialQuart);
        }

        /// <summary>The imperial quart, which is used for both liquid and dry capacity, is equal to one quarter of an imperial gallon, or exactly 1.1365225 liters.</summary>
        [[nodiscard]] static constexpr Volume from_imperial_quarts(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::ImperialQuart);
        }

        /// <summary>The pint is a unit of volume or capacity in both the imperial and United States customary measurement systems. In both of those systems it is traditionally one eighth of a gallon. The British imperial pint is about 20% larger than the American pint because the two systems are defined differently.</summary>
        [[nodiscard]] constexpr un_scalar_t us_pints() const
        {
            return convert_from_base(VolumeUnit::UsPint);
        }

        /// <summary>The pint is a unit of volume or capacity in both the imperial and United States customary measurement systems. In both of those systems it is traditionally one eighth of a gallon. The British imperial pint is about 20% larger than the American pint because the two systems are defined differently.</summary>
        [[nodiscard]] static constexpr Volume from_us_pints(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsPint);
        }

        /// <summary>An acre-foot is 43,560 cubic feet (~1,233.5 m3).</summary>
        [[nodiscard]] constexpr un_scalar_t acre_feet() const
        {
            return convert_from_base(VolumeUnit::AcreFoot);
        }

        /// <summary>An acre-foot is 43,560 cubic feet (~1,233.5 m3).</summary>
        [[nodiscard]] static constexpr Volume from_acre_feet(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::AcreFoot);
        }

        /// <summary>The pint is a unit of volume or capacity in both the imperial and United States customary measurement systems. In both of those systems it is traditionally one eighth of a gallon. The British imperial pint is about 20% larger than the American pint because the two systems are defined differently.</summary>
        [[nodiscard]] constexpr un_scalar_t imperial_pints() const
        {
            return convert_from_base(VolumeUnit::ImperialPint);
        }

        /// <summary>The pint is a unit of volume or capacity in both the imperial and United States customary measurement systems. In both of those systems it is traditionally one eighth of a gallon. The British imperial pint is about 20% larger than the American pint because the two systems are defined differently.</summary>
        [[nodiscard]] static constexpr Volume from_imperial_pints(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::ImperialPint);
        }

        /// <summary>The board foot or board-foot is a unit of measurement for the volume of lumber in the United States and Canada. It equals the volume of a board that is one-foot (305 mm) in length, one-foot (305 mm) in width, and one-inch (25.4 mm) in thickness.</summary>
        [[nodiscard]] constexpr un_scalar_t board_feet() const
        {
            return convert_from_base(VolumeUnit::BoardFoot);
        }

        /// <summary>The board foot or board-foot is a unit of measurement for the volume of lumber in the United States and Canada. It equals the volume of a board that is one-foot (305 mm) in length, one-foot (305 mm) in width, and one-inch (25.4 mm) in thickness.</summary>
        [[nodiscard]] static constexpr Volume from_board_feet(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::BoardFoot);
        }

        [[nodiscard]] static constexpr Volume from_invalid()
        {
            return Volume(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, VolumeUnit unit)
        {
            switch (unit)
            {

            case VolumeUnit::Liter:
                return value / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Nanoliter:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Microliter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Milliliter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Centiliter:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Deciliter:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Decaliter:
                return (value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Hectoliter:
                return (value * static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Kiloliter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Megaliter:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::CubicMeter:
                return value;

            case VolumeUnit::HectocubicMeter:
                return (value * static_cast<un_scalar_t>(1e2));

            case VolumeUnit::KilocubicMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case VolumeUnit::CubicKilometer:
                return value * static_cast<un_scalar_t>(1e9);

            case VolumeUnit::CubicHectometer:
                return value * static_cast<un_scalar_t>(1e6);

            case VolumeUnit::CubicDecimeter:
                return value / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::CubicCentimeter:
                return value / static_cast<un_scalar_t>(1e6);

            case VolumeUnit::CubicMillimeter:
                return value / static_cast<un_scalar_t>(1e9);

            case VolumeUnit::CubicMicrometer:
                return value / static_cast<un_scalar_t>(1e18);

            case VolumeUnit::CubicMile:
                return value * static_cast<un_scalar_t>(4.168181825440579584e9);

            case VolumeUnit::CubicYard:
                return value * static_cast<un_scalar_t>(0.764554857984);

            case VolumeUnit::CubicFoot:
                return value * static_cast<un_scalar_t>(0.028316846592);

            case VolumeUnit::HectocubicFoot:
                return (value * static_cast<un_scalar_t>(1e2)) * static_cast<un_scalar_t>(0.028316846592);

            case VolumeUnit::KilocubicFoot:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.028316846592);

            case VolumeUnit::MegacubicFoot:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.028316846592);

            case VolumeUnit::CubicInch:
                return value * static_cast<un_scalar_t>(1.6387064e-5);

            case VolumeUnit::ImperialGallon:
                return value * static_cast<un_scalar_t>(0.00454609);

            case VolumeUnit::KiloimperialGallon:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.00454609);

            case VolumeUnit::MegaimperialGallon:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.00454609);

            case VolumeUnit::ImperialOunce:
                return value * static_cast<un_scalar_t>(2.84130625e-5);

            case VolumeUnit::UsGallon:
                return value * static_cast<un_scalar_t>(0.003785411784);

            case VolumeUnit::DecausGallon:
                return (value * static_cast<un_scalar_t>(1e1)) * static_cast<un_scalar_t>(0.003785411784);

            case VolumeUnit::DeciusGallon:
                return (value * static_cast<un_scalar_t>(1e-1)) * static_cast<un_scalar_t>(0.003785411784);

            case VolumeUnit::HectousGallon:
                return (value * static_cast<un_scalar_t>(1e2)) * static_cast<un_scalar_t>(0.003785411784);

            case VolumeUnit::KilousGallon:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.003785411784);

            case VolumeUnit::MegausGallon:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.003785411784);

            case VolumeUnit::UsOunce:
                return value * static_cast<un_scalar_t>(2.95735295625e-5);

            case VolumeUnit::UsTablespoon:
                return value * static_cast<un_scalar_t>(1.478676478125e-5);

            case VolumeUnit::AuTablespoon:
                return value * static_cast<un_scalar_t>(2e-5);

            case VolumeUnit::MetricTablespoon:
                return value * static_cast<un_scalar_t>(1.5e-5);

            case VolumeUnit::UkTablespoon:
                return value * static_cast<un_scalar_t>(1.5e-5);

            case VolumeUnit::MetricTeaspoon:
                return value * static_cast<un_scalar_t>(0.5e-5);

            case VolumeUnit::UsTeaspoon:
                return value * static_cast<un_scalar_t>(4.92892159375e-6);

            case VolumeUnit::MetricCup:
                return value * static_cast<un_scalar_t>(0.00025);

            case VolumeUnit::UsCustomaryCup:
                return value * static_cast<un_scalar_t>(0.0002365882365);

            case VolumeUnit::UsLegalCup:
                return value * static_cast<un_scalar_t>(0.00024);

            case VolumeUnit::OilBarrel:
                return value * static_cast<un_scalar_t>(0.158987294928);

            case VolumeUnit::UsBeerBarrel:
                return value * static_cast<un_scalar_t>(0.117347765304);

            case VolumeUnit::ImperialBeerBarrel:
                return value * static_cast<un_scalar_t>(0.16365924);

            case VolumeUnit::UsQuart:
                return value * static_cast<un_scalar_t>(9.46352946e-4);

            case VolumeUnit::ImperialQuart:
                return value * static_cast<un_scalar_t>(1.1365225e-3);

            case VolumeUnit::UsPint:
                return value * static_cast<un_scalar_t>(4.73176473e-4);

            case VolumeUnit::AcreFoot:
                return value * static_cast<un_scalar_t>(1233.48183754752);

            case VolumeUnit::ImperialPint:
                return value * static_cast<un_scalar_t>(5.6826125e-4);

            case VolumeUnit::BoardFoot:
                return value * (static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(12));

            }

            throw std::invalid_argument("Unknown Volume unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const VolumeUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case VolumeUnit::Liter:
                return base_value * static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Nanoliter:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-9);

            case VolumeUnit::Microliter:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-6);

            case VolumeUnit::Milliliter:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case VolumeUnit::Centiliter:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-2);

            case VolumeUnit::Deciliter:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-1);

            case VolumeUnit::Decaliter:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e1);

            case VolumeUnit::Hectoliter:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e2);

            case VolumeUnit::Kiloliter:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Megaliter:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e6);

            case VolumeUnit::CubicMeter:
                return base_value;

            case VolumeUnit::HectocubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e2);

            case VolumeUnit::KilocubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::CubicKilometer:
                return base_value / static_cast<un_scalar_t>(1e9);

            case VolumeUnit::CubicHectometer:
                return base_value / static_cast<un_scalar_t>(1e6);

            case VolumeUnit::CubicDecimeter:
                return base_value * static_cast<un_scalar_t>(1e3);

            case VolumeUnit::CubicCentimeter:
                return base_value * static_cast<un_scalar_t>(1e6);

            case VolumeUnit::CubicMillimeter:
                return base_value * static_cast<un_scalar_t>(1e9);

            case VolumeUnit::CubicMicrometer:
                return base_value * static_cast<un_scalar_t>(1e18);

            case VolumeUnit::CubicMile:
                return base_value / static_cast<un_scalar_t>(4.168181825440579584e9);

            case VolumeUnit::CubicYard:
                return base_value / static_cast<un_scalar_t>(0.764554857984);

            case VolumeUnit::CubicFoot:
                return base_value / static_cast<un_scalar_t>(0.028316846592);

            case VolumeUnit::HectocubicFoot:
                return (base_value / static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e2);

            case VolumeUnit::KilocubicFoot:
                return (base_value / static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::MegacubicFoot:
                return (base_value / static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e6);

            case VolumeUnit::CubicInch:
                return base_value / static_cast<un_scalar_t>(1.6387064e-5);

            case VolumeUnit::ImperialGallon:
                return base_value / static_cast<un_scalar_t>(0.00454609);

            case VolumeUnit::KiloimperialGallon:
                return (base_value / static_cast<un_scalar_t>(0.00454609)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::MegaimperialGallon:
                return (base_value / static_cast<un_scalar_t>(0.00454609)) / static_cast<un_scalar_t>(1e6);

            case VolumeUnit::ImperialOunce:
                return base_value / static_cast<un_scalar_t>(2.84130625e-5);

            case VolumeUnit::UsGallon:
                return base_value / static_cast<un_scalar_t>(0.003785411784);

            case VolumeUnit::DecausGallon:
                return (base_value / static_cast<un_scalar_t>(0.003785411784)) / static_cast<un_scalar_t>(1e1);

            case VolumeUnit::DeciusGallon:
                return (base_value / static_cast<un_scalar_t>(0.003785411784)) / static_cast<un_scalar_t>(1e-1);

            case VolumeUnit::HectousGallon:
                return (base_value / static_cast<un_scalar_t>(0.003785411784)) / static_cast<un_scalar_t>(1e2);

            case VolumeUnit::KilousGallon:
                return (base_value / static_cast<un_scalar_t>(0.003785411784)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::MegausGallon:
                return (base_value / static_cast<un_scalar_t>(0.003785411784)) / static_cast<un_scalar_t>(1e6);

            case VolumeUnit::UsOunce:
                return base_value / static_cast<un_scalar_t>(2.95735295625e-5);

            case VolumeUnit::UsTablespoon:
                return base_value / static_cast<un_scalar_t>(1.478676478125e-5);

            case VolumeUnit::AuTablespoon:
                return base_value / static_cast<un_scalar_t>(2e-5);

            case VolumeUnit::MetricTablespoon:
                return base_value / static_cast<un_scalar_t>(1.5e-5);

            case VolumeUnit::UkTablespoon:
                return base_value / static_cast<un_scalar_t>(1.5e-5);

            case VolumeUnit::MetricTeaspoon:
                return base_value / static_cast<un_scalar_t>(0.5e-5);

            case VolumeUnit::UsTeaspoon:
                return base_value / static_cast<un_scalar_t>(4.92892159375e-6);

            case VolumeUnit::MetricCup:
                return base_value / static_cast<un_scalar_t>(0.00025);

            case VolumeUnit::UsCustomaryCup:
                return base_value / static_cast<un_scalar_t>(0.0002365882365);

            case VolumeUnit::UsLegalCup:
                return base_value / static_cast<un_scalar_t>(0.00024);

            case VolumeUnit::OilBarrel:
                return base_value / static_cast<un_scalar_t>(0.158987294928);

            case VolumeUnit::UsBeerBarrel:
                return base_value / static_cast<un_scalar_t>(0.117347765304);

            case VolumeUnit::ImperialBeerBarrel:
                return base_value / static_cast<un_scalar_t>(0.16365924);

            case VolumeUnit::UsQuart:
                return base_value / static_cast<un_scalar_t>(9.46352946e-4);

            case VolumeUnit::ImperialQuart:
                return base_value / static_cast<un_scalar_t>(1.1365225e-3);

            case VolumeUnit::UsPint:
                return base_value / static_cast<un_scalar_t>(4.73176473e-4);

            case VolumeUnit::AcreFoot:
                return base_value / static_cast<un_scalar_t>(1233.48183754752);

            case VolumeUnit::ImperialPint:
                return base_value / static_cast<un_scalar_t>(5.6826125e-4);

            case VolumeUnit::BoardFoot:
                return base_value / (static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(12));

            }

            throw std::invalid_argument("Unknown Volume unit.");
        }

        un_scalar_t value_;
        VolumeUnit value_unit_type_;       
    };
}
