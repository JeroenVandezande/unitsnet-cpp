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
    enum class ForceChangeRateUnit : std::uint8_t
    {
        NewtonPerMinute,
        DecanewtonPerMinute,
        KilonewtonPerMinute,
        NewtonPerSecond,
        NanonewtonPerSecond,
        MicronewtonPerSecond,
        MillinewtonPerSecond,
        CentinewtonPerSecond,
        DecinewtonPerSecond,
        DecanewtonPerSecond,
        KilonewtonPerSecond,
        PoundForcePerMinute,
        KilopoundForcePerMinute,
        PoundForcePerSecond,
        KilopoundForcePerSecond,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ForceChangeRate.</summary>
    class ForceChangeRateDto
    {
    public:
        constexpr ForceChangeRateDto() noexcept
            : value{}, unit(ForceChangeRateUnit::NewtonPerSecond)
        {
        }

        constexpr ForceChangeRateDto(
            const un_scalar_t value,
            const ForceChangeRateUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ForceChangeRateUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ForceChangeRateUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ForceChangeRateUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ForceChangeRate unit name.");
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
        [[nodiscard]] static ForceChangeRateDto from_json(const nlohmann::json& json)
        {
            return ForceChangeRateDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Force change rate is the ratio of the force change to the time during which the change occurred (value of force changes per unit time).</summary>
    class ForceChangeRate : public UnitsNetBase
    {
    public:
        constexpr explicit ForceChangeRate(
            const un_scalar_t value,
            const ForceChangeRateUnit unit = ForceChangeRateUnit::NewtonPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ForceChangeRateUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ForceChangeRateDto to_dto(
            const ForceChangeRateUnit unit = ForceChangeRateUnit::NewtonPerSecond) const
        {
            return ForceChangeRateDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ForceChangeRate from_dto(const ForceChangeRateDto& dto)
        {
            return ForceChangeRate(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ForceChangeRateUnit unit = ForceChangeRateUnit::NewtonPerSecond) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ForceChangeRate from_json(const nlohmann::json& json)
        {
            return from_dto(ForceChangeRateDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ForceChangeRate operator+(const ForceChangeRate& other) const noexcept
        {
            return ForceChangeRate(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ForceChangeRate operator-(const ForceChangeRate& other)const noexcept
        {
            return ForceChangeRate(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ForceChangeRate operator*(const un_scalar_t scalar) const noexcept
        {
            return ForceChangeRate(base_value() * scalar);
        }

        [[nodiscard]] constexpr ForceChangeRate operator/(const un_scalar_t scalar) const noexcept
        {
            return ForceChangeRate(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ForceChangeRate& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ForceChangeRate& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ForceChangeRate& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t newtons_per_minute() const
        {
            return convert_from_base(ForceChangeRateUnit::NewtonPerMinute);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_newtons_per_minute(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::NewtonPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t decanewtons_per_minute() const
        {
            return convert_from_base(ForceChangeRateUnit::DecanewtonPerMinute);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_decanewtons_per_minute(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::DecanewtonPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_minute() const
        {
            return convert_from_base(ForceChangeRateUnit::KilonewtonPerMinute);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_kilonewtons_per_minute(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::KilonewtonPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t newtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::NewtonPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_newtons_per_second(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::NewtonPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t nanonewtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::NanonewtonPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_nanonewtons_per_second(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::NanonewtonPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t micronewtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::MicronewtonPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_micronewtons_per_second(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::MicronewtonPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t millinewtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::MillinewtonPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_millinewtons_per_second(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::MillinewtonPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t centinewtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::CentinewtonPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_centinewtons_per_second(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::CentinewtonPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t decinewtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::DecinewtonPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_decinewtons_per_second(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::DecinewtonPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t decanewtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::DecanewtonPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_decanewtons_per_second(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::DecanewtonPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::KilonewtonPerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_kilonewtons_per_second(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::KilonewtonPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_per_minute() const
        {
            return convert_from_base(ForceChangeRateUnit::PoundForcePerMinute);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_pounds_force_per_minute(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::PoundForcePerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_minute() const
        {
            return convert_from_base(ForceChangeRateUnit::KilopoundForcePerMinute);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_kilopounds_force_per_minute(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::KilopoundForcePerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::PoundForcePerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_pounds_force_per_second(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::PoundForcePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_second() const
        {
            return convert_from_base(ForceChangeRateUnit::KilopoundForcePerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_kilopounds_force_per_second(const un_scalar_t value)
        {
            return ForceChangeRate(value, ForceChangeRateUnit::KilopoundForcePerSecond);
        }

        [[nodiscard]] static constexpr ForceChangeRate from_invalid()
        {
            return ForceChangeRate(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ForceChangeRateUnit unit)
        {
            switch (unit)
            {

            case ForceChangeRateUnit::NewtonPerMinute:
                return value / static_cast<un_scalar_t>(60);

            case ForceChangeRateUnit::DecanewtonPerMinute:
                return (value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(60);

            case ForceChangeRateUnit::KilonewtonPerMinute:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(60);

            case ForceChangeRateUnit::NewtonPerSecond:
                return value;

            case ForceChangeRateUnit::NanonewtonPerSecond:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ForceChangeRateUnit::MicronewtonPerSecond:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ForceChangeRateUnit::MillinewtonPerSecond:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ForceChangeRateUnit::CentinewtonPerSecond:
                return (value * static_cast<un_scalar_t>(1e-2));

            case ForceChangeRateUnit::DecinewtonPerSecond:
                return (value * static_cast<un_scalar_t>(1e-1));

            case ForceChangeRateUnit::DecanewtonPerSecond:
                return (value * static_cast<un_scalar_t>(1e1));

            case ForceChangeRateUnit::KilonewtonPerSecond:
                return (value * static_cast<un_scalar_t>(1e3));

            case ForceChangeRateUnit::PoundForcePerMinute:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(60);

            case ForceChangeRateUnit::KilopoundForcePerMinute:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(60);

            case ForceChangeRateUnit::PoundForcePerSecond:
                return value * static_cast<un_scalar_t>(4.4482216152605);

            case ForceChangeRateUnit::KilopoundForcePerSecond:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605);

            }

            throw std::invalid_argument("Unknown ForceChangeRate unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ForceChangeRateUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ForceChangeRateUnit::NewtonPerMinute:
                return base_value * static_cast<un_scalar_t>(60);

            case ForceChangeRateUnit::DecanewtonPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e1);

            case ForceChangeRateUnit::KilonewtonPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e3);

            case ForceChangeRateUnit::NewtonPerSecond:
                return base_value;

            case ForceChangeRateUnit::NanonewtonPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ForceChangeRateUnit::MicronewtonPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ForceChangeRateUnit::MillinewtonPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ForceChangeRateUnit::CentinewtonPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case ForceChangeRateUnit::DecinewtonPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case ForceChangeRateUnit::DecanewtonPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e1);

            case ForceChangeRateUnit::KilonewtonPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ForceChangeRateUnit::PoundForcePerMinute:
                return base_value / static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(60);

            case ForceChangeRateUnit::KilopoundForcePerMinute:
                return (base_value / static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e3);

            case ForceChangeRateUnit::PoundForcePerSecond:
                return base_value / static_cast<un_scalar_t>(4.4482216152605);

            case ForceChangeRateUnit::KilopoundForcePerSecond:
                return (base_value / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown ForceChangeRate unit.");
        }

        un_scalar_t value_;
        ForceChangeRateUnit value_unit_type_;       
    };
}
