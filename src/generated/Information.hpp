#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class InformationUnit : std::uint8_t
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
    class Information : public UnitsNetBase
    {
    public:
        constexpr explicit Information(
            const un_scalar_t value,
            const InformationUnit unit = InformationUnit::Bits)
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
            return convert_from_base(InformationUnit::Bytes);
        }

        [[nodiscard]] static constexpr Information from_bytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Bytes);
        }

        [[nodiscard]] constexpr un_scalar_t kilobytes() const
        {
            return convert_from_base(InformationUnit::Kilobytes);
        }

        [[nodiscard]] static constexpr Information from_kilobytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Kilobytes);
        }

        [[nodiscard]] constexpr un_scalar_t megabytes() const
        {
            return convert_from_base(InformationUnit::Megabytes);
        }

        [[nodiscard]] static constexpr Information from_megabytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Megabytes);
        }

        [[nodiscard]] constexpr un_scalar_t gigabytes() const
        {
            return convert_from_base(InformationUnit::Gigabytes);
        }

        [[nodiscard]] static constexpr Information from_gigabytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Gigabytes);
        }

        [[nodiscard]] constexpr un_scalar_t terabytes() const
        {
            return convert_from_base(InformationUnit::Terabytes);
        }

        [[nodiscard]] static constexpr Information from_terabytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Terabytes);
        }

        [[nodiscard]] constexpr un_scalar_t petabytes() const
        {
            return convert_from_base(InformationUnit::Petabytes);
        }

        [[nodiscard]] static constexpr Information from_petabytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Petabytes);
        }

        [[nodiscard]] constexpr un_scalar_t exabytes() const
        {
            return convert_from_base(InformationUnit::Exabytes);
        }

        [[nodiscard]] static constexpr Information from_exabytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Exabytes);
        }

        [[nodiscard]] constexpr un_scalar_t kibibytes() const
        {
            return convert_from_base(InformationUnit::Kibibytes);
        }

        [[nodiscard]] static constexpr Information from_kibibytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Kibibytes);
        }

        [[nodiscard]] constexpr un_scalar_t mebibytes() const
        {
            return convert_from_base(InformationUnit::Mebibytes);
        }

        [[nodiscard]] static constexpr Information from_mebibytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Mebibytes);
        }

        [[nodiscard]] constexpr un_scalar_t gibibytes() const
        {
            return convert_from_base(InformationUnit::Gibibytes);
        }

        [[nodiscard]] static constexpr Information from_gibibytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Gibibytes);
        }

        [[nodiscard]] constexpr un_scalar_t tebibytes() const
        {
            return convert_from_base(InformationUnit::Tebibytes);
        }

        [[nodiscard]] static constexpr Information from_tebibytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Tebibytes);
        }

        [[nodiscard]] constexpr un_scalar_t pebibytes() const
        {
            return convert_from_base(InformationUnit::Pebibytes);
        }

        [[nodiscard]] static constexpr Information from_pebibytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Pebibytes);
        }

        [[nodiscard]] constexpr un_scalar_t exbibytes() const
        {
            return convert_from_base(InformationUnit::Exbibytes);
        }

        [[nodiscard]] static constexpr Information from_exbibytes(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Exbibytes);
        }

        [[nodiscard]] constexpr un_scalar_t octets() const
        {
            return convert_from_base(InformationUnit::Octets);
        }

        [[nodiscard]] static constexpr Information from_octets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Octets);
        }

        [[nodiscard]] constexpr un_scalar_t kilooctets() const
        {
            return convert_from_base(InformationUnit::Kilooctets);
        }

        [[nodiscard]] static constexpr Information from_kilooctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Kilooctets);
        }

        [[nodiscard]] constexpr un_scalar_t megaoctets() const
        {
            return convert_from_base(InformationUnit::Megaoctets);
        }

        [[nodiscard]] static constexpr Information from_megaoctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Megaoctets);
        }

        [[nodiscard]] constexpr un_scalar_t gigaoctets() const
        {
            return convert_from_base(InformationUnit::Gigaoctets);
        }

        [[nodiscard]] static constexpr Information from_gigaoctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Gigaoctets);
        }

        [[nodiscard]] constexpr un_scalar_t teraoctets() const
        {
            return convert_from_base(InformationUnit::Teraoctets);
        }

        [[nodiscard]] static constexpr Information from_teraoctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Teraoctets);
        }

        [[nodiscard]] constexpr un_scalar_t petaoctets() const
        {
            return convert_from_base(InformationUnit::Petaoctets);
        }

        [[nodiscard]] static constexpr Information from_petaoctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Petaoctets);
        }

        [[nodiscard]] constexpr un_scalar_t exaoctets() const
        {
            return convert_from_base(InformationUnit::Exaoctets);
        }

        [[nodiscard]] static constexpr Information from_exaoctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Exaoctets);
        }

        [[nodiscard]] constexpr un_scalar_t kibioctets() const
        {
            return convert_from_base(InformationUnit::Kibioctets);
        }

        [[nodiscard]] static constexpr Information from_kibioctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Kibioctets);
        }

        [[nodiscard]] constexpr un_scalar_t mebioctets() const
        {
            return convert_from_base(InformationUnit::Mebioctets);
        }

        [[nodiscard]] static constexpr Information from_mebioctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Mebioctets);
        }

        [[nodiscard]] constexpr un_scalar_t gibioctets() const
        {
            return convert_from_base(InformationUnit::Gibioctets);
        }

        [[nodiscard]] static constexpr Information from_gibioctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Gibioctets);
        }

        [[nodiscard]] constexpr un_scalar_t tebioctets() const
        {
            return convert_from_base(InformationUnit::Tebioctets);
        }

        [[nodiscard]] static constexpr Information from_tebioctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Tebioctets);
        }

        [[nodiscard]] constexpr un_scalar_t pebioctets() const
        {
            return convert_from_base(InformationUnit::Pebioctets);
        }

        [[nodiscard]] static constexpr Information from_pebioctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Pebioctets);
        }

        [[nodiscard]] constexpr un_scalar_t exbioctets() const
        {
            return convert_from_base(InformationUnit::Exbioctets);
        }

        [[nodiscard]] static constexpr Information from_exbioctets(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Exbioctets);
        }

        [[nodiscard]] constexpr un_scalar_t bits() const
        {
            return convert_from_base(InformationUnit::Bits);
        }

        [[nodiscard]] static constexpr Information from_bits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Bits);
        }

        [[nodiscard]] constexpr un_scalar_t kilobits() const
        {
            return convert_from_base(InformationUnit::Kilobits);
        }

        [[nodiscard]] static constexpr Information from_kilobits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Kilobits);
        }

        [[nodiscard]] constexpr un_scalar_t megabits() const
        {
            return convert_from_base(InformationUnit::Megabits);
        }

        [[nodiscard]] static constexpr Information from_megabits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Megabits);
        }

        [[nodiscard]] constexpr un_scalar_t gigabits() const
        {
            return convert_from_base(InformationUnit::Gigabits);
        }

        [[nodiscard]] static constexpr Information from_gigabits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Gigabits);
        }

        [[nodiscard]] constexpr un_scalar_t terabits() const
        {
            return convert_from_base(InformationUnit::Terabits);
        }

        [[nodiscard]] static constexpr Information from_terabits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Terabits);
        }

        [[nodiscard]] constexpr un_scalar_t petabits() const
        {
            return convert_from_base(InformationUnit::Petabits);
        }

        [[nodiscard]] static constexpr Information from_petabits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Petabits);
        }

        [[nodiscard]] constexpr un_scalar_t exabits() const
        {
            return convert_from_base(InformationUnit::Exabits);
        }

        [[nodiscard]] static constexpr Information from_exabits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Exabits);
        }

        [[nodiscard]] constexpr un_scalar_t kibibits() const
        {
            return convert_from_base(InformationUnit::Kibibits);
        }

        [[nodiscard]] static constexpr Information from_kibibits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Kibibits);
        }

        [[nodiscard]] constexpr un_scalar_t mebibits() const
        {
            return convert_from_base(InformationUnit::Mebibits);
        }

        [[nodiscard]] static constexpr Information from_mebibits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Mebibits);
        }

        [[nodiscard]] constexpr un_scalar_t gibibits() const
        {
            return convert_from_base(InformationUnit::Gibibits);
        }

        [[nodiscard]] static constexpr Information from_gibibits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Gibibits);
        }

        [[nodiscard]] constexpr un_scalar_t tebibits() const
        {
            return convert_from_base(InformationUnit::Tebibits);
        }

        [[nodiscard]] static constexpr Information from_tebibits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Tebibits);
        }

        [[nodiscard]] constexpr un_scalar_t pebibits() const
        {
            return convert_from_base(InformationUnit::Pebibits);
        }

        [[nodiscard]] static constexpr Information from_pebibits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Pebibits);
        }

        [[nodiscard]] constexpr un_scalar_t exbibits() const
        {
            return convert_from_base(InformationUnit::Exbibits);
        }

        [[nodiscard]] static constexpr Information from_exbibits(const un_scalar_t value)
        {
            return Information(value, InformationUnit::Exbibits);
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

            case InformationUnit::Bytes:
                return value * static_cast<un_scalar_t>(8);

            case InformationUnit::Kilobytes:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Megabytes:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Gigabytes:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Terabytes:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Petabytes:
                return (value * static_cast<un_scalar_t>(1e15)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Exabytes:
                return (value * static_cast<un_scalar_t>(1e18)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Kibibytes:
                return (value * static_cast<un_scalar_t>(1024.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Mebibytes:
                return (value * static_cast<un_scalar_t>(1048576.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Gibibytes:
                return (value * static_cast<un_scalar_t>(1073741824.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Tebibytes:
                return (value * static_cast<un_scalar_t>(1099511627776.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Pebibytes:
                return (value * static_cast<un_scalar_t>(1125899906842624.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Exbibytes:
                return (value * static_cast<un_scalar_t>(1152921504606846976.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Octets:
                return value * static_cast<un_scalar_t>(8);

            case InformationUnit::Kilooctets:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Megaoctets:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Gigaoctets:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Teraoctets:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Petaoctets:
                return (value * static_cast<un_scalar_t>(1e15)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Exaoctets:
                return (value * static_cast<un_scalar_t>(1e18)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Kibioctets:
                return (value * static_cast<un_scalar_t>(1024.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Mebioctets:
                return (value * static_cast<un_scalar_t>(1048576.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Gibioctets:
                return (value * static_cast<un_scalar_t>(1073741824.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Tebioctets:
                return (value * static_cast<un_scalar_t>(1099511627776.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Pebioctets:
                return (value * static_cast<un_scalar_t>(1125899906842624.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Exbioctets:
                return (value * static_cast<un_scalar_t>(1152921504606846976.0)) * static_cast<un_scalar_t>(8);

            case InformationUnit::Bits:
                return value;

            case InformationUnit::Kilobits:
                return (value * static_cast<un_scalar_t>(1e3));

            case InformationUnit::Megabits:
                return (value * static_cast<un_scalar_t>(1e6));

            case InformationUnit::Gigabits:
                return (value * static_cast<un_scalar_t>(1e9));

            case InformationUnit::Terabits:
                return (value * static_cast<un_scalar_t>(1e12));

            case InformationUnit::Petabits:
                return (value * static_cast<un_scalar_t>(1e15));

            case InformationUnit::Exabits:
                return (value * static_cast<un_scalar_t>(1e18));

            case InformationUnit::Kibibits:
                return (value * static_cast<un_scalar_t>(1024.0));

            case InformationUnit::Mebibits:
                return (value * static_cast<un_scalar_t>(1048576.0));

            case InformationUnit::Gibibits:
                return (value * static_cast<un_scalar_t>(1073741824.0));

            case InformationUnit::Tebibits:
                return (value * static_cast<un_scalar_t>(1099511627776.0));

            case InformationUnit::Pebibits:
                return (value * static_cast<un_scalar_t>(1125899906842624.0));

            case InformationUnit::Exbibits:
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

            case InformationUnit::Bytes:
                return base_value / static_cast<un_scalar_t>(8);

            case InformationUnit::Kilobytes:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e3);

            case InformationUnit::Megabytes:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e6);

            case InformationUnit::Gigabytes:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e9);

            case InformationUnit::Terabytes:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e12);

            case InformationUnit::Petabytes:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e15);

            case InformationUnit::Exabytes:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e18);

            case InformationUnit::Kibibytes:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1024.0);

            case InformationUnit::Mebibytes:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1048576.0);

            case InformationUnit::Gibibytes:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1073741824.0);

            case InformationUnit::Tebibytes:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1099511627776.0);

            case InformationUnit::Pebibytes:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1125899906842624.0);

            case InformationUnit::Exbibytes:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1152921504606846976.0);

            case InformationUnit::Octets:
                return base_value / static_cast<un_scalar_t>(8);

            case InformationUnit::Kilooctets:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e3);

            case InformationUnit::Megaoctets:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e6);

            case InformationUnit::Gigaoctets:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e9);

            case InformationUnit::Teraoctets:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e12);

            case InformationUnit::Petaoctets:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e15);

            case InformationUnit::Exaoctets:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1e18);

            case InformationUnit::Kibioctets:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1024.0);

            case InformationUnit::Mebioctets:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1048576.0);

            case InformationUnit::Gibioctets:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1073741824.0);

            case InformationUnit::Tebioctets:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1099511627776.0);

            case InformationUnit::Pebioctets:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1125899906842624.0);

            case InformationUnit::Exbioctets:
                return (base_value / static_cast<un_scalar_t>(8)) / static_cast<un_scalar_t>(1152921504606846976.0);

            case InformationUnit::Bits:
                return base_value;

            case InformationUnit::Kilobits:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case InformationUnit::Megabits:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case InformationUnit::Gigabits:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case InformationUnit::Terabits:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            case InformationUnit::Petabits:
                return (base_value) / static_cast<un_scalar_t>(1e15);

            case InformationUnit::Exabits:
                return (base_value) / static_cast<un_scalar_t>(1e18);

            case InformationUnit::Kibibits:
                return (base_value) / static_cast<un_scalar_t>(1024.0);

            case InformationUnit::Mebibits:
                return (base_value) / static_cast<un_scalar_t>(1048576.0);

            case InformationUnit::Gibibits:
                return (base_value) / static_cast<un_scalar_t>(1073741824.0);

            case InformationUnit::Tebibits:
                return (base_value) / static_cast<un_scalar_t>(1099511627776.0);

            case InformationUnit::Pebibits:
                return (base_value) / static_cast<un_scalar_t>(1125899906842624.0);

            case InformationUnit::Exbibits:
                return (base_value) / static_cast<un_scalar_t>(1152921504606846976.0);

            }

            throw std::invalid_argument("Unknown Information unit.");
        }

        un_scalar_t value_;
        InformationUnit value_unit_type_;       
    };
}
