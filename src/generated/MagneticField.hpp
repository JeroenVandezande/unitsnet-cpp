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
    enum class MagneticFieldUnit : std::uint8_t
    {
        Tesla,
        Nanotesla,
        Microtesla,
        Millitesla,
        Gauss,
        Milligauss,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of MagneticField.</summary>
    class MagneticFieldDto
    {
    public:
        constexpr MagneticFieldDto() noexcept
            : value{}, unit(MagneticFieldUnit::Tesla)
        {
        }

        constexpr MagneticFieldDto(
            const un_scalar_t value,
            const MagneticFieldUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        MagneticFieldUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr MagneticFieldUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<MagneticFieldUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown MagneticField unit name.");
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
        [[nodiscard]] static MagneticFieldDto from_json(const nlohmann::json& json)
        {
            return MagneticFieldDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>A magnetic field is a force field that is created by moving electric charges (electric currents) and magnetic dipoles, and exerts a force on other nearby moving charges and magnetic dipoles.</summary>
    class MagneticField : public UnitsNetBase
    {
    public:
        constexpr explicit MagneticField(
            const un_scalar_t value,
            const MagneticFieldUnit unit = MagneticFieldUnit::Tesla)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MagneticFieldUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr MagneticFieldDto to_dto(
            const MagneticFieldUnit unit = MagneticFieldUnit::Tesla) const
        {
            return MagneticFieldDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr MagneticField from_dto(const MagneticFieldDto& dto)
        {
            return MagneticField(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const MagneticFieldUnit unit = MagneticFieldUnit::Tesla) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static MagneticField from_json(const nlohmann::json& json)
        {
            return from_dto(MagneticFieldDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr MagneticField operator+(const MagneticField& other) const noexcept
        {
            return MagneticField(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr MagneticField operator-(const MagneticField& other)const noexcept
        {
            return MagneticField(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr MagneticField operator*(const un_scalar_t scalar) const noexcept
        {
            return MagneticField(base_value() * scalar);
        }

        [[nodiscard]] constexpr MagneticField operator/(const un_scalar_t scalar) const noexcept
        {
            return MagneticField(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MagneticField& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const MagneticField& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const MagneticField& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t teslas() const
        {
            return convert_from_base(MagneticFieldUnit::Tesla);
        }

        [[nodiscard]] static constexpr MagneticField from_teslas(const un_scalar_t value)
        {
            return MagneticField(value, MagneticFieldUnit::Tesla);
        }

        [[nodiscard]] constexpr un_scalar_t nanoteslas() const
        {
            return convert_from_base(MagneticFieldUnit::Nanotesla);
        }

        [[nodiscard]] static constexpr MagneticField from_nanoteslas(const un_scalar_t value)
        {
            return MagneticField(value, MagneticFieldUnit::Nanotesla);
        }

        [[nodiscard]] constexpr un_scalar_t microteslas() const
        {
            return convert_from_base(MagneticFieldUnit::Microtesla);
        }

        [[nodiscard]] static constexpr MagneticField from_microteslas(const un_scalar_t value)
        {
            return MagneticField(value, MagneticFieldUnit::Microtesla);
        }

        [[nodiscard]] constexpr un_scalar_t milliteslas() const
        {
            return convert_from_base(MagneticFieldUnit::Millitesla);
        }

        [[nodiscard]] static constexpr MagneticField from_milliteslas(const un_scalar_t value)
        {
            return MagneticField(value, MagneticFieldUnit::Millitesla);
        }

        [[nodiscard]] constexpr un_scalar_t gausses() const
        {
            return convert_from_base(MagneticFieldUnit::Gauss);
        }

        [[nodiscard]] static constexpr MagneticField from_gausses(const un_scalar_t value)
        {
            return MagneticField(value, MagneticFieldUnit::Gauss);
        }

        [[nodiscard]] constexpr un_scalar_t milligausses() const
        {
            return convert_from_base(MagneticFieldUnit::Milligauss);
        }

        [[nodiscard]] static constexpr MagneticField from_milligausses(const un_scalar_t value)
        {
            return MagneticField(value, MagneticFieldUnit::Milligauss);
        }

        [[nodiscard]] static constexpr MagneticField from_invalid()
        {
            return MagneticField(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MagneticFieldUnit unit)
        {
            switch (unit)
            {

            case MagneticFieldUnit::Tesla:
                return value;

            case MagneticFieldUnit::Nanotesla:
                return (value * static_cast<un_scalar_t>(1e-9));

            case MagneticFieldUnit::Microtesla:
                return (value * static_cast<un_scalar_t>(1e-6));

            case MagneticFieldUnit::Millitesla:
                return (value * static_cast<un_scalar_t>(1e-3));

            case MagneticFieldUnit::Gauss:
                return value / static_cast<un_scalar_t>(1e4);

            case MagneticFieldUnit::Milligauss:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e4);

            }

            throw std::invalid_argument("Unknown MagneticField unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MagneticFieldUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case MagneticFieldUnit::Tesla:
                return base_value;

            case MagneticFieldUnit::Nanotesla:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case MagneticFieldUnit::Microtesla:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case MagneticFieldUnit::Millitesla:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case MagneticFieldUnit::Gauss:
                return base_value * static_cast<un_scalar_t>(1e4);

            case MagneticFieldUnit::Milligauss:
                return (base_value * static_cast<un_scalar_t>(1e4)) / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown MagneticField unit.");
        }

        un_scalar_t value_;
        MagneticFieldUnit value_unit_type_;       
    };
}
