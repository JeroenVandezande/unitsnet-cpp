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
    enum class JerkUnit : std::uint8_t
    {
        MeterPerSecondCubed,
        NanometerPerSecondCubed,
        MicrometerPerSecondCubed,
        MillimeterPerSecondCubed,
        CentimeterPerSecondCubed,
        DecimeterPerSecondCubed,
        KilometerPerSecondCubed,
        InchPerSecondCubed,
        FootPerSecondCubed,
        StandardGravitiesPerSecond,
        MillistandardGravitiesPerSecond,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Jerk.</summary>
    class JerkDto
    {
    public:
        constexpr JerkDto() noexcept
            : value{}, unit(JerkUnit::MeterPerSecondCubed)
        {
        }

        constexpr JerkDto(
            const un_scalar_t value,
            const JerkUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        JerkUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr JerkUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<JerkUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Jerk unit name.");
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
        [[nodiscard]] static JerkDto from_json(const nlohmann::json& json)
        {
            return JerkDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary></summary>
    class Jerk : public UnitsNetBase
    {
    public:
        constexpr explicit Jerk(
            const un_scalar_t value,
            const JerkUnit unit = JerkUnit::MeterPerSecondCubed)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const JerkUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr JerkDto to_dto(
            const JerkUnit unit = JerkUnit::MeterPerSecondCubed) const
        {
            return JerkDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Jerk from_dto(const JerkDto& dto)
        {
            return Jerk(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const JerkUnit unit = JerkUnit::MeterPerSecondCubed) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Jerk from_json(const nlohmann::json& json)
        {
            return from_dto(JerkDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Jerk operator+(const Jerk& other) const noexcept
        {
            return Jerk(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Jerk operator-(const Jerk& other)const noexcept
        {
            return Jerk(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Jerk operator*(const un_scalar_t scalar) const noexcept
        {
            return Jerk(base_value() * scalar);
        }

        [[nodiscard]] constexpr Jerk operator/(const un_scalar_t scalar) const noexcept
        {
            return Jerk(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Jerk& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Jerk& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Jerk& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t meters_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::MeterPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_meters_per_second_cubed(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::MeterPerSecondCubed);
        }

        [[nodiscard]] constexpr un_scalar_t nanometers_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::NanometerPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_nanometers_per_second_cubed(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::NanometerPerSecondCubed);
        }

        [[nodiscard]] constexpr un_scalar_t micrometers_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::MicrometerPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_micrometers_per_second_cubed(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::MicrometerPerSecondCubed);
        }

        [[nodiscard]] constexpr un_scalar_t millimeters_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::MillimeterPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_millimeters_per_second_cubed(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::MillimeterPerSecondCubed);
        }

        [[nodiscard]] constexpr un_scalar_t centimeters_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::CentimeterPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_centimeters_per_second_cubed(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::CentimeterPerSecondCubed);
        }

        [[nodiscard]] constexpr un_scalar_t decimeters_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::DecimeterPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_decimeters_per_second_cubed(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::DecimeterPerSecondCubed);
        }

        [[nodiscard]] constexpr un_scalar_t kilometers_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::KilometerPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_kilometers_per_second_cubed(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::KilometerPerSecondCubed);
        }

        [[nodiscard]] constexpr un_scalar_t inches_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::InchPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_inches_per_second_cubed(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::InchPerSecondCubed);
        }

        [[nodiscard]] constexpr un_scalar_t feet_per_second_cubed() const
        {
            return convert_from_base(JerkUnit::FootPerSecondCubed);
        }

        [[nodiscard]] static constexpr Jerk from_feet_per_second_cubed(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::FootPerSecondCubed);
        }

        [[nodiscard]] constexpr un_scalar_t standard_gravities_per_second() const
        {
            return convert_from_base(JerkUnit::StandardGravitiesPerSecond);
        }

        [[nodiscard]] static constexpr Jerk from_standard_gravities_per_second(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::StandardGravitiesPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t millistandard_gravities_per_second() const
        {
            return convert_from_base(JerkUnit::MillistandardGravitiesPerSecond);
        }

        [[nodiscard]] static constexpr Jerk from_millistandard_gravities_per_second(const un_scalar_t value)
        {
            return Jerk(value, JerkUnit::MillistandardGravitiesPerSecond);
        }

        [[nodiscard]] static constexpr Jerk from_invalid()
        {
            return Jerk(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, JerkUnit unit)
        {
            switch (unit)
            {

            case JerkUnit::MeterPerSecondCubed:
                return value;

            case JerkUnit::NanometerPerSecondCubed:
                return (value * static_cast<un_scalar_t>(1e-9));

            case JerkUnit::MicrometerPerSecondCubed:
                return (value * static_cast<un_scalar_t>(1e-6));

            case JerkUnit::MillimeterPerSecondCubed:
                return (value * static_cast<un_scalar_t>(1e-3));

            case JerkUnit::CentimeterPerSecondCubed:
                return (value * static_cast<un_scalar_t>(1e-2));

            case JerkUnit::DecimeterPerSecondCubed:
                return (value * static_cast<un_scalar_t>(1e-1));

            case JerkUnit::KilometerPerSecondCubed:
                return (value * static_cast<un_scalar_t>(1e3));

            case JerkUnit::InchPerSecondCubed:
                return value * static_cast<un_scalar_t>(0.0254);

            case JerkUnit::FootPerSecondCubed:
                return value * static_cast<un_scalar_t>(0.304800);

            case JerkUnit::StandardGravitiesPerSecond:
                return value * static_cast<un_scalar_t>(9.80665);

            case JerkUnit::MillistandardGravitiesPerSecond:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(9.80665);

            }

            throw std::invalid_argument("Unknown Jerk unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const JerkUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case JerkUnit::MeterPerSecondCubed:
                return base_value;

            case JerkUnit::NanometerPerSecondCubed:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case JerkUnit::MicrometerPerSecondCubed:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case JerkUnit::MillimeterPerSecondCubed:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case JerkUnit::CentimeterPerSecondCubed:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case JerkUnit::DecimeterPerSecondCubed:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case JerkUnit::KilometerPerSecondCubed:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case JerkUnit::InchPerSecondCubed:
                return base_value / static_cast<un_scalar_t>(0.0254);

            case JerkUnit::FootPerSecondCubed:
                return base_value / static_cast<un_scalar_t>(0.304800);

            case JerkUnit::StandardGravitiesPerSecond:
                return base_value / static_cast<un_scalar_t>(9.80665);

            case JerkUnit::MillistandardGravitiesPerSecond:
                return (base_value / static_cast<un_scalar_t>(9.80665)) / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown Jerk unit.");
        }

        un_scalar_t value_;
        JerkUnit value_unit_type_;       
    };
}
