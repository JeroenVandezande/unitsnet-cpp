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
    enum class VolumeConcentrationUnit : std::uint8_t
    {
        DecimalFraction,
        LiterPerLiter,
        PicoliterPerLiter,
        NanoliterPerLiter,
        MicroliterPerLiter,
        MilliliterPerLiter,
        CentiliterPerLiter,
        DeciliterPerLiter,
        LiterPerMilliliter,
        PicoliterPerMilliliter,
        NanoliterPerMilliliter,
        MicroliterPerMilliliter,
        MilliliterPerMilliliter,
        CentiliterPerMilliliter,
        DeciliterPerMilliliter,
        Percent,
        PartPerThousand,
        PartPerMillion,
        PartPerBillion,
        PartPerTrillion,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of VolumeConcentration.</summary>
    class VolumeConcentrationDto
    {
    public:
        constexpr VolumeConcentrationDto() noexcept
            : value{}, unit(VolumeConcentrationUnit::DecimalFraction)
        {
        }

        constexpr VolumeConcentrationDto(
            const un_scalar_t value,
            const VolumeConcentrationUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        VolumeConcentrationUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr VolumeConcentrationUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<VolumeConcentrationUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown VolumeConcentration unit name.");
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
        [[nodiscard]] static VolumeConcentrationDto from_json(const nlohmann::json& json)
        {
            return VolumeConcentrationDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The volume concentration (not to be confused with volume fraction) is defined as the volume of a constituent divided by the total volume of the mixture.</summary>
    class VolumeConcentration : public UnitsNetBase
    {
    public:
        constexpr explicit VolumeConcentration(
            const un_scalar_t value,
            const VolumeConcentrationUnit unit = VolumeConcentrationUnit::DecimalFraction)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const VolumeConcentrationUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr VolumeConcentrationDto to_dto(
            const VolumeConcentrationUnit unit = VolumeConcentrationUnit::DecimalFraction) const
        {
            return VolumeConcentrationDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr VolumeConcentration from_dto(const VolumeConcentrationDto& dto)
        {
            return VolumeConcentration(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const VolumeConcentrationUnit unit = VolumeConcentrationUnit::DecimalFraction) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static VolumeConcentration from_json(const nlohmann::json& json)
        {
            return from_dto(VolumeConcentrationDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr VolumeConcentration operator+(const VolumeConcentration& other) const noexcept
        {
            return VolumeConcentration(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr VolumeConcentration operator-(const VolumeConcentration& other)const noexcept
        {
            return VolumeConcentration(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr VolumeConcentration operator*(const un_scalar_t scalar) const noexcept
        {
            return VolumeConcentration(base_value() * scalar);
        }

        [[nodiscard]] constexpr VolumeConcentration operator/(const un_scalar_t scalar) const noexcept
        {
            return VolumeConcentration(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const VolumeConcentration& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const VolumeConcentration& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const VolumeConcentration& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t decimal_fractions() const
        {
            return convert_from_base(VolumeConcentrationUnit::DecimalFraction);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_decimal_fractions(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::DecimalFraction);
        }

        [[nodiscard]] constexpr un_scalar_t liters_per_liter() const
        {
            return convert_from_base(VolumeConcentrationUnit::LiterPerLiter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_liters_per_liter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::LiterPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t picoliters_per_liter() const
        {
            return convert_from_base(VolumeConcentrationUnit::PicoliterPerLiter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_picoliters_per_liter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::PicoliterPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t nanoliters_per_liter() const
        {
            return convert_from_base(VolumeConcentrationUnit::NanoliterPerLiter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_nanoliters_per_liter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::NanoliterPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t microliters_per_liter() const
        {
            return convert_from_base(VolumeConcentrationUnit::MicroliterPerLiter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_microliters_per_liter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::MicroliterPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t milliliters_per_liter() const
        {
            return convert_from_base(VolumeConcentrationUnit::MilliliterPerLiter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_milliliters_per_liter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::MilliliterPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t centiliters_per_liter() const
        {
            return convert_from_base(VolumeConcentrationUnit::CentiliterPerLiter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_centiliters_per_liter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::CentiliterPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t deciliters_per_liter() const
        {
            return convert_from_base(VolumeConcentrationUnit::DeciliterPerLiter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_deciliters_per_liter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::DeciliterPerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t liters_per_milliliter() const
        {
            return convert_from_base(VolumeConcentrationUnit::LiterPerMilliliter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_liters_per_milliliter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::LiterPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t picoliters_per_milliliter() const
        {
            return convert_from_base(VolumeConcentrationUnit::PicoliterPerMilliliter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_picoliters_per_milliliter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::PicoliterPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t nanoliters_per_milliliter() const
        {
            return convert_from_base(VolumeConcentrationUnit::NanoliterPerMilliliter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_nanoliters_per_milliliter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::NanoliterPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t microliters_per_milliliter() const
        {
            return convert_from_base(VolumeConcentrationUnit::MicroliterPerMilliliter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_microliters_per_milliliter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::MicroliterPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t milliliters_per_milliliter() const
        {
            return convert_from_base(VolumeConcentrationUnit::MilliliterPerMilliliter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_milliliters_per_milliliter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::MilliliterPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t centiliters_per_milliliter() const
        {
            return convert_from_base(VolumeConcentrationUnit::CentiliterPerMilliliter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_centiliters_per_milliliter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::CentiliterPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t deciliters_per_milliliter() const
        {
            return convert_from_base(VolumeConcentrationUnit::DeciliterPerMilliliter);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_deciliters_per_milliliter(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::DeciliterPerMilliliter);
        }

        [[nodiscard]] constexpr un_scalar_t percent() const
        {
            return convert_from_base(VolumeConcentrationUnit::Percent);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_percent(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::Percent);
        }

        [[nodiscard]] constexpr un_scalar_t parts_per_thousand() const
        {
            return convert_from_base(VolumeConcentrationUnit::PartPerThousand);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_parts_per_thousand(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::PartPerThousand);
        }

        [[nodiscard]] constexpr un_scalar_t parts_per_million() const
        {
            return convert_from_base(VolumeConcentrationUnit::PartPerMillion);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_parts_per_million(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::PartPerMillion);
        }

        [[nodiscard]] constexpr un_scalar_t parts_per_billion() const
        {
            return convert_from_base(VolumeConcentrationUnit::PartPerBillion);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_parts_per_billion(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::PartPerBillion);
        }

        [[nodiscard]] constexpr un_scalar_t parts_per_trillion() const
        {
            return convert_from_base(VolumeConcentrationUnit::PartPerTrillion);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_parts_per_trillion(const un_scalar_t value)
        {
            return VolumeConcentration(value, VolumeConcentrationUnit::PartPerTrillion);
        }

        [[nodiscard]] static constexpr VolumeConcentration from_invalid()
        {
            return VolumeConcentration(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, VolumeConcentrationUnit unit)
        {
            switch (unit)
            {

            case VolumeConcentrationUnit::DecimalFraction:
                return value;

            case VolumeConcentrationUnit::LiterPerLiter:
                return value;

            case VolumeConcentrationUnit::PicoliterPerLiter:
                return (value * static_cast<un_scalar_t>(1e-12));

            case VolumeConcentrationUnit::NanoliterPerLiter:
                return (value * static_cast<un_scalar_t>(1e-9));

            case VolumeConcentrationUnit::MicroliterPerLiter:
                return (value * static_cast<un_scalar_t>(1e-6));

            case VolumeConcentrationUnit::MilliliterPerLiter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case VolumeConcentrationUnit::CentiliterPerLiter:
                return (value * static_cast<un_scalar_t>(1e-2));

            case VolumeConcentrationUnit::DeciliterPerLiter:
                return (value * static_cast<un_scalar_t>(1e-1));

            case VolumeConcentrationUnit::LiterPerMilliliter:
                return value / static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::PicoliterPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::NanoliterPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::MicroliterPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::MilliliterPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::CentiliterPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::DeciliterPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::Percent:
                return value / static_cast<un_scalar_t>(1e2);

            case VolumeConcentrationUnit::PartPerThousand:
                return value / static_cast<un_scalar_t>(1e3);

            case VolumeConcentrationUnit::PartPerMillion:
                return value / static_cast<un_scalar_t>(1e6);

            case VolumeConcentrationUnit::PartPerBillion:
                return value / static_cast<un_scalar_t>(1e9);

            case VolumeConcentrationUnit::PartPerTrillion:
                return value / static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown VolumeConcentration unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const VolumeConcentrationUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case VolumeConcentrationUnit::DecimalFraction:
                return base_value;

            case VolumeConcentrationUnit::LiterPerLiter:
                return base_value;

            case VolumeConcentrationUnit::PicoliterPerLiter:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case VolumeConcentrationUnit::NanoliterPerLiter:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case VolumeConcentrationUnit::MicroliterPerLiter:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case VolumeConcentrationUnit::MilliliterPerLiter:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::CentiliterPerLiter:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case VolumeConcentrationUnit::DeciliterPerLiter:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case VolumeConcentrationUnit::LiterPerMilliliter:
                return base_value * static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::PicoliterPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-12);

            case VolumeConcentrationUnit::NanoliterPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-9);

            case VolumeConcentrationUnit::MicroliterPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-6);

            case VolumeConcentrationUnit::MilliliterPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-3);

            case VolumeConcentrationUnit::CentiliterPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-2);

            case VolumeConcentrationUnit::DeciliterPerMilliliter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-1);

            case VolumeConcentrationUnit::Percent:
                return base_value * static_cast<un_scalar_t>(1e2);

            case VolumeConcentrationUnit::PartPerThousand:
                return base_value * static_cast<un_scalar_t>(1e3);

            case VolumeConcentrationUnit::PartPerMillion:
                return base_value * static_cast<un_scalar_t>(1e6);

            case VolumeConcentrationUnit::PartPerBillion:
                return base_value * static_cast<un_scalar_t>(1e9);

            case VolumeConcentrationUnit::PartPerTrillion:
                return base_value * static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown VolumeConcentration unit.");
        }

        un_scalar_t value_;
        VolumeConcentrationUnit value_unit_type_;       
    };
}
