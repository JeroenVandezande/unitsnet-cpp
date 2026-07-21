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
    enum class MolarEnergyUnit : std::uint8_t
    {
        JoulePerMole,
        KilojoulePerMole,
        MegajoulePerMole,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of MolarEnergy.</summary>
    class MolarEnergyDto
    {
    public:
        constexpr MolarEnergyDto() noexcept
            : value{}, unit(MolarEnergyUnit::JoulePerMole)
        {
        }

        constexpr MolarEnergyDto(
            const un_scalar_t value,
            const MolarEnergyUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        MolarEnergyUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr MolarEnergyUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<MolarEnergyUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown MolarEnergy unit name.");
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
        [[nodiscard]] static MolarEnergyDto from_json(const nlohmann::json& json)
        {
            return MolarEnergyDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Molar energy is the amount of energy stored in 1 mole of a substance.</summary>
    class MolarEnergy : public UnitsNetBase
    {
    public:
        constexpr explicit MolarEnergy(
            const un_scalar_t value,
            const MolarEnergyUnit unit = MolarEnergyUnit::JoulePerMole)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MolarEnergyUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr MolarEnergyDto to_dto(
            const MolarEnergyUnit unit = MolarEnergyUnit::JoulePerMole) const
        {
            return MolarEnergyDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr MolarEnergy from_dto(const MolarEnergyDto& dto)
        {
            return MolarEnergy(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const MolarEnergyUnit unit = MolarEnergyUnit::JoulePerMole) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static MolarEnergy from_json(const nlohmann::json& json)
        {
            return from_dto(MolarEnergyDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr MolarEnergy operator+(const MolarEnergy& other) const noexcept
        {
            return MolarEnergy(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr MolarEnergy operator-(const MolarEnergy& other)const noexcept
        {
            return MolarEnergy(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr MolarEnergy operator*(const un_scalar_t scalar) const noexcept
        {
            return MolarEnergy(base_value() * scalar);
        }

        [[nodiscard]] constexpr MolarEnergy operator/(const un_scalar_t scalar) const noexcept
        {
            return MolarEnergy(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MolarEnergy& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const MolarEnergy& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const MolarEnergy& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t joules_per_mole() const
        {
            return convert_from_base(MolarEnergyUnit::JoulePerMole);
        }

        [[nodiscard]] static constexpr MolarEnergy from_joules_per_mole(const un_scalar_t value)
        {
            return MolarEnergy(value, MolarEnergyUnit::JoulePerMole);
        }

        [[nodiscard]] constexpr un_scalar_t kilojoules_per_mole() const
        {
            return convert_from_base(MolarEnergyUnit::KilojoulePerMole);
        }

        [[nodiscard]] static constexpr MolarEnergy from_kilojoules_per_mole(const un_scalar_t value)
        {
            return MolarEnergy(value, MolarEnergyUnit::KilojoulePerMole);
        }

        [[nodiscard]] constexpr un_scalar_t megajoules_per_mole() const
        {
            return convert_from_base(MolarEnergyUnit::MegajoulePerMole);
        }

        [[nodiscard]] static constexpr MolarEnergy from_megajoules_per_mole(const un_scalar_t value)
        {
            return MolarEnergy(value, MolarEnergyUnit::MegajoulePerMole);
        }

        [[nodiscard]] static constexpr MolarEnergy from_invalid()
        {
            return MolarEnergy(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MolarEnergyUnit unit)
        {
            switch (unit)
            {

            case MolarEnergyUnit::JoulePerMole:
                return value;

            case MolarEnergyUnit::KilojoulePerMole:
                return (value * static_cast<un_scalar_t>(1e3));

            case MolarEnergyUnit::MegajoulePerMole:
                return (value * static_cast<un_scalar_t>(1e6));

            }

            throw std::invalid_argument("Unknown MolarEnergy unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MolarEnergyUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case MolarEnergyUnit::JoulePerMole:
                return base_value;

            case MolarEnergyUnit::KilojoulePerMole:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case MolarEnergyUnit::MegajoulePerMole:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown MolarEnergy unit.");
        }

        un_scalar_t value_;
        MolarEnergyUnit value_unit_type_;       
    };
}
