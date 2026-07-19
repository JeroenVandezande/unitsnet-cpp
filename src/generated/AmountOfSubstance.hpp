#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class AmountOfSubstanceUnit : std::uint8_t
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
            const un_scalar_t value,
            const AmountOfSubstanceUnit unit = AmountOfSubstanceUnit::Moles)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const AmountOfSubstanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr AmountOfSubstance operator+(const AmountOfSubstance other) const noexcept
        {
            return AmountOfSubstance(value_ + other.value_);
        }

        [[nodiscard]] constexpr AmountOfSubstance operator-(const AmountOfSubstance other) const noexcept
        {
            return AmountOfSubstance(value_ - other.value_);
        }

        [[nodiscard]] constexpr AmountOfSubstance operator*(const un_scalar_t scalar) const noexcept
        {
            return AmountOfSubstance(value_ * scalar);
        }

        [[nodiscard]] constexpr AmountOfSubstance operator/(const un_scalar_t scalar) const noexcept
        {
            return AmountOfSubstance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const AmountOfSubstance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const AmountOfSubstance other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Moles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_moles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Moles);
        }


        [[nodiscard]] constexpr un_scalar_t femtomoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Femtomoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_femtomoles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Femtomoles);
        }


        [[nodiscard]] constexpr un_scalar_t picomoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Picomoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_picomoles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Picomoles);
        }


        [[nodiscard]] constexpr un_scalar_t nanomoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Nanomoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_nanomoles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Nanomoles);
        }


        [[nodiscard]] constexpr un_scalar_t micromoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Micromoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_micromoles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Micromoles);
        }


        [[nodiscard]] constexpr un_scalar_t millimoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Millimoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_millimoles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Millimoles);
        }


        [[nodiscard]] constexpr un_scalar_t centimoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Centimoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_centimoles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Centimoles);
        }


        [[nodiscard]] constexpr un_scalar_t decimoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Decimoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_decimoles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Decimoles);
        }


        [[nodiscard]] constexpr un_scalar_t kilomoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Kilomoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_kilomoles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Kilomoles);
        }


        [[nodiscard]] constexpr un_scalar_t megamoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Megamoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_megamoles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Megamoles);
        }


        [[nodiscard]] constexpr un_scalar_t pound_moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::PoundMoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_pound_moles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::PoundMoles);
        }


        [[nodiscard]] constexpr un_scalar_t nanopound_moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::NanopoundMoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_nanopound_moles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::NanopoundMoles);
        }


        [[nodiscard]] constexpr un_scalar_t micropound_moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::MicropoundMoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_micropound_moles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::MicropoundMoles);
        }


        [[nodiscard]] constexpr un_scalar_t millipound_moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::MillipoundMoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_millipound_moles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::MillipoundMoles);
        }


        [[nodiscard]] constexpr un_scalar_t centipound_moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::CentipoundMoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_centipound_moles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::CentipoundMoles);
        }


        [[nodiscard]] constexpr un_scalar_t decipound_moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::DecipoundMoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_decipound_moles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::DecipoundMoles);
        }


        [[nodiscard]] constexpr un_scalar_t kilopound_moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::KilopoundMoles);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_kilopound_moles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::KilopoundMoles);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, AmountOfSubstanceUnit unit)
        {
            switch (unit)
            {

            case AmountOfSubstanceUnit::Moles:
                return value;

            case AmountOfSubstanceUnit::Femtomoles:
                return (value * static_cast<un_scalar_t>(1e-15));

            case AmountOfSubstanceUnit::Picomoles:
                return (value * static_cast<un_scalar_t>(1e-12));

            case AmountOfSubstanceUnit::Nanomoles:
                return (value * static_cast<un_scalar_t>(1e-9));

            case AmountOfSubstanceUnit::Micromoles:
                return (value * static_cast<un_scalar_t>(1e-6));

            case AmountOfSubstanceUnit::Millimoles:
                return (value * static_cast<un_scalar_t>(1e-3));

            case AmountOfSubstanceUnit::Centimoles:
                return (value * static_cast<un_scalar_t>(1e-2));

            case AmountOfSubstanceUnit::Decimoles:
                return (value * static_cast<un_scalar_t>(1e-1));

            case AmountOfSubstanceUnit::Kilomoles:
                return (value * static_cast<un_scalar_t>(1e3));

            case AmountOfSubstanceUnit::Megamoles:
                return (value * static_cast<un_scalar_t>(1e6));

            case AmountOfSubstanceUnit::PoundMoles:
                return value * static_cast<un_scalar_t>(453.59237);

            case AmountOfSubstanceUnit::NanopoundMoles:
                return (value * static_cast<un_scalar_t>(1e-9)) * static_cast<un_scalar_t>(453.59237);

            case AmountOfSubstanceUnit::MicropoundMoles:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(453.59237);

            case AmountOfSubstanceUnit::MillipoundMoles:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(453.59237);

            case AmountOfSubstanceUnit::CentipoundMoles:
                return (value * static_cast<un_scalar_t>(1e-2)) * static_cast<un_scalar_t>(453.59237);

            case AmountOfSubstanceUnit::DecipoundMoles:
                return (value * static_cast<un_scalar_t>(1e-1)) * static_cast<un_scalar_t>(453.59237);

            case AmountOfSubstanceUnit::KilopoundMoles:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(453.59237);

            }

            throw std::invalid_argument("Unknown AmountOfSubstance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const AmountOfSubstanceUnit unit) const
        {
            switch (unit)
            {

            case AmountOfSubstanceUnit::Moles:
                return value_;

            case AmountOfSubstanceUnit::Femtomoles:
                return (value_) / static_cast<un_scalar_t>(1e-15);

            case AmountOfSubstanceUnit::Picomoles:
                return (value_) / static_cast<un_scalar_t>(1e-12);

            case AmountOfSubstanceUnit::Nanomoles:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case AmountOfSubstanceUnit::Micromoles:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case AmountOfSubstanceUnit::Millimoles:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case AmountOfSubstanceUnit::Centimoles:
                return (value_) / static_cast<un_scalar_t>(1e-2);

            case AmountOfSubstanceUnit::Decimoles:
                return (value_) / static_cast<un_scalar_t>(1e-1);

            case AmountOfSubstanceUnit::Kilomoles:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case AmountOfSubstanceUnit::Megamoles:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case AmountOfSubstanceUnit::PoundMoles:
                return value_ / static_cast<un_scalar_t>(453.59237);

            case AmountOfSubstanceUnit::NanopoundMoles:
                return (value_ / static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(1e-9);

            case AmountOfSubstanceUnit::MicropoundMoles:
                return (value_ / static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(1e-6);

            case AmountOfSubstanceUnit::MillipoundMoles:
                return (value_ / static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(1e-3);

            case AmountOfSubstanceUnit::CentipoundMoles:
                return (value_ / static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(1e-2);

            case AmountOfSubstanceUnit::DecipoundMoles:
                return (value_ / static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(1e-1);

            case AmountOfSubstanceUnit::KilopoundMoles:
                return (value_ / static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown AmountOfSubstance unit.");
        }

        un_scalar_t value_;
    };
}
