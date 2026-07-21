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
    enum class ElectricReactanceUnit : std::uint8_t
    {
        Ohm,
        Nanoohm,
        Microohm,
        Milliohm,
        Kiloohm,
        Megaohm,
        Gigaohm,
        Teraohm,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ElectricReactance.</summary>
    class ElectricReactanceDto
    {
    public:
        constexpr ElectricReactanceDto() noexcept
            : value{}, unit(ElectricReactanceUnit::Ohm)
        {
        }

        constexpr ElectricReactanceDto(
            const un_scalar_t value,
            const ElectricReactanceUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricReactanceUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricReactanceUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricReactanceUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricReactance unit name.");
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
        [[nodiscard]] static ElectricReactanceDto from_json(const nlohmann::json& json)
        {
            return ElectricReactanceDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In electrical circuits, reactance is the opposition presented to alternating current by inductance and capacitance. Along with resistance, it is one of two elements of impedance.</summary>
    class ElectricReactance : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricReactance(
            const un_scalar_t value,
            const ElectricReactanceUnit unit = ElectricReactanceUnit::Ohm)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricReactanceUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricReactanceDto to_dto(
            const ElectricReactanceUnit unit = ElectricReactanceUnit::Ohm) const
        {
            return ElectricReactanceDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricReactance from_dto(const ElectricReactanceDto& dto)
        {
            return ElectricReactance(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricReactanceUnit unit = ElectricReactanceUnit::Ohm) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricReactance from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricReactanceDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricReactance operator+(const ElectricReactance& other) const noexcept
        {
            return ElectricReactance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricReactance operator-(const ElectricReactance& other)const noexcept
        {
            return ElectricReactance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricReactance operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricReactance(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricReactance operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricReactance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricReactance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricReactance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricReactance& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t ohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Ohm);
        }

        [[nodiscard]] static constexpr ElectricReactance from_ohms(const un_scalar_t value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Ohm);
        }

        [[nodiscard]] constexpr un_scalar_t nanoohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Nanoohm);
        }

        [[nodiscard]] static constexpr ElectricReactance from_nanoohms(const un_scalar_t value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Nanoohm);
        }

        [[nodiscard]] constexpr un_scalar_t microohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Microohm);
        }

        [[nodiscard]] static constexpr ElectricReactance from_microohms(const un_scalar_t value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Microohm);
        }

        [[nodiscard]] constexpr un_scalar_t milliohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Milliohm);
        }

        [[nodiscard]] static constexpr ElectricReactance from_milliohms(const un_scalar_t value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Milliohm);
        }

        [[nodiscard]] constexpr un_scalar_t kiloohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Kiloohm);
        }

        [[nodiscard]] static constexpr ElectricReactance from_kiloohms(const un_scalar_t value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Kiloohm);
        }

        [[nodiscard]] constexpr un_scalar_t megaohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Megaohm);
        }

        [[nodiscard]] static constexpr ElectricReactance from_megaohms(const un_scalar_t value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Megaohm);
        }

        [[nodiscard]] constexpr un_scalar_t gigaohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Gigaohm);
        }

        [[nodiscard]] static constexpr ElectricReactance from_gigaohms(const un_scalar_t value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Gigaohm);
        }

        [[nodiscard]] constexpr un_scalar_t teraohms() const
        {
            return convert_from_base(ElectricReactanceUnit::Teraohm);
        }

        [[nodiscard]] static constexpr ElectricReactance from_teraohms(const un_scalar_t value)
        {
            return ElectricReactance(value, ElectricReactanceUnit::Teraohm);
        }

        [[nodiscard]] static constexpr ElectricReactance from_invalid()
        {
            return ElectricReactance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricReactanceUnit unit)
        {
            switch (unit)
            {

            case ElectricReactanceUnit::Ohm:
                return value;

            case ElectricReactanceUnit::Nanoohm:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricReactanceUnit::Microohm:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricReactanceUnit::Milliohm:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricReactanceUnit::Kiloohm:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricReactanceUnit::Megaohm:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricReactanceUnit::Gigaohm:
                return (value * static_cast<un_scalar_t>(1e9));

            case ElectricReactanceUnit::Teraohm:
                return (value * static_cast<un_scalar_t>(1e12));

            }

            throw std::invalid_argument("Unknown ElectricReactance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricReactanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricReactanceUnit::Ohm:
                return base_value;

            case ElectricReactanceUnit::Nanoohm:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ElectricReactanceUnit::Microohm:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricReactanceUnit::Milliohm:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricReactanceUnit::Kiloohm:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricReactanceUnit::Megaohm:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ElectricReactanceUnit::Gigaohm:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case ElectricReactanceUnit::Teraohm:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown ElectricReactance unit.");
        }

        un_scalar_t value_;
        ElectricReactanceUnit value_unit_type_;       
    };
}
