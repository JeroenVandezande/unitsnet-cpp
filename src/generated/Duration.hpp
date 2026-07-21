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
    enum class DurationUnit : std::uint8_t
    {
        Year365,
        Month30,
        Week,
        Day,
        Hour,
        Minute,
        Second,
        Picosecond,
        Nanosecond,
        Microsecond,
        Millisecond,
        JulianYear,
        Sol,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Duration.</summary>
    class DurationDto
    {
    public:
        constexpr DurationDto() noexcept
            : value{}, unit(DurationUnit::Second)
        {
        }

        constexpr DurationDto(
            const un_scalar_t value,
            const DurationUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        DurationUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr DurationUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<DurationUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Duration unit name.");
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
        [[nodiscard]] static DurationDto from_json(const nlohmann::json& json)
        {
            return DurationDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Time is a dimension in which events can be ordered from the past through the present into the future, and also the measure of durations of events and the intervals between them.</summary>
    class Duration : public UnitsNetBase
    {
    public:
        constexpr explicit Duration(
            const un_scalar_t value,
            const DurationUnit unit = DurationUnit::Second)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const DurationUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr DurationDto to_dto(
            const DurationUnit unit = DurationUnit::Second) const
        {
            return DurationDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Duration from_dto(const DurationDto& dto)
        {
            return Duration(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const DurationUnit unit = DurationUnit::Second) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Duration from_json(const nlohmann::json& json)
        {
            return from_dto(DurationDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Duration operator+(const Duration& other) const noexcept
        {
            return Duration(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Duration operator-(const Duration& other)const noexcept
        {
            return Duration(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Duration operator*(const un_scalar_t scalar) const noexcept
        {
            return Duration(base_value() * scalar);
        }

        [[nodiscard]] constexpr Duration operator/(const un_scalar_t scalar) const noexcept
        {
            return Duration(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Duration& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Duration& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Duration& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t years365() const
        {
            return convert_from_base(DurationUnit::Year365);
        }

        [[nodiscard]] static constexpr Duration from_years365(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Year365);
        }

        [[nodiscard]] constexpr un_scalar_t months30() const
        {
            return convert_from_base(DurationUnit::Month30);
        }

        [[nodiscard]] static constexpr Duration from_months30(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Month30);
        }

        [[nodiscard]] constexpr un_scalar_t weeks() const
        {
            return convert_from_base(DurationUnit::Week);
        }

        [[nodiscard]] static constexpr Duration from_weeks(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Week);
        }

        [[nodiscard]] constexpr un_scalar_t days() const
        {
            return convert_from_base(DurationUnit::Day);
        }

        [[nodiscard]] static constexpr Duration from_days(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Day);
        }

        [[nodiscard]] constexpr un_scalar_t hours() const
        {
            return convert_from_base(DurationUnit::Hour);
        }

        [[nodiscard]] static constexpr Duration from_hours(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Hour);
        }

        [[nodiscard]] constexpr un_scalar_t minutes() const
        {
            return convert_from_base(DurationUnit::Minute);
        }

        [[nodiscard]] static constexpr Duration from_minutes(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Minute);
        }

        [[nodiscard]] constexpr un_scalar_t seconds() const
        {
            return convert_from_base(DurationUnit::Second);
        }

        [[nodiscard]] static constexpr Duration from_seconds(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Second);
        }

        [[nodiscard]] constexpr un_scalar_t picoseconds() const
        {
            return convert_from_base(DurationUnit::Picosecond);
        }

        [[nodiscard]] static constexpr Duration from_picoseconds(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Picosecond);
        }

        [[nodiscard]] constexpr un_scalar_t nanoseconds() const
        {
            return convert_from_base(DurationUnit::Nanosecond);
        }

        [[nodiscard]] static constexpr Duration from_nanoseconds(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Nanosecond);
        }

        [[nodiscard]] constexpr un_scalar_t microseconds() const
        {
            return convert_from_base(DurationUnit::Microsecond);
        }

        [[nodiscard]] static constexpr Duration from_microseconds(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Microsecond);
        }

        [[nodiscard]] constexpr un_scalar_t milliseconds() const
        {
            return convert_from_base(DurationUnit::Millisecond);
        }

        [[nodiscard]] static constexpr Duration from_milliseconds(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Millisecond);
        }

        [[nodiscard]] constexpr un_scalar_t julian_years() const
        {
            return convert_from_base(DurationUnit::JulianYear);
        }

        [[nodiscard]] static constexpr Duration from_julian_years(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::JulianYear);
        }

        [[nodiscard]] constexpr un_scalar_t sols() const
        {
            return convert_from_base(DurationUnit::Sol);
        }

        [[nodiscard]] static constexpr Duration from_sols(const un_scalar_t value)
        {
            return Duration(value, DurationUnit::Sol);
        }

        [[nodiscard]] static constexpr Duration from_invalid()
        {
            return Duration(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, DurationUnit unit)
        {
            switch (unit)
            {

            case DurationUnit::Year365:
                return value * static_cast<un_scalar_t>(365) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600);

            case DurationUnit::Month30:
                return value * static_cast<un_scalar_t>(30) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600);

            case DurationUnit::Week:
                return value * static_cast<un_scalar_t>(7) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600);

            case DurationUnit::Day:
                return value * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600);

            case DurationUnit::Hour:
                return value * static_cast<un_scalar_t>(3600);

            case DurationUnit::Minute:
                return value * static_cast<un_scalar_t>(60);

            case DurationUnit::Second:
                return value;

            case DurationUnit::Picosecond:
                return (value * static_cast<un_scalar_t>(1e-12));

            case DurationUnit::Nanosecond:
                return (value * static_cast<un_scalar_t>(1e-9));

            case DurationUnit::Microsecond:
                return (value * static_cast<un_scalar_t>(1e-6));

            case DurationUnit::Millisecond:
                return (value * static_cast<un_scalar_t>(1e-3));

            case DurationUnit::JulianYear:
                return value * static_cast<un_scalar_t>(365.25) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600);

            case DurationUnit::Sol:
                return value * static_cast<un_scalar_t>(88775.244);

            }

            throw std::invalid_argument("Unknown Duration unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const DurationUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case DurationUnit::Year365:
                return base_value / (static_cast<un_scalar_t>(365) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600));

            case DurationUnit::Month30:
                return base_value / (static_cast<un_scalar_t>(30) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600));

            case DurationUnit::Week:
                return base_value / (static_cast<un_scalar_t>(7) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600));

            case DurationUnit::Day:
                return base_value / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600));

            case DurationUnit::Hour:
                return base_value / static_cast<un_scalar_t>(3600);

            case DurationUnit::Minute:
                return base_value / static_cast<un_scalar_t>(60);

            case DurationUnit::Second:
                return base_value;

            case DurationUnit::Picosecond:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case DurationUnit::Nanosecond:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case DurationUnit::Microsecond:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case DurationUnit::Millisecond:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case DurationUnit::JulianYear:
                return base_value / (static_cast<un_scalar_t>(365.25) * static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3600));

            case DurationUnit::Sol:
                return base_value / static_cast<un_scalar_t>(88775.244);

            }

            throw std::invalid_argument("Unknown Duration unit.");
        }

        un_scalar_t value_;
        DurationUnit value_unit_type_;       
    };
}
