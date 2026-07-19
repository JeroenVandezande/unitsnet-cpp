#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class ElectricResistivityUnit : std::uint8_t
    {
        OhmMeters,
        PicoohmMeters,
        NanoohmMeters,
        MicroohmMeters,
        MilliohmMeters,
        KiloohmMeters,
        MegaohmMeters,
        OhmsCentimeter,
        PicoohmsCentimeter,
        NanoohmsCentimeter,
        MicroohmsCentimeter,
        MilliohmsCentimeter,
        KiloohmsCentimeter,
        MegaohmsCentimeter,
    };

    /// <summary>Electrical resistivity (also known as resistivity, specific electrical resistance, or volume resistivity) is a fundamental property that quantifies how strongly a given material opposes the flow of electric current.</summary>
    class ElectricResistivity
    {
    public:
        constexpr explicit ElectricResistivity(
            const un_scalar_t value,
            const ElectricResistivityUnit unit = ElectricResistivityUnit::OhmMeters)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit ElectricResistivity(const bool isValid)
        {
            _isInvalid = !isValid;
        }
        
        void SetValueAsInvalid()
        {
            _isInvalid = true;
        }
        
        void SetValueAsValid()
        {
            _isInvalid = false;
        }
        
        [[nodiscard]] bool GetValueIsValid() const
        {
            return _isInvalid;
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricResistivityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricResistivity operator+(const ElectricResistivity other) const noexcept
        {
            return ElectricResistivity(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricResistivity operator-(const ElectricResistivity other) const noexcept
        {
            return ElectricResistivity(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricResistivity operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricResistivity(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricResistivity operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricResistivity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricResistivity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const ElectricResistivity other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricResistivity other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t ohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::OhmMeters);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_ohm_meters(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::OhmMeters);
        }


        [[nodiscard]] constexpr un_scalar_t picoohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::PicoohmMeters);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_picoohm_meters(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::PicoohmMeters);
        }


        [[nodiscard]] constexpr un_scalar_t nanoohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::NanoohmMeters);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_nanoohm_meters(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::NanoohmMeters);
        }


        [[nodiscard]] constexpr un_scalar_t microohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::MicroohmMeters);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_microohm_meters(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MicroohmMeters);
        }


        [[nodiscard]] constexpr un_scalar_t milliohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::MilliohmMeters);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_milliohm_meters(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MilliohmMeters);
        }


        [[nodiscard]] constexpr un_scalar_t kiloohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::KiloohmMeters);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_kiloohm_meters(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::KiloohmMeters);
        }


        [[nodiscard]] constexpr un_scalar_t megaohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::MegaohmMeters);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_megaohm_meters(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MegaohmMeters);
        }


        [[nodiscard]] constexpr un_scalar_t ohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::OhmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_ohms_centimeter(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::OhmsCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t picoohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::PicoohmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_picoohms_centimeter(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::PicoohmsCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t nanoohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::NanoohmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_nanoohms_centimeter(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::NanoohmsCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t microohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::MicroohmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_microohms_centimeter(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MicroohmsCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t milliohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::MilliohmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_milliohms_centimeter(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MilliohmsCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kiloohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::KiloohmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_kiloohms_centimeter(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::KiloohmsCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t megaohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::MegaohmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_megaohms_centimeter(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MegaohmsCentimeter);
        }


        [[nodiscard]] static constexpr ElectricResistivity from_invalid()
        {
            return ElectricResistivity(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricResistivityUnit unit)
        {
            switch (unit)
            {

            case ElectricResistivityUnit::OhmMeters:
                return value;

            case ElectricResistivityUnit::PicoohmMeters:
                return (value * static_cast<un_scalar_t>(1e-12));

            case ElectricResistivityUnit::NanoohmMeters:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricResistivityUnit::MicroohmMeters:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricResistivityUnit::MilliohmMeters:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricResistivityUnit::KiloohmMeters:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricResistivityUnit::MegaohmMeters:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricResistivityUnit::OhmsCentimeter:
                return value / static_cast<un_scalar_t>(100);

            case ElectricResistivityUnit::PicoohmsCentimeter:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(100);

            case ElectricResistivityUnit::NanoohmsCentimeter:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(100);

            case ElectricResistivityUnit::MicroohmsCentimeter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(100);

            case ElectricResistivityUnit::MilliohmsCentimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(100);

            case ElectricResistivityUnit::KiloohmsCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(100);

            case ElectricResistivityUnit::MegaohmsCentimeter:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(100);

            }

            throw std::invalid_argument("Unknown ElectricResistivity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricResistivityUnit unit) const
        {
            switch (unit)
            {

            case ElectricResistivityUnit::OhmMeters:
                return value_;

            case ElectricResistivityUnit::PicoohmMeters:
                return (value_) / static_cast<un_scalar_t>(1e-12);

            case ElectricResistivityUnit::NanoohmMeters:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case ElectricResistivityUnit::MicroohmMeters:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case ElectricResistivityUnit::MilliohmMeters:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case ElectricResistivityUnit::KiloohmMeters:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case ElectricResistivityUnit::MegaohmMeters:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case ElectricResistivityUnit::OhmsCentimeter:
                return value_ * static_cast<un_scalar_t>(100);

            case ElectricResistivityUnit::PicoohmsCentimeter:
                return (value_ * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-12);

            case ElectricResistivityUnit::NanoohmsCentimeter:
                return (value_ * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-9);

            case ElectricResistivityUnit::MicroohmsCentimeter:
                return (value_ * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-6);

            case ElectricResistivityUnit::MilliohmsCentimeter:
                return (value_ * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-3);

            case ElectricResistivityUnit::KiloohmsCentimeter:
                return (value_ * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e3);

            case ElectricResistivityUnit::MegaohmsCentimeter:
                return (value_ * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown ElectricResistivity unit.");
        }

        un_scalar_t value_;
    };
}
