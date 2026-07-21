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
    enum class ElectricPotentialChangeRateUnit : std::uint8_t
    {
        VoltPerSecond,
        MicrovoltPerSecond,
        MillivoltPerSecond,
        KilovoltPerSecond,
        MegavoltPerSecond,
        VoltPerMicrosecond,
        MicrovoltPerMicrosecond,
        MillivoltPerMicrosecond,
        KilovoltPerMicrosecond,
        MegavoltPerMicrosecond,
        VoltPerMinute,
        MicrovoltPerMinute,
        MillivoltPerMinute,
        KilovoltPerMinute,
        MegavoltPerMinute,
        VoltPerHour,
        MicrovoltPerHour,
        MillivoltPerHour,
        KilovoltPerHour,
        MegavoltPerHour,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ElectricPotentialChangeRate.</summary>
    class ElectricPotentialChangeRateDto
    {
    public:
        constexpr ElectricPotentialChangeRateDto() noexcept
            : value{}, unit(ElectricPotentialChangeRateUnit::VoltPerSecond)
        {
        }

        constexpr ElectricPotentialChangeRateDto(
            const un_scalar_t value,
            const ElectricPotentialChangeRateUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricPotentialChangeRateUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricPotentialChangeRateUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricPotentialChangeRateUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricPotentialChangeRate unit name.");
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
        [[nodiscard]] static ElectricPotentialChangeRateDto from_json(const nlohmann::json& json)
        {
            return ElectricPotentialChangeRateDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>ElectricPotential change rate is the ratio of the electric potential change to the time during which the change occurred (value of electric potential changes per unit time).</summary>
    class ElectricPotentialChangeRate : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricPotentialChangeRate(
            const un_scalar_t value,
            const ElectricPotentialChangeRateUnit unit = ElectricPotentialChangeRateUnit::VoltPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricPotentialChangeRateUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricPotentialChangeRateDto to_dto(
            const ElectricPotentialChangeRateUnit unit = ElectricPotentialChangeRateUnit::VoltPerSecond) const
        {
            return ElectricPotentialChangeRateDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_dto(const ElectricPotentialChangeRateDto& dto)
        {
            return ElectricPotentialChangeRate(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricPotentialChangeRateUnit unit = ElectricPotentialChangeRateUnit::VoltPerSecond) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricPotentialChangeRate from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricPotentialChangeRateDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricPotentialChangeRate operator+(const ElectricPotentialChangeRate& other) const noexcept
        {
            return ElectricPotentialChangeRate(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricPotentialChangeRate operator-(const ElectricPotentialChangeRate& other)const noexcept
        {
            return ElectricPotentialChangeRate(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricPotentialChangeRate operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricPotentialChangeRate(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricPotentialChangeRate operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricPotentialChangeRate(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricPotentialChangeRate& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricPotentialChangeRate& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricPotentialChangeRate& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t volts_per_second() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::VoltPerSecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_volts_per_second(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::VoltPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t microvolts_per_second() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MicrovoltPerSecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_microvolts_per_second(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MicrovoltPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t millivolts_per_second() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MillivoltPerSecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_millivolts_per_second(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MillivoltPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kilovolts_per_second() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::KilovoltPerSecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_kilovolts_per_second(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::KilovoltPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t megavolts_per_second() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MegavoltPerSecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_megavolts_per_second(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MegavoltPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t volts_per_microsecond() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::VoltPerMicrosecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_volts_per_microsecond(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::VoltPerMicrosecond);
        }

        [[nodiscard]] constexpr un_scalar_t microvolts_per_microsecond() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MicrovoltPerMicrosecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_microvolts_per_microsecond(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MicrovoltPerMicrosecond);
        }

        [[nodiscard]] constexpr un_scalar_t millivolts_per_microsecond() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MillivoltPerMicrosecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_millivolts_per_microsecond(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MillivoltPerMicrosecond);
        }

        [[nodiscard]] constexpr un_scalar_t kilovolts_per_microsecond() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::KilovoltPerMicrosecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_kilovolts_per_microsecond(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::KilovoltPerMicrosecond);
        }

        [[nodiscard]] constexpr un_scalar_t megavolts_per_microsecond() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MegavoltPerMicrosecond);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_megavolts_per_microsecond(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MegavoltPerMicrosecond);
        }

        [[nodiscard]] constexpr un_scalar_t volts_per_minute() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::VoltPerMinute);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_volts_per_minute(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::VoltPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t microvolts_per_minute() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MicrovoltPerMinute);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_microvolts_per_minute(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MicrovoltPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t millivolts_per_minute() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MillivoltPerMinute);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_millivolts_per_minute(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MillivoltPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t kilovolts_per_minute() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::KilovoltPerMinute);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_kilovolts_per_minute(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::KilovoltPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t megavolts_per_minute() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MegavoltPerMinute);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_megavolts_per_minute(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MegavoltPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t volts_per_hour() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::VoltPerHour);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_volts_per_hour(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::VoltPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t microvolts_per_hour() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MicrovoltPerHour);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_microvolts_per_hour(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MicrovoltPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t millivolts_per_hour() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MillivoltPerHour);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_millivolts_per_hour(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MillivoltPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t kilovolts_per_hour() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::KilovoltPerHour);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_kilovolts_per_hour(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::KilovoltPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t megavolts_per_hour() const
        {
            return convert_from_base(ElectricPotentialChangeRateUnit::MegavoltPerHour);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_megavolts_per_hour(const un_scalar_t value)
        {
            return ElectricPotentialChangeRate(value, ElectricPotentialChangeRateUnit::MegavoltPerHour);
        }

        [[nodiscard]] static constexpr ElectricPotentialChangeRate from_invalid()
        {
            return ElectricPotentialChangeRate(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricPotentialChangeRateUnit unit)
        {
            switch (unit)
            {

            case ElectricPotentialChangeRateUnit::VoltPerSecond:
                return value;

            case ElectricPotentialChangeRateUnit::MicrovoltPerSecond:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricPotentialChangeRateUnit::MillivoltPerSecond:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricPotentialChangeRateUnit::KilovoltPerSecond:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricPotentialChangeRateUnit::MegavoltPerSecond:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricPotentialChangeRateUnit::VoltPerMicrosecond:
                return value * static_cast<un_scalar_t>(1E6);

            case ElectricPotentialChangeRateUnit::MicrovoltPerMicrosecond:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(1E6);

            case ElectricPotentialChangeRateUnit::MillivoltPerMicrosecond:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1E6);

            case ElectricPotentialChangeRateUnit::KilovoltPerMicrosecond:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1E6);

            case ElectricPotentialChangeRateUnit::MegavoltPerMicrosecond:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1E6);

            case ElectricPotentialChangeRateUnit::VoltPerMinute:
                return value / static_cast<un_scalar_t>(60);

            case ElectricPotentialChangeRateUnit::MicrovoltPerMinute:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(60);

            case ElectricPotentialChangeRateUnit::MillivoltPerMinute:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(60);

            case ElectricPotentialChangeRateUnit::KilovoltPerMinute:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(60);

            case ElectricPotentialChangeRateUnit::MegavoltPerMinute:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(60);

            case ElectricPotentialChangeRateUnit::VoltPerHour:
                return value / static_cast<un_scalar_t>(3600);

            case ElectricPotentialChangeRateUnit::MicrovoltPerHour:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(3600);

            case ElectricPotentialChangeRateUnit::MillivoltPerHour:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(3600);

            case ElectricPotentialChangeRateUnit::KilovoltPerHour:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(3600);

            case ElectricPotentialChangeRateUnit::MegavoltPerHour:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown ElectricPotentialChangeRate unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricPotentialChangeRateUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricPotentialChangeRateUnit::VoltPerSecond:
                return base_value;

            case ElectricPotentialChangeRateUnit::MicrovoltPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricPotentialChangeRateUnit::MillivoltPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricPotentialChangeRateUnit::KilovoltPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricPotentialChangeRateUnit::MegavoltPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ElectricPotentialChangeRateUnit::VoltPerMicrosecond:
                return base_value / static_cast<un_scalar_t>(1E6);

            case ElectricPotentialChangeRateUnit::MicrovoltPerMicrosecond:
                return (base_value / static_cast<un_scalar_t>(1E6)) / static_cast<un_scalar_t>(1e-6);

            case ElectricPotentialChangeRateUnit::MillivoltPerMicrosecond:
                return (base_value / static_cast<un_scalar_t>(1E6)) / static_cast<un_scalar_t>(1e-3);

            case ElectricPotentialChangeRateUnit::KilovoltPerMicrosecond:
                return (base_value / static_cast<un_scalar_t>(1E6)) / static_cast<un_scalar_t>(1e3);

            case ElectricPotentialChangeRateUnit::MegavoltPerMicrosecond:
                return (base_value / static_cast<un_scalar_t>(1E6)) / static_cast<un_scalar_t>(1e6);

            case ElectricPotentialChangeRateUnit::VoltPerMinute:
                return base_value * static_cast<un_scalar_t>(60);

            case ElectricPotentialChangeRateUnit::MicrovoltPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e-6);

            case ElectricPotentialChangeRateUnit::MillivoltPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e-3);

            case ElectricPotentialChangeRateUnit::KilovoltPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e3);

            case ElectricPotentialChangeRateUnit::MegavoltPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e6);

            case ElectricPotentialChangeRateUnit::VoltPerHour:
                return base_value * static_cast<un_scalar_t>(3600);

            case ElectricPotentialChangeRateUnit::MicrovoltPerHour:
                return (base_value * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e-6);

            case ElectricPotentialChangeRateUnit::MillivoltPerHour:
                return (base_value * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e-3);

            case ElectricPotentialChangeRateUnit::KilovoltPerHour:
                return (base_value * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e3);

            case ElectricPotentialChangeRateUnit::MegavoltPerHour:
                return (base_value * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown ElectricPotentialChangeRate unit.");
        }

        un_scalar_t value_;
        ElectricPotentialChangeRateUnit value_unit_type_;       
    };
}
