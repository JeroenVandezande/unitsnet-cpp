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
    enum class ElectricImpedanceUnit : std::uint8_t
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
    /// <summary>A data-transfer representation of ElectricImpedance.</summary>
    class ElectricImpedanceDto
    {
    public:
        constexpr ElectricImpedanceDto() noexcept
            : value{}, unit(ElectricImpedanceUnit::Ohm)
        {
        }

        constexpr ElectricImpedanceDto(
            const un_scalar_t value,
            const ElectricImpedanceUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricImpedanceUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricImpedanceUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricImpedanceUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricImpedance unit name.");
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
        [[nodiscard]] static ElectricImpedanceDto from_json(const nlohmann::json& json)
        {
            return ElectricImpedanceDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Electric impedance is the opposition to alternating current presented by the combined effect of resistance and reactance in a circuit. It is defined as the inverse of admittance. The SI unit of impedance is the ohm (symbol Ω).</summary>
    class ElectricImpedance : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricImpedance(
            const un_scalar_t value,
            const ElectricImpedanceUnit unit = ElectricImpedanceUnit::Ohm)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricImpedanceUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricImpedanceDto to_dto(
            const ElectricImpedanceUnit unit = ElectricImpedanceUnit::Ohm) const
        {
            return ElectricImpedanceDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricImpedance from_dto(const ElectricImpedanceDto& dto)
        {
            return ElectricImpedance(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricImpedanceUnit unit = ElectricImpedanceUnit::Ohm) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricImpedance from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricImpedanceDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricImpedance operator+(const ElectricImpedance& other) const noexcept
        {
            return ElectricImpedance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricImpedance operator-(const ElectricImpedance& other)const noexcept
        {
            return ElectricImpedance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricImpedance operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricImpedance(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricImpedance operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricImpedance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricImpedance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricImpedance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricImpedance& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t ohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Ohm);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_ohms(const un_scalar_t value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Ohm);
        }

        [[nodiscard]] constexpr un_scalar_t nanoohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Nanoohm);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_nanoohms(const un_scalar_t value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Nanoohm);
        }

        [[nodiscard]] constexpr un_scalar_t microohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Microohm);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_microohms(const un_scalar_t value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Microohm);
        }

        [[nodiscard]] constexpr un_scalar_t milliohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Milliohm);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_milliohms(const un_scalar_t value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Milliohm);
        }

        [[nodiscard]] constexpr un_scalar_t kiloohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Kiloohm);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_kiloohms(const un_scalar_t value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Kiloohm);
        }

        [[nodiscard]] constexpr un_scalar_t megaohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Megaohm);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_megaohms(const un_scalar_t value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Megaohm);
        }

        [[nodiscard]] constexpr un_scalar_t gigaohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Gigaohm);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_gigaohms(const un_scalar_t value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Gigaohm);
        }

        [[nodiscard]] constexpr un_scalar_t teraohms() const
        {
            return convert_from_base(ElectricImpedanceUnit::Teraohm);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_teraohms(const un_scalar_t value)
        {
            return ElectricImpedance(value, ElectricImpedanceUnit::Teraohm);
        }

        [[nodiscard]] static constexpr ElectricImpedance from_invalid()
        {
            return ElectricImpedance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricImpedanceUnit unit)
        {
            switch (unit)
            {

            case ElectricImpedanceUnit::Ohm:
                return value;

            case ElectricImpedanceUnit::Nanoohm:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricImpedanceUnit::Microohm:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricImpedanceUnit::Milliohm:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricImpedanceUnit::Kiloohm:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricImpedanceUnit::Megaohm:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricImpedanceUnit::Gigaohm:
                return (value * static_cast<un_scalar_t>(1e9));

            case ElectricImpedanceUnit::Teraohm:
                return (value * static_cast<un_scalar_t>(1e12));

            }

            throw std::invalid_argument("Unknown ElectricImpedance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricImpedanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricImpedanceUnit::Ohm:
                return base_value;

            case ElectricImpedanceUnit::Nanoohm:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ElectricImpedanceUnit::Microohm:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricImpedanceUnit::Milliohm:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricImpedanceUnit::Kiloohm:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricImpedanceUnit::Megaohm:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ElectricImpedanceUnit::Gigaohm:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case ElectricImpedanceUnit::Teraohm:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown ElectricImpedance unit.");
        }

        un_scalar_t value_;
        ElectricImpedanceUnit value_unit_type_;       
    };
}
