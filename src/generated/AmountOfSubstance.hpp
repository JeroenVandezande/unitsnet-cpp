#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class AmountOfSubstanceUnit : std::uint16_t
    {
        Moles,
        Femtomoles,
        Picomoles,
        Nanomoles,
        Micromoles,
        Millimoles,
        Centimoles,
        Decimoles,
        Kilomoles,
        Megamoles,
        PoundMoles,
        NanopoundMoles,
        MicropoundMoles,
        MillipoundMoles,
        CentipoundMoles,
        DecipoundMoles,
        KilopoundMoles,
    };

    /// <summary>Mole is the amount of substance containing Avagadro's Number (6.02 x 10 ^ 23) of real particles such as molecules,atoms, ions or radicals.</summary>
    class AmountOfSubstance
    {
    public:
        constexpr explicit AmountOfSubstance(
            double value,
            AmountOfSubstanceUnit unit = AmountOfSubstanceUnit::Moles)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(AmountOfSubstanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr AmountOfSubstance operator+(AmountOfSubstance other) const noexcept
        {
            return AmountOfSubstance(value_ + other.value_);
        }

        [[nodiscard]] constexpr AmountOfSubstance operator-(AmountOfSubstance other) const noexcept
        {
            return AmountOfSubstance(value_ - other.value_);
        }

        [[nodiscard]] constexpr AmountOfSubstance operator*(double scalar) const noexcept
        {
            return AmountOfSubstance(value_ * scalar);
        }

        [[nodiscard]] constexpr AmountOfSubstance operator/(double scalar) const noexcept
        {
            return AmountOfSubstance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(AmountOfSubstance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(AmountOfSubstance other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Moles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_moles(double value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Moles);
        }


        [[nodiscard]] constexpr double femtomoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Femtomoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_femtomoles(double value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Femtomoles);
        }


        [[nodiscard]] constexpr double picomoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Picomoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_picomoles(double value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Picomoles);
        }


        [[nodiscard]] constexpr double nanomoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Nanomoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_nanomoles(double value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Nanomoles);
        }


        [[nodiscard]] constexpr double micromoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Micromoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_micromoles(double value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Micromoles);
        }


        [[nodiscard]] constexpr double millimoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Millimoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_millimoles(double value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Millimoles);
        }


        [[nodiscard]] constexpr double centimoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Centimoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_centimoles(double value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Centimoles);
        }


        [[nodiscard]] constexpr double decimoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Decimoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_decimoles(double value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Decimoles);
        }


        [[nodiscard]] constexpr double kilomoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Kilomoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_kilomoles(double value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Kilomoles);
        }


        [[nodiscard]] constexpr double megamoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Megamoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_megamoles(double value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Megamoles);
        }


        [[nodiscard]] constexpr double pound_moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::PoundMoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_pound_moles(double value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::PoundMoles);
        }


        [[nodiscard]] constexpr double nanopound_moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::NanopoundMoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_nanopound_moles(double value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::NanopoundMoles);
        }


        [[nodiscard]] constexpr double micropound_moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::MicropoundMoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_micropound_moles(double value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::MicropoundMoles);
        }


        [[nodiscard]] constexpr double millipound_moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::MillipoundMoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_millipound_moles(double value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::MillipoundMoles);
        }


        [[nodiscard]] constexpr double centipound_moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::CentipoundMoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_centipound_moles(double value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::CentipoundMoles);
        }


        [[nodiscard]] constexpr double decipound_moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::DecipoundMoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_decipound_moles(double value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::DecipoundMoles);
        }


        [[nodiscard]] constexpr double kilopound_moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::KilopoundMoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_kilopound_moles(double value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::KilopoundMoles);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, AmountOfSubstanceUnit unit)
        {
            switch (unit)
            {

            case AmountOfSubstanceUnit::Moles:
                return value;

            case AmountOfSubstanceUnit::Femtomoles:
                return (value * 1e-15);

            case AmountOfSubstanceUnit::Picomoles:
                return (value * 1e-12);

            case AmountOfSubstanceUnit::Nanomoles:
                return (value * 1e-9);

            case AmountOfSubstanceUnit::Micromoles:
                return (value * 1e-6);

            case AmountOfSubstanceUnit::Millimoles:
                return (value * 1e-3);

            case AmountOfSubstanceUnit::Centimoles:
                return (value * 1e-2);

            case AmountOfSubstanceUnit::Decimoles:
                return (value * 1e-1);

            case AmountOfSubstanceUnit::Kilomoles:
                return (value * 1e3);

            case AmountOfSubstanceUnit::Megamoles:
                return (value * 1e6);

            case AmountOfSubstanceUnit::PoundMoles:
                return value * 453.59237;

            case AmountOfSubstanceUnit::NanopoundMoles:
                return (value * 1e-9) * 453.59237;

            case AmountOfSubstanceUnit::MicropoundMoles:
                return (value * 1e-6) * 453.59237;

            case AmountOfSubstanceUnit::MillipoundMoles:
                return (value * 1e-3) * 453.59237;

            case AmountOfSubstanceUnit::CentipoundMoles:
                return (value * 1e-2) * 453.59237;

            case AmountOfSubstanceUnit::DecipoundMoles:
                return (value * 1e-1) * 453.59237;

            case AmountOfSubstanceUnit::KilopoundMoles:
                return (value * 1e3) * 453.59237;

            }

            throw std::invalid_argument("Unknown AmountOfSubstance unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(AmountOfSubstanceUnit unit) const
        {
            switch (unit)
            {

            case AmountOfSubstanceUnit::Moles:
                return value_;

            case AmountOfSubstanceUnit::Femtomoles:
                return (value_) / 1e-15;

            case AmountOfSubstanceUnit::Picomoles:
                return (value_) / 1e-12;

            case AmountOfSubstanceUnit::Nanomoles:
                return (value_) / 1e-9;

            case AmountOfSubstanceUnit::Micromoles:
                return (value_) / 1e-6;

            case AmountOfSubstanceUnit::Millimoles:
                return (value_) / 1e-3;

            case AmountOfSubstanceUnit::Centimoles:
                return (value_) / 1e-2;

            case AmountOfSubstanceUnit::Decimoles:
                return (value_) / 1e-1;

            case AmountOfSubstanceUnit::Kilomoles:
                return (value_) / 1e3;

            case AmountOfSubstanceUnit::Megamoles:
                return (value_) / 1e6;

            case AmountOfSubstanceUnit::PoundMoles:
                return value_ / 453.59237;

            case AmountOfSubstanceUnit::NanopoundMoles:
                return (value_ / 453.59237) / 1e-9;

            case AmountOfSubstanceUnit::MicropoundMoles:
                return (value_ / 453.59237) / 1e-6;

            case AmountOfSubstanceUnit::MillipoundMoles:
                return (value_ / 453.59237) / 1e-3;

            case AmountOfSubstanceUnit::CentipoundMoles:
                return (value_ / 453.59237) / 1e-2;

            case AmountOfSubstanceUnit::DecipoundMoles:
                return (value_ / 453.59237) / 1e-1;

            case AmountOfSubstanceUnit::KilopoundMoles:
                return (value_ / 453.59237) / 1e3;

            }

            throw std::invalid_argument("Unknown AmountOfSubstance unit.");
        }

        double value_;
    };
}
