/*
 * Copyright 2017 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrBlurredEdgeFragmentProcessor.fp; do not modify.
 **************************************************************************************************/
#ifndef GrBlurredEdgeFragmentProcessor_DEFINED
#define GrBlurredEdgeFragmentProcessor_DEFINED

#include "include/core/SkM44.h"
#include "include/core/SkTypes.h"

#include "src/gpu/GrFragmentProcessor.h"

class GrBlurredEdgeFragmentProcessor : public GrFragmentProcessor {
public:
    enum class Mode { kGaussian = 0, kSmoothStep = 1 };
    static std::unique_ptr<GrFragmentProcessor> Make(std::unique_ptr<GrFragmentProcessor> inputFP,
                                                     Mode mode) {
        return std::unique_ptr<GrFragmentProcessor>(
                new GrBlurredEdgeFragmentProcessor(std::move(inputFP), mode));
    }
    GrBlurredEdgeFragmentProcessor(const GrBlurredEdgeFragmentProcessor& src);
#if GR_TEST_UTILS
    SkString dumpInfo() const override;
#endif
    std::unique_ptr<GrFragmentProcessor> clone() const override;
    const char* name() const override { return "BlurredEdgeFragmentProcessor"; }
    Mode mode;

private:
    GrBlurredEdgeFragmentProcessor(std::unique_ptr<GrFragmentProcessor> inputFP, Mode mode)
            : INHERITED(kGrBlurredEdgeFragmentProcessor_ClassID, kNone_OptimizationFlags)
            , mode(mode) {
        this->registerChild(std::move(inputFP), SkSL::SampleUsage::PassThrough());
    }
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;
    void onGetGLSLProcessorKey(const GrShaderCaps&, GrProcessorKeyBuilder*) const override;
    bool onIsEqual(const GrFragmentProcessor&) const override;
    GR_DECLARE_FRAGMENT_PROCESSOR_TEST
    typedef GrFragmentProcessor INHERITED;
};
#endif
