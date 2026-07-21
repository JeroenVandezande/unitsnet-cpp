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
    enum class LuminosityUnit : std::uint8_t
    {
        Watt,
        Femtowatt,
        Picowatt,
        Nanowatt,
        Microwatt,
        Milliwatt,
        Deciwatt,
        Decawatt,
        Kilowatt,
        Megawatt,
        Gigawatt,
        Terawatt,
        Petawatt,
        SolarLuminosity,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Luminosity.</summary>
    class LuminosityDto
    {
    public:
        constexpr LuminosityDto() noexcept
            : value{}, unit(LuminosityUnit::Watt)
        {
        }

        constexpr LuminosityDto(
            const un_scalar_t value,
            const LuminosityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        LuminosityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr LuminosityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<LuminosityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Luminosity unit name.");
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
        [[nodiscard]] static LuminosityDto from_json(const nlohmann::json& json)
        {
            return LuminosityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Luminosity is an absolute measure of radiated electromagnetic power (light), the radiant power emitted by a light-emitting object.</summary>
    class Luminosity : public UnitsNetBase
    {
    public:
        constexpr explicit Luminosity(
            const un_scalar_t value,
            const LuminosityUnit unit = LuminosityUnit::Watt)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const LuminosityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr LuminosityDto to_dto(
            const LuminosityUnit unit = LuminosityUnit::Watt) const
        {
            return LuminosityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Luminosity from_dto(const LuminosityDto& dto)
        {
            return Luminosity(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const LuminosityUnit unit = LuminosityUnit::Watt) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Luminosity from_json(const nlohmann::json& json)
        {
            return from_dto(LuminosityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Luminosity operator+(const Luminosity& other) const noexcept
        {
            return Luminosity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Luminosity operator-(const Luminosity& other)const noexcept
        {
            return Luminosity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Luminosity operator*(const un_scalar_t scalar) const noexcept
        {
            return Luminosity(base_value() * scalar);
        }

        [[nodiscard]] constexpr Luminosity operator/(const un_scalar_t scalar) const noexcept
        {
            return Luminosity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Luminosity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Luminosity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Luminosity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t watts() const
        {
            return convert_from_base(LuminosityUnit::Watt);
        }

        [[nodiscard]] static constexpr Luminosity from_watts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Watt);
        }

        [[nodiscard]] constexpr un_scalar_t femtowatts() const
        {
            return convert_from_base(LuminosityUnit::Femtowatt);
        }

        [[nodiscard]] static constexpr Luminosity from_femtowatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Femtowatt);
        }

        [[nodiscard]] constexpr un_scalar_t picowatts() const
        {
            return convert_from_base(LuminosityUnit::Picowatt);
        }

        [[nodiscard]] static constexpr Luminosity from_picowatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Picowatt);
        }

        [[nodiscard]] constexpr un_scalar_t nanowatts() const
        {
            return convert_from_base(LuminosityUnit::Nanowatt);
        }

        [[nodiscard]] static constexpr Luminosity from_nanowatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Nanowatt);
        }

        [[nodiscard]] constexpr un_scalar_t microwatts() const
        {
            return convert_from_base(LuminosityUnit::Microwatt);
        }

        [[nodiscard]] static constexpr Luminosity from_microwatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Microwatt);
        }

        [[nodiscard]] constexpr un_scalar_t milliwatts() const
        {
            return convert_from_base(LuminosityUnit::Milliwatt);
        }

        [[nodiscard]] static constexpr Luminosity from_milliwatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Milliwatt);
        }

        [[nodiscard]] constexpr un_scalar_t deciwatts() const
        {
            return convert_from_base(LuminosityUnit::Deciwatt);
        }

        [[nodiscard]] static constexpr Luminosity from_deciwatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Deciwatt);
        }

        [[nodiscard]] constexpr un_scalar_t decawatts() const
        {
            return convert_from_base(LuminosityUnit::Decawatt);
        }

        [[nodiscard]] static constexpr Luminosity from_decawatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Decawatt);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatts() const
        {
            return convert_from_base(LuminosityUnit::Kilowatt);
        }

        [[nodiscard]] static constexpr Luminosity from_kilowatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Kilowatt);
        }

        [[nodiscard]] constexpr un_scalar_t megawatts() const
        {
            return convert_from_base(LuminosityUnit::Megawatt);
        }

        [[nodiscard]] static constexpr Luminosity from_megawatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Megawatt);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatts() const
        {
            return convert_from_base(LuminosityUnit::Gigawatt);
        }

        [[nodiscard]] static constexpr Luminosity from_gigawatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Gigawatt);
        }

        [[nodiscard]] constexpr un_scalar_t terawatts() const
        {
            return convert_from_base(LuminosityUnit::Terawatt);
        }

        [[nodiscard]] static constexpr Luminosity from_terawatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Terawatt);
        }

        [[nodiscard]] constexpr un_scalar_t petawatts() const
        {
            return convert_from_base(LuminosityUnit::Petawatt);
        }

        [[nodiscard]] static constexpr Luminosity from_petawatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Petawatt);
        }

        /// <summary>The IAU has defined a nominal solar luminosity of 3.828×10^26 W to promote publication of consistent and comparable values in units of the solar luminosity.</summary>
        [[nodiscard]] constexpr un_scalar_t solar_luminosities() const
        {
            return convert_from_base(LuminosityUnit::SolarLuminosity);
        }

        /// <summary>The IAU has defined a nominal solar luminosity of 3.828×10^26 W to promote publication of consistent and comparable values in units of the solar luminosity.</summary>
        [[nodiscard]] static constexpr Luminosity from_solar_luminosities(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::SolarLuminosity);
        }

        [[nodiscard]] static constexpr Luminosity from_invalid()
        {
            return Luminosity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, LuminosityUnit unit)
        {
            switch (unit)
            {

            case LuminosityUnit::Watt:
                return value;

            case LuminosityUnit::Femtowatt:
                return (value * static_cast<un_scalar_t>(1e-15));

            case LuminosityUnit::Picowatt:
                return (value * static_cast<un_scalar_t>(1e-12));

            case LuminosityUnit::Nanowatt:
                return (value * static_cast<un_scalar_t>(1e-9));

            case LuminosityUnit::Microwatt:
                return (value * static_cast<un_scalar_t>(1e-6));

            case LuminosityUnit::Milliwatt:
                return (value * static_cast<un_scalar_t>(1e-3));

            case LuminosityUnit::Deciwatt:
                return (value * static_cast<un_scalar_t>(1e-1));

            case LuminosityUnit::Decawatt:
                return (value * static_cast<un_scalar_t>(1e1));

            case LuminosityUnit::Kilowatt:
                return (value * static_cast<un_scalar_t>(1e3));

            case LuminosityUnit::Megawatt:
                return (value * static_cast<un_scalar_t>(1e6));

            case LuminosityUnit::Gigawatt:
                return (value * static_cast<un_scalar_t>(1e9));

            case LuminosityUnit::Terawatt:
                return (value * static_cast<un_scalar_t>(1e12));

            case LuminosityUnit::Petawatt:
                return (value * static_cast<un_scalar_t>(1e15));

            case LuminosityUnit::SolarLuminosity:
                return value * static_cast<un_scalar_t>(3.828e26);

            }

            throw std::invalid_argument("Unknown Luminosity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const LuminosityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case LuminosityUnit::Watt:
                return base_value;

            case LuminosityUnit::Femtowatt:
                return (base_value) / static_cast<un_scalar_t>(1e-15);

            case LuminosityUnit::Picowatt:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case LuminosityUnit::Nanowatt:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case LuminosityUnit::Microwatt:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case LuminosityUnit::Milliwatt:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case LuminosityUnit::Deciwatt:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case LuminosityUnit::Decawatt:
                return (base_value) / static_cast<un_scalar_t>(1e1);

            case LuminosityUnit::Kilowatt:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case LuminosityUnit::Megawatt:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case LuminosityUnit::Gigawatt:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case LuminosityUnit::Terawatt:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            case LuminosityUnit::Petawatt:
                return (base_value) / static_cast<un_scalar_t>(1e15);

            case LuminosityUnit::SolarLuminosity:
                return base_value / static_cast<un_scalar_t>(3.828e26);

            }

            throw std::invalid_argument("Unknown Luminosity unit.");
        }

        un_scalar_t value_;
        LuminosityUnit value_unit_type_;       
    };
}
