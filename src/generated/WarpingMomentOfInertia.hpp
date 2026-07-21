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
    enum class WarpingMomentOfInertiaUnit : std::uint8_t
    {
        MeterToTheSixth,
        DecimeterToTheSixth,
        CentimeterToTheSixth,
        MillimeterToTheSixth,
        FootToTheSixth,
        InchToTheSixth,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of WarpingMomentOfInertia.</summary>
    class WarpingMomentOfInertiaDto
    {
    public:
        constexpr WarpingMomentOfInertiaDto() noexcept
            : value{}, unit(WarpingMomentOfInertiaUnit::MeterToTheSixth)
        {
        }

        constexpr WarpingMomentOfInertiaDto(
            const un_scalar_t value,
            const WarpingMomentOfInertiaUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        WarpingMomentOfInertiaUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr WarpingMomentOfInertiaUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<WarpingMomentOfInertiaUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown WarpingMomentOfInertia unit name.");
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
        [[nodiscard]] static WarpingMomentOfInertiaDto from_json(const nlohmann::json& json)
        {
            return WarpingMomentOfInertiaDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>A geometric property of an area that is used to determine the warping stress.</summary>
    class WarpingMomentOfInertia : public UnitsNetBase
    {
    public:
        constexpr explicit WarpingMomentOfInertia(
            const un_scalar_t value,
            const WarpingMomentOfInertiaUnit unit = WarpingMomentOfInertiaUnit::MeterToTheSixth)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const WarpingMomentOfInertiaUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr WarpingMomentOfInertiaDto to_dto(
            const WarpingMomentOfInertiaUnit unit = WarpingMomentOfInertiaUnit::MeterToTheSixth) const
        {
            return WarpingMomentOfInertiaDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr WarpingMomentOfInertia from_dto(const WarpingMomentOfInertiaDto& dto)
        {
            return WarpingMomentOfInertia(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const WarpingMomentOfInertiaUnit unit = WarpingMomentOfInertiaUnit::MeterToTheSixth) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static WarpingMomentOfInertia from_json(const nlohmann::json& json)
        {
            return from_dto(WarpingMomentOfInertiaDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr WarpingMomentOfInertia operator+(const WarpingMomentOfInertia& other) const noexcept
        {
            return WarpingMomentOfInertia(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr WarpingMomentOfInertia operator-(const WarpingMomentOfInertia& other)const noexcept
        {
            return WarpingMomentOfInertia(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr WarpingMomentOfInertia operator*(const un_scalar_t scalar) const noexcept
        {
            return WarpingMomentOfInertia(base_value() * scalar);
        }

        [[nodiscard]] constexpr WarpingMomentOfInertia operator/(const un_scalar_t scalar) const noexcept
        {
            return WarpingMomentOfInertia(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const WarpingMomentOfInertia& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const WarpingMomentOfInertia& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const WarpingMomentOfInertia& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t meters_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::MeterToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_meters_to_the_sixth(const un_scalar_t value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::MeterToTheSixth);
        }

        [[nodiscard]] constexpr un_scalar_t decimeters_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::DecimeterToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_decimeters_to_the_sixth(const un_scalar_t value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::DecimeterToTheSixth);
        }

        [[nodiscard]] constexpr un_scalar_t centimeters_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::CentimeterToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_centimeters_to_the_sixth(const un_scalar_t value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::CentimeterToTheSixth);
        }

        [[nodiscard]] constexpr un_scalar_t millimeters_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::MillimeterToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_millimeters_to_the_sixth(const un_scalar_t value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::MillimeterToTheSixth);
        }

        [[nodiscard]] constexpr un_scalar_t feet_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::FootToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_feet_to_the_sixth(const un_scalar_t value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::FootToTheSixth);
        }

        [[nodiscard]] constexpr un_scalar_t inches_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::InchToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_inches_to_the_sixth(const un_scalar_t value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::InchToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_invalid()
        {
            return WarpingMomentOfInertia(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, WarpingMomentOfInertiaUnit unit)
        {
            switch (unit)
            {

            case WarpingMomentOfInertiaUnit::MeterToTheSixth:
                return value;

            case WarpingMomentOfInertiaUnit::DecimeterToTheSixth:
                return value / static_cast<un_scalar_t>(1e6);

            case WarpingMomentOfInertiaUnit::CentimeterToTheSixth:
                return value / static_cast<un_scalar_t>(1e12);

            case WarpingMomentOfInertiaUnit::MillimeterToTheSixth:
                return value / static_cast<un_scalar_t>(1e18);

            case WarpingMomentOfInertiaUnit::FootToTheSixth:
                return value * static_cast<un_scalar_t>(0.000801843800914862014464);

            case WarpingMomentOfInertiaUnit::InchToTheSixth:
                return value * static_cast<un_scalar_t>(0.000000000268535866540096);

            }

            throw std::invalid_argument("Unknown WarpingMomentOfInertia unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const WarpingMomentOfInertiaUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case WarpingMomentOfInertiaUnit::MeterToTheSixth:
                return base_value;

            case WarpingMomentOfInertiaUnit::DecimeterToTheSixth:
                return base_value * static_cast<un_scalar_t>(1e6);

            case WarpingMomentOfInertiaUnit::CentimeterToTheSixth:
                return base_value * static_cast<un_scalar_t>(1e12);

            case WarpingMomentOfInertiaUnit::MillimeterToTheSixth:
                return base_value * static_cast<un_scalar_t>(1e18);

            case WarpingMomentOfInertiaUnit::FootToTheSixth:
                return base_value / static_cast<un_scalar_t>(0.000801843800914862014464);

            case WarpingMomentOfInertiaUnit::InchToTheSixth:
                return base_value / static_cast<un_scalar_t>(0.000000000268535866540096);

            }

            throw std::invalid_argument("Unknown WarpingMomentOfInertia unit.");
        }

        un_scalar_t value_;
        WarpingMomentOfInertiaUnit value_unit_type_;       
    };
}
