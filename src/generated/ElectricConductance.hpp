#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricConductanceUnit : std::uint16_t
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
            double value,
            ElectricConductanceUnit unit = ElectricConductanceUnit::Siemens)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricConductanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricConductance operator+(ElectricConductance other) const noexcept
        {
            return ElectricConductance(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricConductance operator-(ElectricConductance other) const noexcept
        {
            return ElectricConductance(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricConductance operator*(double scalar) const noexcept
        {
            return ElectricConductance(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricConductance operator/(double scalar) const noexcept
        {
            return ElectricConductance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricConductance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricConductance other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double siemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Siemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_siemens(double value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Siemens);
        }


        [[nodiscard]] constexpr double nanosiemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Nanosiemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_nanosiemens(double value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Nanosiemens);
        }


        [[nodiscard]] constexpr double microsiemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Microsiemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_microsiemens(double value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Microsiemens);
        }


        [[nodiscard]] constexpr double millisiemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Millisiemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_millisiemens(double value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Millisiemens);
        }


        [[nodiscard]] constexpr double kilosiemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Kilosiemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_kilosiemens(double value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Kilosiemens);
        }


        [[nodiscard]] constexpr double megasiemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Megasiemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_megasiemens(double value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Megasiemens);
        }


        [[nodiscard]] constexpr double gigasiemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Gigasiemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_gigasiemens(double value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Gigasiemens);
        }


        [[nodiscard]] constexpr double terasiemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Terasiemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_terasiemens(double value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Terasiemens);
        }


        [[nodiscard]] constexpr double mhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Mhos);
        }

        [[nodiscard]] static constexpr ElectricConductance from_mhos(double value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Mhos);
        }


        [[nodiscard]] constexpr double nanomhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Nanomhos);
        }

        [[nodiscard]] static constexpr ElectricConductance from_nanomhos(double value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Nanomhos);
        }


        [[nodiscard]] constexpr double micromhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Micromhos);
        }

        [[nodiscard]] static constexpr ElectricConductance from_micromhos(double value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Micromhos);
        }


        [[nodiscard]] constexpr double millimhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Millimhos);
        }

        [[nodiscard]] static constexpr ElectricConductance from_millimhos(double value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Millimhos);
        }


        [[nodiscard]] constexpr double kilomhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Kilomhos);
        }

        [[nodiscard]] static constexpr ElectricConductance from_kilomhos(double value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Kilomhos);
        }


        [[nodiscard]] constexpr double megamhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Megamhos);
        }

        [[nodiscard]] static constexpr ElectricConductance from_megamhos(double value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Megamhos);
        }


        [[nodiscard]] constexpr double gigamhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Gigamhos);
        }

        [[nodiscard]] static constexpr ElectricConductance from_gigamhos(double value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Gigamhos);
        }


        [[nodiscard]] constexpr double teramhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Teramhos);
        }

        [[nodiscard]] static constexpr ElectricConductance from_teramhos(double value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Teramhos);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricConductanceUnit unit)
        {
            switch (unit)
            {

            case ElectricConductanceUnit::Siemens:
                return value;

            case ElectricConductanceUnit::Nanosiemens:
                return (value * 1e-9);

            case ElectricConductanceUnit::Microsiemens:
                return (value * 1e-6);

            case ElectricConductanceUnit::Millisiemens:
                return (value * 1e-3);

            case ElectricConductanceUnit::Kilosiemens:
                return (value * 1e3);

            case ElectricConductanceUnit::Megasiemens:
                return (value * 1e6);

            case ElectricConductanceUnit::Gigasiemens:
                return (value * 1e9);

            case ElectricConductanceUnit::Terasiemens:
                return (value * 1e12);

            case ElectricConductanceUnit::Mhos:
                return value;

            case ElectricConductanceUnit::Nanomhos:
                return (value * 1e-9);

            case ElectricConductanceUnit::Micromhos:
                return (value * 1e-6);

            case ElectricConductanceUnit::Millimhos:
                return (value * 1e-3);

            case ElectricConductanceUnit::Kilomhos:
                return (value * 1e3);

            case ElectricConductanceUnit::Megamhos:
                return (value * 1e6);

            case ElectricConductanceUnit::Gigamhos:
                return (value * 1e9);

            case ElectricConductanceUnit::Teramhos:
                return (value * 1e12);

            }

            throw std::invalid_argument("Unknown ElectricConductance unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricConductanceUnit unit) const
        {
            switch (unit)
            {

            case ElectricConductanceUnit::Siemens:
                return value_;

            case ElectricConductanceUnit::Nanosiemens:
                return (value_) / 1e-9;

            case ElectricConductanceUnit::Microsiemens:
                return (value_) / 1e-6;

            case ElectricConductanceUnit::Millisiemens:
                return (value_) / 1e-3;

            case ElectricConductanceUnit::Kilosiemens:
                return (value_) / 1e3;

            case ElectricConductanceUnit::Megasiemens:
                return (value_) / 1e6;

            case ElectricConductanceUnit::Gigasiemens:
                return (value_) / 1e9;

            case ElectricConductanceUnit::Terasiemens:
                return (value_) / 1e12;

            case ElectricConductanceUnit::Mhos:
                return value_;

            case ElectricConductanceUnit::Nanomhos:
                return (value_) / 1e-9;

            case ElectricConductanceUnit::Micromhos:
                return (value_) / 1e-6;

            case ElectricConductanceUnit::Millimhos:
                return (value_) / 1e-3;

            case ElectricConductanceUnit::Kilomhos:
                return (value_) / 1e3;

            case ElectricConductanceUnit::Megamhos:
                return (value_) / 1e6;

            case ElectricConductanceUnit::Gigamhos:
                return (value_) / 1e9;

            case ElectricConductanceUnit::Teramhos:
                return (value_) / 1e12;

            }

            throw std::invalid_argument("Unknown ElectricConductance unit.");
        }

        double value_;
    };
}
