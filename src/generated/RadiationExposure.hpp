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
    enum class RadiationExposureUnit : std::uint8_t
    {
        CoulombPerKilogram,
        PicocoulombPerKilogram,
        NanocoulombPerKilogram,
        MicrocoulombPerKilogram,
        MillicoulombPerKilogram,
        Roentgen,
        Microroentgen,
        Milliroentgen,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of RadiationExposure.</summary>
    class RadiationExposureDto
    {
    public:
        constexpr RadiationExposureDto() noexcept
            : value{}, unit(RadiationExposureUnit::CoulombPerKilogram)
        {
        }

        constexpr RadiationExposureDto(
            const un_scalar_t value,
            const RadiationExposureUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        RadiationExposureUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr RadiationExposureUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<RadiationExposureUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown RadiationExposure unit name.");
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
        [[nodiscard]] static RadiationExposureDto from_json(const nlohmann::json& json)
        {
            return RadiationExposureDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Radiation exposure is a measure of the ionization of air due to ionizing radiation from photons.</summary>
    class RadiationExposure : public UnitsNetBase
    {
    public:
        constexpr explicit RadiationExposure(
            const un_scalar_t value,
            const RadiationExposureUnit unit = RadiationExposureUnit::CoulombPerKilogram)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const RadiationExposureUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr RadiationExposureDto to_dto(
            const RadiationExposureUnit unit = RadiationExposureUnit::CoulombPerKilogram) const
        {
            return RadiationExposureDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr RadiationExposure from_dto(const RadiationExposureDto& dto)
        {
            return RadiationExposure(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const RadiationExposureUnit unit = RadiationExposureUnit::CoulombPerKilogram) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static RadiationExposure from_json(const nlohmann::json& json)
        {
            return from_dto(RadiationExposureDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr RadiationExposure operator+(const RadiationExposure& other) const noexcept
        {
            return RadiationExposure(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr RadiationExposure operator-(const RadiationExposure& other)const noexcept
        {
            return RadiationExposure(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr RadiationExposure operator*(const un_scalar_t scalar) const noexcept
        {
            return RadiationExposure(base_value() * scalar);
        }

        [[nodiscard]] constexpr RadiationExposure operator/(const un_scalar_t scalar) const noexcept
        {
            return RadiationExposure(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RadiationExposure& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const RadiationExposure& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const RadiationExposure& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t coulombs_per_kilogram() const
        {
            return convert_from_base(RadiationExposureUnit::CoulombPerKilogram);
        }

        [[nodiscard]] static constexpr RadiationExposure from_coulombs_per_kilogram(const un_scalar_t value)
        {
            return RadiationExposure(value, RadiationExposureUnit::CoulombPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t picocoulombs_per_kilogram() const
        {
            return convert_from_base(RadiationExposureUnit::PicocoulombPerKilogram);
        }

        [[nodiscard]] static constexpr RadiationExposure from_picocoulombs_per_kilogram(const un_scalar_t value)
        {
            return RadiationExposure(value, RadiationExposureUnit::PicocoulombPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t nanocoulombs_per_kilogram() const
        {
            return convert_from_base(RadiationExposureUnit::NanocoulombPerKilogram);
        }

        [[nodiscard]] static constexpr RadiationExposure from_nanocoulombs_per_kilogram(const un_scalar_t value)
        {
            return RadiationExposure(value, RadiationExposureUnit::NanocoulombPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t microcoulombs_per_kilogram() const
        {
            return convert_from_base(RadiationExposureUnit::MicrocoulombPerKilogram);
        }

        [[nodiscard]] static constexpr RadiationExposure from_microcoulombs_per_kilogram(const un_scalar_t value)
        {
            return RadiationExposure(value, RadiationExposureUnit::MicrocoulombPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t millicoulombs_per_kilogram() const
        {
            return convert_from_base(RadiationExposureUnit::MillicoulombPerKilogram);
        }

        [[nodiscard]] static constexpr RadiationExposure from_millicoulombs_per_kilogram(const un_scalar_t value)
        {
            return RadiationExposure(value, RadiationExposureUnit::MillicoulombPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t roentgens() const
        {
            return convert_from_base(RadiationExposureUnit::Roentgen);
        }

        [[nodiscard]] static constexpr RadiationExposure from_roentgens(const un_scalar_t value)
        {
            return RadiationExposure(value, RadiationExposureUnit::Roentgen);
        }

        [[nodiscard]] constexpr un_scalar_t microroentgens() const
        {
            return convert_from_base(RadiationExposureUnit::Microroentgen);
        }

        [[nodiscard]] static constexpr RadiationExposure from_microroentgens(const un_scalar_t value)
        {
            return RadiationExposure(value, RadiationExposureUnit::Microroentgen);
        }

        [[nodiscard]] constexpr un_scalar_t milliroentgens() const
        {
            return convert_from_base(RadiationExposureUnit::Milliroentgen);
        }

        [[nodiscard]] static constexpr RadiationExposure from_milliroentgens(const un_scalar_t value)
        {
            return RadiationExposure(value, RadiationExposureUnit::Milliroentgen);
        }

        [[nodiscard]] static constexpr RadiationExposure from_invalid()
        {
            return RadiationExposure(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RadiationExposureUnit unit)
        {
            switch (unit)
            {

            case RadiationExposureUnit::CoulombPerKilogram:
                return value;

            case RadiationExposureUnit::PicocoulombPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-12));

            case RadiationExposureUnit::NanocoulombPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-9));

            case RadiationExposureUnit::MicrocoulombPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-6));

            case RadiationExposureUnit::MillicoulombPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-3));

            case RadiationExposureUnit::Roentgen:
                return value * static_cast<un_scalar_t>(2.58e-4);

            case RadiationExposureUnit::Microroentgen:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(2.58e-4);

            case RadiationExposureUnit::Milliroentgen:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(2.58e-4);

            }

            throw std::invalid_argument("Unknown RadiationExposure unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RadiationExposureUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case RadiationExposureUnit::CoulombPerKilogram:
                return base_value;

            case RadiationExposureUnit::PicocoulombPerKilogram:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case RadiationExposureUnit::NanocoulombPerKilogram:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case RadiationExposureUnit::MicrocoulombPerKilogram:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case RadiationExposureUnit::MillicoulombPerKilogram:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case RadiationExposureUnit::Roentgen:
                return base_value / static_cast<un_scalar_t>(2.58e-4);

            case RadiationExposureUnit::Microroentgen:
                return (base_value / static_cast<un_scalar_t>(2.58e-4)) / static_cast<un_scalar_t>(1e-6);

            case RadiationExposureUnit::Milliroentgen:
                return (base_value / static_cast<un_scalar_t>(2.58e-4)) / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown RadiationExposure unit.");
        }

        un_scalar_t value_;
        RadiationExposureUnit value_unit_type_;       
    };
}
