#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class MassFractionUnit : std::uint8_t
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
    class MassFraction : public UnitsNetBase
    {
    public:
        constexpr explicit MassFraction(
            const un_scalar_t value,
            const MassFractionUnit unit = MassFractionUnit::DecimalFractions)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MassFractionUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MassFraction operator+(const MassFraction& other) const noexcept
        {
            return MassFraction(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr MassFraction operator-(const MassFraction& other)const noexcept
        {
            return MassFraction(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr MassFraction operator*(const un_scalar_t scalar) const noexcept
        {
            return MassFraction(base_value() * scalar);
        }

        [[nodiscard]] constexpr MassFraction operator/(const un_scalar_t scalar) const noexcept
        {
            return MassFraction(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MassFraction& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const MassFraction& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const MassFraction& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t decimal_fractions() const
        {
            return convert_from_base(MassFractionUnit::DecimalFractions);
        }

        [[nodiscard]] static constexpr MassFraction from_decimal_fractions(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::DecimalFractions);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_gram() const
        {
            return convert_from_base(MassFractionUnit::GramsPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_grams_per_gram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::GramsPerGram);
        }

        [[nodiscard]] constexpr un_scalar_t nanograms_per_gram() const
        {
            return convert_from_base(MassFractionUnit::NanogramsPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_nanograms_per_gram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::NanogramsPerGram);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_gram() const
        {
            return convert_from_base(MassFractionUnit::MicrogramsPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_micrograms_per_gram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::MicrogramsPerGram);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_gram() const
        {
            return convert_from_base(MassFractionUnit::MilligramsPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_milligrams_per_gram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::MilligramsPerGram);
        }

        [[nodiscard]] constexpr un_scalar_t centigrams_per_gram() const
        {
            return convert_from_base(MassFractionUnit::CentigramsPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_centigrams_per_gram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::CentigramsPerGram);
        }

        [[nodiscard]] constexpr un_scalar_t decigrams_per_gram() const
        {
            return convert_from_base(MassFractionUnit::DecigramsPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_decigrams_per_gram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::DecigramsPerGram);
        }

        [[nodiscard]] constexpr un_scalar_t decagrams_per_gram() const
        {
            return convert_from_base(MassFractionUnit::DecagramsPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_decagrams_per_gram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::DecagramsPerGram);
        }

        [[nodiscard]] constexpr un_scalar_t hectograms_per_gram() const
        {
            return convert_from_base(MassFractionUnit::HectogramsPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_hectograms_per_gram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::HectogramsPerGram);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_gram() const
        {
            return convert_from_base(MassFractionUnit::KilogramsPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_kilograms_per_gram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::KilogramsPerGram);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::GramsPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_grams_per_kilogram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::GramsPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t nanograms_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::NanogramsPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_nanograms_per_kilogram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::NanogramsPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::MicrogramsPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_micrograms_per_kilogram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::MicrogramsPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::MilligramsPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_milligrams_per_kilogram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::MilligramsPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t centigrams_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::CentigramsPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_centigrams_per_kilogram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::CentigramsPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t decigrams_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::DecigramsPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_decigrams_per_kilogram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::DecigramsPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t decagrams_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::DecagramsPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_decagrams_per_kilogram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::DecagramsPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t hectograms_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::HectogramsPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_hectograms_per_kilogram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::HectogramsPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::KilogramsPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_kilograms_per_kilogram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::KilogramsPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t percent() const
        {
            return convert_from_base(MassFractionUnit::Percent);
        }

        [[nodiscard]] static constexpr MassFraction from_percent(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::Percent);
        }

        [[nodiscard]] constexpr un_scalar_t parts_per_thousand() const
        {
            return convert_from_base(MassFractionUnit::PartsPerThousand);
        }

        [[nodiscard]] static constexpr MassFraction from_parts_per_thousand(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::PartsPerThousand);
        }

        [[nodiscard]] constexpr un_scalar_t parts_per_million() const
        {
            return convert_from_base(MassFractionUnit::PartsPerMillion);
        }

        [[nodiscard]] static constexpr MassFraction from_parts_per_million(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::PartsPerMillion);
        }

        [[nodiscard]] constexpr un_scalar_t parts_per_billion() const
        {
            return convert_from_base(MassFractionUnit::PartsPerBillion);
        }

        [[nodiscard]] static constexpr MassFraction from_parts_per_billion(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::PartsPerBillion);
        }

        [[nodiscard]] constexpr un_scalar_t parts_per_trillion() const
        {
            return convert_from_base(MassFractionUnit::PartsPerTrillion);
        }

        [[nodiscard]] static constexpr MassFraction from_parts_per_trillion(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::PartsPerTrillion);
        }

        [[nodiscard]] static constexpr MassFraction from_invalid()
        {
            return MassFraction(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MassFractionUnit unit)
        {
            switch (unit)
            {

            case MassFractionUnit::DecimalFractions:
                return value;

            case MassFractionUnit::GramsPerGram:
                return value;

            case MassFractionUnit::NanogramsPerGram:
                return (value * static_cast<un_scalar_t>(1e-9));

            case MassFractionUnit::MicrogramsPerGram:
                return (value * static_cast<un_scalar_t>(1e-6));

            case MassFractionUnit::MilligramsPerGram:
                return (value * static_cast<un_scalar_t>(1e-3));

            case MassFractionUnit::CentigramsPerGram:
                return (value * static_cast<un_scalar_t>(1e-2));

            case MassFractionUnit::DecigramsPerGram:
                return (value * static_cast<un_scalar_t>(1e-1));

            case MassFractionUnit::DecagramsPerGram:
                return (value * static_cast<un_scalar_t>(1e1));

            case MassFractionUnit::HectogramsPerGram:
                return (value * static_cast<un_scalar_t>(1e2));

            case MassFractionUnit::KilogramsPerGram:
                return (value * static_cast<un_scalar_t>(1e3));

            case MassFractionUnit::GramsPerKilogram:
                return value / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::NanogramsPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::MicrogramsPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::MilligramsPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::CentigramsPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::DecigramsPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::DecagramsPerKilogram:
                return (value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::HectogramsPerKilogram:
                return (value * static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::KilogramsPerKilogram:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::Percent:
                return value / static_cast<un_scalar_t>(1e2);

            case MassFractionUnit::PartsPerThousand:
                return value / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::PartsPerMillion:
                return value / static_cast<un_scalar_t>(1e6);

            case MassFractionUnit::PartsPerBillion:
                return value / static_cast<un_scalar_t>(1e9);

            case MassFractionUnit::PartsPerTrillion:
                return value / static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown MassFraction unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MassFractionUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case MassFractionUnit::DecimalFractions:
                return base_value;

            case MassFractionUnit::GramsPerGram:
                return base_value;

            case MassFractionUnit::NanogramsPerGram:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case MassFractionUnit::MicrogramsPerGram:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case MassFractionUnit::MilligramsPerGram:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case MassFractionUnit::CentigramsPerGram:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case MassFractionUnit::DecigramsPerGram:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case MassFractionUnit::DecagramsPerGram:
                return (base_value) / static_cast<un_scalar_t>(1e1);

            case MassFractionUnit::HectogramsPerGram:
                return (base_value) / static_cast<un_scalar_t>(1e2);

            case MassFractionUnit::KilogramsPerGram:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::GramsPerKilogram:
                return base_value * static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::NanogramsPerKilogram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-9);

            case MassFractionUnit::MicrogramsPerKilogram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-6);

            case MassFractionUnit::MilligramsPerKilogram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case MassFractionUnit::CentigramsPerKilogram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-2);

            case MassFractionUnit::DecigramsPerKilogram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-1);

            case MassFractionUnit::DecagramsPerKilogram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e1);

            case MassFractionUnit::HectogramsPerKilogram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e2);

            case MassFractionUnit::KilogramsPerKilogram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::Percent:
                return base_value * static_cast<un_scalar_t>(1e2);

            case MassFractionUnit::PartsPerThousand:
                return base_value * static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::PartsPerMillion:
                return base_value * static_cast<un_scalar_t>(1e6);

            case MassFractionUnit::PartsPerBillion:
                return base_value * static_cast<un_scalar_t>(1e9);

            case MassFractionUnit::PartsPerTrillion:
                return base_value * static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown MassFraction unit.");
        }

        un_scalar_t value_;
        MassFractionUnit value_unit_type_;       
    };
}
