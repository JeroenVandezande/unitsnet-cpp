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
    enum class RatioUnit : std::uint8_t
    {
        DecimalFraction,
        Percent,
        PartPerThousand,
        PartPerMillion,
        PartPerBillion,
        PartPerTrillion,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Ratio.</summary>
    class RatioDto
    {
    public:
        constexpr RatioDto() noexcept
            : value{}, unit(RatioUnit::DecimalFraction)
        {
        }

        constexpr RatioDto(
            const un_scalar_t value,
            const RatioUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        RatioUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr RatioUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<RatioUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Ratio unit name.");
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
        [[nodiscard]] static RatioDto from_json(const nlohmann::json& json)
        {
            return RatioDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In mathematics, a ratio is a relationship between two numbers of the same kind (e.g., objects, persons, students, spoonfuls, units of whatever identical dimension), usually expressed as "a to b" or a:b, sometimes expressed arithmetically as a dimensionless quotient of the two that explicitly indicates how many times the first number contains the second (not necessarily an integer).</summary>
    class Ratio : public UnitsNetBase
    {
    public:
        constexpr explicit Ratio(
            const un_scalar_t value,
            const RatioUnit unit = RatioUnit::DecimalFraction)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const RatioUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr RatioDto to_dto(
            const RatioUnit unit = RatioUnit::DecimalFraction) const
        {
            return RatioDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Ratio from_dto(const RatioDto& dto)
        {
            return Ratio(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const RatioUnit unit = RatioUnit::DecimalFraction) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Ratio from_json(const nlohmann::json& json)
        {
            return from_dto(RatioDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Ratio operator+(const Ratio& other) const noexcept
        {
            return Ratio(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Ratio operator-(const Ratio& other)const noexcept
        {
            return Ratio(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Ratio operator*(const un_scalar_t scalar) const noexcept
        {
            return Ratio(base_value() * scalar);
        }

        [[nodiscard]] constexpr Ratio operator/(const un_scalar_t scalar) const noexcept
        {
            return Ratio(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Ratio& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Ratio& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Ratio& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t decimal_fractions() const
        {
            return convert_from_base(RatioUnit::DecimalFraction);
        }

        [[nodiscard]] static constexpr Ratio from_decimal_fractions(const un_scalar_t value)
        {
            return Ratio(value, RatioUnit::DecimalFraction);
        }

        [[nodiscard]] constexpr un_scalar_t percent() const
        {
            return convert_from_base(RatioUnit::Percent);
        }

        [[nodiscard]] static constexpr Ratio from_percent(const un_scalar_t value)
        {
            return Ratio(value, RatioUnit::Percent);
        }

        [[nodiscard]] constexpr un_scalar_t parts_per_thousand() const
        {
            return convert_from_base(RatioUnit::PartPerThousand);
        }

        [[nodiscard]] static constexpr Ratio from_parts_per_thousand(const un_scalar_t value)
        {
            return Ratio(value, RatioUnit::PartPerThousand);
        }

        [[nodiscard]] constexpr un_scalar_t parts_per_million() const
        {
            return convert_from_base(RatioUnit::PartPerMillion);
        }

        [[nodiscard]] static constexpr Ratio from_parts_per_million(const un_scalar_t value)
        {
            return Ratio(value, RatioUnit::PartPerMillion);
        }

        [[nodiscard]] constexpr un_scalar_t parts_per_billion() const
        {
            return convert_from_base(RatioUnit::PartPerBillion);
        }

        [[nodiscard]] static constexpr Ratio from_parts_per_billion(const un_scalar_t value)
        {
            return Ratio(value, RatioUnit::PartPerBillion);
        }

        [[nodiscard]] constexpr un_scalar_t parts_per_trillion() const
        {
            return convert_from_base(RatioUnit::PartPerTrillion);
        }

        [[nodiscard]] static constexpr Ratio from_parts_per_trillion(const un_scalar_t value)
        {
            return Ratio(value, RatioUnit::PartPerTrillion);
        }

        [[nodiscard]] static constexpr Ratio from_invalid()
        {
            return Ratio(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RatioUnit unit)
        {
            switch (unit)
            {

            case RatioUnit::DecimalFraction:
                return value;

            case RatioUnit::Percent:
                return value / static_cast<un_scalar_t>(1e2);

            case RatioUnit::PartPerThousand:
                return value / static_cast<un_scalar_t>(1e3);

            case RatioUnit::PartPerMillion:
                return value / static_cast<un_scalar_t>(1e6);

            case RatioUnit::PartPerBillion:
                return value / static_cast<un_scalar_t>(1e9);

            case RatioUnit::PartPerTrillion:
                return value / static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown Ratio unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RatioUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case RatioUnit::DecimalFraction:
                return base_value;

            case RatioUnit::Percent:
                return base_value * static_cast<un_scalar_t>(1e2);

            case RatioUnit::PartPerThousand:
                return base_value * static_cast<un_scalar_t>(1e3);

            case RatioUnit::PartPerMillion:
                return base_value * static_cast<un_scalar_t>(1e6);

            case RatioUnit::PartPerBillion:
                return base_value * static_cast<un_scalar_t>(1e9);

            case RatioUnit::PartPerTrillion:
                return base_value * static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown Ratio unit.");
        }

        un_scalar_t value_;
        RatioUnit value_unit_type_;       
    };
}
