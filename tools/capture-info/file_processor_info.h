/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#ifndef GFXRECON_DECODE_FILE_PROCESSOR_INFO_H
#define GFXRECON_DECODE_FILE_PROCESSOR_INFO_H

#include "decode/file_processor.h"
using namespace gfxrecon;

class FileProcessorInfo : public gfxrecon::decode::FileProcessor
{
protected:
    virtual bool ProcessFunctionCall(const format::BlockHeader& block_header, format::ApiCallId call_id, bool& should_break) override;

    virtual bool ProcessMethodCall(const format::BlockHeader& block_header, format::ApiCallId call_id, bool& should_break) override;

    virtual bool ProcessMetaData(const format::BlockHeader& block_header, format::MetaDataId meta_data_id) override;

    virtual bool
    ProcessFrameMarker(const format::BlockHeader& block_header, format::MarkerType marker_type, bool& should_break) override;

    virtual bool ProcessStateMarker(const format::BlockHeader& block_header, format::MarkerType marker_type) override;

    virtual bool ProcessAnnotation(const format::BlockHeader& block_header, format::AnnotationType annotation_type) override;
};

#endif // GFXRECON_DECODE_FILE_PROCESSOR_INFO_H

