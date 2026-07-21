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
    enum class AccelerationUnit : std::uint8_t
    {
        MeterPerSecondSquared,
        NanometerPerSecondSquared,
        MicrometerPerSecondSquared,
        MillimeterPerSecondSquared,
        CentimeterPerSecondSquared,
        DecimeterPerSecondSquared,
        KilometerPerSecondSquared,
        InchPerSecondSquared,
        FootPerSecondSquared,
        KnotPerSecond,
        KnotPerMinute,
        KnotPerHour,
        StandardGravity,
        MillistandardGravity,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Acceleration.</summary>
    class AccelerationDto
    {
    public:
        constexpr AccelerationDto() noexcept
            : value{}, unit(AccelerationUnit::MeterPerSecondSquared)
        {
        }

        constexpr AccelerationDto(
            const un_scalar_t value,
            const AccelerationUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        AccelerationUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr AccelerationUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<AccelerationUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Acceleration unit name.");
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
        [[nodiscard]] static AccelerationDto from_json(const nlohmann::json& json)
        {
            return AccelerationDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Acceleration, in physics, is the rate at which the velocity of an object changes over time. An object's acceleration is the net result of any and all forces acting on the object, as described by Newton's Second Law. The SI unit for acceleration is the Meter per second squared (m/s²). Accelerations are vector quantities (they have magnitude and direction) and add according to the parallelogram law. As a vector, the calculated net force is equal to the product of the object's mass (a scalar quantity) and the acceleration.</summary>
    class Acceleration : public UnitsNetBase
    {
    public:
        constexpr explicit Acceleration(
            const un_scalar_t value,
            const AccelerationUnit unit = AccelerationUnit::MeterPerSecondSquared)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const AccelerationUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr AccelerationDto to_dto(
            const AccelerationUnit unit = AccelerationUnit::MeterPerSecondSquared) const
        {
            return AccelerationDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Acceleration from_dto(const AccelerationDto& dto)
        {
            return Acceleration(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const AccelerationUnit unit = AccelerationUnit::MeterPerSecondSquared) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Acceleration from_json(const nlohmann::json& json)
        {
            return from_dto(AccelerationDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Acceleration operator+(const Acceleration& other) const noexcept
        {
            return Acceleration(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Acceleration operator-(const Acceleration& other)const noexcept
        {
            return Acceleration(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Acceleration operator*(const un_scalar_t scalar) const noexcept
        {
            return Acceleration(base_value() * scalar);
        }

        [[nodiscard]] constexpr Acceleration operator/(const un_scalar_t scalar) const noexcept
        {
            return Acceleration(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Acceleration& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Acceleration& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Acceleration& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t meters_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::MeterPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_meters_per_second_squared(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::MeterPerSecondSquared);
        }

        [[nodiscard]] constexpr un_scalar_t nanometers_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::NanometerPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_nanometers_per_second_squared(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::NanometerPerSecondSquared);
        }

        [[nodiscard]] constexpr un_scalar_t micrometers_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::MicrometerPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_micrometers_per_second_squared(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::MicrometerPerSecondSquared);
        }

        [[nodiscard]] constexpr un_scalar_t millimeters_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::MillimeterPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_millimeters_per_second_squared(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::MillimeterPerSecondSquared);
        }

        [[nodiscard]] constexpr un_scalar_t centimeters_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::CentimeterPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_centimeters_per_second_squared(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::CentimeterPerSecondSquared);
        }

        [[nodiscard]] constexpr un_scalar_t decimeters_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::DecimeterPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_decimeters_per_second_squared(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::DecimeterPerSecondSquared);
        }

        [[nodiscard]] constexpr un_scalar_t kilometers_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::KilometerPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_kilometers_per_second_squared(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::KilometerPerSecondSquared);
        }

        [[nodiscard]] constexpr un_scalar_t inches_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::InchPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_inches_per_second_squared(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::InchPerSecondSquared);
        }

        [[nodiscard]] constexpr un_scalar_t feet_per_second_squared() const
        {
            return convert_from_base(AccelerationUnit::FootPerSecondSquared);
        }

        [[nodiscard]] static constexpr Acceleration from_feet_per_second_squared(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::FootPerSecondSquared);
        }

        [[nodiscard]] constexpr un_scalar_t knots_per_second() const
        {
            return convert_from_base(AccelerationUnit::KnotPerSecond);
        }

        [[nodiscard]] static constexpr Acceleration from_knots_per_second(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::KnotPerSecond);
        }

        /// <summary>The knot (/nɒt/) is a unit of speed equal to one nautical mile per hour, exactly 1.852 km/h (approximately 1.151 mph or 0.514 m/s).</summary>
        [[nodiscard]] constexpr un_scalar_t knots_per_minute() const
        {
            return convert_from_base(AccelerationUnit::KnotPerMinute);
        }

        /// <summary>The knot (/nɒt/) is a unit of speed equal to one nautical mile per hour, exactly 1.852 km/h (approximately 1.151 mph or 0.514 m/s).</summary>
        [[nodiscard]] static constexpr Acceleration from_knots_per_minute(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::KnotPerMinute);
        }

        /// <summary>The knot (/nɒt/) is a unit of speed equal to one nautical mile per hour, exactly 1.852 km/h (approximately 1.151 mph or 0.514 m/s).</summary>
        [[nodiscard]] constexpr un_scalar_t knots_per_hour() const
        {
            return convert_from_base(AccelerationUnit::KnotPerHour);
        }

        /// <summary>The knot (/nɒt/) is a unit of speed equal to one nautical mile per hour, exactly 1.852 km/h (approximately 1.151 mph or 0.514 m/s).</summary>
        [[nodiscard]] static constexpr Acceleration from_knots_per_hour(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::KnotPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t standard_gravity() const
        {
            return convert_from_base(AccelerationUnit::StandardGravity);
        }

        [[nodiscard]] static constexpr Acceleration from_standard_gravity(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::StandardGravity);
        }

        [[nodiscard]] constexpr un_scalar_t millistandard_gravity() const
        {
            return convert_from_base(AccelerationUnit::MillistandardGravity);
        }

        [[nodiscard]] static constexpr Acceleration from_millistandard_gravity(const un_scalar_t value)
        {
            return Acceleration(value, AccelerationUnit::MillistandardGravity);
        }

        [[nodiscard]] static constexpr Acceleration from_invalid()
        {
            return Acceleration(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, AccelerationUnit unit)
        {
            switch (unit)
            {

            case AccelerationUnit::MeterPerSecondSquared:
                return value;

            case AccelerationUnit::NanometerPerSecondSquared:
                return (value * static_cast<un_scalar_t>(1e-9));

            case AccelerationUnit::MicrometerPerSecondSquared:
                return (value * static_cast<un_scalar_t>(1e-6));

            case AccelerationUnit::MillimeterPerSecondSquared:
                return (value * static_cast<un_scalar_t>(1e-3));

            case AccelerationUnit::CentimeterPerSecondSquared:
                return (value * static_cast<un_scalar_t>(1e-2));

            case AccelerationUnit::DecimeterPerSecondSquared:
                return (value * static_cast<un_scalar_t>(1e-1));

            case AccelerationUnit::KilometerPerSecondSquared:
                return (value * static_cast<un_scalar_t>(1e3));

            case AccelerationUnit::InchPerSecondSquared:
                return value * static_cast<un_scalar_t>(0.0254);

            case AccelerationUnit::FootPerSecondSquared:
                return value * static_cast<un_scalar_t>(0.304800);

            case AccelerationUnit::KnotPerSecond:
                return value * (static_cast<un_scalar_t>(1852.0) / static_cast<un_scalar_t>(3600.0));

            case AccelerationUnit::KnotPerMinute:
                return value * (static_cast<un_scalar_t>(1852.0) / static_cast<un_scalar_t>(3600.0)) / static_cast<un_scalar_t>(60);

            case AccelerationUnit::KnotPerHour:
                return value * (static_cast<un_scalar_t>(1852.0) / static_cast<un_scalar_t>(3600.0)) / static_cast<un_scalar_t>(3600);

            case AccelerationUnit::StandardGravity:
                return value * static_cast<un_scalar_t>(9.80665);

            case AccelerationUnit::MillistandardGravity:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(9.80665);

            }

            throw std::invalid_argument("Unknown Acceleration unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const AccelerationUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case AccelerationUnit::MeterPerSecondSquared:
                return base_value;

            case AccelerationUnit::NanometerPerSecondSquared:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case AccelerationUnit::MicrometerPerSecondSquared:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case AccelerationUnit::MillimeterPerSecondSquared:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case AccelerationUnit::CentimeterPerSecondSquared:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case AccelerationUnit::DecimeterPerSecondSquared:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case AccelerationUnit::KilometerPerSecondSquared:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case AccelerationUnit::InchPerSecondSquared:
                return base_value / static_cast<un_scalar_t>(0.0254);

            case AccelerationUnit::FootPerSecondSquared:
                return base_value / static_cast<un_scalar_t>(0.304800);

            case AccelerationUnit::KnotPerSecond:
                return base_value / (static_cast<un_scalar_t>(1852.0) / static_cast<un_scalar_t>(3600.0));

            case AccelerationUnit::KnotPerMinute:
                return base_value * static_cast<un_scalar_t>(60) / (static_cast<un_scalar_t>(1852.0) / static_cast<un_scalar_t>(3600.0));

            case AccelerationUnit::KnotPerHour:
                return base_value * static_cast<un_scalar_t>(3600) / (static_cast<un_scalar_t>(1852.0) / static_cast<un_scalar_t>(3600.0));

            case AccelerationUnit::StandardGravity:
                return base_value / static_cast<un_scalar_t>(9.80665);

            case AccelerationUnit::MillistandardGravity:
                return (base_value / static_cast<un_scalar_t>(9.80665)) / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown Acceleration unit.");
        }

        un_scalar_t value_;
        AccelerationUnit value_unit_type_;       
    };
}
