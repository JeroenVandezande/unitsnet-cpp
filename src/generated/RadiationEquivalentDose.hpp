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
    enum class RadiationEquivalentDoseUnit : std::uint8_t
    {
        Sievert,
        Nanosievert,
        Microsievert,
        Millisievert,
        RoentgenEquivalentMan,
        MilliroentgenEquivalentMan,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of RadiationEquivalentDose.</summary>
    class RadiationEquivalentDoseDto
    {
    public:
        constexpr RadiationEquivalentDoseDto() noexcept
            : value{}, unit(RadiationEquivalentDoseUnit::Sievert)
        {
        }

        constexpr RadiationEquivalentDoseDto(
            const un_scalar_t value,
            const RadiationEquivalentDoseUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        RadiationEquivalentDoseUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr RadiationEquivalentDoseUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<RadiationEquivalentDoseUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown RadiationEquivalentDose unit name.");
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
        [[nodiscard]] static RadiationEquivalentDoseDto from_json(const nlohmann::json& json)
        {
            return RadiationEquivalentDoseDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Equivalent dose is a dose quantity representing the stochastic health effects of low levels of ionizing radiation on the human body which represents the probability of radiation-induced cancer and genetic damage.</summary>
    class RadiationEquivalentDose : public UnitsNetBase
    {
    public:
        constexpr explicit RadiationEquivalentDose(
            const un_scalar_t value,
            const RadiationEquivalentDoseUnit unit = RadiationEquivalentDoseUnit::Sievert)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const RadiationEquivalentDoseUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr RadiationEquivalentDoseDto to_dto(
            const RadiationEquivalentDoseUnit unit = RadiationEquivalentDoseUnit::Sievert) const
        {
            return RadiationEquivalentDoseDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr RadiationEquivalentDose from_dto(const RadiationEquivalentDoseDto& dto)
        {
            return RadiationEquivalentDose(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const RadiationEquivalentDoseUnit unit = RadiationEquivalentDoseUnit::Sievert) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static RadiationEquivalentDose from_json(const nlohmann::json& json)
        {
            return from_dto(RadiationEquivalentDoseDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr RadiationEquivalentDose operator+(const RadiationEquivalentDose& other) const noexcept
        {
            return RadiationEquivalentDose(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr RadiationEquivalentDose operator-(const RadiationEquivalentDose& other)const noexcept
        {
            return RadiationEquivalentDose(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr RadiationEquivalentDose operator*(const un_scalar_t scalar) const noexcept
        {
            return RadiationEquivalentDose(base_value() * scalar);
        }

        [[nodiscard]] constexpr RadiationEquivalentDose operator/(const un_scalar_t scalar) const noexcept
        {
            return RadiationEquivalentDose(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RadiationEquivalentDose& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const RadiationEquivalentDose& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const RadiationEquivalentDose& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        /// <summary>The sievert is a unit in the International System of Units (SI) intended to represent the stochastic health risk of ionizing radiation, which is defined as the probability of causing radiation-induced cancer and genetic damage.</summary>
        [[nodiscard]] constexpr un_scalar_t sieverts() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::Sievert);
        }

        /// <summary>The sievert is a unit in the International System of Units (SI) intended to represent the stochastic health risk of ionizing radiation, which is defined as the probability of causing radiation-induced cancer and genetic damage.</summary>
        [[nodiscard]] static constexpr RadiationEquivalentDose from_sieverts(const un_scalar_t value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::Sievert);
        }

        /// <summary>The sievert is a unit in the International System of Units (SI) intended to represent the stochastic health risk of ionizing radiation, which is defined as the probability of causing radiation-induced cancer and genetic damage.</summary>
        [[nodiscard]] constexpr un_scalar_t nanosieverts() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::Nanosievert);
        }

        /// <summary>The sievert is a unit in the International System of Units (SI) intended to represent the stochastic health risk of ionizing radiation, which is defined as the probability of causing radiation-induced cancer and genetic damage.</summary>
        [[nodiscard]] static constexpr RadiationEquivalentDose from_nanosieverts(const un_scalar_t value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::Nanosievert);
        }

        /// <summary>The sievert is a unit in the International System of Units (SI) intended to represent the stochastic health risk of ionizing radiation, which is defined as the probability of causing radiation-induced cancer and genetic damage.</summary>
        [[nodiscard]] constexpr un_scalar_t microsieverts() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::Microsievert);
        }

        /// <summary>The sievert is a unit in the International System of Units (SI) intended to represent the stochastic health risk of ionizing radiation, which is defined as the probability of causing radiation-induced cancer and genetic damage.</summary>
        [[nodiscard]] static constexpr RadiationEquivalentDose from_microsieverts(const un_scalar_t value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::Microsievert);
        }

        /// <summary>The sievert is a unit in the International System of Units (SI) intended to represent the stochastic health risk of ionizing radiation, which is defined as the probability of causing radiation-induced cancer and genetic damage.</summary>
        [[nodiscard]] constexpr un_scalar_t millisieverts() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::Millisievert);
        }

        /// <summary>The sievert is a unit in the International System of Units (SI) intended to represent the stochastic health risk of ionizing radiation, which is defined as the probability of causing radiation-induced cancer and genetic damage.</summary>
        [[nodiscard]] static constexpr RadiationEquivalentDose from_millisieverts(const un_scalar_t value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::Millisievert);
        }

        [[nodiscard]] constexpr un_scalar_t roentgens_equivalent_man() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::RoentgenEquivalentMan);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDose from_roentgens_equivalent_man(const un_scalar_t value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::RoentgenEquivalentMan);
        }

        [[nodiscard]] constexpr un_scalar_t milliroentgens_equivalent_man() const
        {
            return convert_from_base(RadiationEquivalentDoseUnit::MilliroentgenEquivalentMan);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDose from_milliroentgens_equivalent_man(const un_scalar_t value)
        {
            return RadiationEquivalentDose(value, RadiationEquivalentDoseUnit::MilliroentgenEquivalentMan);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDose from_invalid()
        {
            return RadiationEquivalentDose(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RadiationEquivalentDoseUnit unit)
        {
            switch (unit)
            {

            case RadiationEquivalentDoseUnit::Sievert:
                return value;

            case RadiationEquivalentDoseUnit::Nanosievert:
                return (value * static_cast<un_scalar_t>(1e-9));

            case RadiationEquivalentDoseUnit::Microsievert:
                return (value * static_cast<un_scalar_t>(1e-6));

            case RadiationEquivalentDoseUnit::Millisievert:
                return (value * static_cast<un_scalar_t>(1e-3));

            case RadiationEquivalentDoseUnit::RoentgenEquivalentMan:
                return value / static_cast<un_scalar_t>(100);

            case RadiationEquivalentDoseUnit::MilliroentgenEquivalentMan:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(100);

            }

            throw std::invalid_argument("Unknown RadiationEquivalentDose unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RadiationEquivalentDoseUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case RadiationEquivalentDoseUnit::Sievert:
                return base_value;

            case RadiationEquivalentDoseUnit::Nanosievert:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case RadiationEquivalentDoseUnit::Microsievert:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case RadiationEquivalentDoseUnit::Millisievert:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case RadiationEquivalentDoseUnit::RoentgenEquivalentMan:
                return base_value * static_cast<un_scalar_t>(100);

            case RadiationEquivalentDoseUnit::MilliroentgenEquivalentMan:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown RadiationEquivalentDose unit.");
        }

        un_scalar_t value_;
        RadiationEquivalentDoseUnit value_unit_type_;       
    };
}
