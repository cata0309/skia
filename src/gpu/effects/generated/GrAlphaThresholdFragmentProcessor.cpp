/*
 * Copyright 2018 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrAlphaThresholdFragmentProcessor.fp; do not modify.
 **************************************************************************************************/
#include "GrAlphaThresholdFragmentProcessor.h"

#include "src/core/SkUtils.h"
#include "src/gpu/GrTexture.h"
#include "src/gpu/glsl/GrGLSLFragmentProcessor.h"
#include "src/gpu/glsl/GrGLSLFragmentShaderBuilder.h"
#include "src/gpu/glsl/GrGLSLProgramBuilder.h"
#include "src/sksl/SkSLCPP.h"
#include "src/sksl/SkSLUtil.h"
class GrGLSLAlphaThresholdFragmentProcessor : public GrGLSLFragmentProcessor {
public:
    GrGLSLAlphaThresholdFragmentProcessor() {}
    void emitCode(EmitArgs& args) override {
        GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
        const GrAlphaThresholdFragmentProcessor& _outer =
                args.fFp.cast<GrAlphaThresholdFragmentProcessor>();
        (void)_outer;
        auto innerThreshold = _outer.innerThreshold;
        (void)innerThreshold;
        auto outerThreshold = _outer.outerThreshold;
        (void)outerThreshold;
        innerThresholdVar = args.fUniformHandler->addUniform(&_outer, kFragment_GrShaderFlag,
                                                             kHalf_GrSLType, "innerThreshold");
        outerThresholdVar = args.fUniformHandler->addUniform(&_outer, kFragment_GrShaderFlag,
                                                             kHalf_GrSLType, "outerThreshold");
        SkString _sample515 = this->invokeChild(0, args);
        fragBuilder->codeAppendf(
                R"SkSL(half4 color = %s;)SkSL", _sample515.c_str());
        SkString _sample555 = this->invokeChild(1, args);
        fragBuilder->codeAppendf(
                R"SkSL(
half4 mask_color = %s;
if (mask_color.w < 0.5) {
    if (color.w > %s) {
        half scale = %s / color.w;
        color.xyz *= scale;
        color.w = %s;
    }
} else if (color.w < %s) {
    half scale = %s / max(0.0010000000474974513, color.w);
    color.xyz *= scale;
    color.w = %s;
}
%s = color;
)SkSL",
                _sample555.c_str(), args.fUniformHandler->getUniformCStr(outerThresholdVar),
                args.fUniformHandler->getUniformCStr(outerThresholdVar),
                args.fUniformHandler->getUniformCStr(outerThresholdVar),
                args.fUniformHandler->getUniformCStr(innerThresholdVar),
                args.fUniformHandler->getUniformCStr(innerThresholdVar),
                args.fUniformHandler->getUniformCStr(innerThresholdVar), args.fOutputColor);
    }

private:
    void onSetData(const GrGLSLProgramDataManager& pdman,
                   const GrFragmentProcessor& _proc) override {
        const GrAlphaThresholdFragmentProcessor& _outer =
                _proc.cast<GrAlphaThresholdFragmentProcessor>();
        {
            pdman.set1f(innerThresholdVar, (_outer.innerThreshold));
            pdman.set1f(outerThresholdVar, (_outer.outerThreshold));
        }
    }
    UniformHandle innerThresholdVar;
    UniformHandle outerThresholdVar;
};
GrGLSLFragmentProcessor* GrAlphaThresholdFragmentProcessor::onCreateGLSLInstance() const {
    return new GrGLSLAlphaThresholdFragmentProcessor();
}
void GrAlphaThresholdFragmentProcessor::onGetGLSLProcessorKey(const GrShaderCaps& caps,
                                                              GrProcessorKeyBuilder* b) const {}
bool GrAlphaThresholdFragmentProcessor::onIsEqual(const GrFragmentProcessor& other) const {
    const GrAlphaThresholdFragmentProcessor& that = other.cast<GrAlphaThresholdFragmentProcessor>();
    (void)that;
    if (innerThreshold != that.innerThreshold) return false;
    if (outerThreshold != that.outerThreshold) return false;
    return true;
}
GrAlphaThresholdFragmentProcessor::GrAlphaThresholdFragmentProcessor(
        const GrAlphaThresholdFragmentProcessor& src)
        : INHERITED(kGrAlphaThresholdFragmentProcessor_ClassID, src.optimizationFlags())
        , innerThreshold(src.innerThreshold)
        , outerThreshold(src.outerThreshold) {
    this->cloneAndRegisterAllChildProcessors(src);
}
std::unique_ptr<GrFragmentProcessor> GrAlphaThresholdFragmentProcessor::clone() const {
    return std::make_unique<GrAlphaThresholdFragmentProcessor>(*this);
}
#if GR_TEST_UTILS
SkString GrAlphaThresholdFragmentProcessor::dumpInfo() const {
    return SkStringPrintf("AlphaThresholdFragmentProcessor(innerThreshold=%f, outerThreshold=%f)",
                          innerThreshold, outerThreshold);
}
#endif
GR_DEFINE_FRAGMENT_PROCESSOR_TEST(GrAlphaThresholdFragmentProcessor);
#if GR_TEST_UTILS
std::unique_ptr<GrFragmentProcessor> GrAlphaThresholdFragmentProcessor::TestCreate(
        GrProcessorTestData* testData) {
    // Make the inner and outer thresholds be in [0, 1].
    float outerThresh = testData->fRandom->nextUScalar1();
    float innerThresh = testData->fRandom->nextUScalar1();
    std::unique_ptr<GrFragmentProcessor> inputChild, maskChild;
    if (testData->fRandom->nextBool()) {
        inputChild = GrProcessorUnitTest::MakeChildFP(testData);
    }
    maskChild = GrProcessorUnitTest::MakeChildFP(testData);

    return GrAlphaThresholdFragmentProcessor::Make(std::move(inputChild), std::move(maskChild),
                                                   innerThresh, outerThresh);
}
#endif
