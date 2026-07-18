#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class BitRateUnit : std::uint16_t
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
    class BitRate
    {
    public:
        constexpr explicit BitRate(
            double value,
            BitRateUnit unit = BitRateUnit::BitsPerSecond)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(BitRateUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr BitRate operator+(BitRate other) const noexcept
        {
            return BitRate(value_ + other.value_);
        }

        [[nodiscard]] constexpr BitRate operator-(BitRate other) const noexcept
        {
            return BitRate(value_ - other.value_);
        }

        [[nodiscard]] constexpr BitRate operator*(double scalar) const noexcept
        {
            return BitRate(value_ * scalar);
        }

        [[nodiscard]] constexpr BitRate operator/(double scalar) const noexcept
        {
            return BitRate(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(BitRate other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(BitRate other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double bits_per_second() const
        {
            return convert_from_base(BitRateUnit::BitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_bits_per_second(double value)
        {
            return BitRate(value, BitRateUnit::BitsPerSecond);
        }


        [[nodiscard]] constexpr double kilobits_per_second() const
        {
            return convert_from_base(BitRateUnit::KilobitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_kilobits_per_second(double value)
        {
            return BitRate(value, BitRateUnit::KilobitsPerSecond);
        }


        [[nodiscard]] constexpr double megabits_per_second() const
        {
            return convert_from_base(BitRateUnit::MegabitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_megabits_per_second(double value)
        {
            return BitRate(value, BitRateUnit::MegabitsPerSecond);
        }


        [[nodiscard]] constexpr double gigabits_per_second() const
        {
            return convert_from_base(BitRateUnit::GigabitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_gigabits_per_second(double value)
        {
            return BitRate(value, BitRateUnit::GigabitsPerSecond);
        }


        [[nodiscard]] constexpr double terabits_per_second() const
        {
            return convert_from_base(BitRateUnit::TerabitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_terabits_per_second(double value)
        {
            return BitRate(value, BitRateUnit::TerabitsPerSecond);
        }


        [[nodiscard]] constexpr double petabits_per_second() const
        {
            return convert_from_base(BitRateUnit::PetabitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_petabits_per_second(double value)
        {
            return BitRate(value, BitRateUnit::PetabitsPerSecond);
        }


        [[nodiscard]] constexpr double exabits_per_second() const
        {
            return convert_from_base(BitRateUnit::ExabitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_exabits_per_second(double value)
        {
            return BitRate(value, BitRateUnit::ExabitsPerSecond);
        }


        [[nodiscard]] constexpr double kibibits_per_second() const
        {
            return convert_from_base(BitRateUnit::KibibitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_kibibits_per_second(double value)
        {
            return BitRate(value, BitRateUnit::KibibitsPerSecond);
        }


        [[nodiscard]] constexpr double mebibits_per_second() const
        {
            return convert_from_base(BitRateUnit::MebibitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_mebibits_per_second(double value)
        {
            return BitRate(value, BitRateUnit::MebibitsPerSecond);
        }


        [[nodiscard]] constexpr double gibibits_per_second() const
        {
            return convert_from_base(BitRateUnit::GibibitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_gibibits_per_second(double value)
        {
            return BitRate(value, BitRateUnit::GibibitsPerSecond);
        }


        [[nodiscard]] constexpr double tebibits_per_second() const
        {
            return convert_from_base(BitRateUnit::TebibitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_tebibits_per_second(double value)
        {
            return BitRate(value, BitRateUnit::TebibitsPerSecond);
        }


        [[nodiscard]] constexpr double pebibits_per_second() const
        {
            return convert_from_base(BitRateUnit::PebibitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_pebibits_per_second(double value)
        {
            return BitRate(value, BitRateUnit::PebibitsPerSecond);
        }


        [[nodiscard]] constexpr double exbibits_per_second() const
        {
            return convert_from_base(BitRateUnit::ExbibitsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_exbibits_per_second(double value)
        {
            return BitRate(value, BitRateUnit::ExbibitsPerSecond);
        }


        [[nodiscard]] constexpr double bytes_per_second() const
        {
            return convert_from_base(BitRateUnit::BytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_bytes_per_second(double value)
        {
            return BitRate(value, BitRateUnit::BytesPerSecond);
        }


        [[nodiscard]] constexpr double kilobytes_per_second() const
        {
            return convert_from_base(BitRateUnit::KilobytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_kilobytes_per_second(double value)
        {
            return BitRate(value, BitRateUnit::KilobytesPerSecond);
        }


        [[nodiscard]] constexpr double megabytes_per_second() const
        {
            return convert_from_base(BitRateUnit::MegabytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_megabytes_per_second(double value)
        {
            return BitRate(value, BitRateUnit::MegabytesPerSecond);
        }


        [[nodiscard]] constexpr double gigabytes_per_second() const
        {
            return convert_from_base(BitRateUnit::GigabytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_gigabytes_per_second(double value)
        {
            return BitRate(value, BitRateUnit::GigabytesPerSecond);
        }


        [[nodiscard]] constexpr double terabytes_per_second() const
        {
            return convert_from_base(BitRateUnit::TerabytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_terabytes_per_second(double value)
        {
            return BitRate(value, BitRateUnit::TerabytesPerSecond);
        }


        [[nodiscard]] constexpr double petabytes_per_second() const
        {
            return convert_from_base(BitRateUnit::PetabytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_petabytes_per_second(double value)
        {
            return BitRate(value, BitRateUnit::PetabytesPerSecond);
        }


        [[nodiscard]] constexpr double exabytes_per_second() const
        {
            return convert_from_base(BitRateUnit::ExabytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_exabytes_per_second(double value)
        {
            return BitRate(value, BitRateUnit::ExabytesPerSecond);
        }


        [[nodiscard]] constexpr double kibibytes_per_second() const
        {
            return convert_from_base(BitRateUnit::KibibytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_kibibytes_per_second(double value)
        {
            return BitRate(value, BitRateUnit::KibibytesPerSecond);
        }


        [[nodiscard]] constexpr double mebibytes_per_second() const
        {
            return convert_from_base(BitRateUnit::MebibytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_mebibytes_per_second(double value)
        {
            return BitRate(value, BitRateUnit::MebibytesPerSecond);
        }


        [[nodiscard]] constexpr double gibibytes_per_second() const
        {
            return convert_from_base(BitRateUnit::GibibytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_gibibytes_per_second(double value)
        {
            return BitRate(value, BitRateUnit::GibibytesPerSecond);
        }


        [[nodiscard]] constexpr double tebibytes_per_second() const
        {
            return convert_from_base(BitRateUnit::TebibytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_tebibytes_per_second(double value)
        {
            return BitRate(value, BitRateUnit::TebibytesPerSecond);
        }


        [[nodiscard]] constexpr double pebibytes_per_second() const
        {
            return convert_from_base(BitRateUnit::PebibytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_pebibytes_per_second(double value)
        {
            return BitRate(value, BitRateUnit::PebibytesPerSecond);
        }


        [[nodiscard]] constexpr double exbibytes_per_second() const
        {
            return convert_from_base(BitRateUnit::ExbibytesPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_exbibytes_per_second(double value)
        {
            return BitRate(value, BitRateUnit::ExbibytesPerSecond);
        }


        [[nodiscard]] constexpr double octets_per_second() const
        {
            return convert_from_base(BitRateUnit::OctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_octets_per_second(double value)
        {
            return BitRate(value, BitRateUnit::OctetsPerSecond);
        }


        [[nodiscard]] constexpr double kilooctets_per_second() const
        {
            return convert_from_base(BitRateUnit::KilooctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_kilooctets_per_second(double value)
        {
            return BitRate(value, BitRateUnit::KilooctetsPerSecond);
        }


        [[nodiscard]] constexpr double megaoctets_per_second() const
        {
            return convert_from_base(BitRateUnit::MegaoctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_megaoctets_per_second(double value)
        {
            return BitRate(value, BitRateUnit::MegaoctetsPerSecond);
        }


        [[nodiscard]] constexpr double gigaoctets_per_second() const
        {
            return convert_from_base(BitRateUnit::GigaoctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_gigaoctets_per_second(double value)
        {
            return BitRate(value, BitRateUnit::GigaoctetsPerSecond);
        }


        [[nodiscard]] constexpr double teraoctets_per_second() const
        {
            return convert_from_base(BitRateUnit::TeraoctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_teraoctets_per_second(double value)
        {
            return BitRate(value, BitRateUnit::TeraoctetsPerSecond);
        }


        [[nodiscard]] constexpr double petaoctets_per_second() const
        {
            return convert_from_base(BitRateUnit::PetaoctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_petaoctets_per_second(double value)
        {
            return BitRate(value, BitRateUnit::PetaoctetsPerSecond);
        }


        [[nodiscard]] constexpr double exaoctets_per_second() const
        {
            return convert_from_base(BitRateUnit::ExaoctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_exaoctets_per_second(double value)
        {
            return BitRate(value, BitRateUnit::ExaoctetsPerSecond);
        }


        [[nodiscard]] constexpr double kibioctets_per_second() const
        {
            return convert_from_base(BitRateUnit::KibioctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_kibioctets_per_second(double value)
        {
            return BitRate(value, BitRateUnit::KibioctetsPerSecond);
        }


        [[nodiscard]] constexpr double mebioctets_per_second() const
        {
            return convert_from_base(BitRateUnit::MebioctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_mebioctets_per_second(double value)
        {
            return BitRate(value, BitRateUnit::MebioctetsPerSecond);
        }


        [[nodiscard]] constexpr double gibioctets_per_second() const
        {
            return convert_from_base(BitRateUnit::GibioctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_gibioctets_per_second(double value)
        {
            return BitRate(value, BitRateUnit::GibioctetsPerSecond);
        }


        [[nodiscard]] constexpr double tebioctets_per_second() const
        {
            return convert_from_base(BitRateUnit::TebioctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_tebioctets_per_second(double value)
        {
            return BitRate(value, BitRateUnit::TebioctetsPerSecond);
        }


        [[nodiscard]] constexpr double pebioctets_per_second() const
        {
            return convert_from_base(BitRateUnit::PebioctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_pebioctets_per_second(double value)
        {
            return BitRate(value, BitRateUnit::PebioctetsPerSecond);
        }


        [[nodiscard]] constexpr double exbioctets_per_second() const
        {
            return convert_from_base(BitRateUnit::ExbioctetsPerSecond);
        }

        [[nodiscard]] static constexpr BitRate from_exbioctets_per_second(double value)
        {
            return BitRate(value, BitRateUnit::ExbioctetsPerSecond);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, BitRateUnit unit)
        {
            switch (unit)
            {

            case BitRateUnit::BitsPerSecond:
                return value;

            case BitRateUnit::KilobitsPerSecond:
                return (value * 1e3);

            case BitRateUnit::MegabitsPerSecond:
                return (value * 1e6);

            case BitRateUnit::GigabitsPerSecond:
                return (value * 1e9);

            case BitRateUnit::TerabitsPerSecond:
                return (value * 1e12);

            case BitRateUnit::PetabitsPerSecond:
                return (value * 1e15);

            case BitRateUnit::ExabitsPerSecond:
                return (value * 1e18);

            case BitRateUnit::KibibitsPerSecond:
                return (value * 1024.0);

            case BitRateUnit::MebibitsPerSecond:
                return (value * 1048576.0);

            case BitRateUnit::GibibitsPerSecond:
                return (value * 1073741824.0);

            case BitRateUnit::TebibitsPerSecond:
                return (value * 1099511627776.0);

            case BitRateUnit::PebibitsPerSecond:
                return (value * 1125899906842624.0);

            case BitRateUnit::ExbibitsPerSecond:
                return (value * 1152921504606846976.0);

            case BitRateUnit::BytesPerSecond:
                return value * 8;

            case BitRateUnit::KilobytesPerSecond:
                return (value * 1e3) * 8;

            case BitRateUnit::MegabytesPerSecond:
                return (value * 1e6) * 8;

            case BitRateUnit::GigabytesPerSecond:
                return (value * 1e9) * 8;

            case BitRateUnit::TerabytesPerSecond:
                return (value * 1e12) * 8;

            case BitRateUnit::PetabytesPerSecond:
                return (value * 1e15) * 8;

            case BitRateUnit::ExabytesPerSecond:
                return (value * 1e18) * 8;

            case BitRateUnit::KibibytesPerSecond:
                return (value * 1024.0) * 8;

            case BitRateUnit::MebibytesPerSecond:
                return (value * 1048576.0) * 8;

            case BitRateUnit::GibibytesPerSecond:
                return (value * 1073741824.0) * 8;

            case BitRateUnit::TebibytesPerSecond:
                return (value * 1099511627776.0) * 8;

            case BitRateUnit::PebibytesPerSecond:
                return (value * 1125899906842624.0) * 8;

            case BitRateUnit::ExbibytesPerSecond:
                return (value * 1152921504606846976.0) * 8;

            case BitRateUnit::OctetsPerSecond:
                return value * 8;

            case BitRateUnit::KilooctetsPerSecond:
                return (value * 1e3) * 8;

            case BitRateUnit::MegaoctetsPerSecond:
                return (value * 1e6) * 8;

            case BitRateUnit::GigaoctetsPerSecond:
                return (value * 1e9) * 8;

            case BitRateUnit::TeraoctetsPerSecond:
                return (value * 1e12) * 8;

            case BitRateUnit::PetaoctetsPerSecond:
                return (value * 1e15) * 8;

            case BitRateUnit::ExaoctetsPerSecond:
                return (value * 1e18) * 8;

            case BitRateUnit::KibioctetsPerSecond:
                return (value * 1024.0) * 8;

            case BitRateUnit::MebioctetsPerSecond:
                return (value * 1048576.0) * 8;

            case BitRateUnit::GibioctetsPerSecond:
                return (value * 1073741824.0) * 8;

            case BitRateUnit::TebioctetsPerSecond:
                return (value * 1099511627776.0) * 8;

            case BitRateUnit::PebioctetsPerSecond:
                return (value * 1125899906842624.0) * 8;

            case BitRateUnit::ExbioctetsPerSecond:
                return (value * 1152921504606846976.0) * 8;

            }

            throw std::invalid_argument("Unknown BitRate unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(BitRateUnit unit) const
        {
            switch (unit)
            {

            case BitRateUnit::BitsPerSecond:
                return value_;

            case BitRateUnit::KilobitsPerSecond:
                return (value_) / 1e3;

            case BitRateUnit::MegabitsPerSecond:
                return (value_) / 1e6;

            case BitRateUnit::GigabitsPerSecond:
                return (value_) / 1e9;

            case BitRateUnit::TerabitsPerSecond:
                return (value_) / 1e12;

            case BitRateUnit::PetabitsPerSecond:
                return (value_) / 1e15;

            case BitRateUnit::ExabitsPerSecond:
                return (value_) / 1e18;

            case BitRateUnit::KibibitsPerSecond:
                return (value_) / 1024.0;

            case BitRateUnit::MebibitsPerSecond:
                return (value_) / 1048576.0;

            case BitRateUnit::GibibitsPerSecond:
                return (value_) / 1073741824.0;

            case BitRateUnit::TebibitsPerSecond:
                return (value_) / 1099511627776.0;

            case BitRateUnit::PebibitsPerSecond:
                return (value_) / 1125899906842624.0;

            case BitRateUnit::ExbibitsPerSecond:
                return (value_) / 1152921504606846976.0;

            case BitRateUnit::BytesPerSecond:
                return value_ / 8;

            case BitRateUnit::KilobytesPerSecond:
                return (value_ / 8) / 1e3;

            case BitRateUnit::MegabytesPerSecond:
                return (value_ / 8) / 1e6;

            case BitRateUnit::GigabytesPerSecond:
                return (value_ / 8) / 1e9;

            case BitRateUnit::TerabytesPerSecond:
                return (value_ / 8) / 1e12;

            case BitRateUnit::PetabytesPerSecond:
                return (value_ / 8) / 1e15;

            case BitRateUnit::ExabytesPerSecond:
                return (value_ / 8) / 1e18;

            case BitRateUnit::KibibytesPerSecond:
                return (value_ / 8) / 1024.0;

            case BitRateUnit::MebibytesPerSecond:
                return (value_ / 8) / 1048576.0;

            case BitRateUnit::GibibytesPerSecond:
                return (value_ / 8) / 1073741824.0;

            case BitRateUnit::TebibytesPerSecond:
                return (value_ / 8) / 1099511627776.0;

            case BitRateUnit::PebibytesPerSecond:
                return (value_ / 8) / 1125899906842624.0;

            case BitRateUnit::ExbibytesPerSecond:
                return (value_ / 8) / 1152921504606846976.0;

            case BitRateUnit::OctetsPerSecond:
                return value_ / 8;

            case BitRateUnit::KilooctetsPerSecond:
                return (value_ / 8) / 1e3;

            case BitRateUnit::MegaoctetsPerSecond:
                return (value_ / 8) / 1e6;

            case BitRateUnit::GigaoctetsPerSecond:
                return (value_ / 8) / 1e9;

            case BitRateUnit::TeraoctetsPerSecond:
                return (value_ / 8) / 1e12;

            case BitRateUnit::PetaoctetsPerSecond:
                return (value_ / 8) / 1e15;

            case BitRateUnit::ExaoctetsPerSecond:
                return (value_ / 8) / 1e18;

            case BitRateUnit::KibioctetsPerSecond:
                return (value_ / 8) / 1024.0;

            case BitRateUnit::MebioctetsPerSecond:
                return (value_ / 8) / 1048576.0;

            case BitRateUnit::GibioctetsPerSecond:
                return (value_ / 8) / 1073741824.0;

            case BitRateUnit::TebioctetsPerSecond:
                return (value_ / 8) / 1099511627776.0;

            case BitRateUnit::PebioctetsPerSecond:
                return (value_ / 8) / 1125899906842624.0;

            case BitRateUnit::ExbioctetsPerSecond:
                return (value_ / 8) / 1152921504606846976.0;

            }

            throw std::invalid_argument("Unknown BitRate unit.");
        }

        double value_;
    };
}
