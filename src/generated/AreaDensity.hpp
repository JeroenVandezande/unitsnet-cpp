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
    enum class AreaDensityUnit : std::uint8_t
    {
        KilogramPerSquareMeter,
        GramPerSquareMeter,
        MilligramPerSquareMeter,
        PoundPerSquareFoot,
        PoundPerThousandSquareFeet,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of AreaDensity.</summary>
    class AreaDensityDto
    {
    public:
        constexpr AreaDensityDto() noexcept
            : value{}, unit(AreaDensityUnit::KilogramPerSquareMeter)
        {
        }

        constexpr AreaDensityDto(
            const un_scalar_t value,
            const AreaDensityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        AreaDensityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr AreaDensityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<AreaDensityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown AreaDensity unit name.");
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
        [[nodiscard]] static AreaDensityDto from_json(const nlohmann::json& json)
        {
            return AreaDensityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The area density of a two-dimensional object is calculated as the mass per unit area. For paper this is also called grammage.</summary>
    class AreaDensity : public UnitsNetBase
    {
    public:
        constexpr explicit AreaDensity(
            const un_scalar_t value,
            const AreaDensityUnit unit = AreaDensityUnit::KilogramPerSquareMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const AreaDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr AreaDensityDto to_dto(
            const AreaDensityUnit unit = AreaDensityUnit::KilogramPerSquareMeter) const
        {
            return AreaDensityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr AreaDensity from_dto(const AreaDensityDto& dto)
        {
            return AreaDensity(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const AreaDensityUnit unit = AreaDensityUnit::KilogramPerSquareMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static AreaDensity from_json(const nlohmann::json& json)
        {
            return from_dto(AreaDensityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr AreaDensity operator+(const AreaDensity& other) const noexcept
        {
            return AreaDensity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr AreaDensity operator-(const AreaDensity& other)const noexcept
        {
            return AreaDensity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr AreaDensity operator*(const un_scalar_t scalar) const noexcept
        {
            return AreaDensity(base_value() * scalar);
        }

        [[nodiscard]] constexpr AreaDensity operator/(const un_scalar_t scalar) const noexcept
        {
            return AreaDensity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const AreaDensity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const AreaDensity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const AreaDensity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_square_meter() const
        {
            return convert_from_base(AreaDensityUnit::KilogramPerSquareMeter);
        }

        [[nodiscard]] static constexpr AreaDensity from_kilograms_per_square_meter(const un_scalar_t value)
        {
            return AreaDensity(value, AreaDensityUnit::KilogramPerSquareMeter);
        }

        /// <summary>Also known as grammage for paper industry. In fiber industry used with abbreviation 'gsm'.</summary>
        [[nodiscard]] constexpr un_scalar_t grams_per_square_meter() const
        {
            return convert_from_base(AreaDensityUnit::GramPerSquareMeter);
        }

        /// <summary>Also known as grammage for paper industry. In fiber industry used with abbreviation 'gsm'.</summary>
        [[nodiscard]] static constexpr AreaDensity from_grams_per_square_meter(const un_scalar_t value)
        {
            return AreaDensity(value, AreaDensityUnit::GramPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_square_meter() const
        {
            return convert_from_base(AreaDensityUnit::MilligramPerSquareMeter);
        }

        [[nodiscard]] static constexpr AreaDensity from_milligrams_per_square_meter(const un_scalar_t value)
        {
            return AreaDensity(value, AreaDensityUnit::MilligramPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_square_foot() const
        {
            return convert_from_base(AreaDensityUnit::PoundPerSquareFoot);
        }

        [[nodiscard]] static constexpr AreaDensity from_pounds_per_square_foot(const un_scalar_t value)
        {
            return AreaDensity(value, AreaDensityUnit::PoundPerSquareFoot);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_thousand_square_feet() const
        {
            return convert_from_base(AreaDensityUnit::PoundPerThousandSquareFeet);
        }

        [[nodiscard]] static constexpr AreaDensity from_pounds_per_thousand_square_feet(const un_scalar_t value)
        {
            return AreaDensity(value, AreaDensityUnit::PoundPerThousandSquareFeet);
        }

        [[nodiscard]] static constexpr AreaDensity from_invalid()
        {
            return AreaDensity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, AreaDensityUnit unit)
        {
            switch (unit)
            {

            case AreaDensityUnit::KilogramPerSquareMeter:
                return value;

            case AreaDensityUnit::GramPerSquareMeter:
                return value / static_cast<un_scalar_t>(1000);

            case AreaDensityUnit::MilligramPerSquareMeter:
                return value / static_cast<un_scalar_t>(1000000);

            case AreaDensityUnit::PoundPerSquareFoot:
                return value * (static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.09290304));

            case AreaDensityUnit::PoundPerThousandSquareFeet:
                return value * (static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.09290304)) / static_cast<un_scalar_t>(1000);

            }

            throw std::invalid_argument("Unknown AreaDensity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const AreaDensityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case AreaDensityUnit::KilogramPerSquareMeter:
                return base_value;

            case AreaDensityUnit::GramPerSquareMeter:
                return base_value * static_cast<un_scalar_t>(1000);

            case AreaDensityUnit::MilligramPerSquareMeter:
                return base_value * static_cast<un_scalar_t>(1000000);

            case AreaDensityUnit::PoundPerSquareFoot:
                return base_value / (static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.09290304));

            case AreaDensityUnit::PoundPerThousandSquareFeet:
                return base_value / (static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.09290304)) * static_cast<un_scalar_t>(1000);

            }

            throw std::invalid_argument("Unknown AreaDensity unit.");
        }

        un_scalar_t value_;
        AreaDensityUnit value_unit_type_;       
    };
}
