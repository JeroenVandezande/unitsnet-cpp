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
    enum class TemperatureDeltaUnit : std::uint8_t
    {
        Kelvin,
        DegreeCelsius,
        MillidegreeCelsius,
        DegreeDelisle,
        DegreeFahrenheit,
        DegreeNewton,
        DegreeRankine,
        DegreeReaumur,
        DegreeRoemer,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of TemperatureDelta.</summary>
    class TemperatureDeltaDto
    {
    public:
        constexpr TemperatureDeltaDto() noexcept
            : value{}, unit(TemperatureDeltaUnit::Kelvin)
        {
        }

        constexpr TemperatureDeltaDto(
            const un_scalar_t value,
            const TemperatureDeltaUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        TemperatureDeltaUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr TemperatureDeltaUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<TemperatureDeltaUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown TemperatureDelta unit name.");
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
        [[nodiscard]] static TemperatureDeltaDto from_json(const nlohmann::json& json)
        {
            return TemperatureDeltaDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Difference between two temperatures. The conversions are different than for Temperature.</summary>
    class TemperatureDelta : public UnitsNetBase
    {
    public:
        constexpr explicit TemperatureDelta(
            const un_scalar_t value,
            const TemperatureDeltaUnit unit = TemperatureDeltaUnit::Kelvin)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const TemperatureDeltaUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr TemperatureDeltaDto to_dto(
            const TemperatureDeltaUnit unit = TemperatureDeltaUnit::Kelvin) const
        {
            return TemperatureDeltaDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr TemperatureDelta from_dto(const TemperatureDeltaDto& dto)
        {
            return TemperatureDelta(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const TemperatureDeltaUnit unit = TemperatureDeltaUnit::Kelvin) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static TemperatureDelta from_json(const nlohmann::json& json)
        {
            return from_dto(TemperatureDeltaDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr TemperatureDelta operator+(const TemperatureDelta& other) const noexcept
        {
            return TemperatureDelta(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr TemperatureDelta operator-(const TemperatureDelta& other)const noexcept
        {
            return TemperatureDelta(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr TemperatureDelta operator*(const un_scalar_t scalar) const noexcept
        {
            return TemperatureDelta(base_value() * scalar);
        }

        [[nodiscard]] constexpr TemperatureDelta operator/(const un_scalar_t scalar) const noexcept
        {
            return TemperatureDelta(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const TemperatureDelta& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const TemperatureDelta& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const TemperatureDelta& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t kelvins() const
        {
            return convert_from_base(TemperatureDeltaUnit::Kelvin);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_kelvins(const un_scalar_t value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::Kelvin);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_celsius() const
        {
            return convert_from_base(TemperatureDeltaUnit::DegreeCelsius);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_degrees_celsius(const un_scalar_t value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::DegreeCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t millidegrees_celsius() const
        {
            return convert_from_base(TemperatureDeltaUnit::MillidegreeCelsius);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_millidegrees_celsius(const un_scalar_t value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::MillidegreeCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_delisle() const
        {
            return convert_from_base(TemperatureDeltaUnit::DegreeDelisle);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_degrees_delisle(const un_scalar_t value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::DegreeDelisle);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_fahrenheit() const
        {
            return convert_from_base(TemperatureDeltaUnit::DegreeFahrenheit);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_degrees_fahrenheit(const un_scalar_t value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::DegreeFahrenheit);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_newton() const
        {
            return convert_from_base(TemperatureDeltaUnit::DegreeNewton);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_degrees_newton(const un_scalar_t value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::DegreeNewton);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_rankine() const
        {
            return convert_from_base(TemperatureDeltaUnit::DegreeRankine);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_degrees_rankine(const un_scalar_t value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::DegreeRankine);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_reaumur() const
        {
            return convert_from_base(TemperatureDeltaUnit::DegreeReaumur);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_degrees_reaumur(const un_scalar_t value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::DegreeReaumur);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_roemer() const
        {
            return convert_from_base(TemperatureDeltaUnit::DegreeRoemer);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_degrees_roemer(const un_scalar_t value)
        {
            return TemperatureDelta(value, TemperatureDeltaUnit::DegreeRoemer);
        }

        [[nodiscard]] static constexpr TemperatureDelta from_invalid()
        {
            return TemperatureDelta(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, TemperatureDeltaUnit unit)
        {
            switch (unit)
            {

            case TemperatureDeltaUnit::Kelvin:
                return value;

            case TemperatureDeltaUnit::DegreeCelsius:
                return value;

            case TemperatureDeltaUnit::MillidegreeCelsius:
                return (value * static_cast<un_scalar_t>(1e-3));

            case TemperatureDeltaUnit::DegreeDelisle:
                return value * static_cast<un_scalar_t>(-2) / static_cast<un_scalar_t>(3);

            case TemperatureDeltaUnit::DegreeFahrenheit:
                return value * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(9);

            case TemperatureDeltaUnit::DegreeNewton:
                return value * static_cast<un_scalar_t>(100) / static_cast<un_scalar_t>(33);

            case TemperatureDeltaUnit::DegreeRankine:
                return value * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(9);

            case TemperatureDeltaUnit::DegreeReaumur:
                return value * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(4);

            case TemperatureDeltaUnit::DegreeRoemer:
                return value * static_cast<un_scalar_t>(40) / static_cast<un_scalar_t>(21);

            }

            throw std::invalid_argument("Unknown TemperatureDelta unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const TemperatureDeltaUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case TemperatureDeltaUnit::Kelvin:
                return base_value;

            case TemperatureDeltaUnit::DegreeCelsius:
                return base_value;

            case TemperatureDeltaUnit::MillidegreeCelsius:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case TemperatureDeltaUnit::DegreeDelisle:
                return base_value * static_cast<un_scalar_t>(-3) / static_cast<un_scalar_t>(2);

            case TemperatureDeltaUnit::DegreeFahrenheit:
                return base_value * static_cast<un_scalar_t>(9) / static_cast<un_scalar_t>(5);

            case TemperatureDeltaUnit::DegreeNewton:
                return base_value * static_cast<un_scalar_t>(33) / static_cast<un_scalar_t>(100);

            case TemperatureDeltaUnit::DegreeRankine:
                return base_value * static_cast<un_scalar_t>(9) / static_cast<un_scalar_t>(5);

            case TemperatureDeltaUnit::DegreeReaumur:
                return base_value * static_cast<un_scalar_t>(4) / static_cast<un_scalar_t>(5);

            case TemperatureDeltaUnit::DegreeRoemer:
                return base_value * static_cast<un_scalar_t>(21) / static_cast<un_scalar_t>(40);

            }

            throw std::invalid_argument("Unknown TemperatureDelta unit.");
        }

        un_scalar_t value_;
        TemperatureDeltaUnit value_unit_type_;       
    };
}
