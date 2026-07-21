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
    enum class ElectricReactiveEnergyUnit : std::uint8_t
    {
        VoltampereReactiveHour,
        KilovoltampereReactiveHour,
        MegavoltampereReactiveHour,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ElectricReactiveEnergy.</summary>
    class ElectricReactiveEnergyDto
    {
    public:
        constexpr ElectricReactiveEnergyDto() noexcept
            : value{}, unit(ElectricReactiveEnergyUnit::VoltampereReactiveHour)
        {
        }

        constexpr ElectricReactiveEnergyDto(
            const un_scalar_t value,
            const ElectricReactiveEnergyUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricReactiveEnergyUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricReactiveEnergyUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricReactiveEnergyUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricReactiveEnergy unit name.");
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
        [[nodiscard]] static ElectricReactiveEnergyDto from_json(const nlohmann::json& json)
        {
            return ElectricReactiveEnergyDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The volt-ampere reactive hour (expressed as varh) is the reactive power of one Volt-ampere reactive produced in one hour.</summary>
    class ElectricReactiveEnergy : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricReactiveEnergy(
            const un_scalar_t value,
            const ElectricReactiveEnergyUnit unit = ElectricReactiveEnergyUnit::VoltampereReactiveHour)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricReactiveEnergyUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricReactiveEnergyDto to_dto(
            const ElectricReactiveEnergyUnit unit = ElectricReactiveEnergyUnit::VoltampereReactiveHour) const
        {
            return ElectricReactiveEnergyDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricReactiveEnergy from_dto(const ElectricReactiveEnergyDto& dto)
        {
            return ElectricReactiveEnergy(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricReactiveEnergyUnit unit = ElectricReactiveEnergyUnit::VoltampereReactiveHour) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricReactiveEnergy from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricReactiveEnergyDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricReactiveEnergy operator+(const ElectricReactiveEnergy& other) const noexcept
        {
            return ElectricReactiveEnergy(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricReactiveEnergy operator-(const ElectricReactiveEnergy& other)const noexcept
        {
            return ElectricReactiveEnergy(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricReactiveEnergy operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricReactiveEnergy(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricReactiveEnergy operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricReactiveEnergy(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricReactiveEnergy& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricReactiveEnergy& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricReactiveEnergy& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t voltampere_reactive_hours() const
        {
            return convert_from_base(ElectricReactiveEnergyUnit::VoltampereReactiveHour);
        }

        [[nodiscard]] static constexpr ElectricReactiveEnergy from_voltampere_reactive_hours(const un_scalar_t value)
        {
            return ElectricReactiveEnergy(value, ElectricReactiveEnergyUnit::VoltampereReactiveHour);
        }

        [[nodiscard]] constexpr un_scalar_t kilovoltampere_reactive_hours() const
        {
            return convert_from_base(ElectricReactiveEnergyUnit::KilovoltampereReactiveHour);
        }

        [[nodiscard]] static constexpr ElectricReactiveEnergy from_kilovoltampere_reactive_hours(const un_scalar_t value)
        {
            return ElectricReactiveEnergy(value, ElectricReactiveEnergyUnit::KilovoltampereReactiveHour);
        }

        [[nodiscard]] constexpr un_scalar_t megavoltampere_reactive_hours() const
        {
            return convert_from_base(ElectricReactiveEnergyUnit::MegavoltampereReactiveHour);
        }

        [[nodiscard]] static constexpr ElectricReactiveEnergy from_megavoltampere_reactive_hours(const un_scalar_t value)
        {
            return ElectricReactiveEnergy(value, ElectricReactiveEnergyUnit::MegavoltampereReactiveHour);
        }

        [[nodiscard]] static constexpr ElectricReactiveEnergy from_invalid()
        {
            return ElectricReactiveEnergy(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricReactiveEnergyUnit unit)
        {
            switch (unit)
            {

            case ElectricReactiveEnergyUnit::VoltampereReactiveHour:
                return value;

            case ElectricReactiveEnergyUnit::KilovoltampereReactiveHour:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricReactiveEnergyUnit::MegavoltampereReactiveHour:
                return (value * static_cast<un_scalar_t>(1e6));

            }

            throw std::invalid_argument("Unknown ElectricReactiveEnergy unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricReactiveEnergyUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricReactiveEnergyUnit::VoltampereReactiveHour:
                return base_value;

            case ElectricReactiveEnergyUnit::KilovoltampereReactiveHour:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricReactiveEnergyUnit::MegavoltampereReactiveHour:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown ElectricReactiveEnergy unit.");
        }

        un_scalar_t value_;
        ElectricReactiveEnergyUnit value_unit_type_;       
    };
}
