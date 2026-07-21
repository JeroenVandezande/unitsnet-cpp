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
    enum class ElectricCurrentGradientUnit : std::uint8_t
    {
        AmperePerSecond,
        MilliamperePerSecond,
        AmperePerMinute,
        MilliamperePerMinute,
        AmperePerMillisecond,
        AmperePerMicrosecond,
        AmperePerNanosecond,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ElectricCurrentGradient.</summary>
    class ElectricCurrentGradientDto
    {
    public:
        constexpr ElectricCurrentGradientDto() noexcept
            : value{}, unit(ElectricCurrentGradientUnit::AmperePerSecond)
        {
        }

        constexpr ElectricCurrentGradientDto(
            const un_scalar_t value,
            const ElectricCurrentGradientUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricCurrentGradientUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricCurrentGradientUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricCurrentGradientUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricCurrentGradient unit name.");
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
        [[nodiscard]] static ElectricCurrentGradientDto from_json(const nlohmann::json& json)
        {
            return ElectricCurrentGradientDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In electromagnetism, the current gradient describes how the current changes in time.</summary>
    class ElectricCurrentGradient : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricCurrentGradient(
            const un_scalar_t value,
            const ElectricCurrentGradientUnit unit = ElectricCurrentGradientUnit::AmperePerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricCurrentGradientUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricCurrentGradientDto to_dto(
            const ElectricCurrentGradientUnit unit = ElectricCurrentGradientUnit::AmperePerSecond) const
        {
            return ElectricCurrentGradientDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricCurrentGradient from_dto(const ElectricCurrentGradientDto& dto)
        {
            return ElectricCurrentGradient(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricCurrentGradientUnit unit = ElectricCurrentGradientUnit::AmperePerSecond) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricCurrentGradient from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricCurrentGradientDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricCurrentGradient operator+(const ElectricCurrentGradient& other) const noexcept
        {
            return ElectricCurrentGradient(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricCurrentGradient operator-(const ElectricCurrentGradient& other)const noexcept
        {
            return ElectricCurrentGradient(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricCurrentGradient operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricCurrentGradient(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricCurrentGradient operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricCurrentGradient(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricCurrentGradient& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricCurrentGradient& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricCurrentGradient& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t amperes_per_second() const
        {
            return convert_from_base(ElectricCurrentGradientUnit::AmperePerSecond);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_amperes_per_second(const un_scalar_t value)
        {
            return ElectricCurrentGradient(value, ElectricCurrentGradientUnit::AmperePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t milliamperes_per_second() const
        {
            return convert_from_base(ElectricCurrentGradientUnit::MilliamperePerSecond);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_milliamperes_per_second(const un_scalar_t value)
        {
            return ElectricCurrentGradient(value, ElectricCurrentGradientUnit::MilliamperePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t amperes_per_minute() const
        {
            return convert_from_base(ElectricCurrentGradientUnit::AmperePerMinute);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_amperes_per_minute(const un_scalar_t value)
        {
            return ElectricCurrentGradient(value, ElectricCurrentGradientUnit::AmperePerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t milliamperes_per_minute() const
        {
            return convert_from_base(ElectricCurrentGradientUnit::MilliamperePerMinute);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_milliamperes_per_minute(const un_scalar_t value)
        {
            return ElectricCurrentGradient(value, ElectricCurrentGradientUnit::MilliamperePerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t amperes_per_millisecond() const
        {
            return convert_from_base(ElectricCurrentGradientUnit::AmperePerMillisecond);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_amperes_per_millisecond(const un_scalar_t value)
        {
            return ElectricCurrentGradient(value, ElectricCurrentGradientUnit::AmperePerMillisecond);
        }

        [[nodiscard]] constexpr un_scalar_t amperes_per_microsecond() const
        {
            return convert_from_base(ElectricCurrentGradientUnit::AmperePerMicrosecond);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_amperes_per_microsecond(const un_scalar_t value)
        {
            return ElectricCurrentGradient(value, ElectricCurrentGradientUnit::AmperePerMicrosecond);
        }

        [[nodiscard]] constexpr un_scalar_t amperes_per_nanosecond() const
        {
            return convert_from_base(ElectricCurrentGradientUnit::AmperePerNanosecond);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_amperes_per_nanosecond(const un_scalar_t value)
        {
            return ElectricCurrentGradient(value, ElectricCurrentGradientUnit::AmperePerNanosecond);
        }

        [[nodiscard]] static constexpr ElectricCurrentGradient from_invalid()
        {
            return ElectricCurrentGradient(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricCurrentGradientUnit unit)
        {
            switch (unit)
            {

            case ElectricCurrentGradientUnit::AmperePerSecond:
                return value;

            case ElectricCurrentGradientUnit::MilliamperePerSecond:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricCurrentGradientUnit::AmperePerMinute:
                return value / static_cast<un_scalar_t>(60);

            case ElectricCurrentGradientUnit::MilliamperePerMinute:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(60);

            case ElectricCurrentGradientUnit::AmperePerMillisecond:
                return value * static_cast<un_scalar_t>(1E3);

            case ElectricCurrentGradientUnit::AmperePerMicrosecond:
                return value * static_cast<un_scalar_t>(1E6);

            case ElectricCurrentGradientUnit::AmperePerNanosecond:
                return value * static_cast<un_scalar_t>(1E9);

            }

            throw std::invalid_argument("Unknown ElectricCurrentGradient unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricCurrentGradientUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricCurrentGradientUnit::AmperePerSecond:
                return base_value;

            case ElectricCurrentGradientUnit::MilliamperePerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricCurrentGradientUnit::AmperePerMinute:
                return base_value * static_cast<un_scalar_t>(60);

            case ElectricCurrentGradientUnit::MilliamperePerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e-3);

            case ElectricCurrentGradientUnit::AmperePerMillisecond:
                return base_value / static_cast<un_scalar_t>(1E3);

            case ElectricCurrentGradientUnit::AmperePerMicrosecond:
                return base_value / static_cast<un_scalar_t>(1E6);

            case ElectricCurrentGradientUnit::AmperePerNanosecond:
                return base_value / static_cast<un_scalar_t>(1E9);

            }

            throw std::invalid_argument("Unknown ElectricCurrentGradient unit.");
        }

        un_scalar_t value_;
        ElectricCurrentGradientUnit value_unit_type_;       
    };
}
