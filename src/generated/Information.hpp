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
    enum class InformationUnit : std::uint8_t
    {
        Byte,
        Kilobyte,
        Megabyte,
        Gigabyte,
        Terabyte,
        Petabyte,
        Exabyte,
        Kibibyte,
        Mebibyte,
        Gibibyte,
        Tebibyte,
        Pebibyte,
        Exbibyte,
        Octet,
        Kilooctet,
        Megaoctet,
        Gigaoctet,
        Teraoctet,
        Petaoctet,
        Exaoctet,
        Kibioctet,
        Mebioctet,
        Gibioctet,
        Tebioctet,
        Pebioctet,
        Exbioctet,
        Bit,
        Kilobit,
        Megabit,
        Gigabit,
        Terabit,
        Petabit,
        Exabit,
        Kibibit,
        Mebibit,
        Gibibit,
        Tebibit,
        Pebibit,
        Exbibit,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Information.</summary>
    class InformationDto
    {
    public:
        constexpr InformationDto() noexcept
            : value{}, unit(InformationUnit::Bit)
        {
        }

        constexpr InformationDto(
            const un_scalar_t value,
            const InformationUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        InformationUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr InformationUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<InformationUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Information unit name.");
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
        [[nodiscard]] static InformationDto from_json(const nlohmann::json& json)
        {
            return InformationDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In computing and telecommunications, a unit of information is the capacity of some standard data storage system or communication channel, used to measure the capacities of other systems and channels. In information theory, units of information are also used to measure the information contents or entropy of random variables.</summary>
    class Information : public UnitsNetBase
    {
    public:
        constexpr explicit Information(
            const un_scalar_t value,
            const InformationUnit unit = InformationUnit::Bit)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const InformationUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr InformationDto to_dto(
            const InformationUnit unit = InformationUnit::Bit) const
        {
            return InformationDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Information from_dto(const InformationDto& dto)
        {
            return Information(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const InformationUnit unit = InformationUnit::Bit) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Information from_json(const nlohmann::json& json)
        {
            return from_dto(InformationDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Information operator+(const Information& other) const noexcept
        {
            return Information(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Information operator-(const Information& other)const noexcept
        {
            return Information(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Information operator*(const un_scalar_t scalar) const noexcept
        {
            return Information(base_value() * scalar);
        }

        [[nodiscard]] constexpr Information operator/(const un_scalar_t scalar) const noexcept
        {
            return Information(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Information& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Information& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Information& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t bytes() const
        {
            return convert_from_base(InformationUnit::Byte);
        }

        [[nodiscard]] static constexpr Information from_bytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Byte);
        }

        [[nodiscard]] constexpr un_scalar_t kilobytes() const
        {
            return convert_from_base(InformationUnit::Kilobyte);
        }

        [[nodiscard]] static constexpr Information from_kilobytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Kilobyte);
        }

        [[nodiscard]] constexpr un_scalar_t megabytes() const
        {
            return convert_from_base(InformationUnit::Megabyte);
        }

        [[nodiscard]] static constexpr Information from_megabytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Megabyte);
        }

        [[nodiscard]] constexpr un_scalar_t gigabytes() const
        {
            return convert_from_base(InformationUnit::Gigabyte);
        }

        [[nodiscard]] static constexpr Information from_gigabytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Gigabyte);
        }

        [[nodiscard]] constexpr un_scalar_t terabytes() const
        {
            return convert_from_base(InformationUnit::Terabyte);
        }

        [[nodiscard]] static constexpr Information from_terabytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Terabyte);
        }

        [[nodiscard]] constexpr un_scalar_t petabytes() const
        {
            return convert_from_base(InformationUnit::Petabyte);
        }

        [[nodiscard]] static constexpr Information from_petabytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Petabyte);
        }

        [[nodiscard]] constexpr un_scalar_t exabytes() const
        {
            return convert_from_base(InformationUnit::Exabyte);
        }

        [[nodiscard]] static constexpr Information from_exabytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Exabyte);
        }

        [[nodiscard]] constexpr un_scalar_t kibibytes() const
        {
            return convert_from_base(InformationUnit::Kibibyte);
        }

        [[nodiscard]] static constexpr Information from_kibibytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Kibibyte);
        }

        [[nodiscard]] constexpr un_scalar_t mebibytes() const
        {
            return convert_from_base(InformationUnit::Mebibyte);
        }

        [[nodiscard]] static constexpr Information from_mebibytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Mebibyte);
        }

        [[nodiscard]] constexpr un_scalar_t gibibytes() const
        {
            return convert_from_base(InformationUnit::Gibibyte);
        }

        [[nodiscard]] static constexpr Information from_gibibytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Gibibyte);
        }

        [[nodiscard]] constexpr un_scalar_t tebibytes() const
        {
            return convert_from_base(InformationUnit::Tebibyte);
        }

        [[nodiscard]] static constexpr Information from_tebibytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Tebibyte);
        }

        [[nodiscard]] constexpr un_scalar_t pebibytes() const
        {
            return convert_from_base(InformationUnit::Pebibyte);
        }

        [[nodiscard]] static constexpr Information from_pebibytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Pebibyte);
        }

        [[nodiscard]] constexpr un_scalar_t exbibytes() const
        {
            return convert_from_base(InformationUnit::Exbibyte);
        }

        [[nodiscard]] static constexpr Information from_exbibytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Exbibyte);
        }

        [[nodiscard]] constexpr un_scalar_t octets() const
        {
            return convert_from_base(InformationUnit::Octet);
        }

        [[nodiscard]] static constexpr Information from_octets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Octet);
        }

        [[nodiscard]] constexpr un_scalar_t kilooctets() const
        {
            return convert_from_base(InformationUnit::Kilooctet);
        }

        [[nodiscard]] static constexpr Information from_kilooctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Kilooctet);
        }

        [[nodiscard]] constexpr un_scalar_t megaoctets() const
        {
            return convert_from_base(InformationUnit::Megaoctet);
        }

        [[nodiscard]] static constexpr Information from_megaoctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Megaoctet);
        }

        [[nodiscard]] constexpr un_scalar_t gigaoctets() const
        {
            return convert_from_base(InformationUnit::Gigaoctet);
        }

        [[nodiscard]] static constexpr Information from_gigaoctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Gigaoctet);
        }

        [[nodiscard]] constexpr un_scalar_t teraoctets() const
        {
            return convert_from_base(InformationUnit::Teraoctet);
        }

        [[nodiscard]] static constexpr Information from_teraoctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Teraoctet);
        }

        [[nodiscard]] constexpr un_scalar_t petaoctets() const
        {
            return convert_from_base(InformationUnit::Petaoctet);
        }

        [[nodiscard]] static constexpr Information from_petaoctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Petaoctet);
        }

        [[nodiscard]] constexpr un_scalar_t exaoctets() const
        {
            return convert_from_base(InformationUnit::Exaoctet);
        }

        [[nodiscard]] static constexpr Information from_exaoctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Exaoctet);
        }

        [[nodiscard]] constexpr un_scalar_t kibioctets() const
        {
            return convert_from_base(InformationUnit::Kibioctet);
        }

        [[nodiscard]] static constexpr Information from_kibioctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Kibioctet);
        }

        [[nodiscard]] constexpr un_scalar_t mebioctets() const
        {
            return convert_from_base(InformationUnit::Mebioctet);
        }

        [[nodiscard]] static constexpr Information from_mebioctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Mebioctet);
        }

        [[nodiscard]] constexpr un_scalar_t gibioctets() const
        {
            return convert_from_base(InformationUnit::Gibioctet);
        }

        [[nodiscard]] static constexpr Information from_gibioctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Gibioctet);
        }

        [[nodiscard]] constexpr un_scalar_t tebioctets() const
        {
            return convert_from_base(InformationUnit::Tebioctet);
        }

        [[nodiscard]] static constexpr Information from_tebioctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Tebioctet);
        }

        [[nodiscard]] constexpr un_scalar_t pebioctets() const
        {
            return convert_from_base(InformationUnit::Pebioctet);
        }

        [[nodiscard]] static constexpr Information from_pebioctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Pebioctet);
        }

        [[nodiscard]] constexpr un_scalar_t exbioctets() const
        {
            return convert_from_base(InformationUnit::Exbioctet);
        }

        [[nodiscard]] static constexpr Information from_exbioctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Exbioctet);
        }

        [[nodiscard]] constexpr un_scalar_t bits() const
        {
            return convert_from_base(InformationUnit::Bit);
        }

        [[nodiscard]] static constexpr Information from_bits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Bit);
        }

        [[nodiscard]] constexpr un_scalar_t kilobits() const
        {
            return convert_from_base(InformationUnit::Kilobit);
        }

        [[nodiscard]] static constexpr Information from_kilobits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Kilobit);
        }

        [[nodiscard]] constexpr un_scalar_t megabits() const
        {
            return convert_from_base(InformationUnit::Megabit);
        }

        [[nodiscard]] static constexpr Information from_megabits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Megabit);
        }

        [[nodiscard]] constexpr un_scalar_t gigabits() const
        {
            return convert_from_base(InformationUnit::Gigabit);
        }

        [[nodiscard]] static constexpr Information from_gigabits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Gigabit);
        }

        [[nodiscard]] constexpr un_scalar_t terabits() const
        {
            return convert_from_base(InformationUnit::Terabit);
        }

        [[nodiscard]] static constexpr Information from_terabits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Terabit);
        }

        [[nodiscard]] constexpr un_scalar_t petabits() const
        {
            return convert_from_base(InformationUnit::Petabit);
        }

        [[nodiscard]] static constexpr Information from_petabits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Petabit);
        }

        [[nodiscard]] constexpr un_scalar_t exabits() const
        {
            return convert_from_base(InformationUnit::Exabit);
        }

        [[nodiscard]] static constexpr Information from_exabits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Exabit);
        }

        [[nodiscard]] constexpr un_scalar_t kibibits() const
        {
            return convert_from_base(InformationUnit::Kibibit);
        }

        [[nodiscard]] static constexpr Information from_kibibits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Kibibit);
        }

        [[nodiscard]] constexpr un_scalar_t mebibits() const
        {
            return convert_from_base(InformationUnit::Mebibit);
        }

        [[nodiscard]] static constexpr Information from_mebibits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Mebibit);
        }

        [[nodiscard]] constexpr un_scalar_t gibibits() const
        {
            return convert_from_base(InformationUnit::Gibibit);
        }

        [[nodiscard]] static constexpr Information from_gibibits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Gibibit);
        }

        [[nodiscard]] constexpr un_scalar_t tebibits() const
        {
            return convert_from_base(InformationUnit::Tebibit);
        }

        [[nodiscard]] static constexpr Information from_tebibits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Tebibit);
        }

        [[nodiscard]] constexpr un_scalar_t pebibits() const
        {
            return convert_from_base(InformationUnit::Pebibit);
        }

        [[nodiscard]] static constexpr Information from_pebibits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Pebibit);
        }

        [[nodiscard]] constexpr un_scalar_t exbibits() const
        {
            return convert_from_base(InformationUnit::Exbibit);
        }

        [[nodiscard]] static constexpr Information from_exbibits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Exbibit);
        }

        [[nodiscard]] static constexpr Information from_invalid()
        {
            return Information(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, InformationUnit unit)
        {
            switch (unit)
            {

            case InformationUnit::Byte:
                return value * static_cast<un_scalar_t>(8);

            case InformationUnit::Kilobyte:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Megabyte:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Gigabyte:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Terabyte:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Petabyte:
                return (value * static_cast<un_scalar_t>(1e15)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Exabyte:
                return (value * static_cast<un_scalar_t>(1e18)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Kibibyte:
                return (value * static_cast<un_scalar_t>(1024.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Mebibyte:
                return (value * static_cast<un_scalar_t>(1048576.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Gibibyte:
                return (value * static_cast<un_scalar_t>(1073741824.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Tebibyte:
                return (value * static_cast<un_scalar_t>(1099511627776.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Pebibyte:
                return (value * static_cast<un_scalar_t>(1125899906842624.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Exbibyte:
                return (value * static_cast<un_scalar_t>(1152921504606846976.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Octet:
                return value * static_cast<un_scalar_t>(8);

            case InformationUnit::Kilooctet:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Megaoctet:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Gigaoctet:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Teraoctet:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Petaoctet:
                return (value * static_cast<un_scalar_t>(1e15)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Exaoctet:
                return (value * static_cast<un_scalar_t>(1e18)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Kibioctet:
                return (value * static_cast<un_scalar_t>(1024.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Mebioctet:
                return (value * static_cast<un_scalar_t>(1048576.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Gibioctet:
                return (value * static_cast<un_scalar_t>(1073741824.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Tebioctet:
                return (value * static_cast<un_scalar_t>(1099511627776.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Pebioctet:
                return (value * static_cast<un_scalar_t>(1125899906842624.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Exbioctet:
                return (value * static_cast<un_scalar_t>(1152921504606846976.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Bit:
                return value;

            case InformationUnit::Kilobit:
                return (value * static_cast<un_scalar_t>(1e3));

            case InformationUnit::Megabit:
                return (value * static_cast<un_scalar_t>(1e6));

            case InformationUnit::Gigabit:
                return (value * static_cast<un_scalar_t>(1e9));

            case InformationUnit::Terabit:
                return (value * static_cast<un_scalar_t>(1e12));

            case InformationUnit::Petabit:
                return (value * static_cast<un_scalar_t>(1e15));

            case InformationUnit::Exabit:
                return (value * static_cast<un_scalar_t>(1e18));

            case InformationUnit::Kibibit:
                return (value * static_cast<un_scalar_t>(1024.0));

            case InformationUnit::Mebibit:
                return (value * static_cast<un_scalar_t>(1048576.0));

            case InformationUnit::Gibibit:
                return (value * static_cast<un_scalar_t>(1073741824.0));

            case InformationUnit::Tebibit:
                return (value * static_cast<un_scalar_t>(1099511627776.0));

            case InformationUnit::Pebibit:
                return (value * static_cast<un_scalar_t>(1125899906842624.0));

            case InformationUnit::Exbibit:
                return (value * static_cast<un_scalar_t>(1152921504606846976.0));

            }

            throw std::invalid_argument("Unknown Information unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const InformationUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case InformationUnit::Byte:
                return base_value / static_cast<un_scalar_t>(8);

            case InformationUnit::Kilobyte:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e3);

            case InformationUnit::Megabyte:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e6);

            case InformationUnit::Gigabyte:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e9);

            case InformationUnit::Terabyte:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e12);

            case InformationUnit::Petabyte:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e15);

            case InformationUnit::Exabyte:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e18);

            case InformationUnit::Kibibyte:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1024.0);

            case InformationUnit::Mebibyte:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1048576.0);

            case InformationUnit::Gibibyte:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1073741824.0);

            case InformationUnit::Tebibyte:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1099511627776.0);

            case InformationUnit::Pebibyte:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1125899906842624.0);

            case InformationUnit::Exbibyte:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1152921504606846976.0);

            case InformationUnit::Octet:
                return base_value / static_cast<un_scalar_t>(8);

            case InformationUnit::Kilooctet:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e3);

            case InformationUnit::Megaoctet:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e6);

            case InformationUnit::Gigaoctet:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e9);

            case InformationUnit::Teraoctet:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e12);

            case InformationUnit::Petaoctet:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e15);

            case InformationUnit::Exaoctet:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e18);

            case InformationUnit::Kibioctet:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1024.0);

            case InformationUnit::Mebioctet:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1048576.0);

            case InformationUnit::Gibioctet:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1073741824.0);

            case InformationUnit::Tebioctet:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1099511627776.0);

            case InformationUnit::Pebioctet:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1125899906842624.0);

            case InformationUnit::Exbioctet:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1152921504606846976.0);

            case InformationUnit::Bit:
                return base_value;

            case InformationUnit::Kilobit:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case InformationUnit::Megabit:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case InformationUnit::Gigabit:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case InformationUnit::Terabit:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            case InformationUnit::Petabit:
                return (base_value) / static_cast<un_scalar_t>(1e15);

            case InformationUnit::Exabit:
                return (base_value) / static_cast<un_scalar_t>(1e18);

            case InformationUnit::Kibibit:
                return (base_value) / static_cast<un_scalar_t>(1024.0);

            case InformationUnit::Mebibit:
                return (base_value) / static_cast<un_scalar_t>(1048576.0);

            case InformationUnit::Gibibit:
                return (base_value) / static_cast<un_scalar_t>(1073741824.0);

            case InformationUnit::Tebibit:
                return (base_value) / static_cast<un_scalar_t>(1099511627776.0);

            case InformationUnit::Pebibit:
                return (base_value) / static_cast<un_scalar_t>(1125899906842624.0);

            case InformationUnit::Exbibit:
                return (base_value) / static_cast<un_scalar_t>(1152921504606846976.0);

            }

            throw std::invalid_argument("Unknown Information unit.");
        }

        un_scalar_t value_;
        InformationUnit value_unit_type_;       
    };
}
