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
    enum class ElectricApparentPowerUnit : std::uint8_t
    {
        Voltampere,
        Microvoltampere,
        Millivoltampere,
        Kilovoltampere,
        Megavoltampere,
        Gigavoltampere,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ElectricApparentPower.</summary>
    class ElectricApparentPowerDto
    {
    public:
        constexpr ElectricApparentPowerDto() noexcept
            : value{}, unit(ElectricApparentPowerUnit::Voltampere)
        {
        }

        constexpr ElectricApparentPowerDto(
            const un_scalar_t value,
            const ElectricApparentPowerUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricApparentPowerUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricApparentPowerUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricApparentPowerUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricApparentPower unit name.");
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
        [[nodiscard]] static ElectricApparentPowerDto from_json(const nlohmann::json& json)
        {
            return ElectricApparentPowerDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Power engineers measure apparent power as the magnitude of the vector sum of active and reactive power. It is the product of the root mean square voltage (in volts) and the root mean square current (in amperes).</summary>
    class ElectricApparentPower : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricApparentPower(
            const un_scalar_t value,
            const ElectricApparentPowerUnit unit = ElectricApparentPowerUnit::Voltampere)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricApparentPowerUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricApparentPowerDto to_dto(
            const ElectricApparentPowerUnit unit = ElectricApparentPowerUnit::Voltampere) const
        {
            return ElectricApparentPowerDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricApparentPower from_dto(const ElectricApparentPowerDto& dto)
        {
            return ElectricApparentPower(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricApparentPowerUnit unit = ElectricApparentPowerUnit::Voltampere) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricApparentPower from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricApparentPowerDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricApparentPower operator+(const ElectricApparentPower& other) const noexcept
        {
            return ElectricApparentPower(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricApparentPower operator-(const ElectricApparentPower& other)const noexcept
        {
            return ElectricApparentPower(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricApparentPower operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricApparentPower(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricApparentPower operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricApparentPower(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricApparentPower& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricApparentPower& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricApparentPower& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t voltamperes() const
        {
            return convert_from_base(ElectricApparentPowerUnit::Voltampere);
        }

        [[nodiscard]] static constexpr ElectricApparentPower from_voltamperes(const un_scalar_t value)
        {
            return ElectricApparentPower(value, ElectricApparentPowerUnit::Voltampere);
        }

        [[nodiscard]] constexpr un_scalar_t microvoltamperes() const
        {
            return convert_from_base(ElectricApparentPowerUnit::Microvoltampere);
        }

        [[nodiscard]] static constexpr ElectricApparentPower from_microvoltamperes(const un_scalar_t value)
        {
            return ElectricApparentPower(value, ElectricApparentPowerUnit::Microvoltampere);
        }

        [[nodiscard]] constexpr un_scalar_t millivoltamperes() const
        {
            return convert_from_base(ElectricApparentPowerUnit::Millivoltampere);
        }

        [[nodiscard]] static constexpr ElectricApparentPower from_millivoltamperes(const un_scalar_t value)
        {
            return ElectricApparentPower(value, ElectricApparentPowerUnit::Millivoltampere);
        }

        [[nodiscard]] constexpr un_scalar_t kilovoltamperes() const
        {
            return convert_from_base(ElectricApparentPowerUnit::Kilovoltampere);
        }

        [[nodiscard]] static constexpr ElectricApparentPower from_kilovoltamperes(const un_scalar_t value)
        {
            return ElectricApparentPower(value, ElectricApparentPowerUnit::Kilovoltampere);
        }

        [[nodiscard]] constexpr un_scalar_t megavoltamperes() const
        {
            return convert_from_base(ElectricApparentPowerUnit::Megavoltampere);
        }

        [[nodiscard]] static constexpr ElectricApparentPower from_megavoltamperes(const un_scalar_t value)
        {
            return ElectricApparentPower(value, ElectricApparentPowerUnit::Megavoltampere);
        }

        [[nodiscard]] constexpr un_scalar_t gigavoltamperes() const
        {
            return convert_from_base(ElectricApparentPowerUnit::Gigavoltampere);
        }

        [[nodiscard]] static constexpr ElectricApparentPower from_gigavoltamperes(const un_scalar_t value)
        {
            return ElectricApparentPower(value, ElectricApparentPowerUnit::Gigavoltampere);
        }

        [[nodiscard]] static constexpr ElectricApparentPower from_invalid()
        {
            return ElectricApparentPower(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricApparentPowerUnit unit)
        {
            switch (unit)
            {

            case ElectricApparentPowerUnit::Voltampere:
                return value;

            case ElectricApparentPowerUnit::Microvoltampere:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricApparentPowerUnit::Millivoltampere:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricApparentPowerUnit::Kilovoltampere:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricApparentPowerUnit::Megavoltampere:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricApparentPowerUnit::Gigavoltampere:
                return (value * static_cast<un_scalar_t>(1e9));

            }

            throw std::invalid_argument("Unknown ElectricApparentPower unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricApparentPowerUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricApparentPowerUnit::Voltampere:
                return base_value;

            case ElectricApparentPowerUnit::Microvoltampere:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricApparentPowerUnit::Millivoltampere:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricApparentPowerUnit::Kilovoltampere:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricApparentPowerUnit::Megavoltampere:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ElectricApparentPowerUnit::Gigavoltampere:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            }

            throw std::invalid_argument("Unknown ElectricApparentPower unit.");
        }

        un_scalar_t value_;
        ElectricApparentPowerUnit value_unit_type_;       
    };
}
