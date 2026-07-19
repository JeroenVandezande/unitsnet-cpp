#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class ElectricConductanceUnit : std::uint8_t
    {
        Siemens,
        Nanosiemens,
        Microsiemens,
        Millisiemens,
        Kilosiemens,
        Megasiemens,
        Gigasiemens,
        Terasiemens,
        Mhos,
        Nanomhos,
        Micromhos,
        Millimhos,
        Kilomhos,
        Megamhos,
        Gigamhos,
        Teramhos,
    };

    /// <summary>The electrical conductance of an object is a measure of the ease with which an electric current passes. Along with susceptance, it is one of two elements of admittance. Its reciprocal quantity is electrical resistance.</summary>
    class ElectricConductance
    {
    public:
        constexpr explicit ElectricConductance(
            const un_scalar_t value,
            const ElectricConductanceUnit unit = ElectricConductanceUnit::Siemens)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricConductanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricConductance operator+(const ElectricConductance other) const noexcept
        {
            return ElectricConductance(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricConductance operator-(const ElectricConductance other) const noexcept
        {
            return ElectricConductance(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricConductance operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricConductance(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricConductance operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricConductance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricConductance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const ElectricConductance other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t siemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Siemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_siemens(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Siemens);
        }


        [[nodiscard]] constexpr un_scalar_t nanosiemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Nanosiemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_nanosiemens(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Nanosiemens);
        }


        [[nodiscard]] constexpr un_scalar_t microsiemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Microsiemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_microsiemens(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Microsiemens);
        }


        [[nodiscard]] constexpr un_scalar_t millisiemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Millisiemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_millisiemens(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Millisiemens);
        }


        [[nodiscard]] constexpr un_scalar_t kilosiemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Kilosiemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_kilosiemens(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Kilosiemens);
        }


        [[nodiscard]] constexpr un_scalar_t megasiemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Megasiemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_megasiemens(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Megasiemens);
        }


        [[nodiscard]] constexpr un_scalar_t gigasiemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Gigasiemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_gigasiemens(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Gigasiemens);
        }


        [[nodiscard]] constexpr un_scalar_t terasiemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Terasiemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_terasiemens(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Terasiemens);
        }


        [[nodiscard]] constexpr un_scalar_t mhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Mhos);
        }

        [[nodiscard]] static constexpr ElectricConductance from_mhos(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Mhos);
        }


        [[nodiscard]] constexpr un_scalar_t nanomhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Nanomhos);
        }

        [[nodiscard]] static constexpr ElectricConductance from_nanomhos(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Nanomhos);
        }


        [[nodiscard]] constexpr un_scalar_t micromhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Micromhos);
        }

        [[nodiscard]] static constexpr ElectricConductance from_micromhos(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Micromhos);
        }


        [[nodiscard]] constexpr un_scalar_t millimhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Millimhos);
        }

        [[nodiscard]] static constexpr ElectricConductance from_millimhos(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Millimhos);
        }


        [[nodiscard]] constexpr un_scalar_t kilomhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Kilomhos);
        }

        [[nodiscard]] static constexpr ElectricConductance from_kilomhos(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Kilomhos);
        }


        [[nodiscard]] constexpr un_scalar_t megamhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Megamhos);
        }

        [[nodiscard]] static constexpr ElectricConductance from_megamhos(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Megamhos);
        }


        [[nodiscard]] constexpr un_scalar_t gigamhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Gigamhos);
        }

        [[nodiscard]] static constexpr ElectricConductance from_gigamhos(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Gigamhos);
        }


        [[nodiscard]] constexpr un_scalar_t teramhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Teramhos);
        }

        [[nodiscard]] static constexpr ElectricConductance from_teramhos(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Teramhos);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricConductanceUnit unit)
        {
            switch (unit)
            {

            case ElectricConductanceUnit::Siemens:
                return value;

            case ElectricConductanceUnit::Nanosiemens:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricConductanceUnit::Microsiemens:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricConductanceUnit::Millisiemens:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricConductanceUnit::Kilosiemens:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricConductanceUnit::Megasiemens:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricConductanceUnit::Gigasiemens:
                return (value * static_cast<un_scalar_t>(1e9));

            case ElectricConductanceUnit::Terasiemens:
                return (value * static_cast<un_scalar_t>(1e12));

            case ElectricConductanceUnit::Mhos:
                return value;

            case ElectricConductanceUnit::Nanomhos:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricConductanceUnit::Micromhos:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricConductanceUnit::Millimhos:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricConductanceUnit::Kilomhos:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricConductanceUnit::Megamhos:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricConductanceUnit::Gigamhos:
                return (value * static_cast<un_scalar_t>(1e9));

            case ElectricConductanceUnit::Teramhos:
                return (value * static_cast<un_scalar_t>(1e12));

            }

            throw std::invalid_argument("Unknown ElectricConductance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricConductanceUnit unit) const
        {
            switch (unit)
            {

            case ElectricConductanceUnit::Siemens:
                return value_;

            case ElectricConductanceUnit::Nanosiemens:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case ElectricConductanceUnit::Microsiemens:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case ElectricConductanceUnit::Millisiemens:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case ElectricConductanceUnit::Kilosiemens:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case ElectricConductanceUnit::Megasiemens:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case ElectricConductanceUnit::Gigasiemens:
                return (value_) / static_cast<un_scalar_t>(1e9);

            case ElectricConductanceUnit::Terasiemens:
                return (value_) / static_cast<un_scalar_t>(1e12);

            case ElectricConductanceUnit::Mhos:
                return value_;

            case ElectricConductanceUnit::Nanomhos:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case ElectricConductanceUnit::Micromhos:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case ElectricConductanceUnit::Millimhos:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case ElectricConductanceUnit::Kilomhos:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case ElectricConductanceUnit::Megamhos:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case ElectricConductanceUnit::Gigamhos:
                return (value_) / static_cast<un_scalar_t>(1e9);

            case ElectricConductanceUnit::Teramhos:
                return (value_) / static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown ElectricConductance unit.");
        }

        un_scalar_t value_;
    };
}
