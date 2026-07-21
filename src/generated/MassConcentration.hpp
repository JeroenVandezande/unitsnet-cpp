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
    enum class MassConcentrationUnit : std::uint8_t
    {
        GramPerCubicMillimeter,
        KilogramPerCubicMillimeter,
        GramPerCubicCentimeter,
        KilogramPerCubicCentimeter,
        GramPerCubicMeter,
        KilogramPerCubicMeter,
        MilligramPerCubicMeter,
        MicrogramPerCubicMeter,
        GramPerMicroliter,
        PicogramPerMicroliter,
        NanogramPerMicroliter,
        MicrogramPerMicroliter,
        MilligramPerMicroliter,
        CentigramPerMicroliter,
        DecigramPerMicroliter,
        GramPerMilliliter,
        PicogramPerMilliliter,
        NanogramPerMilliliter,
        MicrogramPerMilliliter,
        MilligramPerMilliliter,
        CentigramPerMilliliter,
        DecigramPerMilliliter,
        GramPerDeciliter,
        PicogramPerDeciliter,
        NanogramPerDeciliter,
        MicrogramPerDeciliter,
        MilligramPerDeciliter,
        CentigramPerDeciliter,
        DecigramPerDeciliter,
        GramPerLiter,
        PicogramPerLiter,
        NanogramPerLiter,
        MicrogramPerLiter,
        MilligramPerLiter,
        CentigramPerLiter,
        DecigramPerLiter,
        KilogramPerLiter,
        TonnePerCubicMillimeter,
        TonnePerCubicCentimeter,
        TonnePerCubicMeter,
        PoundPerCubicInch,
        KilopoundPerCubicInch,
        PoundPerCubicFoot,
        KilopoundPerCubicFoot,
        SlugPerCubicFoot,
        PoundPerUSGallon,
        OuncePerUSGallon,
        OuncePerImperialGallon,
        PoundPerImperialGallon,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of MassConcentration.</summary>
    class MassConcentrationDto
    {
    public:
        constexpr MassConcentrationDto() noexcept
            : value{}, unit(MassConcentrationUnit::KilogramPerCubicMeter)
        {
        }

        constexpr MassConcentrationDto(
            const un_scalar_t value,
            const MassConcentrationUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        MassConcentrationUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr MassConcentrationUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<MassConcentrationUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown MassConcentration unit name.");
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
        [[nodiscard]] static MassConcentrationDto from_json(const nlohmann::json& json)
        {
            return MassConcentrationDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In chemistry, the mass concentration ρi (or γi) is defined as the mass of a constituent mi divided by the volume of the mixture V</summary>
    class MassConcentration : public UnitsNetBase
    {
    public:
        constexpr explicit MassConcentration(
            const un_scalar_t value,
            const MassConcentrationUnit unit = MassConcentrationUnit::KilogramPerCubicMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MassConcentrationUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr MassConcentrationDto to_dto(
            const MassConcentrationUnit unit = MassConcentrationUnit::KilogramPerCubicMeter) const
        {
            return MassConcentrationDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr MassConcentration from_dto(const MassConcentrationDto& dto)
        {
            return MassConcentration(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const MassConcentrationUnit unit = MassConcentrationUnit::KilogramPerCubicMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static MassConcentration from_json(const nlohmann::json& json)
        {
            return from_dto(MassConcentrationDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr MassConcentration operator+(const MassConcentration& other) const noexcept
        {
            return MassConcentration(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr MassConcentration operator-(const MassConcentration& other)const noexcept
        {
            return MassConcentration(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr MassConcentration operator*(const un_scalar_t scalar) const noexcept
        {
            return MassConcentration(base_value() * scalar);
        }

        [[nodiscard]] constexpr MassConcentration operator/(const un_scalar_t scalar) const noexcept
        {
            return MassConcentration(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MassConcentration& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const MassConcentration& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const MassConcentration& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_cubic_millimeter() const
        {
            return convert_from_base(MassConcentrationUnit::GramPerCubicMillimeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_grams_per_cubic_millimeter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::GramPerCubicMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_cubic_millimeter() const
        {
            return convert_from_base(MassConcentrationUnit::KilogramPerCubicMillimeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_kilograms_per_cubic_millimeter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::KilogramPerCubicMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_cubic_centimeter() const
        {
            return convert_from_base(MassConcentrationUnit::GramPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_grams_per_cubic_centimeter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::GramPerCubicCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_cubic_centimeter() const
        {
            return convert_from_base(MassConcentrationUnit::KilogramPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_kilograms_per_cubic_centimeter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::KilogramPerCubicCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_cubic_meter() const
        {
            return convert_from_base(MassConcentrationUnit::GramPerCubicMeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_grams_per_cubic_meter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::GramPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_cubic_meter() const
        {
            return convert_from_base(MassConcentrationUnit::KilogramPerCubicMeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_kilograms_per_cubic_meter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::KilogramPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_cubic_meter() const
        {
            return convert_from_base(MassConcentrationUnit::MilligramPerCubicMeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_milligrams_per_cubic_meter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::MilligramPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_cubic_meter() const
        {
            return convert_from_base(MassConcentrationUnit::MicrogramPerCubicMeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_micrograms_per_cubic_meter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::MicrogramPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_microliter() const
        {
            return convert_from_base(MassConcentrationUnit::GramPerMicroliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_grams_per_microliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::GramPerMicroliter);
        }

        [[nodiscard]] constexpr un_scalar_t picograms_per_microliter() const
        {
            return convert_from_base(MassConcentrationUnit::PicogramPerMicroliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_picograms_per_microliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::PicogramPerMicroliter);
        }

        [[nodiscard]] constexpr un_scalar_t nanograms_per_microliter() const
        {
            return convert_from_base(MassConcentrationUnit::NanogramPerMicroliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_nanograms_per_microliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::NanogramPerMicroliter);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_microliter() const
        {
            return convert_from_base(MassConcentrationUnit::MicrogramPerMicroliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_micrograms_per_microliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::MicrogramPerMicroliter);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_microliter() const
        {
            return convert_from_base(MassConcentrationUnit::MilligramPerMicroliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_milligrams_per_microliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::MilligramPerMicroliter);
        }

        [[nodiscard]] constexpr un_scalar_t centigrams_per_microliter() const
        {
            return convert_from_base(MassConcentrationUnit::CentigramPerMicroliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_centigrams_per_microliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::CentigramPerMicroliter);
        }

        [[nodiscard]] constexpr un_scalar_t decigrams_per_microliter() const
        {
            return convert_from_base(MassConcentrationUnit::DecigramPerMicroliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_decigrams_per_microliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::DecigramPerMicroliter);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_milliliter() const
        {
            return convert_from_base(MassConcentrationUnit::GramPerMilliliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_grams_per_milliliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::GramPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t picograms_per_milliliter() const
        {
            return convert_from_base(MassConcentrationUnit::PicogramPerMilliliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_picograms_per_milliliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::PicogramPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t nanograms_per_milliliter() const
        {
            return convert_from_base(MassConcentrationUnit::NanogramPerMilliliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_nanograms_per_milliliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::NanogramPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_milliliter() const
        {
            return convert_from_base(MassConcentrationUnit::MicrogramPerMilliliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_micrograms_per_milliliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::MicrogramPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_milliliter() const
        {
            return convert_from_base(MassConcentrationUnit::MilligramPerMilliliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_milligrams_per_milliliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::MilligramPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t centigrams_per_milliliter() const
        {
            return convert_from_base(MassConcentrationUnit::CentigramPerMilliliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_centigrams_per_milliliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::CentigramPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t decigrams_per_milliliter() const
        {
            return convert_from_base(MassConcentrationUnit::DecigramPerMilliliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_decigrams_per_milliliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::DecigramPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_deciliter() const
        {
            return convert_from_base(MassConcentrationUnit::GramPerDeciliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_grams_per_deciliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::GramPerDeciliter);
        }

        [[nodiscard]] constexpr un_scalar_t picograms_per_deciliter() const
        {
            return convert_from_base(MassConcentrationUnit::PicogramPerDeciliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_picograms_per_deciliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::PicogramPerDeciliter);
        }

        [[nodiscard]] constexpr un_scalar_t nanograms_per_deciliter() const
        {
            return convert_from_base(MassConcentrationUnit::NanogramPerDeciliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_nanograms_per_deciliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::NanogramPerDeciliter);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_deciliter() const
        {
            return convert_from_base(MassConcentrationUnit::MicrogramPerDeciliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_micrograms_per_deciliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::MicrogramPerDeciliter);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_deciliter() const
        {
            return convert_from_base(MassConcentrationUnit::MilligramPerDeciliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_milligrams_per_deciliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::MilligramPerDeciliter);
        }

        [[nodiscard]] constexpr un_scalar_t centigrams_per_deciliter() const
        {
            return convert_from_base(MassConcentrationUnit::CentigramPerDeciliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_centigrams_per_deciliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::CentigramPerDeciliter);
        }

        [[nodiscard]] constexpr un_scalar_t decigrams_per_deciliter() const
        {
            return convert_from_base(MassConcentrationUnit::DecigramPerDeciliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_decigrams_per_deciliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::DecigramPerDeciliter);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_liter() const
        {
            return convert_from_base(MassConcentrationUnit::GramPerLiter);
        }

        [[nodiscard]] static constexpr MassConcentration from_grams_per_liter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::GramPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t picograms_per_liter() const
        {
            return convert_from_base(MassConcentrationUnit::PicogramPerLiter);
        }

        [[nodiscard]] static constexpr MassConcentration from_picograms_per_liter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::PicogramPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t nanograms_per_liter() const
        {
            return convert_from_base(MassConcentrationUnit::NanogramPerLiter);
        }

        [[nodiscard]] static constexpr MassConcentration from_nanograms_per_liter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::NanogramPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_liter() const
        {
            return convert_from_base(MassConcentrationUnit::MicrogramPerLiter);
        }

        [[nodiscard]] static constexpr MassConcentration from_micrograms_per_liter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::MicrogramPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_liter() const
        {
            return convert_from_base(MassConcentrationUnit::MilligramPerLiter);
        }

        [[nodiscard]] static constexpr MassConcentration from_milligrams_per_liter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::MilligramPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t centigrams_per_liter() const
        {
            return convert_from_base(MassConcentrationUnit::CentigramPerLiter);
        }

        [[nodiscard]] static constexpr MassConcentration from_centigrams_per_liter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::CentigramPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t decigrams_per_liter() const
        {
            return convert_from_base(MassConcentrationUnit::DecigramPerLiter);
        }

        [[nodiscard]] static constexpr MassConcentration from_decigrams_per_liter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::DecigramPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_liter() const
        {
            return convert_from_base(MassConcentrationUnit::KilogramPerLiter);
        }

        [[nodiscard]] static constexpr MassConcentration from_kilograms_per_liter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::KilogramPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_per_cubic_millimeter() const
        {
            return convert_from_base(MassConcentrationUnit::TonnePerCubicMillimeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_tonnes_per_cubic_millimeter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::TonnePerCubicMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_per_cubic_centimeter() const
        {
            return convert_from_base(MassConcentrationUnit::TonnePerCubicCentimeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_tonnes_per_cubic_centimeter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::TonnePerCubicCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_per_cubic_meter() const
        {
            return convert_from_base(MassConcentrationUnit::TonnePerCubicMeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_tonnes_per_cubic_meter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::TonnePerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_cubic_inch() const
        {
            return convert_from_base(MassConcentrationUnit::PoundPerCubicInch);
        }

        [[nodiscard]] static constexpr MassConcentration from_pounds_per_cubic_inch(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::PoundPerCubicInch);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_per_cubic_inch() const
        {
            return convert_from_base(MassConcentrationUnit::KilopoundPerCubicInch);
        }

        [[nodiscard]] static constexpr MassConcentration from_kilopounds_per_cubic_inch(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::KilopoundPerCubicInch);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_cubic_foot() const
        {
            return convert_from_base(MassConcentrationUnit::PoundPerCubicFoot);
        }

        [[nodiscard]] static constexpr MassConcentration from_pounds_per_cubic_foot(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::PoundPerCubicFoot);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_per_cubic_foot() const
        {
            return convert_from_base(MassConcentrationUnit::KilopoundPerCubicFoot);
        }

        [[nodiscard]] static constexpr MassConcentration from_kilopounds_per_cubic_foot(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::KilopoundPerCubicFoot);
        }

        [[nodiscard]] constexpr un_scalar_t slugs_per_cubic_foot() const
        {
            return convert_from_base(MassConcentrationUnit::SlugPerCubicFoot);
        }

        [[nodiscard]] static constexpr MassConcentration from_slugs_per_cubic_foot(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::SlugPerCubicFoot);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_u_s_gallon() const
        {
            return convert_from_base(MassConcentrationUnit::PoundPerUSGallon);
        }

        [[nodiscard]] static constexpr MassConcentration from_pounds_per_u_s_gallon(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::PoundPerUSGallon);
        }

        [[nodiscard]] constexpr un_scalar_t ounces_per_u_s_gallon() const
        {
            return convert_from_base(MassConcentrationUnit::OuncePerUSGallon);
        }

        [[nodiscard]] static constexpr MassConcentration from_ounces_per_u_s_gallon(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::OuncePerUSGallon);
        }

        [[nodiscard]] constexpr un_scalar_t ounces_per_imperial_gallon() const
        {
            return convert_from_base(MassConcentrationUnit::OuncePerImperialGallon);
        }

        [[nodiscard]] static constexpr MassConcentration from_ounces_per_imperial_gallon(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::OuncePerImperialGallon);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_imperial_gallon() const
        {
            return convert_from_base(MassConcentrationUnit::PoundPerImperialGallon);
        }

        [[nodiscard]] static constexpr MassConcentration from_pounds_per_imperial_gallon(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::PoundPerImperialGallon);
        }

        [[nodiscard]] static constexpr MassConcentration from_invalid()
        {
            return MassConcentration(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MassConcentrationUnit unit)
        {
            switch (unit)
            {

            case MassConcentrationUnit::GramPerCubicMillimeter:
                return value / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::KilogramPerCubicMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::GramPerCubicCentimeter:
                return value / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::KilogramPerCubicCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::GramPerCubicMeter:
                return value / static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::KilogramPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::MilligramPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::MicrogramPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::GramPerMicroliter:
                return value / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::PicogramPerMicroliter:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::NanogramPerMicroliter:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::MicrogramPerMicroliter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::MilligramPerMicroliter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::CentigramPerMicroliter:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::DecigramPerMicroliter:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::GramPerMilliliter:
                return value / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::PicogramPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::NanogramPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::MicrogramPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::MilligramPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::CentigramPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::DecigramPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::GramPerDeciliter:
                return value / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::PicogramPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::NanogramPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::MicrogramPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::MilligramPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::CentigramPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::DecigramPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::GramPerLiter:
                return value;

            case MassConcentrationUnit::PicogramPerLiter:
                return (value * static_cast<un_scalar_t>(1e-12));

            case MassConcentrationUnit::NanogramPerLiter:
                return (value * static_cast<un_scalar_t>(1e-9));

            case MassConcentrationUnit::MicrogramPerLiter:
                return (value * static_cast<un_scalar_t>(1e-6));

            case MassConcentrationUnit::MilligramPerLiter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case MassConcentrationUnit::CentigramPerLiter:
                return (value * static_cast<un_scalar_t>(1e-2));

            case MassConcentrationUnit::DecigramPerLiter:
                return (value * static_cast<un_scalar_t>(1e-1));

            case MassConcentrationUnit::KilogramPerLiter:
                return (value * static_cast<un_scalar_t>(1e3));

            case MassConcentrationUnit::TonnePerCubicMillimeter:
                return value / static_cast<un_scalar_t>(1e-12);

            case MassConcentrationUnit::TonnePerCubicCentimeter:
                return value / static_cast<un_scalar_t>(1e-9);

            case MassConcentrationUnit::TonnePerCubicMeter:
                return value / static_cast<un_scalar_t>(0.001);

            case MassConcentrationUnit::PoundPerCubicInch:
                return value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(1.6387064e-5);

            case MassConcentrationUnit::KilopoundPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(1.6387064e-5);

            case MassConcentrationUnit::PoundPerCubicFoot:
                return value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.028316846592);

            case MassConcentrationUnit::KilopoundPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.028316846592);

            case MassConcentrationUnit::SlugPerCubicFoot:
                return value * (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665)) / (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.028316846592));

            case MassConcentrationUnit::PoundPerUSGallon:
                return value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.003785411784);

            case MassConcentrationUnit::OuncePerUSGallon:
                return value * static_cast<un_scalar_t>(0.028349523125) / static_cast<un_scalar_t>(0.003785411784);

            case MassConcentrationUnit::OuncePerImperialGallon:
                return value * static_cast<un_scalar_t>(0.028349523125) / static_cast<un_scalar_t>(0.00454609);

            case MassConcentrationUnit::PoundPerImperialGallon:
                return value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.00454609);

            }

            throw std::invalid_argument("Unknown MassConcentration unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MassConcentrationUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case MassConcentrationUnit::GramPerCubicMillimeter:
                return base_value * static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::KilogramPerCubicMillimeter:
                return (base_value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::GramPerCubicCentimeter:
                return base_value * static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::KilogramPerCubicCentimeter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::GramPerCubicMeter:
                return base_value * static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::KilogramPerCubicMeter:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::MilligramPerCubicMeter:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::MicrogramPerCubicMeter:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::GramPerMicroliter:
                return base_value * static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::PicogramPerMicroliter:
                return (base_value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-12);

            case MassConcentrationUnit::NanogramPerMicroliter:
                return (base_value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-9);

            case MassConcentrationUnit::MicrogramPerMicroliter:
                return (base_value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::MilligramPerMicroliter:
                return (base_value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::CentigramPerMicroliter:
                return (base_value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-2);

            case MassConcentrationUnit::DecigramPerMicroliter:
                return (base_value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::GramPerMilliliter:
                return base_value * static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::PicogramPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-12);

            case MassConcentrationUnit::NanogramPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-9);

            case MassConcentrationUnit::MicrogramPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::MilligramPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::CentigramPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-2);

            case MassConcentrationUnit::DecigramPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::GramPerDeciliter:
                return base_value * static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::PicogramPerDeciliter:
                return (base_value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-12);

            case MassConcentrationUnit::NanogramPerDeciliter:
                return (base_value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-9);

            case MassConcentrationUnit::MicrogramPerDeciliter:
                return (base_value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::MilligramPerDeciliter:
                return (base_value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::CentigramPerDeciliter:
                return (base_value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-2);

            case MassConcentrationUnit::DecigramPerDeciliter:
                return (base_value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::GramPerLiter:
                return base_value;

            case MassConcentrationUnit::PicogramPerLiter:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case MassConcentrationUnit::NanogramPerLiter:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case MassConcentrationUnit::MicrogramPerLiter:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::MilligramPerLiter:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::CentigramPerLiter:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case MassConcentrationUnit::DecigramPerLiter:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::KilogramPerLiter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::TonnePerCubicMillimeter:
                return base_value * static_cast<un_scalar_t>(1e-12);

            case MassConcentrationUnit::TonnePerCubicCentimeter:
                return base_value * static_cast<un_scalar_t>(1e-9);

            case MassConcentrationUnit::TonnePerCubicMeter:
                return base_value * static_cast<un_scalar_t>(0.001);

            case MassConcentrationUnit::PoundPerCubicInch:
                return base_value * static_cast<un_scalar_t>(1.6387064e-5) / static_cast<un_scalar_t>(0.45359237);

            case MassConcentrationUnit::KilopoundPerCubicInch:
                return (base_value * static_cast<un_scalar_t>(1.6387064e-5) / static_cast<un_scalar_t>(0.45359237)) / static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::PoundPerCubicFoot:
                return base_value * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(0.45359237);

            case MassConcentrationUnit::KilopoundPerCubicFoot:
                return (base_value * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(0.45359237)) / static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::SlugPerCubicFoot:
                return base_value * (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.028316846592)) / (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665));

            case MassConcentrationUnit::PoundPerUSGallon:
                return base_value * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(0.45359237);

            case MassConcentrationUnit::OuncePerUSGallon:
                return base_value * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(0.028349523125);

            case MassConcentrationUnit::OuncePerImperialGallon:
                return base_value * static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(0.028349523125);

            case MassConcentrationUnit::PoundPerImperialGallon:
                return base_value * static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(0.45359237);

            }

            throw std::invalid_argument("Unknown MassConcentration unit.");
        }

        un_scalar_t value_;
        MassConcentrationUnit value_unit_type_;       
    };
}
