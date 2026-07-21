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
    enum class FrequencyUnit : std::uint8_t
    {
        Hertz,
        Microhertz,
        Millihertz,
        Kilohertz,
        Megahertz,
        Gigahertz,
        Terahertz,
        RadianPerSecond,
        CyclePerMinute,
        CyclePerHour,
        BeatPerMinute,
        PerSecond,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Frequency.</summary>
    class FrequencyDto
    {
    public:
        constexpr FrequencyDto() noexcept
            : value{}, unit(FrequencyUnit::Hertz)
        {
        }

        constexpr FrequencyDto(
            const un_scalar_t value,
            const FrequencyUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        FrequencyUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr FrequencyUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<FrequencyUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Frequency unit name.");
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
        [[nodiscard]] static FrequencyDto from_json(const nlohmann::json& json)
        {
            return FrequencyDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The number of occurrences of a repeating event per unit time.</summary>
    class Frequency : public UnitsNetBase
    {
    public:
        constexpr explicit Frequency(
            const un_scalar_t value,
            const FrequencyUnit unit = FrequencyUnit::Hertz)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const FrequencyUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr FrequencyDto to_dto(
            const FrequencyUnit unit = FrequencyUnit::Hertz) const
        {
            return FrequencyDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Frequency from_dto(const FrequencyDto& dto)
        {
            return Frequency(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const FrequencyUnit unit = FrequencyUnit::Hertz) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Frequency from_json(const nlohmann::json& json)
        {
            return from_dto(FrequencyDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Frequency operator+(const Frequency& other) const noexcept
        {
            return Frequency(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Frequency operator-(const Frequency& other)const noexcept
        {
            return Frequency(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Frequency operator*(const un_scalar_t scalar) const noexcept
        {
            return Frequency(base_value() * scalar);
        }

        [[nodiscard]] constexpr Frequency operator/(const un_scalar_t scalar) const noexcept
        {
            return Frequency(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Frequency& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Frequency& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Frequency& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t hertz() const
        {
            return convert_from_base(FrequencyUnit::Hertz);
        }

        [[nodiscard]] static constexpr Frequency from_hertz(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::Hertz);
        }

        [[nodiscard]] constexpr un_scalar_t microhertz() const
        {
            return convert_from_base(FrequencyUnit::Microhertz);
        }

        [[nodiscard]] static constexpr Frequency from_microhertz(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::Microhertz);
        }

        [[nodiscard]] constexpr un_scalar_t millihertz() const
        {
            return convert_from_base(FrequencyUnit::Millihertz);
        }

        [[nodiscard]] static constexpr Frequency from_millihertz(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::Millihertz);
        }

        [[nodiscard]] constexpr un_scalar_t kilohertz() const
        {
            return convert_from_base(FrequencyUnit::Kilohertz);
        }

        [[nodiscard]] static constexpr Frequency from_kilohertz(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::Kilohertz);
        }

        [[nodiscard]] constexpr un_scalar_t megahertz() const
        {
            return convert_from_base(FrequencyUnit::Megahertz);
        }

        [[nodiscard]] static constexpr Frequency from_megahertz(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::Megahertz);
        }

        [[nodiscard]] constexpr un_scalar_t gigahertz() const
        {
            return convert_from_base(FrequencyUnit::Gigahertz);
        }

        [[nodiscard]] static constexpr Frequency from_gigahertz(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::Gigahertz);
        }

        [[nodiscard]] constexpr un_scalar_t terahertz() const
        {
            return convert_from_base(FrequencyUnit::Terahertz);
        }

        [[nodiscard]] static constexpr Frequency from_terahertz(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::Terahertz);
        }

        /// <summary>In SI units, angular frequency is normally presented with the unit radian per second, and need not express a rotational value. The unit hertz (Hz) is dimensionally equivalent, but by convention it is only used for frequency f, never for angular frequency ω. This convention is used to help avoid the confusion that arises when dealing with quantities such as frequency and angular quantities because the units of measure (such as cycle or radian) are considered to be one and hence may be omitted when expressing quantities in terms of SI units.</summary>
        [[nodiscard]] constexpr un_scalar_t radians_per_second() const
        {
            return convert_from_base(FrequencyUnit::RadianPerSecond);
        }

        /// <summary>In SI units, angular frequency is normally presented with the unit radian per second, and need not express a rotational value. The unit hertz (Hz) is dimensionally equivalent, but by convention it is only used for frequency f, never for angular frequency ω. This convention is used to help avoid the confusion that arises when dealing with quantities such as frequency and angular quantities because the units of measure (such as cycle or radian) are considered to be one and hence may be omitted when expressing quantities in terms of SI units.</summary>
        [[nodiscard]] static constexpr Frequency from_radians_per_second(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::RadianPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t cycles_per_minute() const
        {
            return convert_from_base(FrequencyUnit::CyclePerMinute);
        }

        [[nodiscard]] static constexpr Frequency from_cycles_per_minute(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::CyclePerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t cycles_per_hour() const
        {
            return convert_from_base(FrequencyUnit::CyclePerHour);
        }

        [[nodiscard]] static constexpr Frequency from_cycles_per_hour(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::CyclePerHour);
        }

        [[nodiscard]] constexpr un_scalar_t beats_per_minute() const
        {
            return convert_from_base(FrequencyUnit::BeatPerMinute);
        }

        [[nodiscard]] static constexpr Frequency from_beats_per_minute(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::BeatPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t per_second() const
        {
            return convert_from_base(FrequencyUnit::PerSecond);
        }

        [[nodiscard]] static constexpr Frequency from_per_second(const un_scalar_t value)
        {
            return Frequency(value, FrequencyUnit::PerSecond);
        }

        [[nodiscard]] static constexpr Frequency from_invalid()
        {
            return Frequency(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, FrequencyUnit unit)
        {
            switch (unit)
            {

            case FrequencyUnit::Hertz:
                return value;

            case FrequencyUnit::Microhertz:
                return (value * static_cast<un_scalar_t>(1e-6));

            case FrequencyUnit::Millihertz:
                return (value * static_cast<un_scalar_t>(1e-3));

            case FrequencyUnit::Kilohertz:
                return (value * static_cast<un_scalar_t>(1e3));

            case FrequencyUnit::Megahertz:
                return (value * static_cast<un_scalar_t>(1e6));

            case FrequencyUnit::Gigahertz:
                return (value * static_cast<un_scalar_t>(1e9));

            case FrequencyUnit::Terahertz:
                return (value * static_cast<un_scalar_t>(1e12));

            case FrequencyUnit::RadianPerSecond:
                return value / (static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>);

            case FrequencyUnit::CyclePerMinute:
                return value / static_cast<un_scalar_t>(60);

            case FrequencyUnit::CyclePerHour:
                return value / static_cast<un_scalar_t>(3600);

            case FrequencyUnit::BeatPerMinute:
                return value / static_cast<un_scalar_t>(60);

            case FrequencyUnit::PerSecond:
                return value;

            }

            throw std::invalid_argument("Unknown Frequency unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const FrequencyUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case FrequencyUnit::Hertz:
                return base_value;

            case FrequencyUnit::Microhertz:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case FrequencyUnit::Millihertz:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case FrequencyUnit::Kilohertz:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case FrequencyUnit::Megahertz:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case FrequencyUnit::Gigahertz:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case FrequencyUnit::Terahertz:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            case FrequencyUnit::RadianPerSecond:
                return base_value * (static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>);

            case FrequencyUnit::CyclePerMinute:
                return base_value * static_cast<un_scalar_t>(60);

            case FrequencyUnit::CyclePerHour:
                return base_value * static_cast<un_scalar_t>(3600);

            case FrequencyUnit::BeatPerMinute:
                return base_value * static_cast<un_scalar_t>(60);

            case FrequencyUnit::PerSecond:
                return base_value;

            }

            throw std::invalid_argument("Unknown Frequency unit.");
        }

        un_scalar_t value_;
        FrequencyUnit value_unit_type_;       
    };
}
