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
    enum class BitRateUnit : std::uint8_t
    {
        BitPerSecond,
        KilobitPerSecond,
        MegabitPerSecond,
        GigabitPerSecond,
        TerabitPerSecond,
        PetabitPerSecond,
        ExabitPerSecond,
        KibibitPerSecond,
        MebibitPerSecond,
        GibibitPerSecond,
        TebibitPerSecond,
        PebibitPerSecond,
        ExbibitPerSecond,
        BytePerSecond,
        KilobytePerSecond,
        MegabytePerSecond,
        GigabytePerSecond,
        TerabytePerSecond,
        PetabytePerSecond,
        ExabytePerSecond,
        KibibytePerSecond,
        MebibytePerSecond,
        GibibytePerSecond,
        TebibytePerSecond,
        PebibytePerSecond,
        ExbibytePerSecond,
        OctetPerSecond,
        KilooctetPerSecond,
        MegaoctetPerSecond,
        GigaoctetPerSecond,
        TeraoctetPerSecond,
        PetaoctetPerSecond,
        ExaoctetPerSecond,
        KibioctetPerSecond,
        MebioctetPerSecond,
        GibioctetPerSecond,
        TebioctetPerSecond,
        PebioctetPerSecond,
        ExbioctetPerSecond,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of BitRate.</summary>
    class BitRateDto
    {
    public:
        constexpr BitRateDto() noexcept
            : value{}, unit(BitRateUnit::BitPerSecond)
        {
        }

        constexpr BitRateDto(
            const un_scalar_t value,
            const BitRateUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        BitRateUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr BitRateUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<BitRateUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown BitRate unit name.");
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
        [[nodiscard]] static BitRateDto from_json(const nlohmann::json& json)
        {
            return BitRateDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In telecommunications and computing, bit rate is the number of bits that are conveyed or processed per unit of time.</summary>
    class BitRate : public UnitsNetBase
    {
    public:
        constexpr explicit BitRate(
            const un_scalar_t value,
            const BitRateUnit unit = BitRateUnit::BitPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const BitRateUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr BitRateDto to_dto(
            const BitRateUnit unit = BitRateUnit::BitPerSecond) const
        {
            return BitRateDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr BitRate from_dto(const BitRateDto& dto)
        {
            return BitRate(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const BitRateUnit unit = BitRateUnit::BitPerSecond) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static BitRate from_json(const nlohmann::json& json)
        {
            return from_dto(BitRateDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr BitRate operator+(const BitRate& other) const noexcept
        {
            return BitRate(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr BitRate operator-(const BitRate& other)const noexcept
        {
            return BitRate(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr BitRate operator*(const un_scalar_t scalar) const noexcept
        {
            return BitRate(base_value() * scalar);
        }

        [[nodiscard]] constexpr BitRate operator/(const un_scalar_t scalar) const noexcept
        {
            return BitRate(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const BitRate& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const BitRate& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const BitRate& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t bits_per_second() const
        {
            return convert_from_base(BitRateUnit::BitPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_bits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::BitPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kilobits_per_second() const
        {
            return convert_from_base(BitRateUnit::KilobitPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_kilobits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::KilobitPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t megabits_per_second() const
        {
            return convert_from_base(BitRateUnit::MegabitPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_megabits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::MegabitPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t gigabits_per_second() const
        {
            return convert_from_base(BitRateUnit::GigabitPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_gigabits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::GigabitPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t terabits_per_second() const
        {
            return convert_from_base(BitRateUnit::TerabitPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_terabits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::TerabitPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t petabits_per_second() const
        {
            return convert_from_base(BitRateUnit::PetabitPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_petabits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::PetabitPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t exabits_per_second() const
        {
            return convert_from_base(BitRateUnit::ExabitPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_exabits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::ExabitPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kibibits_per_second() const
        {
            return convert_from_base(BitRateUnit::KibibitPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_kibibits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::KibibitPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t mebibits_per_second() const
        {
            return convert_from_base(BitRateUnit::MebibitPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_mebibits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::MebibitPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t gibibits_per_second() const
        {
            return convert_from_base(BitRateUnit::GibibitPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_gibibits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::GibibitPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t tebibits_per_second() const
        {
            return convert_from_base(BitRateUnit::TebibitPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_tebibits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::TebibitPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t pebibits_per_second() const
        {
            return convert_from_base(BitRateUnit::PebibitPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_pebibits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::PebibitPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t exbibits_per_second() const
        {
            return convert_from_base(BitRateUnit::ExbibitPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_exbibits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::ExbibitPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t bytes_per_second() const
        {
            return convert_from_base(BitRateUnit::BytePerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_bytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::BytePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kilobytes_per_second() const
        {
            return convert_from_base(BitRateUnit::KilobytePerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_kilobytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::KilobytePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t megabytes_per_second() const
        {
            return convert_from_base(BitRateUnit::MegabytePerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_megabytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::MegabytePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t gigabytes_per_second() const
        {
            return convert_from_base(BitRateUnit::GigabytePerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_gigabytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::GigabytePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t terabytes_per_second() const
        {
            return convert_from_base(BitRateUnit::TerabytePerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_terabytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::TerabytePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t petabytes_per_second() const
        {
            return convert_from_base(BitRateUnit::PetabytePerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_petabytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::PetabytePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t exabytes_per_second() const
        {
            return convert_from_base(BitRateUnit::ExabytePerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_exabytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::ExabytePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kibibytes_per_second() const
        {
            return convert_from_base(BitRateUnit::KibibytePerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_kibibytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::KibibytePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t mebibytes_per_second() const
        {
            return convert_from_base(BitRateUnit::MebibytePerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_mebibytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::MebibytePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t gibibytes_per_second() const
        {
            return convert_from_base(BitRateUnit::GibibytePerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_gibibytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::GibibytePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t tebibytes_per_second() const
        {
            return convert_from_base(BitRateUnit::TebibytePerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_tebibytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::TebibytePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t pebibytes_per_second() const
        {
            return convert_from_base(BitRateUnit::PebibytePerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_pebibytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::PebibytePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t exbibytes_per_second() const
        {
            return convert_from_base(BitRateUnit::ExbibytePerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_exbibytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::ExbibytePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t octets_per_second() const
        {
            return convert_from_base(BitRateUnit::OctetPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_octets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::OctetPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kilooctets_per_second() const
        {
            return convert_from_base(BitRateUnit::KilooctetPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_kilooctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::KilooctetPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t megaoctets_per_second() const
        {
            return convert_from_base(BitRateUnit::MegaoctetPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_megaoctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::MegaoctetPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t gigaoctets_per_second() const
        {
            return convert_from_base(BitRateUnit::GigaoctetPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_gigaoctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::GigaoctetPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t teraoctets_per_second() const
        {
            return convert_from_base(BitRateUnit::TeraoctetPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_teraoctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::TeraoctetPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t petaoctets_per_second() const
        {
            return convert_from_base(BitRateUnit::PetaoctetPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_petaoctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::PetaoctetPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t exaoctets_per_second() const
        {
            return convert_from_base(BitRateUnit::ExaoctetPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_exaoctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::ExaoctetPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kibioctets_per_second() const
        {
            return convert_from_base(BitRateUnit::KibioctetPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_kibioctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::KibioctetPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t mebioctets_per_second() const
        {
            return convert_from_base(BitRateUnit::MebioctetPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_mebioctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::MebioctetPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t gibioctets_per_second() const
        {
            return convert_from_base(BitRateUnit::GibioctetPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_gibioctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::GibioctetPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t tebioctets_per_second() const
        {
            return convert_from_base(BitRateUnit::TebioctetPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_tebioctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::TebioctetPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t pebioctets_per_second() const
        {
            return convert_from_base(BitRateUnit::PebioctetPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_pebioctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::PebioctetPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t exbioctets_per_second() const
        {
            return convert_from_base(BitRateUnit::ExbioctetPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_exbioctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::ExbioctetPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_invalid()
        {
            return BitRate(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, BitRateUnit unit)
        {
            switch (unit)
            {

            case BitRateUnit::BitPerSecond:
                return value;

            case BitRateUnit::KilobitPerSecond:
                return (value * static_cast<un_scalar_t>(1e3));

            case BitRateUnit::MegabitPerSecond:
                return (value * static_cast<un_scalar_t>(1e6));

            case BitRateUnit::GigabitPerSecond:
                return (value * static_cast<un_scalar_t>(1e9));

            case BitRateUnit::TerabitPerSecond:
                return (value * static_cast<un_scalar_t>(1e12));

            case BitRateUnit::PetabitPerSecond:
                return (value * static_cast<un_scalar_t>(1e15));

            case BitRateUnit::ExabitPerSecond:
                return (value * static_cast<un_scalar_t>(1e18));

            case BitRateUnit::KibibitPerSecond:
                return (value * static_cast<un_scalar_t>(1024.0));

            case BitRateUnit::MebibitPerSecond:
                return (value * static_cast<un_scalar_t>(1048576.0));

            case BitRateUnit::GibibitPerSecond:
                return (value * static_cast<un_scalar_t>(1073741824.0));

            case BitRateUnit::TebibitPerSecond:
                return (value * static_cast<un_scalar_t>(1099511627776.0));

            case BitRateUnit::PebibitPerSecond:
                return (value * static_cast<un_scalar_t>(1125899906842624.0));

            case BitRateUnit::ExbibitPerSecond:
                return (value * static_cast<un_scalar_t>(1152921504606846976.0));

            case BitRateUnit::BytePerSecond:
                return value * static_cast<un_scalar_t>(8);

            case BitRateUnit::KilobytePerSecond:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::MegabytePerSecond:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::GigabytePerSecond:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::TerabytePerSecond:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::PetabytePerSecond:
                return (value * static_cast<un_scalar_t>(1e15)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::ExabytePerSecond:
                return (value * static_cast<un_scalar_t>(1e18)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::KibibytePerSecond:
                return (value * static_cast<un_scalar_t>(1024.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::MebibytePerSecond:
                return (value * static_cast<un_scalar_t>(1048576.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::GibibytePerSecond:
                return (value * static_cast<un_scalar_t>(1073741824.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::TebibytePerSecond:
                return (value * static_cast<un_scalar_t>(1099511627776.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::PebibytePerSecond:
                return (value * static_cast<un_scalar_t>(1125899906842624.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::ExbibytePerSecond:
                return (value * static_cast<un_scalar_t>(1152921504606846976.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::OctetPerSecond:
                return value * static_cast<un_scalar_t>(8);

            case BitRateUnit::KilooctetPerSecond:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::MegaoctetPerSecond:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::GigaoctetPerSecond:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::TeraoctetPerSecond:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::PetaoctetPerSecond:
                return (value * static_cast<un_scalar_t>(1e15)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::ExaoctetPerSecond:
                return (value * static_cast<un_scalar_t>(1e18)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::KibioctetPerSecond:
                return (value * static_cast<un_scalar_t>(1024.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::MebioctetPerSecond:
                return (value * static_cast<un_scalar_t>(1048576.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::GibioctetPerSecond:
                return (value * static_cast<un_scalar_t>(1073741824.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::TebioctetPerSecond:
                return (value * static_cast<un_scalar_t>(1099511627776.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::PebioctetPerSecond:
                return (value * static_cast<un_scalar_t>(1125899906842624.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::ExbioctetPerSecond:
                return (value * static_cast<un_scalar_t>(1152921504606846976.0)) * static_cast<un_scalar_t>(8);

            }

            throw std::invalid_argument("Unknown BitRate unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const BitRateUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case BitRateUnit::BitPerSecond:
                return base_value;

            case BitRateUnit::KilobitPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case BitRateUnit::MegabitPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case BitRateUnit::GigabitPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case BitRateUnit::TerabitPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            case BitRateUnit::PetabitPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e15);

            case BitRateUnit::ExabitPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e18);

            case BitRateUnit::KibibitPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1024.0);

            case BitRateUnit::MebibitPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1048576.0);

            case BitRateUnit::GibibitPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1073741824.0);

            case BitRateUnit::TebibitPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1099511627776.0);

            case BitRateUnit::PebibitPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1125899906842624.0);

            case BitRateUnit::ExbibitPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1152921504606846976.0);

            case BitRateUnit::BytePerSecond:
                return base_value / static_cast<un_scalar_t>(8);

            case BitRateUnit::KilobytePerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e3);

            case BitRateUnit::MegabytePerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e6);

            case BitRateUnit::GigabytePerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e9);

            case BitRateUnit::TerabytePerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e12);

            case BitRateUnit::PetabytePerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e15);

            case BitRateUnit::ExabytePerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e18);

            case BitRateUnit::KibibytePerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1024.0);

            case BitRateUnit::MebibytePerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1048576.0);

            case BitRateUnit::GibibytePerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1073741824.0);

            case BitRateUnit::TebibytePerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1099511627776.0);

            case BitRateUnit::PebibytePerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1125899906842624.0);

            case BitRateUnit::ExbibytePerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1152921504606846976.0);

            case BitRateUnit::OctetPerSecond:
                return base_value / static_cast<un_scalar_t>(8);

            case BitRateUnit::KilooctetPerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e3);

            case BitRateUnit::MegaoctetPerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e6);

            case BitRateUnit::GigaoctetPerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e9);

            case BitRateUnit::TeraoctetPerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e12);

            case BitRateUnit::PetaoctetPerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e15);

            case BitRateUnit::ExaoctetPerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e18);

            case BitRateUnit::KibioctetPerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1024.0);

            case BitRateUnit::MebioctetPerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1048576.0);

            case BitRateUnit::GibioctetPerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1073741824.0);

            case BitRateUnit::TebioctetPerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1099511627776.0);

            case BitRateUnit::PebioctetPerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1125899906842624.0);

            case BitRateUnit::ExbioctetPerSecond:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1152921504606846976.0);

            }

            throw std::invalid_argument("Unknown BitRate unit.");
        }

        un_scalar_t value_;
        BitRateUnit value_unit_type_;       
    };
}
