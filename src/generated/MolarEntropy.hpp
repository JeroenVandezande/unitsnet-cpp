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
    enum class MolarEntropyUnit : std::uint8_t
    {
        JoulePerMoleKelvin,
        KilojoulePerMoleKelvin,
        MegajoulePerMoleKelvin,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of MolarEntropy.</summary>
    class MolarEntropyDto
    {
    public:
        constexpr MolarEntropyDto() noexcept
            : value{}, unit(MolarEntropyUnit::JoulePerMoleKelvin)
        {
        }

        constexpr MolarEntropyDto(
            const un_scalar_t value,
            const MolarEntropyUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        MolarEntropyUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr MolarEntropyUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<MolarEntropyUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown MolarEntropy unit name.");
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
        [[nodiscard]] static MolarEntropyDto from_json(const nlohmann::json& json)
        {
            return MolarEntropyDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Molar entropy is amount of energy required to increase temperature of 1 mole substance by 1 Kelvin.</summary>
    class MolarEntropy : public UnitsNetBase
    {
    public:
        constexpr explicit MolarEntropy(
            const un_scalar_t value,
            const MolarEntropyUnit unit = MolarEntropyUnit::JoulePerMoleKelvin)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MolarEntropyUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr MolarEntropyDto to_dto(
            const MolarEntropyUnit unit = MolarEntropyUnit::JoulePerMoleKelvin) const
        {
            return MolarEntropyDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr MolarEntropy from_dto(const MolarEntropyDto& dto)
        {
            return MolarEntropy(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const MolarEntropyUnit unit = MolarEntropyUnit::JoulePerMoleKelvin) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static MolarEntropy from_json(const nlohmann::json& json)
        {
            return from_dto(MolarEntropyDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr MolarEntropy operator+(const MolarEntropy& other) const noexcept
        {
            return MolarEntropy(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr MolarEntropy operator-(const MolarEntropy& other)const noexcept
        {
            return MolarEntropy(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr MolarEntropy operator*(const un_scalar_t scalar) const noexcept
        {
            return MolarEntropy(base_value() * scalar);
        }

        [[nodiscard]] constexpr MolarEntropy operator/(const un_scalar_t scalar) const noexcept
        {
            return MolarEntropy(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MolarEntropy& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const MolarEntropy& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const MolarEntropy& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t joules_per_mole_kelvin() const
        {
            return convert_from_base(MolarEntropyUnit::JoulePerMoleKelvin);
        }

        [[nodiscard]] static constexpr MolarEntropy from_joules_per_mole_kelvin(const un_scalar_t value)
        {
            return MolarEntropy(value, MolarEntropyUnit::JoulePerMoleKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t kilojoules_per_mole_kelvin() const
        {
            return convert_from_base(MolarEntropyUnit::KilojoulePerMoleKelvin);
        }

        [[nodiscard]] static constexpr MolarEntropy from_kilojoules_per_mole_kelvin(const un_scalar_t value)
        {
            return MolarEntropy(value, MolarEntropyUnit::KilojoulePerMoleKelvin);
        }

        [[nodiscard]] constexpr un_scalar_t megajoules_per_mole_kelvin() const
        {
            return convert_from_base(MolarEntropyUnit::MegajoulePerMoleKelvin);
        }

        [[nodiscard]] static constexpr MolarEntropy from_megajoules_per_mole_kelvin(const un_scalar_t value)
        {
            return MolarEntropy(value, MolarEntropyUnit::MegajoulePerMoleKelvin);
        }

        [[nodiscard]] static constexpr MolarEntropy from_invalid()
        {
            return MolarEntropy(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MolarEntropyUnit unit)
        {
            switch (unit)
            {

            case MolarEntropyUnit::JoulePerMoleKelvin:
                return value;

            case MolarEntropyUnit::KilojoulePerMoleKelvin:
                return (value * static_cast<un_scalar_t>(1e3));

            case MolarEntropyUnit::MegajoulePerMoleKelvin:
                return (value * static_cast<un_scalar_t>(1e6));

            }

            throw std::invalid_argument("Unknown MolarEntropy unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MolarEntropyUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case MolarEntropyUnit::JoulePerMoleKelvin:
                return base_value;

            case MolarEntropyUnit::KilojoulePerMoleKelvin:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case MolarEntropyUnit::MegajoulePerMoleKelvin:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown MolarEntropy unit.");
        }

        un_scalar_t value_;
        MolarEntropyUnit value_unit_type_;       
    };
}
