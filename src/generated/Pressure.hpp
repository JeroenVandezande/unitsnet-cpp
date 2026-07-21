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
    enum class PressureUnit : std::uint8_t
    {
        Pascal,
        Micropascal,
        Millipascal,
        Decapascal,
        Hectopascal,
        Kilopascal,
        Megapascal,
        Gigapascal,
        Atmosphere,
        Bar,
        Microbar,
        Millibar,
        Centibar,
        Decibar,
        Kilobar,
        Megabar,
        KilogramForcePerSquareMeter,
        KilogramForcePerSquareCentimeter,
        KilogramForcePerSquareMillimeter,
        NewtonPerSquareMeter,
        KilonewtonPerSquareMeter,
        MeganewtonPerSquareMeter,
        NewtonPerSquareCentimeter,
        KilonewtonPerSquareCentimeter,
        NewtonPerSquareMillimeter,
        KilonewtonPerSquareMillimeter,
        TechnicalAtmosphere,
        Torr,
        Millitorr,
        PoundForcePerSquareInch,
        KilopoundForcePerSquareInch,
        PoundForcePerSquareMil,
        KilopoundForcePerSquareMil,
        PoundForcePerSquareFoot,
        KilopoundForcePerSquareFoot,
        TonneForcePerSquareMillimeter,
        TonneForcePerSquareMeter,
        MeterOfHead,
        TonneForcePerSquareCentimeter,
        FootOfHead,
        MillimeterOfMercury,
        InchOfMercury,
        DynePerSquareCentimeter,
        PoundPerInchSecondSquared,
        MeterOfWaterColumn,
        MillimeterOfWaterColumn,
        CentimeterOfWaterColumn,
        InchOfWaterColumn,
        MilligramForcePerSquareMeter,
        MilligramForcePerSquareFoot,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Pressure.</summary>
    class PressureDto
    {
    public:
        constexpr PressureDto() noexcept
            : value{}, unit(PressureUnit::Pascal)
        {
        }

        constexpr PressureDto(
            const un_scalar_t value,
            const PressureUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        PressureUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr PressureUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<PressureUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Pressure unit name.");
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
        [[nodiscard]] static PressureDto from_json(const nlohmann::json& json)
        {
            return PressureDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Pressure (symbol: P or p) is the ratio of force to the area over which that force is distributed. Pressure is force per unit area applied in a direction perpendicular to the surface of an object. Gauge pressure (also spelled gage pressure)[a] is the pressure relative to the local atmospheric or ambient pressure. Pressure is measured in any unit of force divided by any unit of area. The SI unit of pressure is the newton per square metre, which is called the pascal (Pa) after the seventeenth-century philosopher and scientist Blaise Pascal. A pressure of 1 Pa is small; it approximately equals the pressure exerted by a dollar bill resting flat on a table. Everyday pressures are often stated in kilopascals (1 kPa = 1000 Pa).</summary>
    class Pressure : public UnitsNetBase
    {
    public:
        constexpr explicit Pressure(
            const un_scalar_t value,
            const PressureUnit unit = PressureUnit::Pascal)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const PressureUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr PressureDto to_dto(
            const PressureUnit unit = PressureUnit::Pascal) const
        {
            return PressureDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Pressure from_dto(const PressureDto& dto)
        {
            return Pressure(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const PressureUnit unit = PressureUnit::Pascal) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Pressure from_json(const nlohmann::json& json)
        {
            return from_dto(PressureDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Pressure operator+(const Pressure& other) const noexcept
        {
            return Pressure(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Pressure operator-(const Pressure& other)const noexcept
        {
            return Pressure(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Pressure operator*(const un_scalar_t scalar) const noexcept
        {
            return Pressure(base_value() * scalar);
        }

        [[nodiscard]] constexpr Pressure operator/(const un_scalar_t scalar) const noexcept
        {
            return Pressure(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Pressure& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Pressure& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Pressure& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t pascals() const
        {
            return convert_from_base(PressureUnit::Pascal);
        }

        [[nodiscard]] static constexpr Pressure from_pascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Pascal);
        }

        [[nodiscard]] constexpr un_scalar_t micropascals() const
        {
            return convert_from_base(PressureUnit::Micropascal);
        }

        [[nodiscard]] static constexpr Pressure from_micropascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Micropascal);
        }

        [[nodiscard]] constexpr un_scalar_t millipascals() const
        {
            return convert_from_base(PressureUnit::Millipascal);
        }

        [[nodiscard]] static constexpr Pressure from_millipascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Millipascal);
        }

        [[nodiscard]] constexpr un_scalar_t decapascals() const
        {
            return convert_from_base(PressureUnit::Decapascal);
        }

        [[nodiscard]] static constexpr Pressure from_decapascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Decapascal);
        }

        [[nodiscard]] constexpr un_scalar_t hectopascals() const
        {
            return convert_from_base(PressureUnit::Hectopascal);
        }

        [[nodiscard]] static constexpr Pressure from_hectopascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Hectopascal);
        }

        [[nodiscard]] constexpr un_scalar_t kilopascals() const
        {
            return convert_from_base(PressureUnit::Kilopascal);
        }

        [[nodiscard]] static constexpr Pressure from_kilopascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Kilopascal);
        }

        [[nodiscard]] constexpr un_scalar_t megapascals() const
        {
            return convert_from_base(PressureUnit::Megapascal);
        }

        [[nodiscard]] static constexpr Pressure from_megapascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Megapascal);
        }

        [[nodiscard]] constexpr un_scalar_t gigapascals() const
        {
            return convert_from_base(PressureUnit::Gigapascal);
        }

        [[nodiscard]] static constexpr Pressure from_gigapascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Gigapascal);
        }

        /// <summary>The standard atmosphere (symbol: atm) is a unit of pressure defined as 101325 Pa. It is sometimes used as a reference pressure or standard pressure. It is approximately equal to Earth's average atmospheric pressure at sea level.</summary>
        [[nodiscard]] constexpr un_scalar_t atmospheres() const
        {
            return convert_from_base(PressureUnit::Atmosphere);
        }

        /// <summary>The standard atmosphere (symbol: atm) is a unit of pressure defined as 101325 Pa. It is sometimes used as a reference pressure or standard pressure. It is approximately equal to Earth's average atmospheric pressure at sea level.</summary>
        [[nodiscard]] static constexpr Pressure from_atmospheres(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Atmosphere);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] constexpr un_scalar_t bars() const
        {
            return convert_from_base(PressureUnit::Bar);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] static constexpr Pressure from_bars(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Bar);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] constexpr un_scalar_t microbars() const
        {
            return convert_from_base(PressureUnit::Microbar);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] static constexpr Pressure from_microbars(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Microbar);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] constexpr un_scalar_t millibars() const
        {
            return convert_from_base(PressureUnit::Millibar);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] static constexpr Pressure from_millibars(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Millibar);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] constexpr un_scalar_t centibars() const
        {
            return convert_from_base(PressureUnit::Centibar);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] static constexpr Pressure from_centibars(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Centibar);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] constexpr un_scalar_t decibars() const
        {
            return convert_from_base(PressureUnit::Decibar);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] static constexpr Pressure from_decibars(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Decibar);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] constexpr un_scalar_t kilobars() const
        {
            return convert_from_base(PressureUnit::Kilobar);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] static constexpr Pressure from_kilobars(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Kilobar);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] constexpr un_scalar_t megabars() const
        {
            return convert_from_base(PressureUnit::Megabar);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] static constexpr Pressure from_megabars(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Megabar);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_square_meter() const
        {
            return convert_from_base(PressureUnit::KilogramForcePerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilograms_force_per_square_meter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilogramForcePerSquareMeter);
        }

        /// <summary>A kilogram-force per centimetre square (kgf/cm2), often just kilogram per square centimetre (kg/cm2), or kilopond per centimetre square (kp/cm2) is a deprecated unit of pressure using metric units. It is not a part of the International System of Units (SI), the modern metric system. 1 kgf/cm2 equals 98.0665 kPa (kilopascals). It is also known as a technical atmosphere (symbol: at).</summary>
        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_square_centimeter() const
        {
            return convert_from_base(PressureUnit::KilogramForcePerSquareCentimeter);
        }

        /// <summary>A kilogram-force per centimetre square (kgf/cm2), often just kilogram per square centimetre (kg/cm2), or kilopond per centimetre square (kp/cm2) is a deprecated unit of pressure using metric units. It is not a part of the International System of Units (SI), the modern metric system. 1 kgf/cm2 equals 98.0665 kPa (kilopascals). It is also known as a technical atmosphere (symbol: at).</summary>
        [[nodiscard]] static constexpr Pressure from_kilograms_force_per_square_centimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilogramForcePerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_square_millimeter() const
        {
            return convert_from_base(PressureUnit::KilogramForcePerSquareMillimeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilograms_force_per_square_millimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilogramForcePerSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t newtons_per_square_meter() const
        {
            return convert_from_base(PressureUnit::NewtonPerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_newtons_per_square_meter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::NewtonPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_square_meter() const
        {
            return convert_from_base(PressureUnit::KilonewtonPerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilonewtons_per_square_meter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilonewtonPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t meganewtons_per_square_meter() const
        {
            return convert_from_base(PressureUnit::MeganewtonPerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_meganewtons_per_square_meter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::MeganewtonPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t newtons_per_square_centimeter() const
        {
            return convert_from_base(PressureUnit::NewtonPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Pressure from_newtons_per_square_centimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::NewtonPerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_square_centimeter() const
        {
            return convert_from_base(PressureUnit::KilonewtonPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilonewtons_per_square_centimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilonewtonPerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t newtons_per_square_millimeter() const
        {
            return convert_from_base(PressureUnit::NewtonPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr Pressure from_newtons_per_square_millimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::NewtonPerSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_square_millimeter() const
        {
            return convert_from_base(PressureUnit::KilonewtonPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilonewtons_per_square_millimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilonewtonPerSquareMillimeter);
        }

        /// <summary>A kilogram-force per centimetre square (kgf/cm2), often just kilogram per square centimetre (kg/cm2), or kilopond per centimetre square (kp/cm2) is a deprecated unit of pressure using metric units. It is not a part of the International System of Units (SI), the modern metric system. 1 kgf/cm2 equals 98.0665 kPa (kilopascals). It is also known as a technical atmosphere (symbol: at).</summary>
        [[nodiscard]] constexpr un_scalar_t technical_atmospheres() const
        {
            return convert_from_base(PressureUnit::TechnicalAtmosphere);
        }

        /// <summary>A kilogram-force per centimetre square (kgf/cm2), often just kilogram per square centimetre (kg/cm2), or kilopond per centimetre square (kp/cm2) is a deprecated unit of pressure using metric units. It is not a part of the International System of Units (SI), the modern metric system. 1 kgf/cm2 equals 98.0665 kPa (kilopascals). It is also known as a technical atmosphere (symbol: at).</summary>
        [[nodiscard]] static constexpr Pressure from_technical_atmospheres(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::TechnicalAtmosphere);
        }

        /// <summary>The torr (symbol: Torr) is a unit of pressure based on an absolute scale, defined as exactly 1/760 of a standard atmosphere (101325 Pa). Thus one torr is exactly 101325/760 pascals (≈ 133.32 Pa).</summary>
        [[nodiscard]] constexpr un_scalar_t torrs() const
        {
            return convert_from_base(PressureUnit::Torr);
        }

        /// <summary>The torr (symbol: Torr) is a unit of pressure based on an absolute scale, defined as exactly 1/760 of a standard atmosphere (101325 Pa). Thus one torr is exactly 101325/760 pascals (≈ 133.32 Pa).</summary>
        [[nodiscard]] static constexpr Pressure from_torrs(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Torr);
        }

        /// <summary>The torr (symbol: Torr) is a unit of pressure based on an absolute scale, defined as exactly 1/760 of a standard atmosphere (101325 Pa). Thus one torr is exactly 101325/760 pascals (≈ 133.32 Pa).</summary>
        [[nodiscard]] constexpr un_scalar_t millitorrs() const
        {
            return convert_from_base(PressureUnit::Millitorr);
        }

        /// <summary>The torr (symbol: Torr) is a unit of pressure based on an absolute scale, defined as exactly 1/760 of a standard atmosphere (101325 Pa). Thus one torr is exactly 101325/760 pascals (≈ 133.32 Pa).</summary>
        [[nodiscard]] static constexpr Pressure from_millitorrs(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Millitorr);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_per_square_inch() const
        {
            return convert_from_base(PressureUnit::PoundForcePerSquareInch);
        }

        [[nodiscard]] static constexpr Pressure from_pounds_force_per_square_inch(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::PoundForcePerSquareInch);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_square_inch() const
        {
            return convert_from_base(PressureUnit::KilopoundForcePerSquareInch);
        }

        [[nodiscard]] static constexpr Pressure from_kilopounds_force_per_square_inch(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilopoundForcePerSquareInch);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_per_square_mil() const
        {
            return convert_from_base(PressureUnit::PoundForcePerSquareMil);
        }

        [[nodiscard]] static constexpr Pressure from_pounds_force_per_square_mil(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::PoundForcePerSquareMil);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_square_mil() const
        {
            return convert_from_base(PressureUnit::KilopoundForcePerSquareMil);
        }

        [[nodiscard]] static constexpr Pressure from_kilopounds_force_per_square_mil(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilopoundForcePerSquareMil);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_per_square_foot() const
        {
            return convert_from_base(PressureUnit::PoundForcePerSquareFoot);
        }

        [[nodiscard]] static constexpr Pressure from_pounds_force_per_square_foot(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::PoundForcePerSquareFoot);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_square_foot() const
        {
            return convert_from_base(PressureUnit::KilopoundForcePerSquareFoot);
        }

        [[nodiscard]] static constexpr Pressure from_kilopounds_force_per_square_foot(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilopoundForcePerSquareFoot);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_square_millimeter() const
        {
            return convert_from_base(PressureUnit::TonneForcePerSquareMillimeter);
        }

        [[nodiscard]] static constexpr Pressure from_tonnes_force_per_square_millimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::TonneForcePerSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_square_meter() const
        {
            return convert_from_base(PressureUnit::TonneForcePerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_tonnes_force_per_square_meter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::TonneForcePerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t meters_of_head() const
        {
            return convert_from_base(PressureUnit::MeterOfHead);
        }

        [[nodiscard]] static constexpr Pressure from_meters_of_head(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::MeterOfHead);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_square_centimeter() const
        {
            return convert_from_base(PressureUnit::TonneForcePerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Pressure from_tonnes_force_per_square_centimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::TonneForcePerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t feet_of_head() const
        {
            return convert_from_base(PressureUnit::FootOfHead);
        }

        [[nodiscard]] static constexpr Pressure from_feet_of_head(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::FootOfHead);
        }

        /// <summary>A millimetre of mercury is a manometric unit of pressure, formerly defined as the extra pressure generated by a column of mercury one millimetre high, and currently defined as exactly 133.322387415 pascals.</summary>
        [[nodiscard]] constexpr un_scalar_t millimeters_of_mercury() const
        {
            return convert_from_base(PressureUnit::MillimeterOfMercury);
        }

        /// <summary>A millimetre of mercury is a manometric unit of pressure, formerly defined as the extra pressure generated by a column of mercury one millimetre high, and currently defined as exactly 133.322387415 pascals.</summary>
        [[nodiscard]] static constexpr Pressure from_millimeters_of_mercury(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::MillimeterOfMercury);
        }

        /// <summary>Inch of mercury (inHg and ″Hg) is a non-SI unit of measurement for pressure. It is used for barometric pressure in weather reports, refrigeration and aviation in the United States. It is the pressure exerted by a column of mercury 1 inch (25.4 mm) in height at the standard acceleration of gravity.</summary>
        [[nodiscard]] constexpr un_scalar_t inches_of_mercury() const
        {
            return convert_from_base(PressureUnit::InchOfMercury);
        }

        /// <summary>Inch of mercury (inHg and ″Hg) is a non-SI unit of measurement for pressure. It is used for barometric pressure in weather reports, refrigeration and aviation in the United States. It is the pressure exerted by a column of mercury 1 inch (25.4 mm) in height at the standard acceleration of gravity.</summary>
        [[nodiscard]] static constexpr Pressure from_inches_of_mercury(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::InchOfMercury);
        }

        [[nodiscard]] constexpr un_scalar_t dynes_per_square_centimeter() const
        {
            return convert_from_base(PressureUnit::DynePerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Pressure from_dynes_per_square_centimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::DynePerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_inch_second_squared() const
        {
            return convert_from_base(PressureUnit::PoundPerInchSecondSquared);
        }

        [[nodiscard]] static constexpr Pressure from_pounds_per_inch_second_squared(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::PoundPerInchSecondSquared);
        }

        /// <summary>A centimetre of water is defined as the pressure exerted by a column of water of 1 cm in height at 4 °C (temperature of maximum density) at the standard acceleration of gravity, so that 1 cmH2O (4°C) = 999.9720 kg/m3 × 9.80665 m/s2 × 1 cm = 98.063754138 Pa, but conventionally a nominal maximum water density of 1000 kg/m3 is used, giving 98.0665 Pa.</summary>
        [[nodiscard]] constexpr un_scalar_t meters_of_water_column() const
        {
            return convert_from_base(PressureUnit::MeterOfWaterColumn);
        }

        /// <summary>A centimetre of water is defined as the pressure exerted by a column of water of 1 cm in height at 4 °C (temperature of maximum density) at the standard acceleration of gravity, so that 1 cmH2O (4°C) = 999.9720 kg/m3 × 9.80665 m/s2 × 1 cm = 98.063754138 Pa, but conventionally a nominal maximum water density of 1000 kg/m3 is used, giving 98.0665 Pa.</summary>
        [[nodiscard]] static constexpr Pressure from_meters_of_water_column(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::MeterOfWaterColumn);
        }

        /// <summary>A centimetre of water is defined as the pressure exerted by a column of water of 1 cm in height at 4 °C (temperature of maximum density) at the standard acceleration of gravity, so that 1 cmH2O (4°C) = 999.9720 kg/m3 × 9.80665 m/s2 × 1 cm = 98.063754138 Pa, but conventionally a nominal maximum water density of 1000 kg/m3 is used, giving 98.0665 Pa.</summary>
        [[nodiscard]] constexpr un_scalar_t millimeters_of_water_column() const
        {
            return convert_from_base(PressureUnit::MillimeterOfWaterColumn);
        }

        /// <summary>A centimetre of water is defined as the pressure exerted by a column of water of 1 cm in height at 4 °C (temperature of maximum density) at the standard acceleration of gravity, so that 1 cmH2O (4°C) = 999.9720 kg/m3 × 9.80665 m/s2 × 1 cm = 98.063754138 Pa, but conventionally a nominal maximum water density of 1000 kg/m3 is used, giving 98.0665 Pa.</summary>
        [[nodiscard]] static constexpr Pressure from_millimeters_of_water_column(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::MillimeterOfWaterColumn);
        }

        /// <summary>A centimetre of water is defined as the pressure exerted by a column of water of 1 cm in height at 4 °C (temperature of maximum density) at the standard acceleration of gravity, so that 1 cmH2O (4°C) = 999.9720 kg/m3 × 9.80665 m/s2 × 1 cm = 98.063754138 Pa, but conventionally a nominal maximum water density of 1000 kg/m3 is used, giving 98.0665 Pa.</summary>
        [[nodiscard]] constexpr un_scalar_t centimeters_of_water_column() const
        {
            return convert_from_base(PressureUnit::CentimeterOfWaterColumn);
        }

        /// <summary>A centimetre of water is defined as the pressure exerted by a column of water of 1 cm in height at 4 °C (temperature of maximum density) at the standard acceleration of gravity, so that 1 cmH2O (4°C) = 999.9720 kg/m3 × 9.80665 m/s2 × 1 cm = 98.063754138 Pa, but conventionally a nominal maximum water density of 1000 kg/m3 is used, giving 98.0665 Pa.</summary>
        [[nodiscard]] static constexpr Pressure from_centimeters_of_water_column(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::CentimeterOfWaterColumn);
        }

        /// <summary>Inches of water is a non-SI unit for pressure. It is defined as the pressure exerted by a column of water of 1 inch in height at defined conditions. At a temperature of 4 °C (39.2 °F) pure water has its highest density (1000 kg/m3). At that temperature and assuming the standard acceleration of gravity, 1 inAq is approximately 249.082 pascals (0.0361263 psi).</summary>
        [[nodiscard]] constexpr un_scalar_t inches_of_water_column() const
        {
            return convert_from_base(PressureUnit::InchOfWaterColumn);
        }

        /// <summary>Inches of water is a non-SI unit for pressure. It is defined as the pressure exerted by a column of water of 1 inch in height at defined conditions. At a temperature of 4 °C (39.2 °F) pure water has its highest density (1000 kg/m3). At that temperature and assuming the standard acceleration of gravity, 1 inAq is approximately 249.082 pascals (0.0361263 psi).</summary>
        [[nodiscard]] static constexpr Pressure from_inches_of_water_column(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::InchOfWaterColumn);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_force_per_square_meter() const
        {
            return convert_from_base(PressureUnit::MilligramForcePerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_milligrams_force_per_square_meter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::MilligramForcePerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_force_per_square_foot() const
        {
            return convert_from_base(PressureUnit::MilligramForcePerSquareFoot);
        }

        [[nodiscard]] static constexpr Pressure from_milligrams_force_per_square_foot(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::MilligramForcePerSquareFoot);
        }

        [[nodiscard]] static constexpr Pressure from_invalid()
        {
            return Pressure(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, PressureUnit unit)
        {
            switch (unit)
            {

            case PressureUnit::Pascal:
                return value;

            case PressureUnit::Micropascal:
                return (value * static_cast<un_scalar_t>(1e-6));

            case PressureUnit::Millipascal:
                return (value * static_cast<un_scalar_t>(1e-3));

            case PressureUnit::Decapascal:
                return (value * static_cast<un_scalar_t>(1e1));

            case PressureUnit::Hectopascal:
                return (value * static_cast<un_scalar_t>(1e2));

            case PressureUnit::Kilopascal:
                return (value * static_cast<un_scalar_t>(1e3));

            case PressureUnit::Megapascal:
                return (value * static_cast<un_scalar_t>(1e6));

            case PressureUnit::Gigapascal:
                return (value * static_cast<un_scalar_t>(1e9));

            case PressureUnit::Atmosphere:
                return value * static_cast<un_scalar_t>(1.01325) * static_cast<un_scalar_t>(1e5);

            case PressureUnit::Bar:
                return value * static_cast<un_scalar_t>(1e5);

            case PressureUnit::Microbar:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(1e5);

            case PressureUnit::Millibar:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e5);

            case PressureUnit::Centibar:
                return (value * static_cast<un_scalar_t>(1e-2)) * static_cast<un_scalar_t>(1e5);

            case PressureUnit::Decibar:
                return (value * static_cast<un_scalar_t>(1e-1)) * static_cast<un_scalar_t>(1e5);

            case PressureUnit::Kilobar:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e5);

            case PressureUnit::Megabar:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1e5);

            case PressureUnit::KilogramForcePerSquareMeter:
                return value * static_cast<un_scalar_t>(9.80665);

            case PressureUnit::KilogramForcePerSquareCentimeter:
                return value * static_cast<un_scalar_t>(9.80665e4);

            case PressureUnit::KilogramForcePerSquareMillimeter:
                return value * static_cast<un_scalar_t>(9.80665e6);

            case PressureUnit::NewtonPerSquareMeter:
                return value;

            case PressureUnit::KilonewtonPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case PressureUnit::MeganewtonPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case PressureUnit::NewtonPerSquareCentimeter:
                return value * static_cast<un_scalar_t>(1e4);

            case PressureUnit::KilonewtonPerSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e4);

            case PressureUnit::NewtonPerSquareMillimeter:
                return value * static_cast<un_scalar_t>(1e6);

            case PressureUnit::KilonewtonPerSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e6);

            case PressureUnit::TechnicalAtmosphere:
                return value * static_cast<un_scalar_t>(9.80665e4);

            case PressureUnit::Torr:
                return value * static_cast<un_scalar_t>(101325) / static_cast<un_scalar_t>(760);

            case PressureUnit::Millitorr:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(101325) / static_cast<un_scalar_t>(760);

            case PressureUnit::PoundForcePerSquareInch:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516);

            case PressureUnit::KilopoundForcePerSquareInch:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516);

            case PressureUnit::PoundForcePerSquareMil:
                return value * static_cast<un_scalar_t>(4.4482216152605) / (static_cast<un_scalar_t>(2.54e-5) * static_cast<un_scalar_t>(2.54e-5));

            case PressureUnit::KilopoundForcePerSquareMil:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605) / (static_cast<un_scalar_t>(2.54e-5) * static_cast<un_scalar_t>(2.54e-5));

            case PressureUnit::PoundForcePerSquareFoot:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(9.290304e-2);

            case PressureUnit::KilopoundForcePerSquareFoot:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(9.290304e-2);

            case PressureUnit::TonneForcePerSquareMillimeter:
                return value * static_cast<un_scalar_t>(9.80665e9);

            case PressureUnit::TonneForcePerSquareMeter:
                return value * static_cast<un_scalar_t>(9.80665e3);

            case PressureUnit::MeterOfHead:
                return value * static_cast<un_scalar_t>(9804.139432);

            case PressureUnit::TonneForcePerSquareCentimeter:
                return value * static_cast<un_scalar_t>(9.80665e7);

            case PressureUnit::FootOfHead:
                return value * static_cast<un_scalar_t>(9804.139432) * static_cast<un_scalar_t>(0.3048);

            case PressureUnit::MillimeterOfMercury:
                return value * static_cast<un_scalar_t>(133.322387415);

            case PressureUnit::InchOfMercury:
                return value * static_cast<un_scalar_t>(2.54e1) * static_cast<un_scalar_t>(133.322387415);

            case PressureUnit::DynePerSquareCentimeter:
                return value * static_cast<un_scalar_t>(1.0e-1);

            case PressureUnit::PoundPerInchSecondSquared:
                return value * (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516)) / static_cast<un_scalar_t>(386.0886);

            case PressureUnit::MeterOfWaterColumn:
                return value * static_cast<un_scalar_t>(9.80665e3);

            case PressureUnit::MillimeterOfWaterColumn:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(9.80665e3);

            case PressureUnit::CentimeterOfWaterColumn:
                return (value * static_cast<un_scalar_t>(1e-2)) * static_cast<un_scalar_t>(9.80665e3);

            case PressureUnit::InchOfWaterColumn:
                return value * static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(9.80665e3);

            case PressureUnit::MilligramForcePerSquareMeter:
                return value * static_cast<un_scalar_t>(9.80665e-6);

            case PressureUnit::MilligramForcePerSquareFoot:
                return value * static_cast<un_scalar_t>(9.80665e-6) / static_cast<un_scalar_t>(9.290304e-2);

            }

            throw std::invalid_argument("Unknown Pressure unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const PressureUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case PressureUnit::Pascal:
                return base_value;

            case PressureUnit::Micropascal:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case PressureUnit::Millipascal:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case PressureUnit::Decapascal:
                return (base_value) / static_cast<un_scalar_t>(1e1);

            case PressureUnit::Hectopascal:
                return (base_value) / static_cast<un_scalar_t>(1e2);

            case PressureUnit::Kilopascal:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::Megapascal:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case PressureUnit::Gigapascal:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case PressureUnit::Atmosphere:
                return base_value / (static_cast<un_scalar_t>(1.01325) * static_cast<un_scalar_t>(1e5));

            case PressureUnit::Bar:
                return base_value / static_cast<un_scalar_t>(1e5);

            case PressureUnit::Microbar:
                return (base_value / static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e-6);

            case PressureUnit::Millibar:
                return (base_value / static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e-3);

            case PressureUnit::Centibar:
                return (base_value / static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e-2);

            case PressureUnit::Decibar:
                return (base_value / static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e-1);

            case PressureUnit::Kilobar:
                return (base_value / static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::Megabar:
                return (base_value / static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e6);

            case PressureUnit::KilogramForcePerSquareMeter:
                return base_value / static_cast<un_scalar_t>(9.80665);

            case PressureUnit::KilogramForcePerSquareCentimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e4);

            case PressureUnit::KilogramForcePerSquareMillimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e6);

            case PressureUnit::NewtonPerSquareMeter:
                return base_value;

            case PressureUnit::KilonewtonPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::MeganewtonPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case PressureUnit::NewtonPerSquareCentimeter:
                return base_value / static_cast<un_scalar_t>(1e4);

            case PressureUnit::KilonewtonPerSquareCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e4)) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::NewtonPerSquareMillimeter:
                return base_value / static_cast<un_scalar_t>(1e6);

            case PressureUnit::KilonewtonPerSquareMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::TechnicalAtmosphere:
                return base_value / static_cast<un_scalar_t>(9.80665e4);

            case PressureUnit::Torr:
                return base_value * static_cast<un_scalar_t>(760) / static_cast<un_scalar_t>(101325);

            case PressureUnit::Millitorr:
                return (base_value * static_cast<un_scalar_t>(760) / static_cast<un_scalar_t>(101325)) / static_cast<un_scalar_t>(1e-3);

            case PressureUnit::PoundForcePerSquareInch:
                return base_value * static_cast<un_scalar_t>(0.00064516) / static_cast<un_scalar_t>(4.4482216152605);

            case PressureUnit::KilopoundForcePerSquareInch:
                return (base_value * static_cast<un_scalar_t>(0.00064516) / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::PoundForcePerSquareMil:
                return base_value * (static_cast<un_scalar_t>(2.54e-5) * static_cast<un_scalar_t>(2.54e-5)) / static_cast<un_scalar_t>(4.4482216152605);

            case PressureUnit::KilopoundForcePerSquareMil:
                return (base_value * (static_cast<un_scalar_t>(2.54e-5) * static_cast<un_scalar_t>(2.54e-5)) / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::PoundForcePerSquareFoot:
                return base_value * static_cast<un_scalar_t>(9.290304e-2) / static_cast<un_scalar_t>(4.4482216152605);

            case PressureUnit::KilopoundForcePerSquareFoot:
                return (base_value * static_cast<un_scalar_t>(9.290304e-2) / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::TonneForcePerSquareMillimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e9);

            case PressureUnit::TonneForcePerSquareMeter:
                return base_value / static_cast<un_scalar_t>(9.80665e3);

            case PressureUnit::MeterOfHead:
                return base_value / static_cast<un_scalar_t>(9804.139432);

            case PressureUnit::TonneForcePerSquareCentimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e7);

            case PressureUnit::FootOfHead:
                return base_value / (static_cast<un_scalar_t>(9804.139432) * static_cast<un_scalar_t>(0.3048));

            case PressureUnit::MillimeterOfMercury:
                return base_value / static_cast<un_scalar_t>(133.322387415);

            case PressureUnit::InchOfMercury:
                return base_value / (static_cast<un_scalar_t>(2.54e1) * static_cast<un_scalar_t>(133.322387415));

            case PressureUnit::DynePerSquareCentimeter:
                return base_value / static_cast<un_scalar_t>(1.0e-1);

            case PressureUnit::PoundPerInchSecondSquared:
                return base_value * static_cast<un_scalar_t>(386.0886) / (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516));

            case PressureUnit::MeterOfWaterColumn:
                return base_value / static_cast<un_scalar_t>(9.80665e3);

            case PressureUnit::MillimeterOfWaterColumn:
                return (base_value / static_cast<un_scalar_t>(9.80665e3)) / static_cast<un_scalar_t>(1e-3);

            case PressureUnit::CentimeterOfWaterColumn:
                return (base_value / static_cast<un_scalar_t>(9.80665e3)) / static_cast<un_scalar_t>(1e-2);

            case PressureUnit::InchOfWaterColumn:
                return base_value / (static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(9.80665e3));

            case PressureUnit::MilligramForcePerSquareMeter:
                return base_value / static_cast<un_scalar_t>(9.80665e-6);

            case PressureUnit::MilligramForcePerSquareFoot:
                return base_value / static_cast<un_scalar_t>(9.80665e-6) * static_cast<un_scalar_t>(9.290304e-2);

            }

            throw std::invalid_argument("Unknown Pressure unit.");
        }

        un_scalar_t value_;
        PressureUnit value_unit_type_;       
    };
}
