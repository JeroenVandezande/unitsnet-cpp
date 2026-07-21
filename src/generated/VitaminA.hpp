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
    enum class VitaminAUnit : std::uint8_t
    {
        InternationalUnit,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of VitaminA.</summary>
    class VitaminADto
    {
    public:
        constexpr VitaminADto() noexcept
            : value{}, unit(VitaminAUnit::InternationalUnit)
        {
        }

        constexpr VitaminADto(
            const un_scalar_t value,
            const VitaminAUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        VitaminAUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr VitaminAUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<VitaminAUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown VitaminA unit name.");
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
        [[nodiscard]] static VitaminADto from_json(const nlohmann::json& json)
        {
            return VitaminADto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Vitamin A: 1 IU is the biological equivalent of 0.3 µg retinol, or of 0.6 µg beta-carotene.</summary>
    class VitaminA : public UnitsNetBase
    {
    public:
        constexpr explicit VitaminA(
            const un_scalar_t value,
            const VitaminAUnit unit = VitaminAUnit::InternationalUnit)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const VitaminAUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr VitaminADto to_dto(
            const VitaminAUnit unit = VitaminAUnit::InternationalUnit) const
        {
            return VitaminADto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr VitaminA from_dto(const VitaminADto& dto)
        {
            return VitaminA(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const VitaminAUnit unit = VitaminAUnit::InternationalUnit) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static VitaminA from_json(const nlohmann::json& json)
        {
            return from_dto(VitaminADto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr VitaminA operator+(const VitaminA& other) const noexcept
        {
            return VitaminA(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr VitaminA operator-(const VitaminA& other)const noexcept
        {
            return VitaminA(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr VitaminA operator*(const un_scalar_t scalar) const noexcept
        {
            return VitaminA(base_value() * scalar);
        }

        [[nodiscard]] constexpr VitaminA operator/(const un_scalar_t scalar) const noexcept
        {
            return VitaminA(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const VitaminA& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const VitaminA& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const VitaminA& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t international_units() const
        {
            return convert_from_base(VitaminAUnit::InternationalUnit);
        }

        [[nodiscard]] static constexpr VitaminA from_international_units(const un_scalar_t value)
        {
            return VitaminA(value, VitaminAUnit::InternationalUnit);
        }

        [[nodiscard]] static constexpr VitaminA from_invalid()
        {
            return VitaminA(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, VitaminAUnit unit)
        {
            switch (unit)
            {

            case VitaminAUnit::InternationalUnit:
                return value;

            }

            throw std::invalid_argument("Unknown VitaminA unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const VitaminAUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case VitaminAUnit::InternationalUnit:
                return base_value;

            }

            throw std::invalid_argument("Unknown VitaminA unit.");
        }

        un_scalar_t value_;
        VitaminAUnit value_unit_type_;       
    };
}
