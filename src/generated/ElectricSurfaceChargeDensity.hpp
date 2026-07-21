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
    enum class ElectricSurfaceChargeDensityUnit : std::uint8_t
    {
        CoulombPerSquareMeter,
        CoulombPerSquareCentimeter,
        CoulombPerSquareInch,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ElectricSurfaceChargeDensity.</summary>
    class ElectricSurfaceChargeDensityDto
    {
    public:
        constexpr ElectricSurfaceChargeDensityDto() noexcept
            : value{}, unit(ElectricSurfaceChargeDensityUnit::CoulombPerSquareMeter)
        {
        }

        constexpr ElectricSurfaceChargeDensityDto(
            const un_scalar_t value,
            const ElectricSurfaceChargeDensityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricSurfaceChargeDensityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricSurfaceChargeDensityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricSurfaceChargeDensityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricSurfaceChargeDensity unit name.");
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
        [[nodiscard]] static ElectricSurfaceChargeDensityDto from_json(const nlohmann::json& json)
        {
            return ElectricSurfaceChargeDensityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In electromagnetism, surface charge density is a measure of the amount of electric charge per surface area.</summary>
    class ElectricSurfaceChargeDensity : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricSurfaceChargeDensity(
            const un_scalar_t value,
            const ElectricSurfaceChargeDensityUnit unit = ElectricSurfaceChargeDensityUnit::CoulombPerSquareMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricSurfaceChargeDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricSurfaceChargeDensityDto to_dto(
            const ElectricSurfaceChargeDensityUnit unit = ElectricSurfaceChargeDensityUnit::CoulombPerSquareMeter) const
        {
            return ElectricSurfaceChargeDensityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricSurfaceChargeDensity from_dto(const ElectricSurfaceChargeDensityDto& dto)
        {
            return ElectricSurfaceChargeDensity(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricSurfaceChargeDensityUnit unit = ElectricSurfaceChargeDensityUnit::CoulombPerSquareMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricSurfaceChargeDensity from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricSurfaceChargeDensityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricSurfaceChargeDensity operator+(const ElectricSurfaceChargeDensity& other) const noexcept
        {
            return ElectricSurfaceChargeDensity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricSurfaceChargeDensity operator-(const ElectricSurfaceChargeDensity& other)const noexcept
        {
            return ElectricSurfaceChargeDensity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricSurfaceChargeDensity operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricSurfaceChargeDensity(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricSurfaceChargeDensity operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricSurfaceChargeDensity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricSurfaceChargeDensity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricSurfaceChargeDensity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricSurfaceChargeDensity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t coulombs_per_square_meter() const
        {
            return convert_from_base(ElectricSurfaceChargeDensityUnit::CoulombPerSquareMeter);
        }

        [[nodiscard]] static constexpr ElectricSurfaceChargeDensity from_coulombs_per_square_meter(const un_scalar_t value)
        {
            return ElectricSurfaceChargeDensity(value, ElectricSurfaceChargeDensityUnit::CoulombPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t coulombs_per_square_centimeter() const
        {
            return convert_from_base(ElectricSurfaceChargeDensityUnit::CoulombPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr ElectricSurfaceChargeDensity from_coulombs_per_square_centimeter(const un_scalar_t value)
        {
            return ElectricSurfaceChargeDensity(value, ElectricSurfaceChargeDensityUnit::CoulombPerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t coulombs_per_square_inch() const
        {
            return convert_from_base(ElectricSurfaceChargeDensityUnit::CoulombPerSquareInch);
        }

        [[nodiscard]] static constexpr ElectricSurfaceChargeDensity from_coulombs_per_square_inch(const un_scalar_t value)
        {
            return ElectricSurfaceChargeDensity(value, ElectricSurfaceChargeDensityUnit::CoulombPerSquareInch);
        }

        [[nodiscard]] static constexpr ElectricSurfaceChargeDensity from_invalid()
        {
            return ElectricSurfaceChargeDensity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricSurfaceChargeDensityUnit unit)
        {
            switch (unit)
            {

            case ElectricSurfaceChargeDensityUnit::CoulombPerSquareMeter:
                return value;

            case ElectricSurfaceChargeDensityUnit::CoulombPerSquareCentimeter:
                return value * static_cast<un_scalar_t>(1.0e4);

            case ElectricSurfaceChargeDensityUnit::CoulombPerSquareInch:
                return value / static_cast<un_scalar_t>(0.00064516);

            }

            throw std::invalid_argument("Unknown ElectricSurfaceChargeDensity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricSurfaceChargeDensityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricSurfaceChargeDensityUnit::CoulombPerSquareMeter:
                return base_value;

            case ElectricSurfaceChargeDensityUnit::CoulombPerSquareCentimeter:
                return base_value / static_cast<un_scalar_t>(1.0e4);

            case ElectricSurfaceChargeDensityUnit::CoulombPerSquareInch:
                return base_value * static_cast<un_scalar_t>(0.00064516);

            }

            throw std::invalid_argument("Unknown ElectricSurfaceChargeDensity unit.");
        }

        un_scalar_t value_;
        ElectricSurfaceChargeDensityUnit value_unit_type_;       
    };
}
