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
    enum class VolumeFlowPerAreaUnit : std::uint8_t
    {
        CubicMeterPerSecondPerSquareMeter,
        CubicFootPerMinutePerSquareFoot,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of VolumeFlowPerArea.</summary>
    class VolumeFlowPerAreaDto
    {
    public:
        constexpr VolumeFlowPerAreaDto() noexcept
            : value{}, unit(VolumeFlowPerAreaUnit::CubicMeterPerSecondPerSquareMeter)
        {
        }

        constexpr VolumeFlowPerAreaDto(
            const un_scalar_t value,
            const VolumeFlowPerAreaUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        VolumeFlowPerAreaUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr VolumeFlowPerAreaUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<VolumeFlowPerAreaUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown VolumeFlowPerArea unit name.");
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
        [[nodiscard]] static VolumeFlowPerAreaDto from_json(const nlohmann::json& json)
        {
            return VolumeFlowPerAreaDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary></summary>
    class VolumeFlowPerArea : public UnitsNetBase
    {
    public:
        constexpr explicit VolumeFlowPerArea(
            const un_scalar_t value,
            const VolumeFlowPerAreaUnit unit = VolumeFlowPerAreaUnit::CubicMeterPerSecondPerSquareMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const VolumeFlowPerAreaUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr VolumeFlowPerAreaDto to_dto(
            const VolumeFlowPerAreaUnit unit = VolumeFlowPerAreaUnit::CubicMeterPerSecondPerSquareMeter) const
        {
            return VolumeFlowPerAreaDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr VolumeFlowPerArea from_dto(const VolumeFlowPerAreaDto& dto)
        {
            return VolumeFlowPerArea(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const VolumeFlowPerAreaUnit unit = VolumeFlowPerAreaUnit::CubicMeterPerSecondPerSquareMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static VolumeFlowPerArea from_json(const nlohmann::json& json)
        {
            return from_dto(VolumeFlowPerAreaDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr VolumeFlowPerArea operator+(const VolumeFlowPerArea& other) const noexcept
        {
            return VolumeFlowPerArea(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr VolumeFlowPerArea operator-(const VolumeFlowPerArea& other)const noexcept
        {
            return VolumeFlowPerArea(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr VolumeFlowPerArea operator*(const un_scalar_t scalar) const noexcept
        {
            return VolumeFlowPerArea(base_value() * scalar);
        }

        [[nodiscard]] constexpr VolumeFlowPerArea operator/(const un_scalar_t scalar) const noexcept
        {
            return VolumeFlowPerArea(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const VolumeFlowPerArea& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const VolumeFlowPerArea& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const VolumeFlowPerArea& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t cubic_meters_per_second_per_square_meter() const
        {
            return convert_from_base(VolumeFlowPerAreaUnit::CubicMeterPerSecondPerSquareMeter);
        }

        [[nodiscard]] static constexpr VolumeFlowPerArea from_cubic_meters_per_second_per_square_meter(const un_scalar_t value)
        {
            return VolumeFlowPerArea(value, VolumeFlowPerAreaUnit::CubicMeterPerSecondPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_feet_per_minute_per_square_foot() const
        {
            return convert_from_base(VolumeFlowPerAreaUnit::CubicFootPerMinutePerSquareFoot);
        }

        [[nodiscard]] static constexpr VolumeFlowPerArea from_cubic_feet_per_minute_per_square_foot(const un_scalar_t value)
        {
            return VolumeFlowPerArea(value, VolumeFlowPerAreaUnit::CubicFootPerMinutePerSquareFoot);
        }

        [[nodiscard]] static constexpr VolumeFlowPerArea from_invalid()
        {
            return VolumeFlowPerArea(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, VolumeFlowPerAreaUnit unit)
        {
            switch (unit)
            {

            case VolumeFlowPerAreaUnit::CubicMeterPerSecondPerSquareMeter:
                return value;

            case VolumeFlowPerAreaUnit::CubicFootPerMinutePerSquareFoot:
                return value * (static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(9.290304e-2);

            }

            throw std::invalid_argument("Unknown VolumeFlowPerArea unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const VolumeFlowPerAreaUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case VolumeFlowPerAreaUnit::CubicMeterPerSecondPerSquareMeter:
                return base_value;

            case VolumeFlowPerAreaUnit::CubicFootPerMinutePerSquareFoot:
                return base_value * static_cast<un_scalar_t>(9.290304e-2) / (static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(60));

            }

            throw std::invalid_argument("Unknown VolumeFlowPerArea unit.");
        }

        un_scalar_t value_;
        VolumeFlowPerAreaUnit value_unit_type_;       
    };
}
