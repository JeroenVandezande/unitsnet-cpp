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
    enum class AngleUnit : std::uint8_t
    {
        Radian,
        Nanoradian,
        Microradian,
        Milliradian,
        Centiradian,
        Deciradian,
        Degree,
        Nanodegree,
        Microdegree,
        Millidegree,
        Arcminute,
        Arcsecond,
        Gradian,
        NatoMil,
        Revolution,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Angle.</summary>
    class AngleDto
    {
    public:
        constexpr AngleDto() noexcept
            : value{}, unit(AngleUnit::Radian)
        {
        }

        constexpr AngleDto(
            const un_scalar_t value,
            const AngleUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        AngleUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr AngleUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<AngleUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Angle unit name.");
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
        [[nodiscard]] static AngleDto from_json(const nlohmann::json& json)
        {
            return AngleDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In geometry, an angle is the figure formed by two rays, called the sides of the angle, sharing a common endpoint, called the vertex of the angle.</summary>
    class Angle : public UnitsNetBase
    {
    public:
        constexpr explicit Angle(
            const un_scalar_t value,
            const AngleUnit unit = AngleUnit::Radian)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const AngleUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr AngleDto to_dto(
            const AngleUnit unit = AngleUnit::Radian) const
        {
            return AngleDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Angle from_dto(const AngleDto& dto)
        {
            return Angle(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const AngleUnit unit = AngleUnit::Radian) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Angle from_json(const nlohmann::json& json)
        {
            return from_dto(AngleDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Angle operator+(const Angle& other) const noexcept
        {
            return Angle(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Angle operator-(const Angle& other)const noexcept
        {
            return Angle(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Angle operator*(const un_scalar_t scalar) const noexcept
        {
            return Angle(base_value() * scalar);
        }

        [[nodiscard]] constexpr Angle operator/(const un_scalar_t scalar) const noexcept
        {
            return Angle(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Angle& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Angle& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Angle& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t radians() const
        {
            return convert_from_base(AngleUnit::Radian);
        }

        [[nodiscard]] static constexpr Angle from_radians(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Radian);
        }

        [[nodiscard]] constexpr un_scalar_t nanoradians() const
        {
            return convert_from_base(AngleUnit::Nanoradian);
        }

        [[nodiscard]] static constexpr Angle from_nanoradians(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Nanoradian);
        }

        [[nodiscard]] constexpr un_scalar_t microradians() const
        {
            return convert_from_base(AngleUnit::Microradian);
        }

        [[nodiscard]] static constexpr Angle from_microradians(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Microradian);
        }

        [[nodiscard]] constexpr un_scalar_t milliradians() const
        {
            return convert_from_base(AngleUnit::Milliradian);
        }

        [[nodiscard]] static constexpr Angle from_milliradians(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Milliradian);
        }

        [[nodiscard]] constexpr un_scalar_t centiradians() const
        {
            return convert_from_base(AngleUnit::Centiradian);
        }

        [[nodiscard]] static constexpr Angle from_centiradians(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Centiradian);
        }

        [[nodiscard]] constexpr un_scalar_t deciradians() const
        {
            return convert_from_base(AngleUnit::Deciradian);
        }

        [[nodiscard]] static constexpr Angle from_deciradians(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Deciradian);
        }

        [[nodiscard]] constexpr un_scalar_t degrees() const
        {
            return convert_from_base(AngleUnit::Degree);
        }

        [[nodiscard]] static constexpr Angle from_degrees(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Degree);
        }

        [[nodiscard]] constexpr un_scalar_t nanodegrees() const
        {
            return convert_from_base(AngleUnit::Nanodegree);
        }

        [[nodiscard]] static constexpr Angle from_nanodegrees(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Nanodegree);
        }

        [[nodiscard]] constexpr un_scalar_t microdegrees() const
        {
            return convert_from_base(AngleUnit::Microdegree);
        }

        [[nodiscard]] static constexpr Angle from_microdegrees(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Microdegree);
        }

        [[nodiscard]] constexpr un_scalar_t millidegrees() const
        {
            return convert_from_base(AngleUnit::Millidegree);
        }

        [[nodiscard]] static constexpr Angle from_millidegrees(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Millidegree);
        }

        [[nodiscard]] constexpr un_scalar_t arcminutes() const
        {
            return convert_from_base(AngleUnit::Arcminute);
        }

        [[nodiscard]] static constexpr Angle from_arcminutes(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Arcminute);
        }

        [[nodiscard]] constexpr un_scalar_t arcseconds() const
        {
            return convert_from_base(AngleUnit::Arcsecond);
        }

        [[nodiscard]] static constexpr Angle from_arcseconds(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Arcsecond);
        }

        [[nodiscard]] constexpr un_scalar_t gradians() const
        {
            return convert_from_base(AngleUnit::Gradian);
        }

        [[nodiscard]] static constexpr Angle from_gradians(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Gradian);
        }

        [[nodiscard]] constexpr un_scalar_t nato_mils() const
        {
            return convert_from_base(AngleUnit::NatoMil);
        }

        [[nodiscard]] static constexpr Angle from_nato_mils(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::NatoMil);
        }

        [[nodiscard]] constexpr un_scalar_t revolutions() const
        {
            return convert_from_base(AngleUnit::Revolution);
        }

        [[nodiscard]] static constexpr Angle from_revolutions(const un_scalar_t value)
        {
            return Angle(value, AngleUnit::Revolution);
        }

        [[nodiscard]] static constexpr Angle from_invalid()
        {
            return Angle(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, AngleUnit unit)
        {
            switch (unit)
            {

            case AngleUnit::Radian:
                return value;

            case AngleUnit::Nanoradian:
                return (value * static_cast<un_scalar_t>(1e-9));

            case AngleUnit::Microradian:
                return (value * static_cast<un_scalar_t>(1e-6));

            case AngleUnit::Milliradian:
                return (value * static_cast<un_scalar_t>(1e-3));

            case AngleUnit::Centiradian:
                return (value * static_cast<un_scalar_t>(1e-2));

            case AngleUnit::Deciradian:
                return (value * static_cast<un_scalar_t>(1e-1));

            case AngleUnit::Degree:
                return value * std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(180);

            case AngleUnit::Nanodegree:
                return (value * static_cast<un_scalar_t>(1e-9)) * std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(180);

            case AngleUnit::Microdegree:
                return (value * static_cast<un_scalar_t>(1e-6)) * std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(180);

            case AngleUnit::Millidegree:
                return (value * static_cast<un_scalar_t>(1e-3)) * std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(180);

            case AngleUnit::Arcminute:
                return value * std::numbers::pi_v<un_scalar_t> / (static_cast<un_scalar_t>(60) * static_cast<un_scalar_t>(180));

            case AngleUnit::Arcsecond:
                return value * std::numbers::pi_v<un_scalar_t> / (static_cast<un_scalar_t>(3600) * static_cast<un_scalar_t>(180));

            case AngleUnit::Gradian:
                return value * std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(200);

            case AngleUnit::NatoMil:
                return value * std::numbers::pi_v<un_scalar_t> / static_cast<un_scalar_t>(3200);

            case AngleUnit::Revolution:
                return value * static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>;

            }

            throw std::invalid_argument("Unknown Angle unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const AngleUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case AngleUnit::Radian:
                return base_value;

            case AngleUnit::Nanoradian:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case AngleUnit::Microradian:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case AngleUnit::Milliradian:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case AngleUnit::Centiradian:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case AngleUnit::Deciradian:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case AngleUnit::Degree:
                return base_value * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>;

            case AngleUnit::Nanodegree:
                return (base_value * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>) / static_cast<un_scalar_t>(1e-9);

            case AngleUnit::Microdegree:
                return (base_value * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>) / static_cast<un_scalar_t>(1e-6);

            case AngleUnit::Millidegree:
                return (base_value * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>) / static_cast<un_scalar_t>(1e-3);

            case AngleUnit::Arcminute:
                return base_value * static_cast<un_scalar_t>(60) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>;

            case AngleUnit::Arcsecond:
                return base_value * static_cast<un_scalar_t>(3600) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>;

            case AngleUnit::Gradian:
                return base_value * static_cast<un_scalar_t>(200) / std::numbers::pi_v<un_scalar_t>;

            case AngleUnit::NatoMil:
                return base_value * static_cast<un_scalar_t>(3200) / std::numbers::pi_v<un_scalar_t>;

            case AngleUnit::Revolution:
                return base_value / (static_cast<un_scalar_t>(2) * std::numbers::pi_v<un_scalar_t>);

            }

            throw std::invalid_argument("Unknown Angle unit.");
        }

        un_scalar_t value_;
        AngleUnit value_unit_type_;       
    };
}
