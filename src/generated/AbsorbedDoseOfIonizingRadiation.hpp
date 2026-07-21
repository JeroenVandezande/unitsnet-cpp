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
    enum class AbsorbedDoseOfIonizingRadiationUnit : std::uint8_t
    {
        Gray,
        Femtogray,
        Picogray,
        Nanogray,
        Microgray,
        Milligray,
        Centigray,
        Decigray,
        Kilogray,
        Megagray,
        Gigagray,
        Teragray,
        Petagray,
        Rad,
        Millirad,
        Kilorad,
        Megarad,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of AbsorbedDoseOfIonizingRadiation.</summary>
    class AbsorbedDoseOfIonizingRadiationDto
    {
    public:
        constexpr AbsorbedDoseOfIonizingRadiationDto() noexcept
            : value{}, unit(AbsorbedDoseOfIonizingRadiationUnit::Gray)
        {
        }

        constexpr AbsorbedDoseOfIonizingRadiationDto(
            const un_scalar_t value,
            const AbsorbedDoseOfIonizingRadiationUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        AbsorbedDoseOfIonizingRadiationUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiationUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<AbsorbedDoseOfIonizingRadiationUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown AbsorbedDoseOfIonizingRadiation unit name.");
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
        [[nodiscard]] static AbsorbedDoseOfIonizingRadiationDto from_json(const nlohmann::json& json)
        {
            return AbsorbedDoseOfIonizingRadiationDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Absorbed dose is a dose quantity which is the measure of the energy deposited in matter by ionizing radiation per unit mass.</summary>
    class AbsorbedDoseOfIonizingRadiation : public UnitsNetBase
    {
    public:
        constexpr explicit AbsorbedDoseOfIonizingRadiation(
            const un_scalar_t value,
            const AbsorbedDoseOfIonizingRadiationUnit unit = AbsorbedDoseOfIonizingRadiationUnit::Gray)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const AbsorbedDoseOfIonizingRadiationUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr AbsorbedDoseOfIonizingRadiationDto to_dto(
            const AbsorbedDoseOfIonizingRadiationUnit unit = AbsorbedDoseOfIonizingRadiationUnit::Gray) const
        {
            return AbsorbedDoseOfIonizingRadiationDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_dto(const AbsorbedDoseOfIonizingRadiationDto& dto)
        {
            return AbsorbedDoseOfIonizingRadiation(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const AbsorbedDoseOfIonizingRadiationUnit unit = AbsorbedDoseOfIonizingRadiationUnit::Gray) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static AbsorbedDoseOfIonizingRadiation from_json(const nlohmann::json& json)
        {
            return from_dto(AbsorbedDoseOfIonizingRadiationDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr AbsorbedDoseOfIonizingRadiation operator+(const AbsorbedDoseOfIonizingRadiation& other) const noexcept
        {
            return AbsorbedDoseOfIonizingRadiation(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr AbsorbedDoseOfIonizingRadiation operator-(const AbsorbedDoseOfIonizingRadiation& other)const noexcept
        {
            return AbsorbedDoseOfIonizingRadiation(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr AbsorbedDoseOfIonizingRadiation operator*(const un_scalar_t scalar) const noexcept
        {
            return AbsorbedDoseOfIonizingRadiation(base_value() * scalar);
        }

        [[nodiscard]] constexpr AbsorbedDoseOfIonizingRadiation operator/(const un_scalar_t scalar) const noexcept
        {
            return AbsorbedDoseOfIonizingRadiation(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const AbsorbedDoseOfIonizingRadiation& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const AbsorbedDoseOfIonizingRadiation& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const AbsorbedDoseOfIonizingRadiation& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t grays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Gray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_grays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Gray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t femtograys() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Femtogray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_femtograys(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Femtogray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t picograys() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Picogray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_picograys(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Picogray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t nanograys() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Nanogray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_nanograys(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Nanogray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t micrograys() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Microgray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_micrograys(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Microgray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t milligrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Milligray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_milligrays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Milligray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t centigrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Centigray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_centigrays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Centigray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t decigrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Decigray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_decigrays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Decigray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t kilograys() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Kilogray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_kilograys(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Kilogray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t megagrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Megagray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_megagrays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Megagray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t gigagrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Gigagray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_gigagrays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Gigagray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t teragrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Teragray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_teragrays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Teragray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t petagrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Petagray);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_petagrays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Petagray);
        }

        /// <summary>The rad is a unit of absorbed radiation dose, defined as 1 rad = 0.01 Gy = 0.01 J/kg.</summary>
        [[nodiscard]] constexpr un_scalar_t rads() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Rad);
        }

        /// <summary>The rad is a unit of absorbed radiation dose, defined as 1 rad = 0.01 Gy = 0.01 J/kg.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_rads(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Rad);
        }

        /// <summary>The rad is a unit of absorbed radiation dose, defined as 1 rad = 0.01 Gy = 0.01 J/kg.</summary>
        [[nodiscard]] constexpr un_scalar_t millirads() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Millirad);
        }

        /// <summary>The rad is a unit of absorbed radiation dose, defined as 1 rad = 0.01 Gy = 0.01 J/kg.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_millirads(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Millirad);
        }

        /// <summary>The rad is a unit of absorbed radiation dose, defined as 1 rad = 0.01 Gy = 0.01 J/kg.</summary>
        [[nodiscard]] constexpr un_scalar_t kilorads() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Kilorad);
        }

        /// <summary>The rad is a unit of absorbed radiation dose, defined as 1 rad = 0.01 Gy = 0.01 J/kg.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_kilorads(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Kilorad);
        }

        /// <summary>The rad is a unit of absorbed radiation dose, defined as 1 rad = 0.01 Gy = 0.01 J/kg.</summary>
        [[nodiscard]] constexpr un_scalar_t megarads() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Megarad);
        }

        /// <summary>The rad is a unit of absorbed radiation dose, defined as 1 rad = 0.01 Gy = 0.01 J/kg.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_megarads(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Megarad);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_invalid()
        {
            return AbsorbedDoseOfIonizingRadiation(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, AbsorbedDoseOfIonizingRadiationUnit unit)
        {
            switch (unit)
            {

            case AbsorbedDoseOfIonizingRadiationUnit::Gray:
                return value;

            case AbsorbedDoseOfIonizingRadiationUnit::Femtogray:
                return (value * static_cast<un_scalar_t>(1e-15));

            case AbsorbedDoseOfIonizingRadiationUnit::Picogray:
                return (value * static_cast<un_scalar_t>(1e-12));

            case AbsorbedDoseOfIonizingRadiationUnit::Nanogray:
                return (value * static_cast<un_scalar_t>(1e-9));

            case AbsorbedDoseOfIonizingRadiationUnit::Microgray:
                return (value * static_cast<un_scalar_t>(1e-6));

            case AbsorbedDoseOfIonizingRadiationUnit::Milligray:
                return (value * static_cast<un_scalar_t>(1e-3));

            case AbsorbedDoseOfIonizingRadiationUnit::Centigray:
                return (value * static_cast<un_scalar_t>(1e-2));

            case AbsorbedDoseOfIonizingRadiationUnit::Decigray:
                return (value * static_cast<un_scalar_t>(1e-1));

            case AbsorbedDoseOfIonizingRadiationUnit::Kilogray:
                return (value * static_cast<un_scalar_t>(1e3));

            case AbsorbedDoseOfIonizingRadiationUnit::Megagray:
                return (value * static_cast<un_scalar_t>(1e6));

            case AbsorbedDoseOfIonizingRadiationUnit::Gigagray:
                return (value * static_cast<un_scalar_t>(1e9));

            case AbsorbedDoseOfIonizingRadiationUnit::Teragray:
                return (value * static_cast<un_scalar_t>(1e12));

            case AbsorbedDoseOfIonizingRadiationUnit::Petagray:
                return (value * static_cast<un_scalar_t>(1e15));

            case AbsorbedDoseOfIonizingRadiationUnit::Rad:
                return value / static_cast<un_scalar_t>(100);

            case AbsorbedDoseOfIonizingRadiationUnit::Millirad:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(100);

            case AbsorbedDoseOfIonizingRadiationUnit::Kilorad:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(100);

            case AbsorbedDoseOfIonizingRadiationUnit::Megarad:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(100);

            }

            throw std::invalid_argument("Unknown AbsorbedDoseOfIonizingRadiation unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const AbsorbedDoseOfIonizingRadiationUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case AbsorbedDoseOfIonizingRadiationUnit::Gray:
                return base_value;

            case AbsorbedDoseOfIonizingRadiationUnit::Femtogray:
                return (base_value) / static_cast<un_scalar_t>(1e-15);

            case AbsorbedDoseOfIonizingRadiationUnit::Picogray:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case AbsorbedDoseOfIonizingRadiationUnit::Nanogray:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case AbsorbedDoseOfIonizingRadiationUnit::Microgray:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case AbsorbedDoseOfIonizingRadiationUnit::Milligray:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case AbsorbedDoseOfIonizingRadiationUnit::Centigray:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case AbsorbedDoseOfIonizingRadiationUnit::Decigray:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case AbsorbedDoseOfIonizingRadiationUnit::Kilogray:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case AbsorbedDoseOfIonizingRadiationUnit::Megagray:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case AbsorbedDoseOfIonizingRadiationUnit::Gigagray:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case AbsorbedDoseOfIonizingRadiationUnit::Teragray:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            case AbsorbedDoseOfIonizingRadiationUnit::Petagray:
                return (base_value) / static_cast<un_scalar_t>(1e15);

            case AbsorbedDoseOfIonizingRadiationUnit::Rad:
                return base_value * static_cast<un_scalar_t>(100);

            case AbsorbedDoseOfIonizingRadiationUnit::Millirad:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-3);

            case AbsorbedDoseOfIonizingRadiationUnit::Kilorad:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e3);

            case AbsorbedDoseOfIonizingRadiationUnit::Megarad:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown AbsorbedDoseOfIonizingRadiation unit.");
        }

        un_scalar_t value_;
        AbsorbedDoseOfIonizingRadiationUnit value_unit_type_;       
    };
}
