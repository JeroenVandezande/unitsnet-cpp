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
    enum class ElectricInductanceUnit : std::uint8_t
    {
        Henry,
        Picohenry,
        Nanohenry,
        Microhenry,
        Millihenry,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ElectricInductance.</summary>
    class ElectricInductanceDto
    {
    public:
        constexpr ElectricInductanceDto() noexcept
            : value{}, unit(ElectricInductanceUnit::Henry)
        {
        }

        constexpr ElectricInductanceDto(
            const un_scalar_t value,
            const ElectricInductanceUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricInductanceUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricInductanceUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricInductanceUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricInductance unit name.");
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
        [[nodiscard]] static ElectricInductanceDto from_json(const nlohmann::json& json)
        {
            return ElectricInductanceDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Inductance is a property of an electrical conductor which opposes a change in current.</summary>
    class ElectricInductance : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricInductance(
            const un_scalar_t value,
            const ElectricInductanceUnit unit = ElectricInductanceUnit::Henry)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricInductanceUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricInductanceDto to_dto(
            const ElectricInductanceUnit unit = ElectricInductanceUnit::Henry) const
        {
            return ElectricInductanceDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricInductance from_dto(const ElectricInductanceDto& dto)
        {
            return ElectricInductance(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricInductanceUnit unit = ElectricInductanceUnit::Henry) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricInductance from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricInductanceDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricInductance operator+(const ElectricInductance& other) const noexcept
        {
            return ElectricInductance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricInductance operator-(const ElectricInductance& other)const noexcept
        {
            return ElectricInductance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricInductance operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricInductance(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricInductance operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricInductance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricInductance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricInductance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricInductance& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t henries() const
        {
            return convert_from_base(ElectricInductanceUnit::Henry);
        }

        [[nodiscard]] static constexpr ElectricInductance from_henries(const un_scalar_t value)
        {
            return ElectricInductance(value, ElectricInductanceUnit::Henry);
        }

        [[nodiscard]] constexpr un_scalar_t picohenries() const
        {
            return convert_from_base(ElectricInductanceUnit::Picohenry);
        }

        [[nodiscard]] static constexpr ElectricInductance from_picohenries(const un_scalar_t value)
        {
            return ElectricInductance(value, ElectricInductanceUnit::Picohenry);
        }

        [[nodiscard]] constexpr un_scalar_t nanohenries() const
        {
            return convert_from_base(ElectricInductanceUnit::Nanohenry);
        }

        [[nodiscard]] static constexpr ElectricInductance from_nanohenries(const un_scalar_t value)
        {
            return ElectricInductance(value, ElectricInductanceUnit::Nanohenry);
        }

        [[nodiscard]] constexpr un_scalar_t microhenries() const
        {
            return convert_from_base(ElectricInductanceUnit::Microhenry);
        }

        [[nodiscard]] static constexpr ElectricInductance from_microhenries(const un_scalar_t value)
        {
            return ElectricInductance(value, ElectricInductanceUnit::Microhenry);
        }

        [[nodiscard]] constexpr un_scalar_t millihenries() const
        {
            return convert_from_base(ElectricInductanceUnit::Millihenry);
        }

        [[nodiscard]] static constexpr ElectricInductance from_millihenries(const un_scalar_t value)
        {
            return ElectricInductance(value, ElectricInductanceUnit::Millihenry);
        }

        [[nodiscard]] static constexpr ElectricInductance from_invalid()
        {
            return ElectricInductance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricInductanceUnit unit)
        {
            switch (unit)
            {

            case ElectricInductanceUnit::Henry:
                return value;

            case ElectricInductanceUnit::Picohenry:
                return (value * static_cast<un_scalar_t>(1e-12));

            case ElectricInductanceUnit::Nanohenry:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricInductanceUnit::Microhenry:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricInductanceUnit::Millihenry:
                return (value * static_cast<un_scalar_t>(1e-3));

            }

            throw std::invalid_argument("Unknown ElectricInductance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricInductanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricInductanceUnit::Henry:
                return base_value;

            case ElectricInductanceUnit::Picohenry:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case ElectricInductanceUnit::Nanohenry:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ElectricInductanceUnit::Microhenry:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricInductanceUnit::Millihenry:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown ElectricInductance unit.");
        }

        un_scalar_t value_;
        ElectricInductanceUnit value_unit_type_;       
    };
}
