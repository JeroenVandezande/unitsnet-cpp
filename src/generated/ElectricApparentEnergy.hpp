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
    enum class ElectricApparentEnergyUnit : std::uint8_t
    {
        VoltampereHour,
        KilovoltampereHour,
        MegavoltampereHour,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ElectricApparentEnergy.</summary>
    class ElectricApparentEnergyDto
    {
    public:
        constexpr ElectricApparentEnergyDto() noexcept
            : value{}, unit(ElectricApparentEnergyUnit::VoltampereHour)
        {
        }

        constexpr ElectricApparentEnergyDto(
            const un_scalar_t value,
            const ElectricApparentEnergyUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricApparentEnergyUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricApparentEnergyUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricApparentEnergyUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricApparentEnergy unit name.");
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
        [[nodiscard]] static ElectricApparentEnergyDto from_json(const nlohmann::json& json)
        {
            return ElectricApparentEnergyDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>A unit for expressing the integral of apparent power over time, equal to the product of 1 volt-ampere and 1 hour, or to 3600 joules.</summary>
    class ElectricApparentEnergy : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricApparentEnergy(
            const un_scalar_t value,
            const ElectricApparentEnergyUnit unit = ElectricApparentEnergyUnit::VoltampereHour)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricApparentEnergyUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricApparentEnergyDto to_dto(
            const ElectricApparentEnergyUnit unit = ElectricApparentEnergyUnit::VoltampereHour) const
        {
            return ElectricApparentEnergyDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricApparentEnergy from_dto(const ElectricApparentEnergyDto& dto)
        {
            return ElectricApparentEnergy(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricApparentEnergyUnit unit = ElectricApparentEnergyUnit::VoltampereHour) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricApparentEnergy from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricApparentEnergyDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricApparentEnergy operator+(const ElectricApparentEnergy& other) const noexcept
        {
            return ElectricApparentEnergy(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricApparentEnergy operator-(const ElectricApparentEnergy& other)const noexcept
        {
            return ElectricApparentEnergy(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricApparentEnergy operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricApparentEnergy(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricApparentEnergy operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricApparentEnergy(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricApparentEnergy& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricApparentEnergy& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricApparentEnergy& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t voltampere_hours() const
        {
            return convert_from_base(ElectricApparentEnergyUnit::VoltampereHour);
        }

        [[nodiscard]] static constexpr ElectricApparentEnergy from_voltampere_hours(const un_scalar_t value)
        {
            return ElectricApparentEnergy(value, ElectricApparentEnergyUnit::VoltampereHour);
        }

        [[nodiscard]] constexpr un_scalar_t kilovoltampere_hours() const
        {
            return convert_from_base(ElectricApparentEnergyUnit::KilovoltampereHour);
        }

        [[nodiscard]] static constexpr ElectricApparentEnergy from_kilovoltampere_hours(const un_scalar_t value)
        {
            return ElectricApparentEnergy(value, ElectricApparentEnergyUnit::KilovoltampereHour);
        }

        [[nodiscard]] constexpr un_scalar_t megavoltampere_hours() const
        {
            return convert_from_base(ElectricApparentEnergyUnit::MegavoltampereHour);
        }

        [[nodiscard]] static constexpr ElectricApparentEnergy from_megavoltampere_hours(const un_scalar_t value)
        {
            return ElectricApparentEnergy(value, ElectricApparentEnergyUnit::MegavoltampereHour);
        }

        [[nodiscard]] static constexpr ElectricApparentEnergy from_invalid()
        {
            return ElectricApparentEnergy(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricApparentEnergyUnit unit)
        {
            switch (unit)
            {

            case ElectricApparentEnergyUnit::VoltampereHour:
                return value;

            case ElectricApparentEnergyUnit::KilovoltampereHour:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricApparentEnergyUnit::MegavoltampereHour:
                return (value * static_cast<un_scalar_t>(1e6));

            }

            throw std::invalid_argument("Unknown ElectricApparentEnergy unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricApparentEnergyUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricApparentEnergyUnit::VoltampereHour:
                return base_value;

            case ElectricApparentEnergyUnit::KilovoltampereHour:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricApparentEnergyUnit::MegavoltampereHour:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown ElectricApparentEnergy unit.");
        }

        un_scalar_t value_;
        ElectricApparentEnergyUnit value_unit_type_;       
    };
}
