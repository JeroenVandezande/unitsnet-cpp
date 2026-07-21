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
    enum class RadioactivityUnit : std::uint8_t
    {
        Becquerel,
        Picobecquerel,
        Nanobecquerel,
        Microbecquerel,
        Millibecquerel,
        Kilobecquerel,
        Megabecquerel,
        Gigabecquerel,
        Terabecquerel,
        Petabecquerel,
        Exabecquerel,
        Curie,
        Picocurie,
        Nanocurie,
        Microcurie,
        Millicurie,
        Kilocurie,
        Megacurie,
        Gigacurie,
        Teracurie,
        Rutherford,
        Picorutherford,
        Nanorutherford,
        Microrutherford,
        Millirutherford,
        Kilorutherford,
        Megarutherford,
        Gigarutherford,
        Terarutherford,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Radioactivity.</summary>
    class RadioactivityDto
    {
    public:
        constexpr RadioactivityDto() noexcept
            : value{}, unit(RadioactivityUnit::Becquerel)
        {
        }

        constexpr RadioactivityDto(
            const un_scalar_t value,
            const RadioactivityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        RadioactivityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr RadioactivityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<RadioactivityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Radioactivity unit name.");
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
        [[nodiscard]] static RadioactivityDto from_json(const nlohmann::json& json)
        {
            return RadioactivityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Amount of ionizing radiation released when an element spontaneously emits energy as a result of the radioactive decay of an unstable atom per unit time.</summary>
    class Radioactivity : public UnitsNetBase
    {
    public:
        constexpr explicit Radioactivity(
            const un_scalar_t value,
            const RadioactivityUnit unit = RadioactivityUnit::Becquerel)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const RadioactivityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr RadioactivityDto to_dto(
            const RadioactivityUnit unit = RadioactivityUnit::Becquerel) const
        {
            return RadioactivityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Radioactivity from_dto(const RadioactivityDto& dto)
        {
            return Radioactivity(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const RadioactivityUnit unit = RadioactivityUnit::Becquerel) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Radioactivity from_json(const nlohmann::json& json)
        {
            return from_dto(RadioactivityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Radioactivity operator+(const Radioactivity& other) const noexcept
        {
            return Radioactivity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Radioactivity operator-(const Radioactivity& other)const noexcept
        {
            return Radioactivity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Radioactivity operator*(const un_scalar_t scalar) const noexcept
        {
            return Radioactivity(base_value() * scalar);
        }

        [[nodiscard]] constexpr Radioactivity operator/(const un_scalar_t scalar) const noexcept
        {
            return Radioactivity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Radioactivity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Radioactivity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Radioactivity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t becquerels() const
        {
            return convert_from_base(RadioactivityUnit::Becquerel);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_becquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Becquerel);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t picobecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Picobecquerel);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_picobecquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Picobecquerel);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t nanobecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Nanobecquerel);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_nanobecquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Nanobecquerel);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t microbecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Microbecquerel);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_microbecquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Microbecquerel);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t millibecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Millibecquerel);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_millibecquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Millibecquerel);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t kilobecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Kilobecquerel);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_kilobecquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Kilobecquerel);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t megabecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Megabecquerel);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_megabecquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Megabecquerel);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t gigabecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Gigabecquerel);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_gigabecquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Gigabecquerel);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t terabecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Terabecquerel);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_terabecquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Terabecquerel);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t petabecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Petabecquerel);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_petabecquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Petabecquerel);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t exabecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Exabecquerel);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_exabecquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Exabecquerel);
        }

        [[nodiscard]] constexpr un_scalar_t curies() const
        {
            return convert_from_base(RadioactivityUnit::Curie);
        }

        [[nodiscard]] static constexpr Radioactivity from_curies(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Curie);
        }

        [[nodiscard]] constexpr un_scalar_t picocuries() const
        {
            return convert_from_base(RadioactivityUnit::Picocurie);
        }

        [[nodiscard]] static constexpr Radioactivity from_picocuries(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Picocurie);
        }

        [[nodiscard]] constexpr un_scalar_t nanocuries() const
        {
            return convert_from_base(RadioactivityUnit::Nanocurie);
        }

        [[nodiscard]] static constexpr Radioactivity from_nanocuries(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Nanocurie);
        }

        [[nodiscard]] constexpr un_scalar_t microcuries() const
        {
            return convert_from_base(RadioactivityUnit::Microcurie);
        }

        [[nodiscard]] static constexpr Radioactivity from_microcuries(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Microcurie);
        }

        [[nodiscard]] constexpr un_scalar_t millicuries() const
        {
            return convert_from_base(RadioactivityUnit::Millicurie);
        }

        [[nodiscard]] static constexpr Radioactivity from_millicuries(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Millicurie);
        }

        [[nodiscard]] constexpr un_scalar_t kilocuries() const
        {
            return convert_from_base(RadioactivityUnit::Kilocurie);
        }

        [[nodiscard]] static constexpr Radioactivity from_kilocuries(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Kilocurie);
        }

        [[nodiscard]] constexpr un_scalar_t megacuries() const
        {
            return convert_from_base(RadioactivityUnit::Megacurie);
        }

        [[nodiscard]] static constexpr Radioactivity from_megacuries(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Megacurie);
        }

        [[nodiscard]] constexpr un_scalar_t gigacuries() const
        {
            return convert_from_base(RadioactivityUnit::Gigacurie);
        }

        [[nodiscard]] static constexpr Radioactivity from_gigacuries(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Gigacurie);
        }

        [[nodiscard]] constexpr un_scalar_t teracuries() const
        {
            return convert_from_base(RadioactivityUnit::Teracurie);
        }

        [[nodiscard]] static constexpr Radioactivity from_teracuries(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Teracurie);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] constexpr un_scalar_t rutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Rutherford);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_rutherfords(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Rutherford);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] constexpr un_scalar_t picorutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Picorutherford);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_picorutherfords(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Picorutherford);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] constexpr un_scalar_t nanorutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Nanorutherford);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_nanorutherfords(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Nanorutherford);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] constexpr un_scalar_t microrutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Microrutherford);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_microrutherfords(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Microrutherford);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] constexpr un_scalar_t millirutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Millirutherford);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_millirutherfords(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Millirutherford);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] constexpr un_scalar_t kilorutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Kilorutherford);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_kilorutherfords(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Kilorutherford);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] constexpr un_scalar_t megarutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Megarutherford);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_megarutherfords(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Megarutherford);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] constexpr un_scalar_t gigarutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Gigarutherford);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_gigarutherfords(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Gigarutherford);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] constexpr un_scalar_t terarutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Terarutherford);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_terarutherfords(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Terarutherford);
        }

        [[nodiscard]] static constexpr Radioactivity from_invalid()
        {
            return Radioactivity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RadioactivityUnit unit)
        {
            switch (unit)
            {

            case RadioactivityUnit::Becquerel:
                return value;

            case RadioactivityUnit::Picobecquerel:
                return (value * static_cast<un_scalar_t>(1e-12));

            case RadioactivityUnit::Nanobecquerel:
                return (value * static_cast<un_scalar_t>(1e-9));

            case RadioactivityUnit::Microbecquerel:
                return (value * static_cast<un_scalar_t>(1e-6));

            case RadioactivityUnit::Millibecquerel:
                return (value * static_cast<un_scalar_t>(1e-3));

            case RadioactivityUnit::Kilobecquerel:
                return (value * static_cast<un_scalar_t>(1e3));

            case RadioactivityUnit::Megabecquerel:
                return (value * static_cast<un_scalar_t>(1e6));

            case RadioactivityUnit::Gigabecquerel:
                return (value * static_cast<un_scalar_t>(1e9));

            case RadioactivityUnit::Terabecquerel:
                return (value * static_cast<un_scalar_t>(1e12));

            case RadioactivityUnit::Petabecquerel:
                return (value * static_cast<un_scalar_t>(1e15));

            case RadioactivityUnit::Exabecquerel:
                return (value * static_cast<un_scalar_t>(1e18));

            case RadioactivityUnit::Curie:
                return value * static_cast<un_scalar_t>(3.7e10);

            case RadioactivityUnit::Picocurie:
                return (value * static_cast<un_scalar_t>(1e-12)) * static_cast<un_scalar_t>(3.7e10);

            case RadioactivityUnit::Nanocurie:
                return (value * static_cast<un_scalar_t>(1e-9)) * static_cast<un_scalar_t>(3.7e10);

            case RadioactivityUnit::Microcurie:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(3.7e10);

            case RadioactivityUnit::Millicurie:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(3.7e10);

            case RadioactivityUnit::Kilocurie:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(3.7e10);

            case RadioactivityUnit::Megacurie:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(3.7e10);

            case RadioactivityUnit::Gigacurie:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(3.7e10);

            case RadioactivityUnit::Teracurie:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(3.7e10);

            case RadioactivityUnit::Rutherford:
                return value * static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Picorutherford:
                return (value * static_cast<un_scalar_t>(1e-12)) * static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Nanorutherford:
                return (value * static_cast<un_scalar_t>(1e-9)) * static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Microrutherford:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Millirutherford:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Kilorutherford:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Megarutherford:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Gigarutherford:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Terarutherford:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown Radioactivity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RadioactivityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case RadioactivityUnit::Becquerel:
                return base_value;

            case RadioactivityUnit::Picobecquerel:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case RadioactivityUnit::Nanobecquerel:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case RadioactivityUnit::Microbecquerel:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case RadioactivityUnit::Millibecquerel:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case RadioactivityUnit::Kilobecquerel:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case RadioactivityUnit::Megabecquerel:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Gigabecquerel:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case RadioactivityUnit::Terabecquerel:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            case RadioactivityUnit::Petabecquerel:
                return (base_value) / static_cast<un_scalar_t>(1e15);

            case RadioactivityUnit::Exabecquerel:
                return (base_value) / static_cast<un_scalar_t>(1e18);

            case RadioactivityUnit::Curie:
                return base_value / static_cast<un_scalar_t>(3.7e10);

            case RadioactivityUnit::Picocurie:
                return (base_value / static_cast<un_scalar_t>(3.7e10)) / static_cast<un_scalar_t>(1e-12);

            case RadioactivityUnit::Nanocurie:
                return (base_value / static_cast<un_scalar_t>(3.7e10)) / static_cast<un_scalar_t>(1e-9);

            case RadioactivityUnit::Microcurie:
                return (base_value / static_cast<un_scalar_t>(3.7e10)) / static_cast<un_scalar_t>(1e-6);

            case RadioactivityUnit::Millicurie:
                return (base_value / static_cast<un_scalar_t>(3.7e10)) / static_cast<un_scalar_t>(1e-3);

            case RadioactivityUnit::Kilocurie:
                return (base_value / static_cast<un_scalar_t>(3.7e10)) / static_cast<un_scalar_t>(1e3);

            case RadioactivityUnit::Megacurie:
                return (base_value / static_cast<un_scalar_t>(3.7e10)) / static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Gigacurie:
                return (base_value / static_cast<un_scalar_t>(3.7e10)) / static_cast<un_scalar_t>(1e9);

            case RadioactivityUnit::Teracurie:
                return (base_value / static_cast<un_scalar_t>(3.7e10)) / static_cast<un_scalar_t>(1e12);

            case RadioactivityUnit::Rutherford:
                return base_value / static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Picorutherford:
                return (base_value / static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e-12);

            case RadioactivityUnit::Nanorutherford:
                return (base_value / static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e-9);

            case RadioactivityUnit::Microrutherford:
                return (base_value / static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e-6);

            case RadioactivityUnit::Millirutherford:
                return (base_value / static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e-3);

            case RadioactivityUnit::Kilorutherford:
                return (base_value / static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e3);

            case RadioactivityUnit::Megarutherford:
                return (base_value / static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Gigarutherford:
                return (base_value / static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e9);

            case RadioactivityUnit::Terarutherford:
                return (base_value / static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown Radioactivity unit.");
        }

        un_scalar_t value_;
        RadioactivityUnit value_unit_type_;       
    };
}
