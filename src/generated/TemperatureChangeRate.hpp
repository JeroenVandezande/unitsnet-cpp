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
    enum class TemperatureChangeRateUnit : std::uint8_t
    {
        DegreeCelsiusPerSecond,
        NanodegreeCelsiusPerSecond,
        MicrodegreeCelsiusPerSecond,
        MillidegreeCelsiusPerSecond,
        CentidegreeCelsiusPerSecond,
        DecidegreeCelsiusPerSecond,
        DecadegreeCelsiusPerSecond,
        HectodegreeCelsiusPerSecond,
        KilodegreeCelsiusPerSecond,
        DegreeCelsiusPerMinute,
        DegreeKelvinPerMinute,
        DegreeFahrenheitPerMinute,
        DegreeFahrenheitPerSecond,
        DegreeKelvinPerSecond,
        DegreeCelsiusPerHour,
        DegreeKelvinPerHour,
        DegreeFahrenheitPerHour,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of TemperatureChangeRate.</summary>
    class TemperatureChangeRateDto
    {
    public:
        constexpr TemperatureChangeRateDto() noexcept
            : value{}, unit(TemperatureChangeRateUnit::DegreeCelsiusPerSecond)
        {
        }

        constexpr TemperatureChangeRateDto(
            const un_scalar_t value,
            const TemperatureChangeRateUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        TemperatureChangeRateUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr TemperatureChangeRateUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<TemperatureChangeRateUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown TemperatureChangeRate unit name.");
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
        [[nodiscard]] static TemperatureChangeRateDto from_json(const nlohmann::json& json)
        {
            return TemperatureChangeRateDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Temperature change rate is the ratio of the temperature change to the time during which the change occurred (value of temperature changes per unit time).</summary>
    class TemperatureChangeRate : public UnitsNetBase
    {
    public:
        constexpr explicit TemperatureChangeRate(
            const un_scalar_t value,
            const TemperatureChangeRateUnit unit = TemperatureChangeRateUnit::DegreeCelsiusPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const TemperatureChangeRateUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr TemperatureChangeRateDto to_dto(
            const TemperatureChangeRateUnit unit = TemperatureChangeRateUnit::DegreeCelsiusPerSecond) const
        {
            return TemperatureChangeRateDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr TemperatureChangeRate from_dto(const TemperatureChangeRateDto& dto)
        {
            return TemperatureChangeRate(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const TemperatureChangeRateUnit unit = TemperatureChangeRateUnit::DegreeCelsiusPerSecond) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static TemperatureChangeRate from_json(const nlohmann::json& json)
        {
            return from_dto(TemperatureChangeRateDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr TemperatureChangeRate operator+(const TemperatureChangeRate& other) const noexcept
        {
            return TemperatureChangeRate(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr TemperatureChangeRate operator-(const TemperatureChangeRate& other)const noexcept
        {
            return TemperatureChangeRate(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr TemperatureChangeRate operator*(const un_scalar_t scalar) const noexcept
        {
            return TemperatureChangeRate(base_value() * scalar);
        }

        [[nodiscard]] constexpr TemperatureChangeRate operator/(const un_scalar_t scalar) const noexcept
        {
            return TemperatureChangeRate(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const TemperatureChangeRate& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const TemperatureChangeRate& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const TemperatureChangeRate& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t degrees_celsius_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DegreeCelsiusPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_degrees_celsius_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DegreeCelsiusPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t nanodegrees_celsius_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::NanodegreeCelsiusPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_nanodegrees_celsius_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::NanodegreeCelsiusPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t microdegrees_celsius_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::MicrodegreeCelsiusPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_microdegrees_celsius_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::MicrodegreeCelsiusPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t millidegrees_celsius_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::MillidegreeCelsiusPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_millidegrees_celsius_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::MillidegreeCelsiusPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t centidegrees_celsius_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::CentidegreeCelsiusPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_centidegrees_celsius_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::CentidegreeCelsiusPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t decidegrees_celsius_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DecidegreeCelsiusPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_decidegrees_celsius_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DecidegreeCelsiusPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t decadegrees_celsius_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DecadegreeCelsiusPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_decadegrees_celsius_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DecadegreeCelsiusPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t hectodegrees_celsius_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::HectodegreeCelsiusPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_hectodegrees_celsius_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::HectodegreeCelsiusPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kilodegrees_celsius_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::KilodegreeCelsiusPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_kilodegrees_celsius_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::KilodegreeCelsiusPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_celsius_per_minute() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DegreeCelsiusPerMinute);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_degrees_celsius_per_minute(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DegreeCelsiusPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_kelvin_per_minute() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DegreeKelvinPerMinute);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_degrees_kelvin_per_minute(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DegreeKelvinPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_fahrenheit_per_minute() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DegreeFahrenheitPerMinute);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_degrees_fahrenheit_per_minute(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DegreeFahrenheitPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_fahrenheit_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DegreeFahrenheitPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_degrees_fahrenheit_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DegreeFahrenheitPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_kelvin_per_second() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DegreeKelvinPerSecond);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_degrees_kelvin_per_second(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DegreeKelvinPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_celsius_per_hour() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DegreeCelsiusPerHour);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_degrees_celsius_per_hour(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DegreeCelsiusPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_kelvin_per_hour() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DegreeKelvinPerHour);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_degrees_kelvin_per_hour(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DegreeKelvinPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_fahrenheit_per_hour() const
        {
            return convert_from_base(TemperatureChangeRateUnit::DegreeFahrenheitPerHour);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_degrees_fahrenheit_per_hour(const un_scalar_t value)
        {
            return TemperatureChangeRate(value, TemperatureChangeRateUnit::DegreeFahrenheitPerHour);
        }

        [[nodiscard]] static constexpr TemperatureChangeRate from_invalid()
        {
            return TemperatureChangeRate(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, TemperatureChangeRateUnit unit)
        {
            switch (unit)
            {

            case TemperatureChangeRateUnit::DegreeCelsiusPerSecond:
                return value;

            case TemperatureChangeRateUnit::NanodegreeCelsiusPerSecond:
                return (value * static_cast<un_scalar_t>(1e-9));

            case TemperatureChangeRateUnit::MicrodegreeCelsiusPerSecond:
                return (value * static_cast<un_scalar_t>(1e-6));

            case TemperatureChangeRateUnit::MillidegreeCelsiusPerSecond:
                return (value * static_cast<un_scalar_t>(1e-3));

            case TemperatureChangeRateUnit::CentidegreeCelsiusPerSecond:
                return (value * static_cast<un_scalar_t>(1e-2));

            case TemperatureChangeRateUnit::DecidegreeCelsiusPerSecond:
                return (value * static_cast<un_scalar_t>(1e-1));

            case TemperatureChangeRateUnit::DecadegreeCelsiusPerSecond:
                return (value * static_cast<un_scalar_t>(1e1));

            case TemperatureChangeRateUnit::HectodegreeCelsiusPerSecond:
                return (value * static_cast<un_scalar_t>(1e2));

            case TemperatureChangeRateUnit::KilodegreeCelsiusPerSecond:
                return (value * static_cast<un_scalar_t>(1e3));

            case TemperatureChangeRateUnit::DegreeCelsiusPerMinute:
                return value / static_cast<un_scalar_t>(60);

            case TemperatureChangeRateUnit::DegreeKelvinPerMinute:
                return value / static_cast<un_scalar_t>(60);

            case TemperatureChangeRateUnit::DegreeFahrenheitPerMinute:
                return value * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(9) / static_cast<un_scalar_t>(60);

            case TemperatureChangeRateUnit::DegreeFahrenheitPerSecond:
                return value * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(9);

            case TemperatureChangeRateUnit::DegreeKelvinPerSecond:
                return value;

            case TemperatureChangeRateUnit::DegreeCelsiusPerHour:
                return value / static_cast<un_scalar_t>(3600);

            case TemperatureChangeRateUnit::DegreeKelvinPerHour:
                return value / static_cast<un_scalar_t>(3600);

            case TemperatureChangeRateUnit::DegreeFahrenheitPerHour:
                return value * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(9) / static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown TemperatureChangeRate unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const TemperatureChangeRateUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case TemperatureChangeRateUnit::DegreeCelsiusPerSecond:
                return base_value;

            case TemperatureChangeRateUnit::NanodegreeCelsiusPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case TemperatureChangeRateUnit::MicrodegreeCelsiusPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case TemperatureChangeRateUnit::MillidegreeCelsiusPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case TemperatureChangeRateUnit::CentidegreeCelsiusPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case TemperatureChangeRateUnit::DecidegreeCelsiusPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case TemperatureChangeRateUnit::DecadegreeCelsiusPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e1);

            case TemperatureChangeRateUnit::HectodegreeCelsiusPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e2);

            case TemperatureChangeRateUnit::KilodegreeCelsiusPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case TemperatureChangeRateUnit::DegreeCelsiusPerMinute:
                return base_value * static_cast<un_scalar_t>(60);

            case TemperatureChangeRateUnit::DegreeKelvinPerMinute:
                return base_value * static_cast<un_scalar_t>(60);

            case TemperatureChangeRateUnit::DegreeFahrenheitPerMinute:
                return base_value * static_cast<un_scalar_t>(9) / static_cast<un_scalar_t>(5) * static_cast<un_scalar_t>(60);

            case TemperatureChangeRateUnit::DegreeFahrenheitPerSecond:
                return base_value * static_cast<un_scalar_t>(9) / static_cast<un_scalar_t>(5);

            case TemperatureChangeRateUnit::DegreeKelvinPerSecond:
                return base_value;

            case TemperatureChangeRateUnit::DegreeCelsiusPerHour:
                return base_value * static_cast<un_scalar_t>(3600);

            case TemperatureChangeRateUnit::DegreeKelvinPerHour:
                return base_value * static_cast<un_scalar_t>(3600);

            case TemperatureChangeRateUnit::DegreeFahrenheitPerHour:
                return base_value * static_cast<un_scalar_t>(9) / static_cast<un_scalar_t>(5) * static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown TemperatureChangeRate unit.");
        }

        un_scalar_t value_;
        TemperatureChangeRateUnit value_unit_type_;       
    };
}
