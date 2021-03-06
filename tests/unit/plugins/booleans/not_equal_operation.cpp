//   Copyright (c) 2017 Hartmut Kaiser
// Copyright (c) 2018 Shahrzad Shirzad
//
//   Distributed under the Boost Software License, Version 1.0. (See accompanying
//   file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <phylanx/phylanx.hpp>

#include <hpx/hpx_main.hpp>
#include <hpx/include/lcos.hpp>
#include <hpx/util/lightweight_test.hpp>

#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

void test_not_equal_operation_0d_true()
{
    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(41.0));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(1.0));

    phylanx::execution_tree::primitive not_equal;
    not_equal = phylanx::execution_tree::primitives::create_not_equal(
        hpx::find_here(),
        phylanx::execution_tree::primitive_arguments_type{
            std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    HPX_TEST_EQ(phylanx::ir::node_data<double>(1.0),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(true),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_0d_true_return_double()
{
    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(41.0));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(1.0));

    phylanx::execution_tree::primitive not_equal;
    not_equal =
        phylanx::execution_tree::primitives::create_not_equal(hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs),
                phylanx::ir::node_data<std::uint8_t>(true)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    HPX_TEST_EQ(f.index(), 4);    //node_data<double>
    HPX_TEST_EQ(phylanx::ir::node_data<double>(1.0),
        phylanx::execution_tree::extract_numeric_value(f));
}

void test_not_equal_operation_0d_bool_true()
{
    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<std::uint8_t>(true));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<std::uint8_t>(false));

    phylanx::execution_tree::primitive not_equal;
    not_equal = phylanx::execution_tree::primitives::create_not_equal(
        hpx::find_here(),
        phylanx::execution_tree::primitive_arguments_type{
            std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(true),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_0d_bool_true_return_bool()
{
    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<std::uint8_t>(true));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<std::uint8_t>(false));

    phylanx::execution_tree::primitive not_equal;
    not_equal =
        phylanx::execution_tree::primitives::create_not_equal(hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs),
                phylanx::ir::node_data<std::uint8_t>(false)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    HPX_TEST_EQ(f.index(), 1);    //node_data<std::uint8_t>
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(true),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_0d_false()
{
    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(1.0));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(1.0));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    HPX_TEST_EQ(phylanx::ir::node_data<double>(0.0),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(false),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_0d_lit_true()
{
    phylanx::ir::node_data<double> lhs(41.0);

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(1.0));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    HPX_TEST_EQ(phylanx::ir::node_data<double>(1.0),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(true),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_0d_lit_false()
{
    phylanx::ir::node_data<double> lhs(1.0);

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(1.0));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    HPX_TEST_EQ(phylanx::ir::node_data<double>(0.0),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(false)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_0d1d()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<double> v = gen.generate(1007UL, 0, 2);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(2.0));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(v));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicVector<double> expected =
        blaze::map(v, [](double x) { return (x != 2.0); });

    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_0d1d_lit()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<double> v = gen.generate(1007UL, 0, 2);

    phylanx::ir::node_data<double> lhs(2.0);

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(v));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicVector<double> expected =
        blaze::map(v, [](double x) { return (x != 2.0); });

    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_0d1d_bool()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<std::uint8_t> v = gen.generate(1007UL, 0, 1);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<std::uint8_t>(false));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<std::uint8_t>(v));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicVector<std::uint8_t> expected =
        blaze::map(v, [](bool x) { return (x != false); });

    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_0d1d_bool_lit()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<std::uint8_t> v = gen.generate(1007UL, 0, 1);

    phylanx::ir::node_data<double> lhs(false);

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(v));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicVector<std::uint8_t> expected =
        blaze::map(v, [](bool x) { return (x != false); });

    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_0d1d_return_double()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<double> v = gen.generate(1007UL, 0, 2);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(2.0));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(v));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs),
                phylanx::ir::node_data<std::uint8_t>(true)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicVector<double> expected =
        blaze::map(v, [](double x) { return (x != 2.0); });

    HPX_TEST_EQ(f.index(), 4);
    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
}

void test_not_equal_operation_0d1d_return_bool()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<double> v = gen.generate(1007UL, 0, 2);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(2.0));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(v));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs),
                phylanx::ir::node_data<std::uint8_t>(false)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicVector<double> expected =
        blaze::map(v, [](double x) { return (x != 2.0); });

    HPX_TEST_EQ(f.index(), 1);
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(expected),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_0d2d()
{
    blaze::Rand<blaze::DynamicMatrix<int>> gen{};
    blaze::DynamicMatrix<double> m = gen.generate(101UL, 101UL, 0, 2);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(2.0));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(m));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<double> expected =
        blaze::map(m, [](double x) { return (x != 2.0); });

    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_0d2d_return_double()
{
    blaze::Rand<blaze::DynamicMatrix<int>> gen{};
    blaze::DynamicMatrix<double> m = gen.generate(101UL, 101UL, 0, 2);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(2.0));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(m));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs),
                phylanx::ir::node_data<std::uint8_t>(true)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<double> expected =
        blaze::map(m, [](double x) { return (x != 2.0); });

    HPX_TEST_EQ(f.index(), 4);    //node_data<double>
    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
}

void test_not_equal_operation_0d2d_lit()
{
    blaze::Rand<blaze::DynamicMatrix<int>> gen{};
    blaze::DynamicMatrix<double> m = gen.generate(101UL, 101UL, 0, 2);

    phylanx::ir::node_data<double> lhs(2.0);

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(m));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<double> expected =
        blaze::map(m, [](double x) { return (x != 2.0); });

    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_0d2d_bool()
{
    blaze::Rand<blaze::DynamicMatrix<int>> gen{};
    blaze::DynamicMatrix<std::uint8_t> m = gen.generate(101UL, 101UL, 0, 1);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<std::uint8_t>(true));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<std::uint8_t>(m));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<std::uint8_t> expected =
        blaze::map(m, [](bool x) { return (x != true); });

    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_0d2d_bool_lit()
{
    blaze::Rand<blaze::DynamicMatrix<int>> gen{};
    blaze::DynamicMatrix<std::uint8_t> m = gen.generate(101UL, 101UL, 0, 1);

    phylanx::ir::node_data<std::uint8_t> lhs(true);

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<std::uint8_t>(m));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<std::uint8_t> expected =
        blaze::map(m, [](bool x) { return (x != true); });

    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_1d()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<double> v1 = gen.generate(100UL, 0, 2);
    blaze::DynamicVector<double> v2 = gen.generate(100UL, 0, 2);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(v1));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(v2));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicVector<double> expected =
        blaze::map(v1, v2, [](double x, double y) { return x != y; });

    HPX_TEST_EQ(phylanx::ir::node_data<double>((expected)),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_1d_return_double()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<double> v1 = gen.generate(100UL, 0, 2);
    blaze::DynamicVector<double> v2 = gen.generate(100UL, 0, 2);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(v1));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(v2));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs),
                phylanx::ir::node_data<std::uint8_t>(true)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicVector<double> expected =
        blaze::map(v1, v2, [](double x, double y) { return x != y; });

    HPX_TEST_EQ(f.index(), 4);    //node_data<double>
    HPX_TEST_EQ(phylanx::ir::node_data<double>((expected)),
        phylanx::execution_tree::extract_numeric_value(f));
}

void test_not_equal_operation_1d_lit()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<double> v1 = gen.generate(1007UL, 0, 2);
    blaze::DynamicVector<double> v2 = gen.generate(1007UL, 0, 2);

    phylanx::ir::node_data<double> lhs(v1);

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(v2));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicVector<double> expected =
        blaze::map(v1, v2, [](double x, double y) { return x != y; });

    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_1d0d()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<double> v = gen.generate(1007UL, 0, 2);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(v));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(2.0));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicVector<double> expected =
        blaze::map(v, [](double x) { return (x != 2.0); });

    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_1d0d_return_double()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<double> v = gen.generate(1007UL, 0, 2);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(v));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(2.0));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs),
                phylanx::ir::node_data<std::uint8_t>(true)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicVector<double> expected =
        blaze::map(v, [](double x) { return (x != 2.0); });

    HPX_TEST_EQ(f.index(), 4);    //node_data<double>
    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
}

void test_not_equal_operation_1d0d_lit()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<double> v = gen.generate(1007UL, 0, 2);

    phylanx::ir::node_data<double> lhs(v);

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(2.0));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicVector<double> expected =
        blaze::map(v, [](double x) { return (x != 2.0); });

    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_1d0d_bool()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<std::uint8_t> v = gen.generate(1007UL, 0, 1);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<std::uint8_t>(v));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<std::uint8_t>(false));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicVector<std::uint8_t> expected =
        blaze::map(v, [](bool x) { return (x != false); });

    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_1d0d_bool_lit()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<std::uint8_t> v = gen.generate(1007UL, 0, 1);

    phylanx::ir::node_data<std::uint8_t> lhs(v);

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<std::uint8_t>(false));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicVector<std::uint8_t> expected =
        blaze::map(v, [](bool x) { return (x != false); });

    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_1d2d()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<double> v = gen.generate(104UL, 0, 2);

    blaze::Rand<blaze::DynamicMatrix<int>> mat_gen{};
    blaze::DynamicMatrix<double> m = mat_gen.generate(101UL, 104UL, 0, 2);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(v));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(m));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<double> expected{m.rows(), m.columns()};

    for (size_t i = 0UL; i < m.rows(); i++)
        blaze::row(expected, i) = blaze::map(blaze::row(m, i),
            blaze::trans(v),
            [](double x, double y) { return x != y; });

    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_1d2d_lit()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<double> v = gen.generate(104UL, 0, 2);

    blaze::Rand<blaze::DynamicMatrix<double>> mat_gen{};
    blaze::DynamicMatrix<double> m = mat_gen.generate(101UL, 104UL, 0, 2);

    phylanx::ir::node_data<double> lhs(v);

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(m));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<double> expected{m.rows(), m.columns()};

    for (size_t i = 0UL; i < m.rows(); i++)
        blaze::row(expected, i) = blaze::map(blaze::row(m, i),
            blaze::trans(v),
            [](double x, double y) { return x != y; });

    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_1d2d_return_double()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<double> v = gen.generate(104UL, 0, 2);

    blaze::Rand<blaze::DynamicMatrix<int>> mat_gen{};
    blaze::DynamicMatrix<double> m = mat_gen.generate(101UL, 104UL, 0, 2);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(v));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(m));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs),
                phylanx::ir::node_data<std::uint8_t>(true)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<double> expected{m.rows(), m.columns()};

    for (size_t i = 0UL; i < m.rows(); i++)
        blaze::row(expected, i) = blaze::map(blaze::row(m, i),
            blaze::trans(v),
            [](double x, double y) { return x != y; });

    HPX_TEST_EQ(f.index(), 4);    //node_data<double>
    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
}

void test_not_equal_operation_1d2d_return_bool()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<double> v = gen.generate(104UL, 0, 2);

    blaze::Rand<blaze::DynamicMatrix<int>> mat_gen{};
    blaze::DynamicMatrix<double> m = mat_gen.generate(101UL, 104UL, 0, 2);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(v));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(m));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs),
                phylanx::ir::node_data<std::uint8_t>(false)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<double> expected{m.rows(), m.columns()};

    for (size_t i = 0UL; i < m.rows(); i++)
        blaze::row(expected, i) = blaze::map(blaze::row(m, i),
            blaze::trans(v),
            [](double x, double y) { return x != y; });

    HPX_TEST_EQ(f.index(), 1);    //node_data<std::uint8_t>
    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
}

void test_not_equal_operation_2d()
{
    blaze::Rand<blaze::DynamicMatrix<int>> gen{};
    blaze::DynamicMatrix<double> m1 = gen.generate(1007UL, 1007UL, 0, 2);
    blaze::DynamicMatrix<double> m2 = gen.generate(1007UL, 1007UL, 0, 2);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(m1));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(m2));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<double> expected =
        blaze::map(m1, m2, [](double x, double y) { return x != y; });

    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_2d_return_double()
{
    blaze::Rand<blaze::DynamicMatrix<int>> gen{};
    blaze::DynamicMatrix<double> m1 = gen.generate(1007UL, 1007UL, 0, 2);
    blaze::DynamicMatrix<double> m2 = gen.generate(1007UL, 1007UL, 0, 2);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(m1));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(m2));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs),
                phylanx::ir::node_data<std::uint8_t>(true)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<double> expected =
        blaze::map(m1, m2, [](double x, double y) { return x != y; });

    HPX_TEST_EQ(f.index(), 4);    //node_data<double>
    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
}

void test_not_equal_operation_2d_lit()
{
    blaze::Rand<blaze::DynamicMatrix<int>> gen{};
    blaze::DynamicMatrix<double> m1 = gen.generate(1007UL, 1007UL, 0, 2);
    blaze::DynamicMatrix<double> m2 = gen.generate(1007UL, 1007UL, 0, 2);

    phylanx::ir::node_data<double> lhs(m1);

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(m2));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<double> expected =
        blaze::map(m1, m2, [](double x, double y) { return x != y; });

    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_2d_bool()
{
    blaze::Rand<blaze::DynamicMatrix<int>> gen{};
    blaze::DynamicMatrix<std::uint8_t> m1 = gen.generate(1007UL, 1007UL, 0, 1);
    blaze::DynamicMatrix<std::uint8_t> m2 = gen.generate(1007UL, 1007UL, 0, 1);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<std::uint8_t>(m1));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<std::uint8_t>(m2));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<std::uint8_t> expected =
        blaze::map(m1, m2, [](bool x, bool y) { return x != y; });

    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_2d_bool_lit()
{
    blaze::Rand<blaze::DynamicMatrix<int>> gen{};
    blaze::DynamicMatrix<std::uint8_t> m1 = gen.generate(1007UL, 1007UL, 0, 1);
    blaze::DynamicMatrix<std::uint8_t> m2 = gen.generate(1007UL, 1007UL, 0, 1);

    phylanx::ir::node_data<std::uint8_t> lhs(m1);

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<std::uint8_t>(m2));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<std::uint8_t> expected =
        blaze::map(m1, m2, [](bool x, bool y) { return x != y; });

    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_2d0d()
{
    blaze::Rand<blaze::DynamicMatrix<int>> gen{};
    blaze::DynamicMatrix<double> m = gen.generate(101UL, 101UL, 0, 2);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(m));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(2.0));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<double> expected =
        blaze::map(m, [](double x) { return (x != 2.0); });

    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_2d0d_return_double()
{
    blaze::Rand<blaze::DynamicMatrix<int>> gen{};
    blaze::DynamicMatrix<double> m = gen.generate(101UL, 101UL, 0, 2);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(m));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(2.0));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs),
                phylanx::ir::node_data<std::uint8_t>(true)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<double> expected =
        blaze::map(m, [](double x) { return (x != 2.0); });

    HPX_TEST_EQ(f.index(), 4);    //node_data<double>
    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
}

void test_not_equal_operation_2d0d_lit()
{
    blaze::Rand<blaze::DynamicMatrix<int>> gen{};
    blaze::DynamicMatrix<double> m = gen.generate(101UL, 101UL, 0, 2);

    phylanx::ir::node_data<double> lhs(m);

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(2.0));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<double> expected =
        blaze::map(m, [](double x) { return (x != 2.0); });

    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_2d0d_bool()
{
    blaze::Rand<blaze::DynamicMatrix<int>> gen{};
    blaze::DynamicMatrix<std::uint8_t> m = gen.generate(101UL, 101UL, 0, 1);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<std::uint8_t>(m));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<std::uint8_t>(true));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<std::uint8_t> expected =
        blaze::map(m, [](bool x) { return (x != true); });

    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_2d0d_bool_lit()
{
    blaze::Rand<blaze::DynamicMatrix<int>> gen{};
    blaze::DynamicMatrix<std::uint8_t> m = gen.generate(101UL, 101UL, 0, 1);

    phylanx::ir::node_data<std::uint8_t> lhs(m);

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<std::uint8_t>(true));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<std::uint8_t> expected =
        blaze::map(m, [](bool x) { return (x != true); });

    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_2d1d()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<double> v = gen.generate(104UL, 0, 2);

    blaze::Rand<blaze::DynamicMatrix<double>> mat_gen{};
    blaze::DynamicMatrix<double> m = mat_gen.generate(101UL, 104UL, 0, 2);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(m));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(v));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<double> expected{m.rows(), m.columns()};
    for (size_t i = 0UL; i < m.rows(); i++)
        blaze::row(expected, i) = blaze::map(blaze::row(m, i),
            blaze::trans(v),
            [](double x, double y) { return x != y; });

    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_2d1d_return_double()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<double> v = gen.generate(104UL, 0, 2);

    blaze::Rand<blaze::DynamicMatrix<double>> mat_gen{};
    blaze::DynamicMatrix<double> m = mat_gen.generate(101UL, 104UL, 0, 2);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(m));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(v));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs),
                phylanx::ir::node_data<std::uint8_t>(true)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<double> expected{m.rows(), m.columns()};
    for (size_t i = 0UL; i < m.rows(); i++)
        blaze::row(expected, i) = blaze::map(blaze::row(m, i),
            blaze::trans(v),
            [](double x, double y) { return x != y; });

    HPX_TEST_EQ(f.index(), 4);    //node_data<double>
    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
}

void test_not_equal_operation_2d1d_lit()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<double> v = gen.generate(104UL, 0, 2);

    blaze::Rand<blaze::DynamicMatrix<double>> mat_gen{};
    blaze::DynamicMatrix<double> m = mat_gen.generate(101UL, 104UL, 0, 2);

    phylanx::ir::node_data<double> lhs(m);

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<double>(v));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<double> expected{m.rows(), m.columns()};
    for (size_t i = 0UL; i < m.rows(); i++)
        blaze::row(expected, i) = blaze::map(blaze::row(m, i),
            blaze::trans(v),
            [](double x, double y) { return x != y; });

    HPX_TEST_EQ(phylanx::ir::node_data<double>(expected),
        phylanx::execution_tree::extract_numeric_value(f));
    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_2d1d_bool()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<std::uint8_t> v = gen.generate(104UL, 0, 1);

    blaze::Rand<blaze::DynamicMatrix<int>> mat_gen{};
    blaze::DynamicMatrix<std::uint8_t> m = mat_gen.generate(101UL, 104UL, 0, 1);

    phylanx::execution_tree::primitive lhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<std::uint8_t>(m));

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<std::uint8_t>(v));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<std::uint8_t> expected{m.rows(), m.columns()};
    for (size_t i = 0UL; i < m.rows(); i++)
        blaze::row(expected, i) = blaze::map(blaze::row(m, i),
            blaze::trans(v),
            [](bool x, bool y) { return x != y; });

    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

void test_not_equal_operation_2d1d_bool_lit()
{
    blaze::Rand<blaze::DynamicVector<int>> gen{};
    blaze::DynamicVector<std::uint8_t> v = gen.generate(104UL, 0, 1);

    blaze::Rand<blaze::DynamicMatrix<int>> mat_gen{};
    blaze::DynamicMatrix<std::uint8_t> m = mat_gen.generate(101UL, 104UL, 0, 1);

    phylanx::ir::node_data<std::uint8_t> lhs(m);

    phylanx::execution_tree::primitive rhs =
        phylanx::execution_tree::primitives::create_variable(
            hpx::find_here(), phylanx::ir::node_data<std::uint8_t>(v));

    phylanx::execution_tree::primitive not_equal =
        phylanx::execution_tree::primitives::create_not_equal(
            hpx::find_here(),
            phylanx::execution_tree::primitive_arguments_type{
                std::move(lhs), std::move(rhs)});

    phylanx::execution_tree::primitive_argument_type f = not_equal.eval().get();

    blaze::DynamicMatrix<std::uint8_t> expected{m.rows(), m.columns()};
    for (size_t i = 0UL; i < m.rows(); i++)
        blaze::row(expected, i) = blaze::map(blaze::row(m, i),
            blaze::trans(v),
            [](bool x, bool y) { return x != y; });

    HPX_TEST_EQ(phylanx::ir::node_data<std::uint8_t>(std::move(expected)),
        phylanx::execution_tree::extract_boolean_data(f));
}

int main(int argc, char* argv[])
{
    test_not_equal_operation_0d_false();
    test_not_equal_operation_0d_bool_true();
    test_not_equal_operation_0d_true_return_double();
    test_not_equal_operation_0d_bool_true_return_bool();
    test_not_equal_operation_0d_true();
    test_not_equal_operation_0d_lit_false();
    test_not_equal_operation_0d_lit_true();
    test_not_equal_operation_0d1d();
    test_not_equal_operation_0d1d_lit();
    test_not_equal_operation_0d1d_bool();
    test_not_equal_operation_0d1d_bool_lit();
    test_not_equal_operation_0d1d_return_double();
    test_not_equal_operation_0d1d_return_bool();
    test_not_equal_operation_0d2d();
    test_not_equal_operation_0d2d_return_double();
    test_not_equal_operation_0d2d_lit();
    test_not_equal_operation_0d2d_bool();
    test_not_equal_operation_0d2d_bool_lit();

    test_not_equal_operation_1d();
    test_not_equal_operation_1d_return_double();
    test_not_equal_operation_1d_lit();
    test_not_equal_operation_1d0d();
    test_not_equal_operation_1d0d_return_double();
    test_not_equal_operation_1d0d_lit();
    test_not_equal_operation_1d0d_bool();
    test_not_equal_operation_1d0d_bool_lit();
    test_not_equal_operation_1d2d();
    test_not_equal_operation_1d2d_lit();
    test_not_equal_operation_1d2d_return_double();
    test_not_equal_operation_1d2d_return_bool();

    test_not_equal_operation_2d();
    test_not_equal_operation_2d_return_double();
    test_not_equal_operation_2d_lit();
    test_not_equal_operation_2d_bool();
    test_not_equal_operation_2d_bool_lit();
    test_not_equal_operation_2d0d();
    test_not_equal_operation_2d0d_return_double();
    test_not_equal_operation_2d0d_lit();
    test_not_equal_operation_2d0d_bool();
    test_not_equal_operation_2d0d_bool_lit();
    test_not_equal_operation_2d1d();
    test_not_equal_operation_2d1d_return_double();
    test_not_equal_operation_2d1d_lit();
    test_not_equal_operation_2d1d_bool();
    test_not_equal_operation_2d1d_bool_lit();

    return hpx::util::report_errors();
}
