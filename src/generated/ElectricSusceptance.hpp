#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricSusceptanceUnit : std::uint16_t
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

    /// <summary>Electrical susceptance is the imaginary part of admittance, where the real part is conductance.</summary>
    class ElectricSusceptance
    {
    public:
        constexpr explicit ElectricSusceptance(
            double value,
            ElectricSusceptanceUnit unit = ElectricSusceptanceUnit::Siemens)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricSusceptanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricSusceptance operator+(ElectricSusceptance other) const noexcept
        {
            return ElectricSusceptance(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricSusceptance operator-(ElectricSusceptance other) const noexcept
        {
            return ElectricSusceptance(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricSusceptance operator*(double scalar) const noexcept
        {
            return ElectricSusceptance(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricSusceptance operator/(double scalar) const noexcept
        {
            return ElectricSusceptance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricSusceptance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricSusceptance other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double siemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Siemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_siemens(double value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Siemens);
        }


        [[nodiscard]] constexpr double nanosiemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Nanosiemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_nanosiemens(double value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Nanosiemens);
        }


        [[nodiscard]] constexpr double microsiemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Microsiemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_microsiemens(double value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Microsiemens);
        }


        [[nodiscard]] constexpr double millisiemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Millisiemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_millisiemens(double value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Millisiemens);
        }


        [[nodiscard]] constexpr double kilosiemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Kilosiemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_kilosiemens(double value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Kilosiemens);
        }


        [[nodiscard]] constexpr double megasiemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Megasiemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_megasiemens(double value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Megasiemens);
        }


        [[nodiscard]] constexpr double gigasiemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Gigasiemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_gigasiemens(double value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Gigasiemens);
        }


        [[nodiscard]] constexpr double terasiemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Terasiemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_terasiemens(double value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Terasiemens);
        }


        [[nodiscard]] constexpr double mhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Mhos);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_mhos(double value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Mhos);
        }


        [[nodiscard]] constexpr double nanomhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Nanomhos);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_nanomhos(double value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Nanomhos);
        }


        [[nodiscard]] constexpr double micromhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Micromhos);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_micromhos(double value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Micromhos);
        }


        [[nodiscard]] constexpr double millimhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Millimhos);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_millimhos(double value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Millimhos);
        }


        [[nodiscard]] constexpr double kilomhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Kilomhos);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_kilomhos(double value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Kilomhos);
        }


        [[nodiscard]] constexpr double megamhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Megamhos);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_megamhos(double value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Megamhos);
        }


        [[nodiscard]] constexpr double gigamhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Gigamhos);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_gigamhos(double value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Gigamhos);
        }


        [[nodiscard]] constexpr double teramhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Teramhos);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_teramhos(double value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Teramhos);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricSusceptanceUnit unit)
        {
            switch (unit)
            {

            case ElectricSusceptanceUnit::Siemens:
                return value;

            case ElectricSusceptanceUnit::Nanosiemens:
                return (value * 1e-9);

            case ElectricSusceptanceUnit::Microsiemens:
                return (value * 1e-6);

            case ElectricSusceptanceUnit::Millisiemens:
                return (value * 1e-3);

            case ElectricSusceptanceUnit::Kilosiemens:
                return (value * 1e3);

            case ElectricSusceptanceUnit::Megasiemens:
                return (value * 1e6);

            case ElectricSusceptanceUnit::Gigasiemens:
                return (value * 1e9);

            case ElectricSusceptanceUnit::Terasiemens:
                return (value * 1e12);

            case ElectricSusceptanceUnit::Mhos:
                return value;

            case ElectricSusceptanceUnit::Nanomhos:
                return (value * 1e-9);

            case ElectricSusceptanceUnit::Micromhos:
                return (value * 1e-6);

            case ElectricSusceptanceUnit::Millimhos:
                return (value * 1e-3);

            case ElectricSusceptanceUnit::Kilomhos:
                return (value * 1e3);

            case ElectricSusceptanceUnit::Megamhos:
                return (value * 1e6);

            case ElectricSusceptanceUnit::Gigamhos:
                return (value * 1e9);

            case ElectricSusceptanceUnit::Teramhos:
                return (value * 1e12);

            }

            throw std::invalid_argument("Unknown ElectricSusceptance unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricSusceptanceUnit unit) const
        {
            switch (unit)
            {

            case ElectricSusceptanceUnit::Siemens:
                return value_;

            case ElectricSusceptanceUnit::Nanosiemens:
                return (value_) / 1e-9;

            case ElectricSusceptanceUnit::Microsiemens:
                return (value_) / 1e-6;

            case ElectricSusceptanceUnit::Millisiemens:
                return (value_) / 1e-3;

            case ElectricSusceptanceUnit::Kilosiemens:
                return (value_) / 1e3;

            case ElectricSusceptanceUnit::Megasiemens:
                return (value_) / 1e6;

            case ElectricSusceptanceUnit::Gigasiemens:
                return (value_) / 1e9;

            case ElectricSusceptanceUnit::Terasiemens:
                return (value_) / 1e12;

            case ElectricSusceptanceUnit::Mhos:
                return value_;

            case ElectricSusceptanceUnit::Nanomhos:
                return (value_) / 1e-9;

            case ElectricSusceptanceUnit::Micromhos:
                return (value_) / 1e-6;

            case ElectricSusceptanceUnit::Millimhos:
                return (value_) / 1e-3;

            case ElectricSusceptanceUnit::Kilomhos:
                return (value_) / 1e3;

            case ElectricSusceptanceUnit::Megamhos:
                return (value_) / 1e6;

            case ElectricSusceptanceUnit::Gigamhos:
                return (value_) / 1e9;

            case ElectricSusceptanceUnit::Teramhos:
                return (value_) / 1e12;

            }

            throw std::invalid_argument("Unknown ElectricSusceptance unit.");
        }

        double value_;
    };
}
