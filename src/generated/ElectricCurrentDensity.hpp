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
    enum class ElectricCurrentDensityUnit : std::uint8_t
    {
        AmperePerSquareMeter,
        AmperePerSquareInch,
        AmperePerSquareFoot,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ElectricCurrentDensity.</summary>
    class ElectricCurrentDensityDto
    {
    public:
        constexpr ElectricCurrentDensityDto() noexcept
            : value{}, unit(ElectricCurrentDensityUnit::AmperePerSquareMeter)
        {
        }

        constexpr ElectricCurrentDensityDto(
            const un_scalar_t value,
            const ElectricCurrentDensityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricCurrentDensityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricCurrentDensityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricCurrentDensityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricCurrentDensity unit name.");
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
        [[nodiscard]] static ElectricCurrentDensityDto from_json(const nlohmann::json& json)
        {
            return ElectricCurrentDensityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In electromagnetism, current density is the electric current per unit area of cross section.</summary>
    class ElectricCurrentDensity : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricCurrentDensity(
            const un_scalar_t value,
            const ElectricCurrentDensityUnit unit = ElectricCurrentDensityUnit::AmperePerSquareMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricCurrentDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricCurrentDensityDto to_dto(
            const ElectricCurrentDensityUnit unit = ElectricCurrentDensityUnit::AmperePerSquareMeter) const
        {
            return ElectricCurrentDensityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricCurrentDensity from_dto(const ElectricCurrentDensityDto& dto)
        {
            return ElectricCurrentDensity(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricCurrentDensityUnit unit = ElectricCurrentDensityUnit::AmperePerSquareMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricCurrentDensity from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricCurrentDensityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricCurrentDensity operator+(const ElectricCurrentDensity& other) const noexcept
        {
            return ElectricCurrentDensity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricCurrentDensity operator-(const ElectricCurrentDensity& other)const noexcept
        {
            return ElectricCurrentDensity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricCurrentDensity operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricCurrentDensity(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricCurrentDensity operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricCurrentDensity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricCurrentDensity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricCurrentDensity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricCurrentDensity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t amperes_per_square_meter() const
        {
            return convert_from_base(ElectricCurrentDensityUnit::AmperePerSquareMeter);
        }

        [[nodiscard]] static constexpr ElectricCurrentDensity from_amperes_per_square_meter(const un_scalar_t value)
        {
            return ElectricCurrentDensity(value, ElectricCurrentDensityUnit::AmperePerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t amperes_per_square_inch() const
        {
            return convert_from_base(ElectricCurrentDensityUnit::AmperePerSquareInch);
        }

        [[nodiscard]] static constexpr ElectricCurrentDensity from_amperes_per_square_inch(const un_scalar_t value)
        {
            return ElectricCurrentDensity(value, ElectricCurrentDensityUnit::AmperePerSquareInch);
        }

        [[nodiscard]] constexpr un_scalar_t amperes_per_square_foot() const
        {
            return convert_from_base(ElectricCurrentDensityUnit::AmperePerSquareFoot);
        }

        [[nodiscard]] static constexpr ElectricCurrentDensity from_amperes_per_square_foot(const un_scalar_t value)
        {
            return ElectricCurrentDensity(value, ElectricCurrentDensityUnit::AmperePerSquareFoot);
        }

        [[nodiscard]] static constexpr ElectricCurrentDensity from_invalid()
        {
            return ElectricCurrentDensity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricCurrentDensityUnit unit)
        {
            switch (unit)
            {

            case ElectricCurrentDensityUnit::AmperePerSquareMeter:
                return value;

            case ElectricCurrentDensityUnit::AmperePerSquareInch:
                return value / static_cast<un_scalar_t>(0.00064516);

            case ElectricCurrentDensityUnit::AmperePerSquareFoot:
                return value / static_cast<un_scalar_t>(9.290304e-2);

            }

            throw std::invalid_argument("Unknown ElectricCurrentDensity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricCurrentDensityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricCurrentDensityUnit::AmperePerSquareMeter:
                return base_value;

            case ElectricCurrentDensityUnit::AmperePerSquareInch:
                return base_value * static_cast<un_scalar_t>(0.00064516);

            case ElectricCurrentDensityUnit::AmperePerSquareFoot:
                return base_value * static_cast<un_scalar_t>(9.290304e-2);

            }

            throw std::invalid_argument("Unknown ElectricCurrentDensity unit.");
        }

        un_scalar_t value_;
        ElectricCurrentDensityUnit value_unit_type_;       
    };
}
