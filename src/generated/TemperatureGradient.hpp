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
    enum class TemperatureGradientUnit : std::uint8_t
    {
        KelvinPerMeter,
        DegreeCelsiusPerMeter,
        DegreeFahrenheitPerFoot,
        DegreeCelsiusPerKilometer,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of TemperatureGradient.</summary>
    class TemperatureGradientDto
    {
    public:
        constexpr TemperatureGradientDto() noexcept
            : value{}, unit(TemperatureGradientUnit::KelvinPerMeter)
        {
        }

        constexpr TemperatureGradientDto(
            const un_scalar_t value,
            const TemperatureGradientUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        TemperatureGradientUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr TemperatureGradientUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<TemperatureGradientUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown TemperatureGradient unit name.");
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
        [[nodiscard]] static TemperatureGradientDto from_json(const nlohmann::json& json)
        {
            return TemperatureGradientDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary></summary>
    class TemperatureGradient : public UnitsNetBase
    {
    public:
        constexpr explicit TemperatureGradient(
            const un_scalar_t value,
            const TemperatureGradientUnit unit = TemperatureGradientUnit::KelvinPerMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const TemperatureGradientUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr TemperatureGradientDto to_dto(
            const TemperatureGradientUnit unit = TemperatureGradientUnit::KelvinPerMeter) const
        {
            return TemperatureGradientDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr TemperatureGradient from_dto(const TemperatureGradientDto& dto)
        {
            return TemperatureGradient(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const TemperatureGradientUnit unit = TemperatureGradientUnit::KelvinPerMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static TemperatureGradient from_json(const nlohmann::json& json)
        {
            return from_dto(TemperatureGradientDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr TemperatureGradient operator+(const TemperatureGradient& other) const noexcept
        {
            return TemperatureGradient(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr TemperatureGradient operator-(const TemperatureGradient& other)const noexcept
        {
            return TemperatureGradient(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr TemperatureGradient operator*(const un_scalar_t scalar) const noexcept
        {
            return TemperatureGradient(base_value() * scalar);
        }

        [[nodiscard]] constexpr TemperatureGradient operator/(const un_scalar_t scalar) const noexcept
        {
            return TemperatureGradient(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const TemperatureGradient& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const TemperatureGradient& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const TemperatureGradient& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t kelvins_per_meter() const
        {
            return convert_from_base(TemperatureGradientUnit::KelvinPerMeter);
        }

        [[nodiscard]] static constexpr TemperatureGradient from_kelvins_per_meter(const un_scalar_t value)
        {
            return TemperatureGradient(value, TemperatureGradientUnit::KelvinPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_celsius_per_meter() const
        {
            return convert_from_base(TemperatureGradientUnit::DegreeCelsiusPerMeter);
        }

        [[nodiscard]] static constexpr TemperatureGradient from_degrees_celsius_per_meter(const un_scalar_t value)
        {
            return TemperatureGradient(value, TemperatureGradientUnit::DegreeCelsiusPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_fahrenheit_per_foot() const
        {
            return convert_from_base(TemperatureGradientUnit::DegreeFahrenheitPerFoot);
        }

        [[nodiscard]] static constexpr TemperatureGradient from_degrees_fahrenheit_per_foot(const un_scalar_t value)
        {
            return TemperatureGradient(value, TemperatureGradientUnit::DegreeFahrenheitPerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_celsius_per_kilometer() const
        {
            return convert_from_base(TemperatureGradientUnit::DegreeCelsiusPerKilometer);
        }

        [[nodiscard]] static constexpr TemperatureGradient from_degrees_celsius_per_kilometer(const un_scalar_t value)
        {
            return TemperatureGradient(value, TemperatureGradientUnit::DegreeCelsiusPerKilometer);
        }

        [[nodiscard]] static constexpr TemperatureGradient from_invalid()
        {
            return TemperatureGradient(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, TemperatureGradientUnit unit)
        {
            switch (unit)
            {

            case TemperatureGradientUnit::KelvinPerMeter:
                return value;

            case TemperatureGradientUnit::DegreeCelsiusPerMeter:
                return value;

            case TemperatureGradientUnit::DegreeFahrenheitPerFoot:
                return (value / static_cast<un_scalar_t>(0.3048)) * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(9);

            case TemperatureGradientUnit::DegreeCelsiusPerKilometer:
                return value / static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown TemperatureGradient unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const TemperatureGradientUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case TemperatureGradientUnit::KelvinPerMeter:
                return base_value;

            case TemperatureGradientUnit::DegreeCelsiusPerMeter:
                return base_value;

            case TemperatureGradientUnit::DegreeFahrenheitPerFoot:
                return (base_value * static_cast<un_scalar_t>(0.3048)) * static_cast<un_scalar_t>(9) / static_cast<un_scalar_t>(5);

            case TemperatureGradientUnit::DegreeCelsiusPerKilometer:
                return base_value * static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown TemperatureGradient unit.");
        }

        un_scalar_t value_;
        TemperatureGradientUnit value_unit_type_;       
    };
}
