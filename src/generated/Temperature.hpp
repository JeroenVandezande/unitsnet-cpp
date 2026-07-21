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
    enum class TemperatureUnit : std::uint8_t
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
        SolarTemperature,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Temperature.</summary>
    class TemperatureDto
    {
    public:
        constexpr TemperatureDto() noexcept
            : value{}, unit(TemperatureUnit::Kelvin)
        {
        }

        constexpr TemperatureDto(
            const un_scalar_t value,
            const TemperatureUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        TemperatureUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr TemperatureUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<TemperatureUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Temperature unit name.");
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
        [[nodiscard]] static TemperatureDto from_json(const nlohmann::json& json)
        {
            return TemperatureDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>A temperature is a numerical measure of hot or cold. Its measurement is by detection of heat radiation or particle velocity or kinetic energy, or by the bulk behavior of a thermometric material. It may be calibrated in any of various temperature scales, Celsius, Fahrenheit, Kelvin, etc. The fundamental physical definition of temperature is provided by thermodynamics.</summary>
    class Temperature : public UnitsNetBase
    {
    public:
        constexpr explicit Temperature(
            const un_scalar_t value,
            const TemperatureUnit unit = TemperatureUnit::Kelvin)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const TemperatureUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr TemperatureDto to_dto(
            const TemperatureUnit unit = TemperatureUnit::Kelvin) const
        {
            return TemperatureDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Temperature from_dto(const TemperatureDto& dto)
        {
            return Temperature(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const TemperatureUnit unit = TemperatureUnit::Kelvin) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Temperature from_json(const nlohmann::json& json)
        {
            return from_dto(TemperatureDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Temperature operator+(const Temperature& other) const noexcept
        {
            return Temperature(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Temperature operator-(const Temperature& other)const noexcept
        {
            return Temperature(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Temperature operator*(const un_scalar_t scalar) const noexcept
        {
            return Temperature(base_value() * scalar);
        }

        [[nodiscard]] constexpr Temperature operator/(const un_scalar_t scalar) const noexcept
        {
            return Temperature(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Temperature& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Temperature& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Temperature& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t kelvins() const
        {
            return convert_from_base(TemperatureUnit::Kelvin);
        }

        [[nodiscard]] static constexpr Temperature from_kelvins(const un_scalar_t value)
        {
            return Temperature(value, TemperatureUnit::Kelvin);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_celsius() const
        {
            return convert_from_base(TemperatureUnit::DegreeCelsius);
        }

        [[nodiscard]] static constexpr Temperature from_degrees_celsius(const un_scalar_t value)
        {
            return Temperature(value, TemperatureUnit::DegreeCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t millidegrees_celsius() const
        {
            return convert_from_base(TemperatureUnit::MillidegreeCelsius);
        }

        [[nodiscard]] static constexpr Temperature from_millidegrees_celsius(const un_scalar_t value)
        {
            return Temperature(value, TemperatureUnit::MillidegreeCelsius);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_delisle() const
        {
            return convert_from_base(TemperatureUnit::DegreeDelisle);
        }

        [[nodiscard]] static constexpr Temperature from_degrees_delisle(const un_scalar_t value)
        {
            return Temperature(value, TemperatureUnit::DegreeDelisle);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_fahrenheit() const
        {
            return convert_from_base(TemperatureUnit::DegreeFahrenheit);
        }

        [[nodiscard]] static constexpr Temperature from_degrees_fahrenheit(const un_scalar_t value)
        {
            return Temperature(value, TemperatureUnit::DegreeFahrenheit);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_newton() const
        {
            return convert_from_base(TemperatureUnit::DegreeNewton);
        }

        [[nodiscard]] static constexpr Temperature from_degrees_newton(const un_scalar_t value)
        {
            return Temperature(value, TemperatureUnit::DegreeNewton);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_rankine() const
        {
            return convert_from_base(TemperatureUnit::DegreeRankine);
        }

        [[nodiscard]] static constexpr Temperature from_degrees_rankine(const un_scalar_t value)
        {
            return Temperature(value, TemperatureUnit::DegreeRankine);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_reaumur() const
        {
            return convert_from_base(TemperatureUnit::DegreeReaumur);
        }

        [[nodiscard]] static constexpr Temperature from_degrees_reaumur(const un_scalar_t value)
        {
            return Temperature(value, TemperatureUnit::DegreeReaumur);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_roemer() const
        {
            return convert_from_base(TemperatureUnit::DegreeRoemer);
        }

        [[nodiscard]] static constexpr Temperature from_degrees_roemer(const un_scalar_t value)
        {
            return Temperature(value, TemperatureUnit::DegreeRoemer);
        }

        [[nodiscard]] constexpr un_scalar_t solar_temperatures() const
        {
            return convert_from_base(TemperatureUnit::SolarTemperature);
        }

        [[nodiscard]] static constexpr Temperature from_solar_temperatures(const un_scalar_t value)
        {
            return Temperature(value, TemperatureUnit::SolarTemperature);
        }

        [[nodiscard]] static constexpr Temperature from_invalid()
        {
            return Temperature(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, TemperatureUnit unit)
        {
            switch (unit)
            {

            case TemperatureUnit::Kelvin:
                return value;

            case TemperatureUnit::DegreeCelsius:
                return value + static_cast<un_scalar_t>(273.15);

            case TemperatureUnit::MillidegreeCelsius:
                return value / static_cast<un_scalar_t>(1000) + static_cast<un_scalar_t>(273.15);

            case TemperatureUnit::DegreeDelisle:
                return value * static_cast<un_scalar_t>(-2) / static_cast<un_scalar_t>(3) + static_cast<un_scalar_t>(373.15);

            case TemperatureUnit::DegreeFahrenheit:
                return value * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(9) + static_cast<un_scalar_t>(459.67) * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(9);

            case TemperatureUnit::DegreeNewton:
                return value * static_cast<un_scalar_t>(100) / static_cast<un_scalar_t>(33) + static_cast<un_scalar_t>(273.15);

            case TemperatureUnit::DegreeRankine:
                return value * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(9);

            case TemperatureUnit::DegreeReaumur:
                return value * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(4) + static_cast<un_scalar_t>(273.15);

            case TemperatureUnit::DegreeRoemer:
                return value * static_cast<un_scalar_t>(40) / static_cast<un_scalar_t>(21) + static_cast<un_scalar_t>(273.15) - static_cast<un_scalar_t>(7.5) * static_cast<un_scalar_t>(40.0) / static_cast<un_scalar_t>(21);

            case TemperatureUnit::SolarTemperature:
                return value * static_cast<un_scalar_t>(5778);

            }

            throw std::invalid_argument("Unknown Temperature unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const TemperatureUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case TemperatureUnit::Kelvin:
                return base_value;

            case TemperatureUnit::DegreeCelsius:
                return base_value - static_cast<un_scalar_t>(273.15);

            case TemperatureUnit::MillidegreeCelsius:
                return (base_value - static_cast<un_scalar_t>(273.15)) * static_cast<un_scalar_t>(1000);

            case TemperatureUnit::DegreeDelisle:
                return (base_value - static_cast<un_scalar_t>(373.15)) * static_cast<un_scalar_t>(-3) / static_cast<un_scalar_t>(2);

            case TemperatureUnit::DegreeFahrenheit:
                return (base_value - static_cast<un_scalar_t>(459.67) * static_cast<un_scalar_t>(5) / static_cast<un_scalar_t>(9)) * static_cast<un_scalar_t>(9) / static_cast<un_scalar_t>(5);

            case TemperatureUnit::DegreeNewton:
                return (base_value - static_cast<un_scalar_t>(273.15)) * static_cast<un_scalar_t>(33) / static_cast<un_scalar_t>(100);

            case TemperatureUnit::DegreeRankine:
                return base_value * static_cast<un_scalar_t>(9) / static_cast<un_scalar_t>(5);

            case TemperatureUnit::DegreeReaumur:
                return (base_value - static_cast<un_scalar_t>(273.15)) * static_cast<un_scalar_t>(4) / static_cast<un_scalar_t>(5);

            case TemperatureUnit::DegreeRoemer:
                return (base_value - (static_cast<un_scalar_t>(273.15) - static_cast<un_scalar_t>(7.5) * static_cast<un_scalar_t>(40.0) / static_cast<un_scalar_t>(21))) * static_cast<un_scalar_t>(21) / static_cast<un_scalar_t>(40);

            case TemperatureUnit::SolarTemperature:
                return base_value / static_cast<un_scalar_t>(5778);

            }

            throw std::invalid_argument("Unknown Temperature unit.");
        }

        un_scalar_t value_;
        TemperatureUnit value_unit_type_;       
    };
}
