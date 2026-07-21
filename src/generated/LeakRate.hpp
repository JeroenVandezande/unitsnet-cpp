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
    enum class LeakRateUnit : std::uint8_t
    {
        PascalCubicMeterPerSecond,
        MillibarLiterPerSecond,
        TorrLiterPerSecond,
        AtmCubicCentimeterPerSecond,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of LeakRate.</summary>
    class LeakRateDto
    {
    public:
        constexpr LeakRateDto() noexcept
            : value{}, unit(LeakRateUnit::PascalCubicMeterPerSecond)
        {
        }

        constexpr LeakRateDto(
            const un_scalar_t value,
            const LeakRateUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        LeakRateUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr LeakRateUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<LeakRateUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown LeakRate unit name.");
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
        [[nodiscard]] static LeakRateDto from_json(const nlohmann::json& json)
        {
            return LeakRateDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>A leakage rate of QL = 1 Pa-m³/s is given when the pressure in a closed, evacuated container with a volume of 1 m³ rises by 1 Pa per second or when the pressure in the container drops by 1 Pa in the event of overpressure.</summary>
    class LeakRate : public UnitsNetBase
    {
    public:
        constexpr explicit LeakRate(
            const un_scalar_t value,
            const LeakRateUnit unit = LeakRateUnit::PascalCubicMeterPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const LeakRateUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr LeakRateDto to_dto(
            const LeakRateUnit unit = LeakRateUnit::PascalCubicMeterPerSecond) const
        {
            return LeakRateDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr LeakRate from_dto(const LeakRateDto& dto)
        {
            return LeakRate(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const LeakRateUnit unit = LeakRateUnit::PascalCubicMeterPerSecond) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static LeakRate from_json(const nlohmann::json& json)
        {
            return from_dto(LeakRateDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr LeakRate operator+(const LeakRate& other) const noexcept
        {
            return LeakRate(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr LeakRate operator-(const LeakRate& other)const noexcept
        {
            return LeakRate(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr LeakRate operator*(const un_scalar_t scalar) const noexcept
        {
            return LeakRate(base_value() * scalar);
        }

        [[nodiscard]] constexpr LeakRate operator/(const un_scalar_t scalar) const noexcept
        {
            return LeakRate(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const LeakRate& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const LeakRate& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const LeakRate& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t pascal_cubic_meters_per_second() const
        {
            return convert_from_base(LeakRateUnit::PascalCubicMeterPerSecond);
        }

        [[nodiscard]] static constexpr LeakRate from_pascal_cubic_meters_per_second(const un_scalar_t value)
        {
            return LeakRate(value, LeakRateUnit::PascalCubicMeterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t millibar_liters_per_second() const
        {
            return convert_from_base(LeakRateUnit::MillibarLiterPerSecond);
        }

        [[nodiscard]] static constexpr LeakRate from_millibar_liters_per_second(const un_scalar_t value)
        {
            return LeakRate(value, LeakRateUnit::MillibarLiterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t torr_liters_per_second() const
        {
            return convert_from_base(LeakRateUnit::TorrLiterPerSecond);
        }

        [[nodiscard]] static constexpr LeakRate from_torr_liters_per_second(const un_scalar_t value)
        {
            return LeakRate(value, LeakRateUnit::TorrLiterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t atm_cubic_centimeters_per_second() const
        {
            return convert_from_base(LeakRateUnit::AtmCubicCentimeterPerSecond);
        }

        [[nodiscard]] static constexpr LeakRate from_atm_cubic_centimeters_per_second(const un_scalar_t value)
        {
            return LeakRate(value, LeakRateUnit::AtmCubicCentimeterPerSecond);
        }

        [[nodiscard]] static constexpr LeakRate from_invalid()
        {
            return LeakRate(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, LeakRateUnit unit)
        {
            switch (unit)
            {

            case LeakRateUnit::PascalCubicMeterPerSecond:
                return value;

            case LeakRateUnit::MillibarLiterPerSecond:
                return value / static_cast<un_scalar_t>(10);

            case LeakRateUnit::TorrLiterPerSecond:
                return value / static_cast<un_scalar_t>(7.5);

            case LeakRateUnit::AtmCubicCentimeterPerSecond:
                return value / (static_cast<un_scalar_t>(1e6) / static_cast<un_scalar_t>(101325));

            }

            throw std::invalid_argument("Unknown LeakRate unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const LeakRateUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case LeakRateUnit::PascalCubicMeterPerSecond:
                return base_value;

            case LeakRateUnit::MillibarLiterPerSecond:
                return base_value * static_cast<un_scalar_t>(10);

            case LeakRateUnit::TorrLiterPerSecond:
                return base_value * static_cast<un_scalar_t>(7.5);

            case LeakRateUnit::AtmCubicCentimeterPerSecond:
                return base_value * (static_cast<un_scalar_t>(1e6) / static_cast<un_scalar_t>(101325));

            }

            throw std::invalid_argument("Unknown LeakRate unit.");
        }

        un_scalar_t value_;
        LeakRateUnit value_unit_type_;       
    };
}
