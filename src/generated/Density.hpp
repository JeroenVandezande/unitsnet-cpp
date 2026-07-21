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
    enum class DensityUnit : std::uint8_t
    {
        GramPerCubicMillimeter,
        KilogramPerCubicMillimeter,
        GramPerCubicCentimeter,
        KilogramPerCubicCentimeter,
        GramPerCubicMeter,
        KilogramPerCubicMeter,
        MilligramPerCubicMeter,
        MicrogramPerCubicMeter,
        PoundPerCubicInch,
        KilopoundPerCubicInch,
        PoundPerCubicFoot,
        KilopoundPerCubicFoot,
        PoundPerCubicYard,
        KilopoundPerCubicYard,
        TonnePerCubicMillimeter,
        TonnePerCubicCentimeter,
        TonnePerCubicMeter,
        SlugPerCubicFoot,
        GramPerLiter,
        FemtogramPerLiter,
        PicogramPerLiter,
        NanogramPerLiter,
        MicrogramPerLiter,
        MilligramPerLiter,
        CentigramPerLiter,
        DecigramPerLiter,
        GramPerDeciliter,
        FemtogramPerDeciliter,
        PicogramPerDeciliter,
        NanogramPerDeciliter,
        MicrogramPerDeciliter,
        MilligramPerDeciliter,
        CentigramPerDeciliter,
        DecigramPerDeciliter,
        GramPerMilliliter,
        FemtogramPerMilliliter,
        PicogramPerMilliliter,
        NanogramPerMilliliter,
        MicrogramPerMilliliter,
        MilligramPerMilliliter,
        CentigramPerMilliliter,
        DecigramPerMilliliter,
        PoundPerUSGallon,
        PoundPerImperialGallon,
        KilogramPerLiter,
        TonnePerCubicFoot,
        TonnePerCubicInch,
        GramPerCubicFoot,
        GramPerCubicInch,
        PoundPerCubicMeter,
        PoundPerCubicCentimeter,
        PoundPerCubicMillimeter,
        SlugPerCubicMeter,
        SlugPerCubicCentimeter,
        SlugPerCubicMillimeter,
        SlugPerCubicInch,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Density.</summary>
    class DensityDto
    {
    public:
        constexpr DensityDto() noexcept
            : value{}, unit(DensityUnit::KilogramPerCubicMeter)
        {
        }

        constexpr DensityDto(
            const un_scalar_t value,
            const DensityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        DensityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr DensityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<DensityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Density unit name.");
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
        [[nodiscard]] static DensityDto from_json(const nlohmann::json& json)
        {
            return DensityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The density, or more precisely, the volumetric mass density, of a substance is its mass per unit volume.</summary>
    class Density : public UnitsNetBase
    {
    public:
        constexpr explicit Density(
            const un_scalar_t value,
            const DensityUnit unit = DensityUnit::KilogramPerCubicMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const DensityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr DensityDto to_dto(
            const DensityUnit unit = DensityUnit::KilogramPerCubicMeter) const
        {
            return DensityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Density from_dto(const DensityDto& dto)
        {
            return Density(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const DensityUnit unit = DensityUnit::KilogramPerCubicMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Density from_json(const nlohmann::json& json)
        {
            return from_dto(DensityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Density operator+(const Density& other) const noexcept
        {
            return Density(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Density operator-(const Density& other)const noexcept
        {
            return Density(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Density operator*(const un_scalar_t scalar) const noexcept
        {
            return Density(base_value() * scalar);
        }

        [[nodiscard]] constexpr Density operator/(const un_scalar_t scalar) const noexcept
        {
            return Density(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Density& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Density& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Density& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_cubic_millimeter() const
        {
            return convert_from_base(DensityUnit::GramPerCubicMillimeter);
        }

        [[nodiscard]] static constexpr Density from_grams_per_cubic_millimeter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::GramPerCubicMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_cubic_millimeter() const
        {
            return convert_from_base(DensityUnit::KilogramPerCubicMillimeter);
        }

        [[nodiscard]] static constexpr Density from_kilograms_per_cubic_millimeter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::KilogramPerCubicMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_cubic_centimeter() const
        {
            return convert_from_base(DensityUnit::GramPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr Density from_grams_per_cubic_centimeter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::GramPerCubicCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_cubic_centimeter() const
        {
            return convert_from_base(DensityUnit::KilogramPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr Density from_kilograms_per_cubic_centimeter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::KilogramPerCubicCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_cubic_meter() const
        {
            return convert_from_base(DensityUnit::GramPerCubicMeter);
        }

        [[nodiscard]] static constexpr Density from_grams_per_cubic_meter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::GramPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_cubic_meter() const
        {
            return convert_from_base(DensityUnit::KilogramPerCubicMeter);
        }

        [[nodiscard]] static constexpr Density from_kilograms_per_cubic_meter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::KilogramPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_cubic_meter() const
        {
            return convert_from_base(DensityUnit::MilligramPerCubicMeter);
        }

        [[nodiscard]] static constexpr Density from_milligrams_per_cubic_meter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::MilligramPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_cubic_meter() const
        {
            return convert_from_base(DensityUnit::MicrogramPerCubicMeter);
        }

        [[nodiscard]] static constexpr Density from_micrograms_per_cubic_meter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::MicrogramPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_cubic_inch() const
        {
            return convert_from_base(DensityUnit::PoundPerCubicInch);
        }

        [[nodiscard]] static constexpr Density from_pounds_per_cubic_inch(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PoundPerCubicInch);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_per_cubic_inch() const
        {
            return convert_from_base(DensityUnit::KilopoundPerCubicInch);
        }

        [[nodiscard]] static constexpr Density from_kilopounds_per_cubic_inch(const un_scalar_t value)
        {
            return Density(value, DensityUnit::KilopoundPerCubicInch);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_cubic_foot() const
        {
            return convert_from_base(DensityUnit::PoundPerCubicFoot);
        }

        [[nodiscard]] static constexpr Density from_pounds_per_cubic_foot(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PoundPerCubicFoot);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_per_cubic_foot() const
        {
            return convert_from_base(DensityUnit::KilopoundPerCubicFoot);
        }

        [[nodiscard]] static constexpr Density from_kilopounds_per_cubic_foot(const un_scalar_t value)
        {
            return Density(value, DensityUnit::KilopoundPerCubicFoot);
        }

        /// <summary>Calculated from the definition of <a href="https://en.wikipedia.org/wiki/Pound_(mass)">pound</a> and <a href="https://en.wikipedia.org/wiki/Cubic_yard">Cubic yard</a> compared to metric kilogram and meter.</summary>
        [[nodiscard]] constexpr un_scalar_t pounds_per_cubic_yard() const
        {
            return convert_from_base(DensityUnit::PoundPerCubicYard);
        }

        /// <summary>Calculated from the definition of <a href="https://en.wikipedia.org/wiki/Pound_(mass)">pound</a> and <a href="https://en.wikipedia.org/wiki/Cubic_yard">Cubic yard</a> compared to metric kilogram and meter.</summary>
        [[nodiscard]] static constexpr Density from_pounds_per_cubic_yard(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PoundPerCubicYard);
        }

        /// <summary>Calculated from the definition of <a href="https://en.wikipedia.org/wiki/Pound_(mass)">pound</a> and <a href="https://en.wikipedia.org/wiki/Cubic_yard">Cubic yard</a> compared to metric kilogram and meter.</summary>
        [[nodiscard]] constexpr un_scalar_t kilopounds_per_cubic_yard() const
        {
            return convert_from_base(DensityUnit::KilopoundPerCubicYard);
        }

        /// <summary>Calculated from the definition of <a href="https://en.wikipedia.org/wiki/Pound_(mass)">pound</a> and <a href="https://en.wikipedia.org/wiki/Cubic_yard">Cubic yard</a> compared to metric kilogram and meter.</summary>
        [[nodiscard]] static constexpr Density from_kilopounds_per_cubic_yard(const un_scalar_t value)
        {
            return Density(value, DensityUnit::KilopoundPerCubicYard);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_per_cubic_millimeter() const
        {
            return convert_from_base(DensityUnit::TonnePerCubicMillimeter);
        }

        [[nodiscard]] static constexpr Density from_tonnes_per_cubic_millimeter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::TonnePerCubicMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_per_cubic_centimeter() const
        {
            return convert_from_base(DensityUnit::TonnePerCubicCentimeter);
        }

        [[nodiscard]] static constexpr Density from_tonnes_per_cubic_centimeter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::TonnePerCubicCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_per_cubic_meter() const
        {
            return convert_from_base(DensityUnit::TonnePerCubicMeter);
        }

        [[nodiscard]] static constexpr Density from_tonnes_per_cubic_meter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::TonnePerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t slugs_per_cubic_foot() const
        {
            return convert_from_base(DensityUnit::SlugPerCubicFoot);
        }

        [[nodiscard]] static constexpr Density from_slugs_per_cubic_foot(const un_scalar_t value)
        {
            return Density(value, DensityUnit::SlugPerCubicFoot);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_liter() const
        {
            return convert_from_base(DensityUnit::GramPerLiter);
        }

        [[nodiscard]] static constexpr Density from_grams_per_liter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::GramPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t femtograms_per_liter() const
        {
            return convert_from_base(DensityUnit::FemtogramPerLiter);
        }

        [[nodiscard]] static constexpr Density from_femtograms_per_liter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::FemtogramPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t picograms_per_liter() const
        {
            return convert_from_base(DensityUnit::PicogramPerLiter);
        }

        [[nodiscard]] static constexpr Density from_picograms_per_liter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PicogramPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t nanograms_per_liter() const
        {
            return convert_from_base(DensityUnit::NanogramPerLiter);
        }

        [[nodiscard]] static constexpr Density from_nanograms_per_liter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::NanogramPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_liter() const
        {
            return convert_from_base(DensityUnit::MicrogramPerLiter);
        }

        [[nodiscard]] static constexpr Density from_micrograms_per_liter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::MicrogramPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_liter() const
        {
            return convert_from_base(DensityUnit::MilligramPerLiter);
        }

        [[nodiscard]] static constexpr Density from_milligrams_per_liter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::MilligramPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t centigrams_per_liter() const
        {
            return convert_from_base(DensityUnit::CentigramPerLiter);
        }

        [[nodiscard]] static constexpr Density from_centigrams_per_liter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::CentigramPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t decigrams_per_liter() const
        {
            return convert_from_base(DensityUnit::DecigramPerLiter);
        }

        [[nodiscard]] static constexpr Density from_decigrams_per_liter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::DecigramPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_deciliter() const
        {
            return convert_from_base(DensityUnit::GramPerDeciliter);
        }

        [[nodiscard]] static constexpr Density from_grams_per_deciliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::GramPerDeciliter);
        }

        [[nodiscard]] constexpr un_scalar_t femtograms_per_deciliter() const
        {
            return convert_from_base(DensityUnit::FemtogramPerDeciliter);
        }

        [[nodiscard]] static constexpr Density from_femtograms_per_deciliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::FemtogramPerDeciliter);
        }

        [[nodiscard]] constexpr un_scalar_t picograms_per_deciliter() const
        {
            return convert_from_base(DensityUnit::PicogramPerDeciliter);
        }

        [[nodiscard]] static constexpr Density from_picograms_per_deciliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PicogramPerDeciliter);
        }

        [[nodiscard]] constexpr un_scalar_t nanograms_per_deciliter() const
        {
            return convert_from_base(DensityUnit::NanogramPerDeciliter);
        }

        [[nodiscard]] static constexpr Density from_nanograms_per_deciliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::NanogramPerDeciliter);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_deciliter() const
        {
            return convert_from_base(DensityUnit::MicrogramPerDeciliter);
        }

        [[nodiscard]] static constexpr Density from_micrograms_per_deciliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::MicrogramPerDeciliter);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_deciliter() const
        {
            return convert_from_base(DensityUnit::MilligramPerDeciliter);
        }

        [[nodiscard]] static constexpr Density from_milligrams_per_deciliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::MilligramPerDeciliter);
        }

        [[nodiscard]] constexpr un_scalar_t centigrams_per_deciliter() const
        {
            return convert_from_base(DensityUnit::CentigramPerDeciliter);
        }

        [[nodiscard]] static constexpr Density from_centigrams_per_deciliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::CentigramPerDeciliter);
        }

        [[nodiscard]] constexpr un_scalar_t decigrams_per_deciliter() const
        {
            return convert_from_base(DensityUnit::DecigramPerDeciliter);
        }

        [[nodiscard]] static constexpr Density from_decigrams_per_deciliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::DecigramPerDeciliter);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_milliliter() const
        {
            return convert_from_base(DensityUnit::GramPerMilliliter);
        }

        [[nodiscard]] static constexpr Density from_grams_per_milliliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::GramPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t femtograms_per_milliliter() const
        {
            return convert_from_base(DensityUnit::FemtogramPerMilliliter);
        }

        [[nodiscard]] static constexpr Density from_femtograms_per_milliliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::FemtogramPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t picograms_per_milliliter() const
        {
            return convert_from_base(DensityUnit::PicogramPerMilliliter);
        }

        [[nodiscard]] static constexpr Density from_picograms_per_milliliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PicogramPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t nanograms_per_milliliter() const
        {
            return convert_from_base(DensityUnit::NanogramPerMilliliter);
        }

        [[nodiscard]] static constexpr Density from_nanograms_per_milliliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::NanogramPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_milliliter() const
        {
            return convert_from_base(DensityUnit::MicrogramPerMilliliter);
        }

        [[nodiscard]] static constexpr Density from_micrograms_per_milliliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::MicrogramPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_milliliter() const
        {
            return convert_from_base(DensityUnit::MilligramPerMilliliter);
        }

        [[nodiscard]] static constexpr Density from_milligrams_per_milliliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::MilligramPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t centigrams_per_milliliter() const
        {
            return convert_from_base(DensityUnit::CentigramPerMilliliter);
        }

        [[nodiscard]] static constexpr Density from_centigrams_per_milliliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::CentigramPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t decigrams_per_milliliter() const
        {
            return convert_from_base(DensityUnit::DecigramPerMilliliter);
        }

        [[nodiscard]] static constexpr Density from_decigrams_per_milliliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::DecigramPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_u_s_gallon() const
        {
            return convert_from_base(DensityUnit::PoundPerUSGallon);
        }

        [[nodiscard]] static constexpr Density from_pounds_per_u_s_gallon(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PoundPerUSGallon);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_imperial_gallon() const
        {
            return convert_from_base(DensityUnit::PoundPerImperialGallon);
        }

        [[nodiscard]] static constexpr Density from_pounds_per_imperial_gallon(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PoundPerImperialGallon);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_liter() const
        {
            return convert_from_base(DensityUnit::KilogramPerLiter);
        }

        [[nodiscard]] static constexpr Density from_kilograms_per_liter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::KilogramPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_per_cubic_foot() const
        {
            return convert_from_base(DensityUnit::TonnePerCubicFoot);
        }

        [[nodiscard]] static constexpr Density from_tonnes_per_cubic_foot(const un_scalar_t value)
        {
            return Density(value, DensityUnit::TonnePerCubicFoot);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_per_cubic_inch() const
        {
            return convert_from_base(DensityUnit::TonnePerCubicInch);
        }

        [[nodiscard]] static constexpr Density from_tonnes_per_cubic_inch(const un_scalar_t value)
        {
            return Density(value, DensityUnit::TonnePerCubicInch);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_cubic_foot() const
        {
            return convert_from_base(DensityUnit::GramPerCubicFoot);
        }

        [[nodiscard]] static constexpr Density from_grams_per_cubic_foot(const un_scalar_t value)
        {
            return Density(value, DensityUnit::GramPerCubicFoot);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_cubic_inch() const
        {
            return convert_from_base(DensityUnit::GramPerCubicInch);
        }

        [[nodiscard]] static constexpr Density from_grams_per_cubic_inch(const un_scalar_t value)
        {
            return Density(value, DensityUnit::GramPerCubicInch);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_cubic_meter() const
        {
            return convert_from_base(DensityUnit::PoundPerCubicMeter);
        }

        [[nodiscard]] static constexpr Density from_pounds_per_cubic_meter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PoundPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_cubic_centimeter() const
        {
            return convert_from_base(DensityUnit::PoundPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr Density from_pounds_per_cubic_centimeter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PoundPerCubicCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_cubic_millimeter() const
        {
            return convert_from_base(DensityUnit::PoundPerCubicMillimeter);
        }

        [[nodiscard]] static constexpr Density from_pounds_per_cubic_millimeter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PoundPerCubicMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t slugs_per_cubic_meter() const
        {
            return convert_from_base(DensityUnit::SlugPerCubicMeter);
        }

        [[nodiscard]] static constexpr Density from_slugs_per_cubic_meter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::SlugPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t slugs_per_cubic_centimeter() const
        {
            return convert_from_base(DensityUnit::SlugPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr Density from_slugs_per_cubic_centimeter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::SlugPerCubicCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t slugs_per_cubic_millimeter() const
        {
            return convert_from_base(DensityUnit::SlugPerCubicMillimeter);
        }

        [[nodiscard]] static constexpr Density from_slugs_per_cubic_millimeter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::SlugPerCubicMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t slugs_per_cubic_inch() const
        {
            return convert_from_base(DensityUnit::SlugPerCubicInch);
        }

        [[nodiscard]] static constexpr Density from_slugs_per_cubic_inch(const un_scalar_t value)
        {
            return Density(value, DensityUnit::SlugPerCubicInch);
        }

        [[nodiscard]] static constexpr Density from_invalid()
        {
            return Density(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, DensityUnit unit)
        {
            switch (unit)
            {

            case DensityUnit::GramPerCubicMillimeter:
                return value / static_cast<un_scalar_t>(1e-6);

            case DensityUnit::KilogramPerCubicMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-6);

            case DensityUnit::GramPerCubicCentimeter:
                return value / static_cast<un_scalar_t>(1e-3);

            case DensityUnit::KilogramPerCubicCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case DensityUnit::GramPerCubicMeter:
                return value / static_cast<un_scalar_t>(1e3);

            case DensityUnit::KilogramPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case DensityUnit::MilligramPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e3);

            case DensityUnit::MicrogramPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e3);

            case DensityUnit::PoundPerCubicInch:
                return value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(1.6387064e-5);

            case DensityUnit::KilopoundPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(1.6387064e-5);

            case DensityUnit::PoundPerCubicFoot:
                return value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.028316846592);

            case DensityUnit::KilopoundPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.028316846592);

            case DensityUnit::PoundPerCubicYard:
                return value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.764554857984);

            case DensityUnit::KilopoundPerCubicYard:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.764554857984);

            case DensityUnit::TonnePerCubicMillimeter:
                return value / static_cast<un_scalar_t>(1e-12);

            case DensityUnit::TonnePerCubicCentimeter:
                return value / static_cast<un_scalar_t>(1e-9);

            case DensityUnit::TonnePerCubicMeter:
                return value / static_cast<un_scalar_t>(0.001);

            case DensityUnit::SlugPerCubicFoot:
                return value * (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665)) / (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.028316846592));

            case DensityUnit::GramPerLiter:
                return value / static_cast<un_scalar_t>(1);

            case DensityUnit::FemtogramPerLiter:
                return (value * static_cast<un_scalar_t>(1e-15)) / static_cast<un_scalar_t>(1);

            case DensityUnit::PicogramPerLiter:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(1);

            case DensityUnit::NanogramPerLiter:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1);

            case DensityUnit::MicrogramPerLiter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1);

            case DensityUnit::MilligramPerLiter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1);

            case DensityUnit::CentigramPerLiter:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1);

            case DensityUnit::DecigramPerLiter:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1);

            case DensityUnit::GramPerDeciliter:
                return value / static_cast<un_scalar_t>(1e-1);

            case DensityUnit::FemtogramPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-15)) / static_cast<un_scalar_t>(1e-1);

            case DensityUnit::PicogramPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(1e-1);

            case DensityUnit::NanogramPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e-1);

            case DensityUnit::MicrogramPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-1);

            case DensityUnit::MilligramPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-1);

            case DensityUnit::CentigramPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e-1);

            case DensityUnit::DecigramPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-1);

            case DensityUnit::GramPerMilliliter:
                return value / static_cast<un_scalar_t>(1e-3);

            case DensityUnit::FemtogramPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-15)) / static_cast<un_scalar_t>(1e-3);

            case DensityUnit::PicogramPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(1e-3);

            case DensityUnit::NanogramPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e-3);

            case DensityUnit::MicrogramPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-3);

            case DensityUnit::MilligramPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-3);

            case DensityUnit::CentigramPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e-3);

            case DensityUnit::DecigramPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-3);

            case DensityUnit::PoundPerUSGallon:
                return value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.003785411784);

            case DensityUnit::PoundPerImperialGallon:
                return value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.00454609);

            case DensityUnit::KilogramPerLiter:
                return value * static_cast<un_scalar_t>(1e3);

            case DensityUnit::TonnePerCubicFoot:
                return value * static_cast<un_scalar_t>(1000) / static_cast<un_scalar_t>(0.028316846592);

            case DensityUnit::TonnePerCubicInch:
                return value * static_cast<un_scalar_t>(1000) / static_cast<un_scalar_t>(1.6387064e-5);

            case DensityUnit::GramPerCubicFoot:
                return value * static_cast<un_scalar_t>(0.001) / static_cast<un_scalar_t>(0.028316846592);

            case DensityUnit::GramPerCubicInch:
                return value * static_cast<un_scalar_t>(0.001) / static_cast<un_scalar_t>(1.6387064e-5);

            case DensityUnit::PoundPerCubicMeter:
                return value * static_cast<un_scalar_t>(0.45359237);

            case DensityUnit::PoundPerCubicCentimeter:
                return value * static_cast<un_scalar_t>(0.45359237e6);

            case DensityUnit::PoundPerCubicMillimeter:
                return value * static_cast<un_scalar_t>(0.45359237e9);

            case DensityUnit::SlugPerCubicMeter:
                return value * static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665) / static_cast<un_scalar_t>(0.3048);

            case DensityUnit::SlugPerCubicCentimeter:
                return value * static_cast<un_scalar_t>(0.45359237e6) * static_cast<un_scalar_t>(9.80665) / static_cast<un_scalar_t>(0.3048);

            case DensityUnit::SlugPerCubicMillimeter:
                return value * static_cast<un_scalar_t>(0.45359237e9) * static_cast<un_scalar_t>(9.80665) / static_cast<un_scalar_t>(0.3048);

            case DensityUnit::SlugPerCubicInch:
                return value * (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665)) / (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(1.6387064e-5));

            }

            throw std::invalid_argument("Unknown Density unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const DensityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case DensityUnit::GramPerCubicMillimeter:
                return base_value * static_cast<un_scalar_t>(1e-6);

            case DensityUnit::KilogramPerCubicMillimeter:
                return (base_value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e3);

            case DensityUnit::GramPerCubicCentimeter:
                return base_value * static_cast<un_scalar_t>(1e-3);

            case DensityUnit::KilogramPerCubicCentimeter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e3);

            case DensityUnit::GramPerCubicMeter:
                return base_value * static_cast<un_scalar_t>(1e3);

            case DensityUnit::KilogramPerCubicMeter:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case DensityUnit::MilligramPerCubicMeter:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case DensityUnit::MicrogramPerCubicMeter:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-6);

            case DensityUnit::PoundPerCubicInch:
                return base_value * static_cast<un_scalar_t>(1.6387064e-5) / static_cast<un_scalar_t>(0.45359237);

            case DensityUnit::KilopoundPerCubicInch:
                return (base_value * static_cast<un_scalar_t>(1.6387064e-5) / static_cast<un_scalar_t>(0.45359237)) / static_cast<un_scalar_t>(1e3);

            case DensityUnit::PoundPerCubicFoot:
                return base_value * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(0.45359237);

            case DensityUnit::KilopoundPerCubicFoot:
                return (base_value * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(0.45359237)) / static_cast<un_scalar_t>(1e3);

            case DensityUnit::PoundPerCubicYard:
                return base_value * static_cast<un_scalar_t>(0.764554857984) / static_cast<un_scalar_t>(0.45359237);

            case DensityUnit::KilopoundPerCubicYard:
                return (base_value * static_cast<un_scalar_t>(0.764554857984) / static_cast<un_scalar_t>(0.45359237)) / static_cast<un_scalar_t>(1e3);

            case DensityUnit::TonnePerCubicMillimeter:
                return base_value * static_cast<un_scalar_t>(1e-12);

            case DensityUnit::TonnePerCubicCentimeter:
                return base_value * static_cast<un_scalar_t>(1e-9);

            case DensityUnit::TonnePerCubicMeter:
                return base_value * static_cast<un_scalar_t>(0.001);

            case DensityUnit::SlugPerCubicFoot:
                return base_value * (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.028316846592)) / (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665));

            case DensityUnit::GramPerLiter:
                return base_value * static_cast<un_scalar_t>(1);

            case DensityUnit::FemtogramPerLiter:
                return (base_value * static_cast<un_scalar_t>(1)) / static_cast<un_scalar_t>(1e-15);

            case DensityUnit::PicogramPerLiter:
                return (base_value * static_cast<un_scalar_t>(1)) / static_cast<un_scalar_t>(1e-12);

            case DensityUnit::NanogramPerLiter:
                return (base_value * static_cast<un_scalar_t>(1)) / static_cast<un_scalar_t>(1e-9);

            case DensityUnit::MicrogramPerLiter:
                return (base_value * static_cast<un_scalar_t>(1)) / static_cast<un_scalar_t>(1e-6);

            case DensityUnit::MilligramPerLiter:
                return (base_value * static_cast<un_scalar_t>(1)) / static_cast<un_scalar_t>(1e-3);

            case DensityUnit::CentigramPerLiter:
                return (base_value * static_cast<un_scalar_t>(1)) / static_cast<un_scalar_t>(1e-2);

            case DensityUnit::DecigramPerLiter:
                return (base_value * static_cast<un_scalar_t>(1)) / static_cast<un_scalar_t>(1e-1);

            case DensityUnit::GramPerDeciliter:
                return base_value * static_cast<un_scalar_t>(1e-1);

            case DensityUnit::FemtogramPerDeciliter:
                return (base_value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-15);

            case DensityUnit::PicogramPerDeciliter:
                return (base_value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-12);

            case DensityUnit::NanogramPerDeciliter:
                return (base_value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-9);

            case DensityUnit::MicrogramPerDeciliter:
                return (base_value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-6);

            case DensityUnit::MilligramPerDeciliter:
                return (base_value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-3);

            case DensityUnit::CentigramPerDeciliter:
                return (base_value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-2);

            case DensityUnit::DecigramPerDeciliter:
                return (base_value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-1);

            case DensityUnit::GramPerMilliliter:
                return base_value * static_cast<un_scalar_t>(1e-3);

            case DensityUnit::FemtogramPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-15);

            case DensityUnit::PicogramPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-12);

            case DensityUnit::NanogramPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-9);

            case DensityUnit::MicrogramPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-6);

            case DensityUnit::MilligramPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-3);

            case DensityUnit::CentigramPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-2);

            case DensityUnit::DecigramPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-1);

            case DensityUnit::PoundPerUSGallon:
                return base_value * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(0.45359237);

            case DensityUnit::PoundPerImperialGallon:
                return base_value * static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(0.45359237);

            case DensityUnit::KilogramPerLiter:
                return base_value / static_cast<un_scalar_t>(1e3);

            case DensityUnit::TonnePerCubicFoot:
                return base_value * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(1000);

            case DensityUnit::TonnePerCubicInch:
                return base_value * static_cast<un_scalar_t>(1.6387064e-5) / static_cast<un_scalar_t>(1000);

            case DensityUnit::GramPerCubicFoot:
                return base_value * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(0.001);

            case DensityUnit::GramPerCubicInch:
                return base_value * static_cast<un_scalar_t>(1.6387064e-5) / static_cast<un_scalar_t>(0.001);

            case DensityUnit::PoundPerCubicMeter:
                return base_value / static_cast<un_scalar_t>(0.45359237);

            case DensityUnit::PoundPerCubicCentimeter:
                return base_value / static_cast<un_scalar_t>(0.45359237e6);

            case DensityUnit::PoundPerCubicMillimeter:
                return base_value / static_cast<un_scalar_t>(0.45359237e9);

            case DensityUnit::SlugPerCubicMeter:
                return base_value * static_cast<un_scalar_t>(0.3048) / (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665));

            case DensityUnit::SlugPerCubicCentimeter:
                return base_value * static_cast<un_scalar_t>(0.3048) / (static_cast<un_scalar_t>(0.45359237e6) * static_cast<un_scalar_t>(9.80665));

            case DensityUnit::SlugPerCubicMillimeter:
                return base_value * static_cast<un_scalar_t>(0.3048) / (static_cast<un_scalar_t>(0.45359237e9) * static_cast<un_scalar_t>(9.80665));

            case DensityUnit::SlugPerCubicInch:
                return base_value * (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(1.6387064e-5)) / (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665));

            }

            throw std::invalid_argument("Unknown Density unit.");
        }

        un_scalar_t value_;
        DensityUnit value_unit_type_;       
    };
}
