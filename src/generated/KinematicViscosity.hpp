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
    enum class KinematicViscosityUnit : std::uint8_t
    {
        SquareMeterPerSecond,
        Stokes,
        Nanostokes,
        Microstokes,
        Millistokes,
        Centistokes,
        Decistokes,
        Kilostokes,
        SquareFootPerSecond,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of KinematicViscosity.</summary>
    class KinematicViscosityDto
    {
    public:
        constexpr KinematicViscosityDto() noexcept
            : value{}, unit(KinematicViscosityUnit::SquareMeterPerSecond)
        {
        }

        constexpr KinematicViscosityDto(
            const un_scalar_t value,
            const KinematicViscosityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        KinematicViscosityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr KinematicViscosityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<KinematicViscosityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown KinematicViscosity unit name.");
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
        [[nodiscard]] static KinematicViscosityDto from_json(const nlohmann::json& json)
        {
            return KinematicViscosityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The viscosity of a fluid is a measure of its resistance to gradual deformation by shear stress or tensile stress.</summary>
    class KinematicViscosity : public UnitsNetBase
    {
    public:
        constexpr explicit KinematicViscosity(
            const un_scalar_t value,
            const KinematicViscosityUnit unit = KinematicViscosityUnit::SquareMeterPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const KinematicViscosityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr KinematicViscosityDto to_dto(
            const KinematicViscosityUnit unit = KinematicViscosityUnit::SquareMeterPerSecond) const
        {
            return KinematicViscosityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr KinematicViscosity from_dto(const KinematicViscosityDto& dto)
        {
            return KinematicViscosity(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const KinematicViscosityUnit unit = KinematicViscosityUnit::SquareMeterPerSecond) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static KinematicViscosity from_json(const nlohmann::json& json)
        {
            return from_dto(KinematicViscosityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr KinematicViscosity operator+(const KinematicViscosity& other) const noexcept
        {
            return KinematicViscosity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr KinematicViscosity operator-(const KinematicViscosity& other)const noexcept
        {
            return KinematicViscosity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr KinematicViscosity operator*(const un_scalar_t scalar) const noexcept
        {
            return KinematicViscosity(base_value() * scalar);
        }

        [[nodiscard]] constexpr KinematicViscosity operator/(const un_scalar_t scalar) const noexcept
        {
            return KinematicViscosity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const KinematicViscosity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const KinematicViscosity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const KinematicViscosity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t square_meters_per_second() const
        {
            return convert_from_base(KinematicViscosityUnit::SquareMeterPerSecond);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_square_meters_per_second(const un_scalar_t value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::SquareMeterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t stokes() const
        {
            return convert_from_base(KinematicViscosityUnit::Stokes);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_stokes(const un_scalar_t value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::Stokes);
        }

        [[nodiscard]] constexpr un_scalar_t nanostokes() const
        {
            return convert_from_base(KinematicViscosityUnit::Nanostokes);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_nanostokes(const un_scalar_t value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::Nanostokes);
        }

        [[nodiscard]] constexpr un_scalar_t microstokes() const
        {
            return convert_from_base(KinematicViscosityUnit::Microstokes);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_microstokes(const un_scalar_t value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::Microstokes);
        }

        [[nodiscard]] constexpr un_scalar_t millistokes() const
        {
            return convert_from_base(KinematicViscosityUnit::Millistokes);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_millistokes(const un_scalar_t value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::Millistokes);
        }

        [[nodiscard]] constexpr un_scalar_t centistokes() const
        {
            return convert_from_base(KinematicViscosityUnit::Centistokes);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_centistokes(const un_scalar_t value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::Centistokes);
        }

        [[nodiscard]] constexpr un_scalar_t decistokes() const
        {
            return convert_from_base(KinematicViscosityUnit::Decistokes);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_decistokes(const un_scalar_t value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::Decistokes);
        }

        [[nodiscard]] constexpr un_scalar_t kilostokes() const
        {
            return convert_from_base(KinematicViscosityUnit::Kilostokes);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_kilostokes(const un_scalar_t value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::Kilostokes);
        }

        [[nodiscard]] constexpr un_scalar_t square_feet_per_second() const
        {
            return convert_from_base(KinematicViscosityUnit::SquareFootPerSecond);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_square_feet_per_second(const un_scalar_t value)
        {
            return KinematicViscosity(value, KinematicViscosityUnit::SquareFootPerSecond);
        }

        [[nodiscard]] static constexpr KinematicViscosity from_invalid()
        {
            return KinematicViscosity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, KinematicViscosityUnit unit)
        {
            switch (unit)
            {

            case KinematicViscosityUnit::SquareMeterPerSecond:
                return value;

            case KinematicViscosityUnit::Stokes:
                return value / static_cast<un_scalar_t>(1e4);

            case KinematicViscosityUnit::Nanostokes:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e4);

            case KinematicViscosityUnit::Microstokes:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e4);

            case KinematicViscosityUnit::Millistokes:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e4);

            case KinematicViscosityUnit::Centistokes:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e4);

            case KinematicViscosityUnit::Decistokes:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e4);

            case KinematicViscosityUnit::Kilostokes:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e4);

            case KinematicViscosityUnit::SquareFootPerSecond:
                return value * static_cast<un_scalar_t>(9.290304e-2);

            }

            throw std::invalid_argument("Unknown KinematicViscosity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const KinematicViscosityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case KinematicViscosityUnit::SquareMeterPerSecond:
                return base_value;

            case KinematicViscosityUnit::Stokes:
                return base_value * static_cast<un_scalar_t>(1e4);

            case KinematicViscosityUnit::Nanostokes:
                return (base_value * static_cast<un_scalar_t>(1e4)) / static_cast<un_scalar_t>(1e-9);

            case KinematicViscosityUnit::Microstokes:
                return (base_value * static_cast<un_scalar_t>(1e4)) / static_cast<un_scalar_t>(1e-6);

            case KinematicViscosityUnit::Millistokes:
                return (base_value * static_cast<un_scalar_t>(1e4)) / static_cast<un_scalar_t>(1e-3);

            case KinematicViscosityUnit::Centistokes:
                return (base_value * static_cast<un_scalar_t>(1e4)) / static_cast<un_scalar_t>(1e-2);

            case KinematicViscosityUnit::Decistokes:
                return (base_value * static_cast<un_scalar_t>(1e4)) / static_cast<un_scalar_t>(1e-1);

            case KinematicViscosityUnit::Kilostokes:
                return (base_value * static_cast<un_scalar_t>(1e4)) / static_cast<un_scalar_t>(1e3);

            case KinematicViscosityUnit::SquareFootPerSecond:
                return base_value / static_cast<un_scalar_t>(9.290304e-2);

            }

            throw std::invalid_argument("Unknown KinematicViscosity unit.");
        }

        un_scalar_t value_;
        KinematicViscosityUnit value_unit_type_;       
    };
}
