#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricChargeUnit : std::uint16_t
    {
        Coulombs,
        Picocoulombs,
        Nanocoulombs,
        Microcoulombs,
        Millicoulombs,
        Kilocoulombs,
        Megacoulombs,
        AmpereHours,
        MilliampereHours,
        KiloampereHours,
        MegaampereHours,
    };

    /// <summary>Electric charge is the physical property of matter that causes it to experience a force when placed in an electromagnetic field.</summary>
    class ElectricCharge
    {
    public:
        constexpr explicit ElectricCharge(
            double value,
            ElectricChargeUnit unit = ElectricChargeUnit::Coulombs)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricChargeUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricCharge operator+(ElectricCharge other) const noexcept
        {
            return ElectricCharge(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricCharge operator-(ElectricCharge other) const noexcept
        {
            return ElectricCharge(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricCharge operator*(double scalar) const noexcept
        {
            return ElectricCharge(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricCharge operator/(double scalar) const noexcept
        {
            return ElectricCharge(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricCharge other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricCharge other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double coulombs() const
        {
            return convert_from_base(ElectricChargeUnit::Coulombs);
        }

        [[nodiscard]] static constexpr ElectricCharge from_coulombs(double value)
        {
            return ElectricCharge(value, ElectricChargeUnit::Coulombs);
        }


        [[nodiscard]] constexpr double picocoulombs() const
        {
            return convert_from_base(ElectricChargeUnit::Picocoulombs);
        }

        [[nodiscard]] static constexpr ElectricCharge from_picocoulombs(double value)
        {
            return ElectricCharge(value, ElectricChargeUnit::Picocoulombs);
        }


        [[nodiscard]] constexpr double nanocoulombs() const
        {
            return convert_from_base(ElectricChargeUnit::Nanocoulombs);
        }

        [[nodiscard]] static constexpr ElectricCharge from_nanocoulombs(double value)
        {
            return ElectricCharge(value, ElectricChargeUnit::Nanocoulombs);
        }


        [[nodiscard]] constexpr double microcoulombs() const
        {
            return convert_from_base(ElectricChargeUnit::Microcoulombs);
        }

        [[nodiscard]] static constexpr ElectricCharge from_microcoulombs(double value)
        {
            return ElectricCharge(value, ElectricChargeUnit::Microcoulombs);
        }


        [[nodiscard]] constexpr double millicoulombs() const
        {
            return convert_from_base(ElectricChargeUnit::Millicoulombs);
        }

        [[nodiscard]] static constexpr ElectricCharge from_millicoulombs(double value)
        {
            return ElectricCharge(value, ElectricChargeUnit::Millicoulombs);
        }


        [[nodiscard]] constexpr double kilocoulombs() const
        {
            return convert_from_base(ElectricChargeUnit::Kilocoulombs);
        }

        [[nodiscard]] static constexpr ElectricCharge from_kilocoulombs(double value)
        {
            return ElectricCharge(value, ElectricChargeUnit::Kilocoulombs);
        }


        [[nodiscard]] constexpr double megacoulombs() const
        {
            return convert_from_base(ElectricChargeUnit::Megacoulombs);
        }

        [[nodiscard]] static constexpr ElectricCharge from_megacoulombs(double value)
        {
            return ElectricCharge(value, ElectricChargeUnit::Megacoulombs);
        }


        [[nodiscard]] constexpr double ampere_hours() const
        {
            return convert_from_base(ElectricChargeUnit::AmpereHours);
        }

        [[nodiscard]] static constexpr ElectricCharge from_ampere_hours(double value)
        {
            return ElectricCharge(value, ElectricChargeUnit::AmpereHours);
        }


        [[nodiscard]] constexpr double milliampere_hours() const
        {
            return convert_from_base(ElectricChargeUnit::MilliampereHours);
        }

        [[nodiscard]] static constexpr ElectricCharge from_milliampere_hours(double value)
        {
            return ElectricCharge(value, ElectricChargeUnit::MilliampereHours);
        }


        [[nodiscard]] constexpr double kiloampere_hours() const
        {
            return convert_from_base(ElectricChargeUnit::KiloampereHours);
        }

        [[nodiscard]] static constexpr ElectricCharge from_kiloampere_hours(double value)
        {
            return ElectricCharge(value, ElectricChargeUnit::KiloampereHours);
        }


        [[nodiscard]] constexpr double megaampere_hours() const
        {
            return convert_from_base(ElectricChargeUnit::MegaampereHours);
        }

        [[nodiscard]] static constexpr ElectricCharge from_megaampere_hours(double value)
        {
            return ElectricCharge(value, ElectricChargeUnit::MegaampereHours);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricChargeUnit unit)
        {
            switch (unit)
            {

            case ElectricChargeUnit::Coulombs:
                return value;

            case ElectricChargeUnit::Picocoulombs:
                return (value * 1e-12);

            case ElectricChargeUnit::Nanocoulombs:
                return (value * 1e-9);

            case ElectricChargeUnit::Microcoulombs:
                return (value * 1e-6);

            case ElectricChargeUnit::Millicoulombs:
                return (value * 1e-3);

            case ElectricChargeUnit::Kilocoulombs:
                return (value * 1e3);

            case ElectricChargeUnit::Megacoulombs:
                return (value * 1e6);

            case ElectricChargeUnit::AmpereHours:
                return value * 3600;

            case ElectricChargeUnit::MilliampereHours:
                return (value * 1e-3) * 3600;

            case ElectricChargeUnit::KiloampereHours:
                return (value * 1e3) * 3600;

            case ElectricChargeUnit::MegaampereHours:
                return (value * 1e6) * 3600;

            }

            throw std::invalid_argument("Unknown ElectricCharge unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricChargeUnit unit) const
        {
            switch (unit)
            {

            case ElectricChargeUnit::Coulombs:
                return value_;

            case ElectricChargeUnit::Picocoulombs:
                return (value_) / 1e-12;

            case ElectricChargeUnit::Nanocoulombs:
                return (value_) / 1e-9;

            case ElectricChargeUnit::Microcoulombs:
                return (value_) / 1e-6;

            case ElectricChargeUnit::Millicoulombs:
                return (value_) / 1e-3;

            case ElectricChargeUnit::Kilocoulombs:
                return (value_) / 1e3;

            case ElectricChargeUnit::Megacoulombs:
                return (value_) / 1e6;

            case ElectricChargeUnit::AmpereHours:
                return value_ / 3600;

            case ElectricChargeUnit::MilliampereHours:
                return (value_ / 3600) / 1e-3;

            case ElectricChargeUnit::KiloampereHours:
                return (value_ / 3600) / 1e3;

            case ElectricChargeUnit::MegaampereHours:
                return (value_ / 3600) / 1e6;

            }

            throw std::invalid_argument("Unknown ElectricCharge unit.");
        }

        double value_;
    };
}
