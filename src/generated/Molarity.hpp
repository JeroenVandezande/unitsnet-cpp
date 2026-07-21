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
    enum class MolarityUnit : std::uint8_t
    {
        MolePerCubicMeter,
        KilomolePerCubicMeter,
        MolePerLiter,
        FemtomolePerLiter,
        PicomolePerLiter,
        NanomolePerLiter,
        MicromolePerLiter,
        MillimolePerLiter,
        CentimolePerLiter,
        DecimolePerLiter,
        PoundMolePerCubicFoot,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Molarity.</summary>
    class MolarityDto
    {
    public:
        constexpr MolarityDto() noexcept
            : value{}, unit(MolarityUnit::MolePerCubicMeter)
        {
        }

        constexpr MolarityDto(
            const un_scalar_t value,
            const MolarityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        MolarityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr MolarityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<MolarityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Molarity unit name.");
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
        [[nodiscard]] static MolarityDto from_json(const nlohmann::json& json)
        {
            return MolarityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Molar concentration, also called molarity, amount concentration or substance concentration, is a measure of the concentration of a solute in a solution, or of any chemical species, in terms of amount of substance in a given volume.</summary>
    class Molarity : public UnitsNetBase
    {
    public:
        constexpr explicit Molarity(
            const un_scalar_t value,
            const MolarityUnit unit = MolarityUnit::MolePerCubicMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MolarityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr MolarityDto to_dto(
            const MolarityUnit unit = MolarityUnit::MolePerCubicMeter) const
        {
            return MolarityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Molarity from_dto(const MolarityDto& dto)
        {
            return Molarity(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const MolarityUnit unit = MolarityUnit::MolePerCubicMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Molarity from_json(const nlohmann::json& json)
        {
            return from_dto(MolarityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Molarity operator+(const Molarity& other) const noexcept
        {
            return Molarity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Molarity operator-(const Molarity& other)const noexcept
        {
            return Molarity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Molarity operator*(const un_scalar_t scalar) const noexcept
        {
            return Molarity(base_value() * scalar);
        }

        [[nodiscard]] constexpr Molarity operator/(const un_scalar_t scalar) const noexcept
        {
            return Molarity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Molarity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Molarity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Molarity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t moles_per_cubic_meter() const
        {
            return convert_from_base(MolarityUnit::MolePerCubicMeter);
        }

        [[nodiscard]] static constexpr Molarity from_moles_per_cubic_meter(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::MolePerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilomoles_per_cubic_meter() const
        {
            return convert_from_base(MolarityUnit::KilomolePerCubicMeter);
        }

        [[nodiscard]] static constexpr Molarity from_kilomoles_per_cubic_meter(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::KilomolePerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t moles_per_liter() const
        {
            return convert_from_base(MolarityUnit::MolePerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_moles_per_liter(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::MolePerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t femtomoles_per_liter() const
        {
            return convert_from_base(MolarityUnit::FemtomolePerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_femtomoles_per_liter(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::FemtomolePerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t picomoles_per_liter() const
        {
            return convert_from_base(MolarityUnit::PicomolePerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_picomoles_per_liter(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::PicomolePerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t nanomoles_per_liter() const
        {
            return convert_from_base(MolarityUnit::NanomolePerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_nanomoles_per_liter(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::NanomolePerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t micromoles_per_liter() const
        {
            return convert_from_base(MolarityUnit::MicromolePerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_micromoles_per_liter(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::MicromolePerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t millimoles_per_liter() const
        {
            return convert_from_base(MolarityUnit::MillimolePerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_millimoles_per_liter(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::MillimolePerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t centimoles_per_liter() const
        {
            return convert_from_base(MolarityUnit::CentimolePerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_centimoles_per_liter(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::CentimolePerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t decimoles_per_liter() const
        {
            return convert_from_base(MolarityUnit::DecimolePerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_decimoles_per_liter(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::DecimolePerLiter);
        }

        [[nodiscard]] constexpr un_scalar_t pound_moles_per_cubic_foot() const
        {
            return convert_from_base(MolarityUnit::PoundMolePerCubicFoot);
        }

        [[nodiscard]] static constexpr Molarity from_pound_moles_per_cubic_foot(const un_scalar_t value)
        {
            return Molarity(value, MolarityUnit::PoundMolePerCubicFoot);
        }

        [[nodiscard]] static constexpr Molarity from_invalid()
        {
            return Molarity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MolarityUnit unit)
        {
            switch (unit)
            {

            case MolarityUnit::MolePerCubicMeter:
                return value;

            case MolarityUnit::KilomolePerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case MolarityUnit::MolePerLiter:
                return value / static_cast<un_scalar_t>(1e-3);

            case MolarityUnit::FemtomolePerLiter:
                return (value * static_cast<un_scalar_t>(1e-15)) / static_cast<un_scalar_t>(1e-3);

            case MolarityUnit::PicomolePerLiter:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(1e-3);

            case MolarityUnit::NanomolePerLiter:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e-3);

            case MolarityUnit::MicromolePerLiter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-3);

            case MolarityUnit::MillimolePerLiter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-3);

            case MolarityUnit::CentimolePerLiter:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e-3);

            case MolarityUnit::DecimolePerLiter:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-3);

            case MolarityUnit::PoundMolePerCubicFoot:
                return value * static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.028316846592);

            }

            throw std::invalid_argument("Unknown Molarity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MolarityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case MolarityUnit::MolePerCubicMeter:
                return base_value;

            case MolarityUnit::KilomolePerCubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case MolarityUnit::MolePerLiter:
                return base_value * static_cast<un_scalar_t>(1e-3);

            case MolarityUnit::FemtomolePerLiter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-15);

            case MolarityUnit::PicomolePerLiter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-12);

            case MolarityUnit::NanomolePerLiter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-9);

            case MolarityUnit::MicromolePerLiter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-6);

            case MolarityUnit::MillimolePerLiter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-3);

            case MolarityUnit::CentimolePerLiter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-2);

            case MolarityUnit::DecimolePerLiter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-1);

            case MolarityUnit::PoundMolePerCubicFoot:
                return base_value / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.028316846592));

            }

            throw std::invalid_argument("Unknown Molarity unit.");
        }

        un_scalar_t value_;
        MolarityUnit value_unit_type_;       
    };
}
