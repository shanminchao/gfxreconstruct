/*
** Copyright (c) 2018-2020,2022 Valve Corporation
** Copyright (c) 2018-2020,2022 LunarG, Inc.
** Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "file_processor_info.h"
#include "util/logging.h"

bool FileProcessorInfo::ProcessFunctionCall(const format::BlockHeader& block_header, format::ApiCallId call_id, bool& should_break)
{
    GFXRECON_WRITE_CONSOLE("Block: kFunctionCallBlock, Size: %d", block_header.size);
    return FileProcessor::ProcessFunctionCall(block_header, call_id, should_break);
}

bool FileProcessorInfo::ProcessMethodCall(const format::BlockHeader& block_header, format::ApiCallId call_id, bool& should_break)
{
    GFXRECON_WRITE_CONSOLE("Block: kMethodCallBlock, Size: %d", block_header.size);
    return FileProcessor::ProcessMethodCall(block_header, call_id, should_break);
}

bool FileProcessorInfo::ProcessMetaData(const format::BlockHeader& block_header, format::MetaDataId meta_data_id)
{
    const char *metadata_strings[] =
    {
        "kUnknownMetaDataType",
        "kDisplayMessageCommand",
        "kFillMemoryCommand",
        "kResizeWindowCommand",
        "kSetSwapchainImageStateCommand",
        "kBeginResourceInitCommand",
        "kEndResourceInitCommand",
        "kInitBufferCommand",
        "kInitImageCommand",
        "kCreateHardwareBufferCommand_deprecated",
        "kDestroyHardwareBufferCommand",
        "kSetDevicePropertiesCommand",
        "kSetDeviceMemoryPropertiesCommand",
        "kResizeWindowCommand2",
        "kSetOpaqueAddressCommand",
        "kSetRayTracingShaderGroupHandlesCommand",
        "kCreateHeapAllocationCommand",
        "kInitSubresourceCommand",
        "kExeFileInfoCommand",
        "kInitDx12AccelerationStructureCommand",
        "kFillMemoryResourceValueCommand",
        "kDxgiAdapterInfoCommand",
        "kDriverInfoCommand",
        "kReserved23",
        "kCreateHardwareBufferCommand",
        "kReserved25",
        "kDx12RuntimeInfoCommand",
        "kParentToChildDependency",
        "kReserved28",
        "kReserved29",
        "kReserved30",
        "kReserved31",
    };
    GFXRECON_WRITE_CONSOLE("Block: kMetaDataBlock, Size: %d", block_header.size);
    GFXRECON_WRITE_CONSOLE("\t%s", metadata_strings[meta_data_id & 0x0000ffff]);
    return FileProcessor::ProcessMetaData(block_header, meta_data_id);
}

bool
FileProcessorInfo::ProcessFrameMarker(const format::BlockHeader& block_header, format::MarkerType marker_type, bool& should_break)
{
    GFXRECON_WRITE_CONSOLE("Block: kFrameMarkerBlock, Size: %d", block_header.size);
    return FileProcessor::ProcessFrameMarker(block_header, marker_type, should_break);
}

bool FileProcessorInfo::ProcessStateMarker(const format::BlockHeader& block_header, format::MarkerType marker_type)
{
    GFXRECON_WRITE_CONSOLE("Block: kStateMarkerBlock, Size: %d", block_header.size);
    return FileProcessor::ProcessStateMarker(block_header, marker_type);
}

bool FileProcessorInfo::ProcessAnnotation(const format::BlockHeader& block_header, format::AnnotationType annotation_type)
{
    GFXRECON_WRITE_CONSOLE("Block: kAnnotation, Size: %d", block_header.size);
    return FileProcessor::ProcessAnnotation(block_header, annotation_type);
}