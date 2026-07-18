#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricAdmittanceUnit : std::uint16_t
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

    /// <summary>Electric admittance is a measure of how easily a circuit or device will allow a current to flow by the combined effect of conductance and susceptance in a circuit. It is defined as the inverse of impedance. The SI unit of admittance is the siemens (symbol S).</summary>
    class ElectricAdmittance
    {
    public:
        constexpr explicit ElectricAdmittance(
            double value,
            ElectricAdmittanceUnit unit = ElectricAdmittanceUnit::Siemens)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricAdmittanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricAdmittance operator+(ElectricAdmittance other) const noexcept
        {
            return ElectricAdmittance(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricAdmittance operator-(ElectricAdmittance other) const noexcept
        {
            return ElectricAdmittance(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricAdmittance operator*(double scalar) const noexcept
        {
            return ElectricAdmittance(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricAdmittance operator/(double scalar) const noexcept
        {
            return ElectricAdmittance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricAdmittance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricAdmittance other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double siemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Siemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_siemens(double value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Siemens);
        }


        [[nodiscard]] constexpr double nanosiemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Nanosiemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_nanosiemens(double value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Nanosiemens);
        }


        [[nodiscard]] constexpr double microsiemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Microsiemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_microsiemens(double value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Microsiemens);
        }


        [[nodiscard]] constexpr double millisiemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Millisiemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_millisiemens(double value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Millisiemens);
        }


        [[nodiscard]] constexpr double kilosiemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Kilosiemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_kilosiemens(double value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Kilosiemens);
        }


        [[nodiscard]] constexpr double megasiemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Megasiemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_megasiemens(double value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Megasiemens);
        }


        [[nodiscard]] constexpr double gigasiemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Gigasiemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_gigasiemens(double value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Gigasiemens);
        }


        [[nodiscard]] constexpr double terasiemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Terasiemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_terasiemens(double value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Terasiemens);
        }


        [[nodiscard]] constexpr double mhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Mhos);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_mhos(double value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Mhos);
        }


        [[nodiscard]] constexpr double nanomhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Nanomhos);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_nanomhos(double value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Nanomhos);
        }


        [[nodiscard]] constexpr double micromhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Micromhos);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_micromhos(double value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Micromhos);
        }


        [[nodiscard]] constexpr double millimhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Millimhos);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_millimhos(double value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Millimhos);
        }


        [[nodiscard]] constexpr double kilomhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Kilomhos);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_kilomhos(double value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Kilomhos);
        }


        [[nodiscard]] constexpr double megamhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Megamhos);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_megamhos(double value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Megamhos);
        }


        [[nodiscard]] constexpr double gigamhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Gigamhos);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_gigamhos(double value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Gigamhos);
        }


        [[nodiscard]] constexpr double teramhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Teramhos);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_teramhos(double value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Teramhos);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricAdmittanceUnit unit)
        {
            switch (unit)
            {

            case ElectricAdmittanceUnit::Siemens:
                return value;

            case ElectricAdmittanceUnit::Nanosiemens:
                return (value * 1e-9);

            case ElectricAdmittanceUnit::Microsiemens:
                return (value * 1e-6);

            case ElectricAdmittanceUnit::Millisiemens:
                return (value * 1e-3);

            case ElectricAdmittanceUnit::Kilosiemens:
                return (value * 1e3);

            case ElectricAdmittanceUnit::Megasiemens:
                return (value * 1e6);

            case ElectricAdmittanceUnit::Gigasiemens:
                return (value * 1e9);

            case ElectricAdmittanceUnit::Terasiemens:
                return (value * 1e12);

            case ElectricAdmittanceUnit::Mhos:
                return value;

            case ElectricAdmittanceUnit::Nanomhos:
                return (value * 1e-9);

            case ElectricAdmittanceUnit::Micromhos:
                return (value * 1e-6);

            case ElectricAdmittanceUnit::Millimhos:
                return (value * 1e-3);

            case ElectricAdmittanceUnit::Kilomhos:
                return (value * 1e3);

            case ElectricAdmittanceUnit::Megamhos:
                return (value * 1e6);

            case ElectricAdmittanceUnit::Gigamhos:
                return (value * 1e9);

            case ElectricAdmittanceUnit::Teramhos:
                return (value * 1e12);

            }

            throw std::invalid_argument("Unknown ElectricAdmittance unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricAdmittanceUnit unit) const
        {
            switch (unit)
            {

            case ElectricAdmittanceUnit::Siemens:
                return value_;

            case ElectricAdmittanceUnit::Nanosiemens:
                return (value_) / 1e-9;

            case ElectricAdmittanceUnit::Microsiemens:
                return (value_) / 1e-6;

            case ElectricAdmittanceUnit::Millisiemens:
                return (value_) / 1e-3;

            case ElectricAdmittanceUnit::Kilosiemens:
                return (value_) / 1e3;

            case ElectricAdmittanceUnit::Megasiemens:
                return (value_) / 1e6;

            case ElectricAdmittanceUnit::Gigasiemens:
                return (value_) / 1e9;

            case ElectricAdmittanceUnit::Terasiemens:
                return (value_) / 1e12;

            case ElectricAdmittanceUnit::Mhos:
                return value_;

            case ElectricAdmittanceUnit::Nanomhos:
                return (value_) / 1e-9;

            case ElectricAdmittanceUnit::Micromhos:
                return (value_) / 1e-6;

            case ElectricAdmittanceUnit::Millimhos:
                return (value_) / 1e-3;

            case ElectricAdmittanceUnit::Kilomhos:
                return (value_) / 1e3;

            case ElectricAdmittanceUnit::Megamhos:
                return (value_) / 1e6;

            case ElectricAdmittanceUnit::Gigamhos:
                return (value_) / 1e9;

            case ElectricAdmittanceUnit::Teramhos:
                return (value_) / 1e12;

            }

            throw std::invalid_argument("Unknown ElectricAdmittance unit.");
        }

        double value_;
    };
}
