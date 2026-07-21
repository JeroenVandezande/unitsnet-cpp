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
    enum class MolalityUnit : std::uint8_t
    {
        MolePerKilogram,
        MillimolePerKilogram,
        MolePerGram,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Molality.</summary>
    class MolalityDto
    {
    public:
        constexpr MolalityDto() noexcept
            : value{}, unit(MolalityUnit::MolePerKilogram)
        {
        }

        constexpr MolalityDto(
            const un_scalar_t value,
            const MolalityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        MolalityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr MolalityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<MolalityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Molality unit name.");
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
        [[nodiscard]] static MolalityDto from_json(const nlohmann::json& json)
        {
            return MolalityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Molality is a measure of the amount of solute in a solution relative to a given mass of solvent.</summary>
    class Molality : public UnitsNetBase
    {
    public:
        constexpr explicit Molality(
            const un_scalar_t value,
            const MolalityUnit unit = MolalityUnit::MolePerKilogram)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MolalityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr MolalityDto to_dto(
            const MolalityUnit unit = MolalityUnit::MolePerKilogram) const
        {
            return MolalityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Molality from_dto(const MolalityDto& dto)
        {
            return Molality(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const MolalityUnit unit = MolalityUnit::MolePerKilogram) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Molality from_json(const nlohmann::json& json)
        {
            return from_dto(MolalityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Molality operator+(const Molality& other) const noexcept
        {
            return Molality(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Molality operator-(const Molality& other)const noexcept
        {
            return Molality(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Molality operator*(const un_scalar_t scalar) const noexcept
        {
            return Molality(base_value() * scalar);
        }

        [[nodiscard]] constexpr Molality operator/(const un_scalar_t scalar) const noexcept
        {
            return Molality(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Molality& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Molality& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Molality& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t moles_per_kilogram() const
        {
            return convert_from_base(MolalityUnit::MolePerKilogram);
        }

        [[nodiscard]] static constexpr Molality from_moles_per_kilogram(const un_scalar_t value)
        {
            return Molality(value, MolalityUnit::MolePerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t millimoles_per_kilogram() const
        {
            return convert_from_base(MolalityUnit::MillimolePerKilogram);
        }

        [[nodiscard]] static constexpr Molality from_millimoles_per_kilogram(const un_scalar_t value)
        {
            return Molality(value, MolalityUnit::MillimolePerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t moles_per_gram() const
        {
            return convert_from_base(MolalityUnit::MolePerGram);
        }

        [[nodiscard]] static constexpr Molality from_moles_per_gram(const un_scalar_t value)
        {
            return Molality(value, MolalityUnit::MolePerGram);
        }

        [[nodiscard]] static constexpr Molality from_invalid()
        {
            return Molality(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MolalityUnit unit)
        {
            switch (unit)
            {

            case MolalityUnit::MolePerKilogram:
                return value;

            case MolalityUnit::MillimolePerKilogram:
                return (value * static_cast<un_scalar_t>(1e-3));

            case MolalityUnit::MolePerGram:
                return value / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown Molality unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MolalityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case MolalityUnit::MolePerKilogram:
                return base_value;

            case MolalityUnit::MillimolePerKilogram:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case MolalityUnit::MolePerGram:
                return base_value * static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown Molality unit.");
        }

        un_scalar_t value_;
        MolalityUnit value_unit_type_;       
    };
}
