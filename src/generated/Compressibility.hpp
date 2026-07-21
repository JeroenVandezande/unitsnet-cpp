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
    enum class CompressibilityUnit : std::uint8_t
    {
        InversePascal,
        InverseKilopascal,
        InverseMegapascal,
        InverseAtmosphere,
        InverseMillibar,
        InverseBar,
        InversePoundForcePerSquareInch,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Compressibility.</summary>
    class CompressibilityDto
    {
    public:
        constexpr CompressibilityDto() noexcept
            : value{}, unit(CompressibilityUnit::InversePascal)
        {
        }

        constexpr CompressibilityDto(
            const un_scalar_t value,
            const CompressibilityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        CompressibilityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr CompressibilityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<CompressibilityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Compressibility unit name.");
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
        [[nodiscard]] static CompressibilityDto from_json(const nlohmann::json& json)
        {
            return CompressibilityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary></summary>
    class Compressibility : public UnitsNetBase
    {
    public:
        constexpr explicit Compressibility(
            const un_scalar_t value,
            const CompressibilityUnit unit = CompressibilityUnit::InversePascal)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const CompressibilityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr CompressibilityDto to_dto(
            const CompressibilityUnit unit = CompressibilityUnit::InversePascal) const
        {
            return CompressibilityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Compressibility from_dto(const CompressibilityDto& dto)
        {
            return Compressibility(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const CompressibilityUnit unit = CompressibilityUnit::InversePascal) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Compressibility from_json(const nlohmann::json& json)
        {
            return from_dto(CompressibilityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Compressibility operator+(const Compressibility& other) const noexcept
        {
            return Compressibility(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Compressibility operator-(const Compressibility& other)const noexcept
        {
            return Compressibility(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Compressibility operator*(const un_scalar_t scalar) const noexcept
        {
            return Compressibility(base_value() * scalar);
        }

        [[nodiscard]] constexpr Compressibility operator/(const un_scalar_t scalar) const noexcept
        {
            return Compressibility(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Compressibility& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Compressibility& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Compressibility& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t inverse_pascals() const
        {
            return convert_from_base(CompressibilityUnit::InversePascal);
        }

        [[nodiscard]] static constexpr Compressibility from_inverse_pascals(const un_scalar_t value)
        {
            return Compressibility(value, CompressibilityUnit::InversePascal);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_kilopascals() const
        {
            return convert_from_base(CompressibilityUnit::InverseKilopascal);
        }

        [[nodiscard]] static constexpr Compressibility from_inverse_kilopascals(const un_scalar_t value)
        {
            return Compressibility(value, CompressibilityUnit::InverseKilopascal);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_megapascals() const
        {
            return convert_from_base(CompressibilityUnit::InverseMegapascal);
        }

        [[nodiscard]] static constexpr Compressibility from_inverse_megapascals(const un_scalar_t value)
        {
            return Compressibility(value, CompressibilityUnit::InverseMegapascal);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_atmospheres() const
        {
            return convert_from_base(CompressibilityUnit::InverseAtmosphere);
        }

        [[nodiscard]] static constexpr Compressibility from_inverse_atmospheres(const un_scalar_t value)
        {
            return Compressibility(value, CompressibilityUnit::InverseAtmosphere);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_millibars() const
        {
            return convert_from_base(CompressibilityUnit::InverseMillibar);
        }

        [[nodiscard]] static constexpr Compressibility from_inverse_millibars(const un_scalar_t value)
        {
            return Compressibility(value, CompressibilityUnit::InverseMillibar);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_bars() const
        {
            return convert_from_base(CompressibilityUnit::InverseBar);
        }

        [[nodiscard]] static constexpr Compressibility from_inverse_bars(const un_scalar_t value)
        {
            return Compressibility(value, CompressibilityUnit::InverseBar);
        }

        [[nodiscard]] constexpr un_scalar_t inverse_pounds_force_per_square_inch() const
        {
            return convert_from_base(CompressibilityUnit::InversePoundForcePerSquareInch);
        }

        [[nodiscard]] static constexpr Compressibility from_inverse_pounds_force_per_square_inch(const un_scalar_t value)
        {
            return Compressibility(value, CompressibilityUnit::InversePoundForcePerSquareInch);
        }

        [[nodiscard]] static constexpr Compressibility from_invalid()
        {
            return Compressibility(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, CompressibilityUnit unit)
        {
            switch (unit)
            {

            case CompressibilityUnit::InversePascal:
                return value;

            case CompressibilityUnit::InverseKilopascal:
                return value * static_cast<un_scalar_t>(1e3);

            case CompressibilityUnit::InverseMegapascal:
                return value * static_cast<un_scalar_t>(1e6);

            case CompressibilityUnit::InverseAtmosphere:
                return value * static_cast<un_scalar_t>(101325);

            case CompressibilityUnit::InverseMillibar:
                return value * static_cast<un_scalar_t>(100);

            case CompressibilityUnit::InverseBar:
                return value * static_cast<un_scalar_t>(1e5);

            case CompressibilityUnit::InversePoundForcePerSquareInch:
                return value * static_cast<un_scalar_t>(6.894757293168361e3);

            }

            throw std::invalid_argument("Unknown Compressibility unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const CompressibilityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case CompressibilityUnit::InversePascal:
                return base_value;

            case CompressibilityUnit::InverseKilopascal:
                return base_value / static_cast<un_scalar_t>(1e3);

            case CompressibilityUnit::InverseMegapascal:
                return base_value / static_cast<un_scalar_t>(1e6);

            case CompressibilityUnit::InverseAtmosphere:
                return base_value / static_cast<un_scalar_t>(101325);

            case CompressibilityUnit::InverseMillibar:
                return base_value / static_cast<un_scalar_t>(100);

            case CompressibilityUnit::InverseBar:
                return base_value / static_cast<un_scalar_t>(1e5);

            case CompressibilityUnit::InversePoundForcePerSquareInch:
                return base_value / static_cast<un_scalar_t>(6.894757293168361e3);

            }

            throw std::invalid_argument("Unknown Compressibility unit.");
        }

        un_scalar_t value_;
        CompressibilityUnit value_unit_type_;       
    };
}
