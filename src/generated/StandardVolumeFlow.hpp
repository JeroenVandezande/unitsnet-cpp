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
    enum class StandardVolumeFlowUnit : std::uint8_t
    {
        StandardCubicMeterPerSecond,
        StandardCubicMeterPerMinute,
        StandardCubicMeterPerHour,
        StandardCubicMeterPerDay,
        StandardCubicCentimeterPerMinute,
        StandardLiterPerMinute,
        StandardCubicFootPerSecond,
        StandardCubicFootPerMinute,
        StandardCubicFootPerHour,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of StandardVolumeFlow.</summary>
    class StandardVolumeFlowDto
    {
    public:
        constexpr StandardVolumeFlowDto() noexcept
            : value{}, unit(StandardVolumeFlowUnit::StandardCubicMeterPerSecond)
        {
        }

        constexpr StandardVolumeFlowDto(
            const un_scalar_t value,
            const StandardVolumeFlowUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        StandardVolumeFlowUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr StandardVolumeFlowUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<StandardVolumeFlowUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown StandardVolumeFlow unit name.");
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
        [[nodiscard]] static StandardVolumeFlowDto from_json(const nlohmann::json& json)
        {
            return StandardVolumeFlowDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The molar flow rate of a gas corrected to standardized conditions of temperature and pressure thus representing a fixed number of moles of gas regardless of composition and actual flow conditions.</summary>
    class StandardVolumeFlow : public UnitsNetBase
    {
    public:
        constexpr explicit StandardVolumeFlow(
            const un_scalar_t value,
            const StandardVolumeFlowUnit unit = StandardVolumeFlowUnit::StandardCubicMeterPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const StandardVolumeFlowUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr StandardVolumeFlowDto to_dto(
            const StandardVolumeFlowUnit unit = StandardVolumeFlowUnit::StandardCubicMeterPerSecond) const
        {
            return StandardVolumeFlowDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr StandardVolumeFlow from_dto(const StandardVolumeFlowDto& dto)
        {
            return StandardVolumeFlow(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const StandardVolumeFlowUnit unit = StandardVolumeFlowUnit::StandardCubicMeterPerSecond) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static StandardVolumeFlow from_json(const nlohmann::json& json)
        {
            return from_dto(StandardVolumeFlowDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr StandardVolumeFlow operator+(const StandardVolumeFlow& other) const noexcept
        {
            return StandardVolumeFlow(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr StandardVolumeFlow operator-(const StandardVolumeFlow& other)const noexcept
        {
            return StandardVolumeFlow(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr StandardVolumeFlow operator*(const un_scalar_t scalar) const noexcept
        {
            return StandardVolumeFlow(base_value() * scalar);
        }

        [[nodiscard]] constexpr StandardVolumeFlow operator/(const un_scalar_t scalar) const noexcept
        {
            return StandardVolumeFlow(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const StandardVolumeFlow& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const StandardVolumeFlow& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const StandardVolumeFlow& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t standard_cubic_meters_per_second() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicMeterPerSecond);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_meters_per_second(const un_scalar_t value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicMeterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t standard_cubic_meters_per_minute() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicMeterPerMinute);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_meters_per_minute(const un_scalar_t value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicMeterPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t standard_cubic_meters_per_hour() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicMeterPerHour);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_meters_per_hour(const un_scalar_t value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicMeterPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t standard_cubic_meters_per_day() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicMeterPerDay);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_meters_per_day(const un_scalar_t value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicMeterPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t standard_cubic_centimeters_per_minute() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicCentimeterPerMinute);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_centimeters_per_minute(const un_scalar_t value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicCentimeterPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t standard_liters_per_minute() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardLiterPerMinute);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_liters_per_minute(const un_scalar_t value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardLiterPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t standard_cubic_feet_per_second() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicFootPerSecond);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_feet_per_second(const un_scalar_t value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicFootPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t standard_cubic_feet_per_minute() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicFootPerMinute);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_feet_per_minute(const un_scalar_t value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicFootPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t standard_cubic_feet_per_hour() const
        {
            return convert_from_base(StandardVolumeFlowUnit::StandardCubicFootPerHour);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_standard_cubic_feet_per_hour(const un_scalar_t value)
        {
            return StandardVolumeFlow(value, StandardVolumeFlowUnit::StandardCubicFootPerHour);
        }

        [[nodiscard]] static constexpr StandardVolumeFlow from_invalid()
        {
            return StandardVolumeFlow(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, StandardVolumeFlowUnit unit)
        {
            switch (unit)
            {

            case StandardVolumeFlowUnit::StandardCubicMeterPerSecond:
                return value;

            case StandardVolumeFlowUnit::StandardCubicMeterPerMinute:
                return value / static_cast<un_scalar_t>(60);

            case StandardVolumeFlowUnit::StandardCubicMeterPerHour:
                return value / static_cast<un_scalar_t>(3600);

            case StandardVolumeFlowUnit::StandardCubicMeterPerDay:
                return value / static_cast<un_scalar_t>(86400);

            case StandardVolumeFlowUnit::StandardCubicCentimeterPerMinute:
                return value / static_cast<un_scalar_t>(6e7);

            case StandardVolumeFlowUnit::StandardLiterPerMinute:
                return value / static_cast<un_scalar_t>(60000);

            case StandardVolumeFlowUnit::StandardCubicFootPerSecond:
                return value * static_cast<un_scalar_t>(0.028316846592);

            case StandardVolumeFlowUnit::StandardCubicFootPerMinute:
                return value * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(60);

            case StandardVolumeFlowUnit::StandardCubicFootPerHour:
                return value * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown StandardVolumeFlow unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const StandardVolumeFlowUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case StandardVolumeFlowUnit::StandardCubicMeterPerSecond:
                return base_value;

            case StandardVolumeFlowUnit::StandardCubicMeterPerMinute:
                return base_value * static_cast<un_scalar_t>(60);

            case StandardVolumeFlowUnit::StandardCubicMeterPerHour:
                return base_value * static_cast<un_scalar_t>(3600);

            case StandardVolumeFlowUnit::StandardCubicMeterPerDay:
                return base_value * static_cast<un_scalar_t>(86400);

            case StandardVolumeFlowUnit::StandardCubicCentimeterPerMinute:
                return base_value * static_cast<un_scalar_t>(6e7);

            case StandardVolumeFlowUnit::StandardLiterPerMinute:
                return base_value * static_cast<un_scalar_t>(60000);

            case StandardVolumeFlowUnit::StandardCubicFootPerSecond:
                return base_value / static_cast<un_scalar_t>(0.028316846592);

            case StandardVolumeFlowUnit::StandardCubicFootPerMinute:
                return base_value / (static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(60));

            case StandardVolumeFlowUnit::StandardCubicFootPerHour:
                return base_value / (static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(3600));

            }

            throw std::invalid_argument("Unknown StandardVolumeFlow unit.");
        }

        un_scalar_t value_;
        StandardVolumeFlowUnit value_unit_type_;       
    };
}
