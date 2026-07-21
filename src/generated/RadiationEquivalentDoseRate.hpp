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
    enum class RadiationEquivalentDoseRateUnit : std::uint8_t
    {
        SievertPerHour,
        NanosievertPerHour,
        MicrosievertPerHour,
        MillisievertPerHour,
        SievertPerSecond,
        NanosievertPerSecond,
        MicrosievertPerSecond,
        MillisievertPerSecond,
        RoentgenEquivalentManPerHour,
        MilliroentgenEquivalentManPerHour,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of RadiationEquivalentDoseRate.</summary>
    class RadiationEquivalentDoseRateDto
    {
    public:
        constexpr RadiationEquivalentDoseRateDto() noexcept
            : value{}, unit(RadiationEquivalentDoseRateUnit::SievertPerSecond)
        {
        }

        constexpr RadiationEquivalentDoseRateDto(
            const un_scalar_t value,
            const RadiationEquivalentDoseRateUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        RadiationEquivalentDoseRateUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr RadiationEquivalentDoseRateUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<RadiationEquivalentDoseRateUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown RadiationEquivalentDoseRate unit name.");
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
        [[nodiscard]] static RadiationEquivalentDoseRateDto from_json(const nlohmann::json& json)
        {
            return RadiationEquivalentDoseRateDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>A dose rate is quantity of radiation absorbed or delivered per unit time.</summary>
    class RadiationEquivalentDoseRate : public UnitsNetBase
    {
    public:
        constexpr explicit RadiationEquivalentDoseRate(
            const un_scalar_t value,
            const RadiationEquivalentDoseRateUnit unit = RadiationEquivalentDoseRateUnit::SievertPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const RadiationEquivalentDoseRateUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr RadiationEquivalentDoseRateDto to_dto(
            const RadiationEquivalentDoseRateUnit unit = RadiationEquivalentDoseRateUnit::SievertPerSecond) const
        {
            return RadiationEquivalentDoseRateDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_dto(const RadiationEquivalentDoseRateDto& dto)
        {
            return RadiationEquivalentDoseRate(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const RadiationEquivalentDoseRateUnit unit = RadiationEquivalentDoseRateUnit::SievertPerSecond) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static RadiationEquivalentDoseRate from_json(const nlohmann::json& json)
        {
            return from_dto(RadiationEquivalentDoseRateDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr RadiationEquivalentDoseRate operator+(const RadiationEquivalentDoseRate& other) const noexcept
        {
            return RadiationEquivalentDoseRate(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr RadiationEquivalentDoseRate operator-(const RadiationEquivalentDoseRate& other)const noexcept
        {
            return RadiationEquivalentDoseRate(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr RadiationEquivalentDoseRate operator*(const un_scalar_t scalar) const noexcept
        {
            return RadiationEquivalentDoseRate(base_value() * scalar);
        }

        [[nodiscard]] constexpr RadiationEquivalentDoseRate operator/(const un_scalar_t scalar) const noexcept
        {
            return RadiationEquivalentDoseRate(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RadiationEquivalentDoseRate& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const RadiationEquivalentDoseRate& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const RadiationEquivalentDoseRate& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t sieverts_per_hour() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::SievertPerHour);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_sieverts_per_hour(const un_scalar_t value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::SievertPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t nanosieverts_per_hour() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::NanosievertPerHour);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_nanosieverts_per_hour(const un_scalar_t value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::NanosievertPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t microsieverts_per_hour() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::MicrosievertPerHour);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_microsieverts_per_hour(const un_scalar_t value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::MicrosievertPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t millisieverts_per_hour() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::MillisievertPerHour);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_millisieverts_per_hour(const un_scalar_t value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::MillisievertPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t sieverts_per_second() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::SievertPerSecond);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_sieverts_per_second(const un_scalar_t value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::SievertPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t nanosieverts_per_second() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::NanosievertPerSecond);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_nanosieverts_per_second(const un_scalar_t value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::NanosievertPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t microsieverts_per_second() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::MicrosievertPerSecond);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_microsieverts_per_second(const un_scalar_t value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::MicrosievertPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t millisieverts_per_second() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::MillisievertPerSecond);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_millisieverts_per_second(const un_scalar_t value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::MillisievertPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t roentgens_equivalent_man_per_hour() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::RoentgenEquivalentManPerHour);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_roentgens_equivalent_man_per_hour(const un_scalar_t value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::RoentgenEquivalentManPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t milliroentgens_equivalent_man_per_hour() const
        {
            return convert_from_base(RadiationEquivalentDoseRateUnit::MilliroentgenEquivalentManPerHour);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_milliroentgens_equivalent_man_per_hour(const un_scalar_t value)
        {
            return RadiationEquivalentDoseRate(value, RadiationEquivalentDoseRateUnit::MilliroentgenEquivalentManPerHour);
        }

        [[nodiscard]] static constexpr RadiationEquivalentDoseRate from_invalid()
        {
            return RadiationEquivalentDoseRate(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RadiationEquivalentDoseRateUnit unit)
        {
            switch (unit)
            {

            case RadiationEquivalentDoseRateUnit::SievertPerHour:
                return value/static_cast<un_scalar_t>(3600);

            case RadiationEquivalentDoseRateUnit::NanosievertPerHour:
                return (value * static_cast<un_scalar_t>(1e-9))/static_cast<un_scalar_t>(3600);

            case RadiationEquivalentDoseRateUnit::MicrosievertPerHour:
                return (value * static_cast<un_scalar_t>(1e-6))/static_cast<un_scalar_t>(3600);

            case RadiationEquivalentDoseRateUnit::MillisievertPerHour:
                return (value * static_cast<un_scalar_t>(1e-3))/static_cast<un_scalar_t>(3600);

            case RadiationEquivalentDoseRateUnit::SievertPerSecond:
                return value;

            case RadiationEquivalentDoseRateUnit::NanosievertPerSecond:
                return (value * static_cast<un_scalar_t>(1e-9));

            case RadiationEquivalentDoseRateUnit::MicrosievertPerSecond:
                return (value * static_cast<un_scalar_t>(1e-6));

            case RadiationEquivalentDoseRateUnit::MillisievertPerSecond:
                return (value * static_cast<un_scalar_t>(1e-3));

            case RadiationEquivalentDoseRateUnit::RoentgenEquivalentManPerHour:
                return value / static_cast<un_scalar_t>(100) / static_cast<un_scalar_t>(3600);

            case RadiationEquivalentDoseRateUnit::MilliroentgenEquivalentManPerHour:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(100) / static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown RadiationEquivalentDoseRate unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RadiationEquivalentDoseRateUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case RadiationEquivalentDoseRateUnit::SievertPerHour:
                return base_value*static_cast<un_scalar_t>(3600);

            case RadiationEquivalentDoseRateUnit::NanosievertPerHour:
                return (base_value*static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e-9);

            case RadiationEquivalentDoseRateUnit::MicrosievertPerHour:
                return (base_value*static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e-6);

            case RadiationEquivalentDoseRateUnit::MillisievertPerHour:
                return (base_value*static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e-3);

            case RadiationEquivalentDoseRateUnit::SievertPerSecond:
                return base_value;

            case RadiationEquivalentDoseRateUnit::NanosievertPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case RadiationEquivalentDoseRateUnit::MicrosievertPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case RadiationEquivalentDoseRateUnit::MillisievertPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case RadiationEquivalentDoseRateUnit::RoentgenEquivalentManPerHour:
                return base_value * static_cast<un_scalar_t>(100) * static_cast<un_scalar_t>(3600);

            case RadiationEquivalentDoseRateUnit::MilliroentgenEquivalentManPerHour:
                return (base_value * static_cast<un_scalar_t>(100) * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown RadiationEquivalentDoseRate unit.");
        }

        un_scalar_t value_;
        RadiationEquivalentDoseRateUnit value_unit_type_;       
    };
}
