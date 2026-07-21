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
    enum class ElectricResistivityUnit : std::uint8_t
    {
        OhmMeter,
        PicoohmMeter,
        NanoohmMeter,
        MicroohmMeter,
        MilliohmMeter,
        KiloohmMeter,
        MegaohmMeter,
        OhmCentimeter,
        PicoohmCentimeter,
        NanoohmCentimeter,
        MicroohmCentimeter,
        MilliohmCentimeter,
        KiloohmCentimeter,
        MegaohmCentimeter,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ElectricResistivity.</summary>
    class ElectricResistivityDto
    {
    public:
        constexpr ElectricResistivityDto() noexcept
            : value{}, unit(ElectricResistivityUnit::OhmMeter)
        {
        }

        constexpr ElectricResistivityDto(
            const un_scalar_t value,
            const ElectricResistivityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricResistivityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricResistivityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricResistivityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricResistivity unit name.");
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
        [[nodiscard]] static ElectricResistivityDto from_json(const nlohmann::json& json)
        {
            return ElectricResistivityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Electrical resistivity (also known as resistivity, specific electrical resistance, or volume resistivity) is a fundamental property that quantifies how strongly a given material opposes the flow of electric current.</summary>
    class ElectricResistivity : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricResistivity(
            const un_scalar_t value,
            const ElectricResistivityUnit unit = ElectricResistivityUnit::OhmMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricResistivityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricResistivityDto to_dto(
            const ElectricResistivityUnit unit = ElectricResistivityUnit::OhmMeter) const
        {
            return ElectricResistivityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricResistivity from_dto(const ElectricResistivityDto& dto)
        {
            return ElectricResistivity(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricResistivityUnit unit = ElectricResistivityUnit::OhmMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricResistivity from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricResistivityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricResistivity operator+(const ElectricResistivity& other) const noexcept
        {
            return ElectricResistivity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricResistivity operator-(const ElectricResistivity& other)const noexcept
        {
            return ElectricResistivity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricResistivity operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricResistivity(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricResistivity operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricResistivity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricResistivity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricResistivity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricResistivity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t ohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::OhmMeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_ohm_meters(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::OhmMeter);
        }

        [[nodiscard]] constexpr un_scalar_t picoohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::PicoohmMeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_picoohm_meters(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::PicoohmMeter);
        }

        [[nodiscard]] constexpr un_scalar_t nanoohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::NanoohmMeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_nanoohm_meters(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::NanoohmMeter);
        }

        [[nodiscard]] constexpr un_scalar_t microohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::MicroohmMeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_microohm_meters(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MicroohmMeter);
        }

        [[nodiscard]] constexpr un_scalar_t milliohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::MilliohmMeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_milliohm_meters(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MilliohmMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kiloohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::KiloohmMeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_kiloohm_meters(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::KiloohmMeter);
        }

        [[nodiscard]] constexpr un_scalar_t megaohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::MegaohmMeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_megaohm_meters(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MegaohmMeter);
        }

        [[nodiscard]] constexpr un_scalar_t ohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::OhmCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_ohms_centimeter(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::OhmCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t picoohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::PicoohmCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_picoohms_centimeter(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::PicoohmCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t nanoohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::NanoohmCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_nanoohms_centimeter(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::NanoohmCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t microohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::MicroohmCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_microohms_centimeter(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MicroohmCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t milliohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::MilliohmCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_milliohms_centimeter(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MilliohmCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kiloohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::KiloohmCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_kiloohms_centimeter(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::KiloohmCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t megaohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::MegaohmCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_megaohms_centimeter(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MegaohmCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_invalid()
        {
            return ElectricResistivity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricResistivityUnit unit)
        {
            switch (unit)
            {

            case ElectricResistivityUnit::OhmMeter:
                return value;

            case ElectricResistivityUnit::PicoohmMeter:
                return (value * static_cast<un_scalar_t>(1e-12));

            case ElectricResistivityUnit::NanoohmMeter:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricResistivityUnit::MicroohmMeter:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricResistivityUnit::MilliohmMeter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricResistivityUnit::KiloohmMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricResistivityUnit::MegaohmMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricResistivityUnit::OhmCentimeter:
                return value / static_cast<un_scalar_t>(100);

            case ElectricResistivityUnit::PicoohmCentimeter:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(100);

            case ElectricResistivityUnit::NanoohmCentimeter:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(100);

            case ElectricResistivityUnit::MicroohmCentimeter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(100);

            case ElectricResistivityUnit::MilliohmCentimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(100);

            case ElectricResistivityUnit::KiloohmCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(100);

            case ElectricResistivityUnit::MegaohmCentimeter:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(100);

            }

            throw std::invalid_argument("Unknown ElectricResistivity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricResistivityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricResistivityUnit::OhmMeter:
                return base_value;

            case ElectricResistivityUnit::PicoohmMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case ElectricResistivityUnit::NanoohmMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ElectricResistivityUnit::MicroohmMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricResistivityUnit::MilliohmMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricResistivityUnit::KiloohmMeter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricResistivityUnit::MegaohmMeter:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ElectricResistivityUnit::OhmCentimeter:
                return base_value * static_cast<un_scalar_t>(100);

            case ElectricResistivityUnit::PicoohmCentimeter:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-12);

            case ElectricResistivityUnit::NanoohmCentimeter:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-9);

            case ElectricResistivityUnit::MicroohmCentimeter:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-6);

            case ElectricResistivityUnit::MilliohmCentimeter:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-3);

            case ElectricResistivityUnit::KiloohmCentimeter:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e3);

            case ElectricResistivityUnit::MegaohmCentimeter:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown ElectricResistivity unit.");
        }

        un_scalar_t value_;
        ElectricResistivityUnit value_unit_type_;       
    };
}
