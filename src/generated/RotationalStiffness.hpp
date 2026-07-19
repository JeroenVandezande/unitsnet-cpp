#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class RotationalStiffnessUnit : std::uint8_t
    {
        NewtonMetersPerRadian,
        KilonewtonMetersPerRadian,
        MeganewtonMetersPerRadian,
        PoundForceFeetPerDegrees,
        KilopoundForceFeetPerDegrees,
        NewtonMillimetersPerDegree,
        NanonewtonMillimetersPerDegree,
        MicronewtonMillimetersPerDegree,
        MillinewtonMillimetersPerDegree,
        CentinewtonMillimetersPerDegree,
        DecinewtonMillimetersPerDegree,
        DecanewtonMillimetersPerDegree,
        KilonewtonMillimetersPerDegree,
        MeganewtonMillimetersPerDegree,
        NewtonMetersPerDegree,
        NanonewtonMetersPerDegree,
        MicronewtonMetersPerDegree,
        MillinewtonMetersPerDegree,
        CentinewtonMetersPerDegree,
        DecinewtonMetersPerDegree,
        DecanewtonMetersPerDegree,
        KilonewtonMetersPerDegree,
        MeganewtonMetersPerDegree,
        NewtonMillimetersPerRadian,
        NanonewtonMillimetersPerRadian,
        MicronewtonMillimetersPerRadian,
        MillinewtonMillimetersPerRadian,
        CentinewtonMillimetersPerRadian,
        DecinewtonMillimetersPerRadian,
        DecanewtonMillimetersPerRadian,
        KilonewtonMillimetersPerRadian,
        MeganewtonMillimetersPerRadian,
        PoundForceFeetPerRadian,
        KilopoundForceFeetPerRadian,
    };

    /// <summary>https://en.wikipedia.org/wiki/Stiffness#Rotational_stiffness</summary>
    class RotationalStiffness
    {
    public:
        constexpr explicit RotationalStiffness(
            const un_scalar_t value,
            const RotationalStiffnessUnit unit = RotationalStiffnessUnit::NewtonMetersPerRadian)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const RotationalStiffnessUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RotationalStiffness operator+(const RotationalStiffness other) const noexcept
        {
            return RotationalStiffness(value_ + other.value_);
        }

        [[nodiscard]] constexpr RotationalStiffness operator-(const RotationalStiffness other) const noexcept
        {
            return RotationalStiffness(value_ - other.value_);
        }

        [[nodiscard]] constexpr RotationalStiffness operator*(const un_scalar_t scalar) const noexcept
        {
            return RotationalStiffness(value_ * scalar);
        }

        [[nodiscard]] constexpr RotationalStiffness operator/(const un_scalar_t scalar) const noexcept
        {
            return RotationalStiffness(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RotationalStiffness other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const RotationalStiffness other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t newton_meters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::NewtonMetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_newton_meters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::NewtonMetersPerRadian);
        }


        [[nodiscard]] constexpr un_scalar_t kilonewton_meters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::KilonewtonMetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_kilonewton_meters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::KilonewtonMetersPerRadian);
        }


        [[nodiscard]] constexpr un_scalar_t meganewton_meters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::MeganewtonMetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_meganewton_meters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MeganewtonMetersPerRadian);
        }


        [[nodiscard]] constexpr un_scalar_t pound_force_feet_per_degrees() const
        {
            return convert_from_base(RotationalStiffnessUnit::PoundForceFeetPerDegrees);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_pound_force_feet_per_degrees(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::PoundForceFeetPerDegrees);
        }


        [[nodiscard]] constexpr un_scalar_t kilopound_force_feet_per_degrees() const
        {
            return convert_from_base(RotationalStiffnessUnit::KilopoundForceFeetPerDegrees);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_kilopound_force_feet_per_degrees(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::KilopoundForceFeetPerDegrees);
        }


        [[nodiscard]] constexpr un_scalar_t newton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::NewtonMillimetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_newton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::NewtonMillimetersPerDegree);
        }


        [[nodiscard]] constexpr un_scalar_t nanonewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::NanonewtonMillimetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_nanonewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::NanonewtonMillimetersPerDegree);
        }


        [[nodiscard]] constexpr un_scalar_t micronewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::MicronewtonMillimetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_micronewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MicronewtonMillimetersPerDegree);
        }


        [[nodiscard]] constexpr un_scalar_t millinewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::MillinewtonMillimetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_millinewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MillinewtonMillimetersPerDegree);
        }


        [[nodiscard]] constexpr un_scalar_t centinewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::CentinewtonMillimetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_centinewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::CentinewtonMillimetersPerDegree);
        }


        [[nodiscard]] constexpr un_scalar_t decinewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::DecinewtonMillimetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_decinewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::DecinewtonMillimetersPerDegree);
        }


        [[nodiscard]] constexpr un_scalar_t decanewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::DecanewtonMillimetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_decanewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::DecanewtonMillimetersPerDegree);
        }


        [[nodiscard]] constexpr un_scalar_t kilonewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::KilonewtonMillimetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_kilonewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::KilonewtonMillimetersPerDegree);
        }


        [[nodiscard]] constexpr un_scalar_t meganewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::MeganewtonMillimetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_meganewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MeganewtonMillimetersPerDegree);
        }


        [[nodiscard]] constexpr un_scalar_t newton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::NewtonMetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_newton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::NewtonMetersPerDegree);
        }


        [[nodiscard]] constexpr un_scalar_t nanonewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::NanonewtonMetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_nanonewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::NanonewtonMetersPerDegree);
        }


        [[nodiscard]] constexpr un_scalar_t micronewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::MicronewtonMetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_micronewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MicronewtonMetersPerDegree);
        }


        [[nodiscard]] constexpr un_scalar_t millinewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::MillinewtonMetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_millinewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MillinewtonMetersPerDegree);
        }


        [[nodiscard]] constexpr un_scalar_t centinewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::CentinewtonMetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_centinewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::CentinewtonMetersPerDegree);
        }


        [[nodiscard]] constexpr un_scalar_t decinewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::DecinewtonMetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_decinewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::DecinewtonMetersPerDegree);
        }


        [[nodiscard]] constexpr un_scalar_t decanewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::DecanewtonMetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_decanewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::DecanewtonMetersPerDegree);
        }


        [[nodiscard]] constexpr un_scalar_t kilonewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::KilonewtonMetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_kilonewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::KilonewtonMetersPerDegree);
        }


        [[nodiscard]] constexpr un_scalar_t meganewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::MeganewtonMetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_meganewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MeganewtonMetersPerDegree);
        }


        [[nodiscard]] constexpr un_scalar_t newton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::NewtonMillimetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_newton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::NewtonMillimetersPerRadian);
        }


        [[nodiscard]] constexpr un_scalar_t nanonewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::NanonewtonMillimetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_nanonewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::NanonewtonMillimetersPerRadian);
        }


        [[nodiscard]] constexpr un_scalar_t micronewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::MicronewtonMillimetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_micronewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MicronewtonMillimetersPerRadian);
        }


        [[nodiscard]] constexpr un_scalar_t millinewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::MillinewtonMillimetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_millinewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MillinewtonMillimetersPerRadian);
        }


        [[nodiscard]] constexpr un_scalar_t centinewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::CentinewtonMillimetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_centinewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::CentinewtonMillimetersPerRadian);
        }


        [[nodiscard]] constexpr un_scalar_t decinewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::DecinewtonMillimetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_decinewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::DecinewtonMillimetersPerRadian);
        }


        [[nodiscard]] constexpr un_scalar_t decanewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::DecanewtonMillimetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_decanewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::DecanewtonMillimetersPerRadian);
        }


        [[nodiscard]] constexpr un_scalar_t kilonewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::KilonewtonMillimetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_kilonewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::KilonewtonMillimetersPerRadian);
        }


        [[nodiscard]] constexpr un_scalar_t meganewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::MeganewtonMillimetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_meganewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MeganewtonMillimetersPerRadian);
        }


        [[nodiscard]] constexpr un_scalar_t pound_force_feet_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::PoundForceFeetPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_pound_force_feet_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::PoundForceFeetPerRadian);
        }


        [[nodiscard]] constexpr un_scalar_t kilopound_force_feet_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::KilopoundForceFeetPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_kilopound_force_feet_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::KilopoundForceFeetPerRadian);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RotationalStiffnessUnit unit)
        {
            switch (unit)
            {

            case RotationalStiffnessUnit::NewtonMetersPerRadian:
                return value;

            case RotationalStiffnessUnit::KilonewtonMetersPerRadian:
                return (value * static_cast<un_scalar_t>(1e3));

            case RotationalStiffnessUnit::MeganewtonMetersPerRadian:
                return (value * static_cast<un_scalar_t>(1e6));

            case RotationalStiffnessUnit::PoundForceFeetPerDegrees:
                return value * (4.4482216152605 * 0.3048 * 180 / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::KilopoundForceFeetPerDegrees:
                return value * (4.4482216152605e3 * 0.3048 * 180 / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::NewtonMillimetersPerDegree:
                return value * 180 / std::numbers::pi_v<un_scalar_t> * 0.001;

            case RotationalStiffnessUnit::NanonewtonMillimetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e-9)) * 180 / std::numbers::pi_v<un_scalar_t> * 0.001;

            case RotationalStiffnessUnit::MicronewtonMillimetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e-6)) * 180 / std::numbers::pi_v<un_scalar_t> * 0.001;

            case RotationalStiffnessUnit::MillinewtonMillimetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e-3)) * 180 / std::numbers::pi_v<un_scalar_t> * 0.001;

            case RotationalStiffnessUnit::CentinewtonMillimetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e-2)) * 180 / std::numbers::pi_v<un_scalar_t> * 0.001;

            case RotationalStiffnessUnit::DecinewtonMillimetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e-1)) * 180 / std::numbers::pi_v<un_scalar_t> * 0.001;

            case RotationalStiffnessUnit::DecanewtonMillimetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e1)) * 180 / std::numbers::pi_v<un_scalar_t> * 0.001;

            case RotationalStiffnessUnit::KilonewtonMillimetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e3)) * 180 / std::numbers::pi_v<un_scalar_t> * 0.001;

            case RotationalStiffnessUnit::MeganewtonMillimetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e6)) * 180 / std::numbers::pi_v<un_scalar_t> * 0.001;

            case RotationalStiffnessUnit::NewtonMetersPerDegree:
                return value * (180 / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::NanonewtonMetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e-9)) * (180 / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::MicronewtonMetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e-6)) * (180 / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::MillinewtonMetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e-3)) * (180 / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::CentinewtonMetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e-2)) * (180 / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::DecinewtonMetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e-1)) * (180 / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::DecanewtonMetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e1)) * (180 / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::KilonewtonMetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e3)) * (180 / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::MeganewtonMetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e6)) * (180 / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::NewtonMillimetersPerRadian:
                return value * 0.001;

            case RotationalStiffnessUnit::NanonewtonMillimetersPerRadian:
                return (value * static_cast<un_scalar_t>(1e-9)) * 0.001;

            case RotationalStiffnessUnit::MicronewtonMillimetersPerRadian:
                return (value * static_cast<un_scalar_t>(1e-6)) * 0.001;

            case RotationalStiffnessUnit::MillinewtonMillimetersPerRadian:
                return (value * static_cast<un_scalar_t>(1e-3)) * 0.001;

            case RotationalStiffnessUnit::CentinewtonMillimetersPerRadian:
                return (value * static_cast<un_scalar_t>(1e-2)) * 0.001;

            case RotationalStiffnessUnit::DecinewtonMillimetersPerRadian:
                return (value * static_cast<un_scalar_t>(1e-1)) * 0.001;

            case RotationalStiffnessUnit::DecanewtonMillimetersPerRadian:
                return (value * static_cast<un_scalar_t>(1e1)) * 0.001;

            case RotationalStiffnessUnit::KilonewtonMillimetersPerRadian:
                return (value * static_cast<un_scalar_t>(1e3)) * 0.001;

            case RotationalStiffnessUnit::MeganewtonMillimetersPerRadian:
                return (value * static_cast<un_scalar_t>(1e6)) * 0.001;

            case RotationalStiffnessUnit::PoundForceFeetPerRadian:
                return value * 4.4482216152605 * 0.3048;

            case RotationalStiffnessUnit::KilopoundForceFeetPerRadian:
                return value * 4.4482216152605e3 * 0.3048;

            }

            throw std::invalid_argument("Unknown RotationalStiffness unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RotationalStiffnessUnit unit) const
        {
            switch (unit)
            {

            case RotationalStiffnessUnit::NewtonMetersPerRadian:
                return value_;

            case RotationalStiffnessUnit::KilonewtonMetersPerRadian:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case RotationalStiffnessUnit::MeganewtonMetersPerRadian:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case RotationalStiffnessUnit::PoundForceFeetPerDegrees:
                return value_ / (4.4482216152605 * 0.3048 * 180 / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::KilopoundForceFeetPerDegrees:
                return value_ / (4.4482216152605e3 * 0.3048 * 180 / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::NewtonMillimetersPerDegree:
                return value_ / 180 * std::numbers::pi_v<un_scalar_t> * 1000;

            case RotationalStiffnessUnit::NanonewtonMillimetersPerDegree:
                return (value_ / 180 * std::numbers::pi_v<un_scalar_t> * 1000) / static_cast<un_scalar_t>(1e-9);

            case RotationalStiffnessUnit::MicronewtonMillimetersPerDegree:
                return (value_ / 180 * std::numbers::pi_v<un_scalar_t> * 1000) / static_cast<un_scalar_t>(1e-6);

            case RotationalStiffnessUnit::MillinewtonMillimetersPerDegree:
                return (value_ / 180 * std::numbers::pi_v<un_scalar_t> * 1000) / static_cast<un_scalar_t>(1e-3);

            case RotationalStiffnessUnit::CentinewtonMillimetersPerDegree:
                return (value_ / 180 * std::numbers::pi_v<un_scalar_t> * 1000) / static_cast<un_scalar_t>(1e-2);

            case RotationalStiffnessUnit::DecinewtonMillimetersPerDegree:
                return (value_ / 180 * std::numbers::pi_v<un_scalar_t> * 1000) / static_cast<un_scalar_t>(1e-1);

            case RotationalStiffnessUnit::DecanewtonMillimetersPerDegree:
                return (value_ / 180 * std::numbers::pi_v<un_scalar_t> * 1000) / static_cast<un_scalar_t>(1e1);

            case RotationalStiffnessUnit::KilonewtonMillimetersPerDegree:
                return (value_ / 180 * std::numbers::pi_v<un_scalar_t> * 1000) / static_cast<un_scalar_t>(1e3);

            case RotationalStiffnessUnit::MeganewtonMillimetersPerDegree:
                return (value_ / 180 * std::numbers::pi_v<un_scalar_t> * 1000) / static_cast<un_scalar_t>(1e6);

            case RotationalStiffnessUnit::NewtonMetersPerDegree:
                return value_ / (180 / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::NanonewtonMetersPerDegree:
                return (value_ / (180 / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e-9);

            case RotationalStiffnessUnit::MicronewtonMetersPerDegree:
                return (value_ / (180 / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e-6);

            case RotationalStiffnessUnit::MillinewtonMetersPerDegree:
                return (value_ / (180 / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e-3);

            case RotationalStiffnessUnit::CentinewtonMetersPerDegree:
                return (value_ / (180 / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e-2);

            case RotationalStiffnessUnit::DecinewtonMetersPerDegree:
                return (value_ / (180 / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e-1);

            case RotationalStiffnessUnit::DecanewtonMetersPerDegree:
                return (value_ / (180 / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e1);

            case RotationalStiffnessUnit::KilonewtonMetersPerDegree:
                return (value_ / (180 / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e3);

            case RotationalStiffnessUnit::MeganewtonMetersPerDegree:
                return (value_ / (180 / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e6);

            case RotationalStiffnessUnit::NewtonMillimetersPerRadian:
                return value_ * 1000;

            case RotationalStiffnessUnit::NanonewtonMillimetersPerRadian:
                return (value_ * 1000) / static_cast<un_scalar_t>(1e-9);

            case RotationalStiffnessUnit::MicronewtonMillimetersPerRadian:
                return (value_ * 1000) / static_cast<un_scalar_t>(1e-6);

            case RotationalStiffnessUnit::MillinewtonMillimetersPerRadian:
                return (value_ * 1000) / static_cast<un_scalar_t>(1e-3);

            case RotationalStiffnessUnit::CentinewtonMillimetersPerRadian:
                return (value_ * 1000) / static_cast<un_scalar_t>(1e-2);

            case RotationalStiffnessUnit::DecinewtonMillimetersPerRadian:
                return (value_ * 1000) / static_cast<un_scalar_t>(1e-1);

            case RotationalStiffnessUnit::DecanewtonMillimetersPerRadian:
                return (value_ * 1000) / static_cast<un_scalar_t>(1e1);

            case RotationalStiffnessUnit::KilonewtonMillimetersPerRadian:
                return (value_ * 1000) / static_cast<un_scalar_t>(1e3);

            case RotationalStiffnessUnit::MeganewtonMillimetersPerRadian:
                return (value_ * 1000) / static_cast<un_scalar_t>(1e6);

            case RotationalStiffnessUnit::PoundForceFeetPerRadian:
                return value_ / (4.4482216152605 * 0.3048);

            case RotationalStiffnessUnit::KilopoundForceFeetPerRadian:
                return value_ / (4.4482216152605e3 * 0.3048);

            }

            throw std::invalid_argument("Unknown RotationalStiffness unit.");
        }

        un_scalar_t value_;
    };
}
