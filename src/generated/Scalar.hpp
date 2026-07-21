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
    enum class ScalarUnit : std::uint8_t
    {
        Amount,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Scalar.</summary>
    class ScalarDto
    {
    public:
        constexpr ScalarDto() noexcept
            : value{}, unit(ScalarUnit::Amount)
        {
        }

        constexpr ScalarDto(
            const un_scalar_t value,
            const ScalarUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ScalarUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ScalarUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ScalarUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Scalar unit name.");
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
        [[nodiscard]] static ScalarDto from_json(const nlohmann::json& json)
        {
            return ScalarDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>A way of representing a number of items.</summary>
    class Scalar : public UnitsNetBase
    {
    public:
        constexpr explicit Scalar(
            const un_scalar_t value,
            const ScalarUnit unit = ScalarUnit::Amount)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ScalarUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ScalarDto to_dto(
            const ScalarUnit unit = ScalarUnit::Amount) const
        {
            return ScalarDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Scalar from_dto(const ScalarDto& dto)
        {
            return Scalar(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ScalarUnit unit = ScalarUnit::Amount) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Scalar from_json(const nlohmann::json& json)
        {
            return from_dto(ScalarDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Scalar operator+(const Scalar& other) const noexcept
        {
            return Scalar(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Scalar operator-(const Scalar& other)const noexcept
        {
            return Scalar(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Scalar operator*(const un_scalar_t scalar) const noexcept
        {
            return Scalar(base_value() * scalar);
        }

        [[nodiscard]] constexpr Scalar operator/(const un_scalar_t scalar) const noexcept
        {
            return Scalar(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Scalar& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Scalar& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Scalar& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t amount() const
        {
            return convert_from_base(ScalarUnit::Amount);
        }

        [[nodiscard]] static constexpr Scalar from_amount(const un_scalar_t value)
        {
            return Scalar(value, ScalarUnit::Amount);
        }

        [[nodiscard]] static constexpr Scalar from_invalid()
        {
            return Scalar(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ScalarUnit unit)
        {
            switch (unit)
            {

            case ScalarUnit::Amount:
                return value;

            }

            throw std::invalid_argument("Unknown Scalar unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ScalarUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ScalarUnit::Amount:
                return base_value;

            }

            throw std::invalid_argument("Unknown Scalar unit.");
        }

        un_scalar_t value_;
        ScalarUnit value_unit_type_;       
    };
}
