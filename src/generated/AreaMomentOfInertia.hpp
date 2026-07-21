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
    enum class AreaMomentOfInertiaUnit : std::uint8_t
    {
        MeterToTheFourth,
        DecimeterToTheFourth,
        CentimeterToTheFourth,
        MillimeterToTheFourth,
        FootToTheFourth,
        InchToTheFourth,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of AreaMomentOfInertia.</summary>
    class AreaMomentOfInertiaDto
    {
    public:
        constexpr AreaMomentOfInertiaDto() noexcept
            : value{}, unit(AreaMomentOfInertiaUnit::MeterToTheFourth)
        {
        }

        constexpr AreaMomentOfInertiaDto(
            const un_scalar_t value,
            const AreaMomentOfInertiaUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        AreaMomentOfInertiaUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr AreaMomentOfInertiaUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<AreaMomentOfInertiaUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown AreaMomentOfInertia unit name.");
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
        [[nodiscard]] static AreaMomentOfInertiaDto from_json(const nlohmann::json& json)
        {
            return AreaMomentOfInertiaDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>A geometric property of an area that reflects how its points are distributed with regard to an axis.</summary>
    class AreaMomentOfInertia : public UnitsNetBase
    {
    public:
        constexpr explicit AreaMomentOfInertia(
            const un_scalar_t value,
            const AreaMomentOfInertiaUnit unit = AreaMomentOfInertiaUnit::MeterToTheFourth)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const AreaMomentOfInertiaUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr AreaMomentOfInertiaDto to_dto(
            const AreaMomentOfInertiaUnit unit = AreaMomentOfInertiaUnit::MeterToTheFourth) const
        {
            return AreaMomentOfInertiaDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr AreaMomentOfInertia from_dto(const AreaMomentOfInertiaDto& dto)
        {
            return AreaMomentOfInertia(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const AreaMomentOfInertiaUnit unit = AreaMomentOfInertiaUnit::MeterToTheFourth) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static AreaMomentOfInertia from_json(const nlohmann::json& json)
        {
            return from_dto(AreaMomentOfInertiaDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr AreaMomentOfInertia operator+(const AreaMomentOfInertia& other) const noexcept
        {
            return AreaMomentOfInertia(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr AreaMomentOfInertia operator-(const AreaMomentOfInertia& other)const noexcept
        {
            return AreaMomentOfInertia(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr AreaMomentOfInertia operator*(const un_scalar_t scalar) const noexcept
        {
            return AreaMomentOfInertia(base_value() * scalar);
        }

        [[nodiscard]] constexpr AreaMomentOfInertia operator/(const un_scalar_t scalar) const noexcept
        {
            return AreaMomentOfInertia(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const AreaMomentOfInertia& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const AreaMomentOfInertia& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const AreaMomentOfInertia& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t meters_to_the_fourth() const
        {
            return convert_from_base(AreaMomentOfInertiaUnit::MeterToTheFourth);
        }

        [[nodiscard]] static constexpr AreaMomentOfInertia from_meters_to_the_fourth(const un_scalar_t value)
        {
            return AreaMomentOfInertia(value, AreaMomentOfInertiaUnit::MeterToTheFourth);
        }

        [[nodiscard]] constexpr un_scalar_t decimeters_to_the_fourth() const
        {
            return convert_from_base(AreaMomentOfInertiaUnit::DecimeterToTheFourth);
        }

        [[nodiscard]] static constexpr AreaMomentOfInertia from_decimeters_to_the_fourth(const un_scalar_t value)
        {
            return AreaMomentOfInertia(value, AreaMomentOfInertiaUnit::DecimeterToTheFourth);
        }

        [[nodiscard]] constexpr un_scalar_t centimeters_to_the_fourth() const
        {
            return convert_from_base(AreaMomentOfInertiaUnit::CentimeterToTheFourth);
        }

        [[nodiscard]] static constexpr AreaMomentOfInertia from_centimeters_to_the_fourth(const un_scalar_t value)
        {
            return AreaMomentOfInertia(value, AreaMomentOfInertiaUnit::CentimeterToTheFourth);
        }

        [[nodiscard]] constexpr un_scalar_t millimeters_to_the_fourth() const
        {
            return convert_from_base(AreaMomentOfInertiaUnit::MillimeterToTheFourth);
        }

        [[nodiscard]] static constexpr AreaMomentOfInertia from_millimeters_to_the_fourth(const un_scalar_t value)
        {
            return AreaMomentOfInertia(value, AreaMomentOfInertiaUnit::MillimeterToTheFourth);
        }

        [[nodiscard]] constexpr un_scalar_t feet_to_the_fourth() const
        {
            return convert_from_base(AreaMomentOfInertiaUnit::FootToTheFourth);
        }

        [[nodiscard]] static constexpr AreaMomentOfInertia from_feet_to_the_fourth(const un_scalar_t value)
        {
            return AreaMomentOfInertia(value, AreaMomentOfInertiaUnit::FootToTheFourth);
        }

        [[nodiscard]] constexpr un_scalar_t inches_to_the_fourth() const
        {
            return convert_from_base(AreaMomentOfInertiaUnit::InchToTheFourth);
        }

        [[nodiscard]] static constexpr AreaMomentOfInertia from_inches_to_the_fourth(const un_scalar_t value)
        {
            return AreaMomentOfInertia(value, AreaMomentOfInertiaUnit::InchToTheFourth);
        }

        [[nodiscard]] static constexpr AreaMomentOfInertia from_invalid()
        {
            return AreaMomentOfInertia(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, AreaMomentOfInertiaUnit unit)
        {
            switch (unit)
            {

            case AreaMomentOfInertiaUnit::MeterToTheFourth:
                return value;

            case AreaMomentOfInertiaUnit::DecimeterToTheFourth:
                return value / static_cast<un_scalar_t>(1e4);

            case AreaMomentOfInertiaUnit::CentimeterToTheFourth:
                return value / static_cast<un_scalar_t>(1e8);

            case AreaMomentOfInertiaUnit::MillimeterToTheFourth:
                return value / static_cast<un_scalar_t>(1e12);

            case AreaMomentOfInertiaUnit::FootToTheFourth:
                return value * static_cast<un_scalar_t>(0.0086309748412416);

            case AreaMomentOfInertiaUnit::InchToTheFourth:
                return value * static_cast<un_scalar_t>(0.0000004162314256);

            }

            throw std::invalid_argument("Unknown AreaMomentOfInertia unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const AreaMomentOfInertiaUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case AreaMomentOfInertiaUnit::MeterToTheFourth:
                return base_value;

            case AreaMomentOfInertiaUnit::DecimeterToTheFourth:
                return base_value * static_cast<un_scalar_t>(1e4);

            case AreaMomentOfInertiaUnit::CentimeterToTheFourth:
                return base_value * static_cast<un_scalar_t>(1e8);

            case AreaMomentOfInertiaUnit::MillimeterToTheFourth:
                return base_value * static_cast<un_scalar_t>(1e12);

            case AreaMomentOfInertiaUnit::FootToTheFourth:
                return base_value / static_cast<un_scalar_t>(0.0086309748412416);

            case AreaMomentOfInertiaUnit::InchToTheFourth:
                return base_value / static_cast<un_scalar_t>(0.0000004162314256);

            }

            throw std::invalid_argument("Unknown AreaMomentOfInertia unit.");
        }

        un_scalar_t value_;
        AreaMomentOfInertiaUnit value_unit_type_;       
    };
}
