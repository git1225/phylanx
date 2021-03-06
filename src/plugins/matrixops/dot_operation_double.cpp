//  Copyright (c) 2017-2018 Hartmut Kaiser
//  Copyright (c) 2017 Parsa Amini
//  Copyright (c) 2019 Bita Hasheminezhad
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <phylanx/config.hpp>
#include <phylanx/ir/node_data.hpp>
#include <phylanx/plugins/matrixops/dot_operation.hpp>
#include <phylanx/plugins/matrixops/dot_operation_impl.hpp>

///////////////////////////////////////////////////////////////////////////////
namespace phylanx { namespace execution_tree { namespace primitives
{
    // explicitly instantiate the required functions

    ///////////////////////////////////////////////////////////////////////////
    template primitive_argument_type dot_operation::dot0d(
        ir::node_data<double>&&, ir::node_data<double>&&) const;

    template primitive_argument_type dot_operation::dot1d(
        ir::node_data<double>&&, ir::node_data<double>&&) const;

    template primitive_argument_type dot_operation::dot2d(
        ir::node_data<double>&&, ir::node_data<double>&&) const;

#if defined(PHYLANX_HAVE_BLAZE_TENSOR)
    template primitive_argument_type dot_operation::dot3d(
        ir::node_data<double>&&, ir::node_data<double>&&) const;
#endif

    ///////////////////////////////////////////////////////////////////////////
    template primitive_argument_type dot_operation::outer_nd_helper(
        ir::node_data<double>&&, ir::node_data<double>&&) const;

    template primitive_argument_type dot_operation::outer1d(
        ir::node_data<double>&&, ir::node_data<double>&&) const;

    template primitive_argument_type dot_operation::outer2d(
        ir::node_data<double>&&, ir::node_data<double>&&) const;

#if defined(PHYLANX_HAVE_BLAZE_TENSOR)
    template primitive_argument_type dot_operation::outer3d(
        ir::node_data<double>&&, ir::node_data<double>&&) const;
#endif

    ///////////////////////////////////////////////////////////////////////////
    template primitive_argument_type dot_operation::contraction2d(
        ir::node_data<double>&&, ir::node_data<double>&&) const;

#if defined(PHYLANX_HAVE_BLAZE_TENSOR)
    template primitive_argument_type dot_operation::contraction3d(
        ir::node_data<double>&&, ir::node_data<double>&&) const;
#endif

    ///////////////////////////////////////////////////////////////////////////
    template primitive_argument_type dot_operation::tensordot_range_of_scalars(
        ir::node_data<double>&&, ir::node_data<double>&&, val_type,
        val_type) const;
}}}
