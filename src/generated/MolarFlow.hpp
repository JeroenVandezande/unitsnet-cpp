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
    enum class MolarFlowUnit : std::uint8_t
    {
        MolePerSecond,
        KilomolePerSecond,
        MolePerMinute,
        KilomolePerMinute,
        MolePerHour,
        KilomolePerHour,
        PoundMolePerSecond,
        PoundMolePerMinute,
        PoundMolePerHour,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of MolarFlow.</summary>
    class MolarFlowDto
    {
    public:
        constexpr MolarFlowDto() noexcept
            : value{}, unit(MolarFlowUnit::MolePerSecond)
        {
        }

        constexpr MolarFlowDto(
            const un_scalar_t value,
            const MolarFlowUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        MolarFlowUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr MolarFlowUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<MolarFlowUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown MolarFlow unit name.");
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
        [[nodiscard]] static MolarFlowDto from_json(const nlohmann::json& json)
        {
            return MolarFlowDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Molar flow is the ratio of the amount of substance change to the time during which the change occurred (value of amount of substance changes per unit time).</summary>
    class MolarFlow : public UnitsNetBase
    {
    public:
        constexpr explicit MolarFlow(
            const un_scalar_t value,
            const MolarFlowUnit unit = MolarFlowUnit::MolePerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MolarFlowUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr MolarFlowDto to_dto(
            const MolarFlowUnit unit = MolarFlowUnit::MolePerSecond) const
        {
            return MolarFlowDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr MolarFlow from_dto(const MolarFlowDto& dto)
        {
            return MolarFlow(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const MolarFlowUnit unit = MolarFlowUnit::MolePerSecond) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static MolarFlow from_json(const nlohmann::json& json)
        {
            return from_dto(MolarFlowDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr MolarFlow operator+(const MolarFlow& other) const noexcept
        {
            return MolarFlow(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr MolarFlow operator-(const MolarFlow& other)const noexcept
        {
            return MolarFlow(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr MolarFlow operator*(const un_scalar_t scalar) const noexcept
        {
            return MolarFlow(base_value() * scalar);
        }

        [[nodiscard]] constexpr MolarFlow operator/(const un_scalar_t scalar) const noexcept
        {
            return MolarFlow(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MolarFlow& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const MolarFlow& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const MolarFlow& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t moles_per_second() const
        {
            return convert_from_base(MolarFlowUnit::MolePerSecond);
        }

        [[nodiscard]] static constexpr MolarFlow from_moles_per_second(const un_scalar_t value)
        {
            return MolarFlow(value, MolarFlowUnit::MolePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kilomoles_per_second() const
        {
            return convert_from_base(MolarFlowUnit::KilomolePerSecond);
        }

        [[nodiscard]] static constexpr MolarFlow from_kilomoles_per_second(const un_scalar_t value)
        {
            return MolarFlow(value, MolarFlowUnit::KilomolePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t moles_per_minute() const
        {
            return convert_from_base(MolarFlowUnit::MolePerMinute);
        }

        [[nodiscard]] static constexpr MolarFlow from_moles_per_minute(const un_scalar_t value)
        {
            return MolarFlow(value, MolarFlowUnit::MolePerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t kilomoles_per_minute() const
        {
            return convert_from_base(MolarFlowUnit::KilomolePerMinute);
        }

        [[nodiscard]] static constexpr MolarFlow from_kilomoles_per_minute(const un_scalar_t value)
        {
            return MolarFlow(value, MolarFlowUnit::KilomolePerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t moles_per_hour() const
        {
            return convert_from_base(MolarFlowUnit::MolePerHour);
        }

        [[nodiscard]] static constexpr MolarFlow from_moles_per_hour(const un_scalar_t value)
        {
            return MolarFlow(value, MolarFlowUnit::MolePerHour);
        }

        [[nodiscard]] constexpr un_scalar_t kilomoles_per_hour() const
        {
            return convert_from_base(MolarFlowUnit::KilomolePerHour);
        }

        [[nodiscard]] static constexpr MolarFlow from_kilomoles_per_hour(const un_scalar_t value)
        {
            return MolarFlow(value, MolarFlowUnit::KilomolePerHour);
        }

        [[nodiscard]] constexpr un_scalar_t pound_moles_per_second() const
        {
            return convert_from_base(MolarFlowUnit::PoundMolePerSecond);
        }

        [[nodiscard]] static constexpr MolarFlow from_pound_moles_per_second(const un_scalar_t value)
        {
            return MolarFlow(value, MolarFlowUnit::PoundMolePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t pound_moles_per_minute() const
        {
            return convert_from_base(MolarFlowUnit::PoundMolePerMinute);
        }

        [[nodiscard]] static constexpr MolarFlow from_pound_moles_per_minute(const un_scalar_t value)
        {
            return MolarFlow(value, MolarFlowUnit::PoundMolePerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t pound_moles_per_hour() const
        {
            return convert_from_base(MolarFlowUnit::PoundMolePerHour);
        }

        [[nodiscard]] static constexpr MolarFlow from_pound_moles_per_hour(const un_scalar_t value)
        {
            return MolarFlow(value, MolarFlowUnit::PoundMolePerHour);
        }

        [[nodiscard]] static constexpr MolarFlow from_invalid()
        {
            return MolarFlow(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MolarFlowUnit unit)
        {
            switch (unit)
            {

            case MolarFlowUnit::MolePerSecond:
                return value;

            case MolarFlowUnit::KilomolePerSecond:
                return (value * static_cast<un_scalar_t>(1e3));

            case MolarFlowUnit::MolePerMinute:
                return value / static_cast<un_scalar_t>(60);

            case MolarFlowUnit::KilomolePerMinute:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(60);

            case MolarFlowUnit::MolePerHour:
                return value / static_cast<un_scalar_t>(3600);

            case MolarFlowUnit::KilomolePerHour:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(3600);

            case MolarFlowUnit::PoundMolePerSecond:
                return value * static_cast<un_scalar_t>(453.59237);

            case MolarFlowUnit::PoundMolePerMinute:
                return (value * static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(60);

            case MolarFlowUnit::PoundMolePerHour:
                return (value * static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown MolarFlow unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MolarFlowUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case MolarFlowUnit::MolePerSecond:
                return base_value;

            case MolarFlowUnit::KilomolePerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case MolarFlowUnit::MolePerMinute:
                return base_value * static_cast<un_scalar_t>(60);

            case MolarFlowUnit::KilomolePerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e3);

            case MolarFlowUnit::MolePerHour:
                return base_value * static_cast<un_scalar_t>(3600);

            case MolarFlowUnit::KilomolePerHour:
                return (base_value * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e3);

            case MolarFlowUnit::PoundMolePerSecond:
                return base_value / static_cast<un_scalar_t>(453.59237);

            case MolarFlowUnit::PoundMolePerMinute:
                return (base_value / static_cast<un_scalar_t>(453.59237)) * static_cast<un_scalar_t>(60);

            case MolarFlowUnit::PoundMolePerHour:
                return (base_value / static_cast<un_scalar_t>(453.59237)) * static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown MolarFlow unit.");
        }

        un_scalar_t value_;
        MolarFlowUnit value_unit_type_;       
    };
}
