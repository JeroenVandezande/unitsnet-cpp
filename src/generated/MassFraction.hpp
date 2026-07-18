#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class MassFractionUnit : std::uint16_t
    {
        DecimalFractions,
        GramsPerGram,
        NanogramsPerGram,
        MicrogramsPerGram,
        MilligramsPerGram,
        CentigramsPerGram,
        DecigramsPerGram,
        DecagramsPerGram,
        HectogramsPerGram,
        KilogramsPerGram,
        GramsPerKilogram,
        NanogramsPerKilogram,
        MicrogramsPerKilogram,
        MilligramsPerKilogram,
        CentigramsPerKilogram,
        DecigramsPerKilogram,
        DecagramsPerKilogram,
        HectogramsPerKilogram,
        KilogramsPerKilogram,
        Percent,
        PartsPerThousand,
        PartsPerMillion,
        PartsPerBillion,
        PartsPerTrillion,
    };

    /// <summary>The mass fraction is defined as the mass of a constituent divided by the total mass of the mixture.</summary>
    class MassFraction
    {
    public:
        constexpr explicit MassFraction(
            double value,
            MassFractionUnit unit = MassFractionUnit::DecimalFractions)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(MassFractionUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MassFraction operator+(MassFraction other) const noexcept
        {
            return MassFraction(value_ + other.value_);
        }

        [[nodiscard]] constexpr MassFraction operator-(MassFraction other) const noexcept
        {
            return MassFraction(value_ - other.value_);
        }

        [[nodiscard]] constexpr MassFraction operator*(double scalar) const noexcept
        {
            return MassFraction(value_ * scalar);
        }

        [[nodiscard]] constexpr MassFraction operator/(double scalar) const noexcept
        {
            return MassFraction(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(MassFraction other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(MassFraction other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double decimal_fractions() const
        {
            return convert_from_base(MassFractionUnit::DecimalFractions);
        }

        [[nodiscard]] static constexpr MassFraction from_decimal_fractions(double value)
        {
            return MassFraction(value, MassFractionUnit::DecimalFractions);
        }


        [[nodiscard]] constexpr double grams_per_gram() const
        {
            return convert_from_base(MassFractionUnit::GramsPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_grams_per_gram(double value)
        {
            return MassFraction(value, MassFractionUnit::GramsPerGram);
        }


        [[nodiscard]] constexpr double nanograms_per_gram() const
        {
            return convert_from_base(MassFractionUnit::NanogramsPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_nanograms_per_gram(double value)
        {
            return MassFraction(value, MassFractionUnit::NanogramsPerGram);
        }


        [[nodiscard]] constexpr double micrograms_per_gram() const
        {
            return convert_from_base(MassFractionUnit::MicrogramsPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_micrograms_per_gram(double value)
        {
            return MassFraction(value, MassFractionUnit::MicrogramsPerGram);
        }


        [[nodiscard]] constexpr double milligrams_per_gram() const
        {
            return convert_from_base(MassFractionUnit::MilligramsPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_milligrams_per_gram(double value)
        {
            return MassFraction(value, MassFractionUnit::MilligramsPerGram);
        }


        [[nodiscard]] constexpr double centigrams_per_gram() const
        {
            return convert_from_base(MassFractionUnit::CentigramsPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_centigrams_per_gram(double value)
        {
            return MassFraction(value, MassFractionUnit::CentigramsPerGram);
        }


        [[nodiscard]] constexpr double decigrams_per_gram() const
        {
            return convert_from_base(MassFractionUnit::DecigramsPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_decigrams_per_gram(double value)
        {
            return MassFraction(value, MassFractionUnit::DecigramsPerGram);
        }


        [[nodiscard]] constexpr double decagrams_per_gram() const
        {
            return convert_from_base(MassFractionUnit::DecagramsPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_decagrams_per_gram(double value)
        {
            return MassFraction(value, MassFractionUnit::DecagramsPerGram);
        }


        [[nodiscard]] constexpr double hectograms_per_gram() const
        {
            return convert_from_base(MassFractionUnit::HectogramsPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_hectograms_per_gram(double value)
        {
            return MassFraction(value, MassFractionUnit::HectogramsPerGram);
        }


        [[nodiscard]] constexpr double kilograms_per_gram() const
        {
            return convert_from_base(MassFractionUnit::KilogramsPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_kilograms_per_gram(double value)
        {
            return MassFraction(value, MassFractionUnit::KilogramsPerGram);
        }


        [[nodiscard]] constexpr double grams_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::GramsPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_grams_per_kilogram(double value)
        {
            return MassFraction(value, MassFractionUnit::GramsPerKilogram);
        }


        [[nodiscard]] constexpr double nanograms_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::NanogramsPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_nanograms_per_kilogram(double value)
        {
            return MassFraction(value, MassFractionUnit::NanogramsPerKilogram);
        }


        [[nodiscard]] constexpr double micrograms_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::MicrogramsPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_micrograms_per_kilogram(double value)
        {
            return MassFraction(value, MassFractionUnit::MicrogramsPerKilogram);
        }


        [[nodiscard]] constexpr double milligrams_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::MilligramsPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_milligrams_per_kilogram(double value)
        {
            return MassFraction(value, MassFractionUnit::MilligramsPerKilogram);
        }


        [[nodiscard]] constexpr double centigrams_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::CentigramsPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_centigrams_per_kilogram(double value)
        {
            return MassFraction(value, MassFractionUnit::CentigramsPerKilogram);
        }


        [[nodiscard]] constexpr double decigrams_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::DecigramsPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_decigrams_per_kilogram(double value)
        {
            return MassFraction(value, MassFractionUnit::DecigramsPerKilogram);
        }


        [[nodiscard]] constexpr double decagrams_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::DecagramsPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_decagrams_per_kilogram(double value)
        {
            return MassFraction(value, MassFractionUnit::DecagramsPerKilogram);
        }


        [[nodiscard]] constexpr double hectograms_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::HectogramsPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_hectograms_per_kilogram(double value)
        {
            return MassFraction(value, MassFractionUnit::HectogramsPerKilogram);
        }


        [[nodiscard]] constexpr double kilograms_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::KilogramsPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_kilograms_per_kilogram(double value)
        {
            return MassFraction(value, MassFractionUnit::KilogramsPerKilogram);
        }


        [[nodiscard]] constexpr double percent() const
        {
            return convert_from_base(MassFractionUnit::Percent);
        }

        [[nodiscard]] static constexpr MassFraction from_percent(double value)
        {
            return MassFraction(value, MassFractionUnit::Percent);
        }


        [[nodiscard]] constexpr double parts_per_thousand() const
        {
            return convert_from_base(MassFractionUnit::PartsPerThousand);
        }

        [[nodiscard]] static constexpr MassFraction from_parts_per_thousand(double value)
        {
            return MassFraction(value, MassFractionUnit::PartsPerThousand);
        }


        [[nodiscard]] constexpr double parts_per_million() const
        {
            return convert_from_base(MassFractionUnit::PartsPerMillion);
        }

        [[nodiscard]] static constexpr MassFraction from_parts_per_million(double value)
        {
            return MassFraction(value, MassFractionUnit::PartsPerMillion);
        }


        [[nodiscard]] constexpr double parts_per_billion() const
        {
            return convert_from_base(MassFractionUnit::PartsPerBillion);
        }

        [[nodiscard]] static constexpr MassFraction from_parts_per_billion(double value)
        {
            return MassFraction(value, MassFractionUnit::PartsPerBillion);
        }


        [[nodiscard]] constexpr double parts_per_trillion() const
        {
            return convert_from_base(MassFractionUnit::PartsPerTrillion);
        }

        [[nodiscard]] static constexpr MassFraction from_parts_per_trillion(double value)
        {
            return MassFraction(value, MassFractionUnit::PartsPerTrillion);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, MassFractionUnit unit)
        {
            switch (unit)
            {

            case MassFractionUnit::DecimalFractions:
                return value;

            case MassFractionUnit::GramsPerGram:
                return value;

            case MassFractionUnit::NanogramsPerGram:
                return (value * 1e-9);

            case MassFractionUnit::MicrogramsPerGram:
                return (value * 1e-6);

            case MassFractionUnit::MilligramsPerGram:
                return (value * 1e-3);

            case MassFractionUnit::CentigramsPerGram:
                return (value * 1e-2);

            case MassFractionUnit::DecigramsPerGram:
                return (value * 1e-1);

            case MassFractionUnit::DecagramsPerGram:
                return (value * 1e1);

            case MassFractionUnit::HectogramsPerGram:
                return (value * 1e2);

            case MassFractionUnit::KilogramsPerGram:
                return (value * 1e3);

            case MassFractionUnit::GramsPerKilogram:
                return value / 1e3;

            case MassFractionUnit::NanogramsPerKilogram:
                return (value * 1e-9) / 1e3;

            case MassFractionUnit::MicrogramsPerKilogram:
                return (value * 1e-6) / 1e3;

            case MassFractionUnit::MilligramsPerKilogram:
                return (value * 1e-3) / 1e3;

            case MassFractionUnit::CentigramsPerKilogram:
                return (value * 1e-2) / 1e3;

            case MassFractionUnit::DecigramsPerKilogram:
                return (value * 1e-1) / 1e3;

            case MassFractionUnit::DecagramsPerKilogram:
                return (value * 1e1) / 1e3;

            case MassFractionUnit::HectogramsPerKilogram:
                return (value * 1e2) / 1e3;

            case MassFractionUnit::KilogramsPerKilogram:
                return (value * 1e3) / 1e3;

            case MassFractionUnit::Percent:
                return value / 1e2;

            case MassFractionUnit::PartsPerThousand:
                return value / 1e3;

            case MassFractionUnit::PartsPerMillion:
                return value / 1e6;

            case MassFractionUnit::PartsPerBillion:
                return value / 1e9;

            case MassFractionUnit::PartsPerTrillion:
                return value / 1e12;

            }

            throw std::invalid_argument("Unknown MassFraction unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(MassFractionUnit unit) const
        {
            switch (unit)
            {

            case MassFractionUnit::DecimalFractions:
                return value_;

            case MassFractionUnit::GramsPerGram:
                return value_;

            case MassFractionUnit::NanogramsPerGram:
                return (value_) / 1e-9;

            case MassFractionUnit::MicrogramsPerGram:
                return (value_) / 1e-6;

            case MassFractionUnit::MilligramsPerGram:
                return (value_) / 1e-3;

            case MassFractionUnit::CentigramsPerGram:
                return (value_) / 1e-2;

            case MassFractionUnit::DecigramsPerGram:
                return (value_) / 1e-1;

            case MassFractionUnit::DecagramsPerGram:
                return (value_) / 1e1;

            case MassFractionUnit::HectogramsPerGram:
                return (value_) / 1e2;

            case MassFractionUnit::KilogramsPerGram:
                return (value_) / 1e3;

            case MassFractionUnit::GramsPerKilogram:
                return value_ * 1e3;

            case MassFractionUnit::NanogramsPerKilogram:
                return (value_ * 1e3) / 1e-9;

            case MassFractionUnit::MicrogramsPerKilogram:
                return (value_ * 1e3) / 1e-6;

            case MassFractionUnit::MilligramsPerKilogram:
                return (value_ * 1e3) / 1e-3;

            case MassFractionUnit::CentigramsPerKilogram:
                return (value_ * 1e3) / 1e-2;

            case MassFractionUnit::DecigramsPerKilogram:
                return (value_ * 1e3) / 1e-1;

            case MassFractionUnit::DecagramsPerKilogram:
                return (value_ * 1e3) / 1e1;

            case MassFractionUnit::HectogramsPerKilogram:
                return (value_ * 1e3) / 1e2;

            case MassFractionUnit::KilogramsPerKilogram:
                return (value_ * 1e3) / 1e3;

            case MassFractionUnit::Percent:
                return value_ * 1e2;

            case MassFractionUnit::PartsPerThousand:
                return value_ * 1e3;

            case MassFractionUnit::PartsPerMillion:
                return value_ * 1e6;

            case MassFractionUnit::PartsPerBillion:
                return value_ * 1e9;

            case MassFractionUnit::PartsPerTrillion:
                return value_ * 1e12;

            }

            throw std::invalid_argument("Unknown MassFraction unit.");
        }

        double value_;
    };
}
