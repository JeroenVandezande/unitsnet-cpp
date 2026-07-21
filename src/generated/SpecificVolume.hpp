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
    enum class SpecificVolumeUnit : std::uint8_t
    {
        CubicMeterPerKilogram,
        MillicubicMeterPerKilogram,
        CubicFootPerPound,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of SpecificVolume.</summary>
    class SpecificVolumeDto
    {
    public:
        constexpr SpecificVolumeDto() noexcept
            : value{}, unit(SpecificVolumeUnit::CubicMeterPerKilogram)
        {
        }

        constexpr SpecificVolumeDto(
            const un_scalar_t value,
            const SpecificVolumeUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        SpecificVolumeUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr SpecificVolumeUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<SpecificVolumeUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown SpecificVolume unit name.");
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
        [[nodiscard]] static SpecificVolumeDto from_json(const nlohmann::json& json)
        {
            return SpecificVolumeDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In thermodynamics, the specific volume of a substance is the ratio of the substance's volume to its mass. It is the reciprocal of density and an intrinsic property of matter as well.</summary>
    class SpecificVolume : public UnitsNetBase
    {
    public:
        constexpr explicit SpecificVolume(
            const un_scalar_t value,
            const SpecificVolumeUnit unit = SpecificVolumeUnit::CubicMeterPerKilogram)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const SpecificVolumeUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr SpecificVolumeDto to_dto(
            const SpecificVolumeUnit unit = SpecificVolumeUnit::CubicMeterPerKilogram) const
        {
            return SpecificVolumeDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr SpecificVolume from_dto(const SpecificVolumeDto& dto)
        {
            return SpecificVolume(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const SpecificVolumeUnit unit = SpecificVolumeUnit::CubicMeterPerKilogram) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static SpecificVolume from_json(const nlohmann::json& json)
        {
            return from_dto(SpecificVolumeDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr SpecificVolume operator+(const SpecificVolume& other) const noexcept
        {
            return SpecificVolume(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr SpecificVolume operator-(const SpecificVolume& other)const noexcept
        {
            return SpecificVolume(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr SpecificVolume operator*(const un_scalar_t scalar) const noexcept
        {
            return SpecificVolume(base_value() * scalar);
        }

        [[nodiscard]] constexpr SpecificVolume operator/(const un_scalar_t scalar) const noexcept
        {
            return SpecificVolume(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const SpecificVolume& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const SpecificVolume& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const SpecificVolume& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t cubic_meters_per_kilogram() const
        {
            return convert_from_base(SpecificVolumeUnit::CubicMeterPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificVolume from_cubic_meters_per_kilogram(const un_scalar_t value)
        {
            return SpecificVolume(value, SpecificVolumeUnit::CubicMeterPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t millicubic_meters_per_kilogram() const
        {
            return convert_from_base(SpecificVolumeUnit::MillicubicMeterPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificVolume from_millicubic_meters_per_kilogram(const un_scalar_t value)
        {
            return SpecificVolume(value, SpecificVolumeUnit::MillicubicMeterPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_feet_per_pound() const
        {
            return convert_from_base(SpecificVolumeUnit::CubicFootPerPound);
        }

        [[nodiscard]] static constexpr SpecificVolume from_cubic_feet_per_pound(const un_scalar_t value)
        {
            return SpecificVolume(value, SpecificVolumeUnit::CubicFootPerPound);
        }

        [[nodiscard]] static constexpr SpecificVolume from_invalid()
        {
            return SpecificVolume(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, SpecificVolumeUnit unit)
        {
            switch (unit)
            {

            case SpecificVolumeUnit::CubicMeterPerKilogram:
                return value;

            case SpecificVolumeUnit::MillicubicMeterPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-3));

            case SpecificVolumeUnit::CubicFootPerPound:
                return value * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(0.45359237);

            }

            throw std::invalid_argument("Unknown SpecificVolume unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const SpecificVolumeUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case SpecificVolumeUnit::CubicMeterPerKilogram:
                return base_value;

            case SpecificVolumeUnit::MillicubicMeterPerKilogram:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case SpecificVolumeUnit::CubicFootPerPound:
                return base_value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.028316846592);

            }

            throw std::invalid_argument("Unknown SpecificVolume unit.");
        }

        un_scalar_t value_;
        SpecificVolumeUnit value_unit_type_;       
    };
}
