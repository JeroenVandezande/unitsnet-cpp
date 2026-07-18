#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class InformationUnit : std::uint16_t
    {
        Bytes,
        Kilobytes,
        Megabytes,
        Gigabytes,
        Terabytes,
        Petabytes,
        Exabytes,
        Kibibytes,
        Mebibytes,
        Gibibytes,
        Tebibytes,
        Pebibytes,
        Exbibytes,
        Octets,
        Kilooctets,
        Megaoctets,
        Gigaoctets,
        Teraoctets,
        Petaoctets,
        Exaoctets,
        Kibioctets,
        Mebioctets,
        Gibioctets,
        Tebioctets,
        Pebioctets,
        Exbioctets,
        Bits,
        Kilobits,
        Megabits,
        Gigabits,
        Terabits,
        Petabits,
        Exabits,
        Kibibits,
        Mebibits,
        Gibibits,
        Tebibits,
        Pebibits,
        Exbibits,
    };

    /// <summary>In computing and telecommunications, a unit of information is the capacity of some standard data storage system or communication channel, used to measure the capacities of other systems and channels. In information theory, units of information are also used to measure the information contents or entropy of random variables.</summary>
    class Information
    {
    public:
        constexpr explicit Information(
            double value,
            InformationUnit unit = InformationUnit::Bits)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(InformationUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Information operator+(Information other) const noexcept
        {
            return Information(value_ + other.value_);
        }

        [[nodiscard]] constexpr Information operator-(Information other) const noexcept
        {
            return Information(value_ - other.value_);
        }

        [[nodiscard]] constexpr Information operator*(double scalar) const noexcept
        {
            return Information(value_ * scalar);
        }

        [[nodiscard]] constexpr Information operator/(double scalar) const noexcept
        {
            return Information(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Information other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Information other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double bytes() const
        {
            return convert_from_base(InformationUnit::Bytes);
        }

        [[nodiscard]] static constexpr Information from_bytes(double value)
        {
            return Information(value, InformationUnit::Bytes);
        }


        [[nodiscard]] constexpr double kilobytes() const
        {
            return convert_from_base(InformationUnit::Kilobytes);
        }

        [[nodiscard]] static constexpr Information from_kilobytes(double value)
        {
            return Information(value, InformationUnit::Kilobytes);
        }


        [[nodiscard]] constexpr double megabytes() const
        {
            return convert_from_base(InformationUnit::Megabytes);
        }

        [[nodiscard]] static constexpr Information from_megabytes(double value)
        {
            return Information(value, InformationUnit::Megabytes);
        }


        [[nodiscard]] constexpr double gigabytes() const
        {
            return convert_from_base(InformationUnit::Gigabytes);
        }

        [[nodiscard]] static constexpr Information from_gigabytes(double value)
        {
            return Information(value, InformationUnit::Gigabytes);
        }


        [[nodiscard]] constexpr double terabytes() const
        {
            return convert_from_base(InformationUnit::Terabytes);
        }

        [[nodiscard]] static constexpr Information from_terabytes(double value)
        {
            return Information(value, InformationUnit::Terabytes);
        }


        [[nodiscard]] constexpr double petabytes() const
        {
            return convert_from_base(InformationUnit::Petabytes);
        }

        [[nodiscard]] static constexpr Information from_petabytes(double value)
        {
            return Information(value, InformationUnit::Petabytes);
        }


        [[nodiscard]] constexpr double exabytes() const
        {
            return convert_from_base(InformationUnit::Exabytes);
        }

        [[nodiscard]] static constexpr Information from_exabytes(double value)
        {
            return Information(value, InformationUnit::Exabytes);
        }


        [[nodiscard]] constexpr double kibibytes() const
        {
            return convert_from_base(InformationUnit::Kibibytes);
        }

        [[nodiscard]] static constexpr Information from_kibibytes(double value)
        {
            return Information(value, InformationUnit::Kibibytes);
        }


        [[nodiscard]] constexpr double mebibytes() const
        {
            return convert_from_base(InformationUnit::Mebibytes);
        }

        [[nodiscard]] static constexpr Information from_mebibytes(double value)
        {
            return Information(value, InformationUnit::Mebibytes);
        }


        [[nodiscard]] constexpr double gibibytes() const
        {
            return convert_from_base(InformationUnit::Gibibytes);
        }

        [[nodiscard]] static constexpr Information from_gibibytes(double value)
        {
            return Information(value, InformationUnit::Gibibytes);
        }


        [[nodiscard]] constexpr double tebibytes() const
        {
            return convert_from_base(InformationUnit::Tebibytes);
        }

        [[nodiscard]] static constexpr Information from_tebibytes(double value)
        {
            return Information(value, InformationUnit::Tebibytes);
        }


        [[nodiscard]] constexpr double pebibytes() const
        {
            return convert_from_base(InformationUnit::Pebibytes);
        }

        [[nodiscard]] static constexpr Information from_pebibytes(double value)
        {
            return Information(value, InformationUnit::Pebibytes);
        }


        [[nodiscard]] constexpr double exbibytes() const
        {
            return convert_from_base(InformationUnit::Exbibytes);
        }

        [[nodiscard]] static constexpr Information from_exbibytes(double value)
        {
            return Information(value, InformationUnit::Exbibytes);
        }


        [[nodiscard]] constexpr double octets() const
        {
            return convert_from_base(InformationUnit::Octets);
        }

        [[nodiscard]] static constexpr Information from_octets(double value)
        {
            return Information(value, InformationUnit::Octets);
        }


        [[nodiscard]] constexpr double kilooctets() const
        {
            return convert_from_base(InformationUnit::Kilooctets);
        }

        [[nodiscard]] static constexpr Information from_kilooctets(double value)
        {
            return Information(value, InformationUnit::Kilooctets);
        }


        [[nodiscard]] constexpr double megaoctets() const
        {
            return convert_from_base(InformationUnit::Megaoctets);
        }

        [[nodiscard]] static constexpr Information from_megaoctets(double value)
        {
            return Information(value, InformationUnit::Megaoctets);
        }


        [[nodiscard]] constexpr double gigaoctets() const
        {
            return convert_from_base(InformationUnit::Gigaoctets);
        }

        [[nodiscard]] static constexpr Information from_gigaoctets(double value)
        {
            return Information(value, InformationUnit::Gigaoctets);
        }


        [[nodiscard]] constexpr double teraoctets() const
        {
            return convert_from_base(InformationUnit::Teraoctets);
        }

        [[nodiscard]] static constexpr Information from_teraoctets(double value)
        {
            return Information(value, InformationUnit::Teraoctets);
        }


        [[nodiscard]] constexpr double petaoctets() const
        {
            return convert_from_base(InformationUnit::Petaoctets);
        }

        [[nodiscard]] static constexpr Information from_petaoctets(double value)
        {
            return Information(value, InformationUnit::Petaoctets);
        }


        [[nodiscard]] constexpr double exaoctets() const
        {
            return convert_from_base(InformationUnit::Exaoctets);
        }

        [[nodiscard]] static constexpr Information from_exaoctets(double value)
        {
            return Information(value, InformationUnit::Exaoctets);
        }


        [[nodiscard]] constexpr double kibioctets() const
        {
            return convert_from_base(InformationUnit::Kibioctets);
        }

        [[nodiscard]] static constexpr Information from_kibioctets(double value)
        {
            return Information(value, InformationUnit::Kibioctets);
        }


        [[nodiscard]] constexpr double mebioctets() const
        {
            return convert_from_base(InformationUnit::Mebioctets);
        }

        [[nodiscard]] static constexpr Information from_mebioctets(double value)
        {
            return Information(value, InformationUnit::Mebioctets);
        }


        [[nodiscard]] constexpr double gibioctets() const
        {
            return convert_from_base(InformationUnit::Gibioctets);
        }

        [[nodiscard]] static constexpr Information from_gibioctets(double value)
        {
            return Information(value, InformationUnit::Gibioctets);
        }


        [[nodiscard]] constexpr double tebioctets() const
        {
            return convert_from_base(InformationUnit::Tebioctets);
        }

        [[nodiscard]] static constexpr Information from_tebioctets(double value)
        {
            return Information(value, InformationUnit::Tebioctets);
        }


        [[nodiscard]] constexpr double pebioctets() const
        {
            return convert_from_base(InformationUnit::Pebioctets);
        }

        [[nodiscard]] static constexpr Information from_pebioctets(double value)
        {
            return Information(value, InformationUnit::Pebioctets);
        }


        [[nodiscard]] constexpr double exbioctets() const
        {
            return convert_from_base(InformationUnit::Exbioctets);
        }

        [[nodiscard]] static constexpr Information from_exbioctets(double value)
        {
            return Information(value, InformationUnit::Exbioctets);
        }


        [[nodiscard]] constexpr double bits() const
        {
            return convert_from_base(InformationUnit::Bits);
        }

        [[nodiscard]] static constexpr Information from_bits(double value)
        {
            return Information(value, InformationUnit::Bits);
        }


        [[nodiscard]] constexpr double kilobits() const
        {
            return convert_from_base(InformationUnit::Kilobits);
        }

        [[nodiscard]] static constexpr Information from_kilobits(double value)
        {
            return Information(value, InformationUnit::Kilobits);
        }


        [[nodiscard]] constexpr double megabits() const
        {
            return convert_from_base(InformationUnit::Megabits);
        }

        [[nodiscard]] static constexpr Information from_megabits(double value)
        {
            return Information(value, InformationUnit::Megabits);
        }


        [[nodiscard]] constexpr double gigabits() const
        {
            return convert_from_base(InformationUnit::Gigabits);
        }

        [[nodiscard]] static constexpr Information from_gigabits(double value)
        {
            return Information(value, InformationUnit::Gigabits);
        }


        [[nodiscard]] constexpr double terabits() const
        {
            return convert_from_base(InformationUnit::Terabits);
        }

        [[nodiscard]] static constexpr Information from_terabits(double value)
        {
            return Information(value, InformationUnit::Terabits);
        }


        [[nodiscard]] constexpr double petabits() const
        {
            return convert_from_base(InformationUnit::Petabits);
        }

        [[nodiscard]] static constexpr Information from_petabits(double value)
        {
            return Information(value, InformationUnit::Petabits);
        }


        [[nodiscard]] constexpr double exabits() const
        {
            return convert_from_base(InformationUnit::Exabits);
        }

        [[nodiscard]] static constexpr Information from_exabits(double value)
        {
            return Information(value, InformationUnit::Exabits);
        }


        [[nodiscard]] constexpr double kibibits() const
        {
            return convert_from_base(InformationUnit::Kibibits);
        }

        [[nodiscard]] static constexpr Information from_kibibits(double value)
        {
            return Information(value, InformationUnit::Kibibits);
        }


        [[nodiscard]] constexpr double mebibits() const
        {
            return convert_from_base(InformationUnit::Mebibits);
        }

        [[nodiscard]] static constexpr Information from_mebibits(double value)
        {
            return Information(value, InformationUnit::Mebibits);
        }


        [[nodiscard]] constexpr double gibibits() const
        {
            return convert_from_base(InformationUnit::Gibibits);
        }

        [[nodiscard]] static constexpr Information from_gibibits(double value)
        {
            return Information(value, InformationUnit::Gibibits);
        }


        [[nodiscard]] constexpr double tebibits() const
        {
            return convert_from_base(InformationUnit::Tebibits);
        }

        [[nodiscard]] static constexpr Information from_tebibits(double value)
        {
            return Information(value, InformationUnit::Tebibits);
        }


        [[nodiscard]] constexpr double pebibits() const
        {
            return convert_from_base(InformationUnit::Pebibits);
        }

        [[nodiscard]] static constexpr Information from_pebibits(double value)
        {
            return Information(value, InformationUnit::Pebibits);
        }


        [[nodiscard]] constexpr double exbibits() const
        {
            return convert_from_base(InformationUnit::Exbibits);
        }

        [[nodiscard]] static constexpr Information from_exbibits(double value)
        {
            return Information(value, InformationUnit::Exbibits);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, InformationUnit unit)
        {
            switch (unit)
            {

            case InformationUnit::Bytes:
                return value * 8;

            case InformationUnit::Kilobytes:
                return (value * 1e3) * 8;

            case InformationUnit::Megabytes:
                return (value * 1e6) * 8;

            case InformationUnit::Gigabytes:
                return (value * 1e9) * 8;

            case InformationUnit::Terabytes:
                return (value * 1e12) * 8;

            case InformationUnit::Petabytes:
                return (value * 1e15) * 8;

            case InformationUnit::Exabytes:
                return (value * 1e18) * 8;

            case InformationUnit::Kibibytes:
                return (value * 1024.0) * 8;

            case InformationUnit::Mebibytes:
                return (value * 1048576.0) * 8;

            case InformationUnit::Gibibytes:
                return (value * 1073741824.0) * 8;

            case InformationUnit::Tebibytes:
                return (value * 1099511627776.0) * 8;

            case InformationUnit::Pebibytes:
                return (value * 1125899906842624.0) * 8;

            case InformationUnit::Exbibytes:
                return (value * 1152921504606846976.0) * 8;

            case InformationUnit::Octets:
                return value * 8;

            case InformationUnit::Kilooctets:
                return (value * 1e3) * 8;

            case InformationUnit::Megaoctets:
                return (value * 1e6) * 8;

            case InformationUnit::Gigaoctets:
                return (value * 1e9) * 8;

            case InformationUnit::Teraoctets:
                return (value * 1e12) * 8;

            case InformationUnit::Petaoctets:
                return (value * 1e15) * 8;

            case InformationUnit::Exaoctets:
                return (value * 1e18) * 8;

            case InformationUnit::Kibioctets:
                return (value * 1024.0) * 8;

            case InformationUnit::Mebioctets:
                return (value * 1048576.0) * 8;

            case InformationUnit::Gibioctets:
                return (value * 1073741824.0) * 8;

            case InformationUnit::Tebioctets:
                return (value * 1099511627776.0) * 8;

            case InformationUnit::Pebioctets:
                return (value * 1125899906842624.0) * 8;

            case InformationUnit::Exbioctets:
                return (value * 1152921504606846976.0) * 8;

            case InformationUnit::Bits:
                return value;

            case InformationUnit::Kilobits:
                return (value * 1e3);

            case InformationUnit::Megabits:
                return (value * 1e6);

            case InformationUnit::Gigabits:
                return (value * 1e9);

            case InformationUnit::Terabits:
                return (value * 1e12);

            case InformationUnit::Petabits:
                return (value * 1e15);

            case InformationUnit::Exabits:
                return (value * 1e18);

            case InformationUnit::Kibibits:
                return (value * 1024.0);

            case InformationUnit::Mebibits:
                return (value * 1048576.0);

            case InformationUnit::Gibibits:
                return (value * 1073741824.0);

            case InformationUnit::Tebibits:
                return (value * 1099511627776.0);

            case InformationUnit::Pebibits:
                return (value * 1125899906842624.0);

            case InformationUnit::Exbibits:
                return (value * 1152921504606846976.0);

            }

            throw std::invalid_argument("Unknown Information unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(InformationUnit unit) const
        {
            switch (unit)
            {

            case InformationUnit::Bytes:
                return value_ / 8;

            case InformationUnit::Kilobytes:
                return (value_ / 8) / 1e3;

            case InformationUnit::Megabytes:
                return (value_ / 8) / 1e6;

            case InformationUnit::Gigabytes:
                return (value_ / 8) / 1e9;

            case InformationUnit::Terabytes:
                return (value_ / 8) / 1e12;

            case InformationUnit::Petabytes:
                return (value_ / 8) / 1e15;

            case InformationUnit::Exabytes:
                return (value_ / 8) / 1e18;

            case InformationUnit::Kibibytes:
                return (value_ / 8) / 1024.0;

            case InformationUnit::Mebibytes:
                return (value_ / 8) / 1048576.0;

            case InformationUnit::Gibibytes:
                return (value_ / 8) / 1073741824.0;

            case InformationUnit::Tebibytes:
                return (value_ / 8) / 1099511627776.0;

            case InformationUnit::Pebibytes:
                return (value_ / 8) / 1125899906842624.0;

            case InformationUnit::Exbibytes:
                return (value_ / 8) / 1152921504606846976.0;

            case InformationUnit::Octets:
                return value_ / 8;

            case InformationUnit::Kilooctets:
                return (value_ / 8) / 1e3;

            case InformationUnit::Megaoctets:
                return (value_ / 8) / 1e6;

            case InformationUnit::Gigaoctets:
                return (value_ / 8) / 1e9;

            case InformationUnit::Teraoctets:
                return (value_ / 8) / 1e12;

            case InformationUnit::Petaoctets:
                return (value_ / 8) / 1e15;

            case InformationUnit::Exaoctets:
                return (value_ / 8) / 1e18;

            case InformationUnit::Kibioctets:
                return (value_ / 8) / 1024.0;

            case InformationUnit::Mebioctets:
                return (value_ / 8) / 1048576.0;

            case InformationUnit::Gibioctets:
                return (value_ / 8) / 1073741824.0;

            case InformationUnit::Tebioctets:
                return (value_ / 8) / 1099511627776.0;

            case InformationUnit::Pebioctets:
                return (value_ / 8) / 1125899906842624.0;

            case InformationUnit::Exbioctets:
                return (value_ / 8) / 1152921504606846976.0;

            case InformationUnit::Bits:
                return value_;

            case InformationUnit::Kilobits:
                return (value_) / 1e3;

            case InformationUnit::Megabits:
                return (value_) / 1e6;

            case InformationUnit::Gigabits:
                return (value_) / 1e9;

            case InformationUnit::Terabits:
                return (value_) / 1e12;

            case InformationUnit::Petabits:
                return (value_) / 1e15;

            case InformationUnit::Exabits:
                return (value_) / 1e18;

            case InformationUnit::Kibibits:
                return (value_) / 1024.0;

            case InformationUnit::Mebibits:
                return (value_) / 1048576.0;

            case InformationUnit::Gibibits:
                return (value_) / 1073741824.0;

            case InformationUnit::Tebibits:
                return (value_) / 1099511627776.0;

            case InformationUnit::Pebibits:
                return (value_) / 1125899906842624.0;

            case InformationUnit::Exbibits:
                return (value_) / 1152921504606846976.0;

            }

            throw std::invalid_argument("Unknown Information unit.");
        }

        double value_;
    };
}
