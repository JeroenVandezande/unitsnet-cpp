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
    enum class ElectricReactivePowerUnit : std::uint8_t
    {
        VoltampereReactive,
        KilovoltampereReactive,
        MegavoltampereReactive,
        GigavoltampereReactive,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ElectricReactivePower.</summary>
    class ElectricReactivePowerDto
    {
    public:
        constexpr ElectricReactivePowerDto() noexcept
            : value{}, unit(ElectricReactivePowerUnit::VoltampereReactive)
        {
        }

        constexpr ElectricReactivePowerDto(
            const un_scalar_t value,
            const ElectricReactivePowerUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricReactivePowerUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricReactivePowerUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricReactivePowerUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricReactivePower unit name.");
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
        [[nodiscard]] static ElectricReactivePowerDto from_json(const nlohmann::json& json)
        {
            return ElectricReactivePowerDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In electric power transmission and distribution, volt-ampere reactive (var) is a unit of measurement of reactive power. Reactive power exists in an AC circuit when the current and voltage are not in phase.</summary>
    class ElectricReactivePower : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricReactivePower(
            const un_scalar_t value,
            const ElectricReactivePowerUnit unit = ElectricReactivePowerUnit::VoltampereReactive)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricReactivePowerUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricReactivePowerDto to_dto(
            const ElectricReactivePowerUnit unit = ElectricReactivePowerUnit::VoltampereReactive) const
        {
            return ElectricReactivePowerDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricReactivePower from_dto(const ElectricReactivePowerDto& dto)
        {
            return ElectricReactivePower(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricReactivePowerUnit unit = ElectricReactivePowerUnit::VoltampereReactive) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricReactivePower from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricReactivePowerDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricReactivePower operator+(const ElectricReactivePower& other) const noexcept
        {
            return ElectricReactivePower(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricReactivePower operator-(const ElectricReactivePower& other)const noexcept
        {
            return ElectricReactivePower(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricReactivePower operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricReactivePower(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricReactivePower operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricReactivePower(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricReactivePower& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricReactivePower& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricReactivePower& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t voltamperes_reactive() const
        {
            return convert_from_base(ElectricReactivePowerUnit::VoltampereReactive);
        }

        [[nodiscard]] static constexpr ElectricReactivePower from_voltamperes_reactive(const un_scalar_t value)
        {
            return ElectricReactivePower(value, ElectricReactivePowerUnit::VoltampereReactive);
        }

        [[nodiscard]] constexpr un_scalar_t kilovoltamperes_reactive() const
        {
            return convert_from_base(ElectricReactivePowerUnit::KilovoltampereReactive);
        }

        [[nodiscard]] static constexpr ElectricReactivePower from_kilovoltamperes_reactive(const un_scalar_t value)
        {
            return ElectricReactivePower(value, ElectricReactivePowerUnit::KilovoltampereReactive);
        }

        [[nodiscard]] constexpr un_scalar_t megavoltamperes_reactive() const
        {
            return convert_from_base(ElectricReactivePowerUnit::MegavoltampereReactive);
        }

        [[nodiscard]] static constexpr ElectricReactivePower from_megavoltamperes_reactive(const un_scalar_t value)
        {
            return ElectricReactivePower(value, ElectricReactivePowerUnit::MegavoltampereReactive);
        }

        [[nodiscard]] constexpr un_scalar_t gigavoltamperes_reactive() const
        {
            return convert_from_base(ElectricReactivePowerUnit::GigavoltampereReactive);
        }

        [[nodiscard]] static constexpr ElectricReactivePower from_gigavoltamperes_reactive(const un_scalar_t value)
        {
            return ElectricReactivePower(value, ElectricReactivePowerUnit::GigavoltampereReactive);
        }

        [[nodiscard]] static constexpr ElectricReactivePower from_invalid()
        {
            return ElectricReactivePower(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricReactivePowerUnit unit)
        {
            switch (unit)
            {

            case ElectricReactivePowerUnit::VoltampereReactive:
                return value;

            case ElectricReactivePowerUnit::KilovoltampereReactive:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricReactivePowerUnit::MegavoltampereReactive:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricReactivePowerUnit::GigavoltampereReactive:
                return (value * static_cast<un_scalar_t>(1e9));

            }

            throw std::invalid_argument("Unknown ElectricReactivePower unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricReactivePowerUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricReactivePowerUnit::VoltampereReactive:
                return base_value;

            case ElectricReactivePowerUnit::KilovoltampereReactive:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricReactivePowerUnit::MegavoltampereReactive:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ElectricReactivePowerUnit::GigavoltampereReactive:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            }

            throw std::invalid_argument("Unknown ElectricReactivePower unit.");
        }

        un_scalar_t value_;
        ElectricReactivePowerUnit value_unit_type_;       
    };
}
