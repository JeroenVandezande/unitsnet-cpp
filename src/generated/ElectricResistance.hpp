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
    enum class ElectricResistanceUnit : std::uint8_t
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
    /// <summary>A data-transfer representation of ElectricResistance.</summary>
    class ElectricResistanceDto
    {
    public:
        constexpr ElectricResistanceDto() noexcept
            : value{}, unit(ElectricResistanceUnit::Ohm)
        {
        }

        constexpr ElectricResistanceDto(
            const un_scalar_t value,
            const ElectricResistanceUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricResistanceUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricResistanceUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricResistanceUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricResistance unit name.");
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
        [[nodiscard]] static ElectricResistanceDto from_json(const nlohmann::json& json)
        {
            return ElectricResistanceDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The electrical resistance of an object is a measure of its opposition to the flow of electric current. Along with reactance, it is one of two elements of impedance. Its reciprocal quantity is electrical conductance.</summary>
    class ElectricResistance : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricResistance(
            const un_scalar_t value,
            const ElectricResistanceUnit unit = ElectricResistanceUnit::Ohm)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricResistanceUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricResistanceDto to_dto(
            const ElectricResistanceUnit unit = ElectricResistanceUnit::Ohm) const
        {
            return ElectricResistanceDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricResistance from_dto(const ElectricResistanceDto& dto)
        {
            return ElectricResistance(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricResistanceUnit unit = ElectricResistanceUnit::Ohm) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricResistance from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricResistanceDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricResistance operator+(const ElectricResistance& other) const noexcept
        {
            return ElectricResistance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricResistance operator-(const ElectricResistance& other)const noexcept
        {
            return ElectricResistance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricResistance operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricResistance(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricResistance operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricResistance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricResistance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricResistance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricResistance& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t ohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Ohm);
        }

        [[nodiscard]] static constexpr ElectricResistance from_ohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Ohm);
        }

        [[nodiscard]] constexpr un_scalar_t nanoohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Nanoohm);
        }

        [[nodiscard]] static constexpr ElectricResistance from_nanoohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Nanoohm);
        }

        [[nodiscard]] constexpr un_scalar_t microohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Microohm);
        }

        [[nodiscard]] static constexpr ElectricResistance from_microohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Microohm);
        }

        [[nodiscard]] constexpr un_scalar_t milliohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Milliohm);
        }

        [[nodiscard]] static constexpr ElectricResistance from_milliohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Milliohm);
        }

        [[nodiscard]] constexpr un_scalar_t kiloohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Kiloohm);
        }

        [[nodiscard]] static constexpr ElectricResistance from_kiloohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Kiloohm);
        }

        [[nodiscard]] constexpr un_scalar_t megaohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Megaohm);
        }

        [[nodiscard]] static constexpr ElectricResistance from_megaohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Megaohm);
        }

        [[nodiscard]] constexpr un_scalar_t gigaohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Gigaohm);
        }

        [[nodiscard]] static constexpr ElectricResistance from_gigaohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Gigaohm);
        }

        [[nodiscard]] constexpr un_scalar_t teraohms() const
        {
            return convert_from_base(ElectricResistanceUnit::Teraohm);
        }

        [[nodiscard]] static constexpr ElectricResistance from_teraohms(const un_scalar_t value)
        {
            return ElectricResistance(value, ElectricResistanceUnit::Teraohm);
        }

        [[nodiscard]] static constexpr ElectricResistance from_invalid()
        {
            return ElectricResistance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricResistanceUnit unit)
        {
            switch (unit)
            {

            case ElectricResistanceUnit::Ohm:
                return value;

            case ElectricResistanceUnit::Nanoohm:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricResistanceUnit::Microohm:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricResistanceUnit::Milliohm:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricResistanceUnit::Kiloohm:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricResistanceUnit::Megaohm:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricResistanceUnit::Gigaohm:
                return (value * static_cast<un_scalar_t>(1e9));

            case ElectricResistanceUnit::Teraohm:
                return (value * static_cast<un_scalar_t>(1e12));

            }

            throw std::invalid_argument("Unknown ElectricResistance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricResistanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricResistanceUnit::Ohm:
                return base_value;

            case ElectricResistanceUnit::Nanoohm:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ElectricResistanceUnit::Microohm:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricResistanceUnit::Milliohm:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricResistanceUnit::Kiloohm:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricResistanceUnit::Megaohm:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ElectricResistanceUnit::Gigaohm:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case ElectricResistanceUnit::Teraohm:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown ElectricResistance unit.");
        }

        un_scalar_t value_;
        ElectricResistanceUnit value_unit_type_;       
    };
}
