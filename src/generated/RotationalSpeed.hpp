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
    enum class RotationalSpeedUnit : std::uint8_t
    {
        RadianPerSecond,
        NanoradianPerSecond,
        MicroradianPerSecond,
        MilliradianPerSecond,
        CentiradianPerSecond,
        DeciradianPerSecond,
        DegreePerSecond,
        NanodegreePerSecond,
        MicrodegreePerSecond,
        MillidegreePerSecond,
        DegreePerMinute,
        RevolutionPerSecond,
        RevolutionPerMinute,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of RotationalSpeed.</summary>
    class RotationalSpeedDto
    {
    public:
        constexpr RotationalSpeedDto() noexcept
            : value{}, unit(RotationalSpeedUnit::RadianPerSecond)
        {
        }

        constexpr RotationalSpeedDto(
            const un_scalar_t value,
            const RotationalSpeedUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        RotationalSpeedUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr RotationalSpeedUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<RotationalSpeedUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown RotationalSpeed unit name.");
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
        [[nodiscard]] static RotationalSpeedDto from_json(const nlohmann::json& json)
        {
            return RotationalSpeedDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Rotational speed (sometimes called speed of revolution) is the number of complete rotations, revolutions, cycles, or turns per time unit. Rotational speed is a cyclic frequency, measured in radians per second or in hertz in the SI System by scientists, or in revolutions per minute (rpm or min-1) or revolutions per second in everyday life. The symbol for rotational speed is ω (the Greek lowercase letter "omega").</summary>
    class RotationalSpeed : public UnitsNetBase
    {
    public:
        constexpr explicit RotationalSpeed(
            const un_scalar_t value,
            const RotationalSpeedUnit unit = RotationalSpeedUnit::RadianPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const RotationalSpeedUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr RotationalSpeedDto to_dto(
            const RotationalSpeedUnit unit = RotationalSpeedUnit::RadianPerSecond) const
        {
            return RotationalSpeedDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr RotationalSpeed from_dto(const RotationalSpeedDto& dto)
        {
            return RotationalSpeed(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const RotationalSpeedUnit unit = RotationalSpeedUnit::RadianPerSecond) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static RotationalSpeed from_json(const nlohmann::json& json)
        {
            return from_dto(RotationalSpeedDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr RotationalSpeed operator+(const RotationalSpeed& other) const noexcept
        {
            return RotationalSpeed(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr RotationalSpeed operator-(const RotationalSpeed& other)const noexcept
        {
            return RotationalSpeed(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr RotationalSpeed operator*(const un_scalar_t scalar) const noexcept
        {
            return RotationalSpeed(base_value() * scalar);
        }

        [[nodiscard]] constexpr RotationalSpeed operator/(const un_scalar_t scalar) const noexcept
        {
            return RotationalSpeed(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RotationalSpeed& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const RotationalSpeed& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const RotationalSpeed& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t radians_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::RadianPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_radians_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::RadianPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t nanoradians_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::NanoradianPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_nanoradians_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::NanoradianPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t microradians_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::MicroradianPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_microradians_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::MicroradianPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t milliradians_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::MilliradianPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_milliradians_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::MilliradianPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t centiradians_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::CentiradianPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_centiradians_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::CentiradianPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t deciradians_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::DeciradianPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_deciradians_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::DeciradianPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::DegreePerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_degrees_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::DegreePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t nanodegrees_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::NanodegreePerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_nanodegrees_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::NanodegreePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t microdegrees_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::MicrodegreePerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_microdegrees_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::MicrodegreePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t millidegrees_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::MillidegreePerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_millidegrees_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::MillidegreePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t degrees_per_minute() const
        {
            return convert_from_base(RotationalSpeedUnit::DegreePerMinute);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_degrees_per_minute(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::DegreePerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t revolutions_per_second() const
        {
            return convert_from_base(RotationalSpeedUnit::RevolutionPerSecond);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_revolutions_per_second(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::RevolutionPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t revolutions_per_minute() const
        {
            return convert_from_base(RotationalSpeedUnit::RevolutionPerMinute);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_revolutions_per_minute(const un_scalar_t value)
        {
            return RotationalSpeed(value, RotationalSpeedUnit::RevolutionPerMinute);
        }

        [[nodiscard]] static constexpr RotationalSpeed from_invalid()
        {
            return RotationalSpeed(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RotationalSpeedUnit unit)
        {
            switch (unit)
            {

            case RotationalSpeedUnit::RadianPerSecond:
                return value;

            case RotationalSpeedUnit::NanoradianPerSecond:
                return (value * static_cast<un_scalar_t>(1e-9));

            case RotationalSpeedUnit::MicroradianPerSecond:
                return (value * static_cast<un_scalar_t>(1e-6));

            case RotationalSpeedUnit::MilliradianPerSecond:
                return (value * static_cast<un_scalar_t>(1e-3));

            case RotationalSpeedUnit::CentiradianPerSecond:
                return (value * static_cast<un_scalar_t>(1e-2));

            case RotationalSpeedUnit::DeciradianPerSecond:
                return (value * static_cast<un_scalar_t>(1e-1));

            case RotationalSpeedUnit::DegreePerSecond:
                return (std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(180)) * value;

            case RotationalSpeedUnit::NanodegreePerSecond:
                return (std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(180)) * (value * static_cast<un_scalar_t>(1e-9));

            case RotationalSpeedUnit::MicrodegreePerSecond:
                return (std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(180)) * (value * static_cast<un_scalar_t>(1e-6));

            case RotationalSpeedUnit::MillidegreePerSecond:
                return (std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(180)) * (value * static_cast<un_scalar_t>(1e-3));

            case RotationalSpeedUnit::DegreePerMinute:
                return (std::numbers::pi_v<un_scalar_t> / (static_cast<un_scalar_t>(180) * static_cast<un_scalar_t>(60))) * value;

            case RotationalSpeedUnit::RevolutionPerSecond:
                return value * static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>;

            case RotationalSpeedUnit::RevolutionPerMinute:
                return (value * static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>) / static_cast<un_scalar_t>(60);

            }

            throw std::invalid_argument("Unknown RotationalSpeed unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RotationalSpeedUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case RotationalSpeedUnit::RadianPerSecond:
                return base_value;

            case RotationalSpeedUnit::NanoradianPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case RotationalSpeedUnit::MicroradianPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case RotationalSpeedUnit::MilliradianPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case RotationalSpeedUnit::CentiradianPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case RotationalSpeedUnit::DeciradianPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case RotationalSpeedUnit::DegreePerSecond:
                return (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>) * base_value;

            case RotationalSpeedUnit::NanodegreePerSecond:
                return ((static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>) * base_value) / static_cast<un_scalar_t>(1e-9);

            case RotationalSpeedUnit::MicrodegreePerSecond:
                return ((static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>) * base_value) / static_cast<un_scalar_t>(1e-6);

            case RotationalSpeedUnit::MillidegreePerSecond:
                return ((static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>) * base_value) / static_cast<un_scalar_t>(1e-3);

            case RotationalSpeedUnit::DegreePerMinute:
                return (static_cast<un_scalar_t>(180) * static_cast<un_scalar_t>(60) / std::numbers::pi_v<un_scalar_t>) * base_value;

            case RotationalSpeedUnit::RevolutionPerSecond:
                return base_value / (static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>);

            case RotationalSpeedUnit::RevolutionPerMinute:
                return (base_value / (static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>)) * static_cast<un_scalar_t>(60);

            }

            throw std::invalid_argument("Unknown RotationalSpeed unit.");
        }

        un_scalar_t value_;
        RotationalSpeedUnit value_unit_type_;       
    };
}
