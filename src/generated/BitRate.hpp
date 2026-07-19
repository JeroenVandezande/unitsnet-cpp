#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class BitRateUnit : std::uint8_t
    {
        BitsPerSecond,
        KilobitsPerSecond,
        MegabitsPerSecond,
        GigabitsPerSecond,
        TerabitsPerSecond,
        PetabitsPerSecond,
        ExabitsPerSecond,
        KibibitsPerSecond,
        MebibitsPerSecond,
        GibibitsPerSecond,
        TebibitsPerSecond,
        PebibitsPerSecond,
        ExbibitsPerSecond,
        BytesPerSecond,
        KilobytesPerSecond,
        MegabytesPerSecond,
        GigabytesPerSecond,
        TerabytesPerSecond,
        PetabytesPerSecond,
        ExabytesPerSecond,
        KibibytesPerSecond,
        MebibytesPerSecond,
        GibibytesPerSecond,
        TebibytesPerSecond,
        PebibytesPerSecond,
        ExbibytesPerSecond,
        OctetsPerSecond,
        KilooctetsPerSecond,
        MegaoctetsPerSecond,
        GigaoctetsPerSecond,
        TeraoctetsPerSecond,
        PetaoctetsPerSecond,
        ExaoctetsPerSecond,
        KibioctetsPerSecond,
        MebioctetsPerSecond,
        GibioctetsPerSecond,
        TebioctetsPerSecond,
        PebioctetsPerSecond,
        ExbioctetsPerSecond,
    };

    /// <summary>In telecommunications and computing, bit rate is the number of bits that are conveyed or processed per unit of time.</summary>
    class BitRate : public UnitsNetBase
    {
    public:
        constexpr explicit BitRate(
            const un_scalar_t value,
            const BitRateUnit unit = BitRateUnit::BitsPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == BitRateUnit::BitsPerSecond)
            {
                base_value_ = value;
                base_value_exists_ = true;
            }
            else
            {
                base_value_ = 0;
                base_value_exists_ = false;
            }
        }
        
        constexpr void create_base_value_if_needed() const noexcept
        {
            if(!base_value_exists_)
            {
                base_value_ = convert_to_base(value_, value_unit_type_);
                base_value_exists_ = true;
            }
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            create_base_value_if_needed();    
            return base_value_;    
        }

        [[nodiscard]] constexpr un_scalar_t value(const BitRateUnit unit) const
        {
            return convert_from_base(unit);
        }

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
            return convert_from_base(BitRateUnit::BitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_bits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::BitsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t kilobits_per_second() const
        {
            return convert_from_base(BitRateUnit::KilobitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_kilobits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::KilobitsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t megabits_per_second() const
        {
            return convert_from_base(BitRateUnit::MegabitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_megabits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::MegabitsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t gigabits_per_second() const
        {
            return convert_from_base(BitRateUnit::GigabitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_gigabits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::GigabitsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t terabits_per_second() const
        {
            return convert_from_base(BitRateUnit::TerabitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_terabits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::TerabitsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t petabits_per_second() const
        {
            return convert_from_base(BitRateUnit::PetabitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_petabits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::PetabitsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t exabits_per_second() const
        {
            return convert_from_base(BitRateUnit::ExabitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_exabits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::ExabitsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t kibibits_per_second() const
        {
            return convert_from_base(BitRateUnit::KibibitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_kibibits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::KibibitsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t mebibits_per_second() const
        {
            return convert_from_base(BitRateUnit::MebibitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_mebibits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::MebibitsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t gibibits_per_second() const
        {
            return convert_from_base(BitRateUnit::GibibitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_gibibits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::GibibitsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t tebibits_per_second() const
        {
            return convert_from_base(BitRateUnit::TebibitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_tebibits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::TebibitsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t pebibits_per_second() const
        {
            return convert_from_base(BitRateUnit::PebibitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_pebibits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::PebibitsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t exbibits_per_second() const
        {
            return convert_from_base(BitRateUnit::ExbibitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_exbibits_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::ExbibitsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t bytes_per_second() const
        {
            return convert_from_base(BitRateUnit::BytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_bytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::BytesPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t kilobytes_per_second() const
        {
            return convert_from_base(BitRateUnit::KilobytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_kilobytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::KilobytesPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t megabytes_per_second() const
        {
            return convert_from_base(BitRateUnit::MegabytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_megabytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::MegabytesPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t gigabytes_per_second() const
        {
            return convert_from_base(BitRateUnit::GigabytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_gigabytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::GigabytesPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t terabytes_per_second() const
        {
            return convert_from_base(BitRateUnit::TerabytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_terabytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::TerabytesPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t petabytes_per_second() const
        {
            return convert_from_base(BitRateUnit::PetabytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_petabytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::PetabytesPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t exabytes_per_second() const
        {
            return convert_from_base(BitRateUnit::ExabytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_exabytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::ExabytesPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t kibibytes_per_second() const
        {
            return convert_from_base(BitRateUnit::KibibytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_kibibytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::KibibytesPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t mebibytes_per_second() const
        {
            return convert_from_base(BitRateUnit::MebibytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_mebibytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::MebibytesPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t gibibytes_per_second() const
        {
            return convert_from_base(BitRateUnit::GibibytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_gibibytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::GibibytesPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t tebibytes_per_second() const
        {
            return convert_from_base(BitRateUnit::TebibytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_tebibytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::TebibytesPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t pebibytes_per_second() const
        {
            return convert_from_base(BitRateUnit::PebibytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_pebibytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::PebibytesPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t exbibytes_per_second() const
        {
            return convert_from_base(BitRateUnit::ExbibytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_exbibytes_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::ExbibytesPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t octets_per_second() const
        {
            return convert_from_base(BitRateUnit::OctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_octets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::OctetsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t kilooctets_per_second() const
        {
            return convert_from_base(BitRateUnit::KilooctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_kilooctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::KilooctetsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t megaoctets_per_second() const
        {
            return convert_from_base(BitRateUnit::MegaoctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_megaoctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::MegaoctetsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t gigaoctets_per_second() const
        {
            return convert_from_base(BitRateUnit::GigaoctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_gigaoctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::GigaoctetsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t teraoctets_per_second() const
        {
            return convert_from_base(BitRateUnit::TeraoctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_teraoctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::TeraoctetsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t petaoctets_per_second() const
        {
            return convert_from_base(BitRateUnit::PetaoctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_petaoctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::PetaoctetsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t exaoctets_per_second() const
        {
            return convert_from_base(BitRateUnit::ExaoctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_exaoctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::ExaoctetsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t kibioctets_per_second() const
        {
            return convert_from_base(BitRateUnit::KibioctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_kibioctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::KibioctetsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t mebioctets_per_second() const
        {
            return convert_from_base(BitRateUnit::MebioctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_mebioctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::MebioctetsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t gibioctets_per_second() const
        {
            return convert_from_base(BitRateUnit::GibioctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_gibioctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::GibioctetsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t tebioctets_per_second() const
        {
            return convert_from_base(BitRateUnit::TebioctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_tebioctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::TebioctetsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t pebioctets_per_second() const
        {
            return convert_from_base(BitRateUnit::PebioctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_pebioctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::PebioctetsPerSecond);
        }


        [[nodiscard]] constexpr un_scalar_t exbioctets_per_second() const
        {
            return convert_from_base(BitRateUnit::ExbioctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_exbioctets_per_second(const un_scalar_t value)
        {
            return BitRate(value, BitRateUnit::ExbioctetsPerSecond);
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

            case BitRateUnit::BitsPerSecond:
                return value;

            case BitRateUnit::KilobitsPerSecond:
                return (value * static_cast<un_scalar_t>(1e3));

            case BitRateUnit::MegabitsPerSecond:
                return (value * static_cast<un_scalar_t>(1e6));

            case BitRateUnit::GigabitsPerSecond:
                return (value * static_cast<un_scalar_t>(1e9));

            case BitRateUnit::TerabitsPerSecond:
                return (value * static_cast<un_scalar_t>(1e12));

            case BitRateUnit::PetabitsPerSecond:
                return (value * static_cast<un_scalar_t>(1e15));

            case BitRateUnit::ExabitsPerSecond:
                return (value * static_cast<un_scalar_t>(1e18));

            case BitRateUnit::KibibitsPerSecond:
                return (value * static_cast<un_scalar_t>(1024.0));

            case BitRateUnit::MebibitsPerSecond:
                return (value * static_cast<un_scalar_t>(1048576.0));

            case BitRateUnit::GibibitsPerSecond:
                return (value * static_cast<un_scalar_t>(1073741824.0));

            case BitRateUnit::TebibitsPerSecond:
                return (value * static_cast<un_scalar_t>(1099511627776.0));

            case BitRateUnit::PebibitsPerSecond:
                return (value * static_cast<un_scalar_t>(1125899906842624.0));

            case BitRateUnit::ExbibitsPerSecond:
                return (value * static_cast<un_scalar_t>(1152921504606846976.0));

            case BitRateUnit::BytesPerSecond:
                return value * static_cast<un_scalar_t>(8);

            case BitRateUnit::KilobytesPerSecond:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::MegabytesPerSecond:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::GigabytesPerSecond:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::TerabytesPerSecond:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::PetabytesPerSecond:
                return (value * static_cast<un_scalar_t>(1e15)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::ExabytesPerSecond:
                return (value * static_cast<un_scalar_t>(1e18)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::KibibytesPerSecond:
                return (value * static_cast<un_scalar_t>(1024.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::MebibytesPerSecond:
                return (value * static_cast<un_scalar_t>(1048576.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::GibibytesPerSecond:
                return (value * static_cast<un_scalar_t>(1073741824.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::TebibytesPerSecond:
                return (value * static_cast<un_scalar_t>(1099511627776.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::PebibytesPerSecond:
                return (value * static_cast<un_scalar_t>(1125899906842624.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::ExbibytesPerSecond:
                return (value * static_cast<un_scalar_t>(1152921504606846976.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::OctetsPerSecond:
                return value * static_cast<un_scalar_t>(8);

            case BitRateUnit::KilooctetsPerSecond:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::MegaoctetsPerSecond:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::GigaoctetsPerSecond:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::TeraoctetsPerSecond:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::PetaoctetsPerSecond:
                return (value * static_cast<un_scalar_t>(1e15)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::ExaoctetsPerSecond:
                return (value * static_cast<un_scalar_t>(1e18)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::KibioctetsPerSecond:
                return (value * static_cast<un_scalar_t>(1024.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::MebioctetsPerSecond:
                return (value * static_cast<un_scalar_t>(1048576.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::GibioctetsPerSecond:
                return (value * static_cast<un_scalar_t>(1073741824.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::TebioctetsPerSecond:
                return (value * static_cast<un_scalar_t>(1099511627776.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::PebioctetsPerSecond:
                return (value * static_cast<un_scalar_t>(1125899906842624.0)) * static_cast<un_scalar_t>(8);

            case BitRateUnit::ExbioctetsPerSecond:
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
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case BitRateUnit::BitsPerSecond:
                return base_value_;

            case BitRateUnit::KilobitsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e3);

            case BitRateUnit::MegabitsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e6);

            case BitRateUnit::GigabitsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e9);

            case BitRateUnit::TerabitsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e12);

            case BitRateUnit::PetabitsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e15);

            case BitRateUnit::ExabitsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1e18);

            case BitRateUnit::KibibitsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1024.0);

            case BitRateUnit::MebibitsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1048576.0);

            case BitRateUnit::GibibitsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1073741824.0);

            case BitRateUnit::TebibitsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1099511627776.0);

            case BitRateUnit::PebibitsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1125899906842624.0);

            case BitRateUnit::ExbibitsPerSecond:
                return (base_value_) / static_cast<un_scalar_t>(1152921504606846976.0);

            case BitRateUnit::BytesPerSecond:
                return base_value_ / static_cast<un_scalar_t>(8);

            case BitRateUnit::KilobytesPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e3);

            case BitRateUnit::MegabytesPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e6);

            case BitRateUnit::GigabytesPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e9);

            case BitRateUnit::TerabytesPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e12);

            case BitRateUnit::PetabytesPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e15);

            case BitRateUnit::ExabytesPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e18);

            case BitRateUnit::KibibytesPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1024.0);

            case BitRateUnit::MebibytesPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1048576.0);

            case BitRateUnit::GibibytesPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1073741824.0);

            case BitRateUnit::TebibytesPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1099511627776.0);

            case BitRateUnit::PebibytesPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1125899906842624.0);

            case BitRateUnit::ExbibytesPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1152921504606846976.0);

            case BitRateUnit::OctetsPerSecond:
                return base_value_ / static_cast<un_scalar_t>(8);

            case BitRateUnit::KilooctetsPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e3);

            case BitRateUnit::MegaoctetsPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e6);

            case BitRateUnit::GigaoctetsPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e9);

            case BitRateUnit::TeraoctetsPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e12);

            case BitRateUnit::PetaoctetsPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e15);

            case BitRateUnit::ExaoctetsPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e18);

            case BitRateUnit::KibioctetsPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1024.0);

            case BitRateUnit::MebioctetsPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1048576.0);

            case BitRateUnit::GibioctetsPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1073741824.0);

            case BitRateUnit::TebioctetsPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1099511627776.0);

            case BitRateUnit::PebioctetsPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1125899906842624.0);

            case BitRateUnit::ExbioctetsPerSecond:
                return (base_value_ / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1152921504606846976.0);

            }

            throw std::invalid_argument("Unknown BitRate unit.");
        }

        un_scalar_t value_;
        BitRateUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
